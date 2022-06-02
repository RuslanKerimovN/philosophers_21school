/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:11:44 by botilia           #+#    #+#             */
/*   Updated: 2022/04/19 12:53:55 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max_eat(t_base *philos)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < philos->num)
	{
		pthread_mutex_lock(&philos->p[j].checking);
		if (philos->p[j].max_eat == 0)
			k++;
		pthread_mutex_unlock(&philos->p[j].checking);
	}
	if (k == (philos->num))
	{
		pthread_mutex_lock(&philos->print);
		return (0);
	}
	return (1);
}

int	check_death_philo(t_base *philos, int i)
{
	int	now;

	now = get_time();
	pthread_mutex_lock(&philos->p[i].checking);
	if (now - philos->p[i].check_timedie
		> philos->t_die && (philos->p[i].max_eat))
	{
		philos->life = 0;
		pthread_mutex_lock(&philos->print);
		printf("%d %d died\n", get_time() - philos->p[i].check_timedie,
			philos->p[i].i_phl_right + 1);
		pthread_mutex_unlock(&philos->print);
		return (0);
	}
	pthread_mutex_unlock(&philos->p[i].checking);
	return (1);
}

int	dead_philo(t_base *philos)
{
	int	i;

	i = 0;
	while (philos->life)
	{
		if (i == philos->num)
			i = 0;
		if (!check_max_eat(philos))
			return (0);
		if (!check_death_philo(philos, i))
			return (1);
		i++;
	}
	return (1);
}

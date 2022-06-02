/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:22:26 by botilia           #+#    #+#             */
/*   Updated: 2022/04/19 13:13:41 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *new, char *str)
{
	pthread_mutex_lock(new->print);
	printf("%d %d %s\n",
		get_time() - new->t_start, new->i_phl_right + 1, str);
	pthread_mutex_unlock(new->print);
}

void	get_fork(t_philo *new)
{
	pthread_mutex_lock(new->fork_r);
	print_message(new, "has taken a fork");
	pthread_mutex_lock(new->fork_l);
	print_message(new, "has taken a fork");
}

void	minus_eat(t_philo *new)
{
	pthread_mutex_lock(&new->checking);
	if (new->max_eat != -1)
		new->max_eat--;
	pthread_mutex_unlock(&new->checking);
}

void	checking_time(t_philo *new)
{
	pthread_mutex_lock(&new->checking);
	new->check_timedie = get_time();
	pthread_mutex_unlock(&new->checking);
}

void	*philosophers(void *p)
{
	t_philo	*new;

	new = p;
	if (new->i_phl_right % 2)
		my_usleep(new->time_eat / 2);
	while (*new->must_die)
	{
		pthread_mutex_lock(&new->checking);
		if (new->max_eat == 0)
			break ;
		else
			pthread_mutex_unlock(&new->checking);
		get_fork(new);
		checking_time(new);
		print_message(new, "is eating");
		my_usleep(new->time_eat);
		pthread_mutex_unlock(new->fork_l);
		pthread_mutex_unlock(new->fork_r);
		print_message(new, "is sleeping");
		my_usleep(new->time_sleep);
		print_message(new, "is thinking");
		minus_eat(new);
	}
	pthread_mutex_unlock(&new->checking);
	return (NULL);
}

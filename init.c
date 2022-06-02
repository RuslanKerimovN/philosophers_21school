/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:35:58 by botilia           #+#    #+#             */
/*   Updated: 2022/04/21 12:21:12 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_base *philos, int i, int left)
{
	if (i == (philos->num - 1))
	{
		philos->p[i].fork_r = &philos->fork[left];
		philos->p[i].fork_l = &philos->fork[i];
	}
	else
	{
		philos->p[i].fork_r = &philos->fork[i];
		philos->p[i].fork_l = &philos->fork[left];
	}
}

int	init_philo_and_mutex(t_base *philos)
{
	int	i;

	i = -1;
	while (++i < philos->num)
	{
		philos->p[i].i_phl_right = i;
		philos->p[i].num_p = philos->num;
		philos->p[i].time_die = philos->t_die;
		philos->p[i].time_eat = philos->t_eat;
		philos->p[i].time_sleep = philos->t_sleep;
		philos->p[i].max_eat = philos->count;
		philos->p[i].left = (i + 1) % philos->num;
		init_forks(philos, i, philos->p[i].left);
		philos->p[i].must_die = &philos->life;
		philos->p[i].t_start = philos->time_start;
		philos->p[i].check_timedie = get_time();
		philos->p[i].print = &philos->print;
		if ((pthread_mutex_init(&philos->fork[i], NULL))
			|| (pthread_mutex_init(&philos->p[i].checking, NULL)))
			return (1);
	}
	if (pthread_mutex_init(&philos->print, NULL))
		return (1);
	return (0);
}

int	init_base(t_base *philos, char **argv)
{
	philos->count = -1;
	if (argv[5])
		philos->count = ft_atoi(argv[5]);
	philos->time_start = get_time();
	philos->life = 1;
	philos->p = malloc(sizeof(t_philo) * philos->num);
	philos->pth_phl = malloc(sizeof(pthread_t) * philos->num);
	philos->fork = malloc(sizeof(pthread_mutex_t) * philos->num);
	if (!philos->p || !philos->fork || !philos->pth_phl)
		return (1);
	return (0);
}

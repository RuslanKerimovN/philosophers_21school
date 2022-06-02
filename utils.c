/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:17:57 by botilia           #+#    #+#             */
/*   Updated: 2022/04/21 12:21:01 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += ((int)str[i] - '0');
		i++;
	}
	return (k * j);
}

int	check_args(int argc, char **argv, t_base *philos)
{
	if (argc < 5 || argc > 6)
		return (0);
	philos->num = ft_atoi(argv[1]);
	if (philos->num <= 0 || philos->num > 200)
		return (0);
	philos->t_die = ft_atoi(argv[2]);
	if (philos->t_die < 60)
		return (0);
	philos->t_eat = ft_atoi(argv[3]);
	if (philos->t_eat < 60)
		return (0);
	philos->t_sleep = ft_atoi(argv[4]);
	if (philos->t_sleep < 60)
		return (0);
	return (1);
}

int	get_time(void)
{
	struct timeval	need_time;

	gettimeofday(&need_time, NULL);
	return ((need_time.tv_sec * 1000) + (need_time.tv_usec / 1000));
}

void	my_usleep(int ms)
{
	int	starttime;
	int	currenttime;

	starttime = get_time();
	currenttime = starttime;
	while (currenttime - starttime < (long)ms)
	{
		currenttime = get_time();
		usleep(ms);
	}
}

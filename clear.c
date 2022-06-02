/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:25:01 by botilia           #+#    #+#             */
/*   Updated: 2022/04/19 11:25:35 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detaching(t_base *philos)
{
	int	i;

	i = -1;
	while (++i < philos->num)
		pthread_detach(philos->pth_phl[i]);
}

void	joining(t_base *philos)
{
	int	i;

	i = -1;
	while (++i < philos->num)
		pthread_join(philos->pth_phl[i], NULL);
}

void	ft_free(t_base *philos, int i)
{
	int	j;

	j = -1;
	if (i == 0)
	{
		pthread_mutex_destroy(&philos->print);
		while (++j < philos->num)
		{
			pthread_mutex_destroy(&philos->p[j].checking);
			pthread_mutex_destroy(&philos->fork[i]);
		}
	}
	free(philos->p);
	free(philos->pth_phl);
	free(philos->fork);
	free(philos);
}

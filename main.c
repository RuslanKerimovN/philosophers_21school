/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:17:45 by botilia           #+#    #+#             */
/*   Updated: 2022/04/21 12:21:11 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_base	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_base));
	if (!philos)
		return (write(1, "Error of memory\n", 16));
	if (!check_args(argc, argv, philos))
		return (write(1, "Error of args\n", 14));
	if (init_base(philos, argv) || init_philo_and_mutex(philos))
		return (write(1, "Error of init\n", 23));
	while (++i < philos->num)
		pthread_create(&philos->pth_phl[i], NULL, philosophers, &philos->p[i]);
	i = dead_philo(philos);
	if (i == 0)
		joining(philos);
	else
		detaching(philos);
	ft_free(philos, i);
	return (0);
}

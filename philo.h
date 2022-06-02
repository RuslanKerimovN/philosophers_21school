/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:15:44 by botilia           #+#    #+#             */
/*   Updated: 2022/04/19 13:14:24 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				i_phl_right;
	int				num_p;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_eat;
	int				left;
	int				*must_die;
	int				t_start;
	int				check_timedie;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*print;
	pthread_mutex_t	checking;
}t_philo;

typedef struct s_base
{
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				count;
	int				time_start;
	int				life;
	t_philo			*p;
	pthread_t		*pth_phl;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}t_base;

// utils
int		ft_atoi(const char *str);
int		check_args(int argc, char **argv, t_base *philos);
int		get_time(void);
void	my_usleep(int ms);
//init
void	init_forks(t_base *philos, int i, int left);
int		init_philo_and_mutex(t_base *philos);
int		init_base(t_base *philos, char **argv);
//philosophers
void	print_message(t_philo *new, char *str);
void	get_fork(t_philo *new);
void	minus_eat(t_philo *new);
void	checking_time(t_philo *new);
void	*philosophers(void *p);
//death_philo
int		check_max_eat(t_base *philos);
int		check_death_philo(t_base *philos, int i);
int		dead_philo(t_base *philos);
//clear
void	detaching(t_base *philos);
void	joining(t_base *philos);
void	ft_free(t_base *philos, int i);

#endif

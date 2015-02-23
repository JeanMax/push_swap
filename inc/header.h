/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 23:00:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define TRUE 1
# define FALSE 0
# define STOP_BRUTE 5
# define QUIET_WHITE 0
# define COUNT_WHITE 1
# define VERBO_WHITE 2
# define DEBUG_WHITE 3
# define QUIET_COLOR 4
# define COUNT_COLOR 5
# define VERBO_COLOR 6
# define DEBUG_COLOR 7
# define USAGE_MSG "-c: color\n-v: verbose\n-d: debug\n-n: count"
# define DOBLE_MSG "You can't give the same number twice."
# define USAGE 0
# define MALLOC 1
# define SA 0
# define RA 1
# define RRA 2
# define PA 3
# define SB 4
# define RB 5
# define RRB 6
# define PB 7
# define SS 8
# define RR 9
# define RRR 10
# define STOP 11

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct		s_env
{
	int		*stack_a;
	int		*stack_b;
	int		*stack_s;
	int		*stack_t;
	int		size_max;
	int		size_a;
	int		size_b;
	t_char	debug;
};

/*
** prototypes
*/
void		error(char error, char *msg);
void		print_tab(int *st, int size, char *msg, t_char debug);
t_char		print_moves(t_char *moves, t_env *e);
void		print_move(t_char moves, t_char dbg);
void		move(t_char move, t_env *e);
t_char		brute(t_env *e);
t_char		soft(t_env *e);
void		cpy_itab(int *src, int *dest, int len);

#endif

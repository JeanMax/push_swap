/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/10 07:20:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define TRUE 1
# define FALSE 0
# define STOP_BRUTE 9
# define MAX_MOVES 512
# define QUIET_WHITE 0
# define VERBO_WHITE 1
# define DEBUG_WHITE 2
# define QUIET_COLOR 3
# define VERBO_COLOR 4
# define DEBUG_COLOR 5
# define USAGE_MSG "-c: color mod\n-v: verbose mod\n-d: debug mod"
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
# define END 42
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>  //debug

/*
** struct && typedef
*/
typedef unsigned char	t_char;
typedef struct s_env	t_env;
struct	s_env
{
	int		*stack_a;
	int		*stack_b;
	int		*stack_s;
	t_char	size_max;
	t_char	size_a;
	t_char	size_b;
	t_char	debug;
};

/*
** prototypes
*/
void		error(char error, char *msg);
void		print_tab(int *st, t_char size, char *msg, t_char debug);
t_char		print_moves(t_char *moves, t_char debug);
void		print_move(t_char moves, t_char dbg);
void		move(t_char move, t_env *e);
t_char		algo(t_env *e);
void		cpy_itab(int *src, int *dest, t_char len);

#endif

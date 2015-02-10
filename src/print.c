/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:30:59 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/10 05:47:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** printing tab
*/

#include "../inc/header.h"

void			print_tab(int *st, t_char size, char *msg, t_char debug)
{
	t_char		c;

	if (!st)
		return ;
	c = 0;
	debug < QUIET_COLOR ? ft_putstr(msg) : ft_putstr_clr(msg, "g");
	while (c < size)
	{
		debug < QUIET_COLOR ? ft_putnbr(st[c]) : ft_putnbr_clr(st[c], "r");
		ft_putstr(", ");
		c++;
	}
	ft_putendl("\n");
}

void		print_move(t_char moves, t_char dbg)
{
	if (moves == 0)
		dbg < QUIET_COLOR ? ft_putstr("sa ") : ft_putstr_clr("sa ", "r");
	else if (moves == 1)
		dbg < QUIET_COLOR ? ft_putstr("ra ") : ft_putstr_clr("ra ", "r");
	else if (moves == 2)
		dbg < QUIET_COLOR ? ft_putstr("rra ") : ft_putstr_clr("rra ", "r");
	else if (moves == 3)
		dbg < QUIET_COLOR ? ft_putstr("pa ") : ft_putstr_clr("pa ", "r");
	else if (moves == 4)
		dbg < QUIET_COLOR ? ft_putstr("sb ") : ft_putstr_clr("sb ", "r");
	else if (moves == 5)
		dbg < QUIET_COLOR ? ft_putstr("rb ") : ft_putstr_clr("rb ", "r");
	else if (moves == 6)
		dbg < QUIET_COLOR ? ft_putstr("rrb ") : ft_putstr_clr("rrb ", "r");
	else if (moves == 7)
		dbg < QUIET_COLOR ? ft_putstr("pb ") : ft_putstr_clr("pb ", "r");
	else if (moves == 8)
		dbg < QUIET_COLOR ? ft_putstr("ss ") : ft_putstr_clr("ss ", "r");
	else if (moves == 9)
		dbg < QUIET_COLOR ? ft_putstr("rr ") : ft_putstr_clr("rr ", "r");
	else
		dbg < QUIET_COLOR ? ft_putstr("rrr ") : ft_putstr_clr("rrr ", "r");
}

t_char			print_moves(t_char *moves, t_char dbg)
{
	size_t		i;

	i = 0;
	while (moves[i] != STOP)
		i++;
	dbg < QUIET_COLOR ? ft_putnbr(i) : ft_putnbr_clr(i, "y");
	dbg < QUIET_COLOR ? ft_putstr(" moves: ") : ft_putstr_clr(" moves: ", "y");
	while (*moves != STOP)
	{
		print_move(*moves, dbg);
		moves++;
	}
	ft_putendl("\n");
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:30:59 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/15 22:07:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** printing tab
*/

#include "header.h"

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
	ft_putendl("");
}

void			print_move(t_char moves, t_char dbg)
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

static t_char	print_verbose(t_char *moves, t_env *e, size_t i)
{
	t_char		*m_swap;
	int			*s_swap;

	m_swap = moves;
	e->size_a = e->size_max;
	s_swap = e->stack_a;
	e->stack_a = e->stack_s;
	e->size_b = 0;
	while (*moves != STOP)
	{
		move(*moves, e);
		print_move(*moves++, e->debug);
		print_tab(e->stack_a, e->size_a, "\nStack A: ", e->debug);
		print_tab(e->stack_b, e->size_b, "Stack B: ", e->debug);
		ft_putendl("");
	}
	moves = m_swap;
	e->debug < QUIET_COLOR ? ft_putnbr(i) : ft_putnbr_clr(i, "y");
	e->debug < QUIET_COLOR ? ft_putstr(" moves: ") :\
		ft_putstr_clr(" moves: ", "y");
	while (*moves != STOP)
		print_move(*moves++, e->debug);
	ft_putendl("\n");
	e->stack_a = s_swap;
	return (TRUE);
}

t_char			print_moves(t_char *moves, t_env *e)
{
	size_t		i;

	i = 0;
	while (moves[i] != STOP)
		i++;
	if (e->debug == VERBO_WHITE || e->debug == VERBO_COLOR)
		return (print_verbose(moves, e, i));
	if (e->debug == DEBUG_WHITE || e->debug == DEBUG_COLOR)
		ft_putendl("");
	e->debug < QUIET_COLOR ? ft_putnbr(i) : ft_putnbr_clr(i, "y");
	e->debug < QUIET_COLOR ? ft_putstr(" moves: ") :\
		ft_putstr_clr(" moves: ", "y");
	while (*moves != STOP)
	{
		print_move(*moves, e->debug);
		moves++;
	}
	ft_putendl("\n");
	if (e->debug != DEBUG_WHITE && e->debug != DEBUG_COLOR)
	{
		print_tab(e->stack_a, e->size_a, "Stack A: ", e->debug);
		print_tab(e->stack_b, e->size_b, "Stack B: ", e->debug);
	}
	return (TRUE);
}

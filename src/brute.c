/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 01:58:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/10 19:23:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** algorithm solver (brute force)
*/

#include "../inc/header.h"

void			cpy_itab(int *src, int *dest, t_char len)
{
	while (len)
	{
		*dest = *src;
		len--;
		dest++;
		src++;
	}
	*dest = *src;
}

static t_char	is_solved(int *stack_a, t_char size_b)
{
	int			*swap;

	if (size_b)
		return (FALSE);
	swap = stack_a;
	while (*(swap + 1) != END)
	{
		if (*swap > *(swap + 1))
			return (FALSE);
		swap++;
	}
	return (TRUE);
}

static void		launch_moves(t_char *moves, t_env *e)
{
	cpy_itab(e->stack_s, e->stack_a, e->size_max);
	e->size_a = e->size_max;
	e->size_b = 0;
	while (*moves != STOP)
	{
		move(*moves, e);
		if (e->debug == DEBUG_WHITE || e->debug == DEBUG_COLOR)
		{
			ft_putendl("");
			print_move(*moves, e->debug);
			ft_putendl("");
			print_tab(e->stack_a, e->size_a, "Stack A: ", e->debug);
			print_tab(e->stack_b, e->size_b, "Stack B: ", e->debug);
		}
		moves++;
	}
}

static t_char	brute_loop(t_char len, t_char *moves, t_env *e)
{
	t_char		i;

	i = 0;
	while (i < len)
	{
		if (e->debug == DEBUG_WHITE || e->debug == DEBUG_COLOR)
		{
			ft_putendl("");
			ft_debugstr("New", "Move");
			print_tab(e->stack_s, e->size_max, "Stack S: ", e->debug);
		}
		launch_moves(moves, e);
		if (is_solved(e->stack_a, e->size_b))
			return (TRUE);
		(*moves)++;
		i = -1;
		while (moves[++i] == STOP)
		{
			moves[i] = 0;
			moves[i + 1]++;
		}
	}
	return (FALSE);
}

t_char			brute(t_env *e)
{
	t_char		moves[MAX_MOVES];
	t_char		len;

	len = 0;
	ft_bzero((void *)moves, MAX_MOVES);
	if (is_solved(e->stack_a, e->size_b))
		return (TRUE);
	while (++len < STOP_BRUTE)
	{
		ft_bzero((void *)moves, len);
		moves[len] = STOP;
		if (brute_loop(len, moves, e))
			return (print_moves(moves, e));
	}
	return (FALSE);
}

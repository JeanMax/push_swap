/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 18:03:58 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/22 21:43:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** soft solver algo (non-brute :D)
*/

#include "header.h"

void			solve_stack(t_env *e)
{
	int			i;
	int			j;
	int			swap;

	j = e->size_max - 1;
	while (j >= 0)
	{
		i = j - 1;
		while (i >= 0)
		{
			if (e->stack_t[i] < e->stack_t[j])
			{
				swap = e->stack_t[j];
				e->stack_t[j] = e->stack_t[i];
				e->stack_t[i] = swap;
			}
			i--;
		}
		j--;
	}
}

static t_char	is_sorted(t_env *e)
{
	int				*swap;
	int				i;

	swap = e->stack_a;
	i = e->size_a - 1;
	while (i)
	{
		if (*swap < *(swap + 1))
			return (FALSE);
		swap++;
		i--;
	}
	return (TRUE);
}

static t_char	is_in_first_half(t_env *e, int cmp)
{
	int			i;

	i = e->size_a / 2 - 1;
	while (i >= 0)
	{
		if (e->stack_a[i] == cmp)
			return (TRUE);
		i--;
	}
	return (FALSE);
}

static t_char	soft_aux(t_env *e, t_char *moves, int i, int *j)
{
	if (e->stack_t[e->size_max - i - 1] != e->stack_a[e->size_a - 1] &&\
		!is_in_first_half(e, e->stack_t[e->size_max - i - 1]))
	{
		if (e->stack_a[e->size_a - 1] > e->stack_a[e->size_a - 2])
		{
			move(SA, e), moves[*j] = SA, (*j)++;
			if (is_sorted(e))
				return (TRUE);
		}
		if (e->stack_t[e->size_max - i - 1] != e->stack_a[e->size_a - 1])
			move(RA, e), moves[*j] = RA, (*j)++;
	}
	else if (e->stack_t[e->size_max - i - 1] != e->stack_a[e->size_a - 1] &&\
			is_in_first_half(e, e->stack_t[e->size_max - i - 1]))
	{
		if (e->stack_a[e->size_a - 1] > e->stack_a[e->size_a - 2])
		{
			move(SA, e), moves[*j] = SA, (*j)++;
			if (is_sorted(e))
				return (TRUE);
		}
		if (e->stack_t[e->size_max - i - 1] != e->stack_a[e->size_a - 1])
			move(RRA, e), moves[*j] = RRA, (*j)++;
	}
	return (FALSE);
}

t_char			soft(t_env *e)
{
	int			i;
	int			j;
	t_char		moves[MAX_MOVES];

	i = 0;
	j = 0;
	while (!is_sorted(e))
	{
		if (soft_aux(e, moves, i, &j))
			break ;
		if (e->stack_t[e->size_max - i - 1] == e->stack_a[e->size_a - 1])
		{
			move(PB, e), moves[j] = PB, j++;
			i++;
		}
	}
	while (e->size_b > 0)
		move(PA, e), moves[j] = PA, j++;
	moves[j] = STOP;
	return (is_sorted(e) ? print_moves(moves, e) : FALSE);
}

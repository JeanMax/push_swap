/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:11:02 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 22:15:54 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle the 4 basics moves : swap, push, rotate, reverse
*/

#include "header.h"

static void		swap(int *tab, int size)
{
	int			swap;

	if (size < 2)
		return ;
	swap = tab[size - 1];
	tab[size - 1] = tab[size - 2];
	tab[size - 2] = swap;
}

static void		push(t_env *e, t_char am_i_a)
{
	if (!(am_i_a ? e->size_b : e->size_a))
		return ;
	if (am_i_a)
	{
		e->stack_a[e->size_a] = e->stack_b[e->size_b - 1];
		e->size_a++;
		e->size_b--;
	}
	else
	{
		e->stack_b[e->size_b] = e->stack_a[e->size_a - 1];
		e->size_b++;
		e->size_a--;
	}
}

static void		rot(int *tab, int size)
{
	int			swap;

	if (size < 2)
		return ;
	tab += size - 1;
	swap = *tab;
	while (size > 1)
	{
		*tab = *(tab - 1);
		size--;
		tab--;
	}
	*tab = swap;
}

static void		rev(int *tab, int size)
{
	int			swap;
	int			i;

	if (size < 2)
		return ;
	swap = *tab;
	size--;
	i = 0;
	while (i < size)
	{
		*tab = *(tab + 1);
		i++;
		tab++;
	}
	*tab = swap;
}

void			move(t_char move, t_env *e)
{
	if (move % 4 == 0)
	{
		move <= PA ? swap(e->stack_a, e->size_a) : swap(e->stack_b, e->size_b);
		move >= SS ? swap(e->stack_a, e->size_a) : NULL;
	}
	else if (move % 4 == 1)
	{
		move <= PA ? rot(e->stack_a, e->size_a) : rot(e->stack_b, e->size_b);
		move >= SS ? rot(e->stack_a, e->size_a) : NULL;
	}
	else if (move % 4 == 2)
	{
		move <= PA ? rev(e->stack_a, e->size_a) : rev(e->stack_b, e->size_b);
		move >= SS ? rev(e->stack_a, e->size_a) : NULL;
	}
	else
	{
		move <= PA ? push(e, TRUE) : push(e, FALSE);
		move >= SS ? push(e, TRUE) : NULL;
	}
}

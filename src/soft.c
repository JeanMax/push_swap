/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 18:03:58 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 22:46:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** soft solver algo (non-brute :D)
*/

#include "header.h"

static void		solve_stack(int *cmp1, int j)
{
	int		i;
	int		swap;
	int		*cmp2;

	cmp1 += j;
	while (j >= 0)
	{
		i = j - 1;
		cmp2 = cmp1 - 1;
		while (i >= 0)
		{
			if (*cmp2 < *cmp1)
			{
				swap = *cmp1;
				*cmp1 = *cmp2;
				*cmp2 = swap;
			}
			cmp2--;
			i--;
		}
		cmp1--;
		j--;
	}
}

static t_char	is_sorted(t_env *e)
{
	int			*swap;
	int			i;

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
	int			*swap;
	int			i;

	i = e->size_a / 2 - 1;
	swap = e->stack_a;
	while (i >= 0)
	{
		if (*swap == cmp)
			return (TRUE);
		swap++;
		i--;
	}
	return (FALSE);
}

static void		soft_loop(t_env *e, t_char **m, int *t_swap, int *a_swap)
{
	while (!is_sorted(e))
	{
		if (*t_swap != *a_swap)
		{
			if (*a_swap > *(a_swap - 1))
			{
				move(SA, e), **m = SA, (*m)++;
				if (is_sorted(e))
					break ;
			}
			if (*t_swap != *a_swap)
			{
				if (is_in_first_half(e, *t_swap))
					move(RRA, e), **m = RRA, (*m)++;
				else
					move(RA, e), **m = RA, (*m)++;
			}
		}
		else
			move(PB, e), **m = PB, (*m)++, t_swap--, a_swap--;
	}
}

t_char			soft(t_env *e)
{
	t_char		*m;
	t_char		*m_swap;

	if (!(m = (t_char *)malloc((sizeof(t_char) * e->size_max * 5000))))
		error(MALLOC, "moves");
	solve_stack(e->stack_t, e->size_max - 1);
	m_swap = m;
	soft_loop(e, &m, e->stack_t + e->size_max - 1, e->stack_a + e->size_a - 1);
	while (e->size_b > 0)
		move(PA, e), *m = PA, m++;
	*m = STOP;
	if (is_sorted(e))
	{
		print_moves(m_swap, e), ft_memdel((void *)&m_swap);
		return (TRUE);
	}
	return (ft_memdel((void *)&m_swap), FALSE);
}

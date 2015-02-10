/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 17:22:18 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/10 06:51:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** yep, this is the main :)
** mostly checking argv (for flags and error), then launch XXX
*/

#include "../inc/header.h"

static t_char	fill_tab(char *s, t_char j, t_env *e)
{
	char		*tmp;
	t_char		i;

	tmp = s;
	s += *s == '-' ? 1 : 0;
	if (!*s)
		return (FALSE);
	while (*s)
		if (!ft_isdigit((int)*s++))
			return (FALSE);
	e->stack_a[j] = ft_atoi(tmp);
	i = 0;
	while (j)
	{
		while (i < j)
		{
			if (i != j && e->stack_a[i] == e->stack_a[j])
				error(USAGE, DOBLE_MSG);
			i++;
		}
		j--;
	}
	return (TRUE);
}

static void		check_nbr(char *s, t_env *e)
{
	t_char		i;
	char		*tmp;

	i = 0;
	s += *s == '-' ? 1 : 0;
	tmp = s;
	while (*s && ++i)
		if (!ft_isdigit((int)*s++))
			error(USAGE, USAGE_MSG);
	if (i > 10)
		error(USAGE, USAGE_MSG);
	else if (i == 10 && (*tmp > 50 || (*tmp == 50 && *(tmp + 1) > 49)))
		error(USAGE, USAGE_MSG);
	e->size_max++;
}

static void		check_flag(char *s, t_env *e)
{
	t_char		clr;

	if (!*s)
		return ;
	clr = -1;
	while (s[++clr])
		if (ft_isdigit((int)s[clr]))
			return (check_nbr(s, e));
	s++;
	clr = e->debug >= QUIET_COLOR ? QUIET_COLOR : 0;
	e->debug -= clr;
	if (ft_strchr(s, 'v') && e->debug != DEBUG_WHITE)
		e->debug = VERBO_WHITE;
	if (ft_strchr(s, 'd'))
		e->debug = DEBUG_WHITE;
	if (ft_strchr(s, 'c'))
		e->debug += QUIET_COLOR;
	e->debug += e->debug < QUIET_COLOR ? clr : 0;
	while (*s)
	{
		if (*s != 'v' && *s != 'd' && *s != 'c')
			error(USAGE, USAGE_MSG);
		s++;
	}
}

static void		check_av(char **av, t_env *e)
{
	t_char		i;
	t_char		j;

	i = 0;
	while (av[++i])
		av[i][0] == '-' ? check_flag(av[i], e) : check_nbr(av[i], e);
	if (!(e->stack_a = (int *)malloc((sizeof(int) * (e->size_max + 2)))))
		error(MALLOC, "stack_a");
	if (!(e->stack_b = (int *)malloc((sizeof(int) * (e->size_max + 2)))))
		error(MALLOC, "stack_b");
	if (!(e->stack_s = (int *)malloc((sizeof(int) * (e->size_max + 2)))))
		error(MALLOC, "stack_s");
	e->stack_a[e->size_max] = END;
	e->stack_b[e->size_max] = END;
	e->stack_s[e->size_max] = END;
	e->size_a = e->size_max;
	e->size_b = 0;
	e->size_max	< 1 ? error(USAGE, USAGE_MSG) : NULL;
	i = 0;
	j = 0;
	while (av[++i])
		j += fill_tab(av[i], j, e);
	cpy_itab(e->stack_a, e->stack_s, e->size_max);
}

int				main(int ac, char **av)
{
	t_env		e;

	e.size_max = 0;
	e.debug = QUIET_WHITE;
	ac == 1 ? error(USAGE, USAGE_MSG) : NULL;
	check_av(av, &e);
	print_tab(e.stack_a, e.size_a, "Stack A: ", e.debug);
	print_tab(e.stack_b, e.size_b, "Stack B: ", e.debug);
	if (algo(&e))
	{
		print_tab(e.stack_a, e.size_a, "Stack A: ", e.debug);
		print_tab(e.stack_b, e.size_b, "Stack B: ", e.debug);
	}
	else
		failn(":/");
	ft_memdel((void *)&(e.stack_a));
	ft_memdel((void *)&(e.stack_b));
	ft_memdel((void *)&(e.stack_s));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/08 17:11:08 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>

/*
** struct def
*/
typedef struct s_env	t_env;
struct	s_env
{
	int	*stack_a;
	int	*stack_b;
	int	size_stack;
};

/*
** prototypes
*/


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/06 19:13:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

static void		subject(void)
{
	fail("- sa : swap a - intervertit les 2 premiers elements au sommet de la");
	fail(" pile a.\n(ne fait rien s'il n'y en a qu'un ou aucun).\n");
	fail("- sb : swap b - intervertit les 2 premiers elements au sommet de la");
	fail(" pile b.\n(ne fait rien s'il n'y en a qu'un ou aucun).\n");
	fail("- ss : sa et sb en meme temps.\n");
	fail("- pa : push a - prend le premier element au sommet de b et le met");
	fail(" sur a.\n(ne fait rien si b est vide).\n");
	fail("- pb : push b - prend le premier element au sommet de a et le met");
	fail(" sur b.\n(ne fait rien si a est vide).\n");
	fail("- ra : rotate a - decale d'une position tous les elements de la");
	fail(" pile a.\n(vers le haut, le premier element devient le dernier).\n");
	fail("- rb : rotate b - decale d'une position tous les elements de la");
	fail("pile b.\n(vers le haut, le premier element devient le dernier).\n");
	fail("- rr : ra et rb en meme temps.\n- rra : reverse rotate a\n");
	fail("(vers le bas, le dernier element devient le premier).\n");
	fail("- rrb : reverse rotate b\n");
	fail("(vers le bas, le dernier element devient le premier).\n");
	fail("- rrr : rra et rrb en meme temps.\n");
}

void			error(char error, char *msg)
{
	error != SUBJECT ? failn("Error") : NULL;
	if (error == USAGE)
		failn("Usage: ./push_swap -[cvdns] int ..."), failn(msg);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	else if (error == SUBJECT)
		failn(SUBJECT_MSG), subject();
	exit(-1);
}

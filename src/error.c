/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/15 21:58:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void	error(char error, char *msg)
{
	failn("Error");
	if (error == USAGE)
	{
		failn("Usage: ./push_swap [-cvd] [int]...");
		failn(msg);
	}
	else if (error == MALLOC)
	{
		fail("Malloc failed with var: ");
		failn(msg);
	}
	exit(-1);
}

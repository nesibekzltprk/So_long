/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:10:11 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/29 13:10:22 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_solong *solong)
{
	solong->wcount += 1;
	ft_printf("%d\n", solong->wcount);
	if (solong->map[solong->chry][solong->chrx + 1] == 'E'
			&& solong->ccount == 0)
		errorm('s', solong);
	if (solong->map[solong->chry][solong->chrx + 1] == 'C')
		solong->ccount -= 1;
	if (solong->map[solong->chry][solong->chrx + 1] == 'E'
			&& solong->ccount != 0)
		solong->control = 1;
	else if (solong->control == 1)
	{
		solong->map[solong->chry][solong->chrx] = 'E';
		solong->map[solong->chry][solong->chrx + 1] = 'P';
		solong->control = 0;
		solong->chrx += 1;
		putwindow(solong, 0, 0);
		return ;
	}
	solong->map[solong->chry][solong->chrx] = '0';
	solong->map[solong->chry][solong->chrx + 1] = 'P';
	solong->chrx += 1;
	putwindow(solong, 0, 0);
}

void	ft_left(t_solong *solong)
{
	solong->wcount += 1;
	ft_printf("%d\n", solong->wcount);
	if (solong->map[solong->chry][solong->chrx - 1] == 'E'
		&& solong->ccount == 0)
		errorm('s', solong);
	if (solong->map[solong->chry][solong->chrx - 1] == 'C')
		solong->ccount -= 1;
	if (solong->map[solong->chry][solong->chrx - 1] == 'E'
		&& solong->ccount != 0)
		solong->control = 1;
	else if (solong->control == 1)
	{
		solong->map[solong->chry][solong->chrx] = 'E';
		solong->map[solong->chry][solong->chrx - 1] = 'P';
		solong->control = 0;
		solong->chrx -= 1;
		putwindow(solong, 0, 0);
		return ;
	}
	solong->map[solong->chry][solong->chrx] = '0';
	solong->map[solong->chry][solong->chrx - 1] = 'P';
	solong->chrx -= 1;
	putwindow(solong, 0, 0);
}

void	ft_up(t_solong *solong)
{
	solong->wcount += 1;
	ft_printf("%d\n", solong->wcount);
	if (solong->map[solong->chry - 1][solong->chrx] == 'E'
			&& solong->ccount == 0)
		errorm('s', solong);
	if (solong->map[solong->chry - 1][solong->chrx] == 'C')
		solong->ccount -= 1;
	if (solong->map[solong->chry - 1][solong->chrx] == 'E'
			&& solong->ccount != 0)
		solong->control = 1;
	else if (solong->control == 1)
	{
		solong->map[solong->chry][solong->chrx] = 'E';
		solong->map[solong->chry - 1][solong->chrx] = 'P';
		solong->control = 0;
		solong->chry -= 1;
		putwindow(solong, 0, 0);
		return ;
	}
	solong->map[solong->chry][solong->chrx] = '0';
	solong->map[solong->chry - 1][solong->chrx] = 'P';
	solong->chry -= 1;
	putwindow(solong, 0, 0);
}

void	ft_down(t_solong *solong)
{
	solong->wcount += 1;
	ft_printf("%d\n", solong->wcount);
	if (solong->map[solong->chry + 1][solong->chrx] == 'E'
			&& solong->ccount == 0)
		errorm('s', solong);
	if (solong->map[solong->chry + 1][solong->chrx] == 'C')
		solong->ccount -= 1;
	if (solong->map[solong->chry + 1][solong->chrx] == 'E'
			&& solong->ccount != 0)
		solong->control = 1;
	else if (solong->control == 1)
	{
		solong->map[solong->chry][solong->chrx] = 'E';
		solong->map[solong->chry + 1][solong->chrx] = 'P';
		solong->control = 0;
		solong->chry += 1;
		putwindow(solong, 0, 0);
		return ;
	}
	solong->map[solong->chry][solong->chrx] = '0';
	solong->map[solong->chry + 1][solong->chrx] = 'P';
	solong->chry += 1;
	putwindow(solong, 0, 0);
}

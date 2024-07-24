/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:08:58 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/29 19:47:59 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(char **tab, t_point size, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= size.y || x >= size.x)
		return ;
	if (tab[y][x] == 'S' || tab[y][x] == '1')
		return ;
	tab[y][x] = 'S';
	f_fill(tab, size, y - 1, x);
	f_fill(tab, size, y + 1, x);
	f_fill(tab, size, y, x - 1);
	f_fill(tab, size, y, x + 1);
}

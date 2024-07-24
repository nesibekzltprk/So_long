/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:10:35 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/29 17:37:01 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_solong
{
	char	**map;
	char	**mapcopy;
	char	*map_name;
	int		mapy;
	int		mapx;
	int		chrx;
	int		chry;
	int		pcount;
	int		ecount;
	int		ccount;
	int		wcount;
	int		control;
	void	*mlx;
	void	*mlx_win;
	void	*exit;
	void	*wall;
	void	*banana;
	void	*monkey;
	void	*floor;
}	t_solong;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	ft_flood(t_solong *solong);
void	ft_getmap(t_solong *solong);
void	mapcheck(t_solong *solong);
void	ft_left(t_solong *solong);
void	ft_right(t_solong *solong);
void	putwindow(t_solong *solong, int x, int y);
void	ft_up(t_solong *solong);
void	errorm(char c, t_solong *chr);
void	ft_down(t_solong *solong);
void	freemapcpy(t_solong *map);
int		closebutton(t_solong *chr);
void	f_fill(char **tab, t_point size, int y, int x);

#endif

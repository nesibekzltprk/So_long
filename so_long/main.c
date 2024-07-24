/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:09:19 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/30 14:29:47 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension_cnt(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		ft_printf("Invalid map name!\n");
		exit(1);
	}
}

void	upimage(t_solong *solong)
{
	int	x;
	int	y;

	solong->wall = mlx_xpm_file_to_image(solong->mlx,
			"textures/wall.xpm", &x, &y);
	solong->exit = mlx_xpm_file_to_image(solong->mlx,
			"textures/exit.xpm", &x, &y);
	solong->banana = mlx_xpm_file_to_image(solong->mlx,
			"textures/banana.xpm", &x, &y);
	solong->floor = mlx_xpm_file_to_image(solong->mlx,
			"textures/floor.xpm", &x, &y);
	solong->monkey = mlx_xpm_file_to_image(solong->mlx,
			"textures/monkey.xpm", &x, &y);
	if (!solong->monkey || !solong->floor || !solong->banana
		|| !solong->exit || !solong->wall)
		errorm('t', solong);
}

void	putwindow(t_solong *solong, int x, int y)
{
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if (solong->map[y][x] == '1')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->wall, x * 64, y * 64);
			if (solong->map[y][x] == '0')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->floor, x * 64, y * 64);
			if (solong->map[y][x] == 'E')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->exit, x * 64, y * 64);
			if (solong->map[y][x] == 'P')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->monkey, x * 64, y * 64);
			if (solong->map[y][x] == 'C')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->banana, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	ft_move(int keycode, t_solong *solong)
{
	if (keycode == 53)
		errorm('e', solong);
	if ((keycode == 2 || keycode == 124)
		&& (solong->map[solong->chry][solong->chrx + 1] != '1'))
		ft_right(solong);
	if ((keycode == 0 || keycode == 123)
		&& (solong->map[solong->chry][solong->chrx - 1] != '1'))
		ft_left(solong);
	if ((keycode == 1 || keycode == 125)
		&& (solong->map[solong->chry + 1][solong->chrx] != '1'))
		ft_down(solong);
	if ((keycode == 13 || keycode == 126)
		&& (solong->map[solong->chry - 1][solong->chrx] != '1'))
		ft_up(solong);
	return (0);
}

int	main(int ac, char *av[])
{
	t_solong	solong;

	if (ac != 2)
	{
		ft_printf("Not enough argc\n");
		exit(1);
	}
	solong.map_name = av[1];
	extension_cnt(solong.map_name);
	upimage(&solong);
	ft_getmap(&solong);
	mapcheck(&solong);
	ft_flood(&solong);
	solong.wcount = 0;
	solong.mlx = mlx_init();
	solong.mlx_win = mlx_new_window(solong.mlx, solong.mapx * 64,
			solong.mapy * 64, "so_long");
	putwindow(&solong, 0, 0);
	mlx_key_hook(solong.mlx_win, ft_move, &solong);
	mlx_hook(solong.mlx_win, 17, 0, closebutton, &solong);
	mlx_loop(solong.mlx);
}

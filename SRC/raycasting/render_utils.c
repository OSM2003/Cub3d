/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:04:18 by oalananz          #+#    #+#             */
/*   Updated: 2025/09/15 13:02:38 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->utils->width || y < 0
		|| y >= game->map->utils->size)
		return (1);
	return (game->map->map[y][x] == '1');
}

char	get_map_cell(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->utils->width || y < 0
		|| y >= game->map->utils->size)
		return ('1');
	return (game->map->map[y][x]);
}

void	draw_floor_ceiling(t_raycast *raycast)
{
	int		x;
	int		y;
	t_game	*game;

	y = 0;
	game = raycast->game;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y > WINDOW_HEIGHT / 2)
				mlx_put_pixel(raycast->img, x, y, game->map->floor->mixed);
			else
				mlx_put_pixel(raycast->img, x, y, game->map->ceiling->mixed);
			x++;
		}
		y++;
	}
}

int	get_wall_texture(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (ray_dir_y > 0)
			return (1);
		else
			return (0);
	}
}

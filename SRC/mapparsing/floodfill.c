/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:18:06 by qhatahet          #+#    #+#             */
/*   Updated: 2025/09/18 17:56:01 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill_2(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map->utils->m_size
		|| x >= game->map->utils->width)
	{
		printf(RED"Error"WH"\nthere is a hole in the wall\n");
		ft_free_2d(game->map->ff_map);
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (game->map->ff_map[y][x] == '1' || game->map->ff_map[y][x] == '2')
		return ;
	game->map->ff_map[y][x] = '2';
	flood_fill_2(game, y + 1, x);
	flood_fill_2(game, y - 1, x);
	flood_fill_2(game, y, x + 1);
	flood_fill_2(game, y, x - 1);
}

void	flood_fill(t_game *game, int player_y, int player_x)
{
	int	i;
	int	j;

	flood_fill_2(game, player_y, player_x);
	i = 0;
	while (game->map->ff_map[i])
	{
		j = 0;
		while (game->map->ff_map[i][j])
		{
			if (game->map->ff_map[i][j] == '0')
				flood_fill_2(game, i, j);
			j++;
		}
		i++;
	}
}

void	ff_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->ff_map = ft_calloc(game->map->utils->m_size + 1, sizeof(char *));
	if (!game->map->ff_map)
	{
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	while (game->map->map[i])
	{
		game->map->ff_map[i] = ft_strtrim(ft_strdup(game->map->map[i]), "\n");
		if (!game->map->ff_map[i])
		{
			clean_game(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game->map->ff_map[i] = NULL;
}

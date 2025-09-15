/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:14:31 by qhatahet          #+#    #+#             */
/*   Updated: 2025/08/19 13:22:22 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	store_map(t_game *game)
{
	int			i;
	t_map_utils	*utils;

	utils = game->map->utils;
	i = utils->m_start;
	while (!ft_strchr(game->map->fd[i], '1')
		&& !ft_strchr(game->map->fd[i], '0'))
		i++;
	utils->m_start = i;
	count_map_lines(game);
	allocate_map(game);
	i = 0;
	while (game->map->fd[utils->m_start]
		&& i < utils->m_size)
	{
		game->map->map[i] = ft_strdup(game->map->fd[utils->m_start]);
		if (!game->map->map[i])
		{
			clean_game(game);
			exit(EXIT_FAILURE);
		}
		i++;
		utils->m_start++;
	}
	game->map->map[i] = NULL;
}

static void	check_store_map(t_game *game)
{
	check_map_lines(game);
	store_map(game);
	validate_map_elements(game);
	store_player_pos(game);
	ff_map(game);
	flood_fill(game, game->player->column * 0.5, game->player->row * 0.5);
	if (game->map->ff_map)
		ft_free_2d(game->map->ff_map);
}

void	init_map(t_game *game)
{
	map_existance(game);
	store_textures(game);
	check_store_map(game);
}

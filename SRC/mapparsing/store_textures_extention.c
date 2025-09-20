/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures_extention.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:12:50 by qhatahet          #+#    #+#             */
/*   Updated: 2025/09/20 12:20:05 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_game *game)
{
	game->map->textures = ft_calloc(1, sizeof(t_textures));
	game->map->textures->ea = NULL;
	game->map->textures->no = NULL;
	game->map->textures->we = NULL;
	game->map->textures->so = NULL;
	game->map->textures->c = NULL;
	game->map->textures->f = NULL;
}

int	check_flag(t_game *game)
{
	if (game->map->utils->flag->c > 1)
		return (1);
	if (game->map->utils->flag->f > 1)
		return (1);
	if (game->map->utils->flag->w > 1)
		return (1);
	if (game->map->utils->flag->e > 1)
		return (1);
	if (game->map->utils->flag->s > 1)
		return (1);
	if (game->map->utils->flag->n > 1)
		return (1);
	return (0);
}

void	check_duplicate(t_game *game)
{
	int		i;

	i = 0;
	while (game->map->fd[i])
	{
		if (ft_strnstr(game->map->fd[i], "NO", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->n += 1;
		if (ft_strnstr(game->map->fd[i], "SO", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->s += 1;
		if (ft_strnstr(game->map->fd[i], "WE", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->w += 1;
		if (ft_strnstr(game->map->fd[i], "EA", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->e += 1;
		if (ft_strnstr(game->map->fd[i], "C", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->c += 1;
		if (ft_strnstr(game->map->fd[i], "F", ft_strlen(game->map->fd[i])))
			game->map->utils->flag->f += 1;
		i++;
	}
	if (check_flag(game))
	{
		printf(RED"Error"WH"\nduplicate in textures\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
}

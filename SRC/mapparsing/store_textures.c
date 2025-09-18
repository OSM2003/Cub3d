/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:20:47 by qhatahet          #+#    #+#             */
/*   Updated: 2025/09/18 17:15:50 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_textures(t_game *game)
{
	t_textures	*textures;

	textures = game->map->textures;
	textures->no = ft_strtrim(textures->no, " \t\n");
	textures->ea = ft_strtrim(textures->ea, " \t\n");
	textures->we = ft_strtrim(textures->we, " \t\n");
	textures->so = ft_strtrim(textures->so, " \t\n");
	check_specifier(game);
	check_texture_path(game);
	if ((ft_strchr(textures->so, ' ') && ft_strchr(textures->ea, ' ')
			&& ft_strchr(textures->no, ' ') && ft_strchr(textures->we, ' '))
		|| (ft_strchr(textures->so, '\t') && ft_strchr(textures->ea, '\t')
			&& ft_strchr(textures->no, '\t') && ft_strchr(textures->we, '\t')))
	{
		textures->so = textures_path(textures->so);
		textures->no = textures_path(textures->no);
		textures->ea = textures_path(textures->ea);
		textures->we = textures_path(textures->we);
	}
	else
	{
		printf(RED"Error"WH"there is no texture specifier\n");
		clean_game (game);
		exit(EXIT_FAILURE);
	}
}

void	split_texture_protection(t_game *game)
{
	if (!game->map->textures->no)
	{
		printf(RED"Error"WH"\nfailed to store no\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (!game->map->textures->so)
	{
		printf(RED"Error"WH"\nfailed to store so\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (!game->map->textures->we)
	{
		printf(RED"Error"WH"\nfailed to store we\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (!game->map->textures->ea)
	{
		printf(RED"Error"WH"\nfailed to store ea\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
}

void	split_textures_extention(t_game *game, int i)
{
	if (ft_strchr(game->map->fd[i], 'N'))
		game->map->textures->no = ft_strdup(game->map->fd[i]);
	else if (ft_strchr(game->map->fd[i], 'S'))
		game->map->textures->so = ft_strdup(game->map->fd[i]);
	else if (ft_strchr(game->map->fd[i], 'W'))
		game->map->textures->we = ft_strdup(game->map->fd[i]);
	else if (ft_strchr(game->map->fd[i], 'E'))
		game->map->textures->ea = ft_strdup(game->map->fd[i]);
	else if (ft_strchr(game->map->fd[i], 'C'))
		game->map->textures->c = ft_strdup(game->map->fd[i]);
	else if (ft_strchr(game->map->fd[i], 'F'))
		game->map->textures->f = ft_strdup(game->map->fd[i]);
	else
		check_invalid_specifier(game->map->fd[i], game);
}

void	split_textrues(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->fd[i])
	{
		split_textures_extention(game, i);
		if (check_if_stored(game->map->textures))
			break ;
		i++;
	}
	split_texture_protection(game);
	game->map->utils->m_start = i + 1;
}

void	store_textures(t_game *game)
{
	init_textures(game);
	count_file_lines(game);
	read_file(game);
	check_duplicate(game);
	split_textrues(game);
	clean_textures(game);
	validate_colors(game);
	mix_colors(game);
}

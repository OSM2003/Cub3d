/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:30:32 by qhatahet          #+#    #+#             */
/*   Updated: 2025/08/19 13:33:17 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_invalid_specifier(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
		{
			printf(RED"ERROR"WH"\ninvalid char\n");
			clean_game(game);
			exit(EXIT_FAILURE);
		}
	}
}

void	validate_specifier(t_game *game, char *s, char *comp1, char *comp2)
{
	if (!ft_strncmp(s, comp1, 3) || !ft_strncmp(s, comp2, 3))
		return ;
	else
	{
		printf(RED"ERROR"WH"\ntextures specifier should be: NO, WE, SO, EA\n");
		clean_game (game);
		exit(EXIT_FAILURE);
	}
}

void	check_specifier(t_game *game)
{
	validate_specifier(game, game->map->textures->we, "WE ", "WE\t");
	validate_specifier(game, game->map->textures->so, "SO ", "SO\t");
	validate_specifier(game, game->map->textures->ea, "EA ", "EA\t");
	validate_specifier(game, game->map->textures->no, "NO ", "NO\t");
}

static void	check_path(char *str, t_game *game)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		word_count++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
	}
	if (word_count != 2)
	{
		printf(RED"ERROR"WH"\nwrong texture\n");
		clean_game(game);
		exit(EXIT_FAILURE);
	}
}

void	check_texture_path(t_game *game)
{
	check_path(game->map->textures->no, game);
	check_path(game->map->textures->we, game);
	check_path(game->map->textures->ea, game);
	check_path(game->map->textures->so, game);
}

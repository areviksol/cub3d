/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:29:48 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/21 18:08:02 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i])
	{
		free(mtx[i]);
		mtx[i] = NULL;
	}
	free(mtx);
	mtx = NULL;
}

void	free_cub(t_cub map)
{
	free_mtx(map.map);
	free(map.so);
	free(map.no);
	free(map.ea);
	free(map.we);
}

void	free_game(t_game *game)
{
	free(game->mlx);
	free(game->win);
	free(game->no);
	free(game->so);
	free(game->ea);
	free(game->we);
	game->mlx = NULL;
	game->win = NULL;
	game->no = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->we = NULL;
}

void	free_all(t_addres *address)
{
	int	i;

	i = -1;
	free_cub(*address->cub);
	free_game(address->game);
	while (++i < 5)
	{
		free(address->img[i].img);
		free(address->img[i].ptr);
	}
	free(address->rcasting);
	free(address->index);
	free(address->game);
	free(address->img);
	address->rcasting = NULL;
	address->index = NULL;
	address->game = NULL;
	address->img = NULL;
	free(address->cub);
}

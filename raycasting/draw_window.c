/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:49:13 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/20 17:04:59 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	initializer(t_addres *address)
{
	address->game->mlx = mlx_init();
	address->game->win = mlx_new_window(address->game->mlx, WIDTH, \
	HEIGHT, "IT IS MY CUB3D!");
	address->game->no = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->no, &address->img[1].width, &address->img[1].height);
	address->game->so = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->so, &address->img[2].width, &address->img[2].height);
	address->game->ea = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->ea, &address->img[3].width, &address->img[3].height);
	address->game->we = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->we, &address->img[4].width, &address->img[4].height);
	address->game->f_color = create_trgb(address->cub->f[0], \
	address->cub->f[1], address->cub->f[2]);
	address->game->c_color = create_trgb(address->cub->c[0], \
	address->cub->c[1], address->cub->c[2]);
	if (address->game->mlx == NULL || address->game->win == NULL)
		close_game(address);
	if (address->game->no == NULL || address->game->so == NULL)
	{
		close_game(address);
	}
	if (address->game->we == NULL || address->game->ea == NULL)
		close_game(address);
}

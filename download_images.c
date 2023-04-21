/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:14:21 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/21 14:49:17 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_imges(t_map *map)
{
	int	w;
	int	h;

	map->img_w = 50;
	map->img_h = 50;
	map->imgn = mlx_xpm_file_to_image(map->mlx, \
	map->result2[0], &map->img_w, &map->img_h);
	printf("after draw\n");
	map->imgs = mlx_xpm_file_to_image(map->mlx, \
	map->result2[1], &map->img_w, &map->img_h);
	map->imgw = mlx_xpm_file_to_image(map->mlx, \
	map->result2[2], &map->img_w, &map->img_h);
	map->imge = mlx_xpm_file_to_image(map->mlx, \
	map->result2[3], &map->img_w, &map->img_h);
	if (!map->imgn || !map->imgs || !map->imgw || !map->imge)
		return (ft_perror("Not valid image path"));
	free_mtx(map->result2);
	return (1);
}

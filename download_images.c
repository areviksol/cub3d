/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:14:21 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/16 15:00:06 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_imges(t_map *map)
{
	int	w;
	int	h;
    
    map->img_w = 50;
    map->img_h = 50;
		printf("bfore draw\n");

	map->imgn = mlx_xpm_file_to_image(map->mlx, \
	map->result2[0], &map->img_w, &map->img_h);
	printf("after draw\n");
	map->imgs = mlx_xpm_file_to_image(map->mlx, \
	map->result2[1], &map->img_w, &map->img_h);
    map->imgw = mlx_xpm_file_to_image(map->mlx, \
	map->result2[2], &map->img_w, &map->img_h);
    map->imge = mlx_xpm_file_to_image(map->mlx, \
	map->result2[3], &map->img_w, &map->img_h);
    if(!map->imgn || !map->imgs || !map->imgw || !map->imge)
	    return ft_perror("Not valid image path");
    return (1);
}
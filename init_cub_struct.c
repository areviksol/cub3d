/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:33:33 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/20 16:16:06 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_cub_color(t_map *map, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		cub->c[i] = map->c[i];
		cub->f[i] = map->f[i];
		i++;
	}
}

void	init_cub(t_map *map, t_cub *cub)
{
	int	i;

	cub->map = map->map;
	i = 0;
	while (map->texture[i])
	{
		if (map->texture[i][0] == 'N' && map->texture[i][1] == 'O')
			cub->no = ft_substr(map->texture[i], 3, \
			ft_strlen(map->texture[i]) - 3);
		if (map->texture[i][0] == 'S' && map->texture[i][1] == 'O')
			cub->so = ft_substr(map->texture[i], 3, \
			ft_strlen(map->texture[i]) - 3);
		if (map->texture[i][0] == 'W' && map->texture[i][1] == 'E')
			cub->we = ft_substr(map->texture[i], 3, \
			ft_strlen(map->texture[i]) - 3);
		if (map->texture[i][0] == 'E' && map->texture[i][1] == 'A')
			cub->ea = ft_substr(map->texture[i], 3, \
			ft_strlen(map->texture[i]) - 3);
		i++;
	}
	init_cub_color(map, cub);
}

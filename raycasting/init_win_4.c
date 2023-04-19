/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:52:14 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/14 19:32:03 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_get_data_addr(t_addres *address)
{
	address->img[1].img = mlx_get_data_addr \
	(address->game->no, &address->img[1].bpp, \
	&address->img[1].size_line, &address->img[1].endian);
	address->img[2].img = mlx_get_data_addr \
	(address->game->so, &address->img[2].bpp, \
	&address->img[2].size_line, &address->img[2].endian);
	address->img[3].img = mlx_get_data_addr \
	(address->game->ea, &address->img[3].bpp, \
	&address->img[3].size_line, &address->img[3].endian);
	address->img[4].img = mlx_get_data_addr \
	(address->game->we, &address->img[4].bpp, \
	&address->img[4].size_line, &address->img[4].endian);
}

int	check_nwse(t_addres *address)
{
	int	n;

	n = 1;
	if (address->rcasting->side == 1 && address->rcasting->raydiry < 0)
		n = 3;
	else if (address->rcasting->side == 1 && address->rcasting->raydiry > 0)
		n = 4;
	else if (address->rcasting->side == 0 && address->rcasting->raydirx > 0)
		n = 2;
	else if (address->rcasting->side == 0 && address->rcasting->raydirx < 0)
		n = 1;
	return (n);
}

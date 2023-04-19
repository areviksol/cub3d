/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:52:36 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/16 14:56:08 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_pos_player(t_addres *address)
{
	int	i;
	int	j;

	i = 0;
	// printf(">>%s<<\n", address->data.map[i]);
	while (address->data.map[i])
	{
		j = 0;
		while (address->data.map[i][j])
		{
			if (address->data.map[i][j] == 'N' || \
				address->data.map[i][j] == 'S' || \
				address->data.map[i][j] == 'E' || \
				address->data.map[i][j] == 'W')
			{
				init_player_pos(address, i, j);
				address->rcasting->posx = i + 0.5;
				address->rcasting->posy = j + 0.5;
				address->data.map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	norm_init_win_2(t_addres *address)
{
	address->rcasting->hit = 0;
	while (address->rcasting->hit == 0)
	{
		if (address->rcasting->sidedistx < address->rcasting->sidedisty)
		{
			address->rcasting->sidedistx += address->rcasting->deltadistx;
			address->rcasting->mapx += address->rcasting->stepx;
			address->rcasting->side = 0;
		}
		else
		{
			address->rcasting->sidedisty += address->rcasting->deltadisty;
			address->rcasting->mapy += address->rcasting->stepy;
			address->rcasting->side = 1;
		}
		if (address->data.map[address->rcasting->mapx] \
		[address->rcasting->mapy] != '0')
			address->rcasting->hit = 1;
	}
	norm_init_win_3(address);
}

void	norm_init_win(t_addres *address)
{
	if (address->rcasting->raydiry < 0)
	{
		address->rcasting->stepy = -1;
		address->rcasting->sidedisty = (address->rcasting->posy - \
		address->rcasting->mapy) * address->rcasting->deltadisty;
	}
	else
	{
		address->rcasting->stepy = 1;
		address->rcasting->sidedisty = (address->rcasting->mapy + 1.0 - \
		address->rcasting->posy) * address->rcasting->deltadisty;
	}
	norm_init_win_2(address);
}

void	continue_init_win(t_addres *address)
{
	if (address->rcasting->raydirx == 0)
		address->rcasting->deltadistx = 1e30;
	else
		address->rcasting->deltadistx = ft_abs(1 / address->rcasting->raydirx);
	if (address->rcasting->raydiry == 0)
		address->rcasting->deltadisty = 1e30;
	else
		address->rcasting->deltadisty = ft_abs(1 / address->rcasting->raydiry);
	if (address->rcasting->raydirx < 0)
	{
		address->rcasting->stepx = -1;
		address->rcasting->sidedistx = (address->rcasting->posx - \
		address->rcasting->mapx) * address->rcasting->deltadistx;
	}
	else
	{
		address->rcasting->stepx = 1;
		address->rcasting->sidedistx = (address->rcasting->mapx + 1.0 - \
		address->rcasting->posx) * address->rcasting->deltadistx;
	}
	norm_init_win(address);
}

void	init_win(t_addres *address)
{
	int	i;

	i = 0;
	find_pos_player(address);
	address->img[0].ptr = mlx_new_image(address->game->mlx, WIDTH, HEIGHT);
	address->img[0].img = mlx_get_data_addr(address->img[0].ptr, \
	&address->img[0].bpp, &address->img[0].size_line, &address->img[0].endian);
	ft_get_data_addr(address);
	while (i < WIDTH)
	{
		address->game->index = i;
		address->rcasting->camerax = 2 * i / (double)WIDTH - 1;
		address->rcasting->raydirx = address->rcasting->dirx + \
		address->rcasting->planex * address->rcasting->camerax;
		address->rcasting->raydiry = address->rcasting->diry + \
		address->rcasting->planey * address->rcasting->camerax;
		address->rcasting->mapx = (int)address->rcasting->posx;
		address->rcasting->mapy = (int)address->rcasting->posy;
		continue_init_win(address);
		i++;
	}
	mlx_put_image_to_window(address->game->mlx, address->game->win, \
	address->img[0].ptr, 0, 0);
}

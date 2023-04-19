/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:53:14 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/14 19:32:13 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rotate_right(t_addres *address, double rotate)
{
	double	old_pos;

	old_pos = address->rcasting->dirx;
	address->rcasting->dirx = old_pos * cos(rotate) - \
	address->rcasting->diry * sin(rotate);
	address->rcasting->diry = old_pos * sin(rotate) + \
	address->rcasting->diry * cos(rotate);
	old_pos = address->rcasting->planex;
	address->rcasting->planex = old_pos * cos(rotate) - \
	address->rcasting->planey * sin(rotate);
	address->rcasting->planey = old_pos * sin(rotate) + \
	address->rcasting->planey * cos(rotate);
}

void	move_left(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx - address->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->data.map[x][y] == '0')
		address->rcasting->posx -= address->rcasting->planex * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy - address->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (address->data.map[x][y] == '0')
		address->rcasting->posy -= address->rcasting->planey * MOVE_SPEED;
}

void	move_right(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx + address->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->data.map[x][y] == '0')
		address->rcasting->posx += address->rcasting->planex * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy + address->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (address->data.map[x][y] == '0')
		address->rcasting->posy += address->rcasting->planey * MOVE_SPEED;
}

void	move_up(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx + \
	address->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->data.map[x][y] == '0')
		address->rcasting->posx += address->rcasting->dirx * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy + \
	address->rcasting->diry * (MOVE_SPEED + 0.1));
	if (address->data.map[x][y] == '0')
		address->rcasting->posy += address->rcasting->diry * MOVE_SPEED;
}

void	move_down(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx - \
	address->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->data.map[x][y] == '0')
		address->rcasting->posx -= address->rcasting->dirx * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy - \
	address->rcasting->diry * (MOVE_SPEED + 0.1));
	if (address->data.map[x][y] == '0')
		address->rcasting->posy -= address->rcasting->diry * MOVE_SPEED;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:51:02 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/14 19:31:58 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*get_correct_arg(char *ptr)
{
	int		i;
	int		j;
	char	*new_arg;

	new_arg = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] != ' ' && ptr[i] != '\t')
		{
			new_arg[j] = ptr[i];
			j++;
		}
		i++;
	}
	new_arg[j] = '\0';
	return (new_arg);
}

void	init_plane(t_addres *address, double i, double j)
{
	address->rcasting->planex = i;
	address->rcasting->planey = j;
}

void	init_dir(t_addres *address, double i, double j)
{
	address->rcasting->dirx = i;
	address->rcasting->diry = j;
}

void	init_player_pos(t_addres *address, int i, int j)
{
	if (address->data.map[i][j] == 'S')
	{
		init_dir(address, 1, 0);
		init_plane(address, 0, -0.66);
	}
	else if (address->data.map[i][j] == 'N')
	{
		init_dir(address, -1, 0);
		init_plane(address, 0, 0.66);
	}
	else if (address->data.map[i][j] == 'E')
	{
		init_dir(address, 0, 1);
		init_plane(address, 0.66, 0);
	}
	else if (address->data.map[i][j] == 'W')
	{
		init_dir(address, 0, -1);
		init_plane(address, -0.66, 0);
	}
}

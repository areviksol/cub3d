/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:24:15 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/24 18:47:39 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_cordination(char **map, int x, int y)
{
	if (x == 0)
		return (0);
	if (ft_strlen(map[x - 1]) < (size_t)y)
		return (0);
	if (!map[x - 1] || !map[x - 1][y] || \
	(map[x - 1][y] != '1' && map[x - 1][y] != '0' && \
	map[x - 1][y] != 'N' && map[x - 1][y] != 'S' && \
	map[x - 1][y] != 'E' && map[x - 1][y] != 'W'))
		return (0);
	if (!map[x + 1] || !map[x + 1][y] || \
	(map[x + 1][y] != '1' && map[x + 1][y] != '0' && \
	map[x + 1][y] != 'N' && map[x + 1][y] != 'S' && \
	map[x + 1][y] != 'E' && map[x + 1][y] != 'W'))
		return (0);
	if (!map[x] || !map[x][y - 1] || \
	(map[x][y - 1] != '1' && map[x][y - 1] != '0' && \
	map[x][y - 1] != 'N' && map[x][y - 1] != 'S' && \
	map[x][y - 1] != 'E' && map[x][y - 1] != 'W'))
		return (0);
	if (!map[x] || !map[x][y + 1] || \
	(map[x][y + 1] != '1' && map[x][y + 1] != '0' && \
	map[x][y + 1] != 'N' && map[x][y + 1] != 'S' && \
	map[x][y + 1] != 'E' && map[x][y + 1] != 'W'))
		return (0);
	return (1);
}

int	zroyi_koghy_mek(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && !ft_isspace(map[0][i]))
			return (ft_perror("Error \n"));
		i++;
	}
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'W' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'N' ) \
			&& (!check_cordination(map, i, j)))
				return (ft_perror("Error: not valid map\n"));
			j++;
		}
	}
	return (1);
}

int	is_map_okay(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[6][i])
	{
		if (array[6][i] != '1' && !ft_isspace(array[6][i]))
			return (ft_perror("error1\n"));
		i++;
	}
	j = count_string_length(array) - 1;
	i = 0;
	while (array[j][i])
	{
		if (array[j][i] != '1' && !ft_isspace(array[j][i]))
			return (ft_perror("error2\n"));
		i++;
	}
	return (1);
}

void	epur_texture(char **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		texture[i] = epurstr(texture[i]);
		i++;
	}
}

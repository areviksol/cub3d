/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:10:27 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/26 16:05:14 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_symbol_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (*map)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		map++;
	}
	return (count);
}

int	check_news(char **map)
{
	int	n;
	int	s;
	int	e;
	int	w;

	n = get_symbol_count(map, 'N');
	w = get_symbol_count(map, 'W');
	e = get_symbol_count(map, 'E');
	s = get_symbol_count(map, 'S');
	if ((n + s + w + e) != 1)
		return (ft_perror("Error: wrong player count\n"));
	return (1);
}

int	check_map_symbols(char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		if (*map[i] != '0' && *map[i] != '1' && *map[i] != ' ' && \
		*map[i] != 'N' && *map[i] != 'S' && *map[i] != 'E' && *map[i] != 'W')
			return (ft_perror("not valid symbol exist in map\n"));
		map++;
	}
	return (1);
}

int	check_the_char(char c)
{
	if (c && (c == ' '))
		return (0);
	return (1);
}

int	check_empty_line(char **playfield)
{
	int	len;
	int	i;

	len = count_string_length(playfield);
	i = 0;
	while (playfield[i])
	{
		if ((playfield[i] == NULL || \
		!ft_strcmp(playfield[i], "")) && i != len - 1)
			return (ft_perror("Error: Empty line\n"));
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:17 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/27 12:54:29 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void	get_textures(char **map, t_map *m)
{
	int	i;

	i = 0;
	m->texture = (char **)malloc(sizeof(char *) * 7);
	while (i < 6)
	{
		m->texture[i] = map[i];
		i++;
	}
	m->texture[i] = NULL;
}

int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_playfield(char **map, t_map *m)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	i = 6;
	flag = 0;
	m->playfield = (char **)malloc(sizeof(char *) * \
	count_string_length(map) - 6);
	while (map[i])
	{
		if (is_empty_string(map[i]))
			flag = 1;
		if (!is_empty_string(map[i]) && flag)
		{
			write(2, "Error: Empty line\n", 18);
			exit(1);
		}
		m->playfield[j] = map[i];
		i++;
		j++;
	}
	m->playfield[j] = NULL;
}

int	count_string_length(char **array)
{
	int	length;

	length = 0;
	if (array == NULL)
		return (length);
	while (*array != NULL)
	{
		length++;
		array++;
	}
	return (length);
}

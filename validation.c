/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:17 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/26 15:18:28 by rkochary         ###   ########.fr       */
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

	j = 0;
	i = 6;
	m->playfield = (char **)malloc(sizeof(char *) * \
	count_string_length(map) - 6);
	while (map[i])
	{
		if (is_empty_string(map[i]))
		{
			printf("Error: Empty line \n");
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

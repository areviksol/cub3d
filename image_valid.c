/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:49:34 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/26 15:54:39 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 4)
	{
		write(2, "error\n", 6);
		exit(1);
	}
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	isimagevalid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".xpm"))
			{
				return ;
			}
		}
		file_line++;
	}
	write(2, "image is not valid", 19);
	exit(1);
}

void	chgitem2(t_map *map, int i)
{
	if (!ft_strcmp("NO", map->result[i]) || \
	!ft_strcmp("SO", map->result[i]) || \
	!ft_strcmp("EA", map->result[i]) || !ft_strcmp("WE", map->result[i]))
		isimagevalid(map->result2[i]);
}

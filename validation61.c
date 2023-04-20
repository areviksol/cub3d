/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation61.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:45:12 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/20 17:03:54 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_color_helper(t_map *map, char	**arr)
{
	if (count_string_length(arr) != 3)
		return (ft_perror("Error: not valid symbols\n"));
	map->term[0] = ft_atoi(arr[0]);
	map->term[1] = ft_atoi(arr[1]);
	map->term[2] = ft_atoi(arr[2]);
	free_mtx(arr);
	return (1);
}

int	valid_color(char *str, t_map *map)
{
	char	*nums;
	char	**arr;
	int		i;
	char	*p;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	nums = ft_substr2(str, i, ft_strlen(str) - 2);
	arr = ft_split(nums, ',');
	free(nums);
	i = 0;
	p = NULL;
	while (arr[i])
	{
		p = arr[i];
		arr[i] = ft_strtrim(arr[i], " \r\v\f\t");
		if (!is_digital_str(arr[i]))
			return (ft_perror("Error: not valid symbols\n"));
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
			return (ft_perror("Error: not valid symbols\n"));
		free(p);
		i++;
	}
	return (valid_color_helper(map, arr));
}

int	is_digital_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_result(char	**arr)
{
	if (!(!strcmp(arr[0], "NO" ) || !strcmp(arr[0], "SO") \
	|| !strcmp(arr[0], "EA") || !strcmp(arr[0], "WE")))
		free_mtx(arr);
	else
	{
		free(arr);
	}
}

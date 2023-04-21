/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:43:51 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/21 19:14:32 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_helper(t_map *aaa, char **array, char **argv)
{
	isfilevalid(argv[1]);
	aaa->map = array;
	get_textures(array, aaa);
	get_playfield(array, aaa);
	check_empty_line(aaa->playfield);
	if (!check_news(aaa->playfield))
		exit(1);
	if (!check_map_symbols(aaa->playfield))
		exit(1);
	if (!zroyi_koghy_mek(aaa->playfield))
		exit(1);
	if (!is_map_okay(array))
		exit(1);
	epur_texture(aaa->texture);
	if (!validate_color_texture(aaa->texture, 6))
		exit(1);
}

void	main_helper2(t_map *aaa)
{
	aaa->result = (char **)malloc(sizeof(char *) * (7));
	aaa->result2 = (char **)malloc(sizeof(char *) * (7));
	if (!chgitem(aaa->texture, aaa))
		exit(1);
	if (!substring_appears_once(aaa->result, "NO"))
		exit(1);
	if (!substring_appears_once(aaa->result, "SO"))
		exit(1);
	if (!substring_appears_once(aaa->result, "EA"))
		exit(1);
	if (!substring_appears_once(aaa->result, "WE"))
		exit(1);
	if (!validate_colors(aaa->texture, aaa))
		exit(1);
}

void	free_texture(t_map *aaa)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(aaa->texture[i]);
		i++;
	}
	free(aaa->texture);
	aaa->texture = NULL;
}

void	main_h(t_map *aaa, char **array, t_cub *cub, char **argv)
{
	main_helper(aaa, array, argv);
	main_helper2(aaa);
	init_cub(aaa, cub);
}

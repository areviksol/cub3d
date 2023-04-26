/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:45:08 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/26 15:49:23 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	isfilevalid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".cub"))
			{
				return ;
			}
		}
		file_line++;
	}
	write(2, "file is not valid", 17);
	exit(1);
}

int	ft_exit(t_map *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
}

t_data	data_collector(t_cub cub, t_map map)
{
	t_data	data;

	(void)cub;
	data.map = map.playfield;
	data.x = -1;
	data.y = -1;
	return (data);
}

int	main(int argc, char **argv)
{
	t_addres	addres;
	char		**array;
	t_map		aaa;

	addres.cub = malloc(sizeof(t_cub));
	array = getmap("map.cub");
	if (argc == 2)
	{
		main_h(&aaa, array, addres.cub, argv);
		init_structs(&addres);
		addres.data = data_collector(*addres.cub, aaa);
		initializer(&addres);
		init_win(&addres);
		mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
		mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
		mlx_loop(addres.game->mlx);
	}
	else
		ft_perror("arg count is not 2\n");
	return (0);
}

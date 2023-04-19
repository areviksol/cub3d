#include "cub.h"

size_t	ft_strlen2(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}


static int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
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

void	ft_error(t_map ***v, char *err)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	perror(err);
	exit(1);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}


void	isaroundwalls(t_map **v)
{
	int		i;
	char	*err;

	err = "map is not surrounded by walls";
	if (check_line((*v)->map[0]))
		ft_error(&v, err);
	i = getheightofmap((*v)->map) - 1;
	while (i)
	{
		if ((*v)->map[i][0] != '1' ||
			(*v)->map[i][ft_strlen((*v)->map[i]) - 1] != '1')
		{
			ft_error(&v, err);
		}
		i--;
	}
	if (check_line((*v)->map[getheightofmap((*v)->map) - 1]))
		ft_error(&v, err);
}

// int worldMap[mapWidth][mapHeight]=
// {
//   {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
//   {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//   {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//   {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//   {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//   {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
//   {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
//   {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
//   {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
//   {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
//   {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
//   {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//   {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// };
// void render(void *mlx)
// {
//     // Call your rendering function
//     // ...
    
//     // Introduce a delay to achieve desired frame rate
//     usleep(1000000 / FRAME_RATE_LIMIT); // Sleep for 1 second divided by the frame rate limit
// }


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

int ft_perror(char *str)
{
	write(2, str, ft_strlen(str));
	return 0;
}
/*
	if (open(filename, O_RDONLY) == -1)
	{
		ft_printf("invalid map\n");
		return (0);
	}
*/

void	getter_cub(t_data *data, t_cub cub)
{
	int		i;
	char	**map;

	i = -1;
	while (cub.map[++i])
		;
	map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!map)
		return ;
	i = -1;
	while (cub.map[++i])
		map[i] = ft_strdup(cub.map[i]);
	map[i] = 0;
	data->map = map;
}

t_data	data_collector(t_cub cub, t_map map)
{
	t_data	data;

	data.map = map.playfield;
	data.x = -1;
	data.y = -1;
	//getter_cub(&data, cub);
	printf("x is %d\n", data.pos_x);
	printf("y is %d\n", data.pos_y);
	// while(map.playfield[++data.x])
	// {
	// 	printf( ">>>%s\n", map.playfield[++data.x]);
	// 	data.y = -1;
	// 	while(map.playfield[data.x][data.y])
	// 	{
	// 		if(map.playfield[data.x][data.y] == 'E' || \
	// 		map.playfield[data.x][data.y] == 'N' || \
	// 		map.playfield[data.x][data.y] == 'S' || \
	// 		map.playfield[data.x][data.y] == 'W')
	// 		{
	// 			data.pos_x = data.x;
	// 			data.pos_y = data.y;
	// 		}
	// 		++data.y;
	// 	}
	// }
	// while (data.map[++(data.y)])
	// {
	// 	data.x = -1;
	// 	while (data.map[++data.y])
	// 	{
	// 		if (data.map[data.x][data.y] == 'E' || \
	// 		data.map[data.x][data.y] == 'N' \
	// 		|| data.map[data.x][data.y] == 'S' || \
	// 		data.map[data.x][data.y] == 'W')
	// 		{
	// 			data.pos_x = data.x;
	// 			data.pos_y = data.y;
	// 			break ;
	// 		}
	// 	}
	// }
	printf("x is %d\n", data.pos_x);
	printf("y is %d\n", data.pos_y);
	return (data);
	// data.x = -1;
	// data.y = -1;
}

int	main(int argc, char **argv)
{
	t_addres addres;

	addres.cub = malloc(sizeof(t_cub));

	if(argc == 2)
	{
		isfilevalid(argv[1]);
		char **array = getmap("map.cub");
		t_map *aaa = malloc(sizeof(t_map));
		//parser
		// aaa->mlx = mlx_init();
		// if (aaa->mlx == NULL)
    	 	//return ft_perror("Failed to initialize mlx");
		aaa->map = array;


		printf("?????????????\n");
		get_textures(array, aaa);
		get_playfield(array, aaa);
		check_empty_line(aaa->playfield);
		if(!check_news(aaa->playfield))
			exit(1); 
		if(!check_map_symbols(aaa->playfield))
			exit(1);
		if(!zroyi_koghy_mek(aaa->playfield))
			exit(1);
		if(!is_map_okay(array))
			exit(1);
		epur_texture(aaa->texture);
		if(!validate_color_texture(aaa->texture, 6))
			exit(1);
		aaa->result = (char **)malloc(sizeof(char *) * (7));
		aaa->result2 = (char **)malloc(sizeof(char *) * (7));
		if(!chgitem(aaa->texture, aaa))
			exit(1);
		 if(!substring_appears_once(aaa->result, "NO"))
			exit(1);
		 if(!substring_appears_once(aaa->result, "SO"))
		 	exit(1);
		 if(!substring_appears_once(aaa->result, "EA"))
			exit(1);
		 if(!substring_appears_once(aaa->result, "WE"))
		 	exit(1);
		if(!validate_colors(aaa->texture, aaa))
			exit(1);
		init_cub(aaa, addres.cub);
		init_structs(&addres);
		addres.data = data_collector(*addres.cub, *aaa);
		//printf("fcvdb");
		initializer(&addres);
		init_win(&addres);
		int i = 0;
		while(i < 6)
		{
			free(aaa->texture[i]);
			i++;
		}
		free(aaa->texture);
		aaa->texture = NULL;
		mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
		mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
		mlx_loop(addres.game->mlx);
		 create_imges(aaa);
		// while(1) 
		// 	;
		//valid_color();

	}else
		ft_perror("arg count is not 2\n");
	return (0);
}

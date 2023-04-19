#include "cub.h"

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void get_textures(char **map, t_map *m)
{
    int i;
    i = 0;

    m->texture = (char **)malloc(sizeof(char *) * 7);
    while(i < 6)
    {
        m->texture[i] = map[i];
        i++;
    }
    m->texture[i] = NULL;
}

int is_empty_string(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!ft_isspace(str[i]))
            return 0;
        i++;
    }
    return 1; 
}

void get_playfield(char **map, t_map *m)
{
    int i;
    i = 6;
    int j = 0;
    m->playfield = (char **)malloc(sizeof(char *) * countStringLength(map) - 6);
    while(map[i])
    {
        if(is_empty_string(map[i]))
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

int countStringLength(char **array) 
{
    int length = 0;
    if (array == NULL) {
        // Handle NULL pointer input
        return length;
    }

    // Iterate through the array until we reach a NULL pointer
    while (*array != NULL) {
        length++;
        array++;
    }

    return length;
}

int get_symbol_count(char **map, char c)
{
    int i;
    i = 0;
    int j = 0;
    int count = 0;
    while(*map)
    {   
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == c) 
                count++;
            j++;        
        }
        map++;
    }
    return count;
}

int check_news(char **map)
{
    int n =  get_symbol_count(map, 'N'); 
    int w =  get_symbol_count(map, 'W');  
    int e =  get_symbol_count(map, 'E');  
    int s =  get_symbol_count(map, 'S'); 
    if((n + s + w + e) != 1)
    {
        return ft_perror("Error: wrong player count\n");
    }
    return 1;
}

int check_map_symbols(char **map)
{
    int i;
    i = 0;
    
    while(*map)
    {
        if(*map[i]!= '0' && *map[i] != '1' && *map[i] != ' ' && *map[i] != 'N' && *map[i] != 'S' && *map[i] != 'E' && *map[i] != 'W') 
            return ft_perror("not valid symbol exist in map\n");       
        map++;
    }
    return 1;
}

int check_the_char(char c)
{
    if(c && (c == ' '))
        return 0;
    return 1;
}

int check_empty_line(char **playfield)
{
    int len;
    int i;
    len = countStringLength(playfield);
    i = 0;
    	while(playfield[i])
		{
			if((playfield[i] == NULL || !strcmp(playfield[i], "")) && i != len - 1)
                return ft_perror("Error: Empty line\n");
            i++;
		}
        return (1);
}

int	check_cordination(char **map, int x, int y)
{
	if (x == 0)
		return (0);
    if(ft_strlen(map[x-1]) < y)
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

int zroyi_koghy_mek(char **map)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[0][i] != '\0')
    {
        if(map[0][i] != '1' && !ft_isspace(map[0][i]) )
        {
            return ft_perror("Error \n");
        }
        i++;
    }
    i = 1;
    while(map[i])
    {
       j = 0;
        while(map[i][j])
        {
            if((map[i][j] == '0' || map[i][j] == 'W' ||  map[i][j] == 'S' ||  map[i][j] == 'E' ||  map[i][j] == 'N' ) \
            &&  (!check_cordination(map, i, j)))
            {
                return ft_perror("Error: not valid map\n");
            }
            j++;
        }
        i++;
    }
    return 1;
}



int is_map_okay(char **array)
{
    int i = 0;
    while(array[6][i])
    {
        if(array[6][i] != '1' && !ft_isspace(array[6][i]))
            return ft_perror("error1\n");
        i++;
    }
    int j = countStringLength(array) - 1;
    i = 0;
    while(array[j][i])
    {
        if(array[j][i] != '1' && !ft_isspace(array[j][i]))
            return ft_perror("error2\n");
        i++;
    }

    return 1;
}


void epur_texture(char **texture)
{
    int i;
    i = 0;

    while(texture[i])
    {
        texture[i] = epurstr(texture[i]);
        i++;
    }
}


int validate_color_texture(char** texture, int numLines) 
{
    bool foundMap = false;
    bool foundTextures = false;
    bool foundFloorColor = false;

    for (int i = 0; i < numLines; i++) {
        char* line = texture[i];
        if (!foundTextures && (strncmp(line, "NO", 2) == 0 || strncmp(line, "SO", 2) == 0 ||
                                strncmp(line, "WE", 2) == 0 || strncmp(line, "EA", 2) == 0)) {
            foundTextures = 1;
            continue;
        }
        if (!foundFloorColor && strncmp(line, "F", 1) == 0) {
            foundFloorColor = 1;
            continue;
        } 
    }
    if (!foundTextures) {
        return ft_perror("Error: Textures element not found.\n");
    }

    if (!foundFloorColor) {
        return  ft_perror("Error: Floor color element not found.\n");
    }
    return 1;
}
// && (!strcmp(arr[0], "NO" ) || !strcmp(arr[0], "SO") || !strcmp(arr[0], "EA") || !strcmp(arr[0],  "WE") )
int chgitem(char **texture, t_map *map)
{
    int i = 0;
    char **arr;
    int flag;
    flag = 0;
    while(i < 6)
    {
        arr = NULL;
        arr = ft_split(texture[i], ' ');
        if(countStringLength(arr) != 2 && (!strcmp(arr[0], "NO" ) || !strcmp(arr[0], "SO") || !strcmp(arr[0], "EA") || !strcmp(arr[0],  "WE") ))
        {
            flag = 1;
        }
        map->result[i] = arr[0];
        map->result2[i] = arr[1];
        // if(!(!strcmp(arr[0], "NO" ) || !strcmp(arr[0], "SO") || !strcmp(arr[0], "EA") || !strcmp(arr[0],  "WE") ))
        //     free_mtx(arr);
        // else{
        //     free(arr);
      //  }
        i++;
    }
    map->result[i] = NULL;
    map->result2[i] = NULL;
    if(flag)
    {
        return ft_perror("Error: split size is not 2\n");
    }
    return 1;
}

int substring_appears_once(char **arr, char *sub) 
{
    int count = 0;

    for (int i = 0; i < 6; i++) {
        if (strcmp(arr[i], sub) == 0) {
            count++;
            if (count > 1) {
                return ft_perror("Error: substring appears more than once.\n");
            }
        }
    }
    if (count == 0) {
        return ft_perror("Error: substring doesnt appear\n");
    }
    return 1;
}

char	*ft_substr2(char *s, int start, int len)
{
	char	*ret;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

int validate_colors(char **texture, t_map * map)
{
    int count_f = 0;
    int count_c = 0;;
    int index_f = 0;
    int index_c = 0;
    int i = 0;
    char * r = 0;
    char * g = 0;
    char * b = 0;
    
    while(i < 6)
    {
        if(texture[i][0] == 'F' && texture[i][1] && ft_isspace(texture[i][1]))
        {
            index_f = i;
            count_f++;
        }
        if(texture[i][0] == 'C' && texture[i][1] && ft_isspace(texture[i][1]))
        {
            index_c = i;
            count_c++;
        }
        i++;
    }
    if(count_c != 1 || count_f != 1)
        return ft_perror("Error: wrong color arguments\n");
    if(!(texture[index_c][2] >= '0' && texture[index_c][2] <= '9'))
        return ft_perror("Error: not valid symbols\n");
    if(!(texture[index_f][2] >= '0' && texture[index_f][2] <= '9'))
        return ft_perror("Error: not valid symbols\n");
    if(!valid_color(texture[index_c], map))
    {
        return 0;
    }
    map->c[0] = map->term[0];
    map->c[1] = map->term[1];
    map->c[2] = map->term[2];
    if(!valid_color(texture[index_f], map))
    {       
        return 0;
    }
    map->f[0] = map->term[0];
    map->f[1] = map->term[1];
    map->f[2] = map->term[2];
    return (1);
}

int is_digital_str(char *str)
{
    int i;
    i = 0;

    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}


int valid_color(char *str, t_map *map)
{
    char *nums;
    char **arr;
    int i;
    i = 0;

    while(!ft_isdigit(str[i]))
    {
        i++;
    }
    nums = ft_substr2(str,i,ft_strlen(str) - 2);
    arr = ft_split(nums,',');
    free(nums);
    i = 0;
    char * p= NULL;

    while(arr[i])
    {
        p = arr[i];
        arr[i] = ft_strtrim(arr[i]," \r\v\f\t");
        if(!is_digital_str(arr[i]))
            return ft_perror("Error: not valid symbols\n");
        if(ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
            return ft_perror("Error: not valid symbols\n");
        free(p);
        i++;
    }
    if(countStringLength(arr) != 3)
        return ft_perror("Error: not valid symbols\n");
    map->term[0] = ft_atoi(arr[0]);
    map->term[1] = ft_atoi(arr[1]);
    map->term[2] = ft_atoi(arr[2]);
    free_mtx(arr);

    return (1);
}


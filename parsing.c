#include "cub.h"


size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	int		res;
	size_t	i;

	i = 0;
	res = ft_strlen((char *)src);
	if (len == 0)
		return (res);
	while (i < len - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (len > i)
		dest[i] = 0;
	return (res);
}


// char	*ft_strdup(const char *s1)
// {
// 	char	*new;
// 	int		len;

// 	if (!s1)
// 		return (NULL);
// 	len = ft_strlen((char *)s1);
// 	new = (char *)malloc(len + 1);
// 	if (!new)
// 		return (NULL);
// 	ft_strlcpy(new, s1, len + 1);
// 	return (new);
// }


int	tab_count(char	*str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	return (count);
}

char	*open_tabs(char *str, int count)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * ((count * 3) + len) + 1);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
		{
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
		}
		else
			line[++j] = str[i];
	}
	line[++j] = '\0';
	return (line);
}

char	*reset_tabs(char *str)
{
	char	*line;
	int		count;

	if (!str)
		return (NULL);
	count = tab_count(str);
	if (count == 0)
		return (ft_strdup(str));
	line = open_tabs(str, count);
	return (line);
}

void clean_tabs(char **map)
{
    int i;
    i = 0;
    char *ptr;
    while(map[i])
    {
        ptr = map[i];
        map[i] = reset_tabs(ptr);
       free(ptr);
        i++;
    }
}

void parser (t_map *map)
{
    if(!map->map || !*map->map)
        exit(1);
    clean_tabs(map->map);
	
}

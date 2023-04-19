#include "cub.h"

int	find_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (0);
	}
	return (-1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*c1;
	unsigned const char	*c2;
	size_t				i;
	size_t				n;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	n = ft_strlen(s2);
	c1 = (unsigned const char *)s1;
	c2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if ((c1[i] != c2[i] || s1[i] == 0) || s2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}



char	**getmap(char *filename)
{
	int		fd;
	char	*full_line;
	char	**map;

	fd = open(filename, O_RDONLY);
	map = NULL;
	if (fd == -1)
		return (NULL);
	full_line = read_map(fd);
	map = ft_split(full_line, '\n');
	//free(full_line);//seg
	close(fd);
	return (map);
}

void	norm_read_map(char **full_line, char **line, int *flag)
{
	char	*ptr;

	ptr = *full_line;
	if (find_char(*line) == 0 || *flag > 6)
	{
		(*flag)++;
		if (ft_strcmp(*line, "\n") == 0)
		{
			free(*line);
			*line = ft_strdup("    \n");
		}
		if (*full_line == NULL)
			*full_line = ft_strdup(*line);
		else
			*full_line = ft_strjoin(ptr, *line);
		free(ptr);//seg
	}
}

char	*read_map(int fd)
{
	char	*line;
	char	*full_line;
	int		flag;

	flag = 0;
	full_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		norm_read_map(&full_line, &line, &flag);
		free(line);
		line = get_next_line(fd);
	}
	return (full_line);
}
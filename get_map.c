#include "cub.h"

static void	throwmessage(void)
{
	perror("Error");
	exit(1);
}

int	getheightofmap(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	helper(int cond)
{
	if (cond)
		throwmessage();
}

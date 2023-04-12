#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
# include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "get_next_line.h"
#include <unistd.h>

typedef  struct s_map 
{
    char	        **texture;
    char            **playfield;
    // char            *NO;
    // char            *WE;
    // char            *SO;
    // char            *EA;
    char            **map; 
    int             height;
    int             width;
    void			*mlx;
	void			*imgn;
    void			*imgw;
    void			*imge;
    void			*imgs;
    int             img_w;
    int             img_h;
	void			*win;
    int				win_w;
	int				win_h;
    char            **result;
    char            **result2;
} t_map;



void	isfilevalid(char *file_line);
char	**getmap(char *path);
void	isfilevalid(char *file_line);
// size_t	ft_nb_len(int nb);
// char	*ft_strdup(const char *s1);
// int	count_strings(char const *s, char c);
// char	*malloc_strings(const char *s, char c);
// char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void clean_tabs(char **map);
size_t	ft_strlen2(const char *c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
// char	**getmap(char *path);
int	getheightofmap(char **map);
char	**getmap(char *filename);
void	norm_read_map(char **full_line, char **line, int *flag);
char	*read_map(int fd);
void get_textures(char **map, t_map *m);
void get_playfield(char **map, t_map *m);
int is_north(char **texture);
int countStringLength(char **array);


int	count_strings(char *s, char c);
void	free_strings(char **tab);
char	*malloc_strings(char *s, char c);
char	**split_loop(char *s, char c, int i, int words);
char	**ft_split(char *s, char c);



bool isValidMapElement(char c) ;
bool validateMap(char** map, int mapRows, int mapCols);
bool validateMapFile(char** fileLines, int numLines) ;
int ft_perror(char *str);
int zroyi_koghy_mek(char **map);
int is_map_okay(char **array);
char *epurstr(char *s);
void epur_texture(char **texture);
int validate_color_texture(char** texture, int numLines);
int substring_appears_once(char **arr, char *sub); 
int chgitem(char **texture, t_map *map);

int	create_imges(t_map *map);
#endif
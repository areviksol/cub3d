/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:53:01 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/04/20 13:56:39 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	count_strings(char *s, char c)
{
	int	act_pos;
	int	str_count;

	act_pos = 0;
	str_count = 0;
	if (s[act_pos] == c)
		str_count--;
	while (s[act_pos] != '\0')
	{
		if (s[act_pos] == c && s[act_pos + 1] != c && s[act_pos + 1] != '\0')
			str_count++;
		act_pos++;
	}
	str_count++;
	return (str_count);
}

void	free_strings(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*malloc_strings(char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_loop(char *s, char c, int i, int words)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
	{
		return (NULL);
	}
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = malloc_strings(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int		words;
	int		i;

	i = 0;
	if (!s || *s == '\0')
		return (NULL);
	words = count_strings(s, c);
	if (words == 0)
		return (NULL);
	return (split_loop(s, c, i, words));
}

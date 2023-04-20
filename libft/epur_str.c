/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:06:32 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/20 13:32:05 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

char	*epurstr(char *s)
{
	int		len;
	char	*new_str;
	char	*p;

	len = ft_strlen(s);
	while (len && ft_isblank(s[len - 1]))
		--len;
	while (len && ft_isblank(*s) && *s++)
		--len;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	p = new_str;
	while (len--)
	{
		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))
			*p++ = *s;
		s++;
	}
	*p = '\0';
	return (new_str);
}

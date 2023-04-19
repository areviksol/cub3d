/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:43:05 by rkochary          #+#    #+#             */
/*   Updated: 2023/04/16 14:48:09 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substring;
// 	size_t	i;
// 	size_t	slen;

// 	i = 0;
// 	if (ft_strlen(s) < start)
// 	{
// 		substring = malloc(sizeof(char));
// 		substring[0] = '\0';
// 		return (substring);
// 	}
// 	slen = ft_strlen(s + start);
// 	if (slen < len)
// 		len = slen;
// 	substring = (char *)malloc(len);
// 	if (!substring)
// 		return (0);
// 	while (i < len)
// 	{
// 		substring[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	substring[i] = '\0';
// 	return (substring);
// }
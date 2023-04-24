/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:54:16 by suhovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:40:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	close_game(t_addres *address)
{
	mlx_destroy_window(address->game->mlx, address->game->win);
	write(1, "Game closed successfully\n", \
	ft_strlen("Game closed successfully\n"));
	free_all(address);
	while(1)
		;
	exit(0);
}

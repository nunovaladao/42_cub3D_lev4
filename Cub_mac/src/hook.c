/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/18 20:02:22 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keyboard_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_exit(data);
	return (0);
}

int	hook_events(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, (void *)mlx_exit, data);
	mlx_key_hook(data->mlx_win, &keyboard_hook, data);
	return (0);
}

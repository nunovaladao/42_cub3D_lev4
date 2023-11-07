/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:28 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/07 11:59:37 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void free_map(t_map *m)
{
    int i;

    i = -1;
    /* if (m->n_texture)
        free(m->n_texture);
    if (m->s_texture)
        free(m->s_texture);
    if (m->w_texture)
        free(m->w_texture);
    if (m->e_texture)
        free(m->e_texture); */
    if (m->worldMap)
    {
        while (++i < m->nr_rows)
            free(m->worldMap[i]);
        free(m->worldMap);
    }
}

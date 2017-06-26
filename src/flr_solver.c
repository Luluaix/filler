/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:33:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:29:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			flr_solver(void)
{
	t_data		*data;
	__uint128_t x;
	int			y;

	data = v_data();
	x = (__uint128_t)0;
	y = data->pce_lines - 1;
	data->player[2] = 0;
	while ((x = flr_test_pos(x, y, y, data->pce_lines - 1))
	<= (__uint128_t)data->map_col)
	{
		flr_set_position(data->current_pce, x, y, data->pce_lines - 1);
		x++;
		if (data->map_col - x - data->pce_col >= (__uint128_t)data->map_col)
			if (!(x &= ~x) && ++y >= data->map_lines)
				break ;
	}
	data->pos_y += data->current_pce[0];
	data->pos_x += data->current_pce[1];
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_set_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:39:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:31:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

void	flr_set_position(int *pce, __uint128_t x, int y, int yp)
{
	int			next_pce[2];

	ft_bzero(next_pce, sizeof(int) * 2);
	if (x != (__uint128_t)(v_data()->map_col - v_data()->pce_col + 1))
	{
		next_pce[0] = y - yp;
		next_pce[1] = v_data()->map_col - x - v_data()->pce_col;
		if (!(pce[0] | pce[1]))
		{
			pce[0] = next_pce[0];
			pce[1] = next_pce[1];
		}
		flr_strat(v_data(), pce, next_pce);
	}
}

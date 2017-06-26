/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_test_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:16:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:34:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

int			flr_zero_bit(__uint128_t line_1, __uint128_t line_2)
{
	return (!(line_1 & line_2));
}

int			flr_one_bit(__uint128_t line_1, __uint128_t line_2)
{
	__uint128_t tmp;

	if (!(tmp = line_1 & line_2))
		return (0);
	return (!(tmp & (tmp - 1)));
}

int			flr_many_bit(__uint128_t line_1, __uint128_t line_2)
{
	if (flr_zero_bit(line_1, line_2))
		return (0);
	return (!flr_one_bit(line_1, line_2));
}

int			flr_test_zero_bit(t_data *data, __uint128_t x, int *y, int *yp)
{
	if (flr_zero_bit(data->pce[*yp] << x, data->him[*y]))
	{
		if (*yp == 0)
			return (1);
		*y -= 1;
		*yp -= 1;
		while (flr_zero_bit(data->pce[*yp] << x, data->both[*y]))
		{
			if (*yp == 0)
				return (1);
			*y -= 1;
			*yp -= 1;
		}
	}
	return (0);
}

__uint128_t	flr_test_pos(int x, int y, int y_start, int yp)
{
	while (x <= v_data()->map_col - v_data()->pce_col)
	{
		yp = v_data()->pce_lines - 1;
		while (flr_many_bit(v_data()->pce[yp] << x, v_data()->me[y])
		&& x <= v_data()->map_col - v_data()->pce_col - 1)
			x++;
		while (flr_zero_bit(v_data()->pce[yp] << x, v_data()->both[y]))
		{
			y--;
			yp--;
			if (yp <= 0)
				break ;
		}
		if (yp >= 0 && y >= 0
			&& flr_one_bit(v_data()->pce[yp] << x, v_data()->me[y]))
			if (flr_test_zero_bit(v_data(), x, &y, &yp))
				return (x);
		y = y_start;
		x++;
	}
	return (x);
}

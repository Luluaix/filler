/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_get_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:05:24 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:32:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

void	flr_trim_pce(int lines, int col)
{
	while (--col)
	{
		while (++lines < v_data()->pce_lines && !(v_data()->pce[lines] & _1))
			;
		if (lines == v_data()->pce_lines)
		{
			while (lines--)
				(v_data()->pce[lines] >>= _1);
			v_data()->pce_col--;
		}
		else
		{
			lines = -1;
			while (++lines < v_data()->pce_lines)
				if ((v_data()->pce[lines] >> (__uint128_t)col) & _1)
					break ;
			if (lines == v_data()->pce_lines)
			{
				v_data()->pce_col--;
				v_data()->pos_x--;
			}
			else
				break ;
		}
	}
}

void	flr_set_pce(int lines, int col)
{
	while (!v_data()->pce[0] && v_data()->pce_lines && (lines = -1))
	{
		while (++lines < v_data()->pce_lines)
			v_data()->pce[lines] = v_data()->pce[lines + 1];
		v_data()->pos_y--;
		v_data()->pce_lines--;
	}
	while (v_data()->pce_lines && !v_data()->pce[v_data()->pce_lines - 1])
		v_data()->pce_lines--;
	flr_trim_pce(-1, col);
}

int		flr_get_piece(char *line, int lines, int col)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	j = -1;
	while (++i < lines)
	{
		if ((ret = get_next_line(0, &line)) < 1)
			flr_error(GNL, FILE, FUNC, LINE);
		v_data()->line = line;
		if (ft_strlen(line) != (size_t)v_data()->pce_col)
			return (flr_error(BAD_LINES_PCE, FILE, FUNC, LINE));
		while (line[++j])
			if (line[j] != '.')
			{
				if (line[j] != '*')
					return (flr_error(PB_PCE, FILE, FUNC, LINE));
				v_data()->pce[i] |= _1 << (col - j - 1);
			}
		j = -1;
		ft_strdel(&v_data()->line);
	}
	return (1);
}

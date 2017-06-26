/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:34 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:26:13 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

void	ft_set_line(char *line, char *player, int i, int j)
{
	v_data()->both[i] |= _1 << (v_data()->map_col - j - 1);
	if (line[j + 4] == player[0])
	{
		if (!v_data()->pos)
			v_data()->pos = j;
		v_data()->me[i] |= (_1 << (v_data()->map_col - j - 1));
		*err() |= 0b01;
	}
	if (line[j + 4] == player[1])
	{
		v_data()->him[i] |= (_1 << (v_data()->map_col - j - 1));
		*err() |= 0b10;
	}
	if (line[j + 4] != player[0] && line[j + 4] != player[1])
		*err() &= 0b011;
}

int		flr_get_map(char *line, int lines)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	j = -1;
	ft_strdel(&line);
	*err() = 0b100;
	while (++i < lines)
	{
		if ((ret = get_next_line(0, &line)) < 1)
			return (flr_error(GNL, FILE, FUNC, LINE));
		v_data()->line = line;
		if (line && ft_strlen(&line[4]) != (size_t)v_data()->map_col)
			return (flr_error(BAD_LINES, FILE, FUNC, LINE));
		while (line[++j + 4])
			if (line[j + 4] != '.')
				ft_set_line(line, v_data()->player, i, j);
		j = -1;
		if (i + 1 == lines && (*err() & 0b111) != 0b111)
			return (flr_error(PB_PLAYER, FILE, FUNC, LINE));
		ft_strdel(&v_data()->line);
	}
	return (1);
}

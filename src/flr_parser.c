/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:03:03 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:30:50 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		flr_get_coordonnees_piece(char *line)
{
	int		i;

	i = 6;
	if (ft_strncmp(line, "Piece ", 6))
		return (flr_error(BAD_PLATEAU_PCE, FILE, FUNC, LINE));
	if (!ft_isdigit(line[6]))
		return (flr_error(BAD_COORD_PCE, FILE, FUNC, LINE));
	if (!(v_data()->pce_lines = ft_atoi(&line[6])))
		return (flr_error(BAD_LINES_PCE, FILE, FUNC, LINE));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!(v_data()->pce_col = ft_atoi(&line[i])))
		return (flr_error(BAD_COL_PCE, FILE, FUNC, LINE));
	v_data()->pce = ft_memalloc(sizeof(__uint128_t) *
	(v_data()->pce_lines + 1));
	return (1);
}

int		flr_get_coordonnees_map(char *line)
{
	int		i;

	i = 8;
	if (ft_strncmp(line, "Plateau ", 8))
		return (flr_error(BAD_PLATEAU, FILE, FUNC, LINE));
	if (!ft_isdigit(line[8]))
		return (flr_error(BAD_COORD, FILE, FUNC, LINE));
	if (!(v_data()->map_lines = ft_atoi(&line[8])))
		return (flr_error(BAD_LINES, FILE, FUNC, LINE));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!(v_data()->map_col = ft_atoi(&line[i])))
		return (flr_error(BAD_COL, FILE, FUNC, LINE));
	v_data()->both = ft_memalloc(sizeof(__uint128_t) * v_data()->map_lines);
	v_data()->me = ft_memalloc(sizeof(__uint128_t) * v_data()->map_lines);
	v_data()->him = ft_memalloc(sizeof(__uint128_t) * v_data()->map_lines);
	ft_strdel(&v_data()->line);
	return (1);
}

int		flr_parser(void)
{
	char	*line;
	int		i;
	int		ret;

	i = -1;
	line = NULL;
	while (++i < 3 && (ret = get_next_line(0, &line) > 0))
	{
		v_data()->line = line;
		if (i == 0 && flr_get_coordonnees_map(line) < 0)
			return (-1);
		if (i == 1 && flr_get_map(line, v_data()->map_lines) < 0)
			return (-1);
		if (i == 2 && flr_get_coordonnees_piece(line) < 0)
			return (-1);
		if (i == 2 &&
			flr_get_piece(line, v_data()->pce_lines, v_data()->pce_col) < 0)
			return (-1);
	}
	v_data()->line = line;
	return (ret);
}

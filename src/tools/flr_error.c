/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:28:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:32:33 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

void	flr_free(int err, t_data *data)
{
	data = v_data();
	ft_memdel((void **)&data->line);
	ft_memdel((void **)&data->me);
	ft_memdel((void **)&data->him);
	ft_memdel((void **)&data->both);
	ft_memdel((void **)&data->pce);
	if (err == NOT_YET)
		ft_bzero(data, sizeof(t_data) - sizeof(char *) - 4);
	else
		ft_bzero(data, sizeof(t_data));
}

int		flr_error(int err, char *file, char *function, int line)
{
	ft_printf("%@\n=====================================================\n", 2);
	ft_printf("%@|{red}ERROR :{eoc}\n", 2);
	ft_printf("%@|{mag}   File{eoc}     : %s\n", 2, file);
	ft_printf("%@|{cya}   Function{eoc} : %s\n", 2, function);
	ft_printf("%@|{yel}   Line{eoc}     : %d\n", 2, line);
	ft_printf("%@=====================================================\n\n", 2);
	err == GNL ? ft_printf("%@FILE PROBLEM\n\n", 2) : 0;
	err == BAD_PLAYER ? ft_printf("%@BAD PLAYER\n\n", 2) : 0;
	err == BAD_PLATEAU ? ft_printf("%@BAD PLATEAU\n\n", 2) : 0;
	err == BAD_COORD ? ft_printf("%@BAD COORDONNEES\n\n", 2) : 0;
	err == BAD_LINES ? ft_printf("%@BAD LINES\n\n", 2) : 0;
	err == BAD_COL ? ft_printf("%@BAD COLUMN\n\n", 2) : 0;
	err == BAD_PLATEAU_PCE ? ft_printf("%@BAD PLATEAU PIECE\n\n", 2) : 0;
	err == BAD_COORD_PCE ? ft_printf("%@BAD PIECE COORDONNEES\n\n", 2) : 0;
	err == BAD_LINES_PCE ? ft_printf("%@BAD PIECE LINES\n\n", 2) : 0;
	err == BAD_COL_PCE ? ft_printf("%@BAD PIECE COLUMN\n\n", 2) : 0;
	err == PB_PLAYER ? ft_printf("%@PROBLEM PLAYER\n\n", 2) : 0;
	err == PB_PCE ? ft_printf("%@PROBLEM PIECE\n\n", 2) : 0;
	err == END ? ft_printf("%@FIN\n\n", 2) : 0;
	flr_free(err, v_data());
	return (-1);
}

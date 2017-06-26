/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:19:57 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:30:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_display(__uint128_t *me, __uint128_t *him, int lines)
{
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	i = 0;
	fd1 = open("/dev/ttys001", O_WRONLY);
	fd2 = open("/dev/ttys002", O_WRONLY);
	fd3 = open("/dev/ttys003", O_WRONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
		return ;
	ft_printf("%@\e[1;1H\e[2J", fd1);
	ft_printf("%@\e[1;1H\e[2J", fd2);
	ft_printf("%@\e[1;1H\e[2J", fd3);
	while (i < lines)
	{
		ft_printf("%@%+.*kb\n", fd1, v_data()->map_col, me[i]);
		ft_printf("%@%+.*kb\n", fd2, v_data()->map_col, him[i]);
		ft_printf("%@%+.*kb\n", fd3, v_data()->map_col, v_data()->both[i]);
		i++;
	}
	ft_printf("%@\n\n", fd1);
	ft_printf("%@\n\n", fd2);
	ft_printf("%@\n\n", fd3);
}

int		main(void)
{
	char	*player;
	int		ret;

	player = NULL;
	if (get_next_line(0, &player) < 0)
		return (flr_error(GNL, FILE, FUNC, LINE));
	v_data()->line = player;
	if (!flr_get_player(player))
		return (flr_error(BAD_PLAYER, FILE, FUNC, LINE));
	ft_strdel(&player);
	while ((ret = flr_parser()) > 0)
	{
		flr_solver();
		ft_printf("%d %d\n", v_data()->pos_y, v_data()->pos_x);
		ft_display(v_data()->me, v_data()->him, v_data()->map_lines);
		flr_free(NOT_YET, v_data());
	}
	flr_free(END, v_data());
	ft_printf("%d %d\n", v_data()->pos_y, v_data()->pos_x);
	return (ret);
}

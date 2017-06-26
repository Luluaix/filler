/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_get_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:53:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/21 18:40:37 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

int		flr_get_player(char *player)
{
	if (ft_strlen(player) > 10)
	{
		if (player[10] == '1' || player[10] == '2')
		{
			v_data()->player[0] = (player[10] == '1' ? 'O' : 'X');
			v_data()->player[1] = (player[10] == '1' ? 'X' : 'O');
			v_data()->player[2] = player[10] == '1' ? '1' : '2';
			return (1);
		}
	}
	return (0);
}

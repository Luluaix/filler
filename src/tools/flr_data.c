/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:27:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/22 14:50:31 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

t_data	*v_data(void)
{
	static t_data	data;

	return (&data);
}

int		*err(void)
{
	static int	err = 0;

	return (&err);
}

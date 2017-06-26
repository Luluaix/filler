/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fill_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:24:04 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/26 19:30:32 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	prf_fill_data(char **data, int len)
{
	if (!*data)
		return ;
	while (**data && len--)
		prf_fill_c(*(*data)++);
	*data = NULL;
}

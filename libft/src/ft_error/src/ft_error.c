/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:39:22 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:22:54 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_error.h"

char	*g_error[10] =
{
	"You have a bad malloc",
	"You try to free something not malloc",
	"coucou"
};

int		ft_error(int code, ...)
{
	va_list		ap;
	int			fd;

	fd = FD;
	va_start(ap, code);
	ft_printf("%@\n{red}Erreur %d -%s-{eoc}\n\n", FD, code, g_error[code]);
	ft_printf("%@  {cya}File     = %s{eoc}\n", FD, va_arg(ap, char *));
	ft_printf("%@  {gre}Function = %s\n{eoc}", FD, va_arg(ap, char *));
	ft_printf("%@  {mag}Line     = %d\n{eoc}\n", FD, va_arg(ap, int));
	return (-1);
}

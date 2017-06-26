/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:40:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/08 19:22:31 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# define INFO	__FILE__, __FUNCTION__, __LINE__ - 1
# define FD		2

# define BAD_MALLOC 0
# define BAD_FREE	1

int		ft_printf(const char *format, ...);
int		ft_error(int code, ...);

#endif

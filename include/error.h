/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:43:15 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:48:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <string.h>
# include <stdio.h>
# define FILE __FILE__
# define FUNC (char *)__FUNCTION__
# define LINE __LINE__
# define GNL 				0
# define END 				1
# define BAD_PLAYER 		2
# define BAD_PLATEAU 		3
# define BAD_COORD 			4
# define BAD_LINES 			5
# define BAD_COL 			6
# define PB_PLAYER			7
# define BAD_PLATEAU_PCE	8
# define BAD_COORD_PCE		9
# define BAD_LINES_PCE		10
# define BAD_COL_PCE		11
# define PB_PCE				12
# define NOT_YET			13

typedef struct s_error	t_error;

struct		s_error
{
	int		err;
};

int			*err(void);
int			flr_error(int err, char *file, char *function, int line);

#endif

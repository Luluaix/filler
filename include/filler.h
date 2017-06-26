/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:18:46 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:49:24 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/include/libft.h"
# include "../include/error.h"
# define _1		(__uint128_t)1
# define _0		(__uint128_t)0

typedef struct s_data	t_data;

struct			s_data
{
	int			pos_x;
	int			pos_y;
	int			map_lines;
	int			map_col;
	int			pce_lines;
	int			pce_col;
	int			current_pce[2];
	int			next[2];
	char		*line;
	__uint128_t	*pce;
	__uint128_t	*both;
	__uint128_t	*me;
	__uint128_t	*him;
	int			pos;
	char		player[3];
};

int				main(void);
void			flr_free(int err, t_data *data);
t_data			*v_data(void);

/*
** PARSING.
*/

int				flr_parser(void);
int				flr_get_player(char *player);
int				flr_get_map(char *line, int lines);
int				flr_get_piece(char *line, int lines, int col);

/*
** SOLVING.
*/

int				flr_solver(void);
__uint128_t		flr_test_pos(int x, int y, int y_start, int yp);
void			flr_set_position(int *pce, __uint128_t x, int y, int yp);
void			flr_strat(t_data *data, int *current, int *next);

#endif

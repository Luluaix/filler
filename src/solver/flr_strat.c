/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_strat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:43:32 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/26 21:35:57 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/filler.h"

int		flr_get_score(int *pce, int *target, int lines, int col)
{
	int		score;
	int		piece[2];

	piece[0] = (pce[0] + pce[0] + lines) / 2;
	piece[1] = (pce[1] + pce[1] + col) / 2;
	lines = ABS((pce[0] - target[0]));
	col = ABS((pce[1] - target[1]));
	score = lines + col;
	return (score);
}

int		flr_count_bits(int nbr)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (nbr >> ++i)
		count += ((nbr >> i) & 1);
	return (count);
}

int		flr_get_bits(t_data *data, int *next, int nb_bits)
{
	__uint128_t x;
	int			i;
	int			j;
	int			nbr;

	j = -2;
	i = next[0] - 1;
	x = (data->map_col - next[1] - data->pce_col - 3);
	if (next[0] <= 0)
		i++;
	if (next[0] == 0)
		i++;
	while (i < data->map_lines && ++j <= data->pce_lines + 2)
	{
		nbr = (data->him[i] >> x) & ((1 << (data->pce_col + 6)) - 1);
		nb_bits += flr_count_bits(nbr);
		i++;
	}
	return (-nb_bits);
}

int		flr_next_pos(t_data *data, int *next, int *score, int *current)
{
	int		score_nxt;
	int		score_cur;

	score_nxt = flr_get_score(next, score, data->map_lines, data->map_col);
	score_cur = flr_get_score(current, score, data->map_lines, data->map_col);
	if (score_nxt < score_cur)
	{
		current[0] = next[0];
		current[1] = next[1];
		score_cur = score_nxt;
		return (score_cur);
	}
	return (score_cur);
}

void	flr_strat(t_data *data, int *current, int *next)
{
	static int	score_cur;
	static int	score[2];
	int			score_nxt;

	score[0] = data->pos;
	score[1] = data->pos < data->map_col / 2 ? data->map_col : 0;
	score_nxt = flr_get_bits(data, next, score_cur);
	if (score_nxt < 0)
	{
		current[0] = next[0];
		current[1] = next[1];
		score_cur = score_nxt;
		return ;
	}
	if (score_cur < 0)
		return ;
	else
		score_cur = flr_next_pos(data, next, score, current);
}

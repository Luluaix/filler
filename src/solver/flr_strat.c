/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_strat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:43:32 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/27 14:33:27 by pdamoune         ###   ########.fr       */
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

void	flr_strat(t_data *data, int *current, int *next)
{
	int			score_cur;
	int			score_nxt;

	score_cur = 0;
	score_nxt = flr_get_bits(data, next, score_cur);
	score_cur = flr_get_bits(data, current, score_cur);
	if (score_nxt < score_cur)
	{
		current[0] = next[0];
		current[1] = next[1];
		score_cur = score_nxt;
		return ;
	}
}

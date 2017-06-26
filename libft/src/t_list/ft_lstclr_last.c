/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 23:14:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/16 16:48:33 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclr_last(t_list **lst)
{
	t_list *tmp;

	if (!(*lst))
		return ;
	tmp = *lst;
	if (tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->content = NULL;
		free(tmp->next);
		tmp->next = NULL;
	}
}

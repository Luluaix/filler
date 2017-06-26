/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:37:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/06/16 12:53:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Create and malloc a list with the size of a ptr.
** set the content to *ptr.
** return the list.
*/

t_list	*ft_lstptr(void *ptr)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL, 0);
	tmp->content = ptr;
	return (tmp);
}

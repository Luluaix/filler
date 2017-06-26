/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:24:59 by philippe          #+#    #+#             */
/*   Updated: 2017/06/16 12:46:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et
** libère la mémoire de ce maillon et celle de tous ses successeurs
** l’un après l’autre avec del et free(3). Pour terminer,
** le pointeur sur le premier maillon maintenant libéré doit être
** mis à NULL (de manière similaire à la fonction ft_memdel de
** la partie obligatoire).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		nxt = (*alst)->next;
		del((*alst)->content, sizeof(*alst));
		free(*alst);
		*alst = nxt;
	}
	ft_memdel((void *)&(*alst));
}

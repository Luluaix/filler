/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:18:18 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:11:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** Compares the two strings s1 and s2. It returns an integer less than, equal
** to, or greater than zero if s1 is found, respectively, to be less than, to
** match, or be greater than s2.
*/

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while ((unsigned char)str1[i] == (unsigned char)str2[i]
	&& str1[i] != '\0' && str2[i] != '\0')
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

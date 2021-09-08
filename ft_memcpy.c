/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:46:52 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/20 18:22:53 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_memcpy(void *str, const void *str2, size_t n)
{
	const char	*ptr2;
	char		*ptr;

	ptr2 = (char *)str2;
	ptr = (char *)str;
	if (ptr == 0 && ptr2 == 0)
		return (0);
	while (n > 0)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		n--;
	}
	return (str);
}

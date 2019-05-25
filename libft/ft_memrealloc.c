/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:02:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 17:05:21 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memrealloc(void *ptr, size_t size)
{
	char	*new;

	new = ft_memalloc(size);
	if (new)
		new = ft_memcpy(new, ptr, size);
	ft_memdel(&ptr);
	return (new);
}

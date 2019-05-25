/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:02:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 16:05:47 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memrealloc(void *ptr, size_t size)
{
	char	*new;

	new = ft_memalloc(size);
	if (new)
		new = ft_memcpy(new, ptr, size - 1);
	ft_memdel(&ptr);
	return (new);
}

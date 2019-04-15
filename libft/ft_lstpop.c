/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:04:08 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/14 17:20:14 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstpop(t_list **alst)
{
	t_list		*popped;
	if (*alst)
	{
		popped = *alst;
		*alst = popped->next;
		popped->next = NULL;
		return (popped);
	}
	return (NULL);
}

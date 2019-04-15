/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:04:08 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/14 16:05:06 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*cursor;

	if (*alst)
	{
		cursor = ft_lstgetlast(*alst);
		cursor->next = new;
	}
	else
		*alst = new;
}

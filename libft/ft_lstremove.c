/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:55:35 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/24 15:43:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstremove(t_list **list, t_list *to_del, void (*del)(void *, size_t))
{
	t_list	*current;

	current = *list;
	while (current)
	{
		if (current == to_del)
			break ;
		current = current->next;
	}
	current = current->next;
	ft_lstdelone(&to_del, del);
}

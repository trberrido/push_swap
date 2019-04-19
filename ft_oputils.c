/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oputils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:11:20 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 19:18:44 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*ft_opadd(t_list **ops, char *name)
{
	t_op	newop;

	ft_strcpy(newop.name, name);
	ft_lstappend(ops, ft_lstnew(&newop, sizeof(t_op)));
	return (ft_lstgetlast(*ops));
}

void		ft_opwrite(t_list *stack_ops)
{
	ft_putendl(((t_op *)(stack_ops->content))->name);
}

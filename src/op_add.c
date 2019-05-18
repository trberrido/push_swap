/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:42:08 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 17:42:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*op_addn(t_list **ops, char *name, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!op_add(ops, name))
			return (NULL);
		i += 1;
	}
	return (*ops);
}

t_list		*op_add(t_list **ops, char *name)
{
	t_op	newop;

	ft_strcpy(newop.name, name);
	ft_lstappend(ops, ft_lstnew(&newop, sizeof(t_op)));
	return (ft_lstgetlast(*ops));
}

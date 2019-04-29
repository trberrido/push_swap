/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:19:12 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/28 17:47:48 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*ft_opaddn(t_list **ops, char *name, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!ft_opadd(ops, name))
			return (NULL);
		i += 1;
	}
	return (*ops);
}

t_list		*ft_opadd(t_list **ops, char *name)
{
	t_op	newop;

	ft_strcpy(newop.name, name);
	ft_lstappend(ops, ft_lstnew(&newop, sizeof(t_op)));
	return (ft_lstgetlast(*ops));
}

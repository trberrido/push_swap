/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:57:43 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 18:58:28 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			stacks_del(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	if (stack_a && *stack_a)
		ft_lstdel(stack_a, &ft_memerase);
	if (stack_b && *stack_b)
		ft_lstdel(stack_b, &ft_memerase);
	if (ops && *ops)
		ft_lstdel(ops, &ft_memerase);
}

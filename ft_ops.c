/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:35:48 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/15 19:37:33 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_opapply(t_op *op, t_list **stack_a, t_list **stack_b)
{
	if (op->option >> 2 & 1)
	{
		if (op->option & 1)
			ft_push(stack_b, stack_a);
		else
			ft_push(stack_a, stack_b);
	}
	else
	{
		if (op->option & 1)
			op->fn(stack_a);
		if (op->option >> 1 & 1)
			op->fn(stack_b);
	}
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	ft_lstpush(stack_to, ft_lstpop(stack_from));
}

void	ft_swap(t_list **stack)
{
	if (*stack && (*stack)->next)
		ft_addrswap((*stack)->content, (*stack)->next->content);
}

void	ft_reverse(t_list **stack)
{
	t_list	*cursor;

	if (*stack && (*stack)->next)
	{
		ft_lstadd(stack, ft_lstgetlast(*stack));
		cursor = *stack;
		while (cursor->next != *stack)
			cursor = cursor->next;
		cursor->next = NULL;
	}
}

void	ft_rotate(t_list **stack)
{
	ft_lstappend(stack, ft_lstpop(stack));
}

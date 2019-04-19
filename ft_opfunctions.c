/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:35:48 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 16:15:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

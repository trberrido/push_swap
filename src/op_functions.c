/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:44:16 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 20:25:00 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list **dst, t_list **src)
{
	ft_lstpush(dst, ft_lstpop(src));
}

void	swap(t_list **stack, t_list **stack_useless)
{
	FT_UNUSED(stack_useless);
	if (*stack && (*stack)->next)
		ft_addrswap((*stack)->content, (*stack)->next->content);
}

void	reverse(t_list **stack, t_list **stack_useless)
{
	t_list	*cursor;

	FT_UNUSED(stack_useless);
	if (*stack && (*stack)->next)
	{
		ft_lstadd(stack, ft_lstgetlast(*stack));
		cursor = *stack;
		while (cursor->next != *stack)
			cursor = cursor->next;
		cursor->next = NULL;
	}
}

void	rotate(t_list **stack, t_list **stack_useless)
{
	FT_UNUSED(stack_useless);
	ft_lstappend(stack, ft_lstpop(stack));
}

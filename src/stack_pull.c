/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:01:39 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:25 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char		*shorterpath(t_list *stack, char stackid, int position)
{
	int			stack_len;
	static char	op_code[4];

	stack_len = ft_lstlen(stack);
	if (stack_len % 2)
		stack_len += 1;
	ft_bzero(op_code, 4);
	if (position < stack_len / 2)
	{
		ft_strncpy(op_code, "r", 4);
		op_code[1] = stackid;
	}
	else
	{
		ft_strncpy(op_code, "rr", 4);
		op_code[2] = stackid;
	}
	return (op_code);
}

t_list		*pullup_minimum(t_list **stack, t_list **ops, char stack_id)
{
	int		minimum_value;

	minimum_value = findn_min(*stack, 1);
	if (!pullup(stack, ops, minimum_value, stack_id))
		return (NULL);
	return (*ops);
}

t_list		*pullup_maximum(t_list **stack, t_list **ops, char stack_id)
{
	int		maximum_value;

	maximum_value = findn_max(*stack, 1);
	if (!pullup(stack, ops, maximum_value, stack_id))
		return (NULL);
	return (*ops);
}

t_list		*pullup(t_list **stack, t_list **ops, int value, char stackid)
{
	char	*op_code;
	int		position;

	position = find_position(*stack, value);
	op_code = shorterpath(*stack, stackid, position);
	while (((t_plate *)(*stack)->content)->value != value)
	{
		if (!ft_strncmp("rr", op_code, 2))
			reverse(stack, NULL);
		else
			rotate(stack, NULL);
		if (!op_add(ops, op_code))
			return (NULL);
	}
	return (*ops);
}

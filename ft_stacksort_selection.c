/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_selection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:36:39 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/07 19:38:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			ft_isasc(t_list *stack)
{
	if (stack && stack->next)
	{
		if (((t_plate *)(stack->content))->value > ((t_plate *)(stack->next->content))->value)
			return (0);
		else
			return (1);
	}
	return (1);
}

int			ft_stackissorted(t_list *stack)
{
	int		i;
	int		len;

	len = ft_lstlen(stack);
	i = 1;
	while (i < len)
	{
		if (!ft_isasc(stack))
			return (0);
		stack = stack->next;
		i += 1;
	}
	return (1);
}

int				ft_findnextmax(t_list *stack)
{
	t_list	*current_lst;
	int		current_value;
	int		next_max;
	int		i;
	int		max;

	i = 0;
	next_max = FT_INTMAX;
	while (i < 2)
	{
		current_lst = stack;
		max = FT_INTMIN;
		while (current_lst)
		{
			current_value = ((t_plate *)current_lst->content)->value;
			if (current_value < next_max && current_value > max)
				max = current_value;
			current_lst = current_lst->next;
		}
		next_max = max;
		i += 1;
	}
	return (next_max);
}

int				ft_findnextmin(t_list *stack)
{
	t_list	*current_lst;
	int		current_value;
	int		prev_min;
	int		i;
	int		min;

	i = 0;
	prev_min = FT_INTMIN;
	while (i < 2)
	{
		current_lst = stack;
		min = FT_INTMAX;
		while (current_lst)
		{
			current_value = ((t_plate *)current_lst->content)->value;
			if (current_value > prev_min && current_value < min)
				min = current_value;
			current_lst = current_lst->next;
		}
		prev_min = min;
		i += 1;
	}
	return (min);
}

t_list			*ft_selection_b(t_list **stack_a, t_list **stack_b, t_list **ops, int len)
{
	int		i;
	int		min;
	int		min_next;
	int		min_pos;
	int		stack_len;

	i = 0;
	stack_len = ft_lstlen(*stack_b);
	while (i < len)
	{
		min = ft_findmaximum(*stack_b);
		min_next = ft_findnextmax(*stack_b);
		min_pos = ft_findposition(*stack_b, min);
		while (((t_plate *)(*stack_b)->content)->value != min)
		{
			if (i + 1 < len && ((t_plate *)(*stack_b)->content)->value == min_next)
			{
				ft_push(stack_b, stack_a);
				if (!ft_opadd(ops, "pa"))
					return (NULL);
				i += 1;
			}
			min_pos = ft_findposition(*stack_b, min);
			if (min_pos <= stack_len / 2)
			{
				ft_rotate(stack_b);
				if (!ft_opadd(ops, "rb"))
					return (NULL);
			}
			else
			{
				ft_reverse(stack_b);
				if (!ft_opadd(ops, "rrb"))
					return (NULL);
			}
		}
		ft_push(stack_b, stack_a);
		if (!ft_opadd(ops, "pa"))
			return (NULL);
		i += 1;
		if (i > 1 && ((t_plate *)(*stack_a)->content)->value > ((t_plate *)(*stack_a)->next->content)->value)
		{
			ft_swap(stack_a);
			if (!ft_opadd(ops, "sa"))
				return (NULL);
			if (*stack_b && (*stack_b)->next)
			{
				if (((t_plate *)(*stack_b)->content)->value < ((t_plate *)(*stack_b)->next->content)->value)
				{
					ft_swap(stack_b);
					if (!ft_opadd(ops, "sb"))
						return (NULL);
				}
			}
		}
	}
	return (*ops);
}

t_list			*ft_selection(t_list **stack_a, t_list **stack_b, t_list **ops, int len)
{
	int		i;
	int		min;
	int		min_next;
	int		min_pos;
	int		stack_len;

	i = 0;
	stack_len = ft_lstlen(*stack_a);
	while (i < len)
	{
		if (ft_stackissorted(*stack_a))
		{
			len = i;
			break ;
		}
		min = ft_findminimum(*stack_a);
		min_next = ft_findnextmin(*stack_a);
		min_pos = ft_findposition(*stack_a, min);
		while (((t_plate *)(*stack_a)->content)->value != min)
		{
			if (i + 1 < len && ((t_plate *)(*stack_a)->content)->value == min_next)
			{
				ft_push(stack_a, stack_b);
				if (!ft_opadd(ops, "pb"))
					return (NULL);
				i += 1;
			}
		min_pos = ft_findposition(*stack_a, min);
			if (min_pos <= stack_len / 2)
			{
				ft_rotate(stack_a);
				if (!ft_opadd(ops, "ra"))
					return (NULL);
			}
			else
			{
				ft_reverse(stack_a);
				if (!ft_opadd(ops, "rra"))
					return (NULL);
			}
		}
		ft_push(stack_a, stack_b);
		if (!ft_opadd(ops, "pb"))
			return (NULL);
		i += 1;
		if (i > 1 && ((t_plate *)(*stack_b)->content)->value < ((t_plate *)(*stack_b)->next->content)->value)
		{
			ft_swap(stack_b);
			if (!ft_opadd(ops, "sb"))
				return (NULL);
			if (*stack_a && (*stack_a)->next)
			{
				if (((t_plate *)(*stack_a)->content)->value > ((t_plate *)(*stack_a)->next->content)->value)
				{
					ft_swap(stack_a);
					if (!ft_opadd(ops, "sa"))
						return (NULL);
				}
			}
		}
	}
	if (!ft_opaddn(ops, "pa", len))
		return (NULL);
	if (!ft_optryn(stack_a, stack_b, "pa", len))
		return (NULL);
	return (*ops);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:45:18 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 16:08:06 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_minlen(t_list *stack, int len, int previous_min)
{
	int		i;
	int		min;
	int		current_value;

	i = 0;
	min = FT_INTMAX;
	while (i < len)
	{
		current_value = ((t_plate *)stack->content)->value;
		if (min > current_value && current_value > previous_min)
			min = current_value;
		stack = stack->next;
		i += 1;
	}
	return (min);
}

int			find_median(t_list *stack, int len)
{
	int		min;
	int		previous_min;
	int		i;

	min = -1;
	previous_min = FT_INTMIN;
	i = 0;
	while (i < len / 2)
	{
		min = find_minlen(stack, len, previous_min);
		previous_min = min;
		i += 1;
	}
	return (min);
}

int			is_shifted(t_list *stack)
{
	int		first;
	int		current;
	int		breaks;

	breaks = count_breaks(stack);
	first = ((t_plate *)stack->content)->value;
	while (stack)
	{
		current = ((t_plate *)stack->content)->value;
		stack = stack->next;
	}
	if (first < current)
		breaks += 1;
	return (breaks);
}

int			count_breaks(t_list *stack)
{
	int		prev;
	int		curr;
	int		breaks;

	breaks = 0;
	if (stack)
		prev = ((t_plate *)stack->content)->value;
	while (stack)
	{
		curr = ((t_plate *)stack->content)->value;
		if (curr < prev)
			breaks += 1;
		prev = curr;
		stack = stack->next;
	}
	return (breaks);
}

int			find_position(t_list *stack, int searched_value)
{
	int		position;

	position = 0;
	while (stack)
	{
		if (((t_plate *)stack->content)->value == searched_value)
			return (position);
		stack = stack->next;
		position += 1;
	}
	return (-1);
}

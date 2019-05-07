/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_utils_find.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:38:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/04 21:10:42 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_isshifted(t_list *stack)
{
	int		first;
	int		current;
	int		breaks;

	breaks = ft_countbreaks(stack);
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

int		ft_countbreaks(t_list *stack)
{
	int		prev;
	int		first;
	int		curr;
	int		breaks;

	breaks = 0;
	prev = ((t_plate *)stack->content)->value;
	first = ((t_plate *)stack->content)->value;
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

t_list	*ft_lstgetn(t_list *stack, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		i += 1;
		stack = stack->next;
		if (!stack)
			return (NULL);
	}
	return (stack);
}

int		ft_findmaximum(t_list *stack)
{
	int		max;

	max = FT_INTMIN;
	while (stack)
	{
		if (max < ((t_plate *)stack->content)->value)
			max = ((t_plate *)stack->content)->value;
		stack = stack->next;
	}
	return (max);
}

int		ft_findminimum(t_list *stack)
{
	int		min;

	min = FT_INTMAX;
	while (stack)
	{
		if (min > ((t_plate *)stack->content)->value)
			min = ((t_plate *)stack->content)->value;
		stack = stack->next;
	}
	return (min);
}

int		ft_findposition(t_list *stack, int searched_value)
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

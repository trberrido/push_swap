/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_findminmax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:08:32 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				findn_min(t_list *stack, int n)
{
	int		min;
	int		previous_min;
	int		current_value;
	t_list	*current;

	min = -1;
	previous_min = FT_INTMIN;
	while (n)
	{
		current = stack;
		min = FT_INTMAX;
		while (current)
		{
			current_value = ((t_plate *)current->content)->value;
			if (min > current_value && current_value > previous_min)
				min = current_value;
			current = current->next;
		}
		previous_min = min;
		n -= 1;
	}
	return (min);
}

int				findn_max(t_list *stack, int n)
{
	int		max;
	int		previous_max;
	int		current_value;
	t_list	*current;

	max = -1;
	previous_max = FT_INTMAX;
	while (n)
	{
		current = stack;
		max = FT_INTMIN;
		while (current)
		{
			current_value = ((t_plate *)current->content)->value;
			if (max < current_value && current_value < previous_max)
				max = current_value;
			current = current->next;
		}
		previous_max = max;
		n -= 1;
	}
	return (max);
}

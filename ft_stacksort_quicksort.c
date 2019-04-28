/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_quicksort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:07:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/28 14:32:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				ft_getmedian(t_list *stack, int len)
{
	t_list	*current_lst;
	int		current_value;
	int		prev_min;
	int		i;
	int		min;

	i = 0;
	prev_min = FT_INTMIN;
	while (i < (len + 1) / 2)
	{
		ft_putendl("-");
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

static t_list	*ft_sliceit(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		median;
	int		i;

	median = ft_getmedian(*s_a, ft_lstlen(*s_a));
	i = 0;
	while (i < len)
	{
		if (((t_plate *)(*s_a)->content)->value < median)
		{
			ft_push(s_a, s_b);
			if (!ft_opadd(ops, "pb"))
				return (NULL);
		}
		else
		{
			ft_rotate(s_a);
			if (!ft_opadd(ops, "ra"))
				return (NULL);
		}
		i += 1;
	}
	return (*ops);
}

t_list			*ft_quicksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int		len;

	len = ft_lstlen(*stack_a);
	while (len > 3)
	{
		if (!ft_sliceit(stack_a, stack_b, ops, len))
			return (NULL);
		len = ft_lstlen(*stack_a);
	}
	return (*ops);
}

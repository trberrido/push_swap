/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_quicksort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:07:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/07 19:38:20 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				ft_getquartile(t_list *stack, int len)
{
	t_list	*current_lst;
	int		current_value;
	int		prev_min;
	int		i;
	int		min;

	i = 0;
	prev_min = FT_INTMIN;
	while (i < (75 * len) / 100)
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

int				ft_getmedian(t_list *stack, int len)
{
	t_list	*current_lst;
	int		current_value;
	int		prev_min;
	int		i;
	int		j;
	int		min;

	i = 0;
	prev_min = FT_INTMIN;
	while (i < (50 * len) / 100)
	{
		current_lst = stack;
		min = FT_INTMAX;
		j = 0;
		while (j < len)
		{
			current_value = ((t_plate *)current_lst->content)->value;
			if (current_value > prev_min && current_value < min)
				min = current_value;
			current_lst = current_lst->next;
			j += 1;
		}
		prev_min = min;
		i += 1;
	}
	return (min);
}

int				ft_hasupmedian(t_list *stack, int median, int len)
{
	int		i;

	i = 0;
	while (i < len && stack)
	{
		if (((t_plate *)stack->content)->value > median)
			return (1);
		stack = stack->next;
		i += 1;
	}
	return (0);
}

int				ft_hasbelowmedian(t_list *stack, int median, int len)
{
	int		i;
	int		below;

	i = 0;
	below = 0;
	while (i < len && stack)
	{
		if (((t_plate *)stack->content)->value < median)
			return (1);
		stack = stack->next;
		i += 1;
	}
	return (0);
}

static int		ft_separate(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		i;
	int		stacklen;
	int		pushed;
	int		median;
	int		quartile;

	i = 0;
	pushed = 0;
	stacklen = ft_lstlen(*s_a);
	median = ft_getmedian(*s_a, len);
	quartile = ft_getquartile(*s_a, len);
	while (i < len)
	{
		if (((t_plate *)(*s_a)->content)->value < median)
		{
			pushed += 1;
			ft_push(s_a, s_b);
			if (!ft_opadd(ops, "pb"))
				return (-1);
		}
		else
		{
			ft_rotate(s_a);
			if (!ft_opadd(ops, "ra"))
				return (-1);
		}
		i += 1;
	}
	return (pushed);
}

static int		ft_separate_b(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		i;
	int		pushed;
	int		median;
	int		stacklen;

	i = 0;
	pushed = 0;
	stacklen = ft_lstlen(*s_b);
	median = ft_getmedian(*s_b, len);
	while (i < len)
	{

		if (((t_plate *)(*s_b)->content)->value > median)
		{
			pushed += 1;
			ft_push(s_b, s_a);
			if (!ft_opadd(ops, "pa"))
				return (-1);
		}
		else
		{
			ft_rotate(s_b);
			if (!ft_opadd(ops, "rb"))
				return (-1);
		}
		i += 1;
	}
	return (pushed);
}

/*
**	SLICE N
**		IF N < 3
**			RETURN FN swap
**		ELSE
**			FN separate
**			FN slice remaining
**			RETURN FN rewind pushed 	___	rewind will push back
**											before recalling slice
*/

/*
**	SLICE N								___ V 2
**		IF N < 3
**			RETURN FN swap
**		ELSE
**			FN separate
**			FN slice remaining
**			RETURN FN rewind half-pushed	___	rewind will push back
**			only							before recalling slice
*/

t_list	*ft_slice_b(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		remaining_b;
	int		pushed;

	if (len > 12)
	{
		if ((pushed = ft_separate_b(s_a, s_b, ops, len)) < 0)
			return (NULL);
		remaining_b = len - pushed;
		if (remaining_b < ft_lstlen(*s_b))
		{
			ft_optryn(s_a, s_b, "rrb", remaining_b);
			if (!ft_opaddn(ops, "rrb", remaining_b))
				return (NULL);
		}
		if (!ft_slice(s_a, s_b, ops, pushed))
			return (NULL);
		return (ft_slice_b(s_a, s_b, ops, remaining_b));
	}
	return (ft_selection_b(s_a, s_b, ops, len));
}

t_list	*ft_slice(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		remaining;
	int		pushed;
	int		pre_pushed;
	int		i;

	if (len > 9)
	{
		if ((pushed = ft_separate(s_a, s_b, ops, len)) < 0)
			return (NULL);
		remaining = len - pushed;
		pre_pushed = 0;
		if (remaining < ft_lstlen(*s_a))
		{
			i = 0;
			while (i < remaining)
			{
				ft_reverse(s_a);
				if (!ft_opadd(ops, "rra"))
					return (NULL);
				i += 1;
			}
		}
		if (!ft_slice(s_a, s_b, ops, remaining))
			return (NULL);
		return (ft_slice_b(s_a, s_b, ops, pushed));
	}
	return (ft_selection(s_a, s_b, ops, len));

}

t_list			*ft_quicksort(t_list **stack_a, t_list **stack_b, t_list **ops, int len)
{
	return (ft_slice(stack_a, stack_b, ops, len));
}

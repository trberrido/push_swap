/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:12:30 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:24 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		separate_b(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		i;
	int		median;
	int		pushed;
	int		return_value;

	i = 0;
	pushed = 0;
	median = find_median(*s_b, len);
	while (i < len)
	{
		return_value = pusharotb(s_a, s_b, ops, median);
		if (return_value == FT_ERROR)
			return (FT_ERROR);
		else
			pushed += return_value;
		i += 1;
	}
	return (pushed);
}

static int		separate_a(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		i;
	int		median;
	int		pushed;
	int		return_value;

	i = 0;
	pushed = 0;
	median = find_median(*s_a, len);
	while (i < len)
	{
		return_value = pushbrota(s_a, s_b, ops, median);
		if (return_value == FT_ERROR)
			return (FT_ERROR);
		else
			pushed += return_value;
		i += 1;
	}
	return (pushed);
}

static t_list	*quicksort_b(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		remaining;
	int		pushed;

	if (len > 12)
	{
		if ((pushed = separate_b(s_a, s_b, ops, len)) == FT_ERROR)
			return (NULL);
		remaining = len - pushed;
		if (remaining < ft_lstlen(*s_b))
		{
			op_tryn(s_a, s_b, "rrb", remaining);
			if (!op_addn(ops, "rrb", remaining))
				return (NULL);
		}
		if (!quicksort(s_a, s_b, ops, pushed))
			return (NULL);
		return (quicksort_b(s_a, s_b, ops, remaining));
	}
	if (pushan_asc(s_a, s_b, ops, len) == FT_ERROR)
		return (NULL);
	return (*ops);
}

t_list			*quicksort(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		remaining;
	int		pushed;

	if (len > 9)
	{
		if ((pushed = separate_a(s_a, s_b, ops, len)) == FT_ERROR)
			return (NULL);
		remaining = len - pushed;
		if (remaining < ft_lstlen(*s_a))
		{
			op_tryn(s_a, s_b, "rra", remaining);
			if (!op_addn(ops, "rra", remaining))
				return (NULL);
		}
		if (!quicksort(s_a, s_b, ops, remaining))
			return (NULL);
		return (quicksort_b(s_a, s_b, ops, pushed));
	}
	return (selection(s_a, s_b, ops, len));
}

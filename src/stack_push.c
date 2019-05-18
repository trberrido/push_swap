/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:58:55 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:28 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	prepush(t_list **s_a, t_list **ops)
{
	int		current;
	int		next;

	if (*s_a && (*s_a)->next)
	{
		current = ((t_plate *)(*s_a)->content)->value;
		next = ((t_plate *)(*s_a)->next->content)->value;
		if (count_breaks(*s_a) == 1 && current > next)
		{
			swap(s_a, NULL);
			if (!op_add(ops, "sa"))
				return (FT_ERROR);
		}
	}
	if (is_shifted(*s_a) == 1)
	{
		if (!pullup(s_a, ops, findn_min(*s_a, 1), 'a'))
			return (FT_ERROR);
		return (1);
	}
	return (0);
}

int			pushbn_min(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		current_pos;

	pushed = 0;
	current_pos = find_position(*s_a, findn_min(*s_a, n));
	if (current_pos)
	{
		pushed = pushbnext_min(s_a, s_b, ops, n);
		if (pushed == FT_ERROR)
			return (FT_ERROR);
		if (!pullup(s_a, ops, findn_min(*s_a, n), 'a'))
			return (FT_ERROR);
	}
	if (!pushb_andswapb(s_a, s_b, ops, pushed))
		return (FT_ERROR);
	pushed += 1;
	return (pushed);
}

int			pushan_max(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		current_pos;

	pushed = 0;
	current_pos = find_position(*s_b, findn_max(*s_b, n));
	if (current_pos)
	{
		pushed = pushanext_max(s_a, s_b, ops, n);
		if (pushed == FT_ERROR)
			return (FT_ERROR);
		if (!pullup(s_b, ops, findn_max(*s_b, n), 'b'))
			return (FT_ERROR);
	}
	if (!pusha_andswapa(s_a, s_b, ops, pushed))
		return (FT_ERROR);
	pushed += 1;
	return (pushed);
}

int			pushbn_desc(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		return_value;

	pushed = 0;
	while (pushed < n)
	{
		return_value = prepush(s_a, ops);
		if (return_value == FT_ERROR)
			return (FT_ERROR);
		if (return_value)
			return (pushed);
		if ((return_value = pushbn_min(s_a, s_b, ops, 1)) == FT_ERROR)
			return (FT_ERROR);
		pushed += return_value;
	}
	return (pushed);
}

int			pushan_asc(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		return_value;

	pushed = 0;
	while (pushed < n)
	{
		if ((return_value = pushan_max(s_a, s_b, ops, 1)) == FT_ERROR)
			return (FT_ERROR);
		pushed += return_value;
	}
	return (pushed);
}

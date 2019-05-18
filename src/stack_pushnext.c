/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:55:36 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			pushbnext_min(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		next_pos;
	int		current_pos;
	char	*shorter_op;

	pushed = 0;
	current_pos = find_position(*s_a, findn_min(*s_a, n));
	next_pos = find_position(*s_a, findn_min(*s_a, n + 1));
	shorter_op = shorterpath(*s_a, 'a', current_pos);
	if ((n < 2 && !ft_strcmp(shorter_op, "ra") && next_pos < current_pos)
		|| (n < 2 && !ft_strcmp(shorter_op, "rra") && next_pos > current_pos)
		|| (n < 1 && !next_pos))
		pushed = pushbn_min(s_a, s_b, ops, n + 1);
	if (pushed == FT_ERROR)
		return (FT_ERROR);
	return (pushed);
}

int			pushanext_max(t_list **s_a, t_list **s_b, t_list **ops, int n)
{
	int		pushed;
	int		next_pos;
	int		current_pos;
	char	*shorter_op;

	pushed = 0;
	current_pos = find_position(*s_b, findn_max(*s_b, n));
	next_pos = find_position(*s_b, findn_max(*s_b, n + 1));
	shorter_op = shorterpath(*s_b, 'b', current_pos);
	if ((n < 2 && !ft_strcmp(shorter_op, "rb") && next_pos < current_pos)
		|| (n < 2 && !ft_strcmp(shorter_op, "rrb") && next_pos > current_pos)
		|| (n < 1 && !next_pos))
		pushed = pushan_max(s_a, s_b, ops, n + 1);
	if (pushed == FT_ERROR)
		return (FT_ERROR);
	return (pushed);
}

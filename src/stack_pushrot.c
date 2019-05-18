/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:32:46 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 20:06:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		pushbrota(t_list **s_a, t_list **s_b, t_list **ops, int median)
{
	if (((t_plate *)(*s_a)->content)->value < median)
	{
		push(s_b, s_a);
		if (!op_add(ops, "pb"))
			return (FT_ERROR);
		return (1);
	}
	rotate(s_a, s_b);
	if (!op_add(ops, "ra"))
		return (FT_ERROR);
	return (0);
}

int		pusharotb(t_list **s_a, t_list **s_b, t_list **ops, int median)
{
	if (((t_plate *)(*s_b)->content)->value > median)
	{
		push(s_a, s_b);
		if (!op_add(ops, "pa"))
			return (FT_ERROR);
		return (1);
	}
	rotate(s_b, s_a);
	if (!op_add(ops, "rb"))
		return (FT_ERROR);
	return (0);
}

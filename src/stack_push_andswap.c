/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_andswap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:47:06 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 22:39:26 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		pushb_andswapb(t_list **s_a, t_list **s_b, t_list **ops, int pushed)
{
	push(s_b, s_a);
	if (!op_add(ops, "pb"))
		return (FT_ERROR);
	if (pushed)
	{
		swap(s_b, s_a);
		if (!op_add(ops, "sb"))
			return (FT_ERROR);
	}
	return (1);
}

int		pusha_andswapa(t_list **s_a, t_list **s_b, t_list **ops, int pushed)
{
	push(s_a, s_b);
	if (!op_add(ops, "pa"))
		return (FT_ERROR);
	if (pushed)
	{
		swap(s_a, s_b);
		if (!op_add(ops, "sa"))
			return (FT_ERROR);
	}
	return (1);
}

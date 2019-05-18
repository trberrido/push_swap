/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:27:47 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 18:28:24 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		sort_check(t_list *stack_a, t_list *stack_b)
{
	if (!count_breaks(stack_a) && !stack_b)
		return (1);
	return (0);
}

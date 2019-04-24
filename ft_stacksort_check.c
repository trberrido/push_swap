/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:51:34 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/24 16:19:11 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_stacksort_check(t_list *stack_a, t_list *stack_b)
{
	if (!ft_countbreaks(stack_a) && !stack_b)
		return (1);
	return (0);
}

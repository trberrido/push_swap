/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:05 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/17 19:22:25 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*ft_stacksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int				i;
	int				stack_len;
	static t_algo	algos[2] = {
		{ft_insertion, 25}, 
		{ft_bubble, 50}
	};

	i = 0;
	stack_len = ft_lstlen(*stack_a);
	while (stack_len > algo[i].limit && i + 1 < 2)
		i += 1;
	algo[i].fn(stack_a, stack_b, ops);	
	return (*ops);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:12:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/23 00:34:46 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_insert_from_b(t_int **topa, t_int **topb, int max)
{
	while (*topb)
	{
		if ((*topb)->digit == max)
		{
			while ((*topa)->digit != ft_min(*topa))
				ft_act_rotate(topa, ft_min(*topa));
			ft_pusha(topa, topb);
			ft_ra(topa);
		}
		else if ((*topb)->digit < ft_median(*topa))
		{
			while ((*topb)->digit > (*topa)->digit)
				ft_ra(topa);
			ft_pusha(topa, topb);
			ft_act_rotate(topa, ft_min(*topa));
		}
		else
		{
			while ((*topb)->digit > (*topa)->digit)
				ft_rra(topa);
			ft_pusha(topa, topb);
			ft_act_rotate(topa, ft_min(*topa));
		}
	}
}

void	ft_sort5(t_int **topa, t_int **topb, int size)
{
	int	max;
	int	min;

	max = ft_max(*topa);
	min = ft_min(*topa);
	if (ft_sorted(*topa))
		return ;
	while (size-- > 3)
		ft_pushb(topb, topa);
	ft_sort3(topa, topb, size + 1);
	if (ft_max(*topa) < ft_min(*topb))
	{
		if ((*topb)->digit != max)
			ft_swapb(topb);
		while (*topb)
			ft_pusha(topa, topb);
		ft_act_rotate(topa, min);
		return ;
	}
	ft_insert_from_b(topa, topb, max);
	ft_act_rotate(topa, min);
}

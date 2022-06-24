/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:55:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/24 15:14:34 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort100(t_int **topa, t_int **topb, int *tab, int size)
{
	int	top_half;
	int	median;
	int	i;

	if (size == 1)
		return ;
	top_half = 0;
	median = ft_median(tab, size - 1);
	i = 0;
	while (i < size)
	{
		while ((*topa)->digit >= median && *topa)
		{
			ft_pushb(topb, topa);
			++top_half;
		}
		++i;
		ft_ra(topa);
	}
//	ft_pusha_ntimes(topa, topb, top_half);
//	ft_rev_rotate_ntimes(topa, size - top_half);
	if (top_half == 0)
		return ;
	ft_sort100(topa, topb, tab, top_half);
	ft_pushb(topb, topa);
}

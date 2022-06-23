/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:12:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/23 19:08:08 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort10(t_int **topa, t_int **topb, int size)
{
	int	min;

	min = ft_min(*topa);
	ft_sel(topa, topb);
	ft_sort3(topa, size);
	while (*topb)
		ft_pusha(topa, topb);
	ft_act_rotate(topa, min);
}

void	ft_quick(t_int **topa, t_int **topb, int size)
{
	int		top_len;
	int		median;
	int		i;
	t_int	*tmp;

	top_len = 0;
	i = 0;
	median = ft_median(*topa);
	tmp = *topa;
	while (i < size)
	{
		if (tmp->digit > median)
	}
}
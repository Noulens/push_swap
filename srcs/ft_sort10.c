/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:12:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/24 14:51:30 by tnoulens         ###   ########.fr       */
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
	ft_act_rotatea(topa, min);
}

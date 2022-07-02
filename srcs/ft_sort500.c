/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:55:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/02 18:52:53 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort500(t_int **topa, t_int **topb, int size)
{
	int	i;
	int	j;
	int	max;
	int	maxbit;
	int	digit;

	max = size - 1;
	maxbit = 0;
	while ((max >> maxbit) != 0)
		++maxbit;
	i = -1;
	while (++i < maxbit)
	{
		j = -1;
		while (++j < size)
		{
			digit = (*topa)->digit;
			if (((digit >> i) & 1) == 1)
				ft_ra(topa);
			else
				ft_pushb(topb, topa);
		}
		while (*topb)
			ft_pusha(topa, topb);
	}
}

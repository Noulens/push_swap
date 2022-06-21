/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:56:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/21 17:35:51 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pusha(t_int **a, t_int **b)
{
	t_int	*tmp2;

	if (!b || !*b)
		return ;
	else
	{
		tmp2 = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp2;
	}
	write(1, "pa\n", 3);
}

void	ft_pushb(t_int **b, t_int **a)
{
	t_int	*tmp2;

	if (!a || !*a)
		return ;
	else
	{
		tmp2 = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp2;
	}
	write(1, "pb\n", 3);
}

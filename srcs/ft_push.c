/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:56:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/03 12:02:54 by tnoulens         ###   ########.fr       */
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
		if (*b != NULL)
			(*b)->bnext = NULL;
		(*a)->next->bnext = *a;
		if ((*a)->next != NULL)
			(*a)->next->bnext = *a;
		else
			(*a)->bnext = NULL;
	}
	ft_printf("pa\n");
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
		if (*b != NULL)
			(*a)->bnext = NULL;
		if ((*b)->next != NULL)
			(*b)->next->bnext = *b;
		else
			(*b)->bnext = NULL;
	}
	ft_printf("pb\n", 3);
}

void	ft_pusha_ntimes(t_int **topa, t_int **topb, int n)
{
	while (n-- > 0)
		ft_pusha(topa, topb);
}

void	ft_pushb_ntimes(t_int **topa, t_int **topb, int n)
{
	while (n-- > 0)
		ft_pushb(topb, topa);
}

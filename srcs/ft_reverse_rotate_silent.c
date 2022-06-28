/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_silent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:43:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/28 10:59:44 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_srra(t_int **a)
{
	t_int	*tmpa;
	t_int	*blast;

	if (!*a || !a || (*a)->next == NULL)
	{
		return ;
	}
	blast = ft_blast(*a);
	tmpa = *a;
	*a = blast->next;
	(*a)->next = tmpa;
	blast->next = NULL;
	(*a)->bnext = NULL;
	tmpa->bnext = *a;
	write(1, "rra\n", 4);
}

void	ft_srrb(t_int **b)
{
	t_int	*tmpb;
	t_int	*blast;

	if (!*b || !b || (*b)->next == NULL)
	{
		return ;
	}
	blast = ft_blast(*b);
	tmpb = *b;
	*b = blast->next;
	(*b)->next = tmpb;
	blast->next = NULL;
	(*b)->bnext = NULL;
	tmpb->bnext = *b;
}

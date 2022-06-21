/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:19:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/21 17:36:28 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swapa(t_int **a)
{
	t_int	*tmp;

	if (!*a || !a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write (1, "sa\n", 3);
}

void	ft_swapb(t_int **b)
{
	t_int	*tmp;

	if (!*b || !b || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write (1, "sb\n", 3);
}

void	ft_swapss(t_int **a, t_int **b)
{
	t_int	*tmp;
	int		flaga;
	int		flagb;

	flaga = 0;
	flagb = 0;
	if (*a && a && (*a)->next != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		flaga = 1;
	}
	if (*b && b && (*b)->next != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		flagb = 1;
	}
	if (flaga == 0 && flagb == 0)
		return ;
	write (1, "ss\n", 3);
}

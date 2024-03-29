/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:19:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/30 18:04:58 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_silentswapa(t_int **a)
{
	t_int	*tmp;

	if (!*a || !a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	(*a)->bnext = NULL;
	tmp->bnext = *a;
	if (tmp->next != NULL)
		tmp->next->bnext = tmp;
}

static void	ft_silentswapb(t_int **b)
{
	t_int	*tmp;

	if (!*b || !b || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	(*b)->bnext = NULL;
	tmp->bnext = *b;
	if (tmp->next != NULL)
		tmp->next->bnext = tmp;
}

void	ft_swapa(t_int **a)
{
	t_int	*tmp;

	if (!*a || !a || (*a)->next == NULL)
		return (write (1, "sa\n", 3), ((void)0));
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	(*a)->bnext = NULL;
	tmp->bnext = *a;
	if (tmp->next != NULL)
		tmp->next->bnext = tmp;
	write (1, "sa\n", 3);
}

void	ft_swapb(t_int **b)
{
	t_int	*tmp;

	if (!*b || !b || (*b)->next == NULL)
		return (write (1, "sb\n", 3), ((void)0));
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	(*b)->bnext = NULL;
	tmp->bnext = *b;
	if (tmp->next != NULL)
		tmp->next->bnext = tmp;
	write (1, "sb\n", 3);
}

void	ft_swapss(t_int **a, t_int **b)
{
	if (*a && a && (*a)->next != NULL)
		ft_silentswapa(a);
	if (*b && b && (*b)->next != NULL)
		ft_silentswapb(b);
	write (1, "ss\n", 3);
}

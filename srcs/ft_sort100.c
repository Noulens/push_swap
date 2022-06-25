/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:55:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/24 21:04:38 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_selb(t_int **topa, t_int **topb)
{
	t_int	*tmp;
	t_int	*max;
	t_int	*r;

	tmp = *topa;
	while (ft_lstsize(*topa) > 0 && !ft_sorted(*topa))
	{
		max = tmp;
		r = tmp->next;
		while (r)
		{
			if (max->digit < r->digit)
				max = r;
			r = r->next;
		}
		ft_act_rotateb(topa, max->digit);
		ft_pusha(topb, topa);
		tmp = *topa;
	}
}

static void	ft_int_tab(int *tab, t_int **topa)
{
	tab[0] = (*topa)->digit;
	tab[1] = (*topa)->next->digit;
	tab[2] = (*topa)->next->next->digit;
}

static void	ft_cases_3b(t_int **topa, int *tab)
{
	if (tab[0] < tab[1] && tab[0] < tab[2] && tab[2] < tab[1])
	{
		ft_swapb(topa);
		ft_rb(topa);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		ft_rb(topa);
	}
	else if (tab[0] > tab[1])
	{
		ft_swapb(topa);
		if (tab[1] > tab[2])
			ft_rrb(topa);
	}
	else if (tab[0] > tab[2])
		ft_rra(topa);
}

void	ft_sort3b(t_int **topa, int size)
{
	int	tab[3];

	if (size == 2 && (*topa)->digit > (*topa)->next->digit)
		return (ft_swapb(topa));
	else if (size == 2)
		return ;
	ft_int_tab(tab, topa);
	ft_cases_3b(topa, tab);
}

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
//	while (*topb)
//		ft_pusha(topa, topb);
	ft_selb(topb, topa);
}

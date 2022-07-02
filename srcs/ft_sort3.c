/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:24:08 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/24 18:43:46 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_int_tab(int *tab, t_int **topa)
{
	tab[0] = (*topa)->digit;
	tab[1] = (*topa)->next->digit;
	tab[2] = (*topa)->next->next->digit;
}

static void	ft_cases_3(t_int **topa, int *tab)
{
	if (tab[0] < tab[1] && tab[0] < tab[2] && tab[2] < tab[1])
	{
		ft_swapa(topa);
		ft_ra(topa);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		ft_ra(topa);
	}
	else if (tab[0] > tab[1])
	{
		ft_swapa(topa);
		if (tab[1] > tab[2])
			ft_rra(topa);
	}
	else if (tab[0] > tab[2])
		ft_rra(topa);
}

void	ft_sort3(t_int **topa, int size)
{
	int	tab[3];

	if (size == 2 && (*topa)->digit > (*topa)->next->digit)
		return (ft_swapa(topa));
	else if (size == 2)
		return ;
	ft_int_tab(tab, topa);
	ft_cases_3(topa, tab);
}

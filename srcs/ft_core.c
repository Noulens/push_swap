/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/17 21:37:42 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_int	*ft_partition(t_int *fst, t_int *lst)
{
	t_int	*pivot;
	t_int	*front;
	int		tmp;

	pivot = fst;
	front = fst;
	while (front && front != lst)
	{
		if (front->digit < (lst)->digit)
		{
			pivot = fst;
			/* OPERATION SWAP */
			tmp = (fst)->digit;
			(fst)->digit = front->digit;
			front->digit = tmp;
			/* increment */
			fst = (fst)->next;
		}
		front = front->next;
	}
	/* OPRATION SWAP pivot with greater element */
	tmp = (fst)->digit;
	(fst)->digit = (lst)->digit;
	(lst)->digit = tmp;
	return (pivot);
}

void	ft_quick_sort(t_int *fst, t_int *lst)
{
	t_int	*pivot;

	if (fst == lst)
		return ;
	pivot = ft_partition(fst, lst);
	if (pivot != NULL && pivot->next != NULL)
		ft_quick_sort(pivot->next, lst);
	if (pivot != NULL && fst != pivot)
		ft_quick_sort(fst, pivot);
}

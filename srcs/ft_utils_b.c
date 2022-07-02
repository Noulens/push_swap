/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:36:36 by waxxy             #+#    #+#             */
/*   Updated: 2022/07/02 18:42:46 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bdisplay(t_int *top)
{
	t_int	*p;

	p = ft_lstlast(top);
	if (!top)
		return ;
	while (p != NULL)
	{
		printf("%ld\n", p->digit);
		p = p->bnext;
	}
}

void	ft_scaling(int *tab, t_int **a, int size)
{
	t_int	*p;
	int		j;

	p = *a;
	while (p)
	{
		j = 0;
		while (j < size)
		{
			if (p->digit == tab[j])
			{
				p->digit = j;
				break ;
			}
			j++;
		}
		p = p->next;
	}
}

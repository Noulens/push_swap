/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:19:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/21 17:36:09 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_int **a)
{
	t_int	*last;

	if (!*a || !a || (*a)->next == NULL)
	{
		write(1, "ra\n", 3);
		return ;
	}
	last = ft_lstlast(*a);
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_int **b)
{
	t_int	*last;

	if (!*b || !b || (*b)->next == NULL)
	{
		write(1, "ra\n", 3);
		return ;
	}
	last = ft_lstlast(*b);
	last->next = *b;
	*b = (*b)->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_int **a, t_int **b)
{
	t_int	*lasta;
	t_int	*lastb;

	if ((!*a || !a || (*a)->next == NULL) && (!*b || !b || (*b)->next == NULL))
	{
		write(1, "rr\n", 3);
		return ;
	}
	if (*a && a && (*a)->next != NULL)
	{
		lasta = ft_lstlast(*a);
		lasta->next = *a;
		*a = (*a)->next;
		lasta->next->next = NULL;
	}
	if (*b && b && (*b)->next != NULL)
	{
		lastb = ft_lstlast(*b);
		lastb->next = *b;
		*b = (*b)->next;
		lastb->next->next = NULL;
	}
	write(1, "rr\n", 3);
}

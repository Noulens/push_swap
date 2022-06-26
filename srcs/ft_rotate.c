/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:19:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/26 21:45:35 by waxxy            ###   ########.fr       */
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
	(*a)->bnext = NULL;
	last->next->bnext = last;
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
	(*b)->bnext = NULL;
	last->next->bnext = last;
	write(1, "rb\n", 3);
}

void	ft_rr(t_int **a, t_int **b)
{
	t_int	*last;

	if ((!*a || !a || (*a)->next == NULL) && (!*b || !b || (*b)->next == NULL))
		return (write(1, "rr\n", 3)) ;
	if (*a && a && (*a)->next != NULL)
	{
		last = ft_lstlast(*a);
		last->next = *a;
		*a = (*a)->next;
		last->next->next = NULL;
		(*a)->bnext = NULL;
		last->next->bnext = last;
	}
	if (*b && b && (*b)->next != NULL)
	{
		last = ft_lstlast(*b);
		last->next = *b;
		*b = (*b)->next;
		last->next->next = NULL;
		(*b)->bnext = NULL;
		last->next->bnext = last;
	}
	write(1, "rr\n", 3);
}

void	ft_rotate_ntimes(t_int **top, int n)
{
	while (n-- > 0)
		ft_ra(top);
}

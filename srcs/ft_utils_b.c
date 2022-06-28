/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:36:36 by waxxy             #+#    #+#             */
/*   Updated: 2022/06/27 10:38:58 by waxxy            ###   ########.fr       */
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

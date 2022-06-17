/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:35:24 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/17 17:02:19 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	*ft_lstnew(char *content)
{
	t_int	*first;

	first = (t_int *)malloc(sizeof(t_int));
	if (!first)
		return (NULL);
	first->digit = ft_atol(content);
	first->next = NULL;
	return (first);
}

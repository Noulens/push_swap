/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:35:24 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/15 20:11:54 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	*ft_lstnew(char *content)
{
	t_int	*first;

	first = (t_int *)malloc(sizeof(t_int));
	if (!first)
		return (NULL);
	first->digit = ft_atoi(content);
	first->next = NULL;
	return (first);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:46:53 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/13 18:02:57 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		exit(EXIT_FAILURE);
	if (argc >= 2)
	{
		while (*argv && argv)
		{
			ft_split(argv[i], " ");
			++i;
		}
	}
}
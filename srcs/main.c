/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:46:53 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/28 13:08:53 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_v_args(char **v)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (v[++i])
	{
		j = -1;
		sign = 0;
		while (v[i][++j])
		{
			if (v[i][j] == '-' && sign == 0)
			{
				sign++;
				if (!ft_isdigit(v[i][j + 1]))
					return (0);
			}
			else if (!ft_isdigit(v[i][j]) && v[i][j] != ' ')
				return (0);
			if (v[i][j] == ' ')
				sign = 0;
		}
	}
	return (1);
}

static void	ft_error_dup(t_int *top)
{
	write(1, "Error\n", 6);
	ft_lstclear(top);
	exit(EXIT_FAILURE);
}

static int	ft_find_duplicate(t_int *top)
{
	int		count;
	t_int	*temp;
	t_int	*temp1;

	temp = top;
	while (temp != NULL)
	{
		temp1 = top;
		count = 0;
		while (temp1 != NULL)
		{
			if (temp->digit == temp1->digit)
				count++;
			if (temp->digit > INT_MAX || temp->digit < INT_MIN)
				count++;
			temp1 = temp1->next;
		}
		if (count > 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_int	*topa;
	t_int	*topb;

	topa = NULL;
	topb = NULL;
	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (argc >= 2)
	{
		if (ft_v_args(argv))
		{
			topa = ft_build_stack(argc - 1, argv + 1);
			if (!ft_find_duplicate(topa))
				ft_error_dup(topa);
			ft_define_sort(&topa, &topb);
		}
		else
			write(1, "Error\n", 6 * sizeof(char));
	}
	ft_lstclear(topa);
	ft_lstclear(topb);
	return (0);
}

/*
			//topb = ft_lstnew("1989");
			//ft_lstadd_back(topb, ft_lstnew("1991"));
			//ft_lstadd_back(topb, ft_lstnew("1993"));
			//ft_display(topa);
			//printf("-\n");
			//ft_display(topb);
			//printf("----\n");
			//ft_swapa(&topa);
			//ft_swapb(&topb);
			//ft_swapb(&topb);
			//ft_swapss(&topa, &topb);
			//ft_rr(&topa, &topb);
			//ft_rrr(&topa, &topb);
			//ft_pusha(&topa, &topb);
			//ft_pushb(&topb, &topa);
			//printf("-\n");
			//ft_display(topa);
			//printf("-\n");
			//ft_display(topb);
			ft_define_sort(&topa, &topb);
			//printf("\n%d\n\n", ft_sorted(topa));
*/	

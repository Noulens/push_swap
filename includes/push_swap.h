/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/23 20:13:15 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

/* proto utils */
t_int	*ft_build_stack(int nbdigit, char **nb_arg);
void	ft_pusha(t_int **topa, t_int **topb);
void	ft_pushb(t_int **topb, t_int **topa);
void	ft_swapa(t_int **a);
void	ft_swapb(t_int **b);
void	ft_swapss(t_int **a, t_int **b);
void	ft_ra(t_int **a);
void	ft_rb(t_int **b);
void	ft_rr(t_int **a, t_int **b);
void	ft_rra(t_int **a);
void	ft_rrr(t_int **a, t_int **b);
int		ft_sorted(t_int *a);
void	ft_display(t_int *top);
int		ft_max(t_int *top);
int		ft_min(t_int *top);
int		ft_median(t_int *top, int n);

int		ft_define_rotate(t_int *top, int digit);
void	ft_act_rotate(t_int **top, int digit);
void	ft_define_sort(t_int **topa, t_int **topb);
void	ft_sel(t_int **topa, t_int **topb);
void	ft_sort3(t_int **topa, int size);
void	ft_sort10(t_int **topa, t_int **topb, int size);
t_int	*ft_qs(t_int *topa, t_int **topb, int size);

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/27 10:39:46 by waxxy            ###   ########.fr       */
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
void	ft_rrb(t_int **b);
void	ft_rrr(t_int **a, t_int **b);
int		ft_sorted(t_int *a);
void	ft_display(t_int *top);
void	ft_bdisplay(t_int *top);
int		ft_max(t_int *top);
int		ft_min(t_int *top);
int		ft_median(int *top, int n);

int		ft_define_rotate(t_int *top, int digit);
void	ft_act_rotatea(t_int **top, int digit);
void	ft_act_rotateb(t_int **top, int digit);
void	ft_define_sort(t_int **topa, t_int **topb);
void	ft_sel(t_int **topa, t_int **topb);
void	ft_selectiona(t_int **topa, t_int **topb);
void	ft_selectionb(t_int **topa, t_int **topb);
void	ft_sort3(t_int **topa, int size);
void	ft_sort10(t_int **topa, t_int **topb, int size);
void	ft_qs(t_int **topa, t_int **topb, int size);
void	ft_rotate_ntimes(t_int **top, int n);
void	ft_rev_rotate_ntimes(t_int **top, int n);
void	ft_pusha_ntimes(t_int **topa, t_int **topb, int n);
void	ft_pushb_ntimes(t_int **topa, t_int **topb, int n);

void	ft_sort100(t_int **topa, t_int **topb, int *tab, int size);

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

#endif

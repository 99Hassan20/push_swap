/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:07:16 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/05 18:31:32 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_log(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long	ft_atoi_v2(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		error_log();
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error_log();
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			error_log();
		i++;
	}
	return (sign * res);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	get_max(t_node *stack)
{
	int		max;
	t_node	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	max = stack->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_node *stack)
{
	int		min;
	t_node	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	min = stack->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
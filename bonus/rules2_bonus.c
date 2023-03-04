/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:27:22 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 22:59:37 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h" 

void	pa(t_stacks *stacks)
{	
	t_node	*top;

	if (!stacks->stack_b)
		return ;
	top = pop(&stacks->stack_b);
	push(&stacks->stack_a, top);
}

void	pb(t_stacks *stacks)
{	
	t_node	*top;

	if (!stacks->stack_a)
		return ;
	top = pop(&stacks->stack_a);
	push(&stacks->stack_b, top);
}

void	rotate(t_node **stack)
{
	t_node	*top;
	t_node	*tmp;

	if (! *stack || get_stack_length(*stack) == 1)
		return ;
	top = pop(stack);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
}

void	ra(t_stacks	*stacks)
{
	rotate(&stacks->stack_a);
}

void	rb(t_stacks	*stacks)
{
	rotate(&stacks->stack_b);
}

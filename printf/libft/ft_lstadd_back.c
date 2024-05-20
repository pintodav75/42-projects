/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:45:24 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/22 01:07:15 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// david nico brahim NULL
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (ptr == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = new;
			break ;
		}
		ptr = ptr->next;
	}
}

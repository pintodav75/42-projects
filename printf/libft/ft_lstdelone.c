/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:29:59 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/22 01:40:05 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL)
		return ;
	if (lst == NULL)
		return ;
	if (lst->content != NULL)
		del(lst->content);
	free(lst);
}

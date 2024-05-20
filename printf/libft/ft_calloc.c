/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:08:13 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/17 00:21:07 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	size = nmemb * size;
	ptr = malloc(size);
	if (ptr != NULL)
		ft_bzero(ptr, size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:25:17 by dpinto            #+#    #+#             */
/*   Updated: 2024/05/20 01:38:09 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_info
{
	char	*flag;
	char	*flagStar;
	char	converter;
	int		width;
}			t_info;

int			ft_printf(const char *format, ...);
void		ft_putnbr_base(long int nbr, char *base);
char		*get_converter(const char *format);
int			get_len_info(t_info *info);
int			ft_get_nbr_len(long int nbr, int base, char conv);
int			ft_get_nbr_len_u(unsigned long long int nbr, unsigned int base,
				char conv);
void		ft_putnbr_base_u(unsigned long long int nbr, char *base);

#endif

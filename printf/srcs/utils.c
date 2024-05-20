/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:39:52 by dpinto            #+#    #+#             */
/*   Updated: 2024/05/20 01:38:40 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_nbr_len_u(unsigned long long int nbr, unsigned int base, char conv)
{
	int	res;

	if (conv == 'c')
		return (1);
	if (conv == 'u')
		base = 10;
	if (nbr == 0)
		return (1);
	res = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		res++;
	}
	return (res);
}

int	ft_get_nbr_len(long int nbr, int base, char conv)
{
	int	res;

	if (conv == 'c')
		return (1);
	if (nbr < 0)
		return (1 + ft_get_nbr_len(-nbr, base, conv));
	if (nbr == 0)
		return (1);
	res = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		res++;
	}
	return (res);
}

void	ft_putnbr_base(long int nbr, char *base)
{
	size_t				base_len;
	unsigned long int	n;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		n = -nbr;
		ft_putchar_fd('-', 1);
	}
	else
		n = nbr;
	if (n < base_len)
		ft_putchar_fd(base[n], 1);
	else
	{
		ft_putnbr_base((n / base_len), base);
		ft_putnbr_base((n % base_len), base);
	}
}

void	ft_putnbr_base_u(unsigned long long int n, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
		ft_putchar_fd(base[n], 1);
	else
	{
		ft_putnbr_base((n / base_len), base);
		ft_putnbr_base((n % base_len), base);
	}
}

char	*get_converter(const char *format)
{
	int		i;
	char	*str;

	i = 0;
	while (format[i] != '\0')
	{
		str = ft_strchr("cspdiuxX%", format[i]);
		if (str != NULL)
			return (str);
		i++;
	}
	return (0);
}

int	get_len_info(t_info *info)
{
	int	res;

	res = 0;
	if (info->flag)
		res++;
	if (info->flagStar)
		res++;
	else
		res = res + ft_get_nbr_len(info->width, 10, '_');
	return (res);
}

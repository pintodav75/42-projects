/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:19:43 by dpinto            #+#    #+#             */
/*   Updated: 2024/05/20 01:38:16 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	parse_format(const char *format, va_list ap)
{
	char	*converter;
	char	*flag;
	char	*flagStar;
	int		width;
	t_info	info;

	converter = get_converter(format);
	flag = ft_strchr("-0.", format[0]);
	flagStar = ft_strchr(format, '*');
	width = ft_atoi(format);
	if (flag)
		width = ft_atoi(format + 1);
	if (flagStar != NULL)
		width = va_arg(ap, int);
	info.width = width;
	info.converter = *converter;
	info.flag = flag;
	info.flagStar = flagStar;
	return (info);
}

void	ft_putchar_n(char c, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_putchar_fd(c, 1);
}

int	ft_display_number(long int value, int width, char *flag, char conv)
{
	const int	len = ft_get_nbr_len(value, 10, conv);

	if (flag && *flag == '0' && width > len)
		ft_putchar_n('0', width - len);
	if (flag && *flag == '.' && width > len)
		ft_putchar_n('0', width - len);
	if (!flag && width > len)
		ft_putchar_n(' ', width - len);
	if (conv == 'c')
		ft_putchar_fd(value, 1);
	else if (conv == 'd' || conv == 'i')
		ft_putnbr_base(value, "0123456789");
	if (flag && *flag == '-' && width > len)
		ft_putchar_n(' ', width - len);
	if (width > len)
		return (width);
	return (len);
}

int	ft_display_number_u(unsigned int value, int width, char *flag, char conv)
{
	const int	len = ft_get_nbr_len_u(value, 16, conv);

	if (flag && *flag == '0' && width > len)
		ft_putchar_n('0', width - len);
	if (flag && *flag == '.' && width > len)
		ft_putchar_n('0', width - len);
	if (!flag && width > len)
		ft_putchar_n(' ', width - len);
	if (conv == 'u')
		ft_putnbr_base(value, "0123456789");
	else if (conv == 'x')
		ft_putnbr_base(value, "0123456789abcdef");
	else if (conv == 'X')
		ft_putnbr_base(value, "0123456789ABCDEF");
	if (flag && *flag == '-' && width > len)
		ft_putchar_n(' ', width - len);
	if (width > len)
		return (width);
	return (len);
}

int	ft_display_string(char *str, int width, char *flag)
{
	int	len;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(str);
	if (!flag && width > len)
		ft_putchar_n(' ', width - len);
	ft_putstr_fd(str, 1);
	if (flag && *flag == '-' && width > len)
		ft_putchar_n(' ', width - len);
	if (flag && *flag == '-' && width > len)
		return (width);
	if (!flag && width > len)
		return (width);
	return (len);
}

int	ft_display_ptr(unsigned long long int value, int width, char *flag)
{
	const int	len = ft_get_nbr_len_u(value, 16, 'X') + 2;

	if (!value)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	if (!flag && width > len)
		ft_putchar_n(' ', width - len);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_u(value, "0123456789abcdef");
	if (flag && *flag == '-' && width > len)
		ft_putchar_n(' ', width - len);
	if (width > len)
		return (width);
	return (len);
}

int	ft_display(t_info *info, va_list ap)
{
	if (info->converter == 'd' || info->converter == 'i'
		|| info->converter == 'c')
		return (ft_display_number(va_arg(ap, int), info->width, info->flag,
				info->converter));
	if (info->converter == 's')
		return (ft_display_string(va_arg(ap, char *), info->width, info->flag));
	if (info->converter == 'p')
		return (ft_display_ptr(va_arg(ap, unsigned long long), info->width,
				info->flag));
	if (info->converter == 'u' || info->converter == 'X'
		|| info->converter == 'x')
		return (ft_display_number_u(va_arg(ap, unsigned int), info->width,
				info->flag, info->converter));
	if (info->converter == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_info	info;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = parse_format(format + i + 1, ap);
			i = i + get_len_info(&info);
			len += ft_display(&info, ap);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

// #include "limits.h"

// int	main(void)
// {
// 	int			c;
// 	long int	a;
// 	long int	b;

// 	a = LONG_MAX;
// 	b = LONG_MIN;
// 	c = printf(" %p %p \n", &a, &b);
// 	printf("%d\n", c);
// 	c = ft_printf(" %p %p \n", &a, &b);
// 	printf("%d\n", c);
// }

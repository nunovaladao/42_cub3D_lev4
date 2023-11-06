/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:57:56 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/15 12:20:29 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(char format, va_list arg)
{
	if (format == '%')
		return (print_char('%'));
	else if (format == 'c')
		return (print_char(va_arg(arg, int)));
	else if (format == 's')
		return (print_str(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(arg, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'p')
		return (print_ptr(va_arg(arg, void *), "0123456789abcdef"));
	else if (format == 'x' || format == 'X')
	{
		if (format == 'X')
			return (print_hex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
		else
			return (print_hex(va_arg(arg, unsigned int), "0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		print_len;

	if (!str)
		return (0);
	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_check_format(str[i + 1], arg);
			i++;
		}
		else if (str[i] != '%')
			print_len += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (print_len);
}

/*int main()
{
	ft_printf("****only_string****\n");	
	ft_printf("printf\n\n");
	
	ft_printf("****char****\n");
	char c = 'c';
	char h = 'h';
	char r = 'r';
	ft_printf("%c %c %c\n\n", c, h, r);
	
	ft_printf("****string****\n");
	char *s = "nuno";	
	ft_printf("%s\n\n", s);

	ft_printf("****int****\n");
	int i = 5;
	int d = 4;	
	ft_printf("%i & %d\n\n", i, d);
	
	ft_printf("****unsigned****\n");
	int u = 0;	
	ft_printf("%u\n\n", u);

	ft_printf("****address pointer****\n");
	int *p;
	p = 0; 	
	ft_printf("%p\n\n", p);

	ft_printf("****hexa****\n");
	unsigned char a = 0x64;
	int b = 0xFAFA;
	
	ft_printf("value of a: %X [%x]\n",a,a);
	ft_printf("value of b: %X [%x]\n\n",b,b);
}*/

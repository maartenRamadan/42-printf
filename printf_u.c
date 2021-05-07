/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:02:43 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:35:11 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			print_spaces(t_struct *f)
{
	while (f->width > 0)
		f->width -= ft_write(f, " ", 1);
}

static int		pf_itou_len(unsigned long long n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*pf_ft_itou(unsigned long long n, t_struct *f)
{
	char	*str;
	int		len;

	len = pf_itou_len(n);
	str = malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	if (n == 0 && f->hasdot && !f->dot && f->width)
		print_spaces(f);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

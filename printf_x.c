/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_x.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 16:50:38 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:36:20 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		pf_itohex_len(long n, int len)
{
	if (n >= 16)
	{
		len = pf_itohex_len(n / 16, len + 1);
		pf_itohex_len(n % 16, len);
	}
	else
		len++;
	return (len);
}

char	pf_hex_to_str(long n, t_struct *f)
{
	int		abc;
	char	c;

	abc = 0;
	c = 0;
	if (n <= 9)
		c = (48 + n);
	else if (n > 9)
	{
		while (n > 9)
		{
			n--;
			abc++;
		}
		if (f->type == 'X')
			c = (64 + abc);
		else
			c = (96 + abc);
	}
	return (c);
}

char	*pf_itohex(long n, t_struct *f)
{
	char	*s;
	int		len;

	len = 0;
	len = pf_itohex_len(n, len);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[len - 1] = '0';
	while (n > 0)
	{
		len--;
		s[len] = pf_hex_to_str(n % 16, f);
		n = n / 16;
	}
	return (s);
}

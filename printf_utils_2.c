/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 10:22:38 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:35:28 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_write(t_struct *f, char *c, int len)
{
	f->ret += write(1, c, len);
	return (len);
}

size_t	pf_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		pf_ft_atoi(const char **str)
{
	unsigned long int	out;
	int					in;

	out = 0;
	in = 1;
	if (**str == '-')
	{
		in = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9' && **str != '\0')
	{
		out = out * 10 + (**str - '0');
		(*str)++;
	}
	(*str)--;
	return (in * out);
}

char	*pf_ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	s3 = (char*)malloc(sizeof(*s3) * (pf_ft_strlen(s1) +
	pf_ft_strlen(s2) + 2));
	if (!s3)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		s3[i] = s2[i2];
		i++;
		i2++;
	}
	s3[i] = '\0';
	return (s3);
}

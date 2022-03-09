/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtwo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:56:32 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:03:01 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_length(int n)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	int		len;
	int		i;

	tmp = n;
	i = 0;
	len = ft_length(tmp);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	if (tmp < 0)
		str[i] = '-';
	if (tmp < 0)
		tmp *= -1;
	i = len - 1;
	if (tmp == 0)
		str[i] = '0';
	while (tmp)
	{
		str[i--] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*s;
	char	*t_src;

	i = 0;
	len = 0;
	t_src = (char *)src;
	while (t_src[len])
	{
		len++;
	}
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!(s))
	{
		return (NULL);
	}
	while (t_src[i])
	{
		s[i] = t_src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

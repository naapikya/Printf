/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:33:01 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:14:31 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstrprec(char *str, int prec)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar_pft(str[char_count++]);
	return (char_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:31:11 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:22:47 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_char(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar_pft(c);
	char_count = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar_pft(c);
	return (char_count + 1);
}

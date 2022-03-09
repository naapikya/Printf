/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:22:00 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:16:36 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_width(int width, int minus, int has_zero)
{
	int	char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar_pft('0');
		else
			ft_putchar_pft(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

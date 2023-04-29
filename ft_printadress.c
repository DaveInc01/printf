/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:33:32 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/05/03 22:41:32 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_adress(char *outbuf, unsigned long long int n)
{
	size_t	len;
	int		j;

	j = 0;
	while (n != 0)
	{
		outbuf[j++] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	outbuf[j] = '\0';
	len = ft_strlen(outbuf);
	j = len;
	if (len)
		write(1, "0x", 2);
	while (len-- > 0)
		write(1, &outbuf[len], 1);
	free (outbuf);
	return (j + 2);
}

int	ft_printadress(void *ptr)
{
	int							j;
	unsigned long long int		n;
	char						*outbuf;

	j = 0;
	if (!ptr)
		return (ft_printstr("0x0"));
	n = (unsigned long long int) ptr;
	while (n != 0)
	{
		n = n / 16;
		j++;
	}
	outbuf = malloc(sizeof(char) * j + 1);
	if (!outbuf)
		return (0);
	n = (unsigned long long int) ptr;
	return (write_adress(outbuf, n));
}

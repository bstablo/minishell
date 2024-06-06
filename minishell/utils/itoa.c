/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:00:03 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:37:53 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isneg(int n)
{
	if (n == -2147483648)
		n = 147483648;
	else
		n = -n;
	return (n);
}

int	ft_sizenb(int nb)
{
	int	size;

	size = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb = nb * -1;
		size++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	if (nb == -2147483648)
		size = 11;
	if (size == 0)
		size = 1;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_sizenb(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
			str[1] = '2';
		n = ft_isneg(n);
	}
	while (n > 0)
	{
		str[size] = 48 + (n % 10);
		n = n / 10;
		size--;
	}
	return (str);
}

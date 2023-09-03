/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:14:28 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/03 19:22:32 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *src)
{
	int		n;
	int		x;
	int		lon;
	char	*str;

	lon = 0;
	while (src[lon])
	{
		if (src[lon] == 92)
			lon++;
		lon++;
	}
	str = (char *)malloc(sizeof(char) * lon + 1);
	if (str == NULL)
		return (NULL);
	n = 0;
	x = 0;
	while (src[x])
	{
		str[n] = src[x];
		if (src[x] != 92)
			x++;
		n++;
	}
	str[n] = '\0';
	free(src);
	return (str);
}
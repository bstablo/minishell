/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:52:07 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:37:18 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*line_prompt(char *line, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	if (!line)
		signal_exit();
	return (line);
}

static int	ft_is_set(char c, char const *set)
{
	int	i;
	int	size_set;

	i = 0;
	size_set = ft_strlen(set);
	while (i < size_set)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*finalstr(char *s1, int i, int j)
{
	int		len;
	char	*str;

	if (!s1)
		return (0);
	len = (ft_strlen(s1)) - (i + j);
	if (len < 0)
		str = (char *) malloc(sizeof(char));
	else
		str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s1);
	if (!s1)
		return (0);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	while (ft_is_set(s1[size - 1], set) && size >= 0)
	{
		size--;
		j++;
	}
	return (finalstr((char *)s1, i, j));
}

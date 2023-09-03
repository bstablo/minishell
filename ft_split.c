/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:40:28 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/03 13:41:46 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_nb_word(char const *str, char c)
{
	size_t	n;
	size_t	x;

	n = 0;
	x = 0;
	while (str[n] != '\0')
	{
		if ((str[n + 1] == c && str[n] != c)
			|| (str[n + 1] == '\0' && str[n] != c))
			x++;
		n++;
	}
	return (x);
}

static size_t	size_word(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

char	*ft_copy(char const *str, char c, size_t *nb_word)
{
	char	*word;
	size_t	x;
	size_t	sw;

	while (str[*nb_word] && str[*nb_word] == c)
		*nb_word = *nb_word + 1;
	x = 0;
	sw = size_word((str + *nb_word), c);
	word = (char *)malloc(sizeof(char) * (sw + 1));
	while (sw > x)
	{
		word[x] = str[*nb_word];
		*nb_word = *nb_word + 1;
		x++;
	}
	word[x] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb;
	size_t	n;
	size_t	index;
	char	**tab;

	n = 0;
	nb = ft_nb_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (nb > index)
	{
		tab[index] = ft_copy(s, c, &n);
		index++;
	}
	tab[nb] = NULL;
	return (tab);
}
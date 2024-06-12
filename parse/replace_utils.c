/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:27:34 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/11 20:56:53 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find(char c, char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (c == s[i])
			return (1);
	}
	return (0);
}

int	count_symbol(char *str, char *s)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (find(str[i], s) == 1)
			return (i);
	}
	return (i);
}

char	*findexp(t_exp *atc, char *str)
{
	t_exp	*head;

	head = atc;
	while (head)
	{
		if (!ft_strcmp(head->name, str))
		{
			return (head->content);
		}
		head = head->next;
	}
	return ("");
}

char	*ft_strdup2(const char *s, int size)
{
	int		i;
	char	*new;

	if (s == NULL || !s)
		return (NULL);
	if (size == 0)
		return ("");
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	while (s[i] && i < size)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*dblquotesdollar(int *i, const char *res)
{
	*i += 1;
	return ((char *)res);
}

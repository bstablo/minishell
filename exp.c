/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:21:40 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 05:52:57 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	insert_exp(char **envp, t_exp **exp)
{
	t_exp	*new;
	char	**tab;
	int		i;

	i = -1;
	while (envp[++i])
	{
		tab = ft_split(envp[i], '=');
		new = expnew(tab[1], tab[0]);
		ft_exp(exp, new);
		free(tab);
	}
	if (envp[0] == NULL)
	{
		new = expnew(getcwd(NULL, 0), "PWD=");
		ft_exp(exp, new);
	}
}

t_exp	*expnew(void *content, char *key)
{
	t_exp	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->name = key;
	element->next = NULL;
	return (element);
}

t_exp	*explast(t_exp *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_exp(t_exp **exp, t_exp *new)
{
	t_exp	*tmp;

	if (!*exp)
		*exp = new;
	else
	{
		tmp = explast(*exp);
		tmp->next = new;
	}
}

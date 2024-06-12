/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:46:16 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/11 11:46:39 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export(t_global *global, t_exp *exp)
{
	t_exp	*tmp;
	char	**tab;
	int		i;

	tmp = exp;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab = ft_export2(tab, exp);
	tab = ft_export3(tab);
	ft_export4(tab, exp);
	print_exp(exp);
	free_tab(tab);
	global->status = 0;
}

char	**ft_export2(char **tab, t_exp *exp)
{
	t_exp	*lst;
	int		i;

	i = 0;
	lst = exp;
	while (lst)
	{
		if (lst->content)
		{
			lst->name = ft_concatenate(lst->name, "=");
			tab[i] = ft_concatenate(lst->name, lst->content);
		}
		else
			tab[i] = lst->name;
		i++;
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_export3(char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!ismore(tab[i], tab[j]))
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	ismore(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	if (s1[i] < s2[i])
		return (1);
	return (0);
}

void	ft_export4(char **tab, t_exp *exp)
{
	int		i;
	t_exp	*tmp;

	i = 0;
	tmp = exp;
	while (tab[i])
	{
		if (ft_find_space(tab[i]))
		{
			tmp->name = ft_prt(tab[i]);
			tmp->content = ft_prt2(tab[i]);
		}
		else
			tmp->name = tab[i];
		tmp = tmp->next;
		i++;
	}
}

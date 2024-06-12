/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:14:32 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:06:33 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exp	*add(t_exp *exp, char *str)
{
	t_exp	*tmp;
	t_exp	*tmp2;
	char	**prt;
	int		i;

	i = 0;
	tmp = exp;
	tmp2 = exp;
	prt = NULL;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt[0] = ft_prt(str);
	prt[1] = ft_prt2(str);
	prt[2] = NULL;
	while (tmp2)
	{
		if (!ft_strcmp(tmp2->name, prt[0]))
			i++;
		tmp2 = tmp2->next;
	}
	tmp = add_2(tmp, prt, i);
	return (exp);
}

t_exp	*add_2(t_exp *tmp, char **prt, int i)
{
	if (i == 0)
		tmp = add_3(tmp, prt);
	else
	{
		while (ft_strcmp(tmp->name, prt[0]) != 0)
			tmp = tmp->next;
		tmp->content = prt[1];
	}
	return (tmp);
}

t_exp	*add_3(t_exp *tmp, char **prt)
{
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = ft_strdup(prt[0]);
	new->content = ft_strdup(prt[1]);
	new->next = NULL;
	return (tmp);
}

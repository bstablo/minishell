/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:33:33 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:36 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exp	*add6(t_exp *exp, char *str)
{
	t_exp	*tmp;
	char	*prt;
	char	*prt2;
	int		i;

	i = 0;
	tmp = exp;
	prt = ft_prt(str);
	prt2 = ft_prt2(str);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, prt))
			i++;
		tmp = tmp->next;
	}
	tmp = add6_2(exp, prt, prt2, i);
	return (exp);
}

t_exp	*add6_2(t_exp *tmp, char *prt, char *prt2, int i)
{
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	if (i == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->name = ft_strdup(prt);
		new->content = ft_strdup(prt2);
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->name, prt))
			tmp = tmp->next;
		tmp->content = ft_strdup(ft_strjoin_no_spc(tmp->content, prt2));
	}
	return (tmp);
}

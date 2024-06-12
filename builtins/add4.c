/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:33:28 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:07:33 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exp	*add4(t_exp *exp, char *str)
{
	t_exp	*tmp;
	char	**prt;
	t_exp	*tmp2;
	int		i;

	i = 0;
	tmp2 = exp;
	tmp = exp;
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
	if (i == 0)
		tmp = add4_2(tmp, prt);
	else
		tmp = add4_3(tmp, prt);
	return (exp);
}

t_exp	*add4_2(t_exp *tmp, char **prt)
{
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = prt[0];
	new->content = prt[1];
	new->next = NULL;
	return (tmp);
}

t_exp	*add4_3(t_exp *tmp, char **prt)
{
	while (ft_strcmp(tmp->name, prt[0]))
		tmp = tmp->next;
	tmp->content = prt[1];
	return (tmp);
}

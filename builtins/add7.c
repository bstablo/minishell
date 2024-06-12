/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:33:35 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:35 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*add7(t_lst *lst, char *str)
{
	t_lst	*tmp;
	char	*prt;
	char	*prt2;
	int		i;

	i = 0;
	tmp = lst;
	prt = ft_prt(str);
	prt2 = ft_prt2(str);
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, prt))
			i++;
		tmp = tmp->next;
	}
	tmp = add7_2(lst, prt, prt2, i);
	return (lst);
}

t_lst	*add7_2(t_lst *tmp, char *prt, char *prt2, int i)
{
	t_lst	*new;

	new = malloc(sizeof(*tmp));
	if (i == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->content = ft_strdup(prt);
		new->content = ft_strdup(prt2);
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->content, prt))
			tmp = tmp->next;
		tmp->content = ft_strdup(ft_strjoin_no_spc(tmp->content, prt2));
	}
	return (tmp);
}

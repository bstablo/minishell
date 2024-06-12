/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:33:30 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:09 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*add5(t_lst *lst, char *str)
{
	t_lst	*tmp;
	char	**prt;
	t_lst	*tmp2;
	int		g;

	g = 0;
	tmp2 = lst;
	tmp = lst;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt[0] = ft_prt(str);
	prt[1] = ft_prt2(str);
	prt[2] = NULL;
	while (tmp2)
	{
		if (!ft_strcmp(tmp2->content, prt[0]))
			g++;
		tmp2 = tmp2->next;
	}
	if (g == 0)
		tmp = add5_2(tmp, prt);
	else
		tmp = add5_3(tmp, prt);
	return (lst);
}

t_lst	*add5_2(t_lst *tmp, char **prt)
{
	t_lst	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->content = prt[0];
	new->content = prt[1];
	new->next = NULL;
	return (tmp);
}

t_lst	*add5_3(t_lst *tmp, char **prt)
{
	while (ft_strcmp(tmp->content, prt[0]))
		tmp = tmp->next;
	tmp->content = prt[1];
	return (tmp);
}

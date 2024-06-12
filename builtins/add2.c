/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:29:00 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:07:04 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*add2(t_lst *lst, char *str)
{
	t_lst	*tmp;
	char	**prt;
	t_lst	*tmp2;
	int		i;

	i = 0;
	tmp2 = lst;
	tmp = lst;
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
	add2_1(tmp, prt, i);
	return (lst);
}

void	add2_1(t_lst *tmp, char **prt, int i)
{
	if (i == 0)
		tmp = add2_2(tmp, prt);
	else
	{
		while (ft_strcmp(tmp->name, prt[0]) != 0)
			tmp = tmp->next;
		tmp->content = prt[1];
	}
}

t_lst	*add2_2(t_lst *tmp, char **prt)
{
	t_lst	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = new;
	new->name = prt[0];
	new->content = prt[1];
	new->next = NULL;
	return (tmp);
}

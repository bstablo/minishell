/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:27 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 14:54:26 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exp	*add3(t_exp *exp, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	t_exp	*tmp2;
	int		i;

	i = 0;
	tmp2 = exp;
	new = malloc(sizeof(t_exp) * 1);
	tmp = exp;
	while (tmp2)
	{
		if (!ft_strcmp(tmp2->name, str))
			i++;
		tmp2 = tmp2->next;
	}
	if (i == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->name = ft_strdup(str);
		new->content = ft_strdup("(null)");
		new->next = NULL;
	}
	return (exp);
}

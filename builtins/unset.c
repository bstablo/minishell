/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:56:04 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 13:02:01 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_global *global, t_lst **lst, t_exp **exp)
{
	t_parse	*parse;
	int		i;

	parse = global->parse;
	i = 0;
	ft_unset2(lst, i, parse);
	ft_unset3(exp, i, parse);
	global->status = 0;
}

void	ft_unset2(t_lst **lst, int i, t_parse *parse)
{
	t_lst	*head;
	t_lst	*temp;

	head = *lst;
	while (parse->arg[i])
	{
		while ((*lst)->next)
		{
			if ((*lst)->next && !ft_strcmp((*lst)->next->name, parse->arg[i]))
			{
				free((*lst)->next->content);
				free((*lst)->next->name);
				temp = (*lst)->next;
				(*lst)->next = (*lst)->next->next;
				free(temp);
				break ;
			}
			(*lst) = (*lst)->next;
		}
		*lst = head;
		i++;
	}
}

void	ft_unset3(t_exp **exp, int i, t_parse *parse)
{
	t_exp	*head;
	t_exp	*temp;

	head = *exp;
	while (parse->arg[i])
	{
		while (*exp)
		{
			if ((*exp)->next && !ft_strcmp((*exp)->next->name, parse->arg[i]))
			{
				free((*exp)->next->content);
				free((*exp)->next->name);
				temp = (*exp)->next;
				(*exp)->next = (*exp)->next->next;
				free(temp);
				break ;
			}
			(*exp) = (*exp)->next;
		}
		*exp = head;
		i++;
	}
}

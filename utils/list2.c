/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:02:40 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/09 14:49:00 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstiter2(t_lst *lst, void (*f)(void *))
{
	t_lst	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		tmp = lst->next;
		lst = tmp;
	}
}

void	ft_lstdelone2(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

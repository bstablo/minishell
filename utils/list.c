/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:01:36 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/09 14:48:45 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_front2(t_lst **alst, t_lst *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear2(t_lst **lst, void (*del)(void*))
{
	t_lst	*tmp;

	if (!*lst && !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone2(*lst, del);
		*lst = tmp;
	}
}

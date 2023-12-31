/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:31:53 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/03 14:27:33 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*La fonction est la boucle faisant tourner le shell en continue. Readline permet de lire ce que l'utilisateur a écrit sur l'entrée et de le stocker.
La fonction permet également d'afficher le prompt.*/
void	loop()
{
	char	*reading;

	while (1)
	{
		reading = readline("User$ ");
		add_history(reading);
		if (reading == NULL)
			break ;
		free(reading);
	}
	return (0);
}
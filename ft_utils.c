/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:57:48 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/11 22:19:54 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./minishell.h"

char	*ft_concatenate(char *line, char *bf)
{
	char		*temp;

	temp = line;
	line = ft_strjoin(temp, bf);
	return (line);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	if ((!s1 || s1 == NULL) || (!s2 || s2 == NULL))
		return (-1);
	while (str1[++i] && str2[i])
	{
		if (str1[i] != str2[i])
			break ;
	}
	return (str1[i] - str2[i]);
}

char	*ft_strjoin_no_spc(const char *s1, const char *s2)
{
	char	*str;
	int		slen;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	slen = ft_strlen((char *)s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free ((void *)s1);
	free ((void *)s2);
	return (str);
}

void	print_list(t_global *global, t_lst *lst)
{
	while (lst)
	{
		if (lst->content == NULL)
			printf("%s= \n", lst->name);
		else
			printf("%s=%s \n", lst->name, (char *)lst->content);
		lst = lst->next;
	}
	global->status = 0;
}

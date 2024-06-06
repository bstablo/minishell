/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:33:41 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:20:29 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char	*first, const char	*second)
{
	unsigned int	i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *) first;
	s = (unsigned char *) second;
	i = 0;
	if (!first || !second)
		return (0);
	while (f[i] == s[i] && f[i] != '\0' && s[i] != '\0')
		i++;
	return (f[i] - s[i]);
}

int	ft_strncmp(const char	*first, const char	*second, size_t length)
{
	unsigned int	i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *) first;
	s = (unsigned char *) second;
	i = 0;
	if (length == 0)
		return (0);
	if (!first || !second)
		return (0);
	while (f[i] == s[i] && f[i] != '\0' && s[i] != '\0'
		&& i < length - 1)
		i++;
	return (f[i] - s[i]);
}

static void	here2(int file, t_parse *parse)
{
	close(file);
	file = open("/tmp/heredoc.tmp", O_RDONLY, 0007);
	init_file(file, 2, parse);
}

void	heredoc(char *stop, t_parse *parse, t_global *global)
{
	char	*line;
	int		file;

	file = open("/tmp/heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file < 0)
		ft_putstr_fd("problem with heredoc\n", 2);
	global->parse->fd_kill = file;
	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || line == NULL)
			break ;
		if (ft_strncmp(line, stop, ft_strlen(stop)) == 0
			&& (ft_strlen(stop) == ft_strlen(line)))
		{
			free(line);
			break ;
		}
		write(file, line, ft_strlen(line));
		write(file, "\n", 1);
		free(line);
	}
	here2(file, parse);
}

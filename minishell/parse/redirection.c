/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 04:04:59 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:31:48 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_file(int fd, int i, t_parse *parse)
{
	if (i == 2)
	{
		if (parse->infile == 0)
			parse->infile = fd;
		else
		{
			close(parse->infile);
			parse->infile = fd;
		}
	}
	else
	{
		if (parse->outfile == 1)
			parse->outfile = fd;
		else
		{
			close(parse->outfile);
			parse->outfile = fd;
		}
	}
}

void	open_file(char *str, int i, t_parse *parse)
{
	int	file;

	file = 0;
	if (i == 0)
	{
		file = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else if (i == 1)
		file = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
	{
		file = open(str, O_RDONLY, 0777);
		if (file == -1)
			parse->infile = 0;
	}
	init_file(file, i, parse);
}

int	redirect_opening(char *line, int i, t_parse *parse, t_global *global)
{
	int		j;

	j = i;
	if (line[i + 1] == 62)
	{
		j += 2;
		parse->sfile = ft_expand(nextword(line + i + 2, &j), global);
		open_file(parse->sfile, 0, parse);
	}
	else
	{
		j++;
		parse->sfile = ft_expand(nextword(line + i + 1, &j), global);
		open_file(parse->sfile, 1, parse);
	}
	return (j);
}

int	redirect_closing(char *line, int i, t_parse *parse, t_global *global)
{
	int		j;

	j = i;
	if (line[i + 1] == 60)
	{
		j += 2;
		parse->sfile = nextword(line + i + 2, &j);
		global->here = 1;
		heredoc(parse->sfile, parse, global);
		global->here = 0;
	}
	else
	{
		j++;
		parse->sfile = ft_expand(nextword(line + i + 1, &j), global);
		open_file(parse->sfile, 2, parse);
	}
	return (j);
}

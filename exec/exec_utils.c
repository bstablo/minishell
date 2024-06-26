/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:42:55 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:38:47 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmdin_parse(t_global *global, t_parse *parse)
{
	t_parse	*lst;

	lst = parse;
	while (lst)
	{
		if (lst->infile == 0 && lst->outfile == 1 \
			&& lst->cmd == NULL && ft_strlen(lst->flag) == 1)
		{
			if (len_parse(global) == 1)
				return (1);
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
			global->status = 258;
			return (1);
		}
		if ((lst->infile == -1 || lst->outfile == -1) \
			&& lst->sfile[0] == '\0')
		{
			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
			global->status = 258;
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	len_parse(t_global *global)
{
	t_parse	*lst;
	int		i;

	i = 0;
	lst = global->parse;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**check_elem(t_global *global, t_parse *parse, t_lst *lst, char **lab)
{
	int	i;
	int	t;
	int	size;

	i = 1;
	t = 0;
	size = len_envp(parse->arg) + 2;
	if (ft_strlen(parse->flag) > 1)
	{
		i++;
		size++;
	}
	lab = ft_calloc(sizeof(char *), size);
	if (parse->cmd != NULL)
		lab[0] = check_path_access(global, lst, parse->cmd);
	if (ft_strlen(parse->flag) > 1)
		lab[1] = ft_strdup(parse->flag);
	if (parse->arg != NULL)
	{
		while (parse->arg[t])
			lab[i++] = ft_strdup(parse->arg[t++]);
	}
	return (lab);
}

void	ft_execve(t_global *global, t_parse *parse, t_lst *lst, char **lab)
{
	int		pid;
	char	**tmp;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		tmp = enov(lst);
		if (execve(lab[0], lab, tmp) == -1)
		{
			ft_err_execve(global, parse);
			free_tab(lab);
			exit(global->status);
		}
	}
	else
	{
		waitpid(pid, &parse->exit_code, 0);
		global->status = exitstatus(parse->exit_code);
	}
}

void	dupfunction(t_global *global, t_parse *parse, int *fd, int fdin)
{
	if (parse->outfile != 1 || parse->indice == len_parse(global))
		dup2(parse->outfile, STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	if (parse->infile != 0)
		dup2(parse->infile, STDIN_FILENO);
	else
		dup2(fdin, STDIN_FILENO);
	if (parse->infile < 0)
	{
		perror(parse->sfile);
		global->status = 1;
		exit (1);
	}
}

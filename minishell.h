/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:18:41 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:50:43 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/stat.h>
#include <stdint.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdint.h>
# include "libft/libft.h"
# include <sys/ioctl.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_lst
{
	void			*content;
	char			*name;
	struct s_lst	*next;
}				t_lst;

typedef struct s_parse
{
	char			*cmd;
	char			**arg;
	char			*flag;
	char			*sfile;
	int				first;
	int				i;
	int				indice;
	int				infile;
	int				outfile;
	int				fd_kill;
	int				exit_code;
	struct s_parse	*next;
}				t_parse;

typedef struct s_exp
{
	void			*content;
	char			*name;
	struct s_exp	*next;
}				t_exp;

typedef struct s_global
{
	t_parse	*parse;
	t_exp	*exp;
	t_lst	*lst;
	int		status;
	int		nb_cmd;
	int		*indice;
	int		old_stdin;
	int		old_stdout;
}				t_global;

//************* MAIN *************//
void	init(char **envp, t_exp *exp, t_lst *lst, t_global *global);

//************* BUILTINS *************//
			// EXIT.C //
int		ft_exit(t_global *global, char **str);
int		ft_num(char *str);
			// UNSET.C //
void	unset(t_global *global, t_lst **lst, t_exp **exp);
void	unset2(t_lst **lst, int i, t_parse *elem);
void	unset3(t_exp **exp, int i, t_parse *elem);

//************* EXEC *************//
			// EXEC.C //
void	brain(t_global *global, t_lst *lst);
void	exec_lab(t_global *global, t_parse *elem, t_lst *lst);
void	ft_fils(t_global *global, t_parse *elem, t_lst *lst, int fdin);
void	exec_cmd(t_global *global, t_parse *parse, t_lst *lst, char **lab);
void	exec_cmdmulti(t_global *global, t_parse *parse, t_lst *lst, char **lab);
			// EXEC_UTILS .C //
int		cmdin_parse(t_global *global, t_parse *parse);
int		len_parse(t_global *global);
char	**check_elem(t_global *global, t_parse *parse, t_lst *lst, char **lab);
void	ft_execve(t_global *global, t_parse *parse, t_lst *lst, char **lab);
void	dupfunction(t_global *global, t_parse *elem, int *fd, int fdin);

void	wronglastcmd(t_global *global, t_parse *parse, t_lst *lst);
int		isbuiltin(char *str);

//************* ERRORS.C *************//
void	ft_perror(t_global *global, char *s1, char *s2, int index);
void	ft_err_execve(t_global *global, t_parse *parse);
void	msg_error(char *err);

//************* SIGNALS.C *************//
void	init_signals(void);
void	ft_signal(int signum);
int		exitstatus(int status);

//************* UTILS.C *************//
char	**enov(t_lst *lst);
int		len_envp(char **envp);
int		ft_slash(char *str);

//************* CHECK_PATH.C *************//
char	*check_path_access(t_global *global, t_lst *lst, char *cmd);
char	*check_path2(char **tab_path, char *test, char *path);
char	**split_path(t_lst *lst, char **tab_path);

//************* FREE.C *************//
void	free_tab(char **tab);

//************* BUILTINS *************//
void	ft_unset(t_global *global, t_lst **lst, t_exp **exp);
void	ft_unset2(t_lst **lst, int i, t_parse *elem);
void	ft_unset3(t_exp **exp, int i, t_parse *elem);

int		ft_exit(t_global *global, char **str);
int		ft_num(char *str);

void	ft_export(t_global *global, t_exp *exp);
char	**ft_export2(char **tab, t_exp *exp);
char	**ft_export3(char **tab);
void	ft_export4(char **tab, t_exp *exp);
int		ft_find_space(char *str);
void	print_exp(t_exp *exp);
int		ismore(char *s1, char *s2);
t_exp	*add(t_exp *exp, char *str);
t_exp	*add_2(t_exp *tmp, char **prt, int i);
t_exp	*add_3(t_exp *tmp, char **prt);
t_lst	*add2(t_lst *lst, char *str);
void	add2_1(t_lst *tmp, char **prt, int i);
t_lst	*add2_2(t_lst *tmp, char **prt);
t_exp	*add3(t_exp *exp, char *str);
t_exp	*add4(t_exp *exp, char *str);
t_exp	*add4_2(t_exp *tmp, char **prt);
t_exp	*add4_3(t_exp *tmp, char **prt);
t_lst	*add5(t_lst *lst, char *str);
t_lst	*add5_2(t_lst *tmp, char **prt);
t_lst	*add5_3(t_lst *tmp, char **prt);
t_exp	*add6(t_exp *exp, char *str);
t_exp	*add6_2(t_exp *tmp, char *prt, char *prt2, int i);
t_lst	*add7(t_lst *lst, char *str);
t_lst	*add7_2(t_lst *tmp, char *prt, char *prt2, int i);
char	*ft_prt(char *str);
char	*ft_prt2(char *str);
void	ft_port(t_global *global, t_exp *exp, t_lst *lst);
void	ft_port2(t_lst *lst, t_parse *parse, int p, t_exp *exp);
int		check(char *str);
int		check2(char *str, int i, int j);
int		check3(int j, int t);
void	ft_echo(t_parse *parse);
void	ft_pwd(void);
void	ft_cd(t_global *global, t_parse *parse, t_lst *lst);

char	*ft_concatenate(char *line, char *bf);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin_no_spc(const char *s1, const char *s2);
int		ft_lstsize2(t_lst *lst);
char	*tolower2(char *cmd);
void	print_list(t_global *global, t_lst *lst);

//************* PARSE *************//

int		ft_cmd_arg(char *line, int i, t_parse *head);
char	**ft_realloc2char(char **src, int size, int start);
t_parse	*ft_pipe(t_parse *head, int *i, t_global *t);
void	heredoc(char *stop, t_parse *parse, t_global *global);
char	*nextword(char *line, int *j);
char	*ft_strjoin_no_spc(const char *s1, const char *s2);
char	*ft_strncpy(char *s, int j);
int		ft_flag(char *line, int i, t_parse *head);
t_parse	*ft_new_parse(t_global *global);
void	lexer(char *line, t_global *global);
char	*trflag(char *str);
int		check_quotes(char *str, int i);
int		handle_quotes(char *line, int i, t_parse *parse);
void	init_file(int fd, int i, t_parse *parse);
void	open_file(char *str, int i, t_parse *parse);
int		redirect_opening(char *line, int i, t_parse *parse, t_global *global);
int		redirect_closing(char *line, int i, t_parse *parse, t_global *global);
int		find(char c, char *s);
int		count_symbol(char *str, char *s);
char	*findexp(t_exp *exp, char *str);
char	*ft_strdup2(const char *s, int size);
char	*dblquotesdollar(int *i, const char *res);
char	*quote_found(int *i, const char *res, char *str);
char	*dblquotes_found(int *i, const char *res, char *str, t_global *global);
char	*dollar_found_after_dblq(int *i, const char *res,
			char *str, t_global *global);
char	*dollar_found(int *i, const char *res, char *str, t_global *global);
char	*else_dbl(int *i, const char *res, char *str, int *t);
char	*repelse(int *i, const char *res, char *str);
char	*inexpand(int *i, const char *res, char *str, t_global *global);
char	*ft_expand(char *str, t_global *global);
void	replacev(t_global *global);
void	signal_exit(void);
char	*line_prompt(char *line, char **argv, int argc);
void	ft_exp(t_exp **exp, t_exp *new);
t_exp	*expnew(void *content, char *key);
void	insert_exp(char **envp, t_exp **exp);
void	insert_env(char **envp, t_lst **lst);
void	free_all(t_global *global);
void	killhere(t_global *global);
t_lst	*ft_lstnew2(void *content, char *key);
void	ft_lstadd_back2(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast2(t_lst *lst);
t_exp	*explast(t_exp *lst);
void	ft_lstdelone2(t_lst *lst, void (*del)(void *));
int		ft_lstsize2(t_lst *lst);
void	ft_lstadd_back_parse(t_parse **lst, t_parse *new);
void	ft_signalquit(int signum);

#endif
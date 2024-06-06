/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:18:41 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 12:58:46 by bstablo          ###   ########.fr       */
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
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
//# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_list
{
	void			*content;
	char			*name;
	struct s_list	*next;
}				t_list;

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
	t_exp	*atc;
	int		status;
	int		nb_cmd;
	int		here;
	int		*indice;
	char	**env;
	int		old_stdin;
	int		old_stdout;
}				t_global;

			// MAIN //

void	init(char **envp, t_exp *atc, t_list *alst, t_global *global);

			// EXEC.C //
void	brain(t_global *global, t_list *lst, t_exp *exp);
void	exec_lab(t_global *global, t_parse *elem, t_list *lst, t_exp *exp);
void	ft_fils(t_global *global, t_parse *elem, t_list *lst, t_exp *exp, int fdin);
void	exec_cmd(t_global *global, t_parse *parse, t_list *lst, t_exp *exp, char **lab);
void	exec_cmdmulti(t_global *global, t_parse *parse, t_list *lst, t_exp *exp, char **lab);
			// EXEC_UTILS .C //
int		cmdin_parse(t_global *global, t_parse *parse);
int		len_parse(t_global *global);
char	**check_elem(t_global *global, t_parse *parse, t_list *lst, char **lab);
void	ft_execve(t_global *global, t_parse *parse, t_list *lst, char **lab);
void	dupfunction(t_global *global, t_parse *elem, int *fd, int fdin);

//************* ERRORS.C *************//
void	ft_perror(t_global *global, char *s1, char *s2, int index);
void	ft_err_execve(t_global *global, t_parse *parse);
void	msg_error(char *err);

//************* SIGNALS.C *************//
void	init_signals(t_global *global);
void	echo_control_seq(int i);
void	*ft_signal(t_global *global);
void	*ft_signalquit(t_global *global);
int		exitstatus(int status);

//************* UTILS.C *************//
char		**enov(t_list *alst);
int			len_envp(char **envp);
int			ft_slash(char *str);
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
int			ft_isneg(int n);
int			ft_sizenb(int nb);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content, char *key);
int			ft_lstsize(t_list *lst);
char		*line_prompt(char *line, char **argv, int argc);
static int	ft_is_set(char c, char const *set);
static char	*finalstr(char *s1, int i, int j);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_atoi(const char *str);
char    	**list_to_array(t_parse *head);
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char	*first, const char	*second, size_t length);
int			ft_strcmp(const char	*first, const char	*second);


//************* CHECK_PATH.C *************//
char	*check_path_access(t_global *global, t_list *alst, char *cmd);
char	*check_path2(char **tab_path, char *test, char *path);
char	**split_path(t_list *alst, char **tab_path);

//************* FREE.C *************//
void	free_tab(char **tab);

//************* PARSE *************//

int		ft_cmd_arg(char *line, int i, t_parse *head);
char	**ft_realloc2char(char **src, int size, int start);
t_parse	*ft_pipe(t_parse *head, int *i, t_global *t);
static void here2(int file, t_parse *parse);
void    heredoc(char *stop, t_parse *parse, t_global *global);
char 	*nextword(char *line, int *j);
char	*ft_strjoin_no_spc(const char *s1, const char *s2);
char	*ft_strncpy(char *s, int j);
int		ft_flag(char *line, int i, t_parse *head);
t_parse	*ft_new_parse(t_global *global);
void	lexer(char *line, t_parse *head, t_global *global);
char	*trflag(char *str);
int		check_quotes(char *str, int i);
int 	handle_quotes(char *line, int i, t_parse *parse);
void	init_file(int fd, int i, t_parse *parse);
void	open_file(char *str, int i, t_parse *parse);
int		redirect_opening(char *line, int i, t_parse *parse, t_global *global);
int		redirect_closing(char *line, int i, t_parse *parse, t_global *global);
int		find(char c, char *s);
int		count_symbol(char *str, char *s);
char	*findexp(t_exp *atc, char *str);
char	*ft_strdup2(const char *s, int size);
char	*dblquotesdollar(int *i, const char *res);
char	*quote_found(int *i, const char *res, char *str);
char	*dblquotes_found(int *i, const char *res, char *str, t_global* global);
char	*dollar_found_after_dblq(int *i, const char *res, char *str, t_global *global);
char	*dollar_found(int *i, const char *res, char *str, t_global *global);
char	*else_dbl(int *i, const char *res, char *str, int *t);
char	*repelse(int *i, const char *res, char *str);
char	*inexpand(int *i, const char *res, char *str, t_global *global);
char	*ft_expand(char *str, t_global *global);
void	replacev(t_parse *head, t_global *global);































#endif
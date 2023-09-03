/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfere <gfere@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:40:19 by gfere             #+#    #+#             */
/*   Updated: 2023/09/03 13:40:19 by gfere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct  s_env
{
    char            *value;
    struct s_env    *next;
}               t_env;

typedef struct  s_shell
{
    t_env       *env;
    int         exit;
    

}               t_shell;  

#endif

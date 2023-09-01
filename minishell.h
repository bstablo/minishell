#ifndef MINISHELL_H
# define MINISHELL_H


#include <stlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct  s_env
{
    char            *value;
    struct s_env    *next;
}               t_env;

typedef struct  s_shell
{
    t_env       *env;

}               t_shell;  

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:39:09 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/01 21:39:09 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initialise un nouvelle environnement en remplissant une liste chainée avec des
  variables d'environnement entrées en parametre en tableau de chaines.*/
int env_init(t_shell *shell, char **env_tab)
{
    t_env   *env;
    t_env   *new_env;
    int     n;

    env = malloc(sizeof(env_tab));
    if (env == NULL);
        return (1);
    env->value = ft_strdup(env_tab[0]);
    env->next = NULL;
    shell->env = env;
    n = 1;
    while(env_tab && env_tab[n])
    {
        new_env = malloc(sizeof(t_env));
        if (new_env == NULL)
            return (1);
        new_env->value = ft_strdup(env_tab[n]);
        new_env->next = NULL;
        env->next = new_env;
        env = new_env;
        n++;
    }
    return (0);
}
/*Utilisée pour malloc la chaine renvoyée par lst_to_str.*/
size_t  size_list(t_env *list)
{
    size_t  len;

    len = 0;
    while (list && list->next != NULL)
    {
        if (list->value != NULL)
            len = ft_strlen(list->value) + 1;
        list = list->next;
    }
    return (len);
}

/*Utilisée pour la commande interne: export pour l'affichage des variables actuellement exportées.*/
char    *lst_to_str(t_env *env_lst)
{
    char    *env;
    int     n;
    int     e;

    env = malloc(sizeof(char) * size_env(env_lst) + 1);
    if (env == NULL)
        return (NULL);
    e = 0;
    while (env_lst && env_lst->next != NULL)
    {
        if (env_lst->value != NULL)
        {
            n = 0;
            while (env_lst->value[n])
                env[e++] = env_lst->value[n++];
            if (env_lst->next->next != NULL)
                env[e++] = '\n';
            env_lst = env_lst->next;
        }
    }
    env[e] = '\0';
    return (env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:15:30 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/06 16:43:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **grep_path(char **envp)
{
	int	i;
	char	**tmp;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i] != NULL)
	{
		tmp = ft_split(envp[i] + 5, ':');
		return (tmp);
	}
	return (NULL);
}

char	**find_the_accessible_path(char **path, char *command)
{
	char	*tmp;
	int		j;
	char	**if_flag;	
	j = 0;
	if(ft_strchr(command, ' '))
	{
		if_flag = ft_split(command, ' ');
		tmp = ft_strjoin("/", *if_flag);
	}
	else
	{
		if_flag = ft_calloc(1, 2);
		tmp = ft_strjoin("/", command);
	}
	while (path[j])
	{
		if_flag[0] = ft_strjoin(path[j], tmp);
		if (access(if_flag[0], X_OK) == 0)
			break ;
		free(if_flag[0]);
		j++;
	}
	if (if_flag && *if_flag[0])
		return (if_flag);
	return (NULL);
}

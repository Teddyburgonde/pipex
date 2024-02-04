/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:21:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/04 18:18:17 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, t_vars *vars)
{
	int	i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i] != NULL)
	{
		vars->paths = ft_split(envp[i] + 5, ':');
		return (envp[i] + 5);
	}
	return (NULL);
}

char	*find_the_accessible_path(char **paths, char *command_type)
{
	char	*tmp;
	char	*right_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		right_path = ft_strjoin(tmp, command_type);
		free(tmp);
		if (access(right_path, F_OK) == 0)
			return (right_path);
		//free(command_type);
		i++;
	}
	return (NULL);
}

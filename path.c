/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:15:30 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 02:55:19 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**grep_path(char **envp)
{
	char	**tmp;
	int		i;

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
	int		i;
	char	**full_cmd;
	char	*is_valid_cmd;
	char	*bin_path;
	size_t	arr_len;
	
	i = 0;
	
	full_cmd = ft_split(command, ' ');
	if (full_cmd == NULL)
	{
		ft_free(full_cmd);
		return (NULL);
	}
	arr_len = ft_array_len(full_cmd);
	if (access(full_cmd[0], X_OK) == 0)
		return (full_cmd);
	while (path[i])
	{
		bin_path = ft_strjoin(path[i++], "/");
		is_valid_cmd = ft_strjoin(bin_path, full_cmd[0]);
		free(bin_path);
		if (access(is_valid_cmd, X_OK) == 0)
		{
			free(full_cmd[0]);
			full_cmd[0] = NULL;
			full_cmd[0] = malloc(ft_strlen(is_valid_cmd) + 1);
			ft_strlcpy(full_cmd[0], is_valid_cmd, ft_strlen(is_valid_cmd) + 1);
			break ;
		}
		// test 
		free(is_valid_cmd);
	}
	free(is_valid_cmd);
	// test
	return (full_cmd);
}

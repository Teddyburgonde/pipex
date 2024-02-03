/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:21:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 02:08:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_access(char *path, char **arg_cmd, int cmd)
{
	if (access(path, X_OK) == 0)
	{
		if (cmd == 1)
			arg_cmd[0] = path;
		else if (cmd == 2)
			arg_cmd[0] = path;
		return ;
	}
}

void	accessible_path(char *argv, t_vars *vars, int cmd)
{
	int		i;

	vars->tab = ft_split(argv, ' ');
	i = 0;
	if (!vars->tab)
		return ;
	check_access(vars->tab[0], vars->arg_cmd1, cmd);
	while (vars->paths[i])
	{
		vars->tmp = ft_strjoin(vars->paths[i], "/");
		vars->new_tab = ft_strjoin(vars->tmp, vars->tab[0]);
		if (access(vars->new_tab, X_OK) == 0)
		{
			if (cmd == 1)
				vars->arg_cmd1[0] = vars->new_tab;
			if (cmd == 2)
				vars->arg_cmd2[0] = vars->new_tab;
			free(vars->tmp);
			break ;
		}
		free(vars->tmp);
		free(vars->new_tab);
		i++;
	}
	ft_free(vars->tab);
}

char	*find_path(char **envp, t_vars *vars)
{
	int	j;

	j = 0;
	while (envp[j])
	{
		if (envp[j][0] == 'P' && envp[j][3] == 'H')
			vars->paths = ft_split(&envp[j][5], ':');
		j++;
	}
	return (NULL);
}

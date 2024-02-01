/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/01 16:27:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	child_process(t_vars *vars, char **envp)
{
	vars->fd_child = open(vars->file1, O_RDONLY);
	if (vars->fd_child == -1)
		exit(1);
	dup2(vars->fd_child, 0);
	dup2(vars->pipe[1], 1);
	if (execve(vars->arg_cmd1[0], vars->arg_cmd1, envp) == -1)
	{
		ft_printf("Error\n");
		ft_free(vars->arg_cmd1);
		ft_free(vars->arg_cmd2);
		free(vars);
		exit(1);
	}
	close(vars->pipe[0]);
	close(vars->pipe[1]);
	close(vars->fd_child);
}

void	parent_process(t_vars *vars, char **envp)
{
	wait(NULL);
	vars->fd_parent = open(vars->file2, O_RDONLY);
	if (vars->fd_parent == -1)
		exit(1);
	dup2(vars->fd_parent, 0);
	dup2(vars->pipe[1], 1);
	if (execve(vars->arg_cmd2[0], vars->arg_cmd2, envp) == -1)
	{
		ft_printf('Error\n');
		ft_free(vars->arg_cmd1);
		ft_free(vars->arg_cmd2);
		free(vars);
		exit(1);
	}
	close(vars->fd_parent);
	close(vars->pipe[0]);
	close(vars->pipe[1]);
}

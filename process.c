/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/02 15:07:52 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_vars *vars, char **envp)
{
	dup2(vars->pipe[1], 1);
	close(vars->pipe[0]);
	close(vars->pipe[1]);
	dup2(vars->fd_child, 0);
	close(vars->fd_child);
	execve(vars->arg_cmd1[0], vars->arg_cmd1, envp);
	perror("Error\n");
	exit(1);
}

void	parent_process(t_vars *vars, char **envp)
{
	wait(NULL);
	vars->fd_parent = open(vars->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if (vars->fd_parent == -1)
	{
		perror("Error opening file\n");
		exit(1);
	}
	dup2(vars->pipe[1], 1);
	close(vars->pipe[0]);
	close(vars->pipe[1]);
	dup2(vars->fd_parent, 0);
	close(vars->fd_parent);
	execve(vars->arg_cmd2[0], vars->arg_cmd2, envp);
	perror("Error\n");
	ft_free(vars->arg_cmd1);
	ft_free(vars->arg_cmd2);
	free(vars);
	exit(1);
}

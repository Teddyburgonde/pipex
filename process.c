/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 05:07:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_vars *vars)
{
	close(vars->pipe[0]);
	close(vars->pipe[1]);
}

void	child_process(t_vars *vars, char **envp)
{
	dup2(vars->pipe[1], 1);
	close(vars->pipe[1]);
	close(vars->pipe[0]);
	dup2(vars->fd_child, 0);
	close(vars->fd_child);
	execve(vars->arg_cmd1[0], vars->arg_cmd1, envp);
	perror("Error\n");
	ft_free(vars->arg_cmd1);
	ft_free(vars->arg_cmd2);
	free(vars);
	exit(1);
}

void	parent_process(t_vars *vars, char **envp)
{
	vars->fd_parent = open(vars->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (vars->fd_parent == -1)
		exit(1);
	vars->pid = fork();
	if (vars->pid == 0)
	{
		dup2(vars->pipe[0], STDIN_FILENO);
		dup2(vars->fd_parent, STDOUT_FILENO);
		execve(vars->arg_cmd2[0], vars->arg_cmd2, envp);
		perror("Error\n");
		ft_free(vars->arg_cmd1);
		ft_free(vars->arg_cmd2);
		free(vars);
		exit(1);
	}
	else
	{
		wait(NULL);
		close_pipes(vars);
		close(vars->fd_parent);
		close(vars->fd_child);
	}
	ft_printf("%s\n%s\n", vars->arg_cmd1[0], vars->arg_cmd2[1]);
	ft_free(vars->arg_cmd1);
	ft_free(vars->arg_cmd2);
	exit(0);
}

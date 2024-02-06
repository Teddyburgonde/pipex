/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:53:12 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/06 17:56:01 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_vars *vars, char *envp[])
{
	close(vars->pipe[0]);
	close(vars->fd_outfile);
	dup2(vars->fd_infile, STDIN_FILENO);
	dup2(vars->pipe[1], STDOUT_FILENO);
	execve(vars->final_path1[0], vars->final_path1, envp);
	ft_putstr_fd("Error child\n", 2);
}

void	parent_process(t_vars *vars, char *envp[])
{
	close (vars->pipe[1]);
	wait(NULL);
	dup2(vars->pipe[0], STDIN_FILENO);
	close (vars->pipe[0]);
	dup2(vars->fd_outfile, STDOUT_FILENO);
	close (vars->fd_outfile);
	execve(vars->final_path2[0], vars->final_path2, envp);
	ft_putstr_fd("Error parent\n", 2);
}

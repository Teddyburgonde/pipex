/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:53:12 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 02:51:13 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Trouver un moyen de regrouper child process et second child process en une fonction
void	child_process(t_vars *vars, char *envp[])
{
	close(vars->pipe[0]);
	close(vars->fd_outfile);
	dup2(vars->fd_infile, STDIN_FILENO);
	dup2(vars->pipe[1], STDOUT_FILENO);
	execve(vars->final_path1[0], vars->final_path1, envp);
	perror("Execve");
	ft_free(vars->final_path1);
	exit(1); 
}

void	second_child_process(t_vars *vars, char *envp[])
{
	close (vars->pipe[1]);
	dup2(vars->pipe[0], STDIN_FILENO);
	close (vars->pipe[0]);
	dup2(vars->fd_outfile, STDOUT_FILENO);
	close (vars->fd_outfile);
	execve(vars->final_path2[0], vars->final_path2, envp);
	perror("Execve");
	ft_free(vars->final_path2);
	exit(1);
}

void	parent_process(t_vars *vars, char *envp[])
{
	vars->pid2 = fork();
	if (vars->pid2 == -1)
	{
		//Free
		exit(1);
	}
	if (vars->pid2 == 0)
		second_child_process(vars, envp);
	else
	{
		close(vars->fd_infile);
    	close(vars->fd_outfile);
		close (vars->pipe[1]);
		close (vars->pipe[0]);
		while (waitpid(-1, NULL, 0) != -1)
			continue ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/04 19:32:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}

void	child_process(t_vars *vars, char **envp, char *argv[], bool first_command)
{
	//Redirection
	if (first_command){
		dup2(vars->pipe[1], STDOUT_FILENO);
		dup2(vars->fd_infile, STDIN_FILENO);
	}
	else{
		dup2(vars->pipe[0], STDIN_FILENO);
		dup2(vars->fd_outfile, STDOUT_FILENO);
	}

	close(vars->fd_infile);
	close(vars->fd_outfile);
	close_pipes(vars->pipe);

	//Execution
	vars->starting_argument = ft_split(argv[2], ' ');
	vars->valid_command = find_the_accessible_path(vars->paths,
			vars->starting_argument[0]);
	if (!vars->valid_command)
	{
		perror("Error in parent_process: Command not found\n");
		free(vars->valid_command);
		exit(1);
	}
	execve(vars->valid_command, vars->starting_argument, envp);
	perror("Error\n");
	//free si execve foire
	exit(1);
}

void	parent_process(t_vars *vars,  bool last_command)
{
	if (last_command){
		close_pipes(vars->pipe);
		close(vars->fd_infile);
		close(vars->fd_outfile);
		//free le reste du programme
	};
}

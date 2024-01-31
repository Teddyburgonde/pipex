/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/31 23:19:52 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	child_process(t_vars *vars)
{
	close(vars->pipe[0]);
	vars->fd_child = open(vars->file1, O_RDONLY);
	if (vars->fd_child == -1)
		exit(1);
	dup2(vars->pipe[1], 1);
	dup2(vars->fd_child, 1);
	
	

	
	//execve(vars->arg_cmd1[0], vars->arg_cmd2, NULL);
}

void	parent_process(t_vars *vars)
{
	wait(NULL);
	dup2(vars->fd1[1], 0);
	close(vars->pipe[1]);
	execve(vars->arg_cmd1[0], vars->arg_cmd2, NULL);
}


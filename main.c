/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/06 16:41:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	// ./pipex infile cmd1 cmd2 outile 
	//   0        1     2   3    4
 	t_vars vars;
	// create a pipe 
	if (pipe(vars.pipe) == -1)
		return (-1);
	// open infile and outfile
	ft_parsing(argc, argv, &vars);
	vars.infile = argv[1];
	vars.outfile = argv[4];
	vars.fd_infile = open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//parsing 
	vars.paths = grep_path(envp);
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		exit(1);
	if (vars.pid1 == 0)
		child_process(&vars, envp);
	else
		parent_process(&vars, envp);
}



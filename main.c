/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 02:49:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	
	if (argc != 5)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	if (pipe(vars.pipe) == -1)
		return (-1);
	vars.infile = argv[1];
	vars.outfile = argv[4];
	//Mettre dans une fonction a part
	vars.fd_infile = open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_parsing(argv, &vars);
	vars.paths = grep_path(envp);
	if (vars.paths == NULL)
	{
		ft_free(vars.paths);
		exit(1);
	}
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	if (vars.final_path1 == NULL)
	{
		ft_free(vars.final_path1);
		exit(1);
	}
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	if (vars.final_path2 == NULL)
	{
		ft_free(vars.final_path2);
		exit(1);
	}
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		exit (1);
	if (vars.pid1 == 0){
		child_process(&vars, envp);
	}
	else
		parent_process(&vars, envp);
	ft_free(vars.paths);
    ft_free(vars.final_path1);
    ft_free(vars.final_path2);
}

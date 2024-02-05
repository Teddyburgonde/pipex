/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/05 19:14:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

#include <stdio.h>

// char	*find_the_accessible_path(char **path, char *command)
// {
// 	char	*right_path;
// 	char	*tmp;
// 	int	j;
	
// 	j = 0;
// 	while (path[j])
// 	{
// 		tmp = ft_strjoin(path[j], "/");
// 		right_path = ft_strjoin(tmp, command);
// 		free(tmp);
// 		if (access(right_path, F_OK) == 0)
// 			return (right_path);
// 		//free command ???
// 		j++;
// 	}
// 	return (NULL);
// }

char	*find_the_accessible_path(char **path, char *command)
{
	char	*right_path;
	char	*tmp;
	int		j;
	
	j = 0;
	tmp = ft_strjoin("/", command);
	while (path[j])
	{
		right_path = ft_strjoin(path[j], tmp);
		if (access(right_path, X_OK) == 0)
			ft_printf("JAI ACCESS\n");
		else
			ft_printf("NON!\n");
		free(right_path);
		//return (right_path);
		//free command ???
		j++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	t_vars vars;
	// create a pipe 
	pipe(vars.pipe);
	
	// open infile and outfile
	vars.fd_infile = open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY, O_CREAT, O_TRUNC, 0644);
	
	//parsing 
	ft_parsing(argc, argv, &vars);
	vars.paths = grep_path(envp);
	find_the_accessible_path(vars.paths, argv[2]);
	// /nfs/homes/tebandam/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
		
	// /nfs/homes/tebandam/bin...etc
	// ft_printf("%s\n", vars.path[i]);

	//find_the_accessible_path(vars.path, argv[2]);
}



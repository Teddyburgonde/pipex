/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: te2bandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*   By: te2bandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/04 19:52:03 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "pipex.h"

static void	ft_parsing(int argc, char **argv, t_vars *vars)
{
	if (argc != 5)
		message_wrong_number_of_arguments();
	if (vars->fd_infile == -1 || vars->fd_outfile == -1)
		message_file_descriptor_error();
	if (access(argv[1], F_OK) == -1)
		message_not_permissions();
}


// POUR LES BONUS 

// int run_sub_process(char **argv, char**envp, int fd_in, int fd_out) {
// 	int pid = fork();
// 	if (pid == 0) { // child process
// 		dup2(fd_in, 0);
// 		dup2(fd_out, 1);
// 		close(fd_in);
// 		close(fd_out);
// 		execve(argv, envp);
// 		return (-1);
// 	}
// 	return pid;
// }

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;

	// POUR LES BONUS 

	//convertion des arguments 
	
	//a faire struct commande executable arguments entrer sorti
	// iterer sur le tableau de commande 
	
	// t_command commands[] = {};

	// t_command command_actuelle = commands[0];

	// int child_input = infile;
	// int child_output = -1;
	// int fds[2];

	// while (command_actuelle) {
	// 	if (je suis pas la derniere commande) {
	// 		pipe(fds);
	// 		child_output = fds[1];
	// 	} else {
	// 		child_output =  outfile
	// 	}


	// 	int pid = fork();
	// 	if (pid == 0) { // child
	// 		run_subprocess(command, envp, child_input, child_output);
	// 	}

	// 	close(child_input);
	// 	close(child_output);

	// 	child_input = fds[0];

	// 	return 0;
	// }
	vars.infile = argv[1];
	vars.outfile = argv[4];
	pipe(vars.pipe);
	vars.fd_infile= open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_parsing(argc, argv, &vars);
	vars.arg_cmd = find_path(envp, &vars);
	//first command
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		perror("Error\npid1");
	if (vars.pid1 == 0)
		child_process(&vars, envp, argv, true);
	else
		parent_process(&vars, false);
	//last command
	vars.pid2 = fork();
	if (vars.pid2 == -1)
		perror("Error\npid2");
	if (vars.pid2 == 0){
		child_process(&vars, envp, argv, false);
	}
	else
		parent_process(&vars, true);
	waitpid(vars.pid1, NULL, 0);
	waitpid(vars.pid2, NULL, 0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/04 19:47:25 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_vars{
	pid_t	pid1;
	pid_t	pid2;
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	int		pipe[2];
	char	*arg_cmd;
	char	*valid_command;
	char	**starting_argument;
	char	**paths;
}	t_vars;

char	*find_path(char **envp, t_vars *vars);
void	child_process(t_vars *vars, char **envp, char *argv[], bool first_command);
void	parent_process(t_vars *vars, bool last_command);
char	*find_the_accessible_path(char **paths, char *command_type);
void	close_pipes(int pipe[2]);
void	message_file_descriptor_error(void);
void	message_wrong_number_of_arguments(void);
void	message_not_permissions(void);

#endif
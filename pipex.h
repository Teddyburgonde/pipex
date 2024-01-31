/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/31 20:04:42 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_vars{
	pid_t	pid;
	char	**arg_cmd1;
	char	**arg_cmd2;

	char	**paths;
	char	*path_cmd1;
	char	*path_cmd2;
	int		pipe[2];
	int		fd1[2];
}t_vars;

void	message_wrong_number_of_arguments(void);
void	message_not_permissions(void);
void	message_pipe_error(void);
char	*find_path(char **envp, t_vars *vars);
void 	init_arg_cmd1(t_vars *vars, char **argv);
void 	init_arg_cmd2(t_vars *vars, char **argv);
void	child_process(t_vars *vars);
void	parent_process(t_vars *vars);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 04:10:24 by tebandam         ###   ########.fr       */
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

typedef struct s_vars{
	pid_t	pid;
	int		fd_child;
	int		fd_parent;
	int		pipe[2];
	char	*path_cmd1;
	char	*path_cmd2;
	char	**arg_cmd1;
	char	**arg_cmd2;
	char	*file1;
	char	*file2;
	char	**paths;
	char	**tab;
	char	*tmp;
	char	*new_tab;
}t_vars;

void	message_wrong_number_of_arguments(void);
void	message_not_permissions(void);
void	message_pipe_error(void);
char	*find_path(char **envp, t_vars *vars);
void	init_arg_cmd1(t_vars *vars, char **argv);
void	init_arg_cmd2(t_vars *vars, char **argv);
void	child_process(t_vars *vars, char **envp);
void	parent_process(t_vars *vars, char **envp);
void	close_pipes(t_vars *vars);
void	accessible_path(char *argv, t_vars *vars, int cmd);
void	check_access(char *path, char **arg_cmd, int cmd);

#endif
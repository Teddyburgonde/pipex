/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:36:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/07 11:01:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_vars{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	char	**paths;
	char	*path;
	char	**final_path1;
	char	**final_path2;
}t_vars;

void	ft_parsing(int argc, char **argv, t_vars *vars);
char	**grep_path(char **envp);
char	**find_the_accessible_path(char **path, char *command);
void	child_process(t_vars *vars);
void	second_child_process(t_vars *vars);
void	parent_process(t_vars *vars);

#endif
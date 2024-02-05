/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:36:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/05 19:14:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_vars{

	int		pipe[2];
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	char	**paths;
	char	*path;
	
}t_vars;


void	ft_parsing(int argc, char **argv, t_vars *vars);
char	**grep_path(char **envp);
# endif
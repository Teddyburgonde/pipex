/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/28 15:08:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H



#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_vars{
	
	char	**arg_cmd1;
	char	**arg_cmd2;

	char	*path_cmd1;
	char	*path_cmd2;
}t_vars;

void	message_wrong_number_of_arguments(void);
void	message_not_permissions(void);

#endif
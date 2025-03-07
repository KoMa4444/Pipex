/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:04:42 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/07 17:37:43 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/wait.h>
# include <string.h>

//error handle
int		input_errors(int argc, char **argv);

//main functions
char	*find_path(char **envp, char *command);

//matrix management
void	free_matrix(char **matrix);
void	add_to_matrix(char **matrix, char *add);
void	ft_print_matrix(char **matrix);

#endif
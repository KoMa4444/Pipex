/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:22:54 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/14 18:22:57 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_matrix(char **matrix)
{
	int i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}


void	add_to_matrix(char **matrix, char *add)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	matrix[i] = add;
	matrix[i+1] = (char *)ft_calloc(1, sizeof(char));
	matrix[i+1] = NULL;
}

void	ft_print_matrix(char **matrix)
{
	int i;

	if (!matrix || !(*matrix))
		return ;
	i = -1;
	while (matrix[++i])
		ft_printf("\033[29m%s\n", matrix[i]);
}

int	ft_matrix_len(char **matrix)
{
	int i;

	if (!matrix || !(*matrix))
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

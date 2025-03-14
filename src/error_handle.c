/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:04:26 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/14 18:50:17 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	input_errors(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Please follow the format:");
		ft_printf(" <srcfile> <cmd1> <cmd2> <dstfile>\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) == 1)
	{
		perror("\033[31mERROR: No src file");
		return (0);
	}
	return (1);
}

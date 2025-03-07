/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:04:26 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/07 19:42:27 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	input_errors(int argc, char **argv)
{
	int	test_fd;

	test_fd = open(argv[1], O_RDONLY);
	if (argc != 5)
	{
		ft_printf("Please follow the format:");
		ft_printf(" <srcfile> <cmd1> <cmd2> <dstfile>\n");
		exit(EXIT_FAILURE);
	}
	if (test_fd == -1)
	{
		close(test_fd);
		perror("\033[31mERROR: No src file");
		return (0);
	}
	close(test_fd);
	return (1);
}

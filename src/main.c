/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:22:42 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/27 17:46:47 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	id0;
	int	chk;
	int	status;

	status = 0;
	chk = input_errors(argc, argv);
	if (pipe(fd) == -1)
		return (2);
	id0 = fork();
	if (id0 == -1)
		return (3);
	if (id0 == 0 && chk == 1)
		cmd1(argv, envp, fd);
	else
	{
		id0 = fork();
		if (id0 == 0)
			cmd2(argv, envp, fd);
		close (fd[0]);
		close (fd[1]);
		waitpid(id0, &status, 0);
	}
	wait(&chk);
	return (WEXITSTATUS(status));
}

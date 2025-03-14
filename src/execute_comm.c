/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_comm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:47:24 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/14 18:48:12 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	execute(char **command, char **envp, int fd)
{
	char	*cmd;

	cmd = ft_badstrjoin("/", command[0]);
	if (access(command[0], X_OK) == 0)
		cmd = command[0];
	else
		cmd = find_path(envp, cmd);
	if (cmd == NULL || execve(cmd, command, envp) == -1)
	{
		perror("execve");
		free_matrix(command);
		free(cmd);
		close(fd);
		exit(127);
	}
	free_matrix(command);
	free(cmd);
	close(fd);
}

char	**get_cmd(char *arg)
{
	char	**cmd_flags;

	if (*arg == '\0')
		exit(9);
	cmd_flags = ft_split(arg, ' ');
	return cmd_flags;
}

void	cmd1(char **argv, char **envp, int fd[2])
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	close(file);
	if (argv[3] == NULL)
		exit(8);
	execute(get_cmd(argv[2]), envp, fd[1]);
}

void cmd2(char **argv, char **envp, int fd[2])
{
	int file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	close(file);
	if (argv[3] == NULL)
		exit(9);
	execute(get_cmd(argv[3]), envp, fd[0]);
}

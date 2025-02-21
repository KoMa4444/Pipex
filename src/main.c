#include "../inc/pipex.h"

void execute(char **command, char **envp)
{
	pid_t pid;
	int status;
	char *cmd;

	ft_print_matrix(command);
	cmd = ft_badstrjoin("/usr/bin/", command[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(cmd, command, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		if (wait(&status) == -1)
			exit(EXIT_FAILURE);
	free(cmd);
	free_matrix(command);
}

char	**get_cmd(char *arg)
{
	char **cmd_flags;
	
	cmd_flags = ft_split(arg, ' ');
	return cmd_flags;
}

void	cmd1(char **argv, char **envp, int fd[2])
{
	int file;
	
	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(fd[0], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[1]);
	execute(get_cmd(argv[2]), envp);
}

void cmd2(char **argv, char **envp, int fd[2])
{
	int file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(fd[1], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	execute(get_cmd(argv[3]), envp);
}

int	main(int argc, char **argv, char **envp)
{
	int fd[2];
	int id;

	if (input_errors(argc, argv) == 0)
		return (1);
	if (pipe(fd) == -1)
		return (2);
	id = fork();
	if (id == -1)
		return (3);
	if (id == 0)
		cmd1(argv, envp, fd);
	else
	{
		waitpid(id, NULL, 0);
		cmd2(argv, envp, fd);
	}
	return (0);
}

#include "../inc/pipex.h"

char	*find_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 1)
		{
			path = ft_split(envp[i], ':');
			ft_print_matrix(path);
			return (path[0]);
		}
		i++;
	}
	exit(5);
}

void	execute(char **command, char **envp)
{
	char	*cmd;

	cmd = ft_badstrjoin(find_path(envp), command[0]);
	if (execve(cmd, command, envp) == -1)
	{
		perror("execve");
		free_matrix(command);
		free(cmd);
		exit(4);
	}
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
	
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	execute(get_cmd(argv[2]), envp);
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
	execute(get_cmd(argv[3]), envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	id0;
	int	id1;
	int	chk;
	int	status;

	ft_print_matrix(envp);
	ft_putstr_fd(find_path(envp), 1);
	status = 0;
	id1 = 0;
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
		id1 = fork();
		if (id1 == 0)
			cmd2(argv, envp, fd);
		close (fd[0]);
		close (fd[1]);
		waitpid(id1, &status, 0);
	}

	return (WEXITSTATUS(status));
}

#include "../inc/pipex.h"

char *get_src_file(char *filename)
{
    char *file;
    char *txt;
    int fd;
    
    fd = open(filename, O_RDONLY);
    txt = get_next_line(fd);
    if (!txt)
        return (0);
    file = (char *)ft_calloc(1, sizeof(char));
    if (!file)
        return (0);
    while (txt != 0)
    {
        file = ft_strjoin(file, txt);
        free(txt);
        txt = get_next_line(fd);
    }
    return (file);
}

void execute_command(char **command, char *file)
{
    pid_t pid;
    int status;
    char *cmd;

    cmd = ft_strjoin("/bin/", command[0]);
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execve(cmd, command, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

char **get_cmd(char *arg)
{
    char **cmd_flags;

    cmd_flags = ft_split(arg, ' ');
    return cmd_flags;
}

int main(int argc, char **argv)
{
    char *file;

    if (input_errors(argc, argv) == 0)
        return (0);

    file = get_src_file(argv[1]);
    ft_printf("\n%s\n", file);
    free(file);
    int j = 0;
    char **matrix = get_cmd(argv[2]);
    while(matrix[j])
    {
        ft_putstr_fd(matrix[j], 1);
        j++;
    }
    return (0);
}

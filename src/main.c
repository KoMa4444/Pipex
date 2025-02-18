#include "../inc/pipex.h"

char **get_cmd(int argc, char argv)
{
    static char *prefix = "/bin/";
    char **command_list;
    int cmd_len;
    int i;
    
    i = 1
    while(++i < argc-1)
    {
        cmd_len = ft_strlen(prefix) + ft_strlen(argv[i]);
        
    }
}

int main(int argc, char **argv)
{
    if (input_errors(argc, argv) == 0)
        return (0);
    return (0);
    command_list 
}
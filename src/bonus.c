#include "../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc > 1 || argv[1])
		return (printf("too many arguments\n") * 0 + 1);
	execve("/bin/bash", NULL, env);
	return (0);
}

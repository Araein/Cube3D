

/*
Write a program that will behave like executing a shell command

    The command line to execute will be the arguments of this program

    Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)

    You must implement "|" and ";" like in bash
        we will never try a "|" immediately followed or preceded by nothing or "|" or ";"

    Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
        if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
        if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' 
        with path_to_change replaced by the argument to cd
        a cd command will never be immediately followed or preceded by a "|"

    You don't need to manage any type of wildcards (*, ~ etc...)

    You don't need to manage environment variables ($BLA ...)

    If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in 
    STDERR followed by a '\n' and the program should exit

    If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n'
    with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)

    Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

*/

/*malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp*/


#include "microshell.h"


#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

// #ifdef TEST_SH
// # define TEST		1
// #else
// # define TEST		0
// #endif

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char const *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void *exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
    
	return (NULL);
}

char *ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (!(copy = (char*)malloc(sizeof(*copy) * (ft_strlen(str) + 1))))
		return (exit_fatal_ptr());
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int add_arg(t_list *cmd, char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
    //nouveau tableau de taille nombre d'arg deja ajoute + 1 (actuel) + 1 pour NULL
	if (!(tmp = (char**)malloc(sizeof(*tmp) * (cmd->length + 2))))
		return (exit_fatal());

    //on recup les args deja ajoutes
	while (i < cmd->length)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
    //si yavait deja eu une commande avant -> on free l'ancien tableau et on remplace par le nouveau
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = tmp;

    //on ajoute le nouvel arg malloc
	cmd->args[i++] = ft_strdup(arg);

    //on finit bien par NULL
	cmd->args[i] = 0;

    //incremente le nombre d'arg
	cmd->length++;
	return (EXIT_SUCCESS);
}

int list_push(t_list **list, char *arg)
{
	t_list	*new;

    // on cree une nouvelle liste

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (exit_fatal());

    //init tout a zero

	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->previous = NULL;
	new->next = NULL;

    //on ajoute la nouvelle liste au sein du tableau de liste et on la met en liste actuelle
	if (*list)
	{
		(*list)->next = new;
		new->previous = *list;
	}
	*list = new;
    //on ajoute un argument
	return (add_arg(new, arg));
}

int list_rewind(t_list **list)
{
	while (*list && (*list)->previous)
		*list = (*list)->previous;
	return (EXIT_SUCCESS);
}

int list_clear(t_list **cmds)
{
	t_list	*tmp;
	int		i;

	list_rewind(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->length)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
	return (EXIT_SUCCESS);
}

int parse_arg(t_list **cmds, char *arg)
{

	int	is_break;

	is_break = (strcmp(";", arg) == 0);

    //si commence par ;
	if (is_break && !*cmds)
		return (EXIT_SUCCESS);

    // si argv normal et que liste commence ou que on est juste apres un | ou un ;     (-> du coup forcement du txt)
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return (list_push(cmds, arg));

    //si | juste prevenir qu'on a un pipe pour le prochain
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;

    //si ; juste prevenir qu'on a un ; pour le prochain
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
    // si ni | ni ; ni premier arg -> on ajoute un arg a la suite
	else
		return (add_arg(*cmds, arg));
	return (EXIT_SUCCESS);
}


int exec_cmd(t_list *cmd, char **env)
{



    pid_t pid
    int     pipeopen;

    pipeopoen = 0;


    if (cmd->type == 1 || cmd->prev->type  == 1)
    {
        pipeopen = 1;
        pipe(cmd->fd);
        //error
    }
    pid = fork()
    //erreur
    if (pid == 0)
    {
        if (cmd->type == 1 && dup2(cmd->fd[1], STDOUT) > 0)
            //ereur
        if (cmd->prev && cmd->prev->type == 1 && dup2(cmd->fd[0], STDin) > 0)
            //erreur
        execve(cmd[0], cmd, env)
        {
            //erreur
        }
    }
    else
    {
        waitpid(pid, &error, NULL);

        if ()

    }


























	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;

    //si il y a un pipe avant ou apres la commande actuelle
	if (cmd->type == TYPE_PIPE || (cmd->previous && cmd->previous->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0)
	{

		if (cmd->type == TYPE_PIPE && dup2(cmd->pipes[STDOUT], STDOUT) < 0)
			return (exit_fatal());
		if (cmd->previous && cmd->previous->type == TYPE_PIPE && dup2(cmd->previous->pipes[STDIN], STDIN) < 0)
			return (exit_fatal());



		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[STDOUT]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[STDIN]);
		}
		if (cmd->previous && cmd->previous->type == TYPE_PIPE)
			close(cmd->previous->pipes[STDIN]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int exec_cmds(t_list **cmds, char **env)
{
	t_list	*crt;
	int		ret;

	ret = EXIT_SUCCESS;
    // on retourne au debut de la liste

	list_rewind(cmds);


//  on fait toutes les commandes dans l'ordre
	while (*cmds)
	{
		crt = *cmds;

        // on fait le built in cd a chaque fois
		if (strcmp("cd", crt->args[0]) == 0)
		{
			ret = EXIT_SUCCESS;
			if (crt->length < 2)
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				ret = show_error("error: cd: cannot change directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else //sinon bon chance
			ret = exec_cmd(crt, env);
        
        //on passe a la commande suivante
		if (!(*cmds)->next)
			break ;
		*cmds = (*cmds)->next;
	}
	return (ret);
}


int main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);

    //a ce stade on a cmds -> liste chainee -> chaque maillon c'est une commande qui contient les args[][]
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(&cmds); //free toutes les structures +  a chaque fois les args [][]
	// if (TEST)
	// 	while (1);
	return (ret);
}


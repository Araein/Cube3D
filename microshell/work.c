#define STDIN 0
#define STDOUT 1
#define STDERR 2



typedef struct s_list
{
    int     type;
    int     length;
    char    **args;
    int     pipe[2];
    struct s_list *next;
    struct s_list *prev;
} t_list;



int parsing(t_list **list, char **argv)
{


}

int main(int argc, char **argv, char **env)
{
    t_list  *list;
    int     i;

    i = 0;
    list = NULL;

    if (argc == 0)
        return (0);
    while(i < argc)
    {
        parsing(&list, argv)
        i++;
    }
    //parsing
    //execution
    //free and close all



}

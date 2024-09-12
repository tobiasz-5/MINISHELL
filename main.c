#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_sigint(int sig)
{
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void handle_sigquit(int sig)
{
    //ignora il segnale
}

int     main()
{
    char    *input;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, handle_sigquit);
    while (1)
    {
        input = readline("MINIPROMPT> ");
        if (!input)
        {
            printf("\nExit From The Shell\n");
            break;
        }
        if (*input == '\0')
            free(input);
        else
        {
            add_history(input);
            free(input);
        }
    }
    rl_clear_history();
    return(0);
}

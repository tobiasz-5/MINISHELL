#include "miniheader.h"

void add_token_to_list(t_token_node **head, t_token_node **tail, char *token_str)
{
    t_token_node *new_node = create_token_node(token_str);
    if (new_node)
    {
        add_token_node(head, tail, new_node);
    }
}

void add_token_node(t_token_node **head, t_token_node **tail, t_token_node *new_node)
{
    if (!*head)                     // Se la lista è vuota (head == NULL)
        *head = new_node;           // Il nuovo nodo diventa la testa
    else
        (*tail)->next = new_node;   // Altrimenti collega l'ultimo nodo della lista al nuovo nodo
    *tail = new_node;               // Aggiorna il puntatore tail per farlo puntare al nuovo ultimo nodo
}


int append_to_temp_token_str(t_token_state *state, char *temp_token)
{
    char *new_str;

    new_str = ft_strjoin(state->token_str, temp_token);
    free(state->token_str);
    if (!new_str)
        return -1;
    state->token_str = new_str;
    return 0;
}
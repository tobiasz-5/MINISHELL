/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:03:01 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:22:05 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

// gestisce il segnale SIGINT (Ctrl+C)
void	handle_sigint(int sig)
{
	(void)sig; // Disabilita il warning "unused parameter"
	write(STDOUT_FILENO, "\n", 1); // Sposta il cursore a capo
	rl_on_new_line(); // Notifica a readline che si è in una nuova riga
	rl_replace_line("", 0); // Sostituisce linea (ex dekjfke^C) con una vuota.
	rl_redisplay(); // Ridisegna il prompt
}

// gestisce il segnale SIGQUIT (Ctrl+\)
void	handle_sigquit(int sig)
{
	(void)sig;
}

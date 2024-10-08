/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:09:38 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 13:51:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

/* non si puo usare switch, va cambiato con if else if */

const char	*token_type_to_string(t_token_type type)
{
	switch (type)
	{
	case TOKEN_PIPE: //	  |
	return ("PIPE");
	case TOKEN_REDIR_APPEND: //	  >>
	return ("REDIRECT_APPEND");
	case TOKEN_HEREDOC: //	  <<
	return ("HEREDOC");
	case TOKEN_REDIR_IN: //	  <
	return ("REDIRECT_IN");
	case TOKEN_REDIR_OUT: //	  >
	return ("REDIRECT_OUT");
	case TOKEN_SINGLE_QUOTE: //	  '
	return ("SINGLE_QUOTE");
	case TOKEN_DOUBLE_QUOTE: //	  "
	return ("DOUBLE_QUOTE");
	case TOKEN_DOLLAR: //	  $
	return ("DOLLAR");
	case TOKEN_WORD: //	  ls, wc, cat, etc.
	return ("WORD");
	default :
	return ("UNKNOWN");
	}
}

t_token_type	determine_token_type(char *token_str)
{
	if (ft_strcmp(token_str, "|") == 0)
		return (TOKEN_PIPE);
	else if (ft_strcmp(token_str, ">>") == 0)
		return (TOKEN_REDIR_APPEND);
	else if (ft_strcmp(token_str, "<<") == 0)
		return (TOKEN_HEREDOC);
	else if (ft_strcmp(token_str, "<") == 0)
		return (TOKEN_REDIR_IN);
	else if (ft_strcmp(token_str, ">") == 0)
		return (TOKEN_REDIR_OUT);
	else if (ft_strcmp(token_str, "'") == 0)
		return (TOKEN_SINGLE_QUOTE);
	else if (ft_strcmp(token_str, "\"") == 0)
		return (TOKEN_DOUBLE_QUOTE);
	else if (ft_strcmp(token_str, "$") == 0)
		return (TOKEN_DOLLAR);
	else
		return (TOKEN_WORD);
}

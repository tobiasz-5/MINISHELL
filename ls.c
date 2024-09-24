/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:35 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/24 12:23:19 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void ls(void)
{
    struct dirent *entry;
    DIR *dirptr;

    dirptr = opendir("."); // apre la directory corrente
    if (dirptr == NULL)
    {
        perror("opendir error: permission issues or directory does not exist");
        return;
    }

    // itera per ogni file
    while ((entry = readdir(dirptr)) != NULL)
    {
        // salta i file nascosti
        if (entry->d_name[0] == '.')
            continue;

        printf("%s  ", entry->d_name);
    }

    printf("\n");
    closedir(dirptr);   // chiude la directory
}

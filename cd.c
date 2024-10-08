#include "miniheader.h"

void	cd(char *input)
{
	char *current_dir;
	char new_dir[100];
	int i;
	int j;

	i = 0;
	j = 0;
	current_dir = getcwd(NULL, 0);
	while (input[j] != 'd')
		j++;
	j += skip_spaces(&input[j], j); 
	while (current_dir[i])
	{
		new_dir[i] = current_dir[i];
		i++;
	}
	new_dir[i++] = '/';
	while (input[j])
		new_dir[i++] = input[j++];
	new_dir[i] = '\0';
	chdir(new_dir);
}
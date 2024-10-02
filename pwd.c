#include "miniheader.h"
//aggiungere libft con ft_printf e sostituire printf con ft_printf e aggiungere header
void    ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		printf("Error pwd malloc");
		return ;
	}
	printf("%s\n", pwd);
	free(pwd);
	return ;
}

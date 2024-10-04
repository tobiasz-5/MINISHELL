#include "miniheader.h"

char	**ft_copy_mtx(char **mtx)
{
	char	**new;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (mtx[c])
		c++;
	new = (char **)malloc((c + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < c)
	{
		new[i] = ft_strdup(mtx[i]);
		if (!new)
		{
			ft_free_mtx(new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

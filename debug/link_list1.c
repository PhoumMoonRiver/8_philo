#include "../philo.h"

void	show_philo(t_env *env, t_philo *h)
{
	int	i;

	i = 0;
	env->p = h;
	while (env->p && i != 10)
	{
		if (env->p->next == NULL)
			return ;
		printf("%d\n", env->p->id);
		env->p = env->p->next;
		i++;
	}
}

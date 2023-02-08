#include "../philo.h"

void	show_philo(t_env *env)
{
	int i;

	i = 0;
	while (env->p && i < 10)
	{
		printf("%d\n", env->p->id);
		env->p = env->p->next;
		i++;
	}
}

#include "../philo.h"

void	show_philo(t_env *env, t_philo *h)
{
	env->p = h;
	while (env->p)
	{
		printf("%d\n", env->p->id);
		if (env->p->next == NULL)
			return ;
		env->p = env->p->next;
	}
}

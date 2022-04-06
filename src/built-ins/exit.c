void	cleanup_env(t_list *l)
{
	t_list	*tmp;
	t_list	*t;

	tmp = l;
	while (tmp != NULL)
	{
		t = tmp->next;
		delvar(tmp);
		tmp = t;
	}
}

void	ms_exit(t_shell *s)
{
	cleanup_env(s->env);
	free(s->input);
	exit(EXIT_SUCCESS);
}

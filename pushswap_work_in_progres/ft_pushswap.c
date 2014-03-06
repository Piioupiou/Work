/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:20:07 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/29 23:28:57 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	ft_createlst(argc, argv);
	ft_putstr("\n");
	return (0);
}

int	ft_createlst(int argc, char **argv)
{
	t_1list	*l_a;
	t_1list	*tmp;
	t_1list	*tmp2;
	int	i;

	i = 1;
	l_a = (t_1list*)malloc(sizeof(t_1list) * ft_strlen(argv[i]));
	tmp = (t_1list*)malloc(sizeof(t_1list) * ft_strlen(argv[i]));
	tmp = l_a;
	tmp->data = atoi(argv[i]);
	tmp->next = NULL;
	i++;
	while (i < argc)
	{
		tmp2 = (t_1list*)malloc(sizeof(t_1list) * ft_strlen(argv[i]));
		tmp2->data = atoi(argv[i]);
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
		i++;
	}
	ft_pushswap(l_a);
	return (0);
}

void	ft_pushswap(t_1list *l_a)
{
	t_1list	*tmp;
	t_1list	*tmp2;
	t_1list	*l_b;
	t_1list	*tmp3;

	tmp3 = NULL;
	tmp = l_a;
	l_b = (t_1list*)malloc(sizeof(t_list) * 2);
	tmp2 = l_b;
	tmp2->data = l_a->data;
	tmp2->next = NULL;
	l_b->next = tmp2;
	while (tmp != NULL)
		tmp = ft_pushswap2(tmp, tmp2, tmp3, l_b);
	ft_putstr_fd("rb", 1);
}

t_1list	*ft_pushswap2(t_1list *tmp, t_1list *tmp2, t_1list *tmp3, t_1list *l_b)
{
	int	i;

	i = 0;
		while (tmp2 != NULL)
		{
			if (tmp2->next == NULL || (tmp->data >= tmp2->data &&
						tmp->data <= (tmp2->next)->data))
			{
				tmp3 = (t_1list*)malloc(sizeof(t_list) * 2);
				tmp3->data = tmp2->data;
				tmp3->next = NULL;
				tmp2->next = tmp3;
				tmp2->data = tmp->data;
				i = 1;
				ft_putstr_fd("pb ", 1);
				break ;
			}
			tmp2 = tmp2->next;
			if (tmp2->next != NULL)
				ft_putstr_fd("rb ", 1);
		}
		tmp2 = l_b;
		if (i != 1)
			ft_putstr_fd("ra ", 1);
		return (tmp->next);
}

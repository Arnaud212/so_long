/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:38:11 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 12:30:59 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*lrn;

	tmp = NULL;
	lrn = *lst;
	while (lrn)
	{
		tmp = lrn;
		lrn = lrn->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:37:39 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/23 18:33:47 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstmap(t_gnl *lst, void *(*f)(void *), void (*del)(void *))
{
	t_gnl	*newlst;
	t_gnl	*newlst_tmp;
	void	*f_content;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		f_content = f(lst->content);
		newlst_tmp = ft_lstnew(f_content);
		if (!newlst_tmp)
		{
			ft_lstclear(&newlst, del);
			del(f_content);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newlst_tmp);
		lst = lst->next;
	}
	return (newlst);
}

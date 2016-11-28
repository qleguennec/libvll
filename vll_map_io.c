/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_map_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:09:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 21:13:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

void		vll_map_io(t_vll *l, void (*f)(t_vect *v))
{
	t_vll_node	*n;

	n = l->head;
	if (!n)
		return ;
#if (VLL_VLL)
	if (IS_VLL(l))
	{
		while (n)
		{
			vll_map_io(n->p, f);
			n = n->next;
		}
	}
#endif
	while (n)
	{
		f(n->p);
		n = n->next;
	}
}

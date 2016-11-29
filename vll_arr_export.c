/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_arr_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:43:28 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 21:48:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void		**vll_arr_export(t_vll *l, int opts)
{
	size_t		i;
	size_t		len;
	t_vect		*v;
	t_vll_node	*n;
	void		**ret;

	MALLOC_N(ret, vll_size(l));
	n = l->head;
	i = 0;
	while (n)
	{
		v = n->p;
		len = (opts & VLL_ARR_EXPORT_STR) + v->used;
		MALLOC_N(ret[i], len);
		ft_memcpy(ret[i], v->data, v->used);
		if (opts & VLL_ARR_EXPORT_STR)
			((unsigned char *)ret[i])[v->used] = '\0';
		n = n->next;
		i++;
	}
	return (ret);
}

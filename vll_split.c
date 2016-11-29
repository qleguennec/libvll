/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:01:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 22:01:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll		*vll_split(t_vect *v,  void *match, size_t n2, int opts)
{
	size_t			n1;
	t_vll			*new;
	t_vll_node		*n;
	unsigned char	*r;
	void			*s;

	new = vll_new();
	s = v->data;
	n1 = v->used;
	n = NULL;
	while ((r = ft_word(&s, &n1, match, n2)))
	{
		n = vll_add_front(new, n, r, (opts & VLL_SPLIT_STR) + (unsigned char *)s - r);
		if (opts & VLL_SPLIT_STR)
			vect_mset_end(n->p, '\0', 1);
	}
	return (new);
}

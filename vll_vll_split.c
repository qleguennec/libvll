/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_vll_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:33:38 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 20:04:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

static void		record_words(t_vll *l, t_vll_node **m, t_vect *v, t_vect *match)
{
	size_t			n;
	t_vll_node		*new;
	unsigned char	*r;
	unsigned char	*s;

	new = NULL;
	s = v->data;
	n = v->used;
	while ((r = ft_word((void **)&s, &n, match->data, match->used)))
		*m = vll_add_front(l, *m, r, s - r);
}

static t_vll	*split(t_vll *l, t_vect *v)
{
	t_vll			*new;
	t_vll_node		*m;
	t_vll_node		*n;

	new = vll_new();
	n = l->head;
	m = NULL;
	while (n)
	{
		record_words(new, &m, n->p, v);
		n = n->next;
	}
	return (new);
}

t_vll			*vll_vll_split(t_vll *l, void *match, size_t n)
{
	t_vect	v;

	v.used = n;
	v.data = match;
	return (vll_fmap(l, (t_vll *(*)(t_vll *, void *))&split, &v));
}

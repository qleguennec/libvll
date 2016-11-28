/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:33:38 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 17:59:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

static t_vect		*next_word
	(unsigned char **s1, size_t *n1, void *match, size_t n2)
{
	unsigned char	*r;
	unsigned char	*s2;

	s2 = match;
	while (*n1 && ft_memchr(s2, (int)**s1, n2))
	{
		--(*n1);
		++(*s1);
	}
	r = *s1;
	while (*n1 && !ft_memchr(s2, (int)**s1, n2))
	{
		--(*n1);
		++(*s1);
	}
	return (r == *s1 ? NULL : vect_new(r, *s1 - r));
}

static t_vll_node	*record_words(t_vll *l, t_vect *v, void *match, size_t size)
{
	size_t			n;
	t_vect			*w;
	t_vll_node		*new;
	unsigned char	*s;

	new = NULL;
	s = v->data;
	n = v->used;
	while ((w = next_word(&s, &n, match, size)))
		new = vll_add_front(l, new, v, (size_t)-1);
	return (new);
}

static t_vll		*split(t_vll *l, t_vect *v)
{
	t_vll			*new;
	t_vll_node		*m;
	t_vll_node		*n;

	new = vll_new();
	n = l->head;
	m = NULL;
	while (n)
	{
		m = record_words(new, n->p, v->data, v->used);
		n = n->next;
	}
	return (new);
}

t_vll				*vll_split(t_vll *l, void *match, size_t n)
{
	t_vect	v;

	v.used = n;
	v.data = match;
	return (vll_fmap(l, (t_vll *(*)(t_vll *, void *))&split, &v));
}

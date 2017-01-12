/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_repeat_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:03:34 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void
	vll_repeat_front
	(t_vll *l
	, t_vect (*f)(void *ctxt)
	, void *ctxt
	, size_t n)
{
	t_vect		v;
	t_vll_node	*m;

	m = NULL;
	while (n)
	{
		v = f(ctxt);
		vll_add_front(l, m, v.data, v.used);
		n--;
	}
}

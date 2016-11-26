/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:38:04 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 16:58:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

size_t		vll_size(t_vll *l)
{
	size_t		ret;
	t_vll_node	*n;

#if (VLL_SIZE)
	return (l->size);
#endif
	n = l->head;
	ret = 0;
	while (n)
	{
		n = n->next;
		++ret;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:03:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 15:03:41 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_node_new(void *data)
{
	t_vll_node	*ret;

	MALLOC_SIZEOF(ret);
	ret->next = NULL;
#if (VLL_DLINK)
	ret->prev = NULL;
#endif
	ret->p = data;
	return (ret);
}

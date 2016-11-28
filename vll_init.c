/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:02:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 13:14:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

void		vll_init(t_vll *l)
{
	l->head = NULL;
#if (VLL_TAIL)
	l->tail = NULL;
#endif
#if (VLL_SIZE)
	l->size = 0;
#endif
#if (VLL_VLL)
	l->vll_vll = 0;
#endif
}

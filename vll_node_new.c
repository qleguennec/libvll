/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:03:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/23 00:56:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll_node		*vll_node_new(void *data)
{
	t_vll_node	*ret;

	MALLOC1(ret);
	ret->next = NULL;
	ret->prev = NULL;
	ret->p = data;
	return (ret);
}

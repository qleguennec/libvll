/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:55:56 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 15:47:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll		*vll_new(void)
{
	t_vll	*ret;

	MALLOC_SIZEOF(ret);
	vll_init(ret);
	return (ret);
}

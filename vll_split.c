/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:01:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 20:05:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll		*vll_split(void *s, size_t n1, void *match, size_t n2)
{
	t_vll			*new;
	t_vll_node		*n;
	unsigned char	*r;

	new = vll_new();
	n = NULL;
	while ((r = ft_word(&s, &n1, match, n2)))
		n = vll_add_front(new, n, r, (unsigned char *)s - r);
	return (new);
}

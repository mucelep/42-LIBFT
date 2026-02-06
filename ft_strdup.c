/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:40 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/04 13:02:30 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*x;
	size_t	i;

	i = ft_strlen(s);
	x = malloc((i + 1) * sizeof(char));
	if (!x)
		return (NULL);
	ft_strlcpy(x, s, i + 1);
	return (x);
}

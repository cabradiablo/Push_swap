/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:20:47 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/07 03:53:31 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(char *msg)
{	
	int	i;

	i = 0;
	(void)msg;
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

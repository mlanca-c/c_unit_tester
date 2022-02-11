/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unit_testing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/11 19:00:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_UNIT_TESTING_H
# define C_UNIT_TESTING_H

/* include a project header to test it */
# include "hello.h"
/* ... */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "color.h"

# define YAY	1
# define NAY	0

/* Message Templates */
# define _SUCCESS	"["GREEN" ok "RESET"]\n"
# define _FAILURE	"["RED" ko "RESET"]\n"
# define _INFO		"["BLUE" %s "RESET"]: "
# define _TEST		BLUE"%-50s "RESET"%s"

/* Tester functions templates */
typedef int(*test_fn)(void);

/* Global struct of the tester */
typedef struct s_tester
{
	int		test_nbr;
	int		success;
	int		failure;
}	t_tester;

/* test_* functions to test */
int	test_hello(void);
/* ... */

#endif /* C_UNIT_TESTING_H */

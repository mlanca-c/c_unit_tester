/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unit_testing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 19:03:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_UNIT_TESTING_H
# define C_UNIT_TESTING_H

/* This tester tested function located in the ../sources/ directory */

/*
** Include your project header(s) HERE
** Example:
** # include "sample.h"
*/
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BRED		"\033[31;1m"
# define BGREEN		"\033[32;1m"
# define BYELLOW	"\033[33;1m"
# define BBLUE		"\033[34;1m"
# define BMAGENTA	"\033[35;1m"
# define BCYAN		"\033[36;1m"
# define BWHITE		"\033[37;1m"
# define YAY	1
# define NAY	0
# define _SUCCESS	"["GREEN" ok "RESET"]\n"
# define _FAILURE	"["RED" ko "RESET"]\n"
# define _INFO		"["YELLOW" %s "RESET"]: "
# define _TEST		YELLOW"%-120s "RESET"%s"

/* Tester functions mandatory prototype */
/* (do not change) */
typedef int(*test_fn)(void);

/* Tester struct that has all the necesssary information regarding the tests */
/* (do not change) */
typedef struct s_tester
{
	int		test_nbr;
	int		success;
	int		failure;
}	t_tester;

/*Your Tester functions */
int	test_strlen(void);
/* ... */

#endif /* C_UNIT_TESTING_H */

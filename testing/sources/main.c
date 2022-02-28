/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:16:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/28 19:04:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "c_unit_testing.h"

t_tester	*tester;

static int	test_yay(void);
static int	test_nay(void);

static char	*scan_name(void)
{
	static char	*type[] = {"yay", "nay", "srtlen", NULL};
	static int	i = 0;

	if (type[i])
		return (type[i++]);
	return (NULL);
}

static int	next_test(void)
{
	static int		i = 0;
	static test_fn	fn[] = {test_yay, test_nay, test_strlen, NULL};
	int				status;

	if (!fn[i])
		exit(1);
	status = fn[i++]();
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	state;

	(void)argc;
	(void)argv;
	(void)envp;

	printf(GREEN"   _|_|_|          _|    _|  _|      _|  _|_|_|  _|_|_|_|_|      _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|  _|_|_|\n");
	printf(GREEN" _|                _|    _|  _|_|    _|    _|        _|              _|      _|        _|            _|      _|        _|    _|\n");
	printf(GREEN" _|    _|_|_|_|_|  _|    _|  _|  _|  _|    _|        _|              _|      _|_|_|      _|_|        _|      _|_|_|    _|_|_|\n");
	printf(GREEN" _|                _|    _|  _|    _|_|    _|        _|              _|      _|              _|      _|      _|        _|    _|\n");
	printf(GREEN"   _|_|_|            _|_|    _|      _|  _|_|_|      _|              _|      _|_|_|_|  _|_|_|        _|      _|_|_|_|  _|    _|\n");
	printf("\tby mlanca-c\n\n");


	tester = calloc(1, sizeof(t_tester));
	if (!tester)
		return (1);
	tester->test_nbr = 3;
	i = 0;
	while (i < tester->test_nbr)
	{
		state = next_test();
		if (state) { printf(_TEST, scan_name(),_SUCCESS); tester->success++; }
		else { printf(_TEST, scan_name(),_FAILURE); tester->failure++; }
		i++;
	}

	printf("%60s"_SUCCESS, " ");
	printf("%60s%d/%d \n", " ",tester->success, tester->test_nbr);
	printf("%60s"_FAILURE, " ");
	printf("%60s%d/%d \n", " ", tester->failure, tester->test_nbr);
}

static int	test_yay(void)
{
	return (YAY);
}

static int	test_nay(void)
{
	return (NAY);
}



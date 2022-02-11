/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:16:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/11 18:54:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "c_unit_testing.h"

t_tester	*tester;

static void	run_tests(void);
static void	status(void);
static void	success(void);
static void	failure(void);
static char	*scan_name(void);
static int	next_test(void);
static int	test_yay(void);
static int	test_nay(void);

static char	*scan_name(void)
{
	static char	*type[] = {"yay", "nay", "hello", NULL};
	static int	i = 0;

	if (type[i])
		return (type[i++]);
	return (NULL);
}

static int	next_test(void)
{
	static int		i = 0;
	static test_fn	fn[] = {test_yay, test_nay, test_hello, NULL};
	int				status;

	if (!fn[i])
		exit(1);
	status = fn[i++]();
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	run_tests();
}

static void	run_tests(void)
{
	int	i;
	int	state;

	printf(GREEN "C UNIT TESTER\n" RESET);
	tester = calloc(1, sizeof(t_tester));
	if (!tester)
		return ;
	tester->test_nbr = 3;
	i = 0;
	while (i < tester->test_nbr)
	{
		state = next_test();
		if (state)
			success();
		else
			failure();
		i++;
	}
	status();
}

static void	success(void)
{
	printf(_TEST, scan_name(),_SUCCESS);
	tester->success++;
}

static void	failure(void)
{
	printf(_TEST, scan_name(),_FAILURE);
	tester->failure++;
}

static void	status(void)
{
	printf(_SUCCESS);
	printf("%d/%d\n", tester->success, tester->test_nbr);
	printf(_FAILURE);
	printf("%d/%d\n", tester->failure, tester->test_nbr);
}

static int	test_yay(void)
{
	return (YAY);
}

static int	test_nay(void)
{
	return (NAY);
}

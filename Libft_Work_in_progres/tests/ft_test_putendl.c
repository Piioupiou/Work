#include "test.h"

int	ft_test_putendl2(char const *str, char const *final)
{
	int		res;
	char	*res2;
	int		fd;
	size_t	len;

	res = 0;
	len = strlen(final);
	res2 = (char *)malloc(sizeof(char) * (len + 1));
	memset((void *)res2, 0, len + 1);
	freopen("log.txt","w",stdout);
	ft_putendl(str);
	freopen("/dev/tty","w",stdout);
	fd = open("log.txt", O_RDONLY);
	read(fd, res2, len);
	close(fd);
	if (strcmp(res2, final))
		++res;
	printf("Test : \"%s\" { \"%s\" }", str, res2);
	free(res2);
	ft_print_status(res);
	return (res);
}

int	ft_test_putendl(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putendl");
	res += ft_test_putendl2("Hello world !", "Hello world !\n");
	res += ft_test_putendl2("Welcome\nIt's a test\n", "Welcome\nIt's a test\n\n");
	return (ft_print_end(res));
}
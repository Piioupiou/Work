#include "test.h"

int	ft_test_putstr2(char const *str)
{
	int		res;
	char	*res2;
	int		fd;
	size_t	len;

	res = 0;
	len = strlen(str);
	res2 = (char *)malloc(sizeof(char) * (len + 1));
	memset((void *)res2, 0, len + 1);
	freopen("log.txt","w",stdout);
	ft_putstr(str);
	freopen("/dev/tty","w",stdout);
	fd = open("log.txt", O_RDONLY);
	read(fd, res2, len);
	close(fd);
	if (strcmp(res2, str))
		++res;
	printf("Test : \"%s\" { \"%s\" }", str, res2);
	free(res2);
	ft_print_status(res);
	return (res);
}

int	ft_test_putstr(void)
{
	int	res;

	res = 0;
	ft_print_begin("ft_putstr");
	res += ft_test_putstr2("Hello world !");
	res += ft_test_putstr2("Welcome\nIt's a test\n");
	return (ft_print_end(res));
}
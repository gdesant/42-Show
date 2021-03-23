#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char	buf1[BUF_SIZE];
	int		fd;
	int		ret;

	// ft_read
	bzero(&buf1, BUF_SIZE);

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);

	if (fd == 0 || fd == -1)
		printf("Enter a Sentence :\n");

	errno = 0;
	if (fd != 0 && fd != -1) 
		ret = ft_read(fd, buf1, BUF_SIZE);
	else
		ret = ft_read(0, buf1, BUF_SIZE);
	if (argc > 1)
		printf("FileContent : %s\n", buf1);
	printf("return value = %d\n", ret);
	perror("perror");
	return (0);
}

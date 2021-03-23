#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char buf1[BUF_SIZE];
	int fd = 0;
	int ret = 0;
	int t1 = 0;
	int t2 = 0;
	int fd1 = 0;
	int fd2 = 0;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (argc > 2)
			fd2 = open(argv[2], O_WRONLY);
	}

	if (fd1 != 0 && fd1 != -1)
		ret = read(fd1, buf1, BUF_SIZE);	
	else if (fd1 == -1)
		strcpy(buf1, argv[1]);
	else if (argc == 1)
		strcpy(buf1, "");
	else
		strcpy(buf1, "LoremIpsumTempText");

	if (argc > 2)
		fd = fd2;
	else
		fd = 1;

	
	errno = 0;
	ret = ft_write(fd, buf1, strlen(buf1) * sizeof(char));
	printf("\n---------------------------------------------------------\n");
	printf("return value = %d\n", ret);
	perror("perror");
	return (0);
}

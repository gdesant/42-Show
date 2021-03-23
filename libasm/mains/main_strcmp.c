#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char buf1[BUF_SIZE];
	char buf2[BUF_SIZE];
	int fd1 = 0;
	int fd2 = 0;
	int ret = 0;
	int t1 = 0;
	int t2 = 0;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (argc > 2)
			fd2 = open(argv[2], O_RDONLY);
	}

	if (fd1 != 0 && fd1 != -1)
		ret = read(fd1, buf1, BUF_SIZE);	
	else if (fd1 == -1)
		strcpy(buf1, argv[1]);
	else if (argc == 1)
		strcpy(buf1, "");
	else
		strcpy(buf1, "LoremIpsumTempText");

	if (fd2 != 0 && fd2 != -1)
		ret = read(fd2, buf2, BUF_SIZE);	
	else if (fd2 == -1)
		strcpy(buf2, argv[2]);
	else if (argc <= 2)
		strcpy(buf2, "");
	else
		strcpy(buf2, "LoremIpsumTempText");

	t1 = ft_strcmp(buf1, buf2);
	t2 = strcmp(buf1, buf2);
	printf("Buf1 : %s\n", buf1);
	printf("Buf2 : %s\n", buf2);
	printf("--------------------------------------------------\n");
	printf("\x1B[35mft_strcmp:\x1B[0m %d\n", t1);
	printf("\x1B[35m-> strcmp:\x1B[0m %d\n", t2);
	if (t1 == t2)
		printf("\x1B[32mSuccess !\n");
	else
		printf("\x1B[31mNot Success !\n");
	return (0);
}

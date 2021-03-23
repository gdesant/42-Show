#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char buf1[BUF_SIZE];
	int fd = 0;
	int ret = 0;
	int t1 = 0;
	int t2 = 0;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);

	if (fd != 0 && fd != -1)
		ret = read(fd, buf1, BUF_SIZE);
	else if (fd == -1)
		strcpy(buf1, argv[1]);
	else if (argc == 1)
		strcpy(buf1, "");
	else
		strcpy(buf1, "LoremIpsumTempText");

	t1 = ft_strlen(buf1);
	t2 = strlen(buf1);
	printf("STR : %s\n------------------------------------------\n", buf1);
	printf("\x1B[35mft_strlen:\x1B[0m %d\n", t1);
	printf("\x1B[35m-> strlen:\x1B[0m %d\n", t2);
	if (t1 == t2)
		printf("\x1B[32mSuccess !\n");
	else
		printf("\x1B[31mNot Success !\n");
	return (0);
}

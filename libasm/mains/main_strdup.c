#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char buf1[BUF_SIZE];
	char buf2[BUF_SIZE];
	int fd = 0;
	int ret = 0;
	int t1 = 0;
	int t2 = 0;

	char *dest1;
	char *dest2;

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


	strcpy(buf2, buf1);
	
	dest1 = ft_strdup(buf1);
	dest2 = strdup(buf2);

	printf("STR : %s\n------------------------------------------\n", buf1);
	printf("\x1B[35mft_strdup:\x1B[0m %s\n", dest1);
	printf("\x1B[35m-> strdup:\x1B[0m %s\n", dest2);
	if (strcmp(dest1, dest2) == 0)
		printf("\x1B[32mSuccess !\n");
	else
		printf("\x1B[31mNot Success !\n");
	free(dest1);
	free(dest2);
	return (0);
}
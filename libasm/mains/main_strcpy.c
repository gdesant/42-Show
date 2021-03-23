#include "libasm_main.h"

int		main(int argc, char **argv)
{
	char buf1[BUF_SIZE];
	char dest1[BUF_SIZE];
	char dest2[BUF_SIZE];
	int fd = 0;
	int ret = 0;
	char *t1;
	char *t2;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);

	if (fd != 0 && fd != -1)
		ret = read(fd, buf1, BUF_SIZE);
	else if (fd == -1)
		ft_strcpy(buf1, argv[1]);
	else if (argc == 1)
		ft_strcpy(buf1, "");
	else
		ft_strcpy(buf1, "LoremIpsumTempText");

	t2 = strcpy(dest2, buf1);
	t1 = ft_strcpy(dest1, buf1);
	printf("\x1B[35mft_strcpy:\x1B[0m %s\n", dest1);
	printf("\x1B[35m-> strcpy:\x1B[0m %s\n", dest2);
	if (strcmp(dest1, dest2) == 0)
		printf("\x1B[32mSuccess !\n");
	else
		printf("\x1B[31mNot Success !\n");
	return (0);
}

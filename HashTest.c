#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[]) {
	char buf[1024];
	memset(buf, 0, 1024);
	if(argc != 3) {
		printf("Usage : %s <Password> <Salt>\n\tSalt value gets only two character. If you write long word, it isn't work.\n", argv[0]);
		exit(1);
	}
	sprintf(buf, "$6$%s", argv[2]);
	printf("Password : %s, Salt : %s\n", argv[1], argv[2]);
	printf("HashValue : %s\n", crypt(argv[1], buf));
	return 0;
}

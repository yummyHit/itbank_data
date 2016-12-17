#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Usage : %s <Password> <Salt>\n\tSalt value gets only two character. If you write long word, it isn't work.\n", argv[0]);
		exit(1);
	}
	printf("Password : %s, Salt : %s\n", argv[1], argv[2]);
	printf("HashValue : %s\n", crypt(argv[1], argv[2]));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char **argv) {
	FILE *WordList;
	char passwd[10], salt[3], buf[1024], *hash;

	if(argc != 3) {
		printf("Usage : %s <WordList> <Hash_Value>\n\tHash_Value is a program. If you want to run this program, you must run Hash_Value program at first.", argv[0]);
		exit(1);
	}

	memset(buf, 0, 1024);
	memset(salt, 0, 3);

	WordList = fopen(argv[1], "r");
	fgets(passwd, sizeof(passwd), WordList);
	passwd[strlen(passwd)-1] = '\0';
	strncpy(salt, argv[2], 2);
	sprintf(buf, "$6$%s", salt);

	hash = crypt(passwd, buf);
	printf("passwd : %s\nsalt : %s\nHash : %s\n", passwd, argv[2], hash);

	fclose(WordList);
	return 0;
}

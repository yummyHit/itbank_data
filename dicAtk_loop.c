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

	memset(salt, 0, 3);

	strncpy(salt, argv[2], 2);
	WordList = fopen(argv[1], "r");
	
	while(fgets(passwd, sizeof(passwd), WordList) != NULL) {
		passwd[strlen(passwd)-1] = '\0';
		hash = crypt(passwd, salt);
		printf("%-10s ==> %20s\n", passwd, hash);
		if(!strcmp(hash, argv[2]))
			printf("Hash : %s\nPassword : %s\n", argv[2], passwd);
	}
	fclose(WordList);
	return 0;
}

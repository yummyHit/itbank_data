#include <stdio.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[]) {
	char passwd[10], salt[20];
	char *HashValue;

	strcpy(passwd, "1234");
	strcpy(salt, "$6$QEKZZ7kk");
	HashValue = crypt(passwd, salt);

	printf("Password : %s, Salt : %s\n", passwd, salt);
	printf("HashValue : %s\n", HashValue);
	return 0;
}

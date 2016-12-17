#include <stdio.h>
#include <string.h>
#include <crypt.h>

int main() {
	int i;
	char *HashValue = "$6$QEKZZ7kk$Z6LQxV63b..gj8xRwOehaFa7p5XvjftMIx6EzF4nUmClBzb8qCAKR1FFLoX21sIdDNuxzKldEZnFNHE45RRpC/";
	char salt[10], passwd[10];

	strcpy(salt, "$6$QEKZZ7kk");

	for(i = 0; i < 10000; i++) {
		sprintf(passwd, "%d", i);
		if(!strcmp(crypt(passwd, salt), HashValue)) {
			printf("Password : %s\n", passwd);
			break;
		}
	}
	return 0;
}

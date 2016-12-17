#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[]) {
	char buf[1024], hash[100], salt[20], passwd[10];
	int i = 0, j = 0, h, k, tmp = 0;
	FILE *fp;

	memset(buf, 0, 1024);
	memset(salt, 0, 20);
	memset(hash, 0, 100);

	if(argc != 2) {
		printf("Usage : %s <user>\n", argv[0]);
		exit(1);
	}

	sprintf(buf, "cat /etc/shadow | grep %s > user.txt", argv[1]);
	i = system(buf);

	if(i != -1 && i != 127) {
		fp = fopen("user.txt", "r");
		fread(buf, 1, sizeof(buf), fp);
		i = 0;
		while(1) {
			if(!strncmp(buf+i, ":", 1)) {
				tmp = i+1;
				while(1) if(!strncmp(buf+i+(++j), ":", 1)) break;
				strncpy(hash, buf+tmp, j-1);
				strncpy(salt, hash, 11);
				printf("Hash : %s\nSalt : %s\n", hash, salt);
				break;
			}
			i++;
		}
	}

	for(i = 0; i < 10000; i++) {
		sprintf(passwd, "%d", i);
		if(!strcmp(crypt(passwd, salt), hash)) {
			printf("Password : %s\n", passwd);
			break;
		}
	}

	return 0;
}

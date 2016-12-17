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

/*
	i = 33;	j = 33;	h = 33;	k = 33;	tmp = 0;
	while(1) {
		sprintf(passwd+tmp, "%c", i++);
		if(!strcmp(crypt(passwd, salt), hash)) {
			printf("Password : %s\n", passwd);
			break;
		}
		if(i > 126) {
			if(tmp == 0) tmp++;
			if(j < 126 && tmp == 1) sprintf(passwd, "%c", j++);
			else if(j < 126 && tmp == 2) sprintf(passwd+1, "%c", j++);
			else if(j < 126 && tmp == 3) sprintf(passwd+2, "%c", j++);
			i = 33;
		}
		else if(i > 126 && j > 126) {
			if(tmp == 1) tmp++;
			if(h < 126 && tmp == 2) sprintf(passwd, "%c", h++);
			else if(h < 126 && tmp == 3) sprintf(passwd+1, "%c", h++);
			i = 33;
			j = 33;
		}
		else if(i > 126 && j > 126 && h > 126) {
			if(tmp == 2) tmp++;
			if(k < 126) sprintf(passwd, "%c", k++);
			i = 33;
			j = 33;
			h = 33;
		}
		else if(i > 126 && j > 126 && h > 126 && k > 126) break;
	}
*/

	for(i = 33; i < 127; i++) {
		for(j = 33; j < 127; j++) {
			for(h = 33; h < 127; h++) {
				for(k = 33; k < 127; k++) {
					sprintf(passwd, "%c", k);
					if(!strcmp(crypt(passwd, salt), hash)) {
						printf("Password : %s\n", passwd);
						break;
					}
				}
				sprintf(passwd+1, "%c", h);
			}
			sprintf(passwd+2, "%c", j);
		}
		sprintf(passwd+3, "%c", i);
	}

	return 0;
}

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "mycon.h"
int main(void) {
	int ch, get;
	int type = 0;
	int curLine = 2;
	FILE *fp = fopen("1.txt", "r");
	cls();
	gotoxy(4, curLine);
	set_size(100, 30);
	if(fp == NULL) {
		printf("[ERROR] Cannot open file `1.txt`!\n");
		fclose(fp);
		while(1);
	}
	ch = fgetc(fp);
	while(!feof(fp)) {
		if(ch == '\n') {
			curLine ++;
			gotoxy(3, curLine);
		}else{
			printf("%c", ch);
		}
		ch = fgetc(fp);
	}
	curLine = 2;
	rewind(fp);
	ch = fgetc(fp);
	gotoxy(3, curLine);
	while(!feof(fp)) {
		if(ch == '\n') {
			curLine ++;
			printf("\b ");
			gotoxy(3, curLine);
		}else{
			while(ch != getkey()) type ++;
			type ++;
			printf("\b |");
		}
		ch = fgetc(fp);
	}
	gotoxy(4, 2);
	printf("Great. Pressed the button %d times!\n    Please click `X` to exit.", type);
	fclose(fp);
	while(1);
}

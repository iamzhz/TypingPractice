/*
 * 编译第一步： gcc -c 打字练习.c -o 1.o
 * 编译第二步： gcc 1.o mycon.o -lwinmm -o 打字练习.exe
 */
#include <stdio.h>
#include <windows.h>
#include <mycon.h>
#include <stdlib.h>

int main(void)
{
	cls();
	
	FILE *fp;
	fp=fopen("1.txt", "r");
	
	set_size(30,100);                 // 宽=50，高=30 
	set_title("打字练习");
	system("color 3F");              // 2=绿色，F=白色 
	gotoxy(2,1);                     // x=2,y=3
	
	char a;                          // a=接收的内容 
	char b;                          // b=文件里的一个字符 
	int c=0 ,d=0 ,f=0;               // c=错了几个 ,d=对了几个，f=一共几个 
	
	 
	//从下一行 
	b=fgetc(fp);
	while(b != EOF)
	{
		f++ ;                        // f=一共几个 
		printf("%c", b);
		b=fgetc(fp);
	}
	//到上一行  是显示文件内容
	
	gotoxy(2,2);                     // x=3,y=3
	
	rewind(fp);                      // fp - 首位
	
	set_color(3,5);
	
	//从下一行 
	b=fgetc(fp);
	while(b != EOF)
	{
		a=getkey();
		printf("%c", a);
		
		if(a != b)   c++ ;            // c=错了几个 ,d=对了几个
		else         d++ ;
		
		b=fgetc(fp);
	}
	//到上一行  是接收和判断
	
	set_color(3,0xF);
	
	if(c == 0)
	{
		printf("\n\n\nVery good!");
		goto E;
	}
	
	printf("\n\n\n一共%d 个，你错了%d 个，对了%d 个。",f ,c ,d);
	
	E:
	
	while(1)
	Sleep(500);
	
	return 0;
}
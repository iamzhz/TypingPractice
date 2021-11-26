#ifndef _WINDOWS_H_
#define	_WINDOWS_H_
#endif

//�ı����̨���ڴ�СΪwidth��height��
void set_size(int width, int height);

//���ÿ���̨���ڵı���Ϊ�ַ���title
void set_title(char *title);

//�ƶ���굽����(x, y)������y��x��
void gotoxy(int x, int y); 

//���ع��
void hide_cursor(void);

//��ʾ���
void show_cursor(void);

//������ɫ������ bcolor����ɫ��fcolorǰ��ɫ 
//������ɫֵ�μ��������µ�color/?���
void set_color(int bcolor, int fcolor);

//��ʱ��������λ����
void delay(int dtime);

//����wav��ʽ������
void play_sound(const char *sndfile);

//����
void cls(void);

//��ȡ����
int getkey(void);

#ifndef __TIPS__
#define __TIPS__
unsigned short int getcolor(int color)
{
	switch (color)
	{
	case 0:return  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;			//ǳ��ɫ
	case 1:return  FOREGROUND_RED | FOREGROUND_BLUE;							//ǳ��ɫ
	case 2:return  FOREGROUND_GREEN;											//ǳ��ɫ
	case 3:return  FOREGROUND_RED;												//ǳ��ɫ
	case 4:return FOREGROUND_GREEN | FOREGROUND_BLUE;							//ǳ��ɫ
	case 5:return  FOREGROUND_RED | FOREGROUND_GREEN;							//ǳ��ɫ
	case 6:return FOREGROUND_INTENSITY | FOREGROUND_RED;						//������ɫ
	case 7:return FOREGROUND_INTENSITY | FOREGROUND_GREEN;					//������ɫ
	case 8:return FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;	//����ǳ��ɫ
	case 9:return FOREGROUND_INTENSITY | FOREGROUND_BLUE;						//������ɫ
	case 10:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN;	//������ɫ
	case 11:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;	//������ɫ
	default:return 0;//ǳ��ɫ
	}
}
void errorbuy1() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "���������������棡"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void errorbuy2() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "ɾȥ����Ʒ�������������ﳵ��ģ�"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void errorbuy3() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "���ﳵ���޴���Ʒ��"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void suclog() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "��¼�ɹ���"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void unsuclog() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "�˺Ż��������"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void sucbuy() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "����ɹ���"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void head1() {
	for (int i = 0; i < 50; i++) cout << "="; cout << endl;
	cout << "1 �û���¼" << "    " << "2 �û�ע��" << "    " << "3 ����Ա��¼" << endl;
	for (int i = 0; i < 50; i++) cout << "="; cout << endl;
}
void head2() {
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
	cout << "0 ע����¼" << "    " << "1 ��ѯ��Ʒ" << "    " << "2 ������Ʒ" << "    " << "3 ɾ����Ʒ" << "    " << "4 �޸���Ʒ����" << "    " << "5 �޸���Ʒ�۸�" << "    " << "6 �ۻ��嵥" << endl;
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
}

#endif
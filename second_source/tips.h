#ifndef __TIPS__
#define __TIPS__
unsigned short int getcolor(int color)
{
	switch (color)
	{
	case 0:return  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;			//浅白色
	case 1:return  FOREGROUND_RED | FOREGROUND_BLUE;							//浅紫色
	case 2:return  FOREGROUND_GREEN;											//浅绿色
	case 3:return  FOREGROUND_RED;												//浅红色
	case 4:return FOREGROUND_GREEN | FOREGROUND_BLUE;							//浅蓝色
	case 5:return  FOREGROUND_RED | FOREGROUND_GREEN;							//浅黄色
	case 6:return FOREGROUND_INTENSITY | FOREGROUND_RED;						//高亮红色
	case 7:return FOREGROUND_INTENSITY | FOREGROUND_GREEN;					//高亮绿色
	case 8:return FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;	//高亮浅蓝色
	case 9:return FOREGROUND_INTENSITY | FOREGROUND_BLUE;						//高亮蓝色
	case 10:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN;	//高亮黄色
	case 11:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;	//高亮紫色
	default:return 0;//浅白色
	}
}
void errorbuy1() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "购买的数量超过库存！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void errorbuy2() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "删去的物品的数量超过购物车里的！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void errorbuy3() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "购物车里无此商品！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void suclog() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "登录成功！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void unsuclog() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "账号或密码错误！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void sucbuy() {
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
	cout << "付款成功！"; cout << endl;
	for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
}
void head1() {
	for (int i = 0; i < 50; i++) cout << "="; cout << endl;
	cout << "1 用户登录" << "    " << "2 用户注册" << "    " << "3 管理员登录" << endl;
	for (int i = 0; i < 50; i++) cout << "="; cout << endl;
}
void head2() {
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
	cout << "0 注销登录" << "    " << "1 查询商品" << "    " << "2 增加商品" << "    " << "3 删除商品" << "    " << "4 修改商品数量" << "    " << "5 修改商品价格" << "    " << "6 售货清单" << endl;
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
}

#endif
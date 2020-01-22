#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
#include "product.h"
#include "tips.h"
#include "user.h"
#define DISCOUNT 0.8
#define SIZE 101
int sta = 1;
product pro[SIZE];
product sell[SIZE];
product buy[SIZE][SIZE];
user us[SIZE];
int bunu[SIZE];
int pronu = 0;
int sellnu = 0;
int usnu = 0;
char line[256];
int nowus = 0;
string head = "";

void head3() {
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
	cout << "1 注销登录" << "    " << "2 查看商品" << "    " << "3 商品搜索" << "    " << "4 添加商品至购物车" << "    " << "5 删除购物车商品" << "    " << "6 查看购物车" << "    " << "7 结账" << "    ";
	HANDLE hOut;//创建句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, getcolor(6));//设置字体颜色
	if (!us[nowus].is_vip()) cout << "8 加入VIP（VIP可以享受8折优惠）" << endl; else cout << endl;
	SetConsoleTextAttribute(hOut, getcolor(0));//还原为白色字体
	for (int i = 0; i < 70; i++) cout << "="; cout << endl;
}

string change1(product x) {
	string st;
	st = st + x._id();
	for (int i = 1; i <= 3; i++) st = st + ' ';
	st = st + x.na();
	for (int i = 1; i <= 24 - x.na().length(); i++) st = st + ' ';
	st = st + x.br();
	for (int i = 1; i <= 24 - x.br().length(); i++) st = st + ' ';
	int z = int(x.va()), w = int(x.va() * 10) % 10, p = 0;
	string t="";
	while (z != 0) {
		t = char(z % 10 + 48) + t;
		z = z / 10; p++;
	}
	if (t == "") t = "0";
	t = t + '.' + char(w + 48);
	p = p + 2;
	st = st + t;
	for (int i = 1; i <= 12 - p; i++) st = st + ' ';
	z = x.nu();
	if (z == -1) t = "-1"; else {
		t = "";
		while (z != 0) {
			t = char(z % 10 + 48) + t;
			z = z / 10;
		}
		if (t == "") t = "0";
	}
	st = st + t;
	return st;
}
string change2(user t) {
	string st = t.na();
	for (int i = 1; i <= 24 - t.na().length(); i++) st = st + ' ';
	st = st + t.se();
	for (int i = 1; i <= 24 - t.se().length(); i++) st = st + ' ';
	if (t.is_vip()) st = st + "是"; else st = st + "否";
	for (int i = 1; i <= 12; i++) st = st + ' ';
	st = st + t.add();
	return st;
}
void update() {
	ofstream outfile1("product.txt");
	outfile1 << head << endl;
	for (int i = 1; i <= pronu; i++) {
		string s = change1(pro[i]);
		outfile1 << s << endl;
	}
	outfile1.close();
	ofstream outfile2("user.txt");
	string ss = "", sss = "";
	for (int i = 1; i <= 18; i++) ss = ss + ' ';
	for (int i = 1; i <= 20; i++) sss = sss + ' ';
	outfile2 << "用户名" << ss << "密码" << sss << "是否是VIP" <<"     "<< "地址"<< endl;
	for (int i = 1; i <= usnu; i++) {
		string sss = change2(us[i]);
		outfile2 << sss << endl;
	}
	outfile2.close();
	ofstream outfile3("sell.txt");
	outfile3 << head << endl;
	for (int i = 1; i <= sellnu; i++) {
		string s = change1(sell[i]);
		outfile3 << s << endl;
	}
	outfile3.close();
	for (int i = 1; i <= usnu; i++) {
		string st = "user", s1 = "";
		int t = i;
		while (t) {
			s1 = char(t % 10 + 48) + s1;
			t = t / 10;
		}
		st = st + s1 + ".txt";
		char p[101];
		for (int k=0;k<st.length();k++) p[k]=st[k];
		ofstream outfile(p);
		outfile << head << endl;
		for (int j = 1; j <= bunu[i]; j++) {
			string ss = change1(buy[i][j]);
			outfile << ss << endl;
		}
		outfile.close();
	}
}

void up() {
	ifstream myfile("product.txt");
	int i = 1;
	int t = 0;
	char buffer[256];
	while (!myfile.fail()) {
		myfile.getline(buffer, 256);
		if (t == 0) {
			t = 1; continue;
		}
		istringstream iss(buffer);
		string st1, st2, st3;
		double st4; int st5;
		iss >> st1 >> st2 >> st3 >> st4 >> st5;
		pro[i] = product(st1, st2, st3, st4, st5);
		i++;
	}
	i--;
	pronu = i - 1;
	ifstream ifile1("user.txt");
	i = 1; t = 0;
	while (!ifile1.fail()) {
		ifile1.getline(buffer, 256);
		istringstream iss(buffer);
		if (t == 0) {
			t = 1; continue;
		}
		if (buffer == "" || buffer[0] == ' ') continue;
		string st1, st2, st3, st4;
		iss >> st1 >> st2 >> st3 >> st4;
		if (st3 == "是")	us[i] = user(st1, st2, true, st4); else us[i] = user(st1, st2, false, st4);
		i++;
	}
	i--;
	usnu = i - 1;
	ifstream ifile2("sell.txt");
	if (ifile2) {
		i = 1; t = 0;
		while (!ifile2.fail()) {
			ifile2.getline(buffer, 256);
			istringstream iss(buffer);
			if (t == 0) {
				t = 1; continue;
			}
			if (buffer == "" || buffer[0] == ' ') continue;
			string st1, st2, st3;
			double st4; int st5;
			iss >> st1 >> st2 >> st3 >> st4 >> st5;
			sell[i] = product(st1, st2, st3, st4, st5);
			i++;
		}
		i--;
		sellnu = i - 1;
	}
	for (int j = 1; j <= usnu; j++) {
		string st,ss;
		int t = j;
		while (t) {
			st = char(t % 10 + 48) + st;
			t = t / 10;
		}
		ss = "user" + st + ".txt";
		char p[101];
		for (int k=0;k<ss.length();k++) p[k]=ss[k];
		ifstream ifile2(p);
		if (ifile2) {
			int i = 1; 
			int t = 0;
			while (!ifile2.fail()) {
				ifile2.getline(buffer, 256);
				istringstream iss(buffer);
				if (t == 0) {
					t = 1; continue;
				}
				if (buffer == "" || buffer[0] == ' ') continue;
				string st1, st2, st3;
				double st4; int st5;
				iss >> st1 >> st2 >> st3 >> st4 >> st5;
				buy[j][i] = product(st1, st2, st3, st4, st5);
				i++;
			}
			i--;
			bunu[j] = i - 1;
		}
	}
}
void initialize() {
	head = "ID";
	for (int i = 1; i <= 6; i++) head = head + ' ';
	head = head + "名称";
	for (int i = 1; i <= 20; i++) head = head + ' ';
	head = head + "品牌";
	for (int i = 1; i <= 20; i++) head = head + ' ';
	head = head + "价格";
	for (int i = 1; i <= 8; i++) head = head + ' ';
	head = head + "数量";
}


void frist() {
	head1();
	cout << "输入操作："; int x; cin >> x;
	if (x == 3) {
		string st1, st2;
		cout << "输入管理员ID："; cin >> st1;
		cout << "输入管理员密码："; cin >> st2;
		if (st1 == "Admin" && st2 == "admin") {
			suclog(); sta = 2;
		}
		else unsuclog();
		_getch();
	}
	else if (x == 2) {
		string st1, st2;
		cout << "输入用户名："; cin >> st1;
		cout << "输入密码："; cin >> st2;
		int f = 0;
		for (int i = 1; i <= usnu; i++) {
			if (us[i].na() == st1) {
				f = 1; break;
			}
		}
		if (f == 1) {
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			cout << "用户已被注册！"; cout << endl;
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			_getch();
		}
		else {
			usnu++; us[usnu] = user(st1, st2);
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			cout << "注册成功！"; cout << endl;
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			_getch();
		}
	}
	else if (x == 1) {
		string st1, st2;
		cout << "输入用户名："; cin >> st1;
		cout << "输入密码："; cin >> st2;
		int f = 1;
		for (int i = 1; i <= usnu; i++)
			if (us[i].na() == st1 && us[i].se() == st2) {
				suclog(); sta = 3; f = 0; nowus = i;
			}
		if (f == 1) unsuclog();
		_getch();
	}
}
void second() {
	head2();
	cout << "输入操作："; int x; cin >> x;
	if (x == 0) {
		sta = 1; _getch(); return;
	}
	else if (x == 1) {
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		cout << head << endl;
		for (int i = 1; i <= pronu; i++)
			if (pro[i].nu() >= 0) {
				string s = change1(pro[i]);
				cout << s << endl;
			}
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		_getch();
	}
	else if (x == 3) {
		cout << "输入商品ID："; string st; cin >> st;
		for (int i = 1; i <= pronu; i++) {
			if (pro[i]._id() == st) pro[i] = product(pro[i]._id(), pro[i].na(), pro[i].br(), pro[i].va(), -1);
		}
		_getch();
	}
	else if (x == 2) {
		cout << "输入商品名称："; string st1; cin >> st1;
		cout << "输入商品品牌："; string st2; cin >> st2;
		cout << "输入商品价格："; double val; cin >> val;
		cout << "输入商品数量："; int num; cin >> num;
		string st3 = pro[pronu]._id();
		if (pro[pronu].nu() == -1) {
			pro[pronu] = product(st3, st1, st2, val, num);
		}
		else {
			pronu++;
			int len = st3.length();
			int p = int(st3[len - 1]) - 48 + 1;
			st3[len - 1] = char((p % 10) + 48);
			p = p / 10;
			while (p != 0) {
				len--;
				p = int(st3[len - 1]) - 48 + p;
				st3[len - 1] = char((p % 10) + 48);
				p = p / 10;
			}
			pro[pronu] = product(st3, st1, st2, val, num);
		}
		_getch();
	}
	else if (x == 4) {
		cout << "输入商品ID："; string st; cin >> st;
		cout << "输入商品数量："; int num; cin >> num;
		for (int i = 1; i <= pronu; i++)
			if (pro[i]._id() == st) pro[i]=product(pro[i]._id(), pro[i].na(), pro[i].br(), pro[i].va(), num);
		_getch();
	}
	else if (x == 5) {
		cout << "输入商品ID："; string st; cin >> st;
		cout << "输入商品价格："; double val; cin >> val;
		for (int i = 1; i <= pronu; i++)
			if (pro[i]._id() == st) pro[i]= product(pro[i]._id(), pro[i].na(), pro[i].br(),val, pro[i].nu());
		_getch();
	}
	else if (x == 6) {
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		cout << head << endl;
		product a[101];
		product b[101];
		for (int i = 1; i <= sellnu; i++) a[i] = sell[i];
		for (int i = 1; i <= sellnu - 1; i++) {
			int k = i;
			for (int j = i + 1; j <= sellnu; j++) {
				if (a[j]._id() < a[k]._id() || a[j]._id()==a[k]._id() && a[j].va()<a[k].va()) k = j;
			}
			if (k != i) {
				product ttt = a[k]; a[k] = a[i]; a[i] = ttt;
			}
		}
		int n = 0; n++; b[n] = a[n];
		for (int i = 2; i <= sellnu; i++) {
			if (a[i]._id() == a[i - 1]._id() && a[i].va() == a[i - 1].va()) b[n]=product(b[n]._id(), b[n].na(), b[n].br(), b[n].va(), b[n].nu() + a[i].nu());
			else {
				n++; b[n] = a[i];
			}
		}
		for (int i = 1; i <= n; i++) {
			string s = change1(b[i]);
			cout << s << endl;
		}
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		_getch();
	}
}
void third() {
	head3();
	cout << "输入操作："; int x; cin >> x;
	if (x == 1) {
		sta = 1; _getch(); return;
	}
	else if (x == 2) {
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		cout << head << endl;
		for (int i = 1; i <= pronu; i++)
			if (pro[i].nu() >= 0) {
				string s = change1(pro[i]);
				cout << s << endl;
			}
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		_getch();
	}
	else if (x == 3) {
		cout << "输入商品名称："; string st; cin >> st;
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		int f = 0;
		for (int i = 1; i <= pronu; i++)
			if (pro[i].nu() >= 0 && pro[i].na() == st) f = 1;
		if (f == 0) cout << "商品不存在!" << endl;  
		else {
			cout << head << endl;
			for (int i = 1; i <= pronu; i++)
				if (pro[i].nu() >= 0 && pro[i].na() == st) {
					string s = change1(pro[i]);
					cout << s << endl;
					f = 1;
				} 
		}
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		_getch();
	}
	else if (x == 4) {
		cout << "输入商品ID和数量："; string st1; int num; cin >> st1 >> num;
		string st2, st3; int nua = 0; double val;
		for (int i = 1; i <= pronu; i++) {
			if (pro[i]._id() == st1) {
				st2 = pro[i].na(); st3 = pro[i].br();
				nua = pro[i].nu(); val = pro[i].va();
			}
		}
		int f = 0, tt = 0;
		for (int i = 1; i <= bunu[nowus]; i++) {
			if (buy[nowus][i]._id() == st1) {
				tt = i; f = 1; break;
			}
		}
		if (num <= nua) {
			if (f == 0) {
				bunu[nowus]++;
				buy[nowus][bunu[nowus]]=product(st1,st2,st3,val,num);
			}
			else {
				upd(buy[nowus][tt], buy[nowus][tt].nu() + num);
			}
			for (int j = 1; j <= pronu; j++) {
				if (st1 == pro[j]._id()) {
					upd(pro[j], pro[j].nu() - num);
					break;
				}
			}
			for (int i = 1; i <= bunu[nowus] - 1; i++) {
				int k = i;
				for (int j = i + 1; j <= bunu[nowus]; j++) {
					if (buy[nowus][j]._id() < buy[nowus][k]._id()) k = j;
				}
				if (k != i) {
					product ttt = buy[nowus][k]; buy[nowus][k] = buy[nowus][i]; buy[nowus][i] = ttt;
				}
			}
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			cout << "已经加入购物车" << endl;
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			cout << "购物车中有：" << endl;
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			cout << head << endl;
			for (int i = 1; i <= bunu[nowus]; i++) {
				string s = change1(buy[nowus][i]);
				cout << s << endl;
			}
			for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		}
		else errorbuy1();
		_getch();
	}
	else if (x == 5) {
		cout << "输入商品ID和数量："; string st1; int num; cin >> st1 >> num;
		int f = 0, tt = 0;
		for (int i = 1; i <= bunu[nowus]; i++) {
			if (buy[nowus][i]._id() == st1) {
				tt = i; f = 1; break;
			}
		}
		if (f == 0) errorbuy3();
		else {
			if (buy[nowus][tt].nu() >= num) {
				upd(buy[nowus][tt], buy[nowus][tt].nu() - num);
				for (int j = 1; j <= pronu; j++) {
					if (st1 == pro[j]._id()) {
						upd(pro[j], pro[j].nu() + num); break;
					}
				}
				if (buy[nowus][tt].nu() == 0) {
					for (int i = tt; i <= bunu[nowus]-1; i++) buy[nowus][i] = buy[nowus][i + 1];
					bunu[nowus]--;
				}
				for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
				cout << "删除成功！" << endl;
				for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
				cout << "购物车中有：" << endl;
				for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
				cout << head << endl;
				for (int i = 1; i <= bunu[nowus]; i++) {
					string s = change1(buy[nowus][i]);
					cout << s << endl;
				}
				for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
			}
			else
				errorbuy2();
		}
		_getch();
	}
	else if (x == 6) {
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		cout << head << endl;
		for (int i = 1; i <= bunu[nowus]; i++) {
			string s = change1(buy[nowus][i]);
			cout << s << endl;
		}
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		_getch();
	}
	else if (x == 7) {
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		cout << head << endl;
		double sum = 0;
		for (int i = 1; i <= bunu[nowus]; i++) {
			string s = change1(buy[nowus][i]);
			cout << s << endl;
			sum = sum + buy[nowus][i].va() * buy[nowus][i].nu();
		}
		if (us[nowus].is_vip()) sum = sum * DISCOUNT;
		for (int i = 0; i < 10; i++) cout << "*"; cout << endl;
		for (int i = 0; i < 10; i++) cout << ">"; cout << endl;
		if (sum == 0) {
			cout << "购物车为空" << endl;
			for (int i = 0; i < 10; i++) cout << ">"; cout << endl;
		}
		else {
			cout << "一共要付款" << sum << "!  " << "确认付款请按1   取消请按0：";
			int p = 0; cin >> p;
			for (int i = 0; i < 10; i++) cout << ">"; cout << endl;
			if (p == 1) {
				sucbuy();
				for (int i = 1; i <= bunu[nowus]; i++) {
					sellnu++;
					sell[sellnu] = buy[nowus][i];
					buy[nowus][i] = product();
				}
				bunu[nowus] = 0;
				if (us[nowus].add() == "") {
					cout << "请输入收货地址：";
					string stt; cin >> stt;
					us[nowus] = user(us[nowus].na(), us[nowus].se(), us[nowus].is_vip(), stt);
				}
			}
		}
		_getch();
	}
	else if (x == 8) {
		for (int i = 0; i < 10; i++) cout << ">"; cout << endl;
		cout << "一共要付款" << 200 << "!  " << "确认付款请按1   取消请按0：";
		int p = 0; cin >> p;
		for (int i = 0; i < 10; i++) cout << ">"; cout << endl;
		if (p == 1) us[nowus] = user(us[nowus].na(), us[nowus].se(), true);
	}
}
int main() {
	initialize();
	HANDLE s; 
	s= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(s, getcolor(0));//还原为白色字体
	for (int i = 1; i <= 100; i++) bunu[i] = 0;
	ifstream myfile("product.txt");
	ifstream myfile2("user.txt");
	if (myfile && myfile2) up();
	while (true) {
		if (sta == 1) frist();
		else if (sta == 2) second();
		else if (sta == 3) {
			if (us[nowus].is_vip()) {
				HANDLE s;
				s = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(s, getcolor(11));
				cout << "尊贵的VIP用户您好！！" << endl;
			}
			third();
		}
		system("cls");
		update();
	}
}


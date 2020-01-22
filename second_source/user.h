#ifndef __USER__
#define __USER__ 

class user {
public:
	user(string n="", string s="",bool v=false,string a="")
		:name(n), secret(s),vip(v),address(a)
	{}
	string na() const { return name; }
	string se() const { return secret; }
	bool is_vip() { return vip; }
	string add() const { return address; }

private:
	string name;
	string secret;
	bool vip;
	string address;
};




#endif
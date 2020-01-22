#ifndef __PRODUCT__
#define __PRODUCT__ 

class product {
public:
	product(string i="",string n="",string b="",double v=0,int numm=0)
		: id(i),name(n),brand(b),val(v),num(numm)
	{}
	string _id() const { return id; }
	string na() const { return name; }
	string br() const { return brand; }
	double va() const { return val; }
	int nu() const { return num; }
	void upd(int nu) {
		num = nu;
	}

private:
	string id;
	string name;
	string brand;
	double val;
	int num;
};


inline void
upd(product& s, int nu) {
	s = product(s._id(), s.na(), s.br(), s.va(), nu);
}


#endif

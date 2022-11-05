class UnsignedVector
{
	unsigned int* v;
	int num;
	int state = 0;
public:
	UnsignedVector() : v(NULL), num(0), state(0) {}
	UnsignedVector(int n);
	UnsignedVector(int n, unsigned int&);
	UnsignedVector(int n, unsigned int*);
	UnsignedVector(const UnsignedVector& s);
	UnsignedVector& operator=(const UnsignedVector& s);
	~UnsignedVector() {
		cout << " del vec";
		if (v) delete[] v;
	}
	void Output();
	void Input();
	UnsignedVector Add(UnsignedVector& b);

};

UnsignedVector::UnsignedVector(int n) {
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new unsigned int[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
}
UnsignedVector::UnsignedVector(int n, unsigned int& b) {
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new unsigned int[n];
	for (int i = 0; i < n; i++) {
		v[i] = b;
	}
}

UnsignedVector::UnsignedVector(int n, unsigned int* p) {
	if (n <= 0 || p == NULL) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new unsigned int[n];
	for (int i = 0; i < n; i++) {
		v[i] = p[i];
	}
}

UnsignedVector::UnsignedVector(const UnsignedVector& s) {

	num = s.num;
	v = new unsigned int[num];
	state = 0;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}

UnsignedVector& UnsignedVector::operator=(const UnsignedVector& s) {

	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new unsigned int[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
void UnsignedVector::Input() {
	if (num == 0) {
		if (v) delete[] v;
		do {
			cout << "Input size Vec\n";
			cin >> num;
		} while (num <= 0);
		v = new unsigned int[num];
	}
	for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
		cout << " v [ " << i << " ] real img  "; cin >> v[i];
#else 
		double re, im;
		cout << " v [ " << i << " ] real img  "; cin >> re >> im;
		v[i].real(re);
		v[i].imag(im);
#endif    


	}
}

void UnsignedVector::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}

UnsignedVector UnsignedVector::Add(UnsignedVector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		UnsignedVector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return UnsignedVector(0);
}


int mainTask2()
{
	unsigned int a(1), b(2), c;
	cout << a << endl;
	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	UnsignedVector VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << " Input a " << endl;

#if defined(_MSC_VER)
	cin >> a;
#else 
	double re, im;
	cin >> re >> im;
	a.real(re);
	a.imag(im);
#endif    
	cout << a << endl;
	UnsignedVector VecObj2(10, a);
	VecObj2.Output();

	VecObj.Input();
	cout << endl;
	VecObj.Output();
	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();

	return 1;
}
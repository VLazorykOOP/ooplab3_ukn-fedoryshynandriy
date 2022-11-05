#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
using namespace std;

class Paralelogram
{
private:
	double a, b; //сторони паралелограма(b-бічна сторона, а-основа)
	double h; //висота паралелограма, опущена на основу
	unsigned int color;

public:
	Paralelogram() : a(1.0), b(3.0), h(2.0), color(0) {}
	Paralelogram(double ai) : a(ai), b(ai), h(ai), color(0) {}
	Paralelogram(int ic) : a(1.0), b(3.0), h(2.0) { if (ic >= 0) color = ic; else color = 0; }
	Paralelogram(double a, double b, double h, int c) {
		this->a = a;
		this->b = b;
		this->h = h;
		if (c >= 0) color = c;
		else color = 0;
	}
	double getABH() const
	{
		return a, b, h;
	}
	void setABH(double a, double b, double h)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set a \n";
			return;
		}
		this->a = a;

		if (b < 0 || b > 1.e+100)
		{
			cout << " Error set b \n";
			return;
		}
		this->b = b;

		if (h < 0 || h > 1.e+100)
		{
			cout << " Error set h \n";
			return;
		}
		this->h = h;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return a * h;
	}
	double P() {
		return 2 * (a + b);
	}

	void printInfo()
	{
		cout << "\n a= " << a << " b= " << b << " h= " << h << " color = " << color << endl;
		cout << " S= " << S() << " P = " << P() << endl;
	}
};

int mainTask1()
{
	Paralelogram obj;
	obj.printInfo();
	double in_a, in_b, in_h;
	int in_color;
	cout << " Input a, b, h and color of Paralelogram \n"; cin >> in_a >> in_b >> in_h >> in_color;
	Paralelogram obj1(in_a), obj2(in_b), obj3(in_h), obj4(in_color), obj5(in_a, in_b, in_h, in_color);
	obj1.printInfo();
	obj2.printInfo();
	obj3.printInfo();
	obj4.printInfo();
	obj5.printInfo();
	obj.setABH(-5, -6, -4);
	obj.printInfo();
	obj.setABH(5, 6, 4);
	obj.printInfo();
	obj.setABH(2.e100, 4.e100, 3.e100);
	obj.printInfo();
	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
	cout << " End testing \n";
	return 0;

}


// Ключове слово static 

class foo
{
private:
	static int count; // загальне поле всім об'єктів
	// (У сенсі "оголошення")
public:
	foo() { incObj(); } // інкрементування під час створення об'єкта
	static int incObj() { return ++count; }
	int getcount() { return count; }
};
int  foo::count = 0;
// Ключове слово static ставиться перед типом способу.В основному використовуються
//для роботи зі статичними полями класу.

/*
ЗАВДАННЯ 2
Створити тип даних - клас вектор, який має вказівник на unsigned int, число елементів і змінну стану. У класі визначити
o	 конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
o	конструктор копій та операцію присвоєння; // !!!
o	деструктор звільняє пам'ять;
o	визначити функції друку, додавання;
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/

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
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; return; }
	num = n;
	v = new unsigned int[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
}
UnsignedVector::UnsignedVector(int n, unsigned int& b) {
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; return; }
	num = n;
	v = new unsigned int[n];
	for (int i = 0; i < n; i++) {
		v[i] = b;
	}
}

UnsignedVector::UnsignedVector(int n, unsigned int* p) {
	if (n <= 0 || p == NULL) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; return; }
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
		cout << " v [ " << i << " ] "; cin >> v[i];
#else 
		double re, im;
		cout << " v [ " << i << " ]"; cin >> re >> im;
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
/*  Task 3
Створити клас матриця. Даний клас містить вказівник на int, розміри рядків і стовпців та стан помилки. У класі визначити
o конструктор без параметрів( виділяє місце для матриці 3 на 3 елемента та інінціалізує його в нуль);
o конструктор з одним параметром – розмір n матриці (виділяє місце n на n та інінціалізує матрицю значенням нуль); 
o конструктор із трьома розміри матриці (n , m) та значення ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням третього аргументу - value); 
o конструктор копій та операцію присвоєння; // !!! o деструктор звільняє пам'ять. o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
o функцію яка одержує деякий елемент матриці за індексами i та j;
o визначити функції друку, додавання, множення, віднімання, які здійснюють ці арифметичні операції з даними цього класу;
o визначити функції порівняння: більше, менше або рівно, які повертають true або false. 
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі матриці. 
Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу..
*/

enum STATE {
	OK, BAD_INIT, BAD_DIV
};

class Vec2
{
	double  x, y;
	int state;
	static int count;
public:
	Vec2() : x(0), y(0) {
		state = OK; count++;
	}   // 	 конструктор без параметрів
	Vec2(double iv) : x(iv), y(iv) {
		state = OK; count++;
	}
	Vec2(double ix, double iy);
	Vec2(double* v);
	~Vec2() {
		count--;
		cout << " state Vec " << state;
		cout << " Vec delete \n";
	}
	Vec2(const Vec2&);
	Vec2 Add(Vec2& d);
	Vec2 Sub(Vec2& d);
	Vec2 Mul(double d);
	Vec2 Div(double d);
	void Input();   //  !!! Без первантаження операцій    
	void Output();  //  !!! Без первантаження операцій
	bool CompLessAll(Vec2& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів Vec2 ";
		return count;
	}
	int getState() { return state; }
};
int Vec2::count = 0;
Vec2::Vec2(double ix, double iy) {
	x = ix; y = iy;
	state = OK;
	count++;
}
Vec2::Vec2(const Vec2& s) {
	if (this == &s) return;
	x = s.x; y = s.y; state = OK;
	count++;
};
Vec2::Vec2(double* v) {
	if (v == nullptr) {
		state = BAD_INIT; x = 0; y = 0;
	}
	else {
		x = v[0]; y = v[1];
		state = OK;
	}
	count++;
}
void Vec2::Input() {
	cout << " Input  x y ";
	cin >> x >> y;
}
void Vec2::Output() {
	cout << " x =" << x << " y = " << y << " state  " << state << endl;
}

Vec2 Vec2::Add(Vec2& s) {
	Vec2 tmp;
	tmp.x = x + s.x;
	tmp.y = y + s.y;
	return tmp;
}

Vec2 Vec2::Sub(Vec2& s) {
	Vec2 tmp;
	tmp.x = x - s.x;
	tmp.y = y - s.y;
	return tmp;
}
Vec2 Vec2::Div(double d) {
	Vec2 tmp;
	if (fabs(d) < 1.e-25) {
		tmp.state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	tmp.x = x / d;
	tmp.y = y / d;
	return tmp;
}
Vec2 Vec2::Mul(double d) {
	Vec2 tmp;
	tmp.x = x * d;
	tmp.y = y * d;
	return tmp;
}

bool Vec2::CompLessAll(Vec2& s) {

	if (x < s.x && y < s.y) return true;
	return false;
}

int mainTask3()
{
#if !defined(CODING_VS_CODE)
	setlocale(LC_CTYPE, "ukr");
	cout << "Тестування створенного класу \n";
	cout << "Тестування конструкторiв \n"; 
#else 
	cout << "Testing create class  \n";
	cout << "Testing crot's  \n";
#endif
	Vec2 ObjCDef;
	ObjCDef.Output();
	Vec2 ObjP1(10.0);
	ObjP1.Output();
	double  a = 1.0, b = 2.0;
	Vec2  ObjP2(a, b);
	ObjP2.Output();
	Vec2 ObjCopy(ObjP2);
	double* v = nullptr, v2[] = { 1.2, 3.3 };
	Vec2  ObjP3(v2);
	if (ObjP3.getState() != OK) cout << " ObjP3  x= 0  y= 0  \n";
	Vec2  ObjP4(v2);
	if (ObjP4.getState() != OK) cout << " ObjP4 x= 0  y= 0  \n";
#if !defined(CODING_VS_CODE)
	cout << " Кiлькiсть створених об'єктiв Vec2 " << Vec2::getCount() << endl;
	cout << "Тестування введення \n";
	ObjCDef.Input();
	cout << "Тестування функцiй \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Кiлькiсть створених об'єктiв Vec2 до Sub " << Vec2::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n Кiлькiсть створених об'єктiв Vec2 пiсля Sub " << Vec2::getCount() << endl;
#else 
	cout << "Testing input \n";
	ObjCDef.Input();
	cout << "Testing gunction \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Counts create objects Vec2 before  Sub " << Vec2::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n  Counts create objects Vec2 after Sub  " << Vec2::getCount() << endl;
#endif

	ObjCDef.Output();
	ObjCDef = ObjCDef.Mul(5);
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(1.3);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();

	ObjCDef = ObjCDef.Div(0.0);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	cout << "ObjCopy state " << ObjCopy.getState() << endl;
	if (ObjCopy.CompLessAll(ObjCDef))  cout << "ObjCopy less ObjDef  " << endl;

	
#if !defined(CODING_VS_CODE)
	cout << "Завершення  тестування  \n";
#else 
	cout << "Completion of testing  \n";
#endif
	return 1;

}


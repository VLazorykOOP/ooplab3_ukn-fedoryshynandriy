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
o конструктор копій та операцію присвоєння; // !!!
o деструктор звільняє пам'ять. o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
o функцію яка одержує деякий елемент матриці за індексами i та j;
o визначити функції друку, додавання, множення, віднімання, які здійснюють ці арифметичні операції з даними цього класу;
o визначити функції порівняння: більше, менше або рівно, які повертають true або false. 
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі матриці. 
Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу..
*/

#include <iostream>
using namespace std;

//клас Матриця
template <typename T>
class MATRIX
{
private:
	T** M; // матриця
	int m; // к-сть рядків
	int n;  // к-сть стовпців
	
public:
	// конструктори
	//конструктор без параметрів
	MATRIX() 
	{
		n = m = 0;
		M = nullptr; 
	}
	//конструктор з одним параметром
	MATRIX( int _n)
	{
		n = _n;
		m =n = _n;
		M = nullptr;
	}

	// конструктор з трьома параметрами
	MATRIX(int _m, int _n)
	{
		m = _m;
		n = _n;

		// Виділити пам'ять для матриці
		// Виділити пам'ять для масиву покажчиків
		M = (T**) new T * [m]; // к-сть рядків, к-сть покажчиків

		// Виділити пам'ять для кожного покажчика
		for (int i = 0; i < m; i++)
			M[i] = (T*)new T[n];

		// Заповнити масив M нулями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
	}

	// Конструктор копіювання
	MATRIX(const MATRIX& _M)
	{
		// Створюється новий об'єкт для якого виділяється пам'ять
		// Копіювання даних *this <= _M
		m = _M.m;
		n = _M.n;

		// Виділити пам'ять для M
		M = (T**) new T * [m]; // к-сть рядків, к-сть покажчиків
		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// заповнити значеннями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = _M.M[i][j];
	}

	// методи доступу
	T GetMij(int i, int j)
	{
		if ((m > 0) && (n > 0))
			return M[i][j];
		else
			return 0;
	}

	void SetMij(int i, int j, T value)
	{
		if ((i < 0) || (i >= m))
			return;
		if ((j < 0) || (j >= n))
			return;
		M[i][j] = value;
	}

	// метод виводу матриці
	void Print(const char* ObjName)
	{
		cout << "Object: " << ObjName << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << M[i][j] << "\t";
			cout << endl;
		}
		cout << "---------------------" << endl << endl;
	}

	// оператор копіювання
	MATRIX operator=(const MATRIX& _M)
	{
		if (n > 0)
		{
			// звільнення пам'яті, виділеної раніше для об'єкту *this
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
		{
			delete[] M;
		}

		// Копіювання даних M <= _M
		m = _M.m;
		n = _M.n;

		// Виділити пам'ять для M знову
		M = (T**) new T * [m];     
		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// заповнити значеннями
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = _M.M[i][j];
		return *this;
	}

	// деструктор
	~MATRIX()
	{
		if (n > 0)
		{
			// звільнити попередньо виділену пам'ять для кожного рядка
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
			delete[] M;
	}
};

int mainTask3()
{
	system("chcp 1251");
	cout << " Task 3\n" <<
		"Створити клас матриця.Даний клас містить вказівник на int, розміри рядків і стовпців та стан помилки.У класі визначити" <<endl<<
		"- конструктор без параметрів(виділяє місце для матриці 3 на 3 елемента та інінціалізує його в нуль);" << endl <<
		"- конструктор з одним параметром – розмір n матриці(виділяє місце n на n та інінціалізує матрицю значенням нуль);" << endl <<
		"- конструктор із трьома розміри матриці(n, m) та значення ініціалізації value" << endl <<
		"(виділяє місце перші аргументи та інінціалізує значенням третього аргументу - value);" << endl <<
		"- конструктор копій та операцію присвоєння; // !!!" << endl <<
		"- деструктор звільняє память."<<endl<<
		"- визначити функцію, яка присвоює елементу масиву деяке значення(параметр за замовчуванням); " << endl <<
		"- функцію яка одержує деякий елемент матриці за індексами i та j;" << endl <<
		"- визначити функції друку, додавання, множення, віднімання, які здійснюють ці арифметичні операції з даними цього класу;\n" << endl<<
		"- визначити функції порівняння : більше, менше або рівно, які повертають true або false." << endl <<
		"У змінну стани встановлювати код помилки, коли не вистачає памяті, виходить за межі матриці. " << endl <<
		"Передбачити можливість підрахунку числа обєктів даного типу. Написати програму тестування всіх можливостей цього класу.." << endl<<endl;

	MATRIX<int> M(3,3);
	cout << endl;
	M.Print("Створити матрицю");

	// Заповнити матрицю значеннями 
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			M.SetMij(i, j, i + j);

	M.Print("Заповнення: елемент= i+j");

	MATRIX<int> M2 = M; // виклик конструктора копіювання
	M2.Print("Конструктор копіювання");

	return 0;
}


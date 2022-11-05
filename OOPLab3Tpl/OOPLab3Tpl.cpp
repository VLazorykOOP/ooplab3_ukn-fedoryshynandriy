// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
using namespace std;

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
int main()
{
    std::cout << " Lab 3!\n";

    int conv;
    int task;
    ask:
    cout<<endl << "What task to do ? " << endl;
    cin >> task;
    switch (task) {
    case 1:
        cout << "Task 1"<<endl;
        mainTask1();
        goto ask;
        break;
       
    case 2:
        cout << "Task 2" << endl;
        mainTask2();
        goto ask;
        break;
       
    case 3:
        cout << "Task 3" << endl;
        mainTask3();
        goto ask;
        break;
        
        
    }

}


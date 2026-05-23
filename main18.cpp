#include <iostream>
#include "h18.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>
#ifdef _WIN64
#include <windows.h>
#endif
    
int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    // TreeOriginal Tree1;
    do {
        cout << "1. TheFun1" << endl;
        cout << "2. TheFun3" << endl;
        cout << "3. TreeWork17" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                TheFun1();
                break;
            }
            case 2: {
                TheFun3();
                break;
            }
            case 3: {
                TheFun12();
                break;
            }
            case 0: {
                cout << "Выход из программы\n";
                break;
            }
            default:
                cout << "Введено неверное значение\n";
        }
    } 
    while (choice != 0);
    return 0;
}
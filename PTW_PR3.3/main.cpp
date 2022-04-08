#include <iostream>
#include <string>
#include <iomanip>
#include "Student.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    string lastName;
    
    int student = 3;
    cout << "Кількість студентів: ";
    Student* s = new Student[student];
    
    s[0].name = "Шевченко";
    s[1].name = "Петренко";
    s[2].name = "Іваненко";
    
    s[0].physics = 3;
    s[1].physics = 5;
    s[2].physics = 4;
    
    s[0].math = 4;
    s[1].math = 4;
    s[2].math = 4;
    
    s[0].programming = 4;
    s[1].programming = 5;
    s[2].programming = 4;

    int ozinka1, ozinka2, ozinka3;
    int key;
    do {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - показати список студентів " << endl;
        cout << " [2] - додати студента " << endl;
        cout << " [3] - вилучити студента " << endl;
        cout << " [4] - редагувати інформацію студента " << endl;
        cout << " [5] - сортувати список за середнім балом " << endl;
        cout << " [6] - сортувати список за прізвищем " << endl;
        cout << " [7] - сортувати список за оцінкою з фізики " << endl;
        cout << " [8] - сортувати список за оцінкою з математики " << endl;
        cout << " [9] - сортувати список за оцінкою з програмування " << endl;
        cout << " [0] - вихід та завершення програми " << endl;
        cout << "Введіть значеня: "; cin >> key;
        cout << endl;
        
        switch (key) {
        case 1:
            {
                Print(s, student);
                break;
            }
        case 2:
            {
                Add(s, student);
                ++student;
                break;
            }
        case 3:
            {
                cout << "Введіть ключі пошуку для видалення:" << endl;
                cout << " Прізвище: "; cin >> lastName;
                cout << "Оцінка з фізики: ";
                cin >> ozinka1;
                cout << "Оцінка з математики: ";
                cin >> ozinka2;
                cout << "Оцінка з програмування: ";
                cin >> ozinka3;
                int index = binSearch(s, student, lastName, ozinka1, ozinka2, ozinka3);
                if(index != -1)
                {
                    Delete(s, student, index);
                    cout << endl;
                    Print(s, student);
                }
                else if(index == -1)
                {
                    Eror();
                }
                break;
            }
        case 4:
            {
                cout << "Введіть ключі пошуку для редагування:" << endl;
                cout << " Прізвище: "; cin >> lastName;
                cout << "Оцінка з фізики: ";
                cin >> ozinka1;
                cout << "Оцінка з математики: ";
                cin >> ozinka2;
                cout << "Оцінка з програмування: ";
                cin >> ozinka3;
                int index = binSearch(s, student, lastName, ozinka1, ozinka2, ozinka3);
                if(index != -1)
                {
                    Change(s, index);
                }
                else if(index == -1)
                {
                    Eror();
                }
                break;
            }
           
        case 5:
            {
                SortAverage(s, student);
                break;
            }
        case 6:
            {
                SortName(s, student);
                break;
            }
        case 7:
            {
                SortPhysics(s, student);
                break;
            }
        case 8:
            {
                SortMath(s, student);
                break;
            }
        case 9:
            {
                SortProgramming(s, student);
                break;
            }
        
        case 0:
            break;
        }
    } while (key != 0);
    return 0;
}

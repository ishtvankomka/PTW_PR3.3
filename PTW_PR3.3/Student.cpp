#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>
#include "Student.hpp"
using namespace std;

void Print(Student* s, int student)
{
    cout << "===========================================================" << endl;
    cout << "| № |    Прiзвище   | Фiзика | Математика | Програмування |" << endl;
    cout << "===========================================================" << endl;
    for (int i = 0; i < student; i++) {
        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(22) << left << s[i].name
            << "| " << setw(7) << right << s[i].physics
            << "| " << setw(11) << right << s[i].math
            << "| " << setw(11) << right << s[i].programming;
        cout << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

int binSearch(Student* s, const int N, const string prizv, const int ozinka1, const int ozinka2, const int ozinka3)
{
    int m = 0, student = N;
    do {
        if (s[m].name == prizv && s[m].physics == ozinka1 && s[m].math == ozinka2 && s[m].programming == ozinka3)
        {
            return m;
        }
        else
        {
            m++;
        }
    } while (m < student);
    return -1;
}

void Delete(Student* &s, int &student, int index)
{
    Student* tmp = new Student[student - 1];
    for (int  i = 0; i < student; i++)
    {
        if(i >= index && i < student - 1)
        {
            tmp[i].name = s[i+1].name;
            tmp[i].physics = s[i+1].physics;
            tmp[i].math = s[i+1].math;
            tmp[i].programming = s[i+1].programming;
        }
        if(i < index)
        {
            tmp[i].name = s[i].name;
            tmp[i].physics = s[i].physics;
            tmp[i].math = s[i].math;
            tmp[i].programming = s[i].programming;
        }
    }
    s = {0};
    s = new Student[student - 1]();
    for (int i = 0; i < student - 1; i++)
    {
        s[i].name = tmp[i].name;
        s[i].physics = tmp[i].physics;
        s[i].math = tmp[i].math;
        s[i].programming = tmp[i].programming;
    }
    student--;
}

void Eror()
{
    cout << "Введено неправильні дані! " << endl;
}

void Change(Student* s, int index)
{
    int key;
    do{
        cout << "Зміна даних " << endl;
        cout << " [1] - прізвище " << endl;
        cout << " [2] - оцінка з фізики " << endl;
        cout << " [3] - оцінка з математики " << endl;
        cout << " [4] - оцінка з програмування " << endl;
        cout << " [0] - завершити редагування " << endl;
        cout << "Введіть значеня: "; cin >> key;
        int ozinka;
        switch(key) {
            case 1:
            {
                string name;
                cout << "Введіть нові дані: "; cin >> name;
                s[index].name = name;
                break;
            }
            case 2:
            {
                ozinka = 0;
                do{
                    cout << "Введіть нові дані: ";
                    cin >> ozinka;
                    if (ozinka < 1 || ozinka > 5)
                    {
                        Eror();
                    }
                } while(ozinka < 1 || ozinka > 5);
                s[index].physics = ozinka;
                break;
            }
            case 3:
            {
                ozinka = 0;
                do{
                    cout << "Введіть нові дані: ";
                    cin >> ozinka;
                    if (ozinka < 1 || ozinka > 5)
                    {
                        Eror();
                    }
                } while(ozinka < 1 || ozinka > 5);
                s[index].math = ozinka;
                break;
            }
            case 4:
            {
                ozinka = 0;
                do{
                    cout << "Введіть нові дані: ";
                    cin >> ozinka;
                    if (ozinka < 1 || ozinka > 5)
                    {
                        Eror();
                    }
                } while(ozinka < 1 || ozinka > 5);
                s[index].programming = ozinka;
                break;
            }
            case 0:
            {
                break;
            }
        }
    }while(key != 0);
}

void Add(Student* s, int students) {
    int i = students;
        cout << "Прiзвище: ";
        cin >> s[i].name;

        int ozinka = -1;
        do{
            cout << "Оцiнка з фiзики: ";
            cin >> ozinka;
            if (ozinka < 1 || ozinka > 5)
            {
                Eror();
            }
        } while(ozinka < 1 || ozinka > 5);
        s[i].physics = ozinka;
        
        ozinka = -1;
        do{
            cout << "Оцiнка з математики: ";
            cin >> ozinka;
            if (ozinka < 1 || ozinka > 5)
            {
                Eror();
            }
        } while(ozinka < 1 || ozinka > 5);
        s[i].math = ozinka;
        
        ozinka = -1;
        do{
            cout << "Оцiнка з програмування: ";
            cin >> ozinka;
            if (ozinka < 1 || ozinka > 5)
            {
                Eror();
            }
        } while(ozinka < 1 || ozinka > 5);
        s[i].programming = ozinka;
}

void SortAverage(Student* s, const int student)
{
    Student tmp;
     for (int i0 = 0; i0 < student - 1; i0++)
         for (int i1 = 0; i1 < student - i0 - 1; i1++)
             if (getAverage(s, i1) < getAverage(s, i1 + 1))
             {
                 tmp = s[i1];
                 s[i1] = s[i1 + 1];
                 s[i1 + 1] = tmp;
             }
}

double getAverage(Student* s, const int index)
{
    double a = s[index].physics + s[index].math + s[index].programming;
    a = a / 3;
    return a;
}

void SortName(Student* s, const int student)
{
    Student tmp;
     for (int i0 = 0; i0 < student - 1; i0++)
         for (int i1 = 0; i1 < student - i0 - 1; i1++)
             if (s[i1].name > s[i1 + 1].name)
             {
                 tmp = s[i1];
                 s[i1] = s[i1 + 1];
                 s[i1 + 1] = tmp;
             }
}

void SortPhysics(Student* s, const int student)
{
    Student tmp;
     for (int i0 = 0; i0 < student - 1; i0++)
         for (int i1 = 0; i1 < student - i0 - 1; i1++)
             if (s[i1].physics < s[i1 + 1].physics)
             {
                 tmp = s[i1];
                 s[i1] = s[i1 + 1];
                 s[i1 + 1] = tmp;
             }
}

void SortMath(Student* s, const int student)
{
    Student tmp;
     for (int i0 = 0; i0 < student - 1; i0++)
         for (int i1 = 0; i1 < student - i0 - 1; i1++)
             if (s[i1].math < s[i1 + 1].math)
             {
                 tmp = s[i1];
                 s[i1] = s[i1 + 1];
                 s[i1 + 1] = tmp;
             }
}

void SortProgramming(Student* s, const int student)
{
    Student tmp;
     for (int i0 = 0; i0 < student - 1; i0++)
         for (int i1 = 0; i1 < student - i0 - 1; i1++)
             if (s[i1].programming < s[i1 + 1].programming)
             {
                 tmp = s[i1];
                 s[i1] = s[i1 + 1];
                 s[i1 + 1] = tmp;
             }
}


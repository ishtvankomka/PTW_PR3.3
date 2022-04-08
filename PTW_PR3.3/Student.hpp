#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int physics;
    int math;
    int programming;
};

void Print(Student*, int);
void Add(Student*, int); 
void Delete(Student* &, int&, int);
void Change(Student*, int);

void SortAverage(Student*, const int);
double getAverage(Student*, const int);
void SortName(Student*, const int);
void SortPhysics(Student*, const int);
void SortMath(Student*, const int);
void SortProgramming(Student*, const int);

int binSearch(Student*, const int, const string, const int, const int, const int);
void Eror();

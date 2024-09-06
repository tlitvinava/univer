#ifndef STUDENICHNIK2_H
#define STUDENICHNIK2_H
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Studenichnik2.h"

typedef long double ld;
typedef double d;


void title(int var);
bool check_string(const std::string& str);
short check_choose();
d check_mark();
ld average(Studenichnik stud);
void sort(Studenichnik*& arr, int n);
void add(Studenichnik& sh, int n);
void show(const Studenichnik& arr, int i);
void add_more(Studenichnik* array, ll& n);
void delete1(Studenichnik* array, ll& n, int index);
void change(Studenichnik* array, ll& n, int index);

#endif
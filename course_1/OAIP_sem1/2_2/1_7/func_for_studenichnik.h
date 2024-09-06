#ifndef STUDENICHNIK1_H
#define STUDENICHNIK1_H

#include <string>
#include"Studenichnik1.h"

void title(int var);
bool check_string(const std::string& str);
short check_choose();
void find_element(Studenichnik* array, int n, const std::string& param);
bool is_double(std::string str);
void add(Studenichnik& sh, int i);
void show(const Studenichnik& arr, int i);
void previous_enter(Studenichnik* array, int n);
bool check(Studenichnik stud, std::string param, int choice);
void sort(Studenichnik*& arr, int n);
void add_more(Studenichnik* array, int& n);
void find_element(Studenichnik* array, int n, const std::string& param);
void delete_or_change(Studenichnik* array, int& n, int index);

#endif

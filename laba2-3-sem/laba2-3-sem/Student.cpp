#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Function.h"

Student::Student()
{
	Human initHuman;
	this->human = initHuman;
	this->scholarship = 10000;
	this->group = "ПИ11";
	count_stud++;
}
Student::Student(int scholarship)
{
	this->human = human;
	this->scholarship = 10000;
	this->group = "ПИ11";
	count_stud++;
}
Student::Student(class Human human, int scholarship, string group)
{
	this->human = human;
	this->scholarship = scholarship;
	this->group = group;
	count_stud++;
}
Student::~Student()
{

}

Student Student::operator + (Student stud)
{
	return Student(this->scholarship + stud.scholarship);
}

Student& Student::operator ++ ()
{
	this->human.setAge((this->human.getAge()) + 1);
	return *this;
}

Student Student::operator ++ (int)
{
	Student stud = *this;
	++* this;
	return stud;
}


void InputStud(Student& stud)
{
	system("cls");
	string first, mid, last, num, ser;
	cout << "Введите фамилию студента: ";
	last = write_str(29);
	cout << "Введите имя студента: ";
	first = write_str(29);
	cout << "Введите отчество студента: ";
	mid = write_str(29);
	stud.human.setFIO(first, mid, last);
	cout << "Введите возраст: ";
	stud.human.setAge(write_num(125));
	cout << "Введите номер паспорта: ";
	num = write_pd(4);
	cout << "Введите серию паспорта: ";
	ser = write_pd(6);
	stud.human.setPD(num, ser);
	cout << "Введите размер стипендии: ";
	stud.scholarship = write_num(100000);
	cout << "Введите номер группы: ";
	cin >> stud.group;
	stud.count_stud++;
}
void Student::OutputStud(int i)
{
	cout << to_string(i + 1) + "-й человек: " << endl;
	cout << "---------------------------------" << endl;
	cout << "ФИО: " + this->human.getFIO().getLast() + " " + this->human.getFIO().getFirst() + " " + this->human.getFIO().getMid() << endl;
	cout << "Паспортные данные: " + this->human.getPD().getNum() + " " + this->human.getPD().getSer() << endl;
	cout << "Возраст: " + to_string(this->human.getAge()) << endl;
	cout << "Студент группы: " + this->group << endl;
	cout << "Стипендия: " + to_string(this->scholarship) << endl;
	cout << "---------------------------------\n\n" << endl;
}

void Student::ChangeInfo()
{
	int inp;
	inp = write_num(6);
	if (inp == 6)
		return;
	else if (inp == 1)
	{
		string first, mid, last;
		cout << "Введите фамилию студента: ";
		last = write_str(29);
		cout << "Введите имя студента: ";
		first = write_str(29);
		cout << "Введите отчество студента: ";
		mid = write_str(29);
		this->human.setFIO(first, mid, last);
	}
	else if (inp == 2)
	{
		string num, ser;
		cout << "Введите номер паспорта: ";
		num = write_pd(4);
		cout << "Введите серию паспорта: ";
		ser = write_pd(6);
		this->human.setPD(num, ser);
	}
	else if (inp == 3)
	{
		cout << "Введите возраст: ";
		this->human.setAge(write_num(125));
	}
	else if (inp == 4)
	{
		cout << "Введите номер группы: ";
		cin >> this->group;
	}
	else if (inp == 5)
	{
		cout << "Введите размер стипендии: ";
		this->scholarship = write_num(100000);
	}
}

void Student::stud_analysis(int* stud_sum_age, int* stud_sum_scholarship,
				   int *count_students, int* max_scholarship, int* min_scholarship)
{
	system("cls");
	if (!*count_students)
	{
		*max_scholarship = this->scholarship;
		*min_scholarship = this->scholarship;
	}
	else if (this->scholarship > *max_scholarship)
	{
		*max_scholarship = this->scholarship;
	}
	else if (this->scholarship < *min_scholarship)
	{
		*min_scholarship = this->scholarship;
	}
	*stud_sum_scholarship += this->scholarship;
	*count_students += 1;
	*stud_sum_age += this->human.getAge();
}

int Student::GetCount()
{
	return count_stud;
}

void Student::SetCount(int count)
{
	count_stud = count;
}

int Student::count_stud = 0;
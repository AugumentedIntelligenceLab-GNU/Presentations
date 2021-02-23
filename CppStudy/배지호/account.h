#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Account         //���� Ŭ����
{
public:
	Account(int id, char name[], int money);
	~Account();

	int compare_id(int id);     // id�� ���� ���̵� �� 

	void add_money(int money);   // money ����
	void sub_money(int money);   // money ����
	void show_cus() const;        // ���� Ŭ����

private:

	int my_id;							
	char *my_name = new char[20];    
	int my_money;

};



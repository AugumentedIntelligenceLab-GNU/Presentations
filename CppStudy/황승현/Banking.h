#pragma once

#include <iostream>
using namespace std;

void ShowMenu();
void OpenAccount();
void Deposit();
void Withdrawal();
void ShowAllAcc();

class Account {
private:
	int accId;
	char* cusName;
	int balance;

public:
	// å ����
	Account(int ID, int money, char* name) : accId(ID), balance(money) { // �̰� ���� ��������? ����Ʈ�ε�
		cusName = new char[strlen(name) + 1]; // �����Ҵ�
	}

	void Init();
	int GetId();
	char* GetName();
	int GetBalance();
	//bool SetId(int id);
	//bool SetName(char* name[]);
	//bool SetMoney();

	//void OpenAcc();
	void DepositAcc(int money);
	void WithdrawalAcc(int money);
};
#pragma once
#include"account.h"

void show_menu();				//�޴����
int find_id(Account* customer[], int account_count, int id);	//id �˻�
void make_account(Account* customer[], int& account_count);     //���� ����
void deposit(Account* customer[], int& account_count);			//�Ա�
void withdraw(Account* customer[], int& account_count);			//���
void show_all_customer(Account* customer[], int& account_count); //�������� ��ü ���
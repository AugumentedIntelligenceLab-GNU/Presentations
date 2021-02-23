#include "control.h"

void show_menu()
{
	cout << "-------------Menu------------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

int find_id(Account* customer[], int account_count, int id)
{
	for (int i = 0; i < account_count; i++)
	{
		if (customer[i]->compare_id(id) == 1)    // compare_id(id) id���� Ŭ������ id���� ��ġ�ϸ� 1��ȯ
			return i;
	}
	cout << "�ش� id�� �����ϴ�." << endl;

	return -1;
}

void make_account(Account* customer[], int& account_count)
{
	int id;
	char name[20];
	int money = 0;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;

	customer[account_count] = new Account(id, name, money);
	account_count++;

	cout << "���°��� �Ϸ�" << endl;

	return;
}

void deposit(Account* customer[], int& account_count)
{
	int id;
	int money = 0;
	int customer_index;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	customer_index = find_id(customer, account_count, id);	//�Է� id�� �ش��ϴ� Ŭ������ �����͹迭 �ε��� ��ȯ

	if (customer_index == -1)								// ��ġ�ϴ� id�� ��ã������
		return;

	customer[customer_index]->add_money(money);

	cout << "�Ա� �Ϸ�" << endl;

	return;
}

void withdraw(Account* customer[], int& account_count)
{
	int id;
	int money = 0;
	int customer_index;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	customer_index = find_id(customer, account_count, id);    //�Է� id�� �ش��ϴ� Ŭ������ �����͹迭 �ε��� ��ȯ

	if (customer_index == -1)                                 // ��ġ�ϴ� id�� ��ã������
		return;

	customer[customer_index]->add_money();

	cout << "��� �Ϸ�" << endl;

	return;
}

void show_all_customer(Account* customer[], int& account_count)
{
	cout << endl;
	cout << "[��������]" << endl;

	for (int i = 0; i < account_count; i++)
	{
		customer[i]->show_cus();
	}

	cout << endl;

	return;
}
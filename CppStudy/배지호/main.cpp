#include "account.h"
#include "control.h"

int main()
{
	int n;
	int account_count = 0;
	
	Account* customer[100];

	while (1) {
		show_menu();      //�޴� ���
		cout << "����: ";
		cin >> n;

		switch (n)
		{
		case 1:
			make_account(customer, account_count);   //���� ����
			break;
		case 2:
			deposit(customer, account_count);    // �Ա�
			break;
		case 3:
			withdraw(customer, account_count);  //��� 
			break;
		case 4:
			show_all_customer(customer, account_count); //�������� ��ü���
			break;
		case 5:
			cout << "���α׷� ����" << endl;
			for (int i = 0; i < account_count; i++)     //�޸� ����
				delete customer[i];
			return 0;
		default:
			cout << "�ش� ��ȣ ����" << endl;
			return -1;
		}
	}

	return 0;
}







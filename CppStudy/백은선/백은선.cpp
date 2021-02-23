#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define NAME_LEN 20

using namespace std;

void ShowMenu(void);         //�޴����
void MakeAccount(void);         //���°���
void DepositMoney(int money);      //�Ա�
void WithdrawMoney(int money);      //���
void AllAccount(void);      //�������� ��ü ���

class Account
{
private:
    int accID;      //���¹�ȣ
    char* accName;   //���̸�
    int accMoney;   //�ܾ�

public:
    Account(int id, char* name, int money) : accID(id), accMoney(��) //������
    {
        accName = new char[strlen(name) + 1];
        strcpy(accName, name);
    }

    int GetAccID() { return accID; }

    void Deposit(int Money)
    {
        accMoney += Money;
    }

    int Withdraw(int Money)
    {
        if (accMoney < Money)
            return 0;

        accMoney -= Money;
        return Money;
    }

    void ShowAccInfo()
    {
        cout << "����ID: " << accID << endl;
        cout << "�̸�: " << accName << endl;
        cout << "�ܾ�: " << accMoney << endl;
    }

    ~Account()   //�Ҹ���
    {
        delete[]accName;
    }
};

Account* accArr[100];   //���� ������ �迭
int accNum = 0;         //���� ����



int main(void) {

    int choice, money;

    while (true) {
        ShowMenu();
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:   //���� ����
            MakeAccount();
            break;
        case 2:   //�Ա�
            cout << "�Ա��� �ݾ�: ";
            cin >> money;
            cout << endl;
            DepositMoney(��);
            break;
        case 3:   //���
            cout << "����� �ݾ�: ";
            cin >> money;
            cout << endl;
            WithdrawMoney(��);
            break;
        case 4:   //��ü ���
            AllAccount();
            break;
        case 5:
            for (int i = 0; i < accNum; i++)   //�����͹迭�� �����Ҵ������Ƿ�
                delete accArr[i];
            return 0;
        default:
            cout << "�߸��� ��ȣ �Է�" << endl << endl;
        }

    }
    return 0;
}

void ShowMenu(void) {

    cout << "-------Menu-------" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
    cout << "-----------------" << endl << endl;
}


void MakeAccount(void) {   //���°���

    int id;
    char name[NAME_LEN];
    int money;

    cout << "[ ���� ���� ]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> money;
    cout << endl;

    accArr[accNum++] = new Account(id, name, money);   //�����ڿ� ������ ����
}


void DepositMoney(int money) {      //�Ա�

    int id;
    cout << "[ ��  �� ]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "�Աݾ�: " << money << endl;;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(��);
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }

    cout << "��ȿ�������� ID �Դϴ�." << endl << endl;
}


void WithdrawMoney(int money) {      //���
    int id;
    cout << "[ ��  �� ]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "��ݾ�: " << money << endl;;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {

            if (accArr[i]->Withdraw(��) == 0) {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }

    cout << "��ȿ�������� ID �Դϴ�." << endl << endl;
}


void AllAccount(void) {      //�������� ��ü ���
    cout << "[ �������� ��ü ��� ]" << endl;

    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }


}
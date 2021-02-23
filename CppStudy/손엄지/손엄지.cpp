#include <iostream>
#include <cstring>
using namespace std;

char all_ID[];
int idNum = 1;

class  Account {
private:
    int ID;
    char* Name;
    int Money;
public:
    Account(int newID, char* newName, int newMoney) : ID(newID), Money(newMoney) {
        Name = new char[strlen(newName) + 1];
        strcpy(Name, newName);
    }

    // ���� ����
    void NewAccount(int newID, char* newName, int newMoney) {
        Name = new char[strlen(newName) + 1];
        strcpy(Name, newName);
        Money = newMoney;
        ID = newID;

        all_ID[idNum] = newID;   // ID �־��ִ� �迭
        idNum++;

        cout << "[���°���]" << endl;
        cout << "����ID: "; cin >> newID;
        cout << "�� ��: "; cin >> newName;
        cout << "�Աݾ�: "; cin >> newMoney;
    }

    // �Ա�
    void InMoney(int newID, int newMoney) {
        for (int i = 0; i < 10; i++) {   // 10���� ����....^^...
            if (all_ID[i] == newID) {   // ID ����O

                cout << "[��" << '\t' << "��]" << endl;
                cout << "����ID: "; cin >> newID;
                cout << "�Աݾ�: "; cin >> newMoney;
                Money += newMoney;
                cout << "�ԱݿϷ�" << endl;
            }
            else {
                cout << "ã���ô� ����ID�� �������� �ʽ��ϴ�." << endl;   // ID ����X
            }
        }
    }

    // ���
    void OutMoney(int newID, int newMoney) {
        for (int i = 0; i < 10; i++) {
            if (all_ID[i] == newID) {

                cout << "[��" << '\t' << "��]" << endl;
                cout << "����ID: "; cin >> newID;
                cout << "��ݾ�: "; cin >> newMoney;
                if (Money < newMoney) {   // �ش� ID�� �ܰ��� ��ݾ��� ū ���
                    cout << "�ܰ� �����մϴ�" << endl;
                }
                else {
                    Money -= newMoney;
                    cout << "��ݿϷ�" << endl;
                }
            }
            else {
                cout << "ã���ô� ����ID�� �������� �ʽ��ϴ�." << endl;
            }
        }
    }

    ~Account() {
        delete[]Name;   // �����Ҵ� ����
    }
};

void ShowMenu() {
    cout << "-----Menu-----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �� ��" << endl;
    cout << "3. �� ��" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void ChooseMenu(int menu) {
    switch (menu) {
    case 1:
        Account NewAccount();
        break;
    case 2:
        Account InMoney();
        break;
    case 3:
        Account OutMoney();
        break;
    case 4:
        Account ShowAllAccount();   // ����X
        break;
    case 5:
        exit(0);
    }
}

int main() {
    int menu;

    while (1) {
        ShowMenu();
        cout << "����: ";
        cin >> menu;
        cout << endl;

        if (menu > 0 && menu < 6) {
            ChooseMenu(menu);
        }
        else {
            cout << "�ٽ� �Է��ϼ���" << endl;
            ShowMenu();      // 111-114�� �ڵ� �ߺ�
            cout << "����: ";
            cin >> menu;
            cout << endl;
        }
    }
    return 0;
}
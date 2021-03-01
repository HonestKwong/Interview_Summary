#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <Windows.h>
using namespace std;

//Э�鴦����
class HandleClientProtocol {
public:
	//�������ӽ��
	void AddMoney() {
		cout << "��������ӽ��!" << endl;
	}
	//����������ʯ
	void AddDiamond() {
		cout << "�����������ʯ" << endl;
	}
	//�������װ��
	void AddEquipment() {
		cout << "����Ҵ�װ��" << endl;
	}

	//������ҵȼ�
	void AddLevel() {
		cout << "���������" << endl;
	}
};

//����ӿ�
class AbstractCommand {
public:
	virtual void handle() = 0;
};

//���������ҽӿ�
class AddMoneyCommand :public AbstractCommand {
public:
	AddMoneyCommand(HandleClientProtocol* protocol) {
		this->pProtocol = protocol;
	}
	virtual void handle() {
		this->pProtocol->AddMoney();
	}
public:
	HandleClientProtocol* pProtocol;
};

//����������ʯ�ӿ�
class AddDiamondCommand :public AbstractCommand {
public:
	AddDiamondCommand(HandleClientProtocol* protocol) {
		this->pProtocol = protocol;
	}
	virtual void handle() {
		this->pProtocol->AddDiamond();
	}
public:
	HandleClientProtocol* pProtocol;
};

//��������װ���ӿ�
class AddEquipmentCommand :public AbstractCommand {
public:
	AddEquipmentCommand(HandleClientProtocol* protocol) {
		this->pProtocol = protocol;
	}
	virtual void handle() {
		this->pProtocol->AddEquipment();
	}
public:
	HandleClientProtocol* pProtocol;
};

//�������������ӿ�
class AddLevelCommand :public AbstractCommand {
public:
	AddLevelCommand(HandleClientProtocol* protocol) {
		this->pProtocol = protocol;
	}
	virtual void handle() {
		this->pProtocol->AddLevel();
	}
public:
	HandleClientProtocol* pProtocol;
};


//����������
class Server {
public:
	void addRequest(AbstractCommand* command) {
		mCommand.push(command);
	}

	void startHandle() {
		while (!mCommand.empty()) {
			mCommand.front()->handle();
			mCommand.pop();
			Sleep(2000);
		}
	}

	
public:
	queue<AbstractCommand*> mCommand;

};

void test01() {

	HandleClientProtocol* protocol = new HandleClientProtocol;
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	AbstractCommand* addlevel = new AddLevelCommand(protocol);
	AbstractCommand* addequipment = new AddEquipmentCommand(protocol);
	AbstractCommand* addDiamond = new AddDiamondCommand(protocol);

	Server server;
	server.addRequest(addmoney);
	server.addRequest(addlevel);
	server.addRequest(addequipment);
	server.startHandle();
	server.addRequest(addDiamond);
	server.startHandle();
}
int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
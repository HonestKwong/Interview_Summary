#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <Windows.h>
using namespace std;

//协议处理类
class HandleClientProtocol {
public:
	//处理增加金币
	void AddMoney() {
		cout << "给玩家增加金币!" << endl;
	}
	//处理增加钻石
	void AddDiamond() {
		cout << "给玩家增加钻石" << endl;
	}
	//处理玩家装备
	void AddEquipment() {
		cout << "给玩家穿装备" << endl;
	}

	//处理玩家等级
	void AddLevel() {
		cout << "给玩家升级" << endl;
	}
};

//命令接口
class AbstractCommand {
public:
	virtual void handle() = 0;
};

//处理请求金币接口
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

//处理请求钻石接口
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

//处理请求装备接口
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

//处理请求升级接口
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


//服务器程序
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
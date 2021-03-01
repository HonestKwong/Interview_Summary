#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

//�ṩһ�ִ��������ƶ���������ķ���
class AbstractCommonInterface{
public:
	virtual void run() = 0;
};


//�Ѿ�д�õ�ϵͳ
class MySystem : public AbstractCommonInterface {
public:
	virtual void run() {
		cout << "ϵͳ����" << endl;
	}
};

class MySystemProxy : AbstractCommonInterface {
public: 
	explicit MySystemProxy(string username, string password) {
		this->mPassword = password;
		this->mUsername = username;
		pSystem = new MySystem;
		
	}
	~MySystemProxy() {
		if (pSystem != NULL)
			delete pSystem;
	}

	virtual void run() {
		if (checkUsernameAndPassword())
			pSystem->run();
		else
			cout << "�û���������Ȩ�޲���" << endl;
	}
private:
	bool checkUsernameAndPassword() {
		if (mUsername == "admin" && mPassword == "admin")
			return true;
		else
			return false;
	}
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};


//����Ҫ��Ȩ�޵���֤, ���������˶����������ҵ�ϵͳ, �ṩ�û���������

int main()
{
	MySystemProxy *proxy = new MySystemProxy("admin", "admin");
	proxy->run();





	system("pause");
	return EXIT_SUCCESS;
}
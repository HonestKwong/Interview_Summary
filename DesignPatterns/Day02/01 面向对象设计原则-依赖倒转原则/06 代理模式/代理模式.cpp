#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

//提供一种代理来控制对其他对象的访问
class AbstractCommonInterface{
public:
	virtual void run() = 0;
};


//已经写好的系统
class MySystem : public AbstractCommonInterface {
public:
	virtual void run() {
		cout << "系统启动" << endl;
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
			cout << "用户名或密码权限不够" << endl;
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


//必须要有权限的验证, 不是所有人都能来启动我的系统, 提供用户名和密码

int main()
{
	MySystemProxy *proxy = new MySystemProxy("admin", "admin");
	proxy->run();





	system("pause");
	return EXIT_SUCCESS;
}
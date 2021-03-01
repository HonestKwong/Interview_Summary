#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//适配器模式,就是将已经写好的接口, 但是这个接口不符合要求
//将写好的接口转换成目标接口	

//这个函数我已经写好了
struct MyPrint {
	void operator() (int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

//定义目标接口 我要转换 适配成什么样的
class Target {
public:
	virtual void operator()(int v) = 0;

};

class Adapter : Target {
public:
	Adapter(int param) {
		this->param = param;
	}
	virtual void operator()(int v) {
		print(v, param);
	}
public:
	MyPrint print;
	int param;

};

//MyBind2nd
Adapter MyBind2d(int v) {
	return Adapter(v);
}


int main()
{

	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyBind2d(10));

	system("pause");
	return EXIT_SUCCESS;
}
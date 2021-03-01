#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//������ģʽ,���ǽ��Ѿ�д�õĽӿ�, ��������ӿڲ�����Ҫ��
//��д�õĽӿ�ת����Ŀ��ӿ�	

//����������Ѿ�д����
struct MyPrint {
	void operator() (int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

//����Ŀ��ӿ� ��Ҫת�� �����ʲô����
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
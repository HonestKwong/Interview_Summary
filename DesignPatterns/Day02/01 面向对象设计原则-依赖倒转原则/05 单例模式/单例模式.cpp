#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A {
private:
	A() {

	}
public:
	static A* getInstace() {
		return a;
	}
private:
	static A* a;

};

//����ʵ�ֲ���
//1.���캯��˽�л�
//2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3.�ṩ��̬����ӿڣ� �������û���õ�������
//�������ࣺ
//����ʽ �� ����ʽ	

class Singleton_lazy {   //�÷���Ϊ����ʽ
private:
	Singleton_lazy() {

	}
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton == NULL) pSingleton = new Singleton_lazy;
		return pSingleton;
	}
	//����һ��������ֻ��һ��, ���Կ��Բ����ͷ�, Ҳ����Ҫȥд����, ��������Զ��ͷ�
#if 0
	static void freeSpace() {
		if (pSingleton != NULL) delete pSingleton;
	}

#endif

private:
	static Singleton_lazy* pSingleton;
};

Singleton_lazy* Singleton_lazy::pSingleton = NULL;

class Singleton_hungry {   //�÷���Ϊ����ʽ
private:
	Singleton_hungry() {
		cout << "���Ƕ�������..." << endl;
	}
public:
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}

private:
	static Singleton_hungry* pSingleton;
};

Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

//�������ͷ�����
void test01() {
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2)
		cout << "����ָ��ָ��ͬһ���ڴ�" << endl;
	else
		cout << "���ǵ���ģʽ" << endl;

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
		cout << "����ָ��ָ��ͬһ���ڴ�" << endl;
	else
		cout << "���ǵ���ģʽ" << endl;


	
}


int main()
{
	// A a;
	//A* a = A::getInstace();
	cout << "����main����ִ�����..." << endl;
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
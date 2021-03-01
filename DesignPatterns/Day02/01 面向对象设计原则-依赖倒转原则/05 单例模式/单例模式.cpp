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

//单例实现步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口， 可以让用户获得单例对象
//单例种类：
//懒汉式 和 饿汉式	

class Singleton_lazy {   //该方法为懒汉式
private:
	Singleton_lazy() {

	}
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton == NULL) pSingleton = new Singleton_lazy;
		return pSingleton;
	}
	//单例一个程序里只有一份, 所以可以不用释放, 也不需要去写析构, 程序结束自动释放
#if 0
	static void freeSpace() {
		if (pSingleton != NULL) delete pSingleton;
	}

#endif

private:
	static Singleton_lazy* pSingleton;
};

Singleton_lazy* Singleton_lazy::pSingleton = NULL;

class Singleton_hungry {   //该方法为饿汉式
private:
	Singleton_hungry() {
		cout << "这是饿汉构造..." << endl;
	}
public:
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}

private:
	static Singleton_hungry* pSingleton;
};

Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

//单例的释放问题
void test01() {
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2)
		cout << "两个指针指向同一块内存" << endl;
	else
		cout << "不是单例模式" << endl;

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
		cout << "两个指针指向同一块内存" << endl;
	else
		cout << "不是单例模式" << endl;


	
}


int main()
{
	// A a;
	//A* a = A::getInstace();
	cout << "这是main函数执行入口..." << endl;
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
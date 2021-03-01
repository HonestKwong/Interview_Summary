#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象车
class AbstractCar {
public:
	virtual void run() = 0;
};

//大众车
class Dazhong : public AbstractCar {
public:
	virtual void run() {
		cout << "大众车启动..." << endl;
		 
	}
};

//拖拉机
class Tuolaji : public AbstractCar {
public:
	virtual void run() {
		cout << "拖拉机启动" << endl;
	}
};

#if 0
//针对具体类  不适用继承
class PersonA : public Tuolaji {
	void Doufeng() {
		run();
	}
};

//针对具体类  不适用继承
class PersonB : public Dazhong {
	void Doufeng() {
		run();
	}
};
#endif

//可以使用组合
class Person {
public: 
	void setCar(AbstractCar* car) {
		cout << "Person的构造函数" << endl;
		this->car = car;
	}
	void Doufeng() {
		this->car->run();
	}
	~Person() {
		cout << "Person 的析构函数" << endl;
		if (this->car != NULL) delete this->car;
	}
public:
	AbstractCar* car;
};

void test02() {
	Person *p = new Person;
	p->setCar(new Dazhong);
	p->Doufeng();
	delete p;
	cout << "test02() end" << endl;
}
//继承和组合 有限使用组合
int main()
{
	test02();


	system("pause");
	return EXIT_SUCCESS;
}
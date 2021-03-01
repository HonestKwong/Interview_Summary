#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����ˮ��
class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

//ƻ��
class Apple : public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl; 
	}
};

//�㽶
class Banana: public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "�����㽶" << endl; 
	}
};

//Ѽ��
class Pear: public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "����Ѽ��" << endl; 
	}
};

class AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

//ƻ������
class AppleFactory : public AbstractFactory {
	virtual AbstractFruit* CreateFruit() {
		return new Apple;
	}
};

//�㽶����
class BananaFactory : public AbstractFactory {
	virtual AbstractFruit* CreateFruit() {
		return new Banana;
	}
};

//Ѽ�湤��
class PearFactory : public AbstractFactory {
	virtual AbstractFruit* CreateFruit() {
		return new Pear;
	}
};

void test01() {
	AbstractFactory* factory = NULL;
	AbstractFruit* fruit = NULL;

	//����һ��ƻ������
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	
	delete factory;
	delete fruit;

	//����һ���㽶����
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;

	//����һ��Ѽ�湤��
	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;
}




int main()
{
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
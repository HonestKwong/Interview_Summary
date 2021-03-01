#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����
class AbstractCar {
public:
	virtual void run() = 0;
};

//���ڳ�
class Dazhong : public AbstractCar {
public:
	virtual void run() {
		cout << "���ڳ�����..." << endl;
		 
	}
};

//������
class Tuolaji : public AbstractCar {
public:
	virtual void run() {
		cout << "����������" << endl;
	}
};

#if 0
//��Ծ�����  �����ü̳�
class PersonA : public Tuolaji {
	void Doufeng() {
		run();
	}
};

//��Ծ�����  �����ü̳�
class PersonB : public Dazhong {
	void Doufeng() {
		run();
	}
};
#endif

//����ʹ�����
class Person {
public: 
	void setCar(AbstractCar* car) {
		cout << "Person�Ĺ��캯��" << endl;
		this->car = car;
	}
	void Doufeng() {
		this->car->run();
	}
	~Person() {
		cout << "Person ����������" << endl;
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
//�̳к���� ����ʹ�����
int main()
{
	test02();


	system("pause");
	return EXIT_SUCCESS;
}
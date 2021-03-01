#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//class BMW {
//public:
//	void run() {
//		cout << "BWM On��";
//	}
//};
//����ȥ�ϰ�
//������ϵ
//class Person {
//public:
//	void GoWork(BMW* car) {
//		car->run();
//	}

//};
/*
//������ϵ
class Person2 {
public:
	void GoWork() {
		car->run();
	}

public:
	BMW* car;
};
*/

//����ԭ��, ����չ����, ���޸Ĺر�,���ӹ�����ͨ�����Ӵ�����ʵ�ֵ�,������ȥ�޸�ԭ����

//дһ��������
class AbstractCalculator {
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a, int b) = 0;
};

class PlusCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	
	virtual int getResult() {
		return mA + mB;
	}

public:
	int mA;
	int mB;
};

class DevideCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA / mB;
	}

public:
	int mA;
	int mB;
};

class MinusCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA - mB;
	}

public:
	int mA;
	int mB;
};

class MultiplyCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA * mB;
	}

public:
	int mA;
	int mB;
};


void test01() {
	AbstractCalculator* calculator = new PlusCalculator;
	calculator->setOperatorNumber(1, 2);
	cout << "ret:" << calculator->getResult() << endl;
	delete calculator;


	calculator = new MinusCalculator;
	calculator->setOperatorNumber(1, 2);
	cout << "ret:" << calculator->getResult() << endl;
	delete calculator;

	calculator = new MultiplyCalculator;
	calculator->setOperatorNumber(1, 2);
	cout << "ret:" << calculator->getResult() << endl;
	delete calculator;

	calculator = new DevideCalculator;
	calculator->setOperatorNumber(1, 2);
	cout << "ret:" << calculator->getResult() << endl;
	delete calculator;
}



int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}
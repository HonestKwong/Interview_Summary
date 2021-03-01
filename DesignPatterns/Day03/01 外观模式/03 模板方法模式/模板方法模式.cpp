#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class DrinkTemplate {
public:
	//��ˮ
	virtual void BoilWater() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void AddSomething() = 0;

	//ģ�巽��
	void Make() {
		this->BoilWater();
		this->Brew();
		this->PourInCup();
		this->AddSomething();
	}
};

//���ݿ���
class Coffee : public DrinkTemplate {
	//��ˮ
	virtual void BoilWater() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�����ȵ���" << endl;
	}
	//���븨��
	virtual void AddSomething() {
		cout << "����ţ��, �ǵ�" << endl;
	}


};

//����
class Tea : public DrinkTemplate {
	//��ˮ
	virtual void BoilWater() {
		cout << "���ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "����ˮ����" << endl;
	}
	//���븨��
	virtual void AddSomething() {
		cout << "�������" << endl;
	}


};


void test01() {
	Tea* tea = new Tea;
	tea->Make();
	Coffee* coffee = new Coffee;
	coffee->Make();
}

int main()
{
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
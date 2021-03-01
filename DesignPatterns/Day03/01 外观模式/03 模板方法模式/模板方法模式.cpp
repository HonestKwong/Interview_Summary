#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class DrinkTemplate {
public:
	//煮水
	virtual void BoilWater() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void AddSomething() = 0;

	//模板方法
	void Make() {
		this->BoilWater();
		this->Brew();
		this->PourInCup();
		this->AddSomething();
	}
};

//冲泡咖啡
class Coffee : public DrinkTemplate {
	//煮水
	virtual void BoilWater() {
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将咖啡倒入" << endl;
	}
	//加入辅料
	virtual void AddSomething() {
		cout << "加入牛奶, 糖等" << endl;
	}


};

//冲泡
class Tea : public DrinkTemplate {
	//煮水
	virtual void BoilWater() {
		cout << "煮茶水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将茶水倒入" << endl;
	}
	//加入辅料
	virtual void AddSomething() {
		cout << "加入枸杞" << endl;
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
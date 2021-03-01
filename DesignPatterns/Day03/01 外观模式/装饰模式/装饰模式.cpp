#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 一般使用继承来实现	类的 功能扩展
//装饰模式 可以动态的给一个类增加功能


//抽象英雄
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int mMp;
	int mHp;
	int mAt;
	int mDf;


};

//具体英雄
class HeroA : public AbstractHero {
public:
	HeroA() {
		mMp = 0;
		mHp = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStatus() {
		cout << "血量:" << mHp << endl;
		cout << "魔法:" << mMp << endl;
		cout << "攻击:" << mAt << endl;
		cout << "防御:" << mDf << endl;
	}
};


//英雄穿上某个装饰物 那么他还是个 英雄
class AbstractEquipment : public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero) {
		this->pHero = hero;
	}

	virtual void ShowStatus() {
		
	}
public:
	AbstractHero* pHero;
};

//狂徒
class KuangtuEquipment : public AbstractEquipment {
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {
	}
	//增加额外的功能
	void AddKuangtu() {
		cout << "英雄穿上狂徒后.." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete pHero;
	}
	virtual void ShowStatus() {
		AddKuangtu();
		cout << "血量:" << mHp << endl;
		cout << "魔法:" << mMp << endl;
		cout << "攻击:" << mAt << endl;
		cout << "防御:" << mDf << endl;
	
	}
};

//无尽
class InfiniteKnifeEquipment : public AbstractEquipment {
public:
	InfiniteKnifeEquipment(AbstractHero* hero) :AbstractEquipment(hero) {
	}
	//增加额外的功能
	void AddInfiniteKnife() {
		cout << "英雄穿上无尽之刃后.." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 30;
		this->mDf = this->pHero->mDf;
		delete pHero;
	}
	virtual void ShowStatus() {
		AddInfiniteKnife();
		cout << "血量:" << mHp << endl;
		cout << "魔法:" << mMp << endl;
		cout << "攻击:" << mAt << endl;
		cout << "防御:" << mDf << endl;
	
	}
};

void test01() {
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();

	cout << "----------" << endl;
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();
	
	cout << "----------" << endl;
	hero = new InfiniteKnifeEquipment(hero);
	hero->ShowStatus();
}

int main()
{

	test01();  


	system("pause");
	return EXIT_SUCCESS;
}


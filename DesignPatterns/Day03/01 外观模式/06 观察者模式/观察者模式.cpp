#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
using namespace std;

//抽象的影响
class AbstractHero {
public:
	virtual void Update() = 0;
};

//具体的观察者
class HeroA : public AbstractHero {
public:
	HeroA() {
		cout << "英雄A正在撸boss" << endl;
	}

	virtual void Update() {
		cout << "英雄A停止攻击, 待机状态" << endl;
	}
};

class HeroB : public AbstractHero {
public:
	HeroB() {
		cout << "英雄B正在撸boss" << endl;
	}

	virtual void Update() {
		cout << "英雄B停止攻击, 待机状态" << endl;
	}
};

class HeroC : public AbstractHero {
public:
	HeroC() {
		cout << "英雄C正在撸boss" << endl;
	}

	virtual void Update() {
		cout << "英雄C停止攻击, 待机状态" << endl;
	}
};

class HeroD : public AbstractHero {
public:
	HeroD() {
		cout << "英雄D正在撸boss" << endl;
	}

	virtual void Update() {
		cout << "英雄D停止攻击, 待机状态" << endl;
	}
};

class HeroE : public AbstractHero {
public:
	HeroE() {
		cout << "英雄E正在撸boss" << endl;
	}

	virtual void Update() {
		cout << "英雄E停止攻击, 待机状态" << endl;
	}
};

//观察目标抽象
class AbstractBoss {
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero) = 0;
	//删除观察者
	virtual void deleteHero(AbstractHero* hero) = 0;
	//通知观察者
	virtual void notifyHero() = 0;
};

//具体观察者A BOSSA
class BOSSA : public AbstractBoss {
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero) {
		pHeroList.push_back(hero);
	}
	//删除观察者
	virtual void deleteHero(AbstractHero* hero) {
		pHeroList.remove(hero);
	}
	//通知观察者
	virtual void notifyHero() {
		for (auto it = pHeroList.begin(); it != pHeroList.end(); it++) {
			(*it)->Update();
		}
	}

public:
	list<AbstractHero*> pHeroList;

};

void test01() {
	//创建观察者
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;

	//创建观察目标
	AbstractBoss* bossA = new BOSSA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);

	cout << "HeroC阵亡" << endl;
	bossA->deleteHero(heroC);
	cout << "Boss阵亡" << endl;
	bossA->notifyHero();

}

int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}
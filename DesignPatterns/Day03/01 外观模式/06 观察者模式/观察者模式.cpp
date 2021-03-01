#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
using namespace std;

//�����Ӱ��
class AbstractHero {
public:
	virtual void Update() = 0;
};

//����Ĺ۲���
class HeroA : public AbstractHero {
public:
	HeroA() {
		cout << "Ӣ��A����ߣboss" << endl;
	}

	virtual void Update() {
		cout << "Ӣ��Aֹͣ����, ����״̬" << endl;
	}
};

class HeroB : public AbstractHero {
public:
	HeroB() {
		cout << "Ӣ��B����ߣboss" << endl;
	}

	virtual void Update() {
		cout << "Ӣ��Bֹͣ����, ����״̬" << endl;
	}
};

class HeroC : public AbstractHero {
public:
	HeroC() {
		cout << "Ӣ��C����ߣboss" << endl;
	}

	virtual void Update() {
		cout << "Ӣ��Cֹͣ����, ����״̬" << endl;
	}
};

class HeroD : public AbstractHero {
public:
	HeroD() {
		cout << "Ӣ��D����ߣboss" << endl;
	}

	virtual void Update() {
		cout << "Ӣ��Dֹͣ����, ����״̬" << endl;
	}
};

class HeroE : public AbstractHero {
public:
	HeroE() {
		cout << "Ӣ��E����ߣboss" << endl;
	}

	virtual void Update() {
		cout << "Ӣ��Eֹͣ����, ����״̬" << endl;
	}
};

//�۲�Ŀ�����
class AbstractBoss {
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) = 0;
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) = 0;
	//֪ͨ�۲���
	virtual void notifyHero() = 0;
};

//����۲���A BOSSA
class BOSSA : public AbstractBoss {
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) {
		pHeroList.push_back(hero);
	}
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) {
		pHeroList.remove(hero);
	}
	//֪ͨ�۲���
	virtual void notifyHero() {
		for (auto it = pHeroList.begin(); it != pHeroList.end(); it++) {
			(*it)->Update();
		}
	}

public:
	list<AbstractHero*> pHeroList;

};

void test01() {
	//�����۲���
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;

	//�����۲�Ŀ��
	AbstractBoss* bossA = new BOSSA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);

	cout << "HeroC����" << endl;
	bossA->deleteHero(heroC);
	cout << "Boss����" << endl;
	bossA->notifyHero();

}

int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}
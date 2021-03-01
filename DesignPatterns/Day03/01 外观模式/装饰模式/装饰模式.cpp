#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// һ��ʹ�ü̳���ʵ��	��� ������չ
//װ��ģʽ ���Զ�̬�ĸ�һ�������ӹ���


//����Ӣ��
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int mMp;
	int mHp;
	int mAt;
	int mDf;


};

//����Ӣ��
class HeroA : public AbstractHero {
public:
	HeroA() {
		mMp = 0;
		mHp = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStatus() {
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};


//Ӣ�۴���ĳ��װ���� ��ô�����Ǹ� Ӣ��
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

//��ͽ
class KuangtuEquipment : public AbstractEquipment {
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {
	}
	//���Ӷ���Ĺ���
	void AddKuangtu() {
		cout << "Ӣ�۴��Ͽ�ͽ��.." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete pHero;
	}
	virtual void ShowStatus() {
		AddKuangtu();
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	
	}
};

//�޾�
class InfiniteKnifeEquipment : public AbstractEquipment {
public:
	InfiniteKnifeEquipment(AbstractHero* hero) :AbstractEquipment(hero) {
	}
	//���Ӷ���Ĺ���
	void AddInfiniteKnife() {
		cout << "Ӣ�۴����޾�֮�к�.." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 30;
		this->mDf = this->pHero->mDf;
		delete pHero;
	}
	virtual void ShowStatus() {
		AddInfiniteKnife();
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	
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


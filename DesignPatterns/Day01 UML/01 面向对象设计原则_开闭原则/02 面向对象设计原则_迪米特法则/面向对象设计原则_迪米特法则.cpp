#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
using namespace std;

//�����ط���, �ֽ���С֪ʶԭ��
class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

//¥��A
class BuildingA : public AbstractBuilding {
public:
	BuildingA() {
		mQulity = "��Ʒ��";
	}

public:
	virtual void sale() {
		cout << "¥��A" << this->mQulity << "������!" << endl;
	}

	virtual string getQuality() {
		return this->mQulity;
	}
public:
	string mQulity;
};

//¥��B
class BuildingB : public AbstractBuilding {
public:
	BuildingB() {
		mQulity = "��Ʒ��";
	}

public:
	virtual void sale() {
		cout << "¥��B" << this->mQulity << "������!" << endl;
	}

	virtual string getQuality() {
		return this->mQulity;
	}
public:
	string mQulity;
};

class Mediator {
public: 
	Mediator() {
	AbstractBuilding* building = new BuildingA;
	vBuilding.push_back(building);
	building = new BuildingA;
	vBuilding.push_back(building);
	}
	
	AbstractBuilding* findMybuilding(string quality) {
		for (auto &x : vBuilding) {
			if (x->getQuality() == quality) return x;
		}
		return NULL;
	}
	//�����ṩ�ӿ�
	~Mediator() {
		for (auto &x : vBuilding)
		{
			delete x;
		}
	}
public:
	vector<AbstractBuilding*> vBuilding;
};

void test01() {
	BuildingA* ba = new BuildingA;
	if (ba->mQulity == "��Ʒ��") {
		ba->sale();
	}

	BuildingB* bb = new BuildingB;
	if (bb->mQulity == "��Ʒ��") {
		bb->sale();  
	}
	
}

void test02() {
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMybuilding("��Ʒ��");
	if (building != NULL)
		building->sale();
	else
		cout << "û�з��� ��������¥��" << endl; 
}


int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
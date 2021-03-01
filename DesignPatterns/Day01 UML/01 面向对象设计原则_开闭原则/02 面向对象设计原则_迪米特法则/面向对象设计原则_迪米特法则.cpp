#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
using namespace std;

//迪米特法则, 又叫最小知识原则
class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

//楼盘A
class BuildingA : public AbstractBuilding {
public:
	BuildingA() {
		mQulity = "高品质";
	}

public:
	virtual void sale() {
		cout << "楼盘A" << this->mQulity << "被售卖!" << endl;
	}

	virtual string getQuality() {
		return this->mQulity;
	}
public:
	string mQulity;
};

//楼盘B
class BuildingB : public AbstractBuilding {
public:
	BuildingB() {
		mQulity = "低品质";
	}

public:
	virtual void sale() {
		cout << "楼盘B" << this->mQulity << "被售卖!" << endl;
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
	//对外提供接口
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
	if (ba->mQulity == "低品质") {
		ba->sale();
	}

	BuildingB* bb = new BuildingB;
	if (bb->mQulity == "低品质") {
		bb->sale();  
	}
	
}

void test02() {
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMybuilding("中品质");
	if (building != NULL)
		building->sale();
	else
		cout << "没有符合 您条件的楼盘" << endl; 
}


int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
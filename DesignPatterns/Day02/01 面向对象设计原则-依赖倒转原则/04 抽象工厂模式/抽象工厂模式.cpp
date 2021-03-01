#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象苹果
class AbstractApple {
public:
	virtual void ShowName() = 0;

};

class ChinaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "中国苹果" << endl;
	}
};

class AmericaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "美国苹果" << endl;
	}
};
class JapanApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "倭国苹果" << endl;
	}
};

//抽象香蕉
class AbstractBanana{
public:
	virtual void ShowName() = 0;

};

class ChinaBanana : public AbstractBanana{
public:
	virtual void ShowName() {
		cout << "中国香蕉" << endl;
	}
};

class AmericaBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "美国香蕉" << endl;
	}
};
class JapanBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "倭国香蕉" << endl;
	}
};

class AbstractPear {
public:
	virtual void ShowName() = 0;
};

class ChinaPear: public AbstractPear {
public:
	virtual void ShowName() {
		cout << "中国苹果" << endl;
	}
};

class AmericaPear: public AbstractPear {
public:
	virtual void ShowName() {
		cout << "美国苹果" << endl;
	}
};
class JapanPear : public AbstractPear {
public:
	virtual void ShowName() {
		cout << "倭国苹果" << endl;
	}
};

//抽象工厂 针对产品族
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};

//中国工厂
class ChinaFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new ChinaBanana;
	}

	virtual AbstractPear* CreatePear() {
		return new ChinaPear;
	}
	
};

//美国工厂
class AmericaFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new AmericaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new AmericaBanana;
	}

	virtual AbstractPear* CreatePear() {
		return new AmericaPear;
	}
	
};
//倭国工厂
class JapanFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new JapanBanana;
	}

	virtual AbstractPear* CreatePear() {
		return new JapanPear;
	}
	
};

void test01() {
	AbstractApple *apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;
	AbstractFactory* factory = NULL;
	factory = new AmericaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
}
int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}
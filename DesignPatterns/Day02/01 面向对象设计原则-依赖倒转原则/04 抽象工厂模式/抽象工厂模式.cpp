#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����ƻ��
class AbstractApple {
public:
	virtual void ShowName() = 0;

};

class ChinaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "�й�ƻ��" << endl;
	}
};

class AmericaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};
class JapanApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};

//�����㽶
class AbstractBanana{
public:
	virtual void ShowName() = 0;

};

class ChinaBanana : public AbstractBanana{
public:
	virtual void ShowName() {
		cout << "�й��㽶" << endl;
	}
};

class AmericaBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "�����㽶" << endl;
	}
};
class JapanBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "�����㽶" << endl;
	}
};

class AbstractPear {
public:
	virtual void ShowName() = 0;
};

class ChinaPear: public AbstractPear {
public:
	virtual void ShowName() {
		cout << "�й�ƻ��" << endl;
	}
};

class AmericaPear: public AbstractPear {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};
class JapanPear : public AbstractPear {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};

//���󹤳� ��Բ�Ʒ��
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};

//�й�����
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

//��������
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
//��������
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���й�����Ա
class BankWorker {
public:
	void saveService() {
		cout << "������ҵ��..." << endl;
	}
	void payService() {
		cout << "����֧��ҵ��..." << endl;
	}
	void transferService() {
		cout << "����ת��ҵ��..." << endl;
	}
};

//�в�ģ��
void doSaveBussiness(BankWorker* worker) {
	worker->saveService();
}
void doPayBussiness(BankWorker* worker) {
	worker->payService();
}
void doTransferBussiness(BankWorker* worker) {
	worker->transferService();
}

//ҵ��ģ��
void test01() {
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);          //������ҵ��
	doPayBussiness(worker);           //����֧��ҵ��
	doTransferBussiness(worker);      //����ת��ҵ��
}


class AbstractWorker {
public:
	virtual void doBusiness() = 0;
};

//ר�Ÿ�����ҵ��Ĺ�����Ա
class SaveBankWorker : public AbstractWorker {
public:
	virtual void doBusiness() {
		cout << "������ҵ��" << endl;
	}
};

//ר�Ÿ���֧��ҵ��Ĺ�����Ա
class PayBankWorker : public AbstractWorker {
public:
	virtual void doBusiness() {
		cout << "����֧��ҵ��" << endl;
	}
};

//ר�Ÿ���ת��ҵ��Ĺ�����Ա
class TransferBankWorker : public AbstractWorker {
public:
	virtual void doBusiness() {
		cout << "����ת��ҵ��" << endl;
	}
};

void doNewBusiness(AbstractWorker* worker) {
	worker->doBusiness();
	delete worker;
}

void test02() {
//	AbstractWorker* transfer = new TransferBankWorker;
	doNewBusiness(new TransferBankWorker);
	doNewBusiness(new PayBankWorker);
	doNewBusiness(new SaveBankWorker);
}


int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
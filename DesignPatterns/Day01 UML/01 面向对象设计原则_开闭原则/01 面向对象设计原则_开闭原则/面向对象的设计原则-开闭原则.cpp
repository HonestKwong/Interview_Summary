#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class BMW {
public:
	void run() {
		cout << "BWM On��";
	}
};
//����ȥ�ϰ�
//������ϵ
class Person {
public:
	void GoWork(BMW* car) {
		car->run();
	}

};

//������ϵ
class Person2 {
public:
	void GoWork() {
		car->run();
	}

public:
	BMW* car;
};


int main()
{



	system("pause");
	return EXIT_SUCCESS;
}
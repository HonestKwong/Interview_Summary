#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���ӻ�
class Television {
public:
	void On() {
		cout << "���ӻ���..." << endl;
	}

	void Off() {
		cout << "���ӻ��ر�..." << endl;
	}
	
};

//��
class Light {
public:
	void On() {
		cout << "�ƴ�..." << endl;
	}

	void Off() {
		cout << "�ƹر�..." << endl;
	}
	
};

//����
class Audio {
public:
	void On() {
		cout << "�����..." << endl;
	}

	void Off() {
		cout << "����ر�..." << endl;
	}
	
};

//��˷�
class Microphone {
public:
	void On() {
		cout << "��˷��..." << endl;
	}

	void Off() {
		cout << "��˷�ر�..." << endl;
	}
	
};

//DVD������
class DVDPlayer {
public:
	void On() {
		cout << "DVD��..." << endl;
	}

	void Off() {
		cout << "DVD�ر�..." << endl;
	}
	
};

//��Ϸ��
class GameMachine {
public:
	void On() {
		cout << "��Ϸ����..." << endl;
	}

	void Off() {
		cout << "��Ϸ���ر�..." << endl;
	}
};

class KTVMode {
public:
	KTVMode() {
		pTv = new Television;
		pAudio = new Audio;
		pMicrophone = new Microphone;
		pLight = new Light;
		pDVDplayer = new DVDPlayer;
	}

	~KTVMode(){
		delete pDVDplayer;
		delete pLight;
		delete pMicrophone;
		delete pAudio;
		delete pTv;
	}

	void OnKTV() {
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDVDplayer->On();
	}
	void OffKTV() {
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMicrophone->Off();
		pDVDplayer->Off();
	}
public:
	Television* pTv;
	Audio* pAudio;
	Microphone* pMicrophone;
	Light* pLight;
	DVDPlayer* pDVDplayer;
};

void test01() {
	KTVMode* ktv = new KTVMode;
	ktv->OnKTV();
	ktv->OffKTV();
	delete ktv;
}

int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}
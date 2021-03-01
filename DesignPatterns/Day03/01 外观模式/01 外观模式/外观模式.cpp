#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//电视机
class Television {
public:
	void On() {
		cout << "电视机打开..." << endl;
	}

	void Off() {
		cout << "电视机关闭..." << endl;
	}
	
};

//灯
class Light {
public:
	void On() {
		cout << "灯打开..." << endl;
	}

	void Off() {
		cout << "灯关闭..." << endl;
	}
	
};

//音响
class Audio {
public:
	void On() {
		cout << "音响打开..." << endl;
	}

	void Off() {
		cout << "音响关闭..." << endl;
	}
	
};

//麦克风
class Microphone {
public:
	void On() {
		cout << "麦克风打开..." << endl;
	}

	void Off() {
		cout << "麦克风关闭..." << endl;
	}
	
};

//DVD播放器
class DVDPlayer {
public:
	void On() {
		cout << "DVD打开..." << endl;
	}

	void Off() {
		cout << "DVD关闭..." << endl;
	}
	
};

//游戏机
class GameMachine {
public:
	void On() {
		cout << "游戏机打开..." << endl;
	}

	void Off() {
		cout << "游戏机关闭..." << endl;
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
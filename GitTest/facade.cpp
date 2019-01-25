#include <iostream>
using namespace std;

class CPU
{
public:
	char *data;
};

class Memory
{
public:
	char *data;
};

class GPU
{
public:
	char *data;
};

class HardDrive
{
public:
	char *data;
};

class Sound
{
public:
	char *data;
};

class OS
{
public:
	virtual void dataTransfer(char *UserData)
	{
		extDataToPool(char *UserData);
		sendToMemory();
		sendToCPU();
		sendToGPU();
		sendToHD();
		sendToSound();
	}

	virtual void extDataToPool(char *UserData);
	virtual void sendToCPU();
	virtual void sendToMemory();
	virtual void sendToGPU();
	virtual void sendToHD();
	virtual void sendToSound();

	char *DataPool;
	CPU cpu;
	Memory ram;
	GPU gpu;
	HardDrive hd;
	Sound sound;
};
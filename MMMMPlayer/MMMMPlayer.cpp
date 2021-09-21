// MMMMPlayer.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <thread>
#include "MMMMThread/MMMMThread.h"
using namespace std;

void ThreadFunc(int threadIndex)
{
	for (int i = 0; i < 10000; ++i)
	{
		printf("ThreadIndex: %d , Run time: %d \n", threadIndex, i);
	}
}


class MyThread : public MMMMThread
{
public:
	void run() override { printf("MyThread is Run!"); };
};

int main()
{
	MyThread mt;
	mt.Start();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	return 0;
}

// MMMMPlayer.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <thread>
#include "MMMMThread/MMMMThread.h"
using namespace std;




class MyThread : public MMMMThread
{
public:
	void run() override { printf("MyThread is Run!"); };
};

int main_thread()
{
	MyThread mt;
	mt.Start();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	return 0;
}

#include "MMMMAV/MMMMAV.h"

int main(int argc, char* argv[])
{
  int frame_count = 0;

	MMMMAVReader reader;
  int ret=reader.Open("E:\\workspace\\temps\\demo_video.mp4");
	if (ret!=0)
	{
		printf_s("Open File Fail!!\n");
		return -1;
	}

	while (1)
	{
          MMMMAVPacket p;
         ret= reader.Read(&p);
          if (ret)
          {
	          break;
          }
          printf("Read Packet Success: %d!\n", ++frame_count);
	}

	reader.Close();

}


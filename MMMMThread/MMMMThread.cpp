#include "MMMMThread.h"

#include <thread>

int MMMMThread::Start()
{
	std::thread t(&MMMMThread::run, this);
	t.detach();
	return 0;
}

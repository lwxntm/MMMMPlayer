#pragma once

extern "C"
{
#include <libavformat/avformat.h>
}

class MMMMAVPacket
{
public:
  MMMMAVPacket();
 ~MMMMAVPacket();
  AVPacket* pkt;
};

class MMMMAVReader
{
public:
	MMMMAVReader();
	~MMMMAVReader();

	int Open(const char* path);

	int Close();

	int Read(MMMMAVPacket* packet);

private:
        AVFormatContext* aVFormatCtx = nullptr;
};


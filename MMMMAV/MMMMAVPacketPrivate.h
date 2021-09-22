#pragma once

extern "C"
{
#include <libavformat/avformat.h>
}

class MMMMAVPacketPrivate
{
public:

	AVPacket* pkt;

private:
};

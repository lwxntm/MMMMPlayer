#include "MMMMAV.h"

MMMMAVReader::MMMMAVReader()
{
	aVFormatCtx = avformat_alloc_context();
}

MMMMAVReader::~MMMMAVReader()
{
	if (aVFormatCtx != nullptr)
	{
		avformat_free_context(aVFormatCtx);
		aVFormatCtx = nullptr;
	}
}

int MMMMAVReader::Open(const char* path)
{
	if (aVFormatCtx == nullptr)
	{
		return -1;
	}
	int ret = avformat_open_input(&aVFormatCtx, path, nullptr, nullptr);
	if (!ret)
	{
		avformat_find_stream_info(aVFormatCtx, nullptr);
	}
	return ret;
}

int MMMMAVReader::Close()
{
	if (aVFormatCtx == nullptr)
	{
		return -1;
	}
	avformat_close_input(&aVFormatCtx);
	return 0;
}

int MMMMAVReader::Read(MMMMAVPacket* packet)
{
	int ret = av_read_frame(aVFormatCtx, packet->pkt);
	return ret;
}

#include "MMMMAV.h"
#include "MMMMAVPacketPrivate.h"
#include "MMMMAVReaderPrivate.h"
MMMMAVReader::MMMMAVReader()
{
  aVReaderPrivate = new MMMMAVReaderPrivate();
	aVReaderPrivate->aVFormatCtx = avformat_alloc_context();
}

MMMMAVReader::~MMMMAVReader()
{
  if (aVReaderPrivate->aVFormatCtx != nullptr)
	{
	
    avformat_free_context(aVReaderPrivate->aVFormatCtx);
    aVReaderPrivate->aVFormatCtx = nullptr;
	}
}

int MMMMAVReader::Open(const char* path)
{
  if (aVReaderPrivate->aVFormatCtx == nullptr)
	{
		return -1;
	}
  int ret = avformat_open_input(&aVReaderPrivate->aVFormatCtx, path, nullptr,
                                nullptr);
	if (!ret)
	{
    avformat_find_stream_info(aVReaderPrivate->aVFormatCtx, nullptr);
	}
	return ret;
}

int MMMMAVReader::Close()
{
  if (aVReaderPrivate->aVFormatCtx == nullptr)
	{
		return -1;
	}
  avformat_close_input(&aVReaderPrivate->aVFormatCtx);
	return 0;
}

int MMMMAVReader::Read(MMMMAVPacket* packet)
{
  int ret = av_read_frame(aVReaderPrivate->aVFormatCtx, packet->aVPacketPrivate->pkt);
	return ret;
}


const char* MMMMAVReader::About()
{
	auto ret = avformat_configuration();
  return ret;
}
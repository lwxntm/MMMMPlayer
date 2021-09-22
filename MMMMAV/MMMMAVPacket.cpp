#include "MMMMAV.h"

MMMMAVPacket::MMMMAVPacket()
{
	pkt = av_packet_alloc();
}

MMMMAVPacket::~MMMMAVPacket()
{
	if (pkt != nullptr)
	{
		av_packet_free(&pkt);
		pkt = nullptr;
	}
}

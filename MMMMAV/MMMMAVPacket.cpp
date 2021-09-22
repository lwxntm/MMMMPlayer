#include "MMMMAV.h"
#include "MMMMAVPacketPrivate.h"

MMMMAVPacket::MMMMAVPacket()
{
	aVPacketPrivate = new MMMMAVPacketPrivate();
	aVPacketPrivate->pkt = av_packet_alloc();
}

MMMMAVPacket::~MMMMAVPacket()
{
	if (aVPacketPrivate != nullptr)
	{
		av_packet_free(&aVPacketPrivate->pkt);
		delete aVPacketPrivate;
		aVPacketPrivate = nullptr;
	}
}

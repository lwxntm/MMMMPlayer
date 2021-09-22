#pragma once

class MMMMAVPacketPrivate;
class MMMMAVReaderPrivate;

class MMMMAVPacket
{
public:
  MMMMAVPacket();
 ~MMMMAVPacket();

 MMMMAVPacketPrivate* aVPacketPrivate;

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
        MMMMAVReaderPrivate* aVReaderPrivate = nullptr;
};


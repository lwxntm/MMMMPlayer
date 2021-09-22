#pragma once

extern "C" {
#include <libavformat/avformat.h>
}

class MMMMAVReaderPrivate {
 public:

AVFormatContext* aVFormatCtx;
 private:
};


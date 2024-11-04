#ifndef ENCODER_H
#define ENCODER_H

#include <filesystem>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/opt.h>
}

#include "libvideo2x.h"

int init_encoder(
    AVBufferRef *hw_ctx,
    std::filesystem::path out_fpath,
    AVFormatContext *ifmt_ctx,
    AVFormatContext **ofmt_ctx,
    AVCodecContext **enc_ctx,
    AVCodecContext *dec_ctx,
    EncoderConfig *encoder_config,
    int vstream_idx,
    int **stream_map
);

int write_frame(
    AVFrame *frame,
    AVCodecContext *enc_ctx,
    AVFormatContext *ofmt_ctx,
    int vstream_idx
);

int flush_encoder(AVCodecContext *enc_ctx, AVFormatContext *ofmt_ctx);

#endif  // ENCODER_H
#pragma once
using namespace std;

  namespace music{
    typedef struct Song{
      char title [64];
      char artist [32];
      char album [64];
      uint8_t track; //Used an unsigned 8-bit integer because it's unlikely that track # will exceed 255
      uint16_t year; //Used an unsigned 16-bit integer because year will obviously not exceed 65535
      enum genre{
        Blues,
        Country,
        Electronic,
        Folk,
        HipHop,
        Jazz,
        Latin,
        Pop,
        Rock
      };
    };
  };

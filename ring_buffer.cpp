#include "ring_buffer.h"

RingBuffer::RingBuffer(size_t capacity)
    : buffer_(capacity),
      capacity_(capacity),
      head_(0),
      tail_(0),
      size_(0) {}

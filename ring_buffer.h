#pragma once
#include <vector>
#include <cstddef>

class RingBuffer {
public:
    explicit RingBuffer(size_t capacity);

private:
    std::vector<int> buffer_;
    size_t capacity_;
    size_t head_;
    size_t tail_;
    size_t size_;
};

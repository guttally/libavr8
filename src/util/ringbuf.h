// The MIT License (MIT)
// 
// Copyright (c) 2015 guttally
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef SRC_UTIL_RINGBUF_H_
#define SRC_UTIL_RINGBUF_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint8_t *buf;
  uint8_t size;
  uint8_t head;
  uint8_t tail;
} TinyRingBuf;

static inline uint8_t TinyRingBufGetNewPos(uint8_t curpos, uint8_t size) {
  uint8_t ret = curpos + 1;
  if (ret >= size) ret = 0;
  return ret;
}

static inline bool TinyRingBufIsEmpty(const TinyRingBuf *b) {
  return (b->tail == b->head);
}

static inline bool TinyRingBufIsFull(const TinyRingBuf *b) {
  return (b->tail == TinyRingBufGetNewPos(b->head, b->size));
}

int TinyRingBufPush(TinyRingBuf *b, const void *src, int offset, int len);

static inline uint8_t TinyRingBufPop(TinyRingBuf *b) {
  uint8_t ret = b->buf[b->tail];
  b->tail = TinyRingBufGetNewPos(b->tail, b->size);
  return ret;
}

#endif//SRC_UTIL_RINGBUF_H_
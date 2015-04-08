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

// Define functions to change bit or bits

#ifndef LIBAVR8_UTIL_BITOPE_H_
#define LIBAVR8_UTIL_BITOPE_H_

#include <stdbool.h>
#include <stdint.h>

static inline uint8_t SetBit8(uint8_t src, int8_t offset, bool val) {
  return (src & ~(1 << offset)) | ((uint8_t)val << offset);
}

static inline uint8_t SetMaskedBits8(uint8_t src, uint8_t mask, uint8_t val) {
  return (src & ~mask) | (val & mask);
}

static inline uint16_t SetBit16(uint16_t src, int8_t offset, bool val) {
  return (src & ~(1 << offset)) | ((uint16_t)val << offset);
}

static inline uint16_t SetMaskedBits16(uint16_t src, uint16_t mask, uint16_t val) {
  return (src & ~mask) | (val & mask);
}

#endif//LIBAVR8_UTIL_BITOPE_H_
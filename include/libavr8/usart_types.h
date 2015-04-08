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

#ifndef LIBAVR8_USART_TYPES_H_
#define LIBAVR8_USART_TYPES_H_

typedef enum {
  UsartCharSize5 = 0,
  UsartCharSize6 = 1,
  UsartCharSize7 = 2,
  UsartCharSize8 = 3
} UsartCharSize;

typedef enum {
  UsartParityNone = 0,
  UsartParityEven = 2,
  UsartParityOdd  = 3
} UsartParity;

typedef enum {
  UsartStopBit1 = 0,
  UsartStopBit2 = 1
} UsartStopBit;

#endif//LIBAVR8_USART_TYPES_H_
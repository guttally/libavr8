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

#ifndef LIBAVR8_UART_H_
#define LIBAVR8_UART_H_

#include <stdint.h>

#define LIBAVR8_UART_H_DEVICE_SPECIFIC_
#if defined(__AVR_ATmega328P__)
#  include <libavr8/devices/ATmega328P/uart.h>
#endif
#undef  LIBAVR8_UART_H_DEVICE_SPECIFIC_

#if !defined(COMPILING_LIBAVR8_) && defined(UartSetBaud_DS)
static inline void UartSetBaud(int32_t cpu_freq, int32_t baud, bool double_speed) {
  UartSetBaud_DS(cpu_freq, baud, double_speed);
}
#undef UartSetBaud_DS
#endif

#if !defined(COMPILING_LIBAVR8_) && defined(UartSetFormat_DS)
static inline void UartSetFormat(UsartCharSize char_size, UsartParity parity,
                         UsartStopBit stop_bit) {
  UartSetFormat_DS(char_size, parity, stop_bit);
}
#undef UartSetFormat_DS
#endif

#endif//LIBAVR8_UART_H_
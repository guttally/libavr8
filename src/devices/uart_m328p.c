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

#define __AVR_ATmega328P__

#include <avr/io.h>
#include <libavr8/uart.h>
#include <libavr8/util/bitope.h>

void UartSetBaud_m328p(int32_t cpu_freq, int32_t baud, bool double_speed) {
  UCSR0C = SetMaskedBits8(UCSR0C, 0x3 << UMSEL00, 0);

  int8_t scale = 4 - (int8_t)double_speed;
  int32_t scaled_baud = baud << scale;
  uint16_t ubr = ((cpu_freq + (scaled_baud >> 1)) / scaled_baud) - 1;

  UBRR0 = ubr;
  UCSR0A = SetBit8(UCSR0A, U2X0, double_speed);
}
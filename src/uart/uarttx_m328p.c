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
#include <avr/interrupt.h>
#include <libavr8/uart.h>
#include <libavr8/util/bitope.h>

#include "uarttx.h"

int UartSend_m328p(const void *dat, int offset, int len) {
  UCSR0B = SetBit8(UCSR0B, TXEN0, true);
  int ret = TinyRingBufPush(&txbuf, dat, offset, len);
  if (ret > 0) {
    UCSR0B = SetBit8(UCSR0B, UDRIE0, true);
  }
  return ret;
}

void UartSend_ISR_USART_UDRE_m328p(void) {
  if (!TinyRingBufIsEmpty(&txbuf)) {
    UDR0 = TinyRingBufPop(&txbuf);
  }
  if (TinyRingBufIsEmpty(&txbuf)) {
//    UCSR0B = SetBit8(UCSR0B, UDRIE0, false);
  }
}
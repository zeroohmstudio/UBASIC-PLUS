/*
 * Copyright (c) 2006, Adam Dunkels
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
  
 /*
 * Modified to support simple string variables and functions by David Mitchell
 * November 2008.
 * Changes and additions are marked 'string additions' throughout
 *
 * Modified to support Plus extension by Marijan Kostrun 2018.
 * 
 */
 
#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include "config.h"

enum {
  TOKENIZER_ERROR,
  TOKENIZER_ENDOFINPUT,
  TOKENIZER_NUMBER,
#if defined(VARIABLE_TYPE_STRING)
  TOKENIZER_STRING,
#endif
  TOKENIZER_VARIABLE,
#if defined(VARIABLE_TYPE_STRING)
  // string additions - must be here and in this order  
  TOKENIZER_STRINGVARIABLE,
  TOKENIZER_PRINT$,
  TOKENIZER_LEFT$,
  TOKENIZER_RIGHT$,
  TOKENIZER_MID$,
  TOKENIZER_STR$,
  TOKENIZER_CHR$,
  TOKENIZER_VAL,
  TOKENIZER_LEN,
  TOKENIZER_INSTR,
  TOKENIZER_ASC,
#endif
// end of string additions
  TOKENIZER_LET,
  TOKENIZER_PRINTLN,
  TOKENIZER_PRINT,
  TOKENIZER_IF,
  TOKENIZER_THEN,
  TOKENIZER_ELSE,
  TOKENIZER_ENDIF,
  TOKENIZER_FOR,
  TOKENIZER_TO,
  TOKENIZER_NEXT,
  TOKENIZER_STEP,
  TOKENIZER_WHILE,
  TOKENIZER_ENDWHILE,
  TOKENIZER_GOTO,
  TOKENIZER_GOSUB,
  TOKENIZER_RETURN,
  TOKENIZER_END,
  TOKENIZER_COMMA,
  TOKENIZER_PLUS,
  TOKENIZER_MINUS,
  TOKENIZER_AND,
  TOKENIZER_OR,
  TOKENIZER_ASTR,
  TOKENIZER_SLASH,
  TOKENIZER_MOD,
  TOKENIZER_LEFTPAREN,
  TOKENIZER_RIGHTPAREN,
  TOKENIZER_LT,
  TOKENIZER_GT,
  TOKENIZER_EQ,
  TOKENIZER_EOL,
//
// Plus : Start
//
  TOKENIZER_NE,
  TOKENIZER_GE,
  TOKENIZER_LE,
  TOKENIZER_LAND,
  TOKENIZER_LOR,
  TOKENIZER_LNOT,
  TOKENIZER_NOT,
  TOKENIZER_PRINT_HEX,
  TOKENIZER_PRINT_DEC,
#if defined(UBASIC_SCRIPT_HAVE_INPUT_FROM_SERIAL)
  TOKENIZER_INPUT,
#endif
#if defined(UBASIC_SCRIPT_HAVE_SLEEP)
  TOKENIZER_SLEEP,
#endif
#if defined(UBASIC_SCRIPT_HAVE_GPIO_CHANNELS)
  TOKENIZER_GPIO,
#endif
#if defined(VARIABLE_TYPE_ARRAY)
  TOKENIZER_DIM,
  TOKENIZER_ARRAYVARIABLE,
#endif
#if defined(UBASIC_SCRIPT_HAVE_RANDOM_NUMBER_GENERATOR)
  TOKENIZER_RAN,
#if defined(UBASIC_SCRIPT_HAVE_TICTOC)
  TOKENIZER_TIC,
  TOKENIZER_TOC,
#endif
#endif
#if defined(VARIABLE_TYPE_FLOAT_AS_FIXEDPT_24_8) || defined(VARIABLE_TYPE_FLOAT_AS_FIXEDPT_22_10)
  TOKENIZER_INT,
  TOKENIZER_FLOAT,
  TOKENIZER_SQRT,
  TOKENIZER_SIN,
  TOKENIZER_COS,
  TOKENIZER_TAN,
  TOKENIZER_EXP,
  TOKENIZER_LN,
  #if defined(UBASIC_SCRIPT_HAVE_RANDOM_NUMBER_GENERATOR)
  TOKENIZER_UNIFORM,
  #endif
  TOKENIZER_ABS,
  TOKENIZER_FLOOR,
  TOKENIZER_CEIL,
  TOKENIZER_ROUND,
  TOKENIZER_POWER,
#endif
#if defined(UBASIC_SCRIPT_HAVE_HARDWARE_EVENTS)
  TOKENIZER_HWE,
#endif
#if defined(UBASIC_SCRIPT_HAVE_PWM_CHANNELS)
  TOKENIZER_PWMCONF,
  TOKENIZER_PWM,
#endif
#if defined(UBASIC_SCRIPT_HAVE_ANALOG_READ)
  TOKENIZER_AREAD,
#endif
  TOKENIZER_LABEL,
  TOKENIZER_COLON,
  //
// Plus: End
// 
};

void tokenizer_init(const char *program);
void tokenizer_next(void);
uint8_t tokenizer_token(void);
VARIABLE_TYPE tokenizer_num(void);
VARIABLE_TYPE tokenizer_int(void);

#ifdef FIXEDPT_FBITS
VARIABLE_TYPE tokenizer_float(void);
#endif

uint8_t tokenizer_variable_num(void);

uint8_t tokenizer_finished(void);
void tokenizer_error_print(VARIABLE_TYPE token);

#if defined(VARIABLE_TYPE_STRING)
void tokenizer_string(char *dest, uint8_t len);
// string addition
int8_t tokenizer_stringlookahead(void);
// end of string addition
#endif

void tokenizer_label(char *dest, uint8_t len);
uint16_t  tokenizer_save_offset(void);
void      tokenizer_jump_offset(uint16_t);
uint16_t  tokenizer_line_number(void);

// string addition
#endif /* __TOKENIZER_H__ */

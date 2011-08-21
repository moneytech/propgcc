/* Definitions of target machine for GNU compiler, for CRX.
   Copyright (C) 1991, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,
   2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef GCC_CRX_H
#define GCC_CRX_H

/*****************************************************************************/
/* CONTROLLING THE DRIVER						     */
/*****************************************************************************/

#define CC1PLUS_SPEC "%{!frtti:-fno-rtti} \
    %{!fenforce-eh-specs:-fno-enforce-eh-specs} \
    %{!fexceptions:-fno-exceptions} \
    %{!fthreadsafe-statics:-fno-threadsafe-statics}"

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "crti.o%s crtbegin.o%s"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

#undef MATH_LIBRARY
#define MATH_LIBRARY ""

/*****************************************************************************/
/* RUN-TIME TARGET SPECIFICATION					     */
/*****************************************************************************/

#ifndef TARGET_CPU_CPP_BUILTINS
#define TARGET_CPU_CPP_BUILTINS()				\
do {								\
     builtin_define("__CRX__");					\
     builtin_define("__CR__");		  			\
} while (0)
#endif

#define TARGET_VERSION fputs (" (CRX/ELF)", stderr);

/*****************************************************************************/
/* STORAGE LAYOUT							     */
/*****************************************************************************/

#define BITS_BIG_ENDIAN  0

#define BYTES_BIG_ENDIAN 0

#define WORDS_BIG_ENDIAN 0

#define UNITS_PER_WORD 4

#define POINTER_SIZE 32

#define PARM_BOUNDARY 32

#define STACK_BOUNDARY 32

#define FUNCTION_BOUNDARY 32

#define STRUCTURE_SIZE_BOUNDARY 32

#define BIGGEST_ALIGNMENT 32

/* In CRX arrays of chars are word-aligned, so strcpy() will be faster.  */
#define DATA_ALIGNMENT(TYPE, ALIGN) \
  (TREE_CODE (TYPE) == ARRAY_TYPE && TYPE_MODE (TREE_TYPE (TYPE)) == QImode \
   && (ALIGN) < BITS_PER_WORD \
   ? (BITS_PER_WORD) : (ALIGN))

/* In CRX strings are word-aligned so strcpy from constants will be faster. */
#define CONSTANT_ALIGNMENT(CONSTANT, ALIGN) \
  (TREE_CODE (CONSTANT) == STRING_CST && (ALIGN) < BITS_PER_WORD \
   ? (BITS_PER_WORD) : (ALIGN))

#define STRICT_ALIGNMENT 0

#define PCC_BITFIELD_TYPE_MATTERS 1

/*****************************************************************************/
/* LAYOUT OF SOURCE LANGUAGE DATA TYPES					     */
/*****************************************************************************/

#define INT_TYPE_SIZE		32

#define SHORT_TYPE_SIZE		16

#define LONG_TYPE_SIZE		32

#define LONG_LONG_TYPE_SIZE	64

#define FLOAT_TYPE_SIZE 	32

#define DOUBLE_TYPE_SIZE 	64

#define LONG_DOUBLE_TYPE_SIZE   64

#define DEFAULT_SIGNED_CHAR	1

#define SIZE_TYPE		"unsigned int"

#define PTRDIFF_TYPE		"int"

/*****************************************************************************/
/* REGISTER USAGE.							     */
/*****************************************************************************/

#define FIRST_PSEUDO_REGISTER	19

/* On the CRX, only the stack pointer (r15) is such. */
#define FIXED_REGISTERS \
  { \
 /* r0  r1  r2  r3  r4  r5  r6  r7  r8  r9  r10 */  \
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,	    \
 /* r11 r12 r13 ra  sp  r16 r17 cc */		    \
    0,  0,  0,  0,  1,  0,  0,  1		    \
  }

/* On the CRX, calls clobbers r0-r6 (scratch registers), ra (the return address)
 * and sp - (the stack pointer which is fixed). */
#define CALL_USED_REGISTERS \
  { \
 /* r0  r1  r2  r3  r4  r5  r6  r7  r8  r9  r10 */  \
    1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,	    \
 /* r11 r12 r13 ra  sp  r16 r17 cc */		    \
    0,  0,  0,  1,  1,  1,  1,  1		    \
  }

#define HARD_REGNO_NREGS(REGNO, MODE) \
    ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)

/* On the CRX architecture, HILO regs can only hold SI mode. */
#define HARD_REGNO_MODE_OK(REGNO, MODE) crx_hard_regno_mode_ok(REGNO, MODE)

/* So far no patterns for moving CCMODE data are available */
#define AVOID_CCMODE_COPIES

/* Interrupt functions can only use registers that have already been saved by
 * the prologue, even if they would normally be call-clobbered. */
#define HARD_REGNO_RENAME_OK(SRC, DEST)	\
  (!crx_interrupt_function_p () || df_regs_ever_live_p (DEST))

#define MODES_TIEABLE_P(MODE1, MODE2)  1

enum reg_class
{
  NO_REGS,
  LO_REGS,
  HI_REGS,
  HILO_REGS,
  NOSP_REGS,
  GENERAL_REGS,
  ALL_REGS,
  LIM_REG_CLASSES
};

#define N_REG_CLASSES (int) LIM_REG_CLASSES

/* The following macro defines cover classes for Integrated Register
   Allocator.  Cover classes is a set of non-intersected register
   classes covering all hard registers used for register allocation
   purpose.  Any move between two registers of a cover class should be
   cheaper than load or store of the registers.  The macro value is
   array of register classes with LIM_REG_CLASSES used as the end
   marker.  */

#define IRA_COVER_CLASSES         \
{                                 \
   GENERAL_REGS, LIM_REG_CLASSES  \
} 

#define REG_CLASS_NAMES \
  {			\
    "NO_REGS",		\
    "LO_REGS",		\
    "HI_REGS",		\
    "HILO_REGS",	\
    "NOSP_REGS",	\
    "GENERAL_REGS",	\
    "ALL_REGS"		\
  }

#define REG_CLASS_CONTENTS				\
  {							\
    {0x00000000}, /* NO_REGS			*/	\
    {0x00010000}, /* LO_REGS :		16 	*/	\
    {0x00020000}, /* HI_REGS :		17	*/	\
    {0x00030000}, /* HILO_REGS :	16, 17	*/	\
    {0x00007fff}, /* NOSP_REGS : 	0 - 14	*/	\
    {0x0000ffff}, /* GENERAL_REGS : 	0 - 15	*/	\
    {0x0007ffff}  /* ALL_REGS : 	0 - 18	*/	\
  }

#define REGNO_REG_CLASS(REGNO)  crx_regno_reg_class(REGNO)

#define BASE_REG_CLASS		GENERAL_REGS

#define INDEX_REG_CLASS		GENERAL_REGS

#define REG_CLASS_FROM_LETTER(C)	\
  ((C) == 'b' ? NOSP_REGS :		\
   (C) == 'l' ? LO_REGS : 		\
   (C) == 'h' ? HI_REGS :		\
   (C) == 'k' ? HILO_REGS :		\
  NO_REGS)

#define REGNO_OK_FOR_BASE_P(REGNO) \
  ((REGNO) < 16 \
   || (reg_renumber && (unsigned)reg_renumber[REGNO] < 16))

#define REGNO_OK_FOR_INDEX_P(REGNO)	   REGNO_OK_FOR_BASE_P(REGNO)

#define SECONDARY_RELOAD_CLASS(CLASS, MODE, X) \
  crx_secondary_reload_class (CLASS, MODE, X)

#define CLASS_MAX_NREGS(CLASS, MODE) \
    (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD

#define SIGNED_INT_FITS_N_BITS(imm, N) \
  ((((imm) < ((long long)1<<((N)-1))) && ((imm) >= -((long long)1<<((N)-1)))) ? 1 : 0)

#define UNSIGNED_INT_FITS_N_BITS(imm, N) \
  (((imm) < ((long long)1<<(N)) && (imm) >= (long long)0) ? 1 : 0)

#define HILO_REGNO_P(regno) \
  (reg_classes_intersect_p(REGNO_REG_CLASS(regno), HILO_REGS))

#define INT_CST4(VALUE) \
  (((VALUE) >= -1 && (VALUE) <= 4) || (VALUE) == -4 \
  || (VALUE) == 7 || (VALUE) == 8 || (VALUE) == 16 || (VALUE) == 32 \
  || (VALUE) == 20 || (VALUE) == 12 || (VALUE) == 48)

#define CONST_OK_FOR_LETTER_P(VALUE, C)				\
  /* Legal const for store immediate instructions */		\
  ((C) == 'I' ? UNSIGNED_INT_FITS_N_BITS(VALUE, 3) :		\
   (C) == 'J' ? UNSIGNED_INT_FITS_N_BITS(VALUE, 4) :		\
   (C) == 'K' ? UNSIGNED_INT_FITS_N_BITS(VALUE, 5) :		\
   (C) == 'L' ? INT_CST4(VALUE) :				\
  0)

#define CONST_DOUBLE_OK_FOR_LETTER_P(VALUE, C)	\
  ((C) == 'G' ? crx_const_double_ok (VALUE) :	\
  0)

/*****************************************************************************/
/* STACK LAYOUT AND CALLING CONVENTIONS.				     */
/*****************************************************************************/

#define STACK_GROWS_DOWNWARD

#define STARTING_FRAME_OFFSET  0

#define	STACK_POINTER_REGNUM	15

#define	FRAME_POINTER_REGNUM	13

#define	ARG_POINTER_REGNUM	12

#define STATIC_CHAIN_REGNUM	1

#define	RETURN_ADDRESS_REGNUM	14

#define FIRST_PARM_OFFSET(FNDECL)  0

#define ELIMINABLE_REGS \
  { \
    { ARG_POINTER_REGNUM,   STACK_POINTER_REGNUM}, \
    { ARG_POINTER_REGNUM,   FRAME_POINTER_REGNUM}, \
    { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}  \
  }

#define INITIAL_ELIMINATION_OFFSET(FROM, TO, OFFSET)			\
  do {									\
    (OFFSET) = crx_initial_elimination_offset ((FROM), (TO));		\
  } while (0)

/*****************************************************************************/
/* PASSING FUNCTION ARGUMENTS						     */
/*****************************************************************************/

#define ACCUMULATE_OUTGOING_ARGS (TARGET_NO_PUSH_ARGS)

#define PUSH_ARGS (!TARGET_NO_PUSH_ARGS)

#define PUSH_ROUNDING(BYTES) (((BYTES) + 3) & ~3)

#ifndef CUMULATIVE_ARGS
struct cumulative_args
{
  int ints;
};

#define CUMULATIVE_ARGS struct cumulative_args
#endif

/* On the CRX architecture, Varargs routines should receive their parameters on
 * the stack.  */

#define INIT_CUMULATIVE_ARGS(CUM, FNTYPE, LIBNAME, FNDECL, N_NAMED_ARGS) \
  crx_init_cumulative_args(&(CUM), (FNTYPE), (LIBNAME))

#define FUNCTION_ARG_REGNO_P(REGNO)  crx_function_arg_regno_p(REGNO)

/*****************************************************************************/
/* RETURNING FUNCTION VALUE						     */
/*****************************************************************************/

/* On the CRX, the return value is in R0 */

#define FUNCTION_VALUE(VALTYPE, FUNC) \
	gen_rtx_REG(TYPE_MODE (VALTYPE), 0)

#define LIBCALL_VALUE(MODE)	gen_rtx_REG (MODE, 0)

#define FUNCTION_VALUE_REGNO_P(N)	((N) == 0)

#define CRX_STRUCT_VALUE_REGNUM  0

/*****************************************************************************/
/* GENERATING CODE FOR PROFILING - NOT IMPLEMENTED			     */
/*****************************************************************************/

#undef  FUNCTION_PROFILER
#define FUNCTION_PROFILER(STREAM, LABELNO)	\
{						\
    sorry ("profiler support for CRX");		\
}
	
/*****************************************************************************/
/* TRAMPOLINES FOR NESTED FUNCTIONS - NOT SUPPORTED      		     */
/*****************************************************************************/

#define TRAMPOLINE_SIZE	32

/*****************************************************************************/
/* ADDRESSING MODES							     */
/*****************************************************************************/

#define CONSTANT_ADDRESS_P(X)						\
  (GET_CODE (X) == LABEL_REF						\
   || GET_CODE (X) == SYMBOL_REF					\
   || GET_CODE (X) == CONST						\
   || GET_CODE (X) == CONST_INT)

#define MAX_REGS_PER_ADDRESS 2

#define HAVE_POST_INCREMENT  1
#define HAVE_POST_DECREMENT  1
#define HAVE_POST_MODIFY_DISP 1
#define HAVE_POST_MODIFY_REG 0

#ifdef REG_OK_STRICT
#define REG_OK_FOR_BASE_P(X)	REGNO_OK_FOR_BASE_P (REGNO (X))
#define REG_OK_FOR_INDEX_P(X)	REGNO_OK_FOR_INDEX_P (REGNO (X))
#else
#define REG_OK_FOR_BASE_P(X)	1
#define REG_OK_FOR_INDEX_P(X)	1
#endif /* REG_OK_STRICT */

#define LEGITIMATE_CONSTANT_P(X)  1

/*****************************************************************************/
/* CONDITION CODE STATUS						     */
/*****************************************************************************/

/*****************************************************************************/
/* RELATIVE COSTS OF OPERATIONS						     */
/*****************************************************************************/

#define MEMORY_MOVE_COST(MODE, CLASS, IN) crx_memory_move_cost(MODE, CLASS, IN)
/* Moving to processor register flushes pipeline - thus asymmetric */
#define REGISTER_MOVE_COST(MODE, FROM, TO) ((TO != GENERAL_REGS) ? 8 : 2)
/* Assume best case (branch predicted) */
#define BRANCH_COST(speed_p, predictable_p) 2

#define SLOW_BYTE_ACCESS  1

/*****************************************************************************/
/* DIVIDING THE OUTPUT INTO SECTIONS					     */
/*****************************************************************************/

#define TEXT_SECTION_ASM_OP	"\t.section\t.text"

#define DATA_SECTION_ASM_OP	"\t.section\t.data"

#define BSS_SECTION_ASM_OP	"\t.section\t.bss"

/*****************************************************************************/
/* POSITION INDEPENDENT CODE						     */
/*****************************************************************************/

#define PIC_OFFSET_TABLE_REGNUM  12

#define LEGITIMATE_PIC_OPERAND_P(X)  1

/*****************************************************************************/
/* ASSEMBLER FORMAT							     */
/*****************************************************************************/

#define GLOBAL_ASM_OP "\t.globl\t"

#undef	USER_LABEL_PREFIX
#define	USER_LABEL_PREFIX "_"

#undef	ASM_OUTPUT_LABELREF
#define ASM_OUTPUT_LABELREF(STREAM, NAME) \
  asm_fprintf (STREAM, "%U%s", (*targetm.strip_name_encoding) (NAME));

#undef	ASM_APP_ON
#define ASM_APP_ON   "#APP\n"

#undef	ASM_APP_OFF
#define ASM_APP_OFF  "#NO_APP\n"

/*****************************************************************************/
/* INSTRUCTION OUTPUT							     */
/*****************************************************************************/

#define REGISTER_NAMES \
  { \
    "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7", \
    "r8",  "r9",  "r10", "r11", "r12", "r13", "ra",  "sp", \
    "lo",  "hi",  "cc" \
  }

#define PRINT_OPERAND(STREAM, X, CODE) \
  crx_print_operand(STREAM, X, CODE)

#define PRINT_OPERAND_ADDRESS(STREAM, ADDR) \
  crx_print_operand_address(STREAM, ADDR)

/*****************************************************************************/
/* OUTPUT OF DISPATCH TABLES						     */
/*****************************************************************************/

#define ASM_OUTPUT_ADDR_VEC_ELT(STREAM, VALUE) \
  asm_fprintf ((STREAM), "\t.long\t.L%d\n", (VALUE))

/*****************************************************************************/
/* ALIGNMENT IN ASSEMBLER FILE						     */
/*****************************************************************************/

#define ASM_OUTPUT_ALIGN(STREAM, POWER) \
  asm_fprintf ((STREAM), "\t.align\t%d\n", 1 << (POWER))

/*****************************************************************************/
/* MISCELLANEOUS PARAMETERS						     */
/*****************************************************************************/

#define CASE_VECTOR_MODE  Pmode

#define MOVE_MAX 4

#define TRULY_NOOP_TRUNCATION(OUTPREC, INPREC)  1

#define STORE_FLAG_VALUE  1

#define Pmode		SImode

#define FUNCTION_MODE	QImode

#endif /* ! GCC_CRX_H */

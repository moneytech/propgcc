#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

  /* this has to match lldiv_t in stdlib.h */
  typedef struct {
    long long quot, rem;
  } imaxdiv_t;

#define PRId8 "%hhd"
#define PRIi8 "%hhi"

#define PRId16 "%hd"
#define PRIi16 "%hd"
#if _INT_SIZE == 4
#define PRId32 "%d"
#define PRIi32 "%i"
#elif _LONG_SIZE == 4
#define PRId32 "%ld"
#define PRIi32 "%li"
#else
#error "compiler not supported"
#endif
#define PRId64 "%lld"
#define PRIi64 "%lli"

#define PRIdPTR "%td"
#define PRIiPTR "%td"
#define PRIdMAX "%jd"
#define PRIiMAX "%ji"

#define PRIdLEAST8  PRId8
#define PRIiLEAST8  PRIi8
#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64

#define PRIdFAST8  "%d"
#define PRIdFAST16 "%d"
#define PRIdFAST32 "%d"
#define PRIdFAST64 "%lld"
#define PRIiFAST8  "%i"
#define PRIiFAST16 "%i"
#define PRIiFAST32 "%i"
#define PRIiFAST64 "%lli"

  /* unsigned modifiers */
#define PRIo8 "%hho"
#define PRIu8 "%hhu"
#define PRIx8 "%hhx"
#define PRIX8 "%hhX"

#define PRIo16 "%ho"
#define PRIu16 "%hu"
#define PRIx16 "%hx"
#define PRIX16 "%hX"

#if _INT_SIZE == 4
#define PRIo32 "%o"
#define PRIu32 "%u"
#define PRIx32 "%x"
#define PRIX32 "%X"
#else
#define PRIo32 "%lo"
#define PRIu32 "%lu"
#define PRIx32 "%lx"
#define PRIX32 "%lX"
#endif

#define PRIo64 "%llo"
#define PRIu64 "%llu"
#define PRIx64 "%llx"
#define PRIX64 "%llX"

#define PRIoLEAST8 PRIo8
#define PRIuLEAST8 PRIu8
#define PRIxLEAST8 PRIx8
#define PRIXLEAST8 PRIX8

#define PRIoLEAST16 PRIo16
#define PRIuLEAST16 PRIu16
#define PRIxLEAST16 PRIx16
#define PRIXLEAST16 PRIX16

#define PRIoLEAST32 PRIo32
#define PRIuLEAST32 PRIu32
#define PRIxLEAST32 PRIx32
#define PRIXLEAST32 PRIX32

#define PRIoLEAST64 PRIo64
#define PRIuLEAST64 PRIu64
#define PRIxLEAST64 PRIx64
#define PRIXLEAST64 PRIX64

#define PRIoFAST8 "%o"
#define PRIuFAST8 "%u"
#define PRIxFAST8 "%x"
#define PRIXFAST8 "%X"

#define PRIoFAST16 PRIoFAST8
#define PRIuFAST16 PRIuFAST8
#define PRIxFAST16 PRIxFAST8
#define PRIXFAST16 PRIXFAST8

#define PRIoFAST32 PRIo32
#define PRIuFAST32 PRIu32
#define PRIxFAST32 PRIx32
#define PRIXFAST32 PRIX32

#define PRIoFAST64 PRIo64
#define PRIuFAST64 PRIu64
#define PRIxFAST64 PRIx64
#define PRIXFAST64 PRIX64

#define PRIoMAX "%jo"
#define PRIuMAX "%ju"
#define PRIxMAX "%jx"
#define PRIXMAX "%jX"

#define PRIoPTR "%to"
#define PRIuPTR "%tu"
#define PRIxPTR "%tx"
#define PRIXPTR "%tX"

  /* scan flags */

  /* signed */
#define SCNd8  PRId8
#define SCNi8  PRIi8
#define SCNd16 PRId16
#define SCNi16 PRIi16
#define SCNd32 PRId32
#define SCNi32 PRIi32
#define SCNd64 PRId64
#define SCNi64 PRIi64

#define SCNdLEAST8  PRIdLEAST8
#define SCNiLEAST8  PRIiLEAST8
#define SCNdLEAST16 PRIdLEAST16
#define SCNiLEAST16 PRIiLEAST16
#define SCNdLEAST32 PRIdLEAST32
#define SCNiLEAST32 PRIiLEAST32
#define SCNdLEAST64 PRIdLEAST64
#define SCNiLEAST64 PRIiLEAST64

#define SCNdFAST8  PRIdFAST8
#define SCNiFAST8  PRIiFAST8
#define SCNdFAST16 PRIdFAST16
#define SCNiFAST16 PRIiFAST16
#define SCNdFAST32 PRIdFAST32
#define SCNiFAST32 PRIiFAST32
#define SCNdFAST64 PRIdFAST64
#define SCNiFAST64 PRIiFAST64

#define SCNdPTR PRIdPTR
#define SCNiPTR PRIdPTR
#define SCNdMAX PRIdMAX
#define SCNiMAX PRIdMAX

  /* unsigned */
#define SCNo8 PRIo8
#define SCNu8 PRIu8
#define SCNx8 PRIx8
#define SCNo16 PRIo16
#define SCNu16 PRIu16
#define SCNx16 PRIx16
#define SCNo32 PRIo32
#define SCNu32 PRIu32
#define SCNx32 PRIx32
#define SCNo64 PRIo64
#define SCNu64 PRIu64
#define SCNx64 PRIx64

#define SCNo8LEAST PRIo8LEAST
#define SCNu8LEAST PRIu8LEAST
#define SCNx8LEAST PRIx8LEAST
#define SCNo16LEAST PRIo16LEAST
#define SCNu16LEAST PRIu16LEAST
#define SCNx16LEAST PRIx16LEAST
#define SCNo32LEAST PRIo32LEAST
#define SCNu32LEAST PRIu32LEAST
#define SCNx32LEAST PRIx32LEAST
#define SCNo64LEAST PRIo64LEAST
#define SCNu64LEAST PRIu64LEAST
#define SCNx64LEAST PRIx64LEAST

#define SCNo8FAST PRIo8FAST
#define SCNu8FAST PRIu8FAST
#define SCNx8FAST PRIx8FAST
#define SCNo16FAST PRIo16FAST
#define SCNu16FAST PRIu16FAST
#define SCNx16FAST PRIx16FAST
#define SCNo32FAST PRIo32FAST
#define SCNu32FAST PRIu32FAST
#define SCNx32FAST PRIx32FAST
#define SCNo64FAST PRIo64FAST
#define SCNu64FAST PRIu64FAST
#define SCNx64FAST PRIx64FAST

#define SCNoMAX PRIoMAX
#define SCNuMAX PRIuMAX
#define SCNxMAX PRIxMAX

#define SCNoPTR PRIoPTR
#define SCNuPTR PRIuPTR
#define SCNxPTR PRIxPTR

  /* function defintions */
  intmax_t imaxabs(intmax_t);
  imaxdiv_t imaxdiv(intmax_t, intmax_t);
  intmax_t strtoimax(const char *__restrict, char **__restrict, int);
  uintmax_t strtouimax(const char *__restrict, char **__restrict, int);

#ifdef __cplusplus
}
#endif

#endif
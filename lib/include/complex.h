#ifndef _COMPLEX_H
#define _COMPLEX_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__GNUC__)
#define _Complex_I (__extension__ 1.0iF)
#else
#define _Complex_I _Complex_I is not supported on this compiler
#endif

#define complex _Complex
#define I _Complex_I

  double complex cacos(double complex z);
  float complex cacosf(float complex z);
  long double complex cacosl(long double complex z);

  double complex casin(double complex z);
  float complex casinf(float complex z);
  long double complex casinl(long double complex z);

  double complex catan(double complex z);
  float complex catanf(float complex z);
  long double complex catanl(long double complex z);

  double complex ccos(double complex z);
  float complex ccosf(float complex z);
  long double complex ccosl(long double complex z);

  double complex csin(double complex z);
  float complex csinf(float complex z);
  long double complex csinl(long double complex z);

  double complex ctan(double complex z);
  float complex ctanf(float complex z);
  long double complex ctanl(long double complex z);

  double complex cacosh(double complex z);
  float complex cacoshf(float complex z);
  long double complex cacoshl(long double complex z);

  double complex casinh(double complex z);
  float complex casinhf(float complex z);
  long double complex casinhl(long double complex z);

  double complex catanh(double complex z);
  float complex catanhf(float complex z);
  long double complex catanhl(long double complex z);

  double complex ccosh(double complex z);
  float complex ccoshf(float complex z);
  long double complex ccoshl(long double complex z);

  double complex csinh(double complex z);
  float complex csinhf(float complex z);
  long double complex csinhl(long double complex z);

  double complex ctanh(double complex z);
  float complex ctanhf(float complex z);
  long double complex ctanhl(long double complex z);

  /* exponential and logarithm functions */
  double complex cexp(double complex z);
  float complex cexpf(float complex z);
  long double complex cexpl(long double complex z);

  double complex clog(double complex z);
  float complex clogf(float complex z);
  long double complex clogl(long double complex z);

  /* power and absolute value */
  double complex cpow(double complex x, double complex y);
  float complex cpowf(float complex x, float complex y);
  long double complex cpowl(long double complex x, long double complex y);

  double cabs(double complex z);
  float  cabsf(float complex z);
  long double cabsl(long double complex z);

  double complex csqrt(double complex z);
  float complex csqrtf(float complex z);
  long double complex csqrtl(long double complex z);

  /* manipulation functions */
  double carg(double complex z);
  float  cargf(float complex z);
  long double cargl(long double complex z);

  double cimag(double complex z);
  float  cimagf(float complex z);
  long double cimagl(long double complex z);
  double creal(double complex z);
  float  crealf(float complex z);
  long double creall(long double complex z);

  double complex conj(double complex z);
  float complex conjf(float complex z);
  long double complex conjl(long double complex z);

  double complex cproj(double complex z);
  float complex cprojf(float complex z);
  long double complex cprojl(long double complex z);

#if defined(__cplusplus)
}
#endif

#endif /* _COMPLEX_H */

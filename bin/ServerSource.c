       
typedef long unsigned int size_t;
typedef int wchar_t;

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) atoi (const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline __attribute__ ((__gnu_inline__)) long int
__attribute__ ((__nothrow__ , __leaf__)) atol (const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}
__extension__ extern __inline __attribute__ ((__gnu_inline__)) long long int
__attribute__ ((__nothrow__ , __leaf__)) atoll (const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
extern long int __fdelt_chk (long int __d);
extern long int __fdelt_warn (long int __d)
  __attribute__((__warning__ ("bit outside of fd_set selected")));

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) __attribute__ ((__warn_unused_result__));
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) __attribute__ ((__warn_unused_result__));
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) __attribute__ ((__warn_unused_result__));
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int system (const char *__command) __attribute__ ((__warn_unused_result__));
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
  __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (const void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
 __u = __idx;
      else if (__comparison > 0)
 __l = __idx + 1;
      else
 {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
   return (void *) __p;
#pragma GCC diagnostic pop
 }
    }
  return ((void *)0);
}
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) __attribute__ ((__warn_unused_result__));
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) __attribute__ ((__warn_unused_result__));
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__warn_unused_result__));
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __inline __attribute__ ((__gnu_inline__)) double
__attribute__ ((__nothrow__ , __leaf__)) atof (const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}
extern char *__realpath_chk (const char *__restrict __name,
        char *__restrict __resolved,
        size_t __resolvedlen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__realpath_alias (const char *__restrict __name, char *__restrict __resolved) __asm__ ("" "realpath") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__realpath_chk_warn (const char *__restrict __name, char *__restrict __resolved, size_t __resolvedlen) __asm__ ("" "__realpath_chk") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__((__warning__ ("second argument of realpath must be either NULL or at " "least PATH_MAX bytes long buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) realpath (const char *__restrict __name, char *__restrict __resolved)
{
  size_t sz = __builtin_object_size (__resolved, 2 > 1);
  if (sz == (size_t) -1)
    return __realpath_alias (__name, __resolved);
  return __realpath_chk (__name, __resolved, sz);
}
extern int __ptsname_r_chk (int __fd, char *__buf, size_t __buflen,
       size_t __nreal) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int __ptsname_r_alias (int __fd, char *__buf, size_t __buflen) __asm__ ("" "ptsname_r") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int __ptsname_r_chk_warn (int __fd, char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__ptsname_r_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2))) __attribute__((__warning__ ("ptsname_r called with buflen bigger than " "size of buf")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) ptsname_r (int __fd, char *__buf, size_t __buflen)
{
  return ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __ptsname_r_alias (__fd, __buf, __buflen) : ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __ptsname_r_chk_warn (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1)) : __ptsname_r_chk (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1))));
}
extern int __wctomb_chk (char *__s, wchar_t __wchar, size_t __buflen)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int __wctomb_alias (char *__s, wchar_t __wchar) __asm__ ("" "wctomb") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) int
__attribute__ ((__nothrow__ , __leaf__)) wctomb (char *__s, wchar_t __wchar)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1
      && 16 > __builtin_object_size (__s, 2 > 1))
    return __wctomb_chk (__s, __wchar, __builtin_object_size (__s, 2 > 1));
  return __wctomb_alias (__s, __wchar);
}
extern size_t __mbstowcs_chk (wchar_t *__restrict __dst,
         const char *__restrict __src,
         size_t __len, size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 1, 3))) __attribute__ ((__access__ (__read_only__, 2)));
extern size_t __mbstowcs_alias (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len) __asm__ ("" "mbstowcs") __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 1, 3))) __attribute__ ((__access__ (__read_only__, 2)));
extern size_t __mbstowcs_chk_warn (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len, size_t __dstlen) __asm__ ("" "__mbstowcs_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("mbstowcs called with dst buffer smaller than len " "* sizeof (wchar_t)")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) mbstowcs (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len)
{
  return ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t)))) && (((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t)))) ? __mbstowcs_alias (__dst, __src, __len) : ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t)))) && !(((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t)))) ? __mbstowcs_chk_warn (__dst, __src, __len, (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t))) : __mbstowcs_chk (__dst, __src, __len, (__builtin_object_size (__dst, 2 > 1)) / (sizeof (wchar_t)))));
}
extern size_t __wcstombs_chk (char *__restrict __dst,
         const wchar_t *__restrict __src,
         size_t __len, size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3))) __attribute__ ((__access__ (__read_only__, 2)));
extern size_t __wcstombs_alias (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len) __asm__ ("" "wcstombs") __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3))) __attribute__ ((__access__ (__read_only__, 2)));
extern size_t __wcstombs_chk_warn (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len, size_t __dstlen) __asm__ ("" "__wcstombs_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wcstombs called with dst buffer smaller than len")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) wcstombs (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len)
{
  return ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (char)))) ? __wcstombs_alias (__dst, __src, __len) : ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__len)) <= (__builtin_object_size (__dst, 2 > 1)) / (sizeof (char)))) ? __wcstombs_chk_warn (__dst, __src, __len, __builtin_object_size (__dst, 2 > 1)) : __wcstombs_chk (__dst, __src, __len, __builtin_object_size (__dst, 2 > 1))));
}

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
       
typedef long int ptrdiff_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
struct WebSocketServer_t;
typedef struct WebSocketServer_t WebSocketServer;
typedef WebSocketServer *PWebSocketServer;
typedef enum {
  OPCODE_CONTINUATION_FRAME = 0x0,
  OPCODE_TEXT_FRAME = 0x1,
  OPCODE_BINARY = 0x2,
  OPCODE_CONNECTION_CLOSE = 0x8,
  OPCODE_PING = 0x9,
  OPCODE_PONG = 0xA
} Opcode;
typedef struct Auth_t {
  uint8_t bff[8];
} Auth;
typedef Auth *PAuth;
typedef struct EventBuffer_t {
  char *buffer;
  uint32_t size;
} EventBuffer;
typedef EventBuffer *PEventBuffer;
typedef struct EventMessage_t {
  uint8_t isAuthed;
  uint32_t headerCode;
  Auth uniqueCode;
  EventBuffer str;
} EventMessage;
typedef struct WebSocketObject_t {
  char *buffer;
  size_t sz;
  uint8_t opcode;
  char *_fullMessage;
} WebSocketObject;
typedef WebSocketObject *PWebSocketObject;
typedef EventMessage *PEventMessage;
typedef struct SocketMethod_t {
  void *method;
  void *mirrorBuffer;
} SocketMethod;
typedef struct Connection_t {
  int32_t fd;
} Connection;
typedef struct DataFragment_t {
  uint32_t size;
  uint8_t persistent;
  Connection conn;
  char *data;
} DataFragment;
typedef SocketMethod *PSocketMethod;
typedef Connection *PConnection;
typedef DataFragment *PDataFragment;
typedef struct EventServer_t {
  PWebSocketServer wsServer;
  PSocketMethod onReceive;
  PSocketMethod onClose;
} EventServer;
typedef struct ResponseObject_t {
  EventMessage metaData;
  PConnection conn;
} ResponseObject;
typedef ResponseObject *PResponseObject;
typedef EventServer *PEventServer;
typedef struct PrivateMethodsBundle_t {
  PSocketMethod _onConnect;
  PSocketMethod _onReceive;
  PSocketMethod _onRelease;
} PrivateMethodsBundle;
typedef struct TimeMethod_t {
  void *method;
  void *buffer;
} TimeMethod;
typedef struct TimeFragment_t {
  TimeMethod methodFragment;
  int64_t executeAfter;
  int64_t time;
} TimeFragment;
struct Array_t {
  void *buffer;
  size_t size;
  size_t capacity;
  size_t objSize;
};
typedef struct Array_t *Array;
typedef struct TimeServer_t {
  Array methods;
  Array loopMethods;
} TimeServer;
typedef TimeServer *PTimeServer;
typedef struct Timeout_t {
  uint64_t timeout;
  PTimeServer server;
} Timeout;
typedef Timeout *PTimeout;
typedef struct Timers_t {
  PTimeServer timeServer;
  int64_t timeout;
} Timers;
typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
  int32_t maxBytesPerReadConnection;
  Connection serverFD;
  Array connections;
  Array inputReads;
  Array outputCommands;
  Array closeConnectionsQueue;
  PSocketMethod onConnectionRelease;
  PSocketMethod onConnectionAquire;
  PSocketMethod onReceiveMessage;
  Timers timeServer;
} SocketServer;
typedef SocketServer *PSocketServer;
typedef struct WebSocketServer_t {
  PSocketServer socketServer;
  PSocketMethod onConnect;
  PSocketMethod onReceiveMessage;
  PSocketMethod onRelease;
  PrivateMethodsBundle methodsBundle;
  Array pendingConnections;
  Array pendingPingRequests;
  Array activeConnections;
  PTimeout timeServer;
  size_t maxBSize;
  size_t maxBSizeForHttpReq;
} WebSocketServer;
typedef WebSocketServer *PWebSocketServer;
typedef enum {
  GET,
  POST,
  PUT,
  PATCH,
  DELETE
} HttpAction;
typedef struct HttpString_t {
  char *buffer;
  size_t sz;
} HttpString;
typedef HttpString *PHttpString;
typedef struct URL_t {
  HttpString path;
  char httpType[16];
  HttpAction method;
} URL;
typedef URL *PURL;
typedef struct HttpMetaData_t {
  HttpString codes[10];
  size_t actionsSz;
} HttpMetaData;
typedef HttpMetaData *PHttpMetaData;
typedef struct TrieNode_t *PTrieNode;
typedef struct Hsh_t {
  uint32_t count;
  PTrieNode parentNode;
} Hsh;
typedef Hsh *PHsh;
typedef struct TrieNode_t {
  uint32_t count;
  void *buffer;
  PTrieNode *nextNodes;
} TrieNode;
typedef struct Key_t {
  char *key;
  uint32_t keySize;
} Key;
typedef struct Hash_t {
  PHsh hash;
  PHsh valuesSize;
} Hash;
typedef struct HttpRequest_t {
  Hash headers;
  PURL url;
  HttpString body;
  char *_endBuffer;
  PHttpMetaData metadata;
} HttpRequest;
typedef HttpRequest *PHttpRequest;
typedef struct HttpResponse_t {
  char *httpCode;
  Hash headers;
  HttpString body;
  uint16_t response;
} HttpResponse;
typedef HttpResponse *PHttpResponse;
typedef enum {
  JSON_INVALID,
  JSON_NULL,
  JSON_INTEGER,
  JSON_NUMBER,
  JSON_STRING,
  JSON_BOOLEAN,
  JSON_JSON,
  JSON_ARRAY
} JsonType;
typedef enum {
  RESPONSE_TIMEOUT,
  RESPONSE_PARSE_ERROR
} RequestError;
typedef struct JsonElement_t {
  void *value;
  JsonType type;
} JsonElement;
typedef JsonElement *PJsonElement;
typedef struct JsonObject_t {
  PHsh hsh;
  uint8_t selfContained;
} JsonObject;
typedef JsonObject *PJsonObject;
typedef struct HttpServer_t {
  PSocketServer server;
  PSocketMethod onReceive;
  Array connections;
  size_t maximumRequestSize;
} HttpServer;
typedef HttpServer *PHttpServer;
typedef struct HttpRequestServer_t {
  Array requests;
  int64_t timeoutMS;
  size_t maxSizeInB;
} HttpRequestServer;
typedef HttpRequestServer *PHttpRequestServer;
typedef struct RequestStruct_t {
  uint16_t port;
  char ip[17];
  HttpString query;
  PSocketMethod onSuccess;
  PSocketMethod onFailure;
} RequestStruct;
typedef struct JWT_t {
  JsonElement header;
  JsonElement payload;
} JWT;
typedef JWT *PJWT;
typedef struct NetworkBuffer_t {
  void *buffer;
  void *currentBuffer;
  size_t size;
  size_t capacity;
  size_t maxRetriedSize;
  size_t maxSizeB;
} NetworkBuffer;
typedef NetworkBuffer *PNetworkBuffer;
typedef struct User_t {
  uint64_t ID;
  PConnection conn;
  uint8_t active;
} User;
typedef User *PUser;
typedef struct UserData_t {
  Array users;
} UserData;
typedef UserData *PUserData;
typedef struct Manager_t {
  PUserData userData;
  PWebSocketServer server;
  PHttpServer httpServer;
  HttpString hmacKey;
  Array pendingConnections;
  Array timeoutConnectionCheckers;
  PTimeServer timeServer;
  PSocketMethod onLogin;
  PSocketMethod onReceive;
  PSocketMethod onDisconnect;
} Manager;
typedef Manager *PManager;
Array arr_Init(size_t size);
Array arr_InitWithCapacity(size_t size, size_t count);
void arr_Push(Array self, void *buffer);
void arr_Delete(Array self);
void arr_DeleteWOBuffer(Array self);
void arr_Clear(Array self);
void arr_RemoveElement(Array payload, size_t index);
Array arr_RemoveElements(Array payload, Array indexes);
int64_t arr_Find(Array payload, void *element);
Array arr_InitWithSize(size_t objSize, size_t count);
char *arr_Last(Array self);
void arr_Pop(Array self);
void arr_RemoveElementsWithReplacing(Array *self, Array indexes);

extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void
__attribute__ ((__nothrow__ , __leaf__)) bcopy (const void *__src, void *__dest, size_t __len)
{
  (void) __builtin___memmove_chk (__dest, __src, __len,
      __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void
__attribute__ ((__nothrow__ , __leaf__)) bzero (void *__dest, size_t __len)
{
  (void) __builtin___memset_chk (__dest, '\0', __len,
     __builtin_object_size (__dest, 0));
}
extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memcpy (void *__restrict __dest, const void *__restrict __src, size_t __len)
{
  return __builtin___memcpy_chk (__dest, __src, __len,
     __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memmove (void *__dest, const void *__src, size_t __len)
{
  return __builtin___memmove_chk (__dest, __src, __len,
      __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memset (void *__dest, int __ch, size_t __len)
{
  return __builtin___memset_chk (__dest, __ch, __len,
     __builtin_object_size (__dest, 0));
}
void __explicit_bzero_chk (void *__dest, size_t __len, size_t __destlen)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void
__attribute__ ((__nothrow__ , __leaf__)) explicit_bzero (void *__dest, size_t __len)
{
  __explicit_bzero_chk (__dest, __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strcpy (char *__restrict __dest, const char *__restrict __src)
{
  return __builtin___strcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) stpcpy (char *__restrict __dest, const char *__restrict __src)
{
  return __builtin___stpcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strncpy (char *__restrict __dest, const char *__restrict __src, size_t __len)
{
  return __builtin___strncpy_chk (__dest, __src, __len,
      __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) stpncpy (char *__dest, const char *__src, size_t __n)
{
  return __builtin___stpncpy_chk (__dest, __src, __n,
      __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strcat (char *__restrict __dest, const char *__restrict __src)
{
  return __builtin___strcat_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strncat (char *__restrict __dest, const char *__restrict __src, size_t __len)
{
  return __builtin___strncat_chk (__dest, __src, __len,
      __builtin_object_size (__dest, 2 > 1));
}


typedef __builtin_va_list __gnuc_va_list;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int fclose (FILE *__stream);
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) __attribute__ ((__warn_unused_result__));
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) __attribute__ ((__warn_unused_result__));
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) __attribute__ ((__warn_unused_result__));
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) __attribute__ ((__warn_unused_result__));
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) __attribute__ ((__warn_unused_result__));
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__warn_unused_result__));
extern int scanf (const char *__restrict __format, ...) __attribute__ ((__warn_unused_result__));
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") __attribute__ ((__warn_unused_result__));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") __attribute__ ((__warn_unused_result__));
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__warn_unused_result__));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __attribute__ ((__warn_unused_result__));
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__warn_unused_result__));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) __attribute__ ((__warn_unused_result__));
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) __attribute__ ((__warn_unused_result__));
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) __attribute__ ((__warn_unused_result__));
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void perror (const char *__s);
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) __attribute__ ((__warn_unused_result__));
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
extern __inline __attribute__ ((__gnu_inline__)) int
getchar (void)
{
  return getc (stdin);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar (int __c)
{
  return putc (__c, stdout);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x0010) != 0);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x0020) != 0);
}
extern int __sprintf_chk (char *__restrict __s, int __flag, size_t __slen,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 1, 3)));
extern int __vsprintf_chk (char *__restrict __s, int __flag, size_t __slen,
      const char *__restrict __format,
      __gnuc_va_list __ap) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 1, 3)));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) sprintf (char *__restrict __s, const char *__restrict __fmt, ...)
{
  return __builtin___sprintf_chk (__s, 2 - 1,
      __builtin_object_size (__s, 2 > 1), __fmt,
      __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) vsprintf (char *__restrict __s, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __builtin___vsprintf_chk (__s, 2 - 1,
       __builtin_object_size (__s, 2 > 1), __fmt, __ap);
}
extern int __snprintf_chk (char *__restrict __s, size_t __n, int __flag,
      size_t __slen, const char *__restrict __format,
      ...) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __vsnprintf_chk (char *__restrict __s, size_t __n, int __flag,
       size_t __slen, const char *__restrict __format,
       __gnuc_va_list __ap) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) snprintf (char *__restrict __s, size_t __n, const char *__restrict __fmt, ...)
{
  return __builtin___snprintf_chk (__s, __n, 2 - 1,
       __builtin_object_size (__s, 2 > 1), __fmt,
       __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) vsnprintf (char *__restrict __s, size_t __n, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __builtin___vsnprintf_chk (__s, __n, 2 - 1,
        __builtin_object_size (__s, 2 > 1), __fmt, __ap);
}
extern int __fprintf_chk (FILE *__restrict __stream, int __flag,
     const char *__restrict __format, ...);
extern int __printf_chk (int __flag, const char *__restrict __format, ...);
extern int __vfprintf_chk (FILE *__restrict __stream, int __flag,
      const char *__restrict __format, __gnuc_va_list __ap);
extern int __vprintf_chk (int __flag, const char *__restrict __format,
     __gnuc_va_list __ap);
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
fprintf (FILE *__restrict __stream, const char *__restrict __fmt, ...)
{
  return __fprintf_chk (__stream, 2 - 1, __fmt,
   __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
printf (const char *__restrict __fmt, ...)
{
  return __printf_chk (2 - 1, __fmt, __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vprintf (const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vfprintf_chk (stdout, 2 - 1, __fmt, __ap);
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vfprintf (FILE *__restrict __stream,
   const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vfprintf_chk (__stream, 2 - 1, __fmt, __ap);
}
extern int __dprintf_chk (int __fd, int __flag, const char *__restrict __fmt,
     ...) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int __vdprintf_chk (int __fd, int __flag,
      const char *__restrict __fmt, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 3, 0)));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
dprintf (int __fd, const char *__restrict __fmt, ...)
{
  return __dprintf_chk (__fd, 2 - 1, __fmt,
   __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vdprintf (int __fd, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vdprintf_chk (__fd, 2 - 1, __fmt, __ap);
}
extern char *__fgets_chk (char *__restrict __s, size_t __size, int __n,
     FILE *__restrict __stream)
    __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern char *__fgets_alias (char *__restrict __s, int __n, FILE *__restrict __stream) __asm__ ("" "fgets")
    __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *__fgets_chk_warn (char *__restrict __s, size_t __size, int __n, FILE *__restrict __stream) __asm__ ("" "__fgets_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fgets called with bigger size than length " "of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2))) char *
fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
{
  size_t sz = __builtin_object_size (__s, 2 > 1);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && (((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_alias (__s, __n, __stream);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_chk_warn (__s, sz, __n, __stream);
  return __fgets_chk (__s, sz, __n, __stream);
}
extern size_t __fread_chk (void *__restrict __ptr, size_t __ptrlen,
      size_t __size, size_t __n,
      FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t __fread_alias (void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "fread") __attribute__ ((__warn_unused_result__));
extern size_t __fread_chk_warn (void *__restrict __ptr, size_t __ptrlen, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "__fread_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fread called with bigger size * nmemb than length " "of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) size_t
fread (void *__restrict __ptr, size_t __size, size_t __n,
       FILE *__restrict __stream)
{
  size_t sz = __builtin_object_size (__ptr, 0);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && (((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_alias (__ptr, __size, __n, __stream);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && !(((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_chk_warn (__ptr, sz, __size, __n, __stream);
  return __fread_chk (__ptr, sz, __size, __n, __stream);
}
extern size_t __fread_unlocked_chk (void *__restrict __ptr, size_t __ptrlen,
        size_t __size, size_t __n,
        FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t __fread_unlocked_alias (void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "fread_unlocked") __attribute__ ((__warn_unused_result__));
extern size_t __fread_unlocked_chk_warn (void *__restrict __ptr, size_t __ptrlen, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "__fread_unlocked_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fread_unlocked called with bigger size * nmemb than " "length of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) size_t
fread_unlocked (void *__restrict __ptr, size_t __size, size_t __n,
  FILE *__restrict __stream)
{
  size_t sz = __builtin_object_size (__ptr, 0);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && (((long unsigned int) (__n)) <= (sz) / (__size))))
    {
      if (__builtin_constant_p (__size)
   && __builtin_constant_p (__n)
   && (__size | __n) < (((size_t) 1) << (8 * sizeof (size_t) / 2))
   && __size * __n <= 8)
 {
   size_t __cnt = __size * __n;
   char *__cptr = (char *) __ptr;
   if (__cnt == 0)
     return 0;
   for (; __cnt > 0; --__cnt)
     {
       int __c = getc_unlocked (__stream);
       if (__c == (-1))
  break;
       *__cptr++ = __c;
     }
   return (__cptr - (char *) __ptr) / __size;
 }
      return __fread_unlocked_alias (__ptr, __size, __n, __stream);
    }
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && !(((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_unlocked_chk_warn (__ptr, sz, __size, __n, __stream);
  return __fread_unlocked_chk (__ptr, sz, __size, __n, __stream);
}


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

Array arr_Init(size_t size) {
  Array self = (Array)malloc(sizeof(struct Array_t));
  self->buffer = malloc(size);
  self->size = 0;
  self->capacity = 1;
  self->objSize = size;
  return self;
}
Array arr_InitWithCapacity(size_t size, size_t count) {
  Array self = malloc(sizeof(struct Array_t));
  self->buffer = malloc(size * count);
  self->size = 0;
  self->capacity = count;
  self->objSize = size;
  return self;
}
Array arr_InitWithSize(size_t objSize, size_t count) {
  Array self = malloc(sizeof(struct Array_t));
  self->buffer = malloc(objSize * count);
  self->size = count;
  self->capacity = count;
  self->objSize = objSize;
  return self;
}
void arr_CopyData(Array self, void *buffer) {
  memcpy(self->buffer + (self->size * self->objSize), buffer, self->objSize);
  self->size++;
}
void arr_Push(Array self, void *buffer) {
  if(self->size >= self->capacity) {
    self->capacity <<= 1;
    self->buffer = realloc(self->buffer, self->capacity * self->objSize);
  }
  arr_CopyData(self, buffer);
}
void arr_RemoveElement(Array self, size_t index) {
  ((void) sizeof ((self->size != 0) ? 1 : 0), __extension__ ({ if (self->size != 0) ; else __assert_fail ("self->size != 0", "bin/svv.c", 48, __extension__ __PRETTY_FUNCTION__); }));
  if(index >= self->size) {
    return ;
  }
  char *payloadBuffer = self->buffer;
  for(ssize_t i = index, c = (ssize_t)self->size - 1; i < c; i++) {
    memcpy(payloadBuffer + i * self->objSize, payloadBuffer + (i + 1) * self->objSize, self->objSize);
  }
  self->size--;
}
void arr_Delete(Array self) {
  free(self->buffer);
  free(self);
}
void arr_DeleteWOBuffer(Array self) {
  free(self);
}
char *arr_Last(Array self) {
  if(!self->size) {
    return ((void *)0);
  }
  return self->buffer + (self->size - 1) * self->objSize;
}
void arr_Pop(Array self) {
  if(!self->size) {
    return ;
  }
  self->size--;
}
Array arr_RemoveElements(Array payload, Array indexes) {
  Array indexesCount = arr_InitWithSize(sizeof(uint8_t), payload->size);
  memset(indexesCount->buffer, 0, sizeof(uint8_t) * payload->size);
  size_t *indexesBuffer = indexes->buffer;
  uint8_t *aparitionCount = indexesCount->buffer;
  for(size_t i = 0, c = indexes->size; i < c; i++) {
    if(indexesBuffer[i] < payload->size) {
      aparitionCount[indexesBuffer[i]] = 1;
    }
  }
  Array payloadWithMissingElements = arr_Init(payload->objSize);
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!aparitionCount[i]) {
      arr_Push(payloadWithMissingElements, payload->buffer + i * payload->objSize);
    }
  }
  arr_Delete(indexesCount);
  return payloadWithMissingElements;
}
void arr_RemoveElementsWithReplacing(Array *self, Array indexes) {
  Array deleted = arr_RemoveElements(*self, indexes);
  arr_Delete(*self);
  *self = deleted;
}
int64_t arr_Find(Array payload, void *element) {
  void *startingPointer = payload->buffer;
  size_t objSize = payload->objSize;
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!memcmp(startingPointer + i * objSize, element, objSize)) {
      return i;
    }
  }
  return -1;
}
void arr_Clear(Array self) {
  self->size = 0;
}
       
EventBuffer evm_New_Transform(const PEventMessage self);
EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer);
EventMessage evm_Parse(EventBuffer buffer, uint8_t *valid);
uint32_t evm_Out_Public_TotalSize(PEventMessage self);
static inline uint8_t evm_Out_IsAuthed(const PEventMessage self) {
  return self->isAuthed;
}
static inline char *evm_Out_PayloadSizePointer(const PEventMessage self, char *buffer) {
  return buffer;
}
static inline char *evm_Out_HeaderPointer(const PEventMessage self, char *buffer) {
  return buffer + sizeof(self->str.size);
}
static inline char *evm_Out_HeaderAuthPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return ((void *)0);
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
}
static inline char *evm_Out_PayloadPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode) + sizeof(Auth);
}
static inline char *evm_In_SizePointer(char *buffer) {
  return buffer;
}
static inline char *evm_In_HeaderPointer(char *buffer) {
  return evm_In_SizePointer(buffer) + sizeof(uint32_t);
}
static inline uint32_t evm_In_Size(char *buffer) {
  return *(uint32_t *)evm_In_SizePointer(buffer);
}
static inline uint32_t evm_In_Header(char *buffer) {
  return *(uint32_t *)evm_In_HeaderPointer(buffer);
}
static inline uint32_t evm_In_HeaderCode(char *buffer) {
  return (evm_In_Header(buffer) & 0xFFFFFF);
}
static inline uint8_t evm_In_HeaderIsAuth(char *buffer) {
  return (evm_In_Header(buffer) & (1<<24)) != 0;
}
static inline char *evm_In_AuthPointer(char *buffer) {
  if(!evm_In_HeaderIsAuth(buffer)) {
    return ((void *)0);
  }
  return evm_In_HeaderPointer(buffer) + sizeof(uint32_t);
}
static inline char *evm_In_PayloadPointer(char *buffer) {
  return evm_In_HeaderPointer(buffer) + ((size_t)evm_In_AuthPointer(buffer) != 0) * sizeof(Auth) + sizeof(uint32_t);
}
static inline char *evm_In_EndPointer(char *buffer) {
  return evm_In_PayloadPointer(buffer) + evm_In_Size(buffer);
}
static inline uint32_t evm_Out_TotalSize(const PEventMessage self) {
  return self->str.size + sizeof(self->headerCode) + sizeof(self->str.size) + sizeof(Auth) * evm_Out_IsAuthed(self);
}
uint32_t evm_Out_Public_TotalSize(PEventMessage self) {
  return evm_Out_TotalSize(self);
}
EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  memcpy(evm_Out_PayloadSizePointer(self, buffer), &self->str.size, sizeof(self->str.size));
  uint32_t mergedHeaders = (self->headerCode | ((1<<24) * self->isAuthed));
  memcpy(evm_Out_HeaderPointer(self, buffer), &mergedHeaders, sizeof(mergedHeaders));
  char *headerPointer = evm_Out_HeaderAuthPointer(self, buffer);
  if(headerPointer) {
    memcpy(headerPointer, self->uniqueCode.bff, sizeof(self->uniqueCode));
  }
  if(self->str.buffer) {
    memcpy(evm_Out_PayloadPointer(self, buffer), self->str.buffer, self->str.size);
  }
  return (EventBuffer) {
    .buffer = buffer,
    .size = totalSize
  };
}
EventBuffer evm_New_Transform(const PEventMessage self) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  char *buffer = malloc(totalSize);
  return evm_Reuse_Transform(self, buffer);
}
EventMessage evm_Parse(EventBuffer inp, uint8_t *valid) {
  *valid = 0;
  if(inp.size < 8) {
    return (EventMessage) {};
  }
  char *endBuffer = evm_In_EndPointer(inp.buffer);
  if(endBuffer != inp.size + inp.buffer) {
    return (EventMessage) {};
  }
  EventMessage response = (EventMessage) {
    .isAuthed = evm_In_HeaderIsAuth(inp.buffer),
    .headerCode = evm_In_HeaderCode(inp.buffer),
    .str = (EventBuffer) {
      .buffer = evm_In_PayloadPointer(inp.buffer),
      .size = evm_In_Size(inp.buffer)
    }
  };
  char *authCode = evm_In_AuthPointer(inp.buffer);
  if(authCode) {
    memcpy(response.uniqueCode.bff, authCode, sizeof(Auth));
  }
  *valid = 1;
  return response;
}
       
PEventServer evs_Create(uint16_t port);
void evs_Delete(PEventServer self);
void evs_OnFrame(PEventServer self, uint64_t deltaMS);
void evs_PushMessage(PEventServer self, PResponseObject msg);
void evs_EnablePingPongTimeout(PEventServer self, uint64_t timeout);
       
PWebSocketServer wss_Create(uint16_t port);
size_t wss_ConnectionsCount(PWebSocketServer self);
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS);
void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout);
void wss_Delete(PWebSocketServer self);
void wss_SendMessage(PWebSocketServer self, PDataFragment dt);
void wss_SetMaxBSizeSocket(PWebSocketServer self, size_t bytesSize);
       
PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);
void sock_OnFrame(PSocketServer self, uint64_t deltaMS);
void sock_Write_Push(PSocketServer self, DataFragment *dt);
size_t sock_ConnectionCount(PSocketServer self);
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);
void sock_PushCloseConnections(PSocketServer self, PConnection conn);
void sock_CloseConnection(PSocketServer self, size_t index);
PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer);
void sock_Method_Delete(PSocketMethod self);
static inline void evs_ProcessClosingConn(PEventServer self, PConnection conn) {
  if(self->onClose) {
    void (*method)(PConnection, void *) = self->onClose->method;
    method(conn, self->onClose->mirrorBuffer);
  }
}
static inline void evs_PushEventBuffer(PEventServer self, PEventBuffer bff, PConnection conn) {
  DataFragment nextFrag = {
    .conn = *conn,
    .data = bff->buffer,
    .size = bff->size
  };
  wss_SendMessage(self->wsServer, &nextFrag);
}
void evs_EnablePingPongTimeout(PEventServer self, uint64_t timeout) {
  wss_EnablePingPongTimeout(self->wsServer, timeout);
}
void evs_PushMessage(PEventServer self, PResponseObject msg) {
  uint32_t msgSize = evm_Out_Public_TotalSize(&msg->metaData);
  if(msgSize < (1<<12)) {
    char buffer[(1<<12)];
    EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
    evs_PushEventBuffer(self, &response, msg->conn);
    return ;
  }
  char *buffer = malloc(msgSize);
  EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
  evs_PushEventBuffer(self, &response, msg->conn);
  free(buffer);
}
void _evs_OnClose(Connection conn, void *buffer) {
  evs_ProcessClosingConn(buffer, &conn);
}
void _evs_OnReceive(PDataFragment frag, void *buffer) {
  PEventServer self = buffer;
  uint8_t valid;
  EventMessage currentMessage = evm_Parse((EventBuffer) {
    .buffer = frag->data,
    .size = frag->size
  }, &valid);
  if(!valid) {
    evs_ProcessClosingConn(self, &frag->conn);
    sock_PushCloseConnections(self->wsServer->socketServer, &frag->conn);
    return ;
  }
  if(self->onReceive) {
    void (*method)(PResponseObject, void *) = self->onReceive->method;
    ResponseObject rsp = (ResponseObject) {
      .conn = &frag->conn,
      .metaData = currentMessage
    };
    method(&rsp, self->onReceive->mirrorBuffer);
  }
}
static inline void evs_RegisterMethods(PEventServer self) {
  PSocketMethod _onReceive = sock_Method_Create(
    _evs_OnReceive,
    self
  );
  self->wsServer->onReceiveMessage = _onReceive;
  PSocketMethod _onClose = sock_Method_Create(
    _evs_OnClose,
    self
  );
  self->wsServer->onRelease = _onClose;
}
PEventServer evs_Create(uint16_t port) {
  PEventServer self = malloc(sizeof(EventServer));
  memset(self, 0, sizeof(EventServer));
  self->wsServer = wss_Create(port);
  evs_RegisterMethods(self);
  return self;
}
void evs_FreeMethods(PEventServer self) {
  sock_Method_Delete(self->wsServer->onReceiveMessage);
  sock_Method_Delete(self->wsServer->onRelease);
}
void evs_OnFrame(PEventServer self, uint64_t deltaMS) {
  wss_OnFrame(self->wsServer, deltaMS);
}
void evs_Delete(PEventServer self) {
  evs_FreeMethods(self);
  wss_Delete(self->wsServer);
  free(self);
}
       
       
PHttpServer httpS_Create(uint16_t port);
void httpS_Delete(PHttpServer self);
JsonElement httpS_Json_Get(PHttpRequest req);
PHttpResponse httpS_Json_Post(JsonElement jsn);
void httpS_OnFrame(PHttpServer self, uint64_t deltaMS);
PHttpRequestServer httpS_Request_Create(int64_t timeoutMS);
void httpS_Request_Delete(PHttpRequestServer self);
void httpS_Request_OnFrame(PHttpRequestServer self, uint64_t deltaMS);
void httpS_Request_Send(PHttpRequestServer self, RequestStruct request);
RequestStruct httpS_Request_StructInit(HttpString ip, uint16_t port);
       
       
PConnection sock_Client_Connect(uint16_t port, char *ip);
void sock_Client_SendMessage(PDataFragment frag);
void sock_Client_Free(PConnection conn);
DataFragment sock_Client_Receive(PConnection conn);
HttpString sock_Client_ReceiveWithErrors(PConnection conn);
PUserData usrs_Create();
size_t usrs_ConnID(PUserData self, PConnection conn, uint8_t *ok);
PUser usrs_Activate(PUserData self, uint64_t ID, PConnection conn);
PUser usrs_Get(PUserData self, uint64_t ID);
PUser usrs_ByIndex(PUserData self, uint64_t index);
PUser usrs_ByConnection(PUserData self, PConnection conn);
void usrs_Deactivate(PUserData self, PConnection conn);
void usrs_Delete(PUserData self);
void usrs_AddUser(PUserData self, uint64_t ID);
void usr_Deactivate(PUser self);
       
PJsonObject json_Create();
JsonElement json_Map_Create();
void json_Delete(PJsonObject self);
void json_Add(PJsonObject self, PHttpString key, JsonElement element);
HttpString json_ToString(PJsonObject self);
void json_RemoveSelfContainedData(PJsonObject self);
JsonElement json_Parse(HttpString buffer, char **nextBuffer);
HttpString json_Element_ToString(JsonElement self);
void json_Parser_Print(JsonElement self);
void json_DeleteElement(JsonElement element);
JsonElement json_Map_Get(JsonElement jsonMap, HttpString str);
JsonElement json_Array_At(JsonElement arr, size_t index);
size_t json_Array_Size(JsonElement arr);
int64_t json_Integer_Get(JsonElement arr);
float json_Number_Get(JsonElement arr);
JsonElement json_Map_GetString(JsonElement jsonMap, const char *key);
void json_Map_Add(JsonElement map, char *key, JsonElement element);
void json_Map_String_String_Add(JsonElement map, char *key, char *value);
void json_Map_String_Integer_Add(JsonElement map, char *key, int64_t value);
JsonElement json_Integer_Create(int64_t val);
JsonElement json_Number_Create(float val);
JsonElement json_String_Create(char *string);
JsonElement json_String_CreateFromHttpString(HttpString string);
       
PTimeServer tf_Create();
void tf_OnFrame(PTimeServer self, uint64_t deltaMS);
void tf_Delete(PTimeServer self);
void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS);
void tf_ExecuteLoop(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS);
uint64_t tf_CurrentTimeMS();
PManager man_Create(uint16_t port);
void man_Delete(PManager self);
void man_OnFrame(PManager self, uint64_t deltaMS);
void man_SetSecret(PManager self, HttpString hmacKey);
PUser man_User_Get(PManager self, uint64_t ID);
void man_SendMessage(const PManager self, const PDataFragment dt);
void man_UserRegister(PManager self, uint64_t userID);
       
HttpString jwt_Encode(JsonElement payload, HttpString secret, uint64_t expirationInMS);
size_t jwt_Base64_Size_Public(size_t sz);
uint8_t jwt_IsSigned(HttpString str, HttpString secret);
uint8_t jwt_IsValid(HttpString str, HttpString secret);
PJWT jwt_Parse(HttpString jwtStr, HttpString secret);
void jwt_Delete(PJWT self);
       
       
PNetworkBuffer tpd_Create(size_t maxSizeB);
void tpd_Delete(PNetworkBuffer self);
uint8_t tpd_Push(PNetworkBuffer self, void *buffer, size_t size);
size_t tpd_Size(PNetworkBuffer self);
void tpd_Retract(PNetworkBuffer self, size_t bytes);
void *tpd_StartingBuffer(PNetworkBuffer self);
PHttpRequest http_Request_Parse(char *buffer, size_t sz);
HttpString http_Request_ToString(PHttpRequest self);
HttpString http_Request_GetValue(PHttpRequest self, char *buffer);
void http_Request_Delete(PHttpRequest self);
PHttpRequest http_Request_Create();
void http_Request_SetBody(PHttpRequest self, HttpString str);
HttpString http_Request_GetBody(PHttpRequest self);
HttpString http_Request_GetPath(PHttpRequest self);
void http_Request_AddHeader(PHttpRequest self, char *key, char *value);
PHttpRequest http_Request_Basic();
PHttpRequest http_Request_Chomp(HttpString bff, char **endBuffer);
PHttpRequest http_Request_NB_Get(PNetworkBuffer netBuffer);
HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen);
PHttpResponse http_Response_Create();
PHttpResponse http_Response_DeepCopy(PHttpResponse self);
void http_Response_SetBody(PHttpResponse self, PHttpString buffer);
void http_Response_Delete(PHttpResponse self);
HttpString http_Response_ToString(PHttpResponse self);
PHttpResponse http_Response_Empty();
void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize);
void http_Response_SetJSON(PHttpResponse self);
PHttpResponse http_Response_Parse(HttpString buffer);
HttpString http_Response_GetValue(PHttpResponse self, char *buffer);
PHttpResponse http_Response_Chomp(HttpString bff, char **endBuffer);
PHttpResponse http_Response_NB_Get(PNetworkBuffer netBuffer);
void man_SetupMethods(PManager self);
uint8_t man_RemoveConnection(const PManager self, const Connection conn);
static inline void man_RunOnLogin(const PManager self, const PUser user);
static inline void man_PushClosingConnection(const PManager self, Connection conn);
typedef struct GameConnTimeout_t {
  PManager man;
  Connection conn;
} GameConnTimeout;
typedef GameConnTimeout *PGameConnTimeout;
PManager man_Create(uint16_t port) {
  PManager self = malloc(sizeof(Manager));
  memset(self, 0, sizeof(Manager));
  self->server = wss_Create(port);
  self->pendingConnections = arr_Init(sizeof(Connection));
  self->timeoutConnectionCheckers = arr_Init(sizeof(PGameConnTimeout));
  self->timeServer = tf_Create();
  self->userData = usrs_Create();
  wss_EnablePingPongTimeout(self->server, 10000);
  man_SetupMethods(self);
  return self;
}
static inline size_t man_GetConn(const PManager self, const PDataFragment dt, uint8_t *found) {
  return usrs_ConnID(self->userData, &dt->conn, found);
}
void man_DeleteTimeoutConn(const PGameConnTimeout gameConnTimeout) {
  const PManager self = gameConnTimeout->man;
  PGameConnTimeout *buffer = self->timeoutConnectionCheckers->buffer;
  for(size_t i = 0, c = self->timeoutConnectionCheckers->size; i < c; i++) {
    if(buffer[i] == gameConnTimeout) {
      free(buffer[i]);
      arr_RemoveElement(self->timeoutConnectionCheckers, i);
      return ;
    }
  }
}
static inline void man_RunOnLogin(const PManager self, const PUser user) {
  if(!self->onLogin || !user) {
    return ;
  }
  void (*method)(PUser, void *) = self->onLogin->method;
  method(user, self->onLogin->mirrorBuffer);
}
static inline void man_DeleteRemainingConns(const PManager self) {
  PGameConnTimeout *buffer = self->timeoutConnectionCheckers->buffer;
  for(size_t i = 0, c = self->timeoutConnectionCheckers->size; i < c; i++) {
    free(buffer[i]);
  }
  arr_Delete(self->timeoutConnectionCheckers);
}
static inline void man_PushClosingConnection(const PManager self, Connection conn) {
  sock_PushCloseConnections(self->server->socketServer, &conn);
}
void _man_ExecuteAfterMS(void *buffer) {
  PGameConnTimeout gameConnTimeout = buffer;
  if(man_RemoveConnection(gameConnTimeout->man, gameConnTimeout->conn)) {
    man_PushClosingConnection(gameConnTimeout->man, gameConnTimeout->conn);
  }
  man_DeleteTimeoutConn(gameConnTimeout);
}
void man_SetSecret(PManager self, HttpString hmacKey) {
  self->hmacKey.buffer = malloc(hmacKey.sz);
  self->hmacKey.sz = hmacKey.sz;
  memcpy(self->hmacKey.buffer, hmacKey.buffer, hmacKey.sz);
}
void man_PushConnTimeout(const PManager self, const PConnection conn, uint64_t afterMS) {
  PGameConnTimeout gameConnTimeout = malloc(sizeof(GameConnTimeout));
  gameConnTimeout->conn = *conn;
  gameConnTimeout->man = self;
  TimeMethod tm = {
    .buffer = gameConnTimeout,
    .method = _man_ExecuteAfterMS
  };
  arr_Push(self->timeoutConnectionCheckers, &gameConnTimeout);
  tf_ExecuteAfter(self->timeServer, tm, afterMS);
}
void man_OnConnect(PManager self, PConnection conn) {
  arr_Push(self->pendingConnections, conn);
  man_PushConnTimeout(self, conn, 2500);
}
static inline uint8_t man_ProcessJWT(const PManager self, const HttpString jwt, uint64_t *userID) {
  if(!self->hmacKey.buffer || !self->hmacKey.sz) {
    return 0;
  }
  PJWT jwtToken = jwt_Parse(jwt, self->hmacKey);
  if(!jwtToken) {
    return 0;
  }
  JsonElement userIDString = json_Map_Get(jwtToken->payload, (HttpString) {
    .buffer = "user_id",
    .sz = sizeof("user_id") - 1
  });
  if(userIDString.type != JSON_INTEGER) {
    return 0;
  }
  *userID = json_Integer_Get(userIDString);
  jwt_Delete(jwtToken);
  return 1;
}
uint8_t man_RemoveConnection(const PManager self, const Connection conn) {
  Array pendingConns = self->pendingConnections;
  Connection *conns = pendingConns->buffer;
  for(size_t i = 0, c = pendingConns->size; i < c; i++) {
    if(conn.fd == conns[i].fd) {
      arr_RemoveElement(pendingConns, i);
      return 1;
    }
  }
  return 0;
}
void man_SendMessage(const PManager self, const PDataFragment dt) {
  wss_SendMessage(self->server, dt);
}
void man_Response_SendMessage(const PManager self, PConnection conn, JsonElement element) {
  if(element.type != JSON_JSON) {
    return ;
  }
  HttpString message = json_Element_ToString(element);
  DataFragment frag = {
    .conn = *conn,
    .data = message.buffer,
    .persistent = 1,
    .size = message.sz
  };
  man_SendMessage(self, &frag);
  free(message.buffer);
}
void man_SendResponseMessage(const PManager self, const PDataFragment dt, int64_t code) {
  JsonElement response = json_Map_Create();
  json_Map_String_Integer_Add(response, "statue", code);
  man_Response_SendMessage(self, &dt->conn, response);
  json_DeleteElement(response);
}
static inline PUser man_ProcessPendingMessage_t(const PManager self, const PDataFragment dt) {
  char *endBuffer;
  JsonElement currentElement = json_Parse((HttpString) {
    .buffer = dt->data,
    .sz = dt->size
  }, &endBuffer);
  if(currentElement.type != JSON_JSON || endBuffer != dt->data + dt->size) {
    json_DeleteElement(currentElement);
    return ((void *)0);
  }
  JsonElement jwtToken = json_Map_Get(currentElement, (HttpString) {
    .buffer = "token",
    .sz = sizeof("token") - 1
  });
  if(jwtToken.type != JSON_STRING) {
    json_DeleteElement(currentElement);
    return ((void *)0);
  }
  uint64_t userID;
  if(!man_ProcessJWT(self, *(HttpString *)jwtToken.value, &userID)) {
    json_DeleteElement(currentElement);
    return ((void *)0);
  }
  json_DeleteElement(currentElement);
  PUser activatedUser = usrs_Activate(self->userData, userID, &dt->conn);
  (void)!man_RemoveConnection(self, dt->conn);
  man_RunOnLogin(self, activatedUser);
  return activatedUser;
}
static inline uint8_t man_IsUserActive(const PManager self, const size_t plyIndex) {
  PUser user = usrs_Get(self->userData, plyIndex);
  ((void) sizeof ((user != ((void *)0)) ? 1 : 0), __extension__ ({ if (user != ((void *)0)) ; else __assert_fail ("user != NULL", "bin/svv.c", 542, __extension__ __PRETTY_FUNCTION__); }));
  return user->active;
}
PUser man_User_Get(PManager self, uint64_t ID) {
  return usrs_Get(self->userData, ID);
}
static inline PUser man_ProcessPendingMessage(const PManager self, const PDataFragment dt) {
  PUser currentUser = man_ProcessPendingMessage_t(self, dt);
  if(!currentUser) {
    man_SendResponseMessage(self, dt, 401);
  } else {
    man_SendResponseMessage(self, dt, 200);
  }
  return currentUser;
}
static inline PUser man_ProcessPendingConnection(const PManager self, const PDataFragment dt) {
  uint8_t found;
  size_t plyIndex = man_GetConn(self, dt, &found);
  if(!found) {
    return man_ProcessPendingMessage(self, dt);
  }
  PUser currentUser = usrs_ByIndex(self->userData, plyIndex);
  if(!currentUser->active) {
    return ((void *)0);
  }
  return currentUser;
}
static inline void man_RunOnReceiveCommand(const PManager self, const PDataFragment dt, const PUser user) {
  if(!self->onReceive) {
    return ;
  }
  void (*method)(PDataFragment, PUser, void *) = self->onReceive->method;
  method(dt, user, self->onReceive->mirrorBuffer);
}
static inline void man_RunOnRelease(const PManager self, const PUser user) {
  if(!self->onDisconnect) {
    return ;
  }
  void (*method)(PUser, void *) = self->onDisconnect->method;
  method(user, self->onDisconnect->mirrorBuffer);
}
static inline void man_OnReceive(const PManager self, const PDataFragment dt) {
  const PUser currentUser = man_ProcessPendingConnection(self, dt);
  if(!currentUser) {
    sock_PushCloseConnections(self->server->socketServer, &dt->conn);
    return ;
  }
  man_RunOnReceiveCommand(self, dt, currentUser);
}
void _man_OnReceive(PDataFragment dt, void *mirror) {
  man_OnReceive(mirror, dt);
}
void _man_OnConnect(PConnection conn, void *mirror) {
  man_OnConnect(mirror, conn);
}
void man_UserRegister(PManager self, uint64_t userID) {
  usrs_AddUser(self->userData, userID);
}
void _man_OnRelease(Connection conn, void *mirror) {
  PManager self = mirror;
  PUser currentUser = usrs_ByConnection(self->userData, &conn);
  usr_Deactivate(currentUser);
  (void)!man_RemoveConnection(self, conn);
  man_RunOnRelease(self, currentUser);
}
void man_SetupMethods(PManager self) {
  PSocketMethod onConnectMethod = sock_Method_Create(
    _man_OnConnect,
    self
  );
  self->server->onConnect = onConnectMethod;
  PSocketMethod onReceiveMethod = sock_Method_Create(
    _man_OnReceive,
    self
  );
  self->server->onReceiveMessage = onReceiveMethod;
  PSocketMethod onRelease = sock_Method_Create(
    _man_OnRelease,
    self
  );
  self->server->onRelease = onRelease;
}
void man_Delete(PManager self) {
  sock_Method_Delete(self->server->onReceiveMessage);
  sock_Method_Delete(self->server->onRelease);
  sock_Method_Delete(self->server->onConnect);
  wss_Delete(self->server);
  arr_Delete(self->pendingConnections);
  man_DeleteRemainingConns(self);
  tf_Delete(self->timeServer);
  usrs_Delete(self->userData);
  if(self->hmacKey.buffer) {
    free(self->hmacKey.buffer);
  }
  free(self);
}
void man_OnFrame(PManager self, uint64_t deltaMS) {
  wss_OnFrame(self->server, deltaMS);
  tf_OnFrame(self->timeServer, deltaMS);
}
       
PHsh hsh_Create();
void hsh_Add(PHsh self, void* key, uint32_t keySize, void* value, uint32_t valueSize);
void hsh_Delete(PHsh self);
void hsh_RemoveNode(PHsh self, void* key, uint32_t keySize);
void* hsh_GetBuffer(PHsh self, void* key, uint32_t keySize);
void hsh_Integer32_Insert(PHsh self, uint32_t key, uint32_t value);
void* hsh_Integer32_Get(PHsh self, uint32_t key);
void hsh_Integer32_RemoveElement(PHsh self, uint32_t key);
void hsh_Buffer_AddToIndex64(PHsh self, uint64_t id, void* buffer, uint32_t bufferSize);
void* hsh_Buffer_GetFromIndex64(PHsh self, uint64_t id);
void hsh_Buffer_RemoveAtIndex64(PHsh self, uint64_t id);
void hsh_Buffer_AddToIndex(PHsh self, uint32_t id, void* buffer, uint32_t bufferSize);
void* hsh_Buffer_GetFromIndex(PHsh self, uint32_t id);
void hsh_Buffer_RemoveAtIndex(PHsh self, uint32_t id);
Array hsh_GetValues(PHsh self, size_t valueSize);
Array hsh_GetKeys(PHsh self);
void hsh_FreeKeys(Array keys);
PTrieNode trn_Create();
uint8_t trn_AddValues(PTrieNode self, void* key, uint32_t keySize, void* value, uint32_t valueSize, uint32_t position);
PHsh hsh_Create() {
  PHsh self = malloc(sizeof(Hsh));
  memset(self, 0, sizeof(Hsh));
  self->parentNode = trn_Create();
  return self;
}
void hsh_Add(PHsh self, void* key, uint32_t keySize, void* value, uint32_t valueSize) {
  if(!trn_AddValues(self->parentNode, key, keySize, value, valueSize, 0)) {
    self->count++;
  }
}
PTrieNode trn_Create() {
  PTrieNode self = malloc(sizeof(TrieNode));
  memset(self, 0, sizeof(TrieNode));
  self->nextNodes = malloc(sizeof(PTrieNode) * 16);
  memset(self->nextNodes, 0, sizeof(PTrieNode) * 16);
  return self;
}
static inline void hsh_FreeNode(PTrieNode self) {
  free(self->nextNodes);
  free(self);
}
void trn_DeleteNodes(PTrieNode self) {
  for(uint8_t i = 0; i < 16; i++) {
    if(self->nextNodes[i]) {
      trn_DeleteNodes(self->nextNodes[i]);
      self->nextNodes[i] = ((void *)0);
    }
  }
  if(self->buffer) {
    free(self->buffer);
  }
  hsh_FreeNode(self);
}
uint8_t trn_RemoveNode_t(PTrieNode self, void* key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    if(self->buffer) {
      free(self->buffer);
      self->buffer = ((void *)0);
      return 1;
    }
    return 0;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  uint8_t deleted = 0;
  if(node) {
    deleted = trn_RemoveNode_t(node, key, keySize, position + 1);
    node->count--;
    if(!node->count) {
      self->nextNodes[currentValue] = ((void *)0);
      hsh_FreeNode(node);
    }
  }
  return deleted;
}
void hsh_Buffer_AddToIndex(PHsh self, uint32_t id, void* buffer, uint32_t bufferSize) {
  hsh_Add(self, &id, sizeof(uint32_t), buffer, bufferSize);
}
void hsh_Buffer_AddToIndex64(PHsh self, uint64_t id, void* buffer, uint32_t bufferSize) {
  hsh_Add(self, &id, sizeof(uint64_t), buffer, bufferSize);
}
void* hsh_Buffer_GetFromIndex(PHsh self, uint32_t id) {
  return hsh_GetBuffer(self, &id, sizeof(uint32_t));
}
void* hsh_Buffer_GetFromIndex64(PHsh self, uint64_t id) {
  return hsh_GetBuffer(self, &id, sizeof(uint64_t));
}
void hsh_Buffer_RemoveAtIndex(PHsh self, uint32_t id) {
  hsh_RemoveNode(self, &id, sizeof(uint32_t));
}
void hsh_Buffer_RemoveAtIndex64(PHsh self, uint64_t id) {
  hsh_RemoveNode(self, &id, sizeof(uint64_t));
}
void* trn_GetBuffer_t(PTrieNode self, void* key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    return self->buffer;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(node) {
    return trn_GetBuffer_t(node, key, keySize, position + 1);
  }
  return ((void *)0);
}
void hsh_GetValues_t(PTrieNode self, Array values) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    arr_Push(values, self->buffer);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(size_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      hsh_GetValues_t(nextNodes[i], values);
    }
  }
}
Array hsh_GetValues(PHsh self, size_t valueSize) {
  Array response = arr_Init(valueSize);
  hsh_GetValues_t(self->parentNode, response);
  return response;
}
void hsh_Key_Push(Array currentKey, uint8_t value, size_t position) {
  if(!(position & 1)) {
    value <<= 4;
    arr_Push(currentKey, &value);
    return ;
  }
  uint8_t *last = (uint8_t *)arr_Last(currentKey);
  if(!last) {
    return ;
  }
  (*last) += value;
}
static inline void hsh_Key_Pop(Array currentKey, size_t position) {
  if(!(position & 1)) {
    arr_Pop(currentKey);
  }
  else {
    uint8_t *last = (uint8_t *)arr_Last(currentKey);
    if(!last) {
      return ;
    }
    (*last) &= 0xF0;
  }
}
void hsh_GetKeys_t(PTrieNode self, Array keys, Array currentKey, size_t position) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    Key key;
    key.keySize = currentKey->size;
    key.key = malloc(key.keySize);
    memcpy(key.key, currentKey->buffer, key.keySize);
    arr_Push(keys, &key);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(uint8_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      hsh_Key_Push(currentKey, i, position);
      hsh_GetKeys_t(nextNodes[i], keys, currentKey, position + 1);
      hsh_Key_Pop(currentKey, position);
    }
  }
}
Array hsh_GetKeys(PHsh self) {
  Array response = arr_Init(sizeof(Key));
  Array currentKey = arr_Init(sizeof(uint8_t));
  hsh_GetKeys_t(self->parentNode, response, currentKey, 0);
  arr_Delete(currentKey);
  return response;
}
void hsh_FreeKeys(Array keys) {
  Key *buffer = (Key *)keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    free(buffer[i].key);
  }
  arr_Delete(keys);
}
void* hsh_GetBuffer(PHsh self, void* key, uint32_t keySize) {
  return trn_GetBuffer_t(self->parentNode, key, keySize, 0);
}
void hsh_RemoveNode(PHsh self, void* key, uint32_t keySize) {
  if(trn_RemoveNode_t(self->parentNode, key, keySize, 0)) {
    self->count--;
  }
}
uint8_t trn_AddValues(PTrieNode self, void* key, uint32_t keySize, void* value, uint32_t valueSize, uint32_t position) {
  if(position >= (keySize << 1)) {
    void* lastBuffer = self->buffer;
    self->buffer = malloc(valueSize);
    memcpy(self->buffer, value, valueSize);
    if(lastBuffer) {
      free(lastBuffer);
      return 0;
    }
    return 1;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(!node) {
    node = trn_Create();
    self->nextNodes[currentValue] = node;
  }
  node->count++;
  return trn_AddValues(node, key, keySize, value, valueSize, position + 1);
}
void hsh_Integer32_Insert(PHsh self, uint32_t key, uint32_t value) {
  hsh_Add(self, &key, sizeof(uint32_t), &value, sizeof(uint32_t));
}
void* hsh_Integer32_Get(PHsh self, uint32_t key) {
  return hsh_GetBuffer(self, &key, sizeof(uint32_t));
}
void hsh_Integer32_RemoveElement(PHsh self, uint32_t key) {
  hsh_RemoveNode(self, &key, sizeof(uint32_t));
}
void hsh_Delete(PHsh self) {
  trn_DeleteNodes(self->parentNode);
  free(self);
}

enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) tolower (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_tolower_loc ())[__c] : __c;
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) toupper (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc ())[__c] : __c;
}
extern int isalnum_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isblank_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int __tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int __toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

       
HttpString string_DeepCopy(HttpString str);
void string_Print(HttpString str);
static inline PHttpMetaData http_InitMetadata();
static inline PURL http_URL_Init();
static inline void http_UpdateString(PHttpString string, char *buffer, char *_endBuffer);
uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer);
static inline char *http_ChompString(PHttpString buff, char *like, uint8_t repeat);
uint8_t http_Header_Parse(Hash self, char *endBuffer, PHttpString buffer);
char *http_GetToken(PHttpString buffer, PHttpString token);
static inline char *http_ChompLineSeparator(PHttpString buffer);
static inline Hash http_Hash_Create();
HttpString http_Body_Process(Hash self, char *_endBuffer, PHttpString buffer);
static inline void http_SetBuffer(HttpString buffer, PHttpString nextPart, char *next);
PHttpResponse _http_Response_Empty(Hash headers);
PHttpResponse http_Response_Chomp_t(HttpString *bff);
PHttpRequest http_Request_Chomp_t(HttpString *bff);
static HttpString http_Body_ProcessWithError(Hash headers, char *_endBuffer, HttpString *bff, uint8_t *valid);
ssize_t http_Get_Number(Hash self, char *key, uint8_t *isValid);
PHttpRequest http_Request_Parse(char *buffer, size_t sz) {
  HttpString req = {
    .buffer = buffer,
    .sz = sz
  };
  PHttpRequest self = http_Request_Chomp_t(&req);
  if(!self) {
    return ((void *)0);
  }
  if(req.sz) {
    http_Request_Delete(self);
    return ((void *)0);
  }
  return self;
}
PHttpRequest http_Request_Chomp_t(HttpString *bff) {
  PHttpRequest self = malloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->headers = http_Hash_Create();
  self->_endBuffer = bff->buffer + bff->sz;
  self->metadata = http_InitMetadata();
  self->url = http_URL_Init();
  if(!http_Route_Parse(self, bff)) {
    http_Request_Delete(self);
    return ((void *)0);
  }
  if(!http_Header_Parse(self->headers, self->_endBuffer, bff)) {
    http_Request_Delete(self);
    return ((void *)0);
  }
  uint8_t valid;
  self->body = http_Body_ProcessWithError(self->headers, self->_endBuffer, bff, &valid);
  if(!valid) {
    http_Request_Delete(self);
    return ((void *)0);
  }
  return self;
}
static HttpString http_Body_ProcessWithError(Hash headers, char *_endBuffer, HttpString *bff, uint8_t *valid) {
  *valid = 1;
  HttpString response = http_Body_Process(headers, _endBuffer, bff);
  uint8_t contentLengthChecker;
  ssize_t contentLength = http_Get_Number(headers, "Content-Length", &contentLengthChecker);
  if(!contentLengthChecker && response.buffer) {
    *valid = 0;
    return response;
  }
  if(contentLengthChecker && response.sz != contentLength) {
    *valid = 0;
    return response;
  }
  return response;
}
PHttpRequest http_Request_NB_Get(PNetworkBuffer netBuffer) {
  char *stBuffer = tpd_StartingBuffer(netBuffer);
  char *endingBuffer;
  PHttpRequest req = http_Request_Chomp((HttpString) {
    .buffer = stBuffer,
    .sz = tpd_Size(netBuffer)
  }, &endingBuffer);
  if(!req) {
    return ((void *)0);
  }
  const size_t nextSize = (size_t)(endingBuffer - stBuffer);
  tpd_Retract(netBuffer, nextSize);
  return req;
}
PHttpRequest http_Request_Chomp(HttpString bff, char **endBuffer) {
  PHttpRequest self = http_Request_Chomp_t(&bff);
  if(!self) {
    return ((void *)0);
  }
  *endBuffer = bff.buffer;
  return self;
}
PHttpResponse http_Response_NB_Get(PNetworkBuffer netBuffer) {
  char *stBuffer = tpd_StartingBuffer(netBuffer);
  char *endingBuffer;
  PHttpResponse res = http_Response_Chomp((HttpString) {
    .buffer = stBuffer,
    .sz = tpd_Size(netBuffer)
  }, &endingBuffer);
  if(!res) {
    return ((void *)0);
  }
  const size_t nextSize = (size_t)(endingBuffer - stBuffer);
  tpd_Retract(netBuffer, nextSize);
  return res;
}
static inline PURL http_URL_Init() {
  PURL self = malloc(sizeof(URL));
  memset(self, 0, sizeof(URL));
  self->path.buffer = malloc(sizeof(char));
  self->path.buffer[0] = '/';
  self->path.sz = 1;
  return self;
}
static inline void http_Meta_InitCodes(PHttpMetaData self) {
  char *codes[] = {"GET", "POST", "PUT", "PATCH", "DELETE"};
  self->actionsSz = 0;
  for(size_t i = 0; i < sizeof(codes) / sizeof(char *); i++) {
    self->codes[i] = (HttpString) {
      .buffer = codes[i],
      .sz = strlen(codes[i])
    };
    self->actionsSz++;
  }
}
static inline void http_Hash_Add(Hash self, char *key, size_t keySize, char *value, size_t valueSize) {
  hsh_Add(self.hash, key, keySize, value, valueSize);
  hsh_Add(self.valuesSize, key, keySize, &valueSize, sizeof(size_t));
}
char *http_Header_ParseLine(Hash self, char *endBuffer, PHttpString buffer) {
  char *key = http_ChompString(buffer, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-.^_`|~", 1);
  if(!key) {
    return ((void *)0);
  }
  size_t keySize = (size_t)(key - buffer->buffer);
  char *keyOffset = buffer->buffer;
  http_UpdateString(buffer, key, endBuffer);
  char *separator = http_ChompString(buffer, ":", 0);
  if(!separator) {
    return ((void *)0);
  }
  http_UpdateString(buffer, separator, endBuffer);
  char *space = http_ChompString(buffer, " ", 0);
  if(space) {
    http_UpdateString(buffer, space, endBuffer);
  }
  char *value = http_ChompString(buffer, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./;:<=>?@[\\]^_`{|}~ ", 1);
  if(!value) {
    return ((void *)0);
  }
  size_t valueSize = (size_t)(value - buffer->buffer);
  char *valueOffset = buffer->buffer;
  http_UpdateString(buffer, value, endBuffer);
  http_Hash_Add(self, keyOffset, keySize, valueOffset, valueSize);
  char *endOfLine = http_ChompLineSeparator(buffer);
  if(!endOfLine) {
    return ((void *)0);
  }
  http_UpdateString(buffer, endOfLine, endBuffer);
  return endOfLine;
}
static inline Hash http_Hash_Create() {
  Hash hash;
  hash.hash = hsh_Create();
  hash.valuesSize = hsh_Create();
  return hash;
}
Hash http_Hash_DeepCopy(Hash hash) {
  Hash newHash = http_Hash_Create();
  Array keys = hsh_GetKeys(hash.hash);
  Key *bff = keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    HttpString value = http_Hash_GetValue(hash, bff[i].key, bff[i].keySize);
    http_Hash_Add(newHash, bff[i].key, bff[i].keySize, value.buffer, value.sz);
  }
  hsh_FreeKeys(keys);
  return newHash;
}
static inline char *http_ChompLineSeparator(PHttpString buffer) {
  HttpString lineSeparator = {
    .buffer = "\r\n",
    .sz = sizeof("\r\n") - 1
  };
  return http_GetToken(buffer, &lineSeparator);
}
HttpString http_Request_GetValue(PHttpRequest self, char *buffer) {
  return http_Hash_GetValue(self->headers, buffer, strlen(buffer));
}
HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen) {
  char *response = hsh_GetBuffer(self.hash, buffer, bufferLen);
  size_t *size = hsh_GetBuffer(self.valuesSize, buffer, bufferLen);
  return (HttpString){
    .buffer = response,
    .sz = size ? *size : 0
  };
}
uint8_t http_Header_Parse(Hash self, char *endBuffer, PHttpString buffer) {
  char *buff;
  HttpString cpyStr = *buffer;
  while((buff = http_Header_ParseLine(self, endBuffer, &cpyStr)) && buff);
  char *endOfLine = http_ChompLineSeparator(&cpyStr);
  if(!endOfLine) {
    return 0;
  }
  http_UpdateString(buffer, endOfLine, endBuffer);
  return 1;
}
static inline PHttpMetaData http_InitMetadata() {
  PHttpMetaData metaData = malloc(sizeof(HttpMetaData));
  http_Meta_InitCodes(metaData);
  return metaData;
}
char *http_GetToken(PHttpString buffer, PHttpString token) {
  if(buffer->sz < token->sz) {
    return ((void *)0);
  }
  for(size_t i = 0, c = token->sz; i < c; i++) {
    if(token->buffer[i] != buffer->buffer[i]) {
      return ((void *)0);
    }
  }
  return buffer->buffer + token->sz;
}
ssize_t http_Parse_Number(char *buffer, size_t sz, char **endBufer) {
  size_t index = 0;
  ssize_t number = 0;
  while(index < sz && index < 15 && buffer[index] >= '0' && buffer[index] <= '9') {
    number *= 10LL;
    number += (ssize_t)(buffer[index] - '0');
    index++;
  }
  *endBufer = buffer + index;
  return number;
}
ssize_t http_Get_Number(Hash self, char *key, uint8_t *isValid) {
  *isValid = 0;
  HttpString value = http_Hash_GetValue(self, key, strlen(key));
  if(!value.buffer) {
    return 0;
  }
  char *endPtr;
  ssize_t number = http_Parse_Number(value.buffer, value.sz, &endPtr);
  if(endPtr != value.buffer + value.sz) {
    return 0;
  }
  *isValid = 1;
  return number;
}
HttpString http_Body_Chomp_t(PHttpString buffer, ssize_t contentLength) {
  if(contentLength > buffer->sz) {
    return (HttpString) {
      .buffer = ((void *)0)
    };
  }
  HttpString response;
  response.buffer = malloc(contentLength);
  response.sz = (size_t)contentLength;
  memcpy(response.buffer, buffer->buffer, response.sz);
  return response;
}
char *http_Body_Chomp(Hash self, PHttpString buffer, HttpString *response) {
  uint8_t valid;
  ssize_t contentLength = http_Get_Number(self, "Content-Length", &valid);
  if(!valid || contentLength < 0) {
    return ((void *)0);
  }
  HttpString body = http_Body_Chomp_t(buffer, contentLength);
  if(!body.buffer) {
    return ((void *)0);
  }
  *response = body;
  return buffer->buffer + body.sz;
}
HttpString http_Body_Process(Hash self, char *_endBuffer, PHttpString buffer) {
  HttpString body;
  char *bodyBuffer = http_Body_Chomp(self, buffer, &body);
  if(!bodyBuffer) {
    return (HttpString) {
      .buffer = ((void *)0)
    };
  }
  http_UpdateString(buffer, bodyBuffer, _endBuffer);
  return body;
}
char *http_Route_ParseCodes(PHttpRequest parent, PHttpString buffer) {
  PHttpMetaData meta = parent->metadata;
  for(size_t i = 0, c = meta->actionsSz; i < c; i++) {
    char *currentToken = http_GetToken(buffer, &meta->codes[i]);
    if(!currentToken) {
      continue;
    }
    parent->url->method = i;
    return currentToken;
  }
  return ((void *)0);
}
static inline void http_UpdateString(PHttpString string, char *buffer, char *_endBuffer) {
  string->buffer = buffer;
  string->sz = (size_t)(_endBuffer - buffer);
}
static inline char *http_ChompString(PHttpString buff, char *like, uint8_t repeat) {
  char presence[257] = {0};
  for(size_t i = 0, c = strlen(like); i < c; i++) {
    presence[(uint8_t)like[i]] = 1;
  }
  size_t index = 0;
  while(repeat && index < buff->sz && presence[(uint8_t)buff->buffer[index]]) {
    index++;
  }
  if(!repeat && index < buff->sz && presence[(uint8_t)buff->buffer[index]]) {
    index++;
  }
  if(!index) {
    return ((void *)0);
  }
  return buff->buffer + index;
}
PHttpResponse http_Response_DeepCopy(PHttpResponse self) {
  Hash newHeaders = http_Hash_DeepCopy(self->headers);
  PHttpResponse newResponse = _http_Response_Empty(newHeaders);
  newResponse->httpCode = self->httpCode;
  newResponse->response = self->response;
  newResponse->body = string_DeepCopy(self->body);
  return newResponse;
}
char *http_Path_Parse(PHttpRequest parent, PHttpString buffer) {
  HttpString cpyBuffer = *buffer;
  char *strings[] = {
    "/",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_."
  };
  uint8_t i = 0;
  char *bff;
  while((bff = http_ChompString(&cpyBuffer, strings[i], i)) && bff) {
    http_UpdateString(&cpyBuffer, bff, parent->_endBuffer);
    i = !i;
  }
  return cpyBuffer.buffer;
}
char *http_Route_ParseType(PHttpRequest parent, PHttpString buffer) {
  HttpString cpyString = *buffer;
  char *bff = http_ChompString(&cpyString, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.", 1);
  if(!bff) {
    return ((void *)0);
  }
  http_UpdateString(&cpyString, bff, parent->_endBuffer);
  bff = http_ChompString(&cpyString, "/", 0);
  if(!bff) {
    return ((void *)0);
  }
  http_UpdateString(&cpyString, bff, parent->_endBuffer);
  bff = http_ChompString(&cpyString, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.", 1);
  if(!bff) {
    return ((void *)0);
  }
  http_UpdateString(&cpyString, bff, parent->_endBuffer);
  return bff;
}
void http_URL_Set(PURL url, HttpString buffer) {
  if(url->path.buffer) {
    free(url->path.buffer);
  }
  url->path.buffer = malloc(buffer.sz);
  memcpy(url->path.buffer, buffer.buffer, buffer.sz);
  url->path.sz = buffer.sz;
}
char *http_Route_Parse_t(PHttpRequest parent, PHttpString buffer) {
  char *codesBuffer = http_Route_ParseCodes(parent, buffer);
  if(!codesBuffer) {
    return ((void *)0);
  }
  http_UpdateString(buffer, codesBuffer, parent->_endBuffer);
  char *chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return ((void *)0);
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);
  char *path = http_Path_Parse(parent, buffer);
  if(!path) {
    return ((void *)0);
  }
  size_t bffSize = (size_t)(path - buffer->buffer);
  http_URL_Set(parent->url, (HttpString) {
    .buffer = buffer->buffer,
    .sz = bffSize
  });
  http_UpdateString(buffer, path, parent->_endBuffer);
  chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return ((void *)0);
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);
  char *httpType = http_Route_ParseType(parent, buffer);
  if(!httpType) {
    return ((void *)0);
  }
  size_t mthSize = (size_t)(httpType - buffer->buffer);
  if(mthSize >= sizeof(parent->url->httpType)) {
    return ((void *)0);
  }
  memcpy(parent->url->httpType, buffer->buffer, mthSize);
  http_UpdateString(buffer, httpType, parent->_endBuffer);
  chompedSpace = http_ChompLineSeparator(buffer);
  if(!chompedSpace) {
    return ((void *)0);
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);
  return buffer->buffer;
}
uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer) {
  HttpString nextBuffer = *buffer;
  char *urlParse = http_Route_Parse_t(parent, &nextBuffer);
  if(!urlParse) {
    return 0;
  }
  http_UpdateString(buffer, urlParse, parent->_endBuffer);
  return 1;
}
void http_URL_Free(PURL self) {
  if(!self) {
    return ;
  }
  if(self->path.buffer) {
    free(self->path.buffer);
  }
  free(self);
}
static inline void http_Hash_Delete(Hash self) {
  hsh_Delete(self.hash);
  hsh_Delete(self.valuesSize);
}
void http_Metadata_Delete(PHttpMetaData self) {
  free(self);
}
void http_Request_Delete(PHttpRequest self) {
  if(self->body.buffer) {
    free(self->body.buffer);
  }
  http_URL_Free(self->url);
  http_Hash_Delete(self->headers);
  http_Metadata_Delete(self->metadata);
  free(self);
}
void http_SetBodySize(Hash hash, size_t sz) {
  char buffer[20] = {0};
  snprintf(buffer, sizeof(buffer), "%zu", sz);
  http_Hash_Add(hash, "Content-Length", sizeof("Content-Length") - 1, buffer, strlen(buffer));
}
static inline void http_Response_SetBodySize(PHttpResponse self, size_t sz) {
  http_SetBodySize(self->headers, sz);
}
static inline void http_Request_SetBodySize(PHttpRequest self, size_t sz) {
  http_SetBodySize(self->headers, sz);
}
void http_Response_SetBody(PHttpResponse self, PHttpString buffer) {
  if(self->body.buffer) {
    free(self->body.buffer);
  }
  self->body.buffer = malloc(buffer->sz);
  memcpy(self->body.buffer, buffer->buffer, buffer->sz);
  self->body.sz = buffer->sz;
  http_Response_SetBodySize(self, buffer->sz);
}
static inline size_t http_Response_Size(Hash headers, Array headersArr) {
  size_t totalSize = 0;
  Key *headerBuffer = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(headers, headerBuffer[i].key, headerBuffer[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    }
    totalSize += snprintf(((void *)0), 0, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
  }
  return totalSize;
}
char *http_FormatHeaders(Hash headers, Array headersArr, char *buffer, size_t bufferSize) {
  Key *headerBuffer = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(headers, headerBuffer[i].key, headerBuffer[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    }
    size_t bufferBytesCount = snprintf(((void *)0), 0, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, (char *)valueBuffer.buffer);
    char tempBuffer[bufferBytesCount + 3];
    snprintf(tempBuffer, bufferBytesCount + 3, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, (char *)valueBuffer.buffer);
    memcpy(buffer, tempBuffer, bufferBytesCount);
    buffer += (bufferBytesCount);
  }
  memcpy(buffer, "\r\n", sizeof("\r\n") - 1);
  buffer += sizeof("\r\n") - 1;
  return buffer;
}
char *http_Response_ResponseString(PHttpResponse self) {
  if(self->response >= 200 && self->response <= 299) {
    return "OK";
  }
  if(self->response >= 400 && self->response <= 499) {
    return "Bad Request";
  }
  return "Undefined";
}
HttpString http_Response_ToString(PHttpResponse self) {
  char messageHeader[64] = {0};
  snprintf(messageHeader, sizeof(messageHeader), "%s %u %s\r\n", self->httpCode, self->response, http_Response_ResponseString(self));
  Array headersArr = hsh_GetKeys(self->headers.hash);
  size_t requestSize = http_Response_Size(self->headers, headersArr);
  size_t headerSizeCode = strlen(messageHeader);
  size_t bufferSize = headerSizeCode + requestSize + self->body.sz + 5;
  char *buffer = malloc(bufferSize);
  char *cpyBuffer = buffer;
  memcpy(cpyBuffer, messageHeader, headerSizeCode);
  cpyBuffer += headerSizeCode;
  cpyBuffer = http_FormatHeaders(self->headers, headersArr, cpyBuffer, requestSize);
  if(self->body.buffer) {
    memcpy(cpyBuffer, self->body.buffer, self->body.sz);
    cpyBuffer += self->body.sz;
  }
  hsh_FreeKeys(headersArr);
  return (HttpString) {
    .buffer = buffer,
    .sz = (size_t)(cpyBuffer - buffer)
  };
}
void http_Response_SetDefault(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "text/plain", sizeof("text/plain") - 1);
  http_Hash_Add(self->headers, "Connection", sizeof("Connection") - 1, "close", sizeof("close") - 1);
}
static inline void http_PushString(Array str, HttpString buffer) {
  char *bff = buffer.buffer;
  for(size_t i = 0, c = buffer.sz; i < c; i++) {
    arr_Push(str, &bff[i]);
  }
}
static inline void http_PushCharArray(Array str, char *buffer) {
  for(size_t i = 0, c = strlen(buffer); i < c; i++) {
    arr_Push(str, &buffer[i]);
  }
}
void http_Request_AddTopString(PHttpRequest self, Array str) {
  switch (self->url->method)
  {
    case GET: {
      http_PushString(str, (HttpString) {
        .buffer = "GET",
        .sz = sizeof("GET") - 1
      });
      break;
    }
    case POST: {
      http_PushString(str, (HttpString) {
        .buffer = "POST",
        .sz = sizeof("POST") - 1
      });
      break;
    }
    case PUT: {
      http_PushString(str, (HttpString) {
        .buffer = "PUT",
        .sz = sizeof("PUT") - 1
      });
      break;
    }
    case DELETE: {
      http_PushString(str, (HttpString) {
        .buffer = "DELETE",
        .sz = sizeof("DELETE") - 1
      });
      break;
    }
    case PATCH: {
      http_PushString(str, (HttpString) {
        .buffer = "PATCH",
        .sz = sizeof("PATCH") - 1
      });
      break;
    }
    default:
      break;
  }
  http_PushCharArray(str, " ");
  http_PushString(str, self->url->path);
  http_PushCharArray(str, " ");
  http_PushString(str, (HttpString) {
    .buffer = self->url->httpType,
    .sz = strlen(self->url->httpType)
  });
  http_PushCharArray(str, "\r\n");
}
void http_Request_PushHeaders(Hash header, Array str) {
  Array headersArr = hsh_GetKeys(header.hash);
  Key *keys = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(header, keys[i].key, keys[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    }
    int32_t sz = snprintf(((void *)0), 0, "%.*s: %.*s\r\n", (int)keys[i].keySize, (char *)keys[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
    char response[sz + 2];
    snprintf(response, sz + 2, "%.*s: %.*s\r\n", (int)keys[i].keySize, (char *)keys[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
    http_PushString(str, (HttpString) {
      .buffer = response,
      .sz = sz
    });
  }
  http_PushCharArray(str, "\r\n");
  hsh_FreeKeys(headersArr);
}
static inline void http_Request_PushBody(PHttpRequest self, Array str) {
  http_PushString(str, self->body);
}
HttpString http_Request_ToString(PHttpRequest self) {
  Array response = arr_Init(sizeof(char));
  http_Request_AddTopString(self, response);
  http_Request_PushHeaders(self->headers, response);
  http_Request_PushBody(self, response);
  HttpString rsp = {
    .buffer = response->buffer,
    .sz = response->size
  };
  arr_DeleteWOBuffer(response);
  return rsp;
}
HttpString http_Request_GetPath(PHttpRequest self) {
  return self->url->path;
}
HttpString http_Request_GetBody(PHttpRequest self) {
  return self->body;
}
PHttpRequest http_Request_Create() {
  PHttpRequest self = malloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->url = http_URL_Init();
  self->metadata = http_InitMetadata();
  self->headers = http_Hash_Create();
  self->url->method = GET;
  memcpy(self->url->httpType, "HTTP/1.1", sizeof("HTTP/1.1"));
  return self;
}
PHttpRequest http_Request_Basic() {
  PHttpRequest self = malloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->url = http_URL_Init();
  self->metadata = http_InitMetadata();
  self->headers = http_Hash_Create();
  self->url->method = GET;
  http_Request_AddHeader(self, "Accept", "*/*");
  http_Request_AddHeader(self, "Accept-Encoding", "gzip, deflate, br");
  http_Request_AddHeader(self, "Connection", "keep-alive");
  memcpy(self->url->httpType, "HTTP/1.1", sizeof("HTTP/1.1"));
  return self;
}
void http_Request_AddHeader(PHttpRequest self, char *key, char *value) {
  http_Hash_Add(self->headers, key, strlen(key), value, strlen(value));
}
HttpString http_String_Copy(HttpString str) {
  HttpString response;
  response.sz = str.sz;
  response.buffer = malloc(str.sz);
  memcpy(response.buffer, str.buffer, str.sz);
  return response;
}
void http_Request_SetBody(PHttpRequest self, HttpString str) {
  HttpString resp;
  resp = http_String_Copy(str);
  self->body = resp;
  http_Request_SetBodySize(self, str.sz);
}
void http_Response_SetJSON(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "json", sizeof("json") - 1);
}
void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize) {
  http_Hash_Add(self->headers, key, keySize, value, valueSize);
}
PHttpResponse _http_Response_Empty(Hash headers) {
  PHttpResponse self = malloc(sizeof(HttpResponse));
  memset(self, 0, sizeof(HttpResponse));
  self->headers = headers;
  self->httpCode = "HTTP/1.1";
  self->response = 200;
  http_Response_SetBodySize(self, 0);
  return self;
}
PHttpResponse http_Response_Empty() {
  Hash newHash = http_Hash_Create();
  return _http_Response_Empty(newHash);
}
uint8_t http_Response_ParseCurrentToken(PHttpString buffer, PHttpString token, PHttpString nextPart) {
  char *next = http_GetToken(buffer, token);
  if(!next) {
    return 0;
  }
  http_SetBuffer(*buffer, nextPart, next);
  return 1;
}
uint8_t http_Response_ParseHttpVersion(PHttpString buffer) {
  size_t index = 0;
  while(index < buffer->sz && (buffer->buffer[index] != ' ')) {
    if(buffer->buffer[index] == '\n' || buffer->buffer[index] == '\r') {
      return 0;
    }
    index++;
  }
  buffer->sz = buffer->sz - index;
  buffer->buffer += (size_t)index;
  return 1;
}
uint8_t http_Response_ParseCode(PHttpString buffer) {
  HttpString token = {
    .buffer = "HTTP/",
    .sz = sizeof("HTTP/") - 1
  };
  if(!http_Response_ParseCurrentToken(buffer, &token, buffer)) {
    return 0;
  }
  return http_Response_ParseHttpVersion(buffer);
}
uint8_t http_Response_ParseEmptySpace(PHttpString buffer) {
  HttpString token = {
    .buffer = " ",
    .sz = sizeof(" ") - 1
  };
  return http_Response_ParseCurrentToken(buffer, &token, buffer);
}
uint8_t http_Response_ParseLineSeparator(PHttpString buffer) {
  HttpString token = {
    .buffer = "\r\n",
    .sz = sizeof("\r\n") - 1
  };
  return http_Response_ParseCurrentToken(buffer, &token, buffer);
}
static inline void http_Response_SetCode(PHttpResponse self, char *buffer) {
  self->response = (buffer[0] - '0') * 100 + (buffer[1] - '0') * 10 + (buffer[2] - '0');
}
static inline void http_SetBuffer(HttpString buffer, PHttpString nextPart, char *next) {
  *nextPart = (HttpString) {
    .buffer = next,
    .sz = (size_t)((buffer.buffer + buffer.sz) - next)
  };
}
uint8_t http_Response_ParseHttpCode(PHttpResponse self, PHttpString buffer) {
  char *next = http_ChompString(buffer, "0123456789", 1);
  if(!next || (next - buffer->buffer != 0x3)) {
    return 0;
  }
  http_Response_SetCode(self, buffer->buffer);
  http_SetBuffer(*buffer, buffer, next);
  return 1;
}
uint8_t http_Response_ParseMessage(PHttpString buffer) {
  char *next = http_ChompString(buffer, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./;:<=>?@[\\]^_`{|}~ ", 1);
  if(!next) {
    return 0;
  }
  http_SetBuffer(*buffer, buffer, next);
  return 1;
}
uint8_t http_Response_ParseBody(PHttpResponse self, PHttpServer buffer) {
  return 1;
}
PHttpResponse http_Response_Chomp_t(HttpString *bff) {
  if(!http_Response_ParseCode(bff)) {
    return ((void *)0);
  }
  if(!http_Response_ParseEmptySpace(bff)) {
    return ((void *)0);
  }
  char *_endBuffer = bff->buffer + bff->sz;
  PHttpResponse self = http_Response_Empty();
  if(!http_Response_ParseHttpCode(self, bff)) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  if(!http_Response_ParseEmptySpace(bff)) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  if(!http_Response_ParseMessage(bff)) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  if(!http_Response_ParseLineSeparator(bff)) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  if(!http_Header_Parse(self->headers, _endBuffer, bff)) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  uint8_t valid;
  self->body = http_Body_ProcessWithError(self->headers, _endBuffer, bff, &valid);
  if(!valid) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  return self;
}
PHttpResponse http_Response_Chomp(HttpString bff, char **endBuffer) {
  PHttpResponse response = http_Response_Chomp_t(&bff);
  if(!response) {
    return ((void *)0);
  }
  *endBuffer = bff.buffer;
  return response;
}
PHttpResponse http_Response_Parse(HttpString buffer) {
  PHttpResponse self = http_Response_Chomp_t(&buffer);
  if(!self) {
    return ((void *)0);
  }
  if(buffer.sz) {
    http_Response_Delete(self);
    return ((void *)0);
  }
  return self;
}
HttpString http_Response_GetValue(PHttpResponse self, char *buffer) {
  return http_Hash_GetValue(self->headers, buffer, strlen(buffer));
}
PHttpResponse http_Response_Create() {
  PHttpResponse self = http_Response_Empty();
  http_Response_SetDefault(self);
  return self;
}
void http_Response_Delete(PHttpResponse self) {
  if(self->body.buffer) {
    free(self->body.buffer);
  }
  http_Hash_Delete(self->headers);
  free(self);
}
typedef struct RequestMetadata_t {
  RequestStruct metadata;
  PConnection conn;
  uint64_t requestDateMS;
  PNetworkBuffer buffer;
} RequestMetadata;
typedef RequestMetadata *PRequestMetadata;
HttpString sock_Client_ReceiveWithErrors(PConnection conn);
void httpS_Request_CleanHangingConnections(const PHttpRequestServer self);
static void httpS_Request_FreeRequestMetadata(const PRequestMetadata metadata);
PHttpRequestServer httpS_Request_Create(int64_t timeoutMS) {
  PHttpRequestServer self = malloc(sizeof(HttpRequestServer));
  self->requests = arr_Init(sizeof(RequestMetadata));
  self->timeoutMS = timeoutMS;
  self->maxSizeInB = 1024 * 1024 * 10;
  return self;
}
void httpS_Request_Delete(PHttpRequestServer self) {
  httpS_Request_CleanHangingConnections(self);
  arr_Delete(self->requests);
  free(self);
}
void httpS_Request_Send(PHttpRequestServer self, RequestStruct request) {
  RequestMetadata toAdd = {
    .conn = ((void *)0),
    .metadata = request,
    .requestDateMS = tf_CurrentTimeMS(),
    .buffer = tpd_Create(self->maxSizeInB)
  };
  arr_Push(self->requests, &toAdd);
}
void httpS_Request_ProcessRequests(PHttpRequestServer self, PRequestMetadata data) {
  DataFragment frag = {
    .size = data->metadata.query.sz,
    .persistent = 0,
    .conn = *data->conn,
    .data = data->metadata.query.buffer
  };
  sock_Client_SendMessage(&frag);
}
void httpS_Request_ProcessPendingRequests(PHttpRequestServer self) {
  RequestMetadata *buffer = self->requests->buffer;
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(buffer[i].conn) {
      continue;
    }
    buffer[i].conn = sock_Client_Connect(buffer[i].metadata.port, buffer[i].metadata.ip);
    if(!buffer[i].conn) {
      continue;
    }
    httpS_Request_ProcessRequests(self, &buffer[i]);
  }
}
static inline void httpS_Request_ExecuteErrorMethod(PSocketMethod method, RequestError error) {
  if(!method) {
    return ;
  }
  void (*onFailure)(RequestError, void *) = method->method;
  onFailure(error, method->mirrorBuffer);
}
static inline void httpS_Request_ExecuteSuccessMethod(PSocketMethod method, PHttpResponse response) {
  if(!method) {
    return ;
  }
  void (*onSuccess)(PHttpResponse, void *) = method->method;
  onSuccess(response, method->mirrorBuffer);
}
static inline PHttpResponse httpS_Response_Process(const PHttpRequestServer self, const HttpString msg, const PRequestMetadata metadata, uint8_t *incomplete) {
  *incomplete = 0;
  if(!tpd_Push(metadata->buffer, msg.buffer, msg.sz)) {
    return ((void *)0);
  }
  PHttpResponse resp = http_Response_NB_Get(metadata->buffer);
  if(!resp) {
    *incomplete = 1;
    return ((void *)0);
  }
  return resp;
}
static inline uint8_t httpS_Request_ProcessCurrentFragment(const PHttpRequestServer self, const PRequestMetadata metadata, const uint64_t deltaMS) {
  if(metadata->requestDateMS <= deltaMS) {
    httpS_Request_ExecuteErrorMethod(metadata->metadata.onFailure, RESPONSE_TIMEOUT);
    return 1;
  }
  HttpString response = sock_Client_ReceiveWithErrors(metadata->conn);
  if(!response.buffer) {
    return 0;
  }
  uint8_t incomplete;
  PHttpResponse httpResponse = httpS_Response_Process(self, response, metadata, &incomplete);
  if(incomplete) {
    free(response.buffer);
    return 0;
  }
  if(!httpResponse) {
    free(response.buffer);
    httpS_Request_ExecuteErrorMethod(metadata->metadata.onFailure, RESPONSE_PARSE_ERROR);
    return 1;
  }
  free(response.buffer);
  httpS_Request_ExecuteSuccessMethod(metadata->metadata.onSuccess, httpResponse);
  http_Response_Delete(httpResponse);
  metadata->requestDateMS -= deltaMS;
  return 1;
}
static void httpS_Request_FreeRequestMetadata(const PRequestMetadata metadata) {
  sock_Client_Free(metadata->conn);
  tpd_Delete(metadata->buffer);
  metadata->conn = ((void *)0);
}
void httpS_Request_CleanHangingConnections(const PHttpRequestServer self) {
  RequestMetadata *buffer = self->requests->buffer;
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(!buffer[i].conn) {
      continue;
    }
    httpS_Request_FreeRequestMetadata(&buffer[i]);
  }
}
void httpS_Request_ProcessActiveRequests(PHttpRequestServer self, uint64_t deltaMS) {
  RequestMetadata *buffer = self->requests->buffer;
  Array indexes = arr_Init(sizeof(size_t));
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(!buffer[i].conn) {
      continue;
    }
    if(httpS_Request_ProcessCurrentFragment(self, &buffer[i], deltaMS)) {
      arr_Push(indexes, &i);
      httpS_Request_FreeRequestMetadata(&buffer[i]);
      buffer[i].conn = ((void *)0);
    }
  }
  Array request = self->requests;
  self->requests = arr_RemoveElements(self->requests, indexes);
  arr_Delete(request);
  arr_Delete(indexes);
}
void httpS_Request_OnFrame(PHttpRequestServer self, uint64_t deltaMS) {
  httpS_Request_ProcessPendingRequests(self);
  httpS_Request_ProcessActiveRequests(self, deltaMS);
}
typedef struct HttpConnectionProtocol_t {
  Connection conn;
  PNetworkBuffer buff;
} HttpConnectionProtocol;
void httpS_InitializeMethods(PHttpServer self);
static void httpS_ReleaseConns(const PHttpServer self);
static void httpS_Remove(const PHttpServer self, const PDataFragment dt, const HttpConnectionProtocol *protocol);
PHttpServer httpS_Create(uint16_t port) {
  PHttpServer self = malloc(sizeof(HttpServer));
  memset(self, 0, sizeof(HttpServer));
  self->server = sock_Create(port);
  self->connections = arr_Init(sizeof(HttpConnectionProtocol));
  self->maximumRequestSize = 1024 * 1024 * 10;
  httpS_InitializeMethods(self);
  return self;
}
void httpS_SetMethod(PHttpServer self, PSocketMethod onReceive) {
  self->onReceive = onReceive;
}
PHttpResponse httpS_PrivateCaller(PHttpServer self, PHttpRequest req) {
  PHttpResponse (*caller)(PHttpRequest, void *) = (PHttpResponse (*)(PHttpRequest, void *))self->onReceive->method;
  return caller(req, self->onReceive->mirrorBuffer);
}
void remote_OnConnect(Connection conn, void *mirror) {
  PHttpServer self = mirror;
  HttpConnectionProtocol proto = {
    .conn = conn,
    .buff = tpd_Create(self->maximumRequestSize)
  };
  arr_Push(self->connections, &proto);
}
static void httpS_ReleaseConns(const PHttpServer self) {
  HttpConnectionProtocol *conns = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    tpd_Delete(conns[i].buff);
  }
  arr_Delete(self->connections);
}
JsonElement httpS_Json_Get(PHttpRequest req) {
  if(!req->body.buffer) {
    return (JsonElement) {
      .type = JSON_INVALID
    };
  }
  char *_endingBuffer = ((void *)0);
  JsonElement jsonElement = json_Parse((HttpString) {
    .buffer = req->body.buffer,
    .sz = req->body.sz
  }, &_endingBuffer);
  if(jsonElement.type != JSON_JSON || _endingBuffer != req->body.buffer + req->body.sz) {
    json_DeleteElement(jsonElement);
    return (JsonElement) {
      .type = JSON_INVALID
    };
  }
  return jsonElement;
}
PHttpResponse httpS_Json_Post(JsonElement jsn) {
  PHttpResponse response = http_Response_Create();
  HttpString str = json_Element_ToString(jsn);
  http_Response_SetBody(response, &str);
  if(jsn.type == JSON_JSON) {
    http_Response_SetJSON(response);
  }
  free(str.buffer);
  return response;
}
RequestStruct httpS_Request_StructInit(HttpString ip, uint16_t port) {
  RequestStruct response;
  memset(&response, 0, sizeof(RequestStruct));
  response.ip[ip.sz] = 0;
  memcpy(response.ip, ip.buffer, ip.sz);
  response.port = port;
  return response;
}
static HttpConnectionProtocol *httpS_Request_FindConn(const PHttpServer self, const PDataFragment dt) {
  HttpConnectionProtocol *conns = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    if(conns[i].conn.fd == dt->conn.fd) {
      return &conns[i];
    }
  }
  return ((void *)0);
}
static PHttpRequest httpS_Request_ParseData(const PHttpServer self, const PDataFragment dt, uint8_t *incomplete) {
  *incomplete = 0;
  HttpConnectionProtocol *protocol = httpS_Request_FindConn(self, dt);
  if(!protocol) {
    sock_PushCloseConnections(self->server, &dt->conn);
    return ((void *)0);
  }
  if(!tpd_Push(protocol->buff, dt->data, dt->size)) {
    sock_PushCloseConnections(self->server, &dt->conn);
    return ((void *)0);
  }
  PHttpRequest request = http_Request_NB_Get(protocol->buff);
  if(!request) {
    *incomplete = 1;
    return ((void *)0);
  }
  httpS_Remove(self, dt, protocol);
  return request;
}
static void httpS_Remove(const PHttpServer self, const PDataFragment dt, const HttpConnectionProtocol *protocol) {
  tpd_Delete(protocol->buff);
  size_t index = (HttpConnectionProtocol *)protocol - (HttpConnectionProtocol *)self->connections->buffer;
  arr_RemoveElement(self->connections, index);
  sock_PushCloseConnections(self->server, &dt->conn);
}
void remote_OnReceiveMessage(PDataFragment frag, void *buffer) {
  PHttpServer self = buffer;
  if(!self->onReceive) {
    sock_PushCloseConnections(self->server, &frag->conn);
    return ;
  }
  uint8_t incomplete;
  PHttpRequest req = httpS_Request_ParseData(self, frag, &incomplete);
  if(!req || incomplete) {
    return ;
  }
  PHttpResponse response = httpS_PrivateCaller(self, req);
  HttpString responseString = http_Response_ToString(response);
  if(!responseString.buffer) {
    return ;
  }
  DataFragment dt = {
    .conn = frag->conn,
    .data = responseString.buffer,
    .persistent = 1,
    .size = responseString.sz
  };
  sock_Write_Push(self->server, &dt);
  free(responseString.buffer);
  http_Response_Delete(response);
  http_Request_Delete(req);
}
void httpS_InitializeMethods(PHttpServer self) {
  PSocketMethod onReceive = sock_Method_Create(
    (void *)remote_OnReceiveMessage,
    self
  );
  self->server->onReceiveMessage = onReceive;
  PSocketMethod onConnect = sock_Method_Create(
    (void *)remote_OnConnect,
    self
  );
  self->server->onConnectionAquire = onConnect;
}
void httpS_Delete(PHttpServer self) {
  sock_Method_Delete(self->server->onConnectionAquire);
  sock_Method_Delete(self->server->onReceiveMessage);
  httpS_ReleaseConns(self);
  sock_Delete(self->server);
  free(self);
}
void httpS_OnFrame(PHttpServer self, uint64_t deltaMS) {
  sock_OnFrame(self->server, deltaMS);
}

extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

void json_ToString_t(PJsonObject self, Array str);
void json_DeleteArray(JsonElement element);
void json_PushLeafValue(Array str, JsonElement element);
typedef struct TokenParser_t {
  char *startToken;
  char *endToken;
  char *endingBuffer;
} TokenParser;
typedef TokenParser *PTokenParser;
JsonElement json_Parser_Get_Array(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Map(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Null(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Boolean(TokenParser tck, PTokenParser next);
TokenParser json_Parser_Array(TokenParser tck);
TokenParser json_Parser_Null(TokenParser tck);
TokenParser json_Parser_Boolean(TokenParser tck);
TokenParser json_Parser_Map(TokenParser tck);
PJsonObject json_Create() {
  PJsonObject self = malloc(sizeof(JsonObject));
  self->hsh = hsh_Create();
  self->selfContained = 0;
  return self;
}
void json_Add(PJsonObject self, PHttpString key, JsonElement element) {
  ((void) sizeof ((self->hsh) ? 1 : 0), __extension__ ({ if (self->hsh) ; else __assert_fail ("self->hsh", "bin/svv.c", 2240, __extension__ __PRETTY_FUNCTION__); }));
  hsh_Add(self->hsh, key->buffer, key->sz, &element, sizeof(JsonElement));
}
void json_Delete(PJsonObject self) {
  json_RemoveSelfContainedData(self);
  hsh_Delete(self->hsh);
  free(self);
}
static inline void json_PushString(Array str, char *strC, size_t sz) {
  for(size_t i = 0; i < sz; i++) {
    arr_Push(str, &strC[i]);
  }
}
static inline size_t json_Parser_CurrentSize(PTokenParser tck) {
  return (size_t)(tck->endingBuffer - tck->endToken);
}
static inline uint8_t json_Parser_IsInvalid(TokenParser tck) {
  return !tck.endingBuffer || !tck.endToken || !tck.startToken;
}
static inline uint8_t json_Parser_Get_IsInvalid(JsonElement tck) {
  return tck.type == JSON_INVALID;
}
static inline JsonElement json_Parser_Get_Invalid() {
  return (JsonElement) {
    .type = JSON_INVALID
  };
}
static inline TokenParser json_Parse_Invalid() {
  return (TokenParser) {
    .startToken = ((void *)0),
    .endToken = ((void *)0),
    .endingBuffer = ((void *)0)
  };
}
static inline void json_Element_PushInteger(Array str, int64_t number) {
  char arr[21] = {0};
  snprintf(arr, sizeof(arr) - 1, "%ld", number);
  json_PushString(str, arr, strlen(arr));
}
static inline void json_Element_PushFloat(Array str, float number) {
  char arr[21] = {0};
  snprintf(arr, sizeof(arr) - 1, "%f", number);
  json_PushString(str, arr, strlen(arr));
}
static inline JsonElement json_Element_Invalid() {
  return (JsonElement) {
    .type = JSON_INVALID
  };
}
static inline void json_Element_PushString(Array str, PHttpString value) {
  arr_Push(str, &(char){'"'});
  char *bff = value->buffer;
  for(size_t i = 0, c = value->sz; i < c; i++) {
    arr_Push(str, &bff[i]);
  }
  arr_Push(str, &(char){'"'});
}
void json_PushLeafArray(Array str, JsonElement element) {
  arr_Push(str, &(char){'['});
  Array currentVector = element.value;
  JsonElement *arrList = currentVector->buffer;
  for(size_t i = 0, c = currentVector->size; i < c; i++) {
    json_PushLeafValue(str, arrList[i]);
    if(i != c - 1) {
      arr_Push(str, &(char){','});
    }
  }
  arr_Push(str, &(char){']'});
}
void json_PushLeafValue(Array str, JsonElement element) {
  switch (element.type)
  {
    case JSON_NULL: {
      json_PushString(str, "null", sizeof("null") - 1);
      break;
    }
    case JSON_BOOLEAN: {
      if(element.value > ((void *)0)) {
        json_PushString(str, "true", sizeof("true") - 1);
        return ;
      }
      json_PushString(str, "false", sizeof("false") - 1);
      break;
    }
    case JSON_INVALID: {
      json_PushString(str, "INVALID_JSON_ELEMENT", sizeof("INVALID_JSON_ELEMENT") - 1);
      break;
    }
    case JSON_JSON: {
      json_ToString_t(element.value, str);
      break;
    }
    case JSON_INTEGER: {
      ((void) sizeof ((element.value) ? 1 : 0), __extension__ ({ if (element.value) ; else __assert_fail ("element.value", "bin/svv.c", 2346, __extension__ __PRETTY_FUNCTION__); }));
      json_Element_PushInteger(str, *(int64_t *)element.value);
      break;
    }
    case JSON_NUMBER: {
      ((void) sizeof ((element.value) ? 1 : 0), __extension__ ({ if (element.value) ; else __assert_fail ("element.value", "bin/svv.c", 2351, __extension__ __PRETTY_FUNCTION__); }));
      json_Element_PushFloat(str, *(float *)element.value);
      break;
    }
    case JSON_STRING: {
      ((void) sizeof ((element.value) ? 1 : 0), __extension__ ({ if (element.value) ; else __assert_fail ("element.value", "bin/svv.c", 2356, __extension__ __PRETTY_FUNCTION__); }));
      json_Element_PushString(str, element.value);
      break;
    }
    case JSON_ARRAY: {
      json_PushLeafArray(str, element);
      break;
    }
    default:
      break;
  }
}
void json_PushLeafElement(Array str, PHttpString key, JsonElement element, int8_t lastElement) {
  arr_Push(str, &(char){'"'});
  char *bff = key->buffer;
  for(size_t i = 0, c = key->sz; i < c; i++) {
    arr_Push(str, &bff[i]);
  }
  arr_Push(str, &(char){'"'});
  arr_Push(str, &(char){':'});
  json_PushLeafValue(str, element);
  if(!lastElement) {
    arr_Push(str, &(char){','});
  }
}
void json_ToString_t(PJsonObject self, Array str) {
  arr_Push(str, &(char){'{'});
  Array keys = hsh_GetKeys(self->hsh);
  Key *keysBuffer = keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    HttpString currentKey = {
      .buffer = keysBuffer[i].key,
      .sz = keysBuffer[i].keySize
    };
    JsonElement *currentElement = hsh_GetBuffer(self->hsh, currentKey.buffer, currentKey.sz);
    json_PushLeafElement(str, &currentKey, *currentElement, i == keys->size - 1);
    free(currentKey.buffer);
  }
  arr_Push(str, &(char){'}'});
  arr_Delete(keys);
}
HttpString json_ToString(PJsonObject self) {
  Array rsp = arr_Init(sizeof(char));
  json_ToString_t(self, rsp);
  HttpString response = {
    .buffer = rsp->buffer,
    .sz = rsp->size
  };
  arr_DeleteWOBuffer(rsp);
  return response;
}
HttpString json_Element_ToString(JsonElement self) {
  Array responseString = arr_Init(sizeof(char));
  json_PushLeafValue(responseString, self);
  HttpString response = {
    .buffer = responseString->buffer,
    .sz = responseString->size
  };
  arr_DeleteWOBuffer(responseString);
  return response;
}
void json_DeleteElement(JsonElement element) {
  switch (element.type)
  {
    case JSON_INTEGER: {
      free(element.value);
      break;
    }
    case JSON_NUMBER: {
      free(element.value);
      break;
    }
    case JSON_STRING: {
      free(((PHttpString)element.value)->buffer);
      free(element.value);
      break;
    }
    case JSON_JSON: {
      json_Delete(element.value);
      break;
    }
    case JSON_ARRAY: {
      json_DeleteArray(element);
      break;
    }
    default:
      break;
  }
}
void json_DeleteArray(JsonElement element) {
  Array listArr = element.value;
  JsonElement *arr = listArr->buffer;
  for(size_t i = 0, c = listArr->size; i < c; i++) {
    json_DeleteElement(arr[i]);
  }
  arr_Delete(listArr);
}
void json_RemoveSelfContainedData(PJsonObject self) {
  if(!self || !self->selfContained) {
    return ;
  }
  Array values = hsh_GetValues(self->hsh, sizeof(JsonElement));
  JsonElement *elements = values->buffer;
  for(size_t i = 0, c = values->size; i < c; i++) {
    json_DeleteElement(elements[i]);
  }
  arr_Delete(values);
}
void json_Parser_RemoveFillers(PTokenParser tck) {
  size_t sz = json_Parser_CurrentSize(tck);
  size_t startingIndex = 0;
  while(startingIndex < sz && (tck->endToken[startingIndex] == ' '
      || tck->endToken[startingIndex] == '\n'
      || tck->endToken[startingIndex] == '\t')) {
    startingIndex++;
  }
  tck->endToken += startingIndex;
}
TokenParser json_Parser_Token(TokenParser tck, char *token, size_t tokenSize) {
  size_t sz = json_Parser_CurrentSize(&tck);
  if(sz < tokenSize || memcmp(tck.endToken, token, (sz < tokenSize ? sz : tokenSize) * sizeof(char))) {
    return json_Parse_Invalid();
  }
  return (TokenParser) {
    .startToken = tck.endToken,
    .endToken = tck.endToken + tokenSize,
    .endingBuffer = tck.endingBuffer
  };
}
static inline TokenParser json_Parser_Token_IgnoreErrors(TokenParser tck, char *token, size_t tokenSize) {
  TokenParser resp = json_Parser_Token(tck, token, tokenSize);
  if(json_Parser_IsInvalid(resp)) {
    return tck;
  }
  return resp;
}
uint8_t json_Parser_IsCharValid(char val) {
  return val != '"';
}
TokenParser json_Parser_String(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "\"", sizeof("\"") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  while(tck.endToken < tck.endingBuffer) {
    TokenParser specialCharOffset = json_Parser_Token(tck, "\\\"", sizeof("\\\"") - 1);
    if(!json_Parser_IsInvalid(specialCharOffset)) {
      tck.endToken = specialCharOffset.endToken;
      continue;
    }
    if(!json_Parser_IsCharValid(*tck.endToken)) {
      break;
    }
    tck.endToken++;
  }
  if(tck.endToken >= tck.endingBuffer) {
    return json_Parse_Invalid();
  }
  tck = json_Parser_Token(tck, "\"", sizeof("\"") - 1);
  tck.startToken = cpyTck.startToken;
  return tck;
}
TokenParser json_Parser_Null(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "null", sizeof("null") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return json_Parse_Invalid();
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
void json_Map_Add(JsonElement map, char *key, JsonElement element) {
  ((void) sizeof ((map.type == JSON_JSON) ? 1 : 0), __extension__ ({ if (map.type == JSON_JSON) ; else __assert_fail ("map.type == JSON_JSON", "bin/svv.c", 2547, __extension__ __PRETTY_FUNCTION__); }));
  HttpString str = {
    .buffer = key,
    .sz = strlen(key)
  };
  json_Add(map.value, &str, element);
}
JsonElement json_Integer_Create(int64_t val) {
  JsonElement element = {
    .type = JSON_INTEGER,
    .value = malloc(sizeof(int64_t))
  };
  *(int64_t *)element.value = val;
  return element;
}
JsonElement json_Map_Create() {
  PJsonObject json = json_Create();
  json->selfContained = 1;
  return (JsonElement) {
    .type = JSON_JSON,
    .value = json
  };
}
JsonElement json_String_Create(char *string) {
  PHttpString str = malloc(sizeof(HttpString));
  str->sz = strlen(string);
  str->buffer = malloc(str->sz);
  memcpy(str->buffer, string, str->sz);
  return (JsonElement) {
    .type = JSON_STRING,
    .value = str
  };
}
JsonElement json_String_CreateFromHttpString(HttpString string) {
  PHttpString str = malloc(sizeof(HttpString));
  str->sz = string.sz;
  str->buffer = malloc(str->sz);
  memcpy(str->buffer, string.buffer, str->sz);
  return (JsonElement) {
    .type = JSON_STRING,
    .value = str
  };
}
void json_Map_String_String_Add(JsonElement map, char *key, char *value) {
  if(map.type != JSON_JSON) {
    return ;
  }
  JsonElement element = json_String_Create(value);
  json_Map_Add(map, key, element);
}
void json_Map_String_Integer_Add(JsonElement map, char *key, int64_t value) {
  if(map.type != JSON_JSON) {
    return ;
  }
  JsonElement element = json_Integer_Create(value);
  json_Map_Add(map, key, element);
}
JsonElement json_Number_Create(float val) {
  JsonElement element = {
    .type = JSON_NUMBER,
    .value = malloc(sizeof(float))
  };
  *(float *)element.value = val;
  return element;
}
TokenParser json_Parser_Boolean(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser srt = json_Parser_Token(tck, "true", sizeof("true") - 1);
  if(!json_Parser_IsInvalid(srt)) {
    tck = srt;
    return tck;
  }
  srt = json_Parser_Token(tck, "false", sizeof("false") - 1);
  if(!json_Parser_IsInvalid(srt)) {
    tck = srt;
    return tck;
  }
  return json_Parse_Invalid();
}
TokenParser json_Parser_Integer(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token_IgnoreErrors(tck, "-", sizeof("-") - 1);
  uint8_t checker = 0;
  while(tck.endToken < tck.endingBuffer && ((*__ctype_b_loc ())[(int) ((*tck.endToken))] & (unsigned short int) _ISdigit)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
TokenParser json_Parser_Number(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token_IgnoreErrors(tck, "-", sizeof("-") - 1);
  uint8_t checker = 0;
  while(tck.endToken < tck.endingBuffer && ((*__ctype_b_loc ())[(int) ((*tck.endToken))] & (unsigned short int) _ISdigit)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck = json_Parser_Token(tck, ".", sizeof(".") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  checker = 0;
  while(tck.endToken < tck.endingBuffer && ((*__ctype_b_loc ())[(int) ((*tck.endToken))] & (unsigned short int) _ISdigit)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
TokenParser json_Parser_Comma(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, ",", sizeof(",") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
static inline TokenParser json_Parser_Splitter(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, ":", sizeof(":") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
static void *parserMethods[] = {
  (void *)json_Parser_Null,
  (void *)json_Parser_Boolean,
  (void *)json_Parser_String,
  (void *)json_Parser_Number,
  (void *)json_Parser_Integer,
  (void *)json_Parser_Map,
  (void *)json_Parser_Array
};
TokenParser json_Parser_Array(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "[", sizeof("[") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  TokenParser ncpy = tck;
  while(ncpy.endToken < ncpy.endingBuffer) {
    uint8_t validToken = 0;
    for(size_t i = 0; i < sizeof(parserMethods) / sizeof(void *); i++) {
      TokenParser (*tokenMethod)(TokenParser) = (TokenParser (*)(TokenParser)) (((size_t *)parserMethods)[i]);
      TokenParser next = tokenMethod(ncpy);
      if(json_Parser_IsInvalid(next)) {
        continue;
      }
      ncpy = next;
      validToken = 1;
      break;
    }
    if(!validToken) {
      return json_Parse_Invalid();
    }
    TokenParser comma = json_Parser_Comma(ncpy);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    ncpy = comma;
  }
  tck.endToken = ncpy.endToken;
  json_Parser_RemoveFillers(&tck);
  tck = json_Parser_Token(tck, "]", sizeof("]") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
TokenParser json_Parser_Map(TokenParser tck) {
  json_Parser_RemoveFillers(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "{", sizeof("{") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  TokenParser ncpy = tck;
  while(ncpy.endToken < ncpy.endingBuffer) {
    uint8_t validToken = 0;
    ncpy = json_Parser_String(ncpy);
    if(json_Parser_IsInvalid(ncpy)) {
      return json_Parse_Invalid();
    }
    ncpy = json_Parser_Splitter(ncpy);
    if(json_Parser_IsInvalid(ncpy)) {
      return json_Parse_Invalid();
    }
    for(size_t i = 0; i < sizeof(parserMethods) / sizeof(void *); i++) {
      TokenParser (*tokenMethod)(TokenParser) = (TokenParser (*)(TokenParser)) (((size_t *)parserMethods)[i]);
      TokenParser next = tokenMethod(ncpy);
      if(json_Parser_IsInvalid(next)) {
        continue;
      }
      ncpy = next;
      validToken = 1;
      break;
    }
    if(!validToken) {
      return json_Parse_Invalid();
    }
    TokenParser comma = json_Parser_Comma(ncpy);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    ncpy = comma;
  }
  tck.endToken = ncpy.endToken;
  json_Parser_RemoveFillers(&tck);
  tck = json_Parser_Token(tck, "}", sizeof("}") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}
JsonElement json_Parser_Get_String(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_String(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  const size_t stringSize = (size_t)(nextTck.endToken - nextTck.startToken) - 2;
  PHttpString responseString = malloc(sizeof(HttpString));
  responseString->sz = stringSize;
  responseString->buffer = malloc(stringSize + 1);
  memcpy(responseString->buffer, nextTck.startToken + 1, stringSize);
  if(next) {
    *next = nextTck;
  }
  return (JsonElement) {
    .type = JSON_STRING,
    .value = responseString
  };
}
JsonElement json_Parser_Get_Integer(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Integer(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  JsonElement response = {
    .type = JSON_INTEGER
  };
  char *endingPointer;
  (*__errno_location ()) = 0;
  int64_t nrm = strtoll(nextTck.startToken, &endingPointer, 10);
  if((*__errno_location ()) == 34 || endingPointer == nextTck.startToken) {
    return json_Element_Invalid();
  }
  response.value = malloc(sizeof(int64_t));
  memcpy(response.value, &nrm, sizeof(int64_t));
  if(next) {
    *next = nextTck;
  }
  return response;
}
JsonElement json_Parser_Get_Number(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Number(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  JsonElement response = {
    .type = JSON_NUMBER
  };
  char *endingPointer;
  (*__errno_location ()) = 0;
  float nrm = strtof(nextTck.startToken, &endingPointer);
  if((*__errno_location ()) == 34 || endingPointer == nextTck.startToken) {
    return json_Element_Invalid();
  }
  response.value = malloc(sizeof(float));
  memcpy(response.value, &nrm, sizeof(float));
  if(next) {
    *next = nextTck;
  }
  return response;
}
static inline TokenParser json_Parser_Open_SquareBracket(TokenParser token) {
  json_Parser_RemoveFillers(&token);
  token = json_Parser_Token_IgnoreErrors(token, "[", sizeof("[") - 1);
  return token;
}
static inline TokenParser json_Parser_Close_SquareBracket(TokenParser token) {
  json_Parser_RemoveFillers(&token);
  token = json_Parser_Token_IgnoreErrors(token, "]", sizeof("]") - 1);
  return token;
}
static inline TokenParser json_Parser_Open_CurlyBracket(TokenParser token) {
  json_Parser_RemoveFillers(&token);
  token = json_Parser_Token_IgnoreErrors(token, "{", sizeof("{") - 1);
  return token;
}
static inline TokenParser json_Parser_Close_CurlyBracket(TokenParser token) {
  json_Parser_RemoveFillers(&token);
  token = json_Parser_Token_IgnoreErrors(token, "}", sizeof("}") - 1);
  return token;
}
static inline TokenParser json_Parser_Close_Splitter(TokenParser token) {
  json_Parser_RemoveFillers(&token);
  token = json_Parser_Token_IgnoreErrors(token, ":", sizeof(":") - 1);
  return token;
}
static void *parserGetMethods[] = {
  json_Parser_Get_Null,
  json_Parser_Get_Boolean,
  json_Parser_Get_String,
  json_Parser_Get_Number,
  json_Parser_Get_Integer,
  json_Parser_Get_Map,
  json_Parser_Get_Array
};
JsonElement json_Parser_Get_Array(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Array(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  Array rspArray = arr_Init(sizeof(JsonElement));
  JsonElement response = {
    .type = JSON_ARRAY,
    .value = rspArray
  };
  tck = json_Parser_Open_SquareBracket(tck);
  TokenParser cpyTck = tck;
  while(1) {
    for(size_t i = 0; i < sizeof(parserGetMethods) / sizeof(void *); i++) {
      JsonElement (*tokenMethod)(TokenParser, PTokenParser) = (JsonElement (*)(TokenParser, PTokenParser)) (((size_t *)parserGetMethods)[i]);
      JsonElement currentElement = tokenMethod(cpyTck, &cpyTck);
      if(json_Parser_Get_IsInvalid(currentElement)) {
        continue;
      }
      arr_Push(rspArray, &currentElement);
      break;
    }
    TokenParser comma = json_Parser_Comma(cpyTck);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    cpyTck = comma;
  }
  cpyTck = json_Parser_Close_SquareBracket(cpyTck);
  if(next) {
    *next = cpyTck;
  }
  return response;
}
void json_Parser_Print(JsonElement self) {
  HttpString strResponse = json_Element_ToString(self);
  printf("%.*s\n", (uint32_t)strResponse.sz, strResponse.buffer);
  free(strResponse.buffer);
}
JsonElement json_Parser_Get_Null(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Null(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  JsonElement response = {
    .type = JSON_NULL
  };
  if(next) {
    *next = nextTck;
  }
  return response;
}
JsonElement json_Parser_Get_Boolean(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Boolean(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  json_Parser_RemoveFillers(&tck);
  size_t validTrue = (size_t)json_Parser_IsInvalid(json_Parser_Token(tck, "false", sizeof("false") - 1));
  JsonElement response = {
    .type = JSON_BOOLEAN,
    .value = (void *)validTrue
  };
  if(next) {
    *next = nextTck;
  }
  return response;
}
JsonElement json_Parser_Get_Map(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Map(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  PJsonObject jsn = json_Create();
  jsn->selfContained = 1;
  JsonElement response = {
    .type = JSON_JSON,
    .value = jsn
  };
  tck = json_Parser_Open_CurlyBracket(tck);
  TokenParser cpyTck = tck;
  while(1) {
    JsonElement key = json_Parser_Get_String(cpyTck, &cpyTck);
    cpyTck = json_Parser_Close_Splitter(cpyTck);
    for(size_t i = 0; i < sizeof(parserGetMethods) / sizeof(void *); i++) {
      JsonElement (*tokenMethod)(TokenParser, PTokenParser) = (JsonElement (*)(TokenParser, PTokenParser)) (((size_t *)parserGetMethods)[i]);
      JsonElement currentElement = tokenMethod(cpyTck, &cpyTck);
      if(json_Parser_Get_IsInvalid(currentElement)) {
        continue;
      }
      json_Add((PJsonObject)response.value, key.value, currentElement);
      break;
    }
    json_DeleteElement(key);
    TokenParser comma = json_Parser_Comma(cpyTck);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    cpyTck = comma;
  }
  cpyTck = json_Parser_Close_CurlyBracket(cpyTck);
  if(next) {
    *next = cpyTck;
  }
  return response;
}
JsonElement json_Parse(HttpString buffer, char **nextBuffer) {
  TokenParser tck = (TokenParser) {
    .startToken = buffer.buffer,
    .endToken = buffer.buffer,
    .endingBuffer = buffer.buffer + buffer.sz
  };
  for(size_t i = 0; i < sizeof(parserGetMethods) / sizeof(void *); i++) {
    JsonElement (*tokenMethod)(TokenParser, PTokenParser) = (JsonElement (*)(TokenParser, PTokenParser)) (((size_t *)parserGetMethods)[i]);
    JsonElement currentElement = tokenMethod(tck, &tck);
    if(json_Parser_Get_IsInvalid(currentElement)) {
      continue;
    }
    if(nextBuffer) {
      *nextBuffer = tck.endToken;
    }
    return currentElement;
  }
  return json_Parser_Get_Invalid();
}
JsonElement json_Map_Get(JsonElement jsonMap, HttpString str) {
  if(jsonMap.type != JSON_JSON) {
    return json_Parser_Get_Invalid();
  }
  JsonElement *element = hsh_GetBuffer(((PJsonObject)jsonMap.value)->hsh, str.buffer, str.sz);
  if(!element) {
    return json_Parser_Get_Invalid();
  }
  return *element;
}
JsonElement json_Map_GetString(JsonElement jsonMap, const char *key) {
  return json_Map_Get(jsonMap, (HttpString) {
    .buffer = (char *)key,
    .sz = strlen(key)
  });
}
JsonElement json_Array_At(JsonElement arr, size_t index) {
  if(arr.type != JSON_ARRAY) {
    return json_Parser_Get_Invalid();
  }
  Array vct = arr.value;
  if(index >= vct->size) {
    return json_Parser_Get_Invalid();
  }
  return ((JsonElement *)vct->buffer)[index];
}
size_t json_Array_Size(JsonElement arr) {
  ((void) sizeof ((arr.type == JSON_ARRAY) ? 1 : 0), __extension__ ({ if (arr.type == JSON_ARRAY) ; else __assert_fail ("arr.type == JSON_ARRAY", "bin/svv.c", 3069, __extension__ __PRETTY_FUNCTION__); }));
  return ((Array)arr.value)->size;
}
int64_t json_Integer_Get(JsonElement arr) {
  ((void) sizeof ((arr.type == JSON_INTEGER) ? 1 : 0), __extension__ ({ if (arr.type == JSON_INTEGER) ; else __assert_fail ("arr.type == JSON_INTEGER", "bin/svv.c", 3074, __extension__ __PRETTY_FUNCTION__); }));
  return *((int64_t *)arr.value);
}
float json_Number_Get(JsonElement arr) {
  ((void) sizeof ((arr.type == JSON_NUMBER) ? 1 : 0), __extension__ ({ if (arr.type == JSON_NUMBER) ; else __assert_fail ("arr.type == JSON_NUMBER", "bin/svv.c", 3079, __extension__ __PRETTY_FUNCTION__); }));
  return *((float *)arr.value);
}
        
        
        
        
        
        
        
        
typedef int __gwchar_t;

typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));

typedef intmax_t ossl_intmax_t;
typedef uintmax_t ossl_uintmax_t;
        
        
typedef struct stack_st OPENSSL_STACK;
typedef int (*OPENSSL_sk_compfunc)(const void *, const void *);
typedef void (*OPENSSL_sk_freefunc)(void *);
typedef void *(*OPENSSL_sk_copyfunc)(const void *);
int OPENSSL_sk_num(const OPENSSL_STACK *);
void *OPENSSL_sk_value(const OPENSSL_STACK *, int);
void *OPENSSL_sk_set(OPENSSL_STACK *st, int i, const void *data);
OPENSSL_STACK *OPENSSL_sk_new(OPENSSL_sk_compfunc cmp);
OPENSSL_STACK *OPENSSL_sk_new_null(void);
OPENSSL_STACK *OPENSSL_sk_new_reserve(OPENSSL_sk_compfunc c, int n);
int OPENSSL_sk_reserve(OPENSSL_STACK *st, int n);
void OPENSSL_sk_free(OPENSSL_STACK *);
void OPENSSL_sk_pop_free(OPENSSL_STACK *st, void (*func) (void *));
OPENSSL_STACK *OPENSSL_sk_deep_copy(const OPENSSL_STACK *,
                                    OPENSSL_sk_copyfunc c,
                                    OPENSSL_sk_freefunc f);
int OPENSSL_sk_insert(OPENSSL_STACK *sk, const void *data, int where);
void *OPENSSL_sk_delete(OPENSSL_STACK *st, int loc);
void *OPENSSL_sk_delete_ptr(OPENSSL_STACK *st, const void *p);
int OPENSSL_sk_find(OPENSSL_STACK *st, const void *data);
int OPENSSL_sk_find_ex(OPENSSL_STACK *st, const void *data);
int OPENSSL_sk_find_all(OPENSSL_STACK *st, const void *data, int *pnum);
int OPENSSL_sk_push(OPENSSL_STACK *st, const void *data);
int OPENSSL_sk_unshift(OPENSSL_STACK *st, const void *data);
void *OPENSSL_sk_shift(OPENSSL_STACK *st);
void *OPENSSL_sk_pop(OPENSSL_STACK *st);
void OPENSSL_sk_zero(OPENSSL_STACK *st);
OPENSSL_sk_compfunc OPENSSL_sk_set_cmp_func(OPENSSL_STACK *sk,
                                            OPENSSL_sk_compfunc cmp);
OPENSSL_STACK *OPENSSL_sk_dup(const OPENSSL_STACK *st);
void OPENSSL_sk_sort(OPENSSL_STACK *st);
int OPENSSL_sk_is_sorted(const OPENSSL_STACK *st);
typedef char *OPENSSL_STRING;
typedef const char *OPENSSL_CSTRING;
struct stack_st_OPENSSL_STRING; typedef int (*sk_OPENSSL_STRING_compfunc)(const char * const *a, const char *const *b); typedef void (*sk_OPENSSL_STRING_freefunc)(char *a); typedef char * (*sk_OPENSSL_STRING_copyfunc)(const char *a); static __attribute__((unused)) inline char *ossl_check_OPENSSL_STRING_type(char *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_OPENSSL_STRING_sk_type(const struct stack_st_OPENSSL_STRING *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_OPENSSL_STRING_sk_type(struct stack_st_OPENSSL_STRING *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_OPENSSL_STRING_compfunc_type(sk_OPENSSL_STRING_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_OPENSSL_STRING_copyfunc_type(sk_OPENSSL_STRING_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_OPENSSL_STRING_freefunc_type(sk_OPENSSL_STRING_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
struct stack_st_OPENSSL_CSTRING; typedef int (*sk_OPENSSL_CSTRING_compfunc)(const char * const *a, const char *const *b); typedef void (*sk_OPENSSL_CSTRING_freefunc)(char *a); typedef char * (*sk_OPENSSL_CSTRING_copyfunc)(const char *a); static __attribute__((unused)) inline const char *ossl_check_OPENSSL_CSTRING_type(const char *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_OPENSSL_CSTRING_sk_type(const struct stack_st_OPENSSL_CSTRING *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_OPENSSL_CSTRING_sk_type(struct stack_st_OPENSSL_CSTRING *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_OPENSSL_CSTRING_compfunc_type(sk_OPENSSL_CSTRING_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_OPENSSL_CSTRING_copyfunc_type(sk_OPENSSL_CSTRING_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_OPENSSL_CSTRING_freefunc_type(sk_OPENSSL_CSTRING_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef void *OPENSSL_BLOCK;
struct stack_st_OPENSSL_BLOCK; typedef int (*sk_OPENSSL_BLOCK_compfunc)(const void * const *a, const void *const *b); typedef void (*sk_OPENSSL_BLOCK_freefunc)(void *a); typedef void * (*sk_OPENSSL_BLOCK_copyfunc)(const void *a); static __attribute__((unused)) inline void *ossl_check_OPENSSL_BLOCK_type(void *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_OPENSSL_BLOCK_sk_type(const struct stack_st_OPENSSL_BLOCK *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_OPENSSL_BLOCK_sk_type(struct stack_st_OPENSSL_BLOCK *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_OPENSSL_BLOCK_compfunc_type(sk_OPENSSL_BLOCK_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_OPENSSL_BLOCK_copyfunc_type(sk_OPENSSL_BLOCK_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_OPENSSL_BLOCK_freefunc_type(sk_OPENSSL_BLOCK_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef struct ossl_provider_st OSSL_PROVIDER;
typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_string_st ASN1_ENUMERATED;
typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_string_st ASN1_PRINTABLESTRING;
typedef struct asn1_string_st ASN1_T61STRING;
typedef struct asn1_string_st ASN1_IA5STRING;
typedef struct asn1_string_st ASN1_GENERALSTRING;
typedef struct asn1_string_st ASN1_UNIVERSALSTRING;
typedef struct asn1_string_st ASN1_BMPSTRING;
typedef struct asn1_string_st ASN1_UTCTIME;
typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_VISIBLESTRING;
typedef struct asn1_string_st ASN1_UTF8STRING;
typedef struct asn1_string_st ASN1_STRING;
typedef int ASN1_BOOLEAN;
typedef int ASN1_NULL;
typedef struct asn1_type_st ASN1_TYPE;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_string_table_st ASN1_STRING_TABLE;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct asn1_pctx_st ASN1_PCTX;
typedef struct asn1_sctx_st ASN1_SCTX;
typedef struct bio_st BIO;
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_blinding_st BN_BLINDING;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bn_recp_ctx_st BN_RECP_CTX;
typedef struct bn_gencb_st BN_GENCB;
typedef struct buf_mem_st BUF_MEM;
struct stack_st_BIGNUM;
struct stack_st_BIGNUM_const;
typedef struct err_state_st ERR_STATE;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct evp_md_st EVP_MD;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct evp_mac_st EVP_MAC;
typedef struct evp_mac_ctx_st EVP_MAC_CTX;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_pkey_asn1_method_st EVP_PKEY_ASN1_METHOD;
typedef struct evp_pkey_method_st EVP_PKEY_METHOD;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;
typedef struct evp_keymgmt_st EVP_KEYMGMT;
typedef struct evp_kdf_st EVP_KDF;
typedef struct evp_kdf_ctx_st EVP_KDF_CTX;
typedef struct evp_rand_st EVP_RAND;
typedef struct evp_rand_ctx_st EVP_RAND_CTX;
typedef struct evp_keyexch_st EVP_KEYEXCH;
typedef struct evp_signature_st EVP_SIGNATURE;
typedef struct evp_asym_cipher_st EVP_ASYM_CIPHER;
typedef struct evp_kem_st EVP_KEM;
typedef struct evp_Encode_Ctx_st EVP_ENCODE_CTX;
typedef struct hmac_ctx_st HMAC_CTX;
typedef struct dh_st DH;
typedef struct dh_method DH_METHOD;
typedef struct dsa_st DSA;
typedef struct dsa_method DSA_METHOD;
typedef struct rsa_st RSA;
typedef struct rsa_meth_st RSA_METHOD;
typedef struct rsa_pss_params_st RSA_PSS_PARAMS;
typedef struct ec_key_st EC_KEY;
typedef struct ec_key_method_st EC_KEY_METHOD;
typedef struct rand_meth_st RAND_METHOD;
typedef struct rand_drbg_st RAND_DRBG;
typedef struct ssl_dane_st SSL_DANE;
typedef struct x509_st X509;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_crl_st X509_CRL;
typedef struct x509_crl_method_st X509_CRL_METHOD;
typedef struct x509_revoked_st X509_REVOKED;
typedef struct X509_name_st X509_NAME;
typedef struct X509_pubkey_st X509_PUBKEY;
typedef struct x509_store_st X509_STORE;
typedef struct x509_store_ctx_st X509_STORE_CTX;
typedef struct x509_object_st X509_OBJECT;
typedef struct x509_lookup_st X509_LOOKUP;
typedef struct x509_lookup_method_st X509_LOOKUP_METHOD;
typedef struct X509_VERIFY_PARAM_st X509_VERIFY_PARAM;
typedef struct x509_sig_info_st X509_SIG_INFO;
typedef struct pkcs8_priv_key_info_st PKCS8_PRIV_KEY_INFO;
typedef struct v3_ext_ctx X509V3_CTX;
typedef struct conf_st CONF;
typedef struct ossl_init_settings_st OPENSSL_INIT_SETTINGS;
typedef struct ui_st UI;
typedef struct ui_method_st UI_METHOD;
typedef struct engine_st ENGINE;
typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct comp_ctx_st COMP_CTX;
typedef struct comp_method_st COMP_METHOD;
typedef struct X509_POLICY_NODE_st X509_POLICY_NODE;
typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct AUTHORITY_KEYID_st AUTHORITY_KEYID;
typedef struct DIST_POINT_st DIST_POINT;
typedef struct ISSUING_DIST_POINT_st ISSUING_DIST_POINT;
typedef struct NAME_CONSTRAINTS_st NAME_CONSTRAINTS;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef struct ossl_http_req_ctx_st OSSL_HTTP_REQ_CTX;
typedef struct ocsp_response_st OCSP_RESPONSE;
typedef struct ocsp_responder_id_st OCSP_RESPID;
typedef struct sct_st SCT;
typedef struct sct_ctx_st SCT_CTX;
typedef struct ctlog_st CTLOG;
typedef struct ctlog_store_st CTLOG_STORE;
typedef struct ct_policy_eval_ctx_st CT_POLICY_EVAL_CTX;
typedef struct ossl_store_info_st OSSL_STORE_INFO;
typedef struct ossl_store_search_st OSSL_STORE_SEARCH;
typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;
typedef struct ossl_dispatch_st OSSL_DISPATCH;
typedef struct ossl_item_st OSSL_ITEM;
typedef struct ossl_algorithm_st OSSL_ALGORITHM;
typedef struct ossl_param_st OSSL_PARAM;
typedef struct ossl_param_bld_st OSSL_PARAM_BLD;
typedef int pem_password_cb (char *buf, int size, int rwflag, void *userdata);
typedef struct ossl_encoder_st OSSL_ENCODER;
typedef struct ossl_encoder_ctx_st OSSL_ENCODER_CTX;
typedef struct ossl_decoder_st OSSL_DECODER;
typedef struct ossl_decoder_ctx_st OSSL_DECODER_CTX;
typedef struct ossl_self_test_st OSSL_SELF_TEST;
        
typedef struct ossl_core_handle_st OSSL_CORE_HANDLE;
typedef struct openssl_core_ctx_st OPENSSL_CORE_CTX;
typedef struct ossl_core_bio_st OSSL_CORE_BIO;
struct ossl_dispatch_st {
    int function_id;
    void (*function)(void);
};
struct ossl_item_st {
    unsigned int id;
    void *ptr;
};
struct ossl_algorithm_st {
    const char *algorithm_names;
    const char *property_definition;
    const OSSL_DISPATCH *implementation;
    const char *algorithm_description;
};
struct ossl_param_st {
    const char *key;
    unsigned int data_type;
    void *data;
    size_t data_size;
    size_t return_size;
};
typedef void (*OSSL_thread_stop_handler_fn)(void *arg);
typedef int (OSSL_provider_init_fn)(const OSSL_CORE_HANDLE *handle,
                                    const OSSL_DISPATCH *in,
                                    const OSSL_DISPATCH **out,
                                    void **provctx);
extern OSSL_provider_init_fn OSSL_provider_init;
typedef int (OSSL_CALLBACK)(const OSSL_PARAM params[], void *arg);
typedef int (OSSL_INOUT_CALLBACK)(const OSSL_PARAM in_params[],
                                  OSSL_PARAM out_params[], void *arg);
typedef int (OSSL_PASSPHRASE_CALLBACK)(char *pass, size_t pass_size,
                                       size_t *pass_len,
                                       const OSSL_PARAM params[], void *arg);
        
typedef const OSSL_PARAM * (OSSL_FUNC_core_gettable_params_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_gettable_params_fn *OSSL_FUNC_core_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_gettable_params_fn *)opf->function; }
typedef int (OSSL_FUNC_core_get_params_fn)(const OSSL_CORE_HANDLE *prov, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_core_get_params_fn *OSSL_FUNC_core_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_core_thread_start_fn)(const OSSL_CORE_HANDLE *prov, OSSL_thread_stop_handler_fn handfn, void *arg); static __attribute__((unused)) inline OSSL_FUNC_core_thread_start_fn *OSSL_FUNC_core_thread_start(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_thread_start_fn *)opf->function; }
typedef OPENSSL_CORE_CTX * (OSSL_FUNC_core_get_libctx_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_get_libctx_fn *OSSL_FUNC_core_get_libctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_get_libctx_fn *)opf->function; }
typedef void (OSSL_FUNC_core_new_error_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_new_error_fn *OSSL_FUNC_core_new_error(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_new_error_fn *)opf->function; }
typedef void (OSSL_FUNC_core_set_error_debug_fn)(const OSSL_CORE_HANDLE *prov, const char *file, int line, const char *func); static __attribute__((unused)) inline OSSL_FUNC_core_set_error_debug_fn *OSSL_FUNC_core_set_error_debug(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_set_error_debug_fn *)opf->function; }
typedef void (OSSL_FUNC_core_vset_error_fn)(const OSSL_CORE_HANDLE *prov, uint32_t reason, const char *fmt, va_list args); static __attribute__((unused)) inline OSSL_FUNC_core_vset_error_fn *OSSL_FUNC_core_vset_error(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_vset_error_fn *)opf->function; }
typedef int (OSSL_FUNC_core_set_error_mark_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_set_error_mark_fn *OSSL_FUNC_core_set_error_mark(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_set_error_mark_fn *)opf->function; }
typedef int (OSSL_FUNC_core_clear_last_error_mark_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_clear_last_error_mark_fn *OSSL_FUNC_core_clear_last_error_mark(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_clear_last_error_mark_fn *)opf->function; }
typedef int (OSSL_FUNC_core_pop_error_to_mark_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_core_pop_error_to_mark_fn *OSSL_FUNC_core_pop_error_to_mark(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_pop_error_to_mark_fn *)opf->function; }
typedef int (OSSL_FUNC_core_obj_add_sigid_fn)(const OSSL_CORE_HANDLE *prov, const char *sign_name, const char *digest_name, const char *pkey_name); static __attribute__((unused)) inline OSSL_FUNC_core_obj_add_sigid_fn *OSSL_FUNC_core_obj_add_sigid(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_obj_add_sigid_fn *)opf->function; }
typedef int (OSSL_FUNC_core_obj_create_fn)(const OSSL_CORE_HANDLE *prov, const char *oid, const char *sn, const char *ln); static __attribute__((unused)) inline OSSL_FUNC_core_obj_create_fn *OSSL_FUNC_core_obj_create(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_core_obj_create_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_malloc_fn)(size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_malloc_fn *OSSL_FUNC_CRYPTO_malloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_malloc_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_zalloc_fn)(size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_zalloc_fn *OSSL_FUNC_CRYPTO_zalloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_zalloc_fn *)opf->function; }
typedef void (OSSL_FUNC_CRYPTO_free_fn)(void *ptr, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_free_fn *OSSL_FUNC_CRYPTO_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_free_fn *)opf->function; }
typedef void (OSSL_FUNC_CRYPTO_clear_free_fn)(void *ptr, size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_clear_free_fn *OSSL_FUNC_CRYPTO_clear_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_clear_free_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_realloc_fn)(void *addr, size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_realloc_fn *OSSL_FUNC_CRYPTO_realloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_realloc_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_clear_realloc_fn)(void *addr, size_t old_num, size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_clear_realloc_fn *OSSL_FUNC_CRYPTO_clear_realloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_clear_realloc_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_secure_malloc_fn)(size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_secure_malloc_fn *OSSL_FUNC_CRYPTO_secure_malloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_secure_malloc_fn *)opf->function; }
typedef void * (OSSL_FUNC_CRYPTO_secure_zalloc_fn)(size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_secure_zalloc_fn *OSSL_FUNC_CRYPTO_secure_zalloc(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_secure_zalloc_fn *)opf->function; }
typedef void (OSSL_FUNC_CRYPTO_secure_free_fn)(void *ptr, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_secure_free_fn *OSSL_FUNC_CRYPTO_secure_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_secure_free_fn *)opf->function; }
typedef void (OSSL_FUNC_CRYPTO_secure_clear_free_fn)(void *ptr, size_t num, const char *file, int line); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_secure_clear_free_fn *OSSL_FUNC_CRYPTO_secure_clear_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_secure_clear_free_fn *)opf->function; }
typedef int (OSSL_FUNC_CRYPTO_secure_allocated_fn)(const void *ptr); static __attribute__((unused)) inline OSSL_FUNC_CRYPTO_secure_allocated_fn *OSSL_FUNC_CRYPTO_secure_allocated(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_CRYPTO_secure_allocated_fn *)opf->function; }
typedef void (OSSL_FUNC_OPENSSL_cleanse_fn)(void *ptr, size_t len); static __attribute__((unused)) inline OSSL_FUNC_OPENSSL_cleanse_fn *OSSL_FUNC_OPENSSL_cleanse(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_OPENSSL_cleanse_fn *)opf->function; }
typedef OSSL_CORE_BIO * (OSSL_FUNC_BIO_new_file_fn)(const char *filename, const char *mode); static __attribute__((unused)) inline OSSL_FUNC_BIO_new_file_fn *OSSL_FUNC_BIO_new_file(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_new_file_fn *)opf->function; }
typedef OSSL_CORE_BIO * (OSSL_FUNC_BIO_new_membuf_fn)(const void *buf, int len); static __attribute__((unused)) inline OSSL_FUNC_BIO_new_membuf_fn *OSSL_FUNC_BIO_new_membuf(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_new_membuf_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_read_ex_fn)(OSSL_CORE_BIO *bio, void *data, size_t data_len, size_t *bytes_read); static __attribute__((unused)) inline OSSL_FUNC_BIO_read_ex_fn *OSSL_FUNC_BIO_read_ex(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_read_ex_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_write_ex_fn)(OSSL_CORE_BIO *bio, const void *data, size_t data_len, size_t *written); static __attribute__((unused)) inline OSSL_FUNC_BIO_write_ex_fn *OSSL_FUNC_BIO_write_ex(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_write_ex_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_gets_fn)(OSSL_CORE_BIO *bio, char *buf, int size); static __attribute__((unused)) inline OSSL_FUNC_BIO_gets_fn *OSSL_FUNC_BIO_gets(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_gets_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_puts_fn)(OSSL_CORE_BIO *bio, const char *str); static __attribute__((unused)) inline OSSL_FUNC_BIO_puts_fn *OSSL_FUNC_BIO_puts(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_puts_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_up_ref_fn)(OSSL_CORE_BIO *bio); static __attribute__((unused)) inline OSSL_FUNC_BIO_up_ref_fn *OSSL_FUNC_BIO_up_ref(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_up_ref_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_free_fn)(OSSL_CORE_BIO *bio); static __attribute__((unused)) inline OSSL_FUNC_BIO_free_fn *OSSL_FUNC_BIO_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_free_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_vprintf_fn)(OSSL_CORE_BIO *bio, const char *format, va_list args); static __attribute__((unused)) inline OSSL_FUNC_BIO_vprintf_fn *OSSL_FUNC_BIO_vprintf(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_vprintf_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_vsnprintf_fn)(char *buf, size_t n, const char *fmt, va_list args); static __attribute__((unused)) inline OSSL_FUNC_BIO_vsnprintf_fn *OSSL_FUNC_BIO_vsnprintf(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_vsnprintf_fn *)opf->function; }
typedef int (OSSL_FUNC_BIO_ctrl_fn)(OSSL_CORE_BIO *bio, int cmd, long num, void *ptr); static __attribute__((unused)) inline OSSL_FUNC_BIO_ctrl_fn *OSSL_FUNC_BIO_ctrl(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_BIO_ctrl_fn *)opf->function; }
typedef void (OSSL_FUNC_self_test_cb_fn)(OPENSSL_CORE_CTX *ctx, OSSL_CALLBACK **cb, void **cbarg); static __attribute__((unused)) inline OSSL_FUNC_self_test_cb_fn *OSSL_FUNC_self_test_cb(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_self_test_cb_fn *)opf->function; }
typedef size_t (OSSL_FUNC_get_entropy_fn)(const OSSL_CORE_HANDLE *handle, unsigned char **pout, int entropy, size_t min_len, size_t max_len); static __attribute__((unused)) inline OSSL_FUNC_get_entropy_fn *OSSL_FUNC_get_entropy(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_get_entropy_fn *)opf->function; }
typedef void (OSSL_FUNC_cleanup_entropy_fn)(const OSSL_CORE_HANDLE *handle, unsigned char *buf, size_t len); static __attribute__((unused)) inline OSSL_FUNC_cleanup_entropy_fn *OSSL_FUNC_cleanup_entropy(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cleanup_entropy_fn *)opf->function; }
typedef size_t (OSSL_FUNC_get_nonce_fn)(const OSSL_CORE_HANDLE *handle, unsigned char **pout, size_t min_len, size_t max_len, const void *salt, size_t salt_len); static __attribute__((unused)) inline OSSL_FUNC_get_nonce_fn *OSSL_FUNC_get_nonce(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_get_nonce_fn *)opf->function; }
typedef void (OSSL_FUNC_cleanup_nonce_fn)(const OSSL_CORE_HANDLE *handle, unsigned char *buf, size_t len); static __attribute__((unused)) inline OSSL_FUNC_cleanup_nonce_fn *OSSL_FUNC_cleanup_nonce(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cleanup_nonce_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_register_child_cb_fn)(const OSSL_CORE_HANDLE *handle, int (*create_cb)(const OSSL_CORE_HANDLE *provider, void *cbdata), int (*remove_cb)(const OSSL_CORE_HANDLE *provider, void *cbdata), int (*global_props_cb)(const char *props, void *cbdata), void *cbdata); static __attribute__((unused)) inline OSSL_FUNC_provider_register_child_cb_fn *OSSL_FUNC_provider_register_child_cb(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_register_child_cb_fn *)opf->function; }
typedef void (OSSL_FUNC_provider_deregister_child_cb_fn)(const OSSL_CORE_HANDLE *handle); static __attribute__((unused)) inline OSSL_FUNC_provider_deregister_child_cb_fn *OSSL_FUNC_provider_deregister_child_cb(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_deregister_child_cb_fn *)opf->function; }
typedef const char * (OSSL_FUNC_provider_name_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_provider_name_fn *OSSL_FUNC_provider_name(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_name_fn *)opf->function; }
typedef void * (OSSL_FUNC_provider_get0_provider_ctx_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_provider_get0_provider_ctx_fn *OSSL_FUNC_provider_get0_provider_ctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_get0_provider_ctx_fn *)opf->function; }
typedef const OSSL_DISPATCH * (OSSL_FUNC_provider_get0_dispatch_fn)(const OSSL_CORE_HANDLE *prov); static __attribute__((unused)) inline OSSL_FUNC_provider_get0_dispatch_fn *OSSL_FUNC_provider_get0_dispatch(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_get0_dispatch_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_up_ref_fn)(const OSSL_CORE_HANDLE *prov, int activate); static __attribute__((unused)) inline OSSL_FUNC_provider_up_ref_fn *OSSL_FUNC_provider_up_ref(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_up_ref_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_free_fn)(const OSSL_CORE_HANDLE *prov, int deactivate); static __attribute__((unused)) inline OSSL_FUNC_provider_free_fn *OSSL_FUNC_provider_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_free_fn *)opf->function; }
typedef void (OSSL_FUNC_provider_teardown_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_provider_teardown_fn *OSSL_FUNC_provider_teardown(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_teardown_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_provider_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_provider_gettable_params_fn *OSSL_FUNC_provider_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_gettable_params_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_get_params_fn)(void *provctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_provider_get_params_fn *OSSL_FUNC_provider_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_get_params_fn *)opf->function; }
typedef const OSSL_ALGORITHM * (OSSL_FUNC_provider_query_operation_fn)(void *provctx, int operation_id, int *no_store); static __attribute__((unused)) inline OSSL_FUNC_provider_query_operation_fn *OSSL_FUNC_provider_query_operation(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_query_operation_fn *)opf->function; }
typedef void (OSSL_FUNC_provider_unquery_operation_fn)(void *provctx, int operation_id, const OSSL_ALGORITHM *); static __attribute__((unused)) inline OSSL_FUNC_provider_unquery_operation_fn *OSSL_FUNC_provider_unquery_operation(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_unquery_operation_fn *)opf->function; }
typedef const OSSL_ITEM * (OSSL_FUNC_provider_get_reason_strings_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_provider_get_reason_strings_fn *OSSL_FUNC_provider_get_reason_strings(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_get_reason_strings_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_get_capabilities_fn)(void *provctx, const char *capability, OSSL_CALLBACK *cb, void *arg); static __attribute__((unused)) inline OSSL_FUNC_provider_get_capabilities_fn *OSSL_FUNC_provider_get_capabilities(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_get_capabilities_fn *)opf->function; }
typedef int (OSSL_FUNC_provider_self_test_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_provider_self_test_fn *OSSL_FUNC_provider_self_test(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_provider_self_test_fn *)opf->function; }
typedef void * (OSSL_FUNC_digest_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_digest_newctx_fn *OSSL_FUNC_digest_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_init_fn)(void *dctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_digest_init_fn *OSSL_FUNC_digest_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_init_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_update_fn)(void *dctx, const unsigned char *in, size_t inl); static __attribute__((unused)) inline OSSL_FUNC_digest_update_fn *OSSL_FUNC_digest_update(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_update_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_final_fn)(void *dctx, unsigned char *out, size_t *outl, size_t outsz); static __attribute__((unused)) inline OSSL_FUNC_digest_final_fn *OSSL_FUNC_digest_final(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_final_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_digest_fn)(void *provctx, const unsigned char *in, size_t inl, unsigned char *out, size_t *outl, size_t outsz); static __attribute__((unused)) inline OSSL_FUNC_digest_digest_fn *OSSL_FUNC_digest_digest(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_digest_fn *)opf->function; }
typedef void (OSSL_FUNC_digest_freectx_fn)(void *dctx); static __attribute__((unused)) inline OSSL_FUNC_digest_freectx_fn *OSSL_FUNC_digest_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_digest_dupctx_fn)(void *dctx); static __attribute__((unused)) inline OSSL_FUNC_digest_dupctx_fn *OSSL_FUNC_digest_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_digest_get_params_fn *OSSL_FUNC_digest_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_set_ctx_params_fn)(void *vctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_digest_set_ctx_params_fn *OSSL_FUNC_digest_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_set_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_digest_get_ctx_params_fn)(void *vctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_digest_get_ctx_params_fn *OSSL_FUNC_digest_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_get_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_digest_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_digest_gettable_params_fn *OSSL_FUNC_digest_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_gettable_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_digest_settable_ctx_params_fn)(void *dctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_digest_settable_ctx_params_fn *OSSL_FUNC_digest_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_settable_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_digest_gettable_ctx_params_fn)(void *dctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_digest_gettable_ctx_params_fn *OSSL_FUNC_digest_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_digest_gettable_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_cipher_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_newctx_fn *OSSL_FUNC_cipher_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_encrypt_init_fn)(void *cctx, const unsigned char *key, size_t keylen, const unsigned char *iv, size_t ivlen, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_cipher_encrypt_init_fn *OSSL_FUNC_cipher_encrypt_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_encrypt_init_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_decrypt_init_fn)(void *cctx, const unsigned char *key, size_t keylen, const unsigned char *iv, size_t ivlen, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_cipher_decrypt_init_fn *OSSL_FUNC_cipher_decrypt_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_decrypt_init_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_update_fn)(void *cctx, unsigned char *out, size_t *outl, size_t outsize, const unsigned char *in, size_t inl); static __attribute__((unused)) inline OSSL_FUNC_cipher_update_fn *OSSL_FUNC_cipher_update(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_update_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_final_fn)(void *cctx, unsigned char *out, size_t *outl, size_t outsize); static __attribute__((unused)) inline OSSL_FUNC_cipher_final_fn *OSSL_FUNC_cipher_final(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_final_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_cipher_fn)(void *cctx, unsigned char *out, size_t *outl, size_t outsize, const unsigned char *in, size_t inl); static __attribute__((unused)) inline OSSL_FUNC_cipher_cipher_fn *OSSL_FUNC_cipher_cipher(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_cipher_fn *)opf->function; }
typedef void (OSSL_FUNC_cipher_freectx_fn)(void *cctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_freectx_fn *OSSL_FUNC_cipher_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_cipher_dupctx_fn)(void *cctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_dupctx_fn *OSSL_FUNC_cipher_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_cipher_get_params_fn *OSSL_FUNC_cipher_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_get_ctx_params_fn)(void *cctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_cipher_get_ctx_params_fn *OSSL_FUNC_cipher_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_get_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_cipher_set_ctx_params_fn)(void *cctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_cipher_set_ctx_params_fn *OSSL_FUNC_cipher_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_cipher_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_gettable_params_fn *OSSL_FUNC_cipher_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_gettable_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_cipher_settable_ctx_params_fn)(void *cctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_settable_ctx_params_fn *OSSL_FUNC_cipher_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_settable_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_cipher_gettable_ctx_params_fn)(void *cctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_cipher_gettable_ctx_params_fn *OSSL_FUNC_cipher_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_cipher_gettable_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_mac_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_mac_newctx_fn *OSSL_FUNC_mac_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_newctx_fn *)opf->function; }
typedef void * (OSSL_FUNC_mac_dupctx_fn)(void *src); static __attribute__((unused)) inline OSSL_FUNC_mac_dupctx_fn *OSSL_FUNC_mac_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_dupctx_fn *)opf->function; }
typedef void (OSSL_FUNC_mac_freectx_fn)(void *mctx); static __attribute__((unused)) inline OSSL_FUNC_mac_freectx_fn *OSSL_FUNC_mac_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_freectx_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_init_fn)(void *mctx, const unsigned char *key, size_t keylen, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_mac_init_fn *OSSL_FUNC_mac_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_init_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_update_fn)(void *mctx, const unsigned char *in, size_t inl); static __attribute__((unused)) inline OSSL_FUNC_mac_update_fn *OSSL_FUNC_mac_update(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_update_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_final_fn)(void *mctx, unsigned char *out, size_t *outl, size_t outsize); static __attribute__((unused)) inline OSSL_FUNC_mac_final_fn *OSSL_FUNC_mac_final(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_final_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_mac_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_mac_gettable_params_fn *OSSL_FUNC_mac_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_gettable_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_mac_gettable_ctx_params_fn)(void *mctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_mac_gettable_ctx_params_fn *OSSL_FUNC_mac_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_gettable_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_mac_settable_ctx_params_fn)(void *mctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_mac_settable_ctx_params_fn *OSSL_FUNC_mac_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_mac_get_params_fn *OSSL_FUNC_mac_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_get_ctx_params_fn)(void *mctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_mac_get_ctx_params_fn *OSSL_FUNC_mac_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_get_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_mac_set_ctx_params_fn)(void *mctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_mac_set_ctx_params_fn *OSSL_FUNC_mac_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_mac_set_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_kdf_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_newctx_fn *OSSL_FUNC_kdf_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_newctx_fn *)opf->function; }
typedef void * (OSSL_FUNC_kdf_dupctx_fn)(void *src); static __attribute__((unused)) inline OSSL_FUNC_kdf_dupctx_fn *OSSL_FUNC_kdf_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_dupctx_fn *)opf->function; }
typedef void (OSSL_FUNC_kdf_freectx_fn)(void *kctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_freectx_fn *OSSL_FUNC_kdf_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_freectx_fn *)opf->function; }
typedef void (OSSL_FUNC_kdf_reset_fn)(void *kctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_reset_fn *OSSL_FUNC_kdf_reset(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_reset_fn *)opf->function; }
typedef int (OSSL_FUNC_kdf_derive_fn)(void *kctx, unsigned char *key, size_t keylen, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kdf_derive_fn *OSSL_FUNC_kdf_derive(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_derive_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_kdf_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_gettable_params_fn *OSSL_FUNC_kdf_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_gettable_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_kdf_gettable_ctx_params_fn)(void *kctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_gettable_ctx_params_fn *OSSL_FUNC_kdf_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_gettable_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_kdf_settable_ctx_params_fn)(void *kctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kdf_settable_ctx_params_fn *OSSL_FUNC_kdf_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_kdf_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kdf_get_params_fn *OSSL_FUNC_kdf_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_kdf_get_ctx_params_fn)(void *kctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kdf_get_ctx_params_fn *OSSL_FUNC_kdf_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_get_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_kdf_set_ctx_params_fn)(void *kctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kdf_set_ctx_params_fn *OSSL_FUNC_kdf_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kdf_set_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_rand_newctx_fn)(void *provctx, void *parent, const OSSL_DISPATCH *parent_calls); static __attribute__((unused)) inline OSSL_FUNC_rand_newctx_fn *OSSL_FUNC_rand_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_newctx_fn *)opf->function; }
typedef void (OSSL_FUNC_rand_freectx_fn)(void *vctx); static __attribute__((unused)) inline OSSL_FUNC_rand_freectx_fn *OSSL_FUNC_rand_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_freectx_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_instantiate_fn)(void *vdrbg, unsigned int strength, int prediction_resistance, const unsigned char *pstr, size_t pstr_len, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_rand_instantiate_fn *OSSL_FUNC_rand_instantiate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_instantiate_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_uninstantiate_fn)(void *vdrbg); static __attribute__((unused)) inline OSSL_FUNC_rand_uninstantiate_fn *OSSL_FUNC_rand_uninstantiate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_uninstantiate_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_generate_fn)(void *vctx, unsigned char *out, size_t outlen, unsigned int strength, int prediction_resistance, const unsigned char *addin, size_t addin_len); static __attribute__((unused)) inline OSSL_FUNC_rand_generate_fn *OSSL_FUNC_rand_generate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_generate_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_reseed_fn)(void *vctx, int prediction_resistance, const unsigned char *ent, size_t ent_len, const unsigned char *addin, size_t addin_len); static __attribute__((unused)) inline OSSL_FUNC_rand_reseed_fn *OSSL_FUNC_rand_reseed(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_reseed_fn *)opf->function; }
typedef size_t (OSSL_FUNC_rand_nonce_fn)(void *vctx, unsigned char *out, unsigned int strength, size_t min_noncelen, size_t max_noncelen); static __attribute__((unused)) inline OSSL_FUNC_rand_nonce_fn *OSSL_FUNC_rand_nonce(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_nonce_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_enable_locking_fn)(void *vctx); static __attribute__((unused)) inline OSSL_FUNC_rand_enable_locking_fn *OSSL_FUNC_rand_enable_locking(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_enable_locking_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_lock_fn)(void *vctx); static __attribute__((unused)) inline OSSL_FUNC_rand_lock_fn *OSSL_FUNC_rand_lock(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_lock_fn *)opf->function; }
typedef void (OSSL_FUNC_rand_unlock_fn)(void *vctx); static __attribute__((unused)) inline OSSL_FUNC_rand_unlock_fn *OSSL_FUNC_rand_unlock(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_unlock_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_rand_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_rand_gettable_params_fn *OSSL_FUNC_rand_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_gettable_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_rand_gettable_ctx_params_fn)(void *vctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_rand_gettable_ctx_params_fn *OSSL_FUNC_rand_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_gettable_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_rand_settable_ctx_params_fn)(void *vctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_rand_settable_ctx_params_fn *OSSL_FUNC_rand_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_rand_get_params_fn *OSSL_FUNC_rand_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_get_params_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_get_ctx_params_fn)(void *vctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_rand_get_ctx_params_fn *OSSL_FUNC_rand_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_get_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_set_ctx_params_fn)(void *vctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_rand_set_ctx_params_fn *OSSL_FUNC_rand_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_set_ctx_params_fn *)opf->function; }
typedef void (OSSL_FUNC_rand_set_callbacks_fn)(void *vctx, OSSL_INOUT_CALLBACK *get_entropy, OSSL_CALLBACK *cleanup_entropy, OSSL_INOUT_CALLBACK *get_nonce, OSSL_CALLBACK *cleanup_nonce, void *arg); static __attribute__((unused)) inline OSSL_FUNC_rand_set_callbacks_fn *OSSL_FUNC_rand_set_callbacks(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_set_callbacks_fn *)opf->function; }
typedef int (OSSL_FUNC_rand_verify_zeroization_fn)(void *vctx); static __attribute__((unused)) inline OSSL_FUNC_rand_verify_zeroization_fn *OSSL_FUNC_rand_verify_zeroization(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_verify_zeroization_fn *)opf->function; }
typedef size_t (OSSL_FUNC_rand_get_seed_fn)(void *vctx, unsigned char **buffer, int entropy, size_t min_len, size_t max_len, int prediction_resistance, const unsigned char *adin, size_t adin_len); static __attribute__((unused)) inline OSSL_FUNC_rand_get_seed_fn *OSSL_FUNC_rand_get_seed(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_get_seed_fn *)opf->function; }
typedef void (OSSL_FUNC_rand_clear_seed_fn)(void *vctx, unsigned char *buffer, size_t b_len); static __attribute__((unused)) inline OSSL_FUNC_rand_clear_seed_fn *OSSL_FUNC_rand_clear_seed(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_rand_clear_seed_fn *)opf->function; }
typedef void * (OSSL_FUNC_keymgmt_new_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_new_fn *OSSL_FUNC_keymgmt_new(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_new_fn *)opf->function; }
typedef void * (OSSL_FUNC_keymgmt_gen_init_fn)(void *provctx, int selection, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_init_fn *OSSL_FUNC_keymgmt_gen_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_init_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_gen_set_template_fn)(void *genctx, void *templ); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_set_template_fn *OSSL_FUNC_keymgmt_gen_set_template(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_set_template_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_gen_set_params_fn)(void *genctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_set_params_fn *OSSL_FUNC_keymgmt_gen_set_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_set_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keymgmt_gen_settable_params_fn)(void *genctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_settable_params_fn *OSSL_FUNC_keymgmt_gen_settable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_settable_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_keymgmt_gen_fn)(void *genctx, OSSL_CALLBACK *cb, void *cbarg); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_fn *OSSL_FUNC_keymgmt_gen(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_fn *)opf->function; }
typedef void (OSSL_FUNC_keymgmt_gen_cleanup_fn)(void *genctx); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gen_cleanup_fn *OSSL_FUNC_keymgmt_gen_cleanup(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gen_cleanup_fn *)opf->function; }
typedef void * (OSSL_FUNC_keymgmt_load_fn)(const void *reference, size_t reference_sz); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_load_fn *OSSL_FUNC_keymgmt_load(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_load_fn *)opf->function; }
typedef void (OSSL_FUNC_keymgmt_free_fn)(void *keydata); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_free_fn *OSSL_FUNC_keymgmt_free(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_free_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_get_params_fn)(void *keydata, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_get_params_fn *OSSL_FUNC_keymgmt_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_get_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keymgmt_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_gettable_params_fn *OSSL_FUNC_keymgmt_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_gettable_params_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_set_params_fn)(void *keydata, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_set_params_fn *OSSL_FUNC_keymgmt_set_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_set_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keymgmt_settable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_settable_params_fn *OSSL_FUNC_keymgmt_settable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_settable_params_fn *)opf->function; }
typedef const char * (OSSL_FUNC_keymgmt_query_operation_name_fn)(int operation_id); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_query_operation_name_fn *OSSL_FUNC_keymgmt_query_operation_name(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_query_operation_name_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_has_fn)(const void *keydata, int selection); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_has_fn *OSSL_FUNC_keymgmt_has(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_has_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_validate_fn)(const void *keydata, int selection, int checktype); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_validate_fn *OSSL_FUNC_keymgmt_validate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_validate_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_match_fn)(const void *keydata1, const void *keydata2, int selection); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_match_fn *OSSL_FUNC_keymgmt_match(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_match_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_import_fn)(void *keydata, int selection, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_import_fn *OSSL_FUNC_keymgmt_import(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_import_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keymgmt_import_types_fn)(int selection); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_import_types_fn *OSSL_FUNC_keymgmt_import_types(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_import_types_fn *)opf->function; }
typedef int (OSSL_FUNC_keymgmt_export_fn)(void *keydata, int selection, OSSL_CALLBACK *param_cb, void *cbarg); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_export_fn *OSSL_FUNC_keymgmt_export(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_export_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keymgmt_export_types_fn)(int selection); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_export_types_fn *OSSL_FUNC_keymgmt_export_types(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_export_types_fn *)opf->function; }
typedef void * (OSSL_FUNC_keymgmt_dup_fn)(const void *keydata_from, int selection); static __attribute__((unused)) inline OSSL_FUNC_keymgmt_dup_fn *OSSL_FUNC_keymgmt_dup(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keymgmt_dup_fn *)opf->function; }
typedef void * (OSSL_FUNC_keyexch_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keyexch_newctx_fn *OSSL_FUNC_keyexch_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_keyexch_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keyexch_init_fn *OSSL_FUNC_keyexch_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_init_fn *)opf->function; }
typedef int (OSSL_FUNC_keyexch_derive_fn)(void *ctx, unsigned char *secret, size_t *secretlen, size_t outlen); static __attribute__((unused)) inline OSSL_FUNC_keyexch_derive_fn *OSSL_FUNC_keyexch_derive(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_derive_fn *)opf->function; }
typedef int (OSSL_FUNC_keyexch_set_peer_fn)(void *ctx, void *provkey); static __attribute__((unused)) inline OSSL_FUNC_keyexch_set_peer_fn *OSSL_FUNC_keyexch_set_peer(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_set_peer_fn *)opf->function; }
typedef void (OSSL_FUNC_keyexch_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_keyexch_freectx_fn *OSSL_FUNC_keyexch_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_keyexch_dupctx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_keyexch_dupctx_fn *OSSL_FUNC_keyexch_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_keyexch_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keyexch_set_ctx_params_fn *OSSL_FUNC_keyexch_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keyexch_settable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keyexch_settable_ctx_params_fn *OSSL_FUNC_keyexch_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_keyexch_get_ctx_params_fn)(void *ctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_keyexch_get_ctx_params_fn *OSSL_FUNC_keyexch_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_get_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_keyexch_gettable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_keyexch_gettable_ctx_params_fn *OSSL_FUNC_keyexch_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_keyexch_gettable_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_signature_newctx_fn)(void *provctx, const char *propq); static __attribute__((unused)) inline OSSL_FUNC_signature_newctx_fn *OSSL_FUNC_signature_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_sign_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_sign_init_fn *OSSL_FUNC_signature_sign_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_sign_init_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_sign_fn)(void *ctx, unsigned char *sig, size_t *siglen, size_t sigsize, const unsigned char *tbs, size_t tbslen); static __attribute__((unused)) inline OSSL_FUNC_signature_sign_fn *OSSL_FUNC_signature_sign(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_sign_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_verify_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_verify_init_fn *OSSL_FUNC_signature_verify_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_verify_init_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_verify_fn)(void *ctx, const unsigned char *sig, size_t siglen, const unsigned char *tbs, size_t tbslen); static __attribute__((unused)) inline OSSL_FUNC_signature_verify_fn *OSSL_FUNC_signature_verify(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_verify_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_verify_recover_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_verify_recover_init_fn *OSSL_FUNC_signature_verify_recover_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_verify_recover_init_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_verify_recover_fn)(void *ctx, unsigned char *rout, size_t *routlen, size_t routsize, const unsigned char *sig, size_t siglen); static __attribute__((unused)) inline OSSL_FUNC_signature_verify_recover_fn *OSSL_FUNC_signature_verify_recover(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_verify_recover_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_sign_init_fn)(void *ctx, const char *mdname, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_sign_init_fn *OSSL_FUNC_signature_digest_sign_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_sign_init_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_sign_update_fn)(void *ctx, const unsigned char *data, size_t datalen); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_sign_update_fn *OSSL_FUNC_signature_digest_sign_update(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_sign_update_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_sign_final_fn)(void *ctx, unsigned char *sig, size_t *siglen, size_t sigsize); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_sign_final_fn *OSSL_FUNC_signature_digest_sign_final(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_sign_final_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_sign_fn)(void *ctx, unsigned char *sigret, size_t *siglen, size_t sigsize, const unsigned char *tbs, size_t tbslen); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_sign_fn *OSSL_FUNC_signature_digest_sign(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_sign_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_verify_init_fn)(void *ctx, const char *mdname, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_verify_init_fn *OSSL_FUNC_signature_digest_verify_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_verify_init_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_verify_update_fn)(void *ctx, const unsigned char *data, size_t datalen); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_verify_update_fn *OSSL_FUNC_signature_digest_verify_update(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_verify_update_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_verify_final_fn)(void *ctx, const unsigned char *sig, size_t siglen); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_verify_final_fn *OSSL_FUNC_signature_digest_verify_final(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_verify_final_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_digest_verify_fn)(void *ctx, const unsigned char *sig, size_t siglen, const unsigned char *tbs, size_t tbslen); static __attribute__((unused)) inline OSSL_FUNC_signature_digest_verify_fn *OSSL_FUNC_signature_digest_verify(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_digest_verify_fn *)opf->function; }
typedef void (OSSL_FUNC_signature_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_signature_freectx_fn *OSSL_FUNC_signature_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_signature_dupctx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_signature_dupctx_fn *OSSL_FUNC_signature_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_get_ctx_params_fn)(void *ctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_get_ctx_params_fn *OSSL_FUNC_signature_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_get_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_signature_gettable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_signature_gettable_ctx_params_fn *OSSL_FUNC_signature_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_gettable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_set_ctx_params_fn *OSSL_FUNC_signature_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_signature_settable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_signature_settable_ctx_params_fn *OSSL_FUNC_signature_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_get_ctx_md_params_fn)(void *ctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_get_ctx_md_params_fn *OSSL_FUNC_signature_get_ctx_md_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_get_ctx_md_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_signature_gettable_ctx_md_params_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_signature_gettable_ctx_md_params_fn *OSSL_FUNC_signature_gettable_ctx_md_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_gettable_ctx_md_params_fn *)opf->function; }
typedef int (OSSL_FUNC_signature_set_ctx_md_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_signature_set_ctx_md_params_fn *OSSL_FUNC_signature_set_ctx_md_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_set_ctx_md_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_signature_settable_ctx_md_params_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_signature_settable_ctx_md_params_fn *OSSL_FUNC_signature_settable_ctx_md_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_signature_settable_ctx_md_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_asym_cipher_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_newctx_fn *OSSL_FUNC_asym_cipher_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_encrypt_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_encrypt_init_fn *OSSL_FUNC_asym_cipher_encrypt_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_encrypt_init_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_encrypt_fn)(void *ctx, unsigned char *out, size_t *outlen, size_t outsize, const unsigned char *in, size_t inlen); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_encrypt_fn *OSSL_FUNC_asym_cipher_encrypt(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_encrypt_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_decrypt_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_decrypt_init_fn *OSSL_FUNC_asym_cipher_decrypt_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_decrypt_init_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_decrypt_fn)(void *ctx, unsigned char *out, size_t *outlen, size_t outsize, const unsigned char *in, size_t inlen); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_decrypt_fn *OSSL_FUNC_asym_cipher_decrypt(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_decrypt_fn *)opf->function; }
typedef void (OSSL_FUNC_asym_cipher_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_freectx_fn *OSSL_FUNC_asym_cipher_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_asym_cipher_dupctx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_dupctx_fn *OSSL_FUNC_asym_cipher_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_get_ctx_params_fn)(void *ctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_get_ctx_params_fn *OSSL_FUNC_asym_cipher_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_get_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_asym_cipher_gettable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_gettable_ctx_params_fn *OSSL_FUNC_asym_cipher_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_gettable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_asym_cipher_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_set_ctx_params_fn *OSSL_FUNC_asym_cipher_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_asym_cipher_settable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_asym_cipher_settable_ctx_params_fn *OSSL_FUNC_asym_cipher_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_asym_cipher_settable_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_kem_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kem_newctx_fn *OSSL_FUNC_kem_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_newctx_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_encapsulate_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kem_encapsulate_init_fn *OSSL_FUNC_kem_encapsulate_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_encapsulate_init_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_encapsulate_fn)(void *ctx, unsigned char *out, size_t *outlen, unsigned char *secret, size_t *secretlen); static __attribute__((unused)) inline OSSL_FUNC_kem_encapsulate_fn *OSSL_FUNC_kem_encapsulate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_encapsulate_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_decapsulate_init_fn)(void *ctx, void *provkey, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kem_decapsulate_init_fn *OSSL_FUNC_kem_decapsulate_init(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_decapsulate_init_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_decapsulate_fn)(void *ctx, unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen); static __attribute__((unused)) inline OSSL_FUNC_kem_decapsulate_fn *OSSL_FUNC_kem_decapsulate(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_decapsulate_fn *)opf->function; }
typedef void (OSSL_FUNC_kem_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_kem_freectx_fn *OSSL_FUNC_kem_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_freectx_fn *)opf->function; }
typedef void * (OSSL_FUNC_kem_dupctx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_kem_dupctx_fn *OSSL_FUNC_kem_dupctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_dupctx_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_get_ctx_params_fn)(void *ctx, OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kem_get_ctx_params_fn *OSSL_FUNC_kem_get_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_get_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_kem_gettable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kem_gettable_ctx_params_fn *OSSL_FUNC_kem_gettable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_gettable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_kem_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_kem_set_ctx_params_fn *OSSL_FUNC_kem_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_kem_settable_ctx_params_fn)(void *ctx, void *provctx); static __attribute__((unused)) inline OSSL_FUNC_kem_settable_ctx_params_fn *OSSL_FUNC_kem_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_kem_settable_ctx_params_fn *)opf->function; }
typedef void * (OSSL_FUNC_encoder_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_encoder_newctx_fn *OSSL_FUNC_encoder_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_newctx_fn *)opf->function; }
typedef void (OSSL_FUNC_encoder_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_encoder_freectx_fn *OSSL_FUNC_encoder_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_freectx_fn *)opf->function; }
typedef int (OSSL_FUNC_encoder_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_encoder_get_params_fn *OSSL_FUNC_encoder_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_get_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_encoder_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_encoder_gettable_params_fn *OSSL_FUNC_encoder_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_gettable_params_fn *)opf->function; }
typedef int (OSSL_FUNC_encoder_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_encoder_set_ctx_params_fn *OSSL_FUNC_encoder_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_encoder_settable_ctx_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_encoder_settable_ctx_params_fn *OSSL_FUNC_encoder_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_encoder_does_selection_fn)(void *provctx, int selection); static __attribute__((unused)) inline OSSL_FUNC_encoder_does_selection_fn *OSSL_FUNC_encoder_does_selection(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_does_selection_fn *)opf->function; }
typedef int (OSSL_FUNC_encoder_encode_fn)(void *ctx, OSSL_CORE_BIO *out, const void *obj_raw, const OSSL_PARAM obj_abstract[], int selection, OSSL_PASSPHRASE_CALLBACK *cb, void *cbarg); static __attribute__((unused)) inline OSSL_FUNC_encoder_encode_fn *OSSL_FUNC_encoder_encode(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_encode_fn *)opf->function; }
typedef void * (OSSL_FUNC_encoder_import_object_fn)(void *ctx, int selection, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_encoder_import_object_fn *OSSL_FUNC_encoder_import_object(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_import_object_fn *)opf->function; }
typedef void (OSSL_FUNC_encoder_free_object_fn)(void *obj); static __attribute__((unused)) inline OSSL_FUNC_encoder_free_object_fn *OSSL_FUNC_encoder_free_object(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_encoder_free_object_fn *)opf->function; }
typedef void * (OSSL_FUNC_decoder_newctx_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_decoder_newctx_fn *OSSL_FUNC_decoder_newctx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_newctx_fn *)opf->function; }
typedef void (OSSL_FUNC_decoder_freectx_fn)(void *ctx); static __attribute__((unused)) inline OSSL_FUNC_decoder_freectx_fn *OSSL_FUNC_decoder_freectx(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_freectx_fn *)opf->function; }
typedef int (OSSL_FUNC_decoder_get_params_fn)(OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_decoder_get_params_fn *OSSL_FUNC_decoder_get_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_get_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_decoder_gettable_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_decoder_gettable_params_fn *OSSL_FUNC_decoder_gettable_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_gettable_params_fn *)opf->function; }
typedef int (OSSL_FUNC_decoder_set_ctx_params_fn)(void *ctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_decoder_set_ctx_params_fn *OSSL_FUNC_decoder_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_set_ctx_params_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_decoder_settable_ctx_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_decoder_settable_ctx_params_fn *OSSL_FUNC_decoder_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_decoder_does_selection_fn)(void *provctx, int selection); static __attribute__((unused)) inline OSSL_FUNC_decoder_does_selection_fn *OSSL_FUNC_decoder_does_selection(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_does_selection_fn *)opf->function; }
typedef int (OSSL_FUNC_decoder_decode_fn)(void *ctx, OSSL_CORE_BIO *in, int selection, OSSL_CALLBACK *data_cb, void *data_cbarg, OSSL_PASSPHRASE_CALLBACK *pw_cb, void *pw_cbarg); static __attribute__((unused)) inline OSSL_FUNC_decoder_decode_fn *OSSL_FUNC_decoder_decode(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_decode_fn *)opf->function; }
typedef int (OSSL_FUNC_decoder_export_object_fn)(void *ctx, const void *objref, size_t objref_sz, OSSL_CALLBACK *export_cb, void *export_cbarg); static __attribute__((unused)) inline OSSL_FUNC_decoder_export_object_fn *OSSL_FUNC_decoder_export_object(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_decoder_export_object_fn *)opf->function; }
typedef void * (OSSL_FUNC_store_open_fn)(void *provctx, const char *uri); static __attribute__((unused)) inline OSSL_FUNC_store_open_fn *OSSL_FUNC_store_open(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_open_fn *)opf->function; }
typedef void * (OSSL_FUNC_store_attach_fn)(void *provctx, OSSL_CORE_BIO *in); static __attribute__((unused)) inline OSSL_FUNC_store_attach_fn *OSSL_FUNC_store_attach(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_attach_fn *)opf->function; }
typedef const OSSL_PARAM * (OSSL_FUNC_store_settable_ctx_params_fn)(void *provctx); static __attribute__((unused)) inline OSSL_FUNC_store_settable_ctx_params_fn *OSSL_FUNC_store_settable_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_settable_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_store_set_ctx_params_fn)(void *loaderctx, const OSSL_PARAM params[]); static __attribute__((unused)) inline OSSL_FUNC_store_set_ctx_params_fn *OSSL_FUNC_store_set_ctx_params(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_set_ctx_params_fn *)opf->function; }
typedef int (OSSL_FUNC_store_load_fn)(void *loaderctx, OSSL_CALLBACK *object_cb, void *object_cbarg, OSSL_PASSPHRASE_CALLBACK *pw_cb, void *pw_cbarg); static __attribute__((unused)) inline OSSL_FUNC_store_load_fn *OSSL_FUNC_store_load(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_load_fn *)opf->function; }
typedef int (OSSL_FUNC_store_eof_fn)(void *loaderctx); static __attribute__((unused)) inline OSSL_FUNC_store_eof_fn *OSSL_FUNC_store_eof(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_eof_fn *)opf->function; }
typedef int (OSSL_FUNC_store_close_fn)(void *loaderctx); static __attribute__((unused)) inline OSSL_FUNC_store_close_fn *OSSL_FUNC_store_close(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_close_fn *)opf->function; }
typedef int (OSSL_FUNC_store_export_object_fn)(void *loaderctx, const void *objref, size_t objref_sz, OSSL_CALLBACK *export_cb, void *export_cbarg); static __attribute__((unused)) inline OSSL_FUNC_store_export_object_fn *OSSL_FUNC_store_export_object(const OSSL_DISPATCH *opf) { return (OSSL_FUNC_store_export_object_fn *)opf->function; }
        
        
        
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;

extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

        
        
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_ASN1_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_ASYNC_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_BIO_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_BN_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_BUF_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_CMS_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_COMP_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_CONF_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_CRYPTO_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_CT_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_DH_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_DSA_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_EC_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_ENGINE_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_ERR_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_EVP_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_KDF_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_OBJ_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_OCSP_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_PEM_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_PKCS12_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_PKCS7_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_RAND_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_RSA_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_OSSL_STORE_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_TS_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_UI_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_X509_strings(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int ERR_load_X509V3_strings(void);
typedef struct {
    int dummy;
} CRYPTO_dynlock;
typedef void CRYPTO_RWLOCK;
CRYPTO_RWLOCK *CRYPTO_THREAD_lock_new(void);
 int CRYPTO_THREAD_read_lock(CRYPTO_RWLOCK *lock);
 int CRYPTO_THREAD_write_lock(CRYPTO_RWLOCK *lock);
int CRYPTO_THREAD_unlock(CRYPTO_RWLOCK *lock);
void CRYPTO_THREAD_lock_free(CRYPTO_RWLOCK *lock);
int CRYPTO_atomic_add(int *val, int amount, int *ret, CRYPTO_RWLOCK *lock);
int CRYPTO_atomic_or(uint64_t *val, uint64_t op, uint64_t *ret,
                     CRYPTO_RWLOCK *lock);
int CRYPTO_atomic_load(uint64_t *val, uint64_t *ret, CRYPTO_RWLOCK *lock);
size_t OPENSSL_strlcpy(char *dst, const char *src, size_t siz);
size_t OPENSSL_strlcat(char *dst, const char *src, size_t siz);
size_t OPENSSL_strnlen(const char *str, size_t maxlen);
int OPENSSL_buf2hexstr_ex(char *str, size_t str_n, size_t *strlength,
                          const unsigned char *buf, size_t buflen,
                          const char sep);
char *OPENSSL_buf2hexstr(const unsigned char *buf, long buflen);
int OPENSSL_hexstr2buf_ex(unsigned char *buf, size_t buf_n, size_t *buflen,
                          const char *str, const char sep);
unsigned char *OPENSSL_hexstr2buf(const char *str, long *buflen);
int OPENSSL_hexchar2int(unsigned char c);
int OPENSSL_strcasecmp(const char *s1, const char *s2);
int OPENSSL_strncasecmp(const char *s1, const char *s2, size_t n);
unsigned int OPENSSL_version_major(void);
unsigned int OPENSSL_version_minor(void);
unsigned int OPENSSL_version_patch(void);
const char *OPENSSL_version_pre_release(void);
const char *OPENSSL_version_build_metadata(void);
unsigned long OpenSSL_version_num(void);
const char *OpenSSL_version(int type);
const char *OPENSSL_info(int type);
int OPENSSL_issetugid(void);
struct crypto_ex_data_st {
    OSSL_LIB_CTX *ctx;
    struct stack_st_void *sk;
};
struct stack_st_void; typedef int (*sk_void_compfunc)(const void * const *a, const void *const *b); typedef void (*sk_void_freefunc)(void *a); typedef void * (*sk_void_copyfunc)(const void *a); static __attribute__((unused)) inline void *ossl_check_void_type(void *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_void_sk_type(const struct stack_st_void *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_void_sk_type(struct stack_st_void *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_void_compfunc_type(sk_void_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_void_copyfunc_type(sk_void_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_void_freefunc_type(sk_void_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef void CRYPTO_EX_new (void *parent, void *ptr, CRYPTO_EX_DATA *ad,
                           int idx, long argl, void *argp);
typedef void CRYPTO_EX_free (void *parent, void *ptr, CRYPTO_EX_DATA *ad,
                             int idx, long argl, void *argp);
typedef int CRYPTO_EX_dup (CRYPTO_EX_DATA *to, const CRYPTO_EX_DATA *from,
                           void **from_d, int idx, long argl, void *argp);
 int CRYPTO_get_ex_new_index(int class_index, long argl, void *argp,
                                   CRYPTO_EX_new *new_func,
                                   CRYPTO_EX_dup *dup_func,
                                   CRYPTO_EX_free *free_func);
int CRYPTO_free_ex_index(int class_index, int idx);
int CRYPTO_new_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad);
int CRYPTO_dup_ex_data(int class_index, CRYPTO_EX_DATA *to,
                       const CRYPTO_EX_DATA *from);
void CRYPTO_free_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad);
int CRYPTO_alloc_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad,
                         int idx);
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int idx, void *val);
void *CRYPTO_get_ex_data(const CRYPTO_EX_DATA *ad, int idx);
typedef struct crypto_threadid_st {
    int dummy;
} CRYPTO_THREADID;
typedef void *(*CRYPTO_malloc_fn)(size_t num, const char *file, int line);
typedef void *(*CRYPTO_realloc_fn)(void *addr, size_t num, const char *file,
                                   int line);
typedef void (*CRYPTO_free_fn)(void *addr, const char *file, int line);
int CRYPTO_set_mem_functions(CRYPTO_malloc_fn malloc_fn,
                             CRYPTO_realloc_fn realloc_fn,
                             CRYPTO_free_fn free_fn);
void CRYPTO_get_mem_functions(CRYPTO_malloc_fn *malloc_fn,
                              CRYPTO_realloc_fn *realloc_fn,
                              CRYPTO_free_fn *free_fn);
void *CRYPTO_malloc(size_t num, const char *file, int line);
void *CRYPTO_zalloc(size_t num, const char *file, int line);
void *CRYPTO_memdup(const void *str, size_t siz, const char *file, int line);
char *CRYPTO_strdup(const char *str, const char *file, int line);
char *CRYPTO_strndup(const char *str, size_t s, const char *file, int line);
void CRYPTO_free(void *ptr, const char *file, int line);
void CRYPTO_clear_free(void *ptr, size_t num, const char *file, int line);
void *CRYPTO_realloc(void *addr, size_t num, const char *file, int line);
void *CRYPTO_clear_realloc(void *addr, size_t old_num, size_t num,
                           const char *file, int line);
int CRYPTO_secure_malloc_init(size_t sz, size_t minsize);
int CRYPTO_secure_malloc_done(void);
void *CRYPTO_secure_malloc(size_t num, const char *file, int line);
void *CRYPTO_secure_zalloc(size_t num, const char *file, int line);
void CRYPTO_secure_free(void *ptr, const char *file, int line);
void CRYPTO_secure_clear_free(void *ptr, size_t num,
                              const char *file, int line);
int CRYPTO_secure_allocated(const void *ptr);
int CRYPTO_secure_malloc_initialized(void);
size_t CRYPTO_secure_actual_size(void *ptr);
size_t CRYPTO_secure_used(void);
void OPENSSL_cleanse(void *ptr, size_t len);
_Noreturn void OPENSSL_die(const char *assertion, const char *file, int line);
int OPENSSL_isservice(void);
void OPENSSL_init(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void OPENSSL_fork_prepare(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void OPENSSL_fork_parent(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void OPENSSL_fork_child(void);
struct tm *OPENSSL_gmtime(const time_t *timer, struct tm *result);
int OPENSSL_gmtime_adj(struct tm *tm, int offset_day, long offset_sec);
int OPENSSL_gmtime_diff(int *pday, int *psec,
                        const struct tm *from, const struct tm *to);
int CRYPTO_memcmp(const void * in_a, const void * in_b, size_t len);
void OPENSSL_cleanup(void);
int OPENSSL_init_crypto(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
int OPENSSL_atexit(void (*handler)(void));
void OPENSSL_thread_stop(void);
void OPENSSL_thread_stop_ex(OSSL_LIB_CTX *ctx);
OPENSSL_INIT_SETTINGS *OPENSSL_INIT_new(void);
int OPENSSL_INIT_set_config_filename(OPENSSL_INIT_SETTINGS *settings,
                                     const char *config_filename);
void OPENSSL_INIT_set_config_file_flags(OPENSSL_INIT_SETTINGS *settings,
                                        unsigned long flags);
int OPENSSL_INIT_set_config_appname(OPENSSL_INIT_SETTINGS *settings,
                                    const char *config_appname);
void OPENSSL_INIT_free(OPENSSL_INIT_SETTINGS *settings);
struct sched_param
{
  int sched_priority;
};


typedef unsigned long int __cpu_mask;
typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;

extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
     __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));

typedef long int __jmp_buf[8];
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };
enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
};
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};
enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};
enum
{
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};
enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};

extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));
extern int pthread_join (pthread_t __th, void **__thread_return);
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));
extern pthread_t pthread_self (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate (int __state, int *__oldstate);
extern int pthread_setcanceltype (int __type, int *__oldtype);
extern int pthread_cancel (pthread_t __th);
extern void pthread_testcancel (void);
struct __cancel_jmp_buf_tag
{
  __jmp_buf __cancel_jmp_buf;
  int __mask_was_saved;
};
typedef struct
{
  struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))
     __attribute__ ((__weak__))
     ;
extern int __sigsetjmp_cancel (struct __cancel_jmp_buf_tag __env[1], int __savemask) __asm__ ("" "__sigsetjmp") __attribute__ ((__nothrow__)) __attribute__ ((__returns_twice__));
extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__access__ (__none__, 2)));
extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) pthread_equal (pthread_t __thread1, pthread_t __thread2)
{
  return __thread1 == __thread2;
}

typedef pthread_once_t CRYPTO_ONCE;
typedef pthread_key_t CRYPTO_THREAD_LOCAL;
typedef pthread_t CRYPTO_THREAD_ID;
int CRYPTO_THREAD_run_once(CRYPTO_ONCE *once, void (*init)(void));
int CRYPTO_THREAD_init_local(CRYPTO_THREAD_LOCAL *key, void (*cleanup)(void *));
void *CRYPTO_THREAD_get_local(CRYPTO_THREAD_LOCAL *key);
int CRYPTO_THREAD_set_local(CRYPTO_THREAD_LOCAL *key, void *val);
int CRYPTO_THREAD_cleanup_local(CRYPTO_THREAD_LOCAL *key);
CRYPTO_THREAD_ID CRYPTO_THREAD_get_current_id(void);
int CRYPTO_THREAD_compare_id(CRYPTO_THREAD_ID a, CRYPTO_THREAD_ID b);
OSSL_LIB_CTX *OSSL_LIB_CTX_new(void);
OSSL_LIB_CTX *OSSL_LIB_CTX_new_from_dispatch(const OSSL_CORE_HANDLE *handle,
                                             const OSSL_DISPATCH *in);
OSSL_LIB_CTX *OSSL_LIB_CTX_new_child(const OSSL_CORE_HANDLE *handle,
                                     const OSSL_DISPATCH *in);
int OSSL_LIB_CTX_load_config(OSSL_LIB_CTX *ctx, const char *config_file);
void OSSL_LIB_CTX_free(OSSL_LIB_CTX *);
OSSL_LIB_CTX *OSSL_LIB_CTX_get0_global_default(void);
OSSL_LIB_CTX *OSSL_LIB_CTX_set0_default(OSSL_LIB_CTX *libctx);
        
typedef union bio_addr_st BIO_ADDR;
typedef struct bio_addrinfo_st BIO_ADDRINFO;
int BIO_get_new_index(void);
void BIO_set_flags(BIO *b, int flags);
int BIO_test_flags(const BIO *b, int flags);
void BIO_clear_flags(BIO *b, int flags);
typedef long (*BIO_callback_fn)(BIO *b, int oper, const char *argp, int argi,
                                long argl, long ret);
__attribute__((deprecated("Since OpenSSL " "3.0"))) BIO_callback_fn BIO_get_callback(const BIO *b);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void BIO_set_callback(BIO *b, BIO_callback_fn callback);
__attribute__((deprecated("Since OpenSSL " "3.0"))) long BIO_debug_callback(BIO *bio, int cmd,
                                               const char *argp, int argi,
                                               long argl, long ret);
typedef long (*BIO_callback_fn_ex)(BIO *b, int oper, const char *argp,
                                   size_t len, int argi,
                                   long argl, int ret, size_t *processed);
BIO_callback_fn_ex BIO_get_callback_ex(const BIO *b);
void BIO_set_callback_ex(BIO *b, BIO_callback_fn_ex callback);
long BIO_debug_callback_ex(BIO *bio, int oper, const char *argp, size_t len,
                           int argi, long argl, int ret, size_t *processed);
char *BIO_get_callback_arg(const BIO *b);
void BIO_set_callback_arg(BIO *b, char *arg);
typedef struct bio_method_st BIO_METHOD;
const char *BIO_method_name(const BIO *b);
int BIO_method_type(const BIO *b);
typedef int BIO_info_cb(BIO *, int, int);
typedef BIO_info_cb bio_info_cb;
struct stack_st_BIO; typedef int (*sk_BIO_compfunc)(const BIO * const *a, const BIO *const *b); typedef void (*sk_BIO_freefunc)(BIO *a); typedef BIO * (*sk_BIO_copyfunc)(const BIO *a); static __attribute__((unused)) inline BIO *ossl_check_BIO_type(BIO *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_BIO_sk_type(const struct stack_st_BIO *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_BIO_sk_type(struct stack_st_BIO *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_BIO_compfunc_type(sk_BIO_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_BIO_copyfunc_type(sk_BIO_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_BIO_freefunc_type(sk_BIO_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef int asn1_ps_func (BIO *b, unsigned char **pbuf, int *plen,
                          void *parg);
typedef void (*BIO_dgram_sctp_notification_handler_fn) (BIO *b,
                                                        void *context,
                                                        void *buf);
size_t BIO_ctrl_pending(BIO *b);
size_t BIO_ctrl_wpending(BIO *b);
size_t BIO_ctrl_get_write_guarantee(BIO *b);
size_t BIO_ctrl_get_read_request(BIO *b);
int BIO_ctrl_reset_read_request(BIO *b);
int BIO_set_ex_data(BIO *bio, int idx, void *data);
void *BIO_get_ex_data(const BIO *bio, int idx);
uint64_t BIO_number_read(BIO *bio);
uint64_t BIO_number_written(BIO *bio);
int BIO_asn1_set_prefix(BIO *b, asn1_ps_func *prefix,
                        asn1_ps_func *prefix_free);
int BIO_asn1_get_prefix(BIO *b, asn1_ps_func **pprefix,
                        asn1_ps_func **pprefix_free);
int BIO_asn1_set_suffix(BIO *b, asn1_ps_func *suffix,
                        asn1_ps_func *suffix_free);
int BIO_asn1_get_suffix(BIO *b, asn1_ps_func **psuffix,
                        asn1_ps_func **psuffix_free);
const BIO_METHOD *BIO_s_file(void);
BIO *BIO_new_file(const char *filename, const char *mode);
BIO *BIO_new_from_core_bio(OSSL_LIB_CTX *libctx, OSSL_CORE_BIO *corebio);
BIO *BIO_new_fp(FILE *stream, int close_flag);
BIO *BIO_new_ex(OSSL_LIB_CTX *libctx, const BIO_METHOD *method);
BIO *BIO_new(const BIO_METHOD *type);
int BIO_free(BIO *a);
void BIO_set_data(BIO *a, void *ptr);
void *BIO_get_data(BIO *a);
void BIO_set_init(BIO *a, int init);
int BIO_get_init(BIO *a);
void BIO_set_shutdown(BIO *a, int shut);
int BIO_get_shutdown(BIO *a);
void BIO_vfree(BIO *a);
int BIO_up_ref(BIO *a);
int BIO_read(BIO *b, void *data, int dlen);
int BIO_read_ex(BIO *b, void *data, size_t dlen, size_t *readbytes);
int BIO_gets(BIO *bp, char *buf, int size);
int BIO_get_line(BIO *bio, char *buf, int size);
int BIO_write(BIO *b, const void *data, int dlen);
int BIO_write_ex(BIO *b, const void *data, size_t dlen, size_t *written);
int BIO_puts(BIO *bp, const char *buf);
int BIO_indent(BIO *b, int indent, int max);
long BIO_ctrl(BIO *bp, int cmd, long larg, void *parg);
long BIO_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp);
void *BIO_ptr_ctrl(BIO *bp, int cmd, long larg);
long BIO_int_ctrl(BIO *bp, int cmd, long larg, int iarg);
BIO *BIO_push(BIO *b, BIO *append);
BIO *BIO_pop(BIO *b);
void BIO_free_all(BIO *a);
BIO *BIO_find_type(BIO *b, int bio_type);
BIO *BIO_next(BIO *b);
void BIO_set_next(BIO *b, BIO *next);
BIO *BIO_get_retry_BIO(BIO *bio, int *reason);
int BIO_get_retry_reason(BIO *bio);
void BIO_set_retry_reason(BIO *bio, int reason);
BIO *BIO_dup_chain(BIO *in);
int BIO_nread0(BIO *bio, char **buf);
int BIO_nread(BIO *bio, char **buf, int num);
int BIO_nwrite0(BIO *bio, char **buf);
int BIO_nwrite(BIO *bio, char **buf, int num);
const BIO_METHOD *BIO_s_mem(void);
const BIO_METHOD *BIO_s_secmem(void);
BIO *BIO_new_mem_buf(const void *buf, int len);
const BIO_METHOD *BIO_s_socket(void);
const BIO_METHOD *BIO_s_connect(void);
const BIO_METHOD *BIO_s_accept(void);
const BIO_METHOD *BIO_s_fd(void);
const BIO_METHOD *BIO_s_log(void);
const BIO_METHOD *BIO_s_bio(void);
const BIO_METHOD *BIO_s_null(void);
const BIO_METHOD *BIO_f_null(void);
const BIO_METHOD *BIO_f_buffer(void);
const BIO_METHOD *BIO_f_readbuffer(void);
const BIO_METHOD *BIO_f_linebuffer(void);
const BIO_METHOD *BIO_f_nbio_test(void);
const BIO_METHOD *BIO_f_prefix(void);
const BIO_METHOD *BIO_s_core(void);
const BIO_METHOD *BIO_s_datagram(void);
int BIO_dgram_non_fatal_error(int error);
BIO *BIO_new_dgram(int fd, int close_flag);
int BIO_sock_should_retry(int i);
int BIO_sock_non_fatal_error(int error);
int BIO_socket_wait(int fd, int for_read, time_t max_time);
int BIO_wait(BIO *bio, time_t max_time, unsigned int nap_milliseconds);
int BIO_do_connect_retry(BIO *bio, int timeout, int nap_milliseconds);
int BIO_fd_should_retry(int i);
int BIO_fd_non_fatal_error(int error);
int BIO_dump_cb(int (*cb) (const void *data, size_t len, void *u),
                void *u, const void *s, int len);
int BIO_dump_indent_cb(int (*cb) (const void *data, size_t len, void *u),
                       void *u, const void *s, int len, int indent);
int BIO_dump(BIO *b, const void *bytes, int len);
int BIO_dump_indent(BIO *b, const void *bytes, int len, int indent);
int BIO_dump_fp(FILE *fp, const void *s, int len);
int BIO_dump_indent_fp(FILE *fp, const void *s, int len, int indent);
int BIO_hex_string(BIO *out, int indent, int width, const void *data,
                   int datalen);
BIO_ADDR *BIO_ADDR_new(void);
int BIO_ADDR_rawmake(BIO_ADDR *ap, int family,
                     const void *where, size_t wherelen, unsigned short port);
void BIO_ADDR_free(BIO_ADDR *);
void BIO_ADDR_clear(BIO_ADDR *ap);
int BIO_ADDR_family(const BIO_ADDR *ap);
int BIO_ADDR_rawaddress(const BIO_ADDR *ap, void *p, size_t *l);
unsigned short BIO_ADDR_rawport(const BIO_ADDR *ap);
char *BIO_ADDR_hostname_string(const BIO_ADDR *ap, int numeric);
char *BIO_ADDR_service_string(const BIO_ADDR *ap, int numeric);
char *BIO_ADDR_path_string(const BIO_ADDR *ap);
const BIO_ADDRINFO *BIO_ADDRINFO_next(const BIO_ADDRINFO *bai);
int BIO_ADDRINFO_family(const BIO_ADDRINFO *bai);
int BIO_ADDRINFO_socktype(const BIO_ADDRINFO *bai);
int BIO_ADDRINFO_protocol(const BIO_ADDRINFO *bai);
const BIO_ADDR *BIO_ADDRINFO_address(const BIO_ADDRINFO *bai);
void BIO_ADDRINFO_free(BIO_ADDRINFO *bai);
enum BIO_hostserv_priorities {
    BIO_PARSE_PRIO_HOST, BIO_PARSE_PRIO_SERV
};
int BIO_parse_hostserv(const char *hostserv, char **host, char **service,
                       enum BIO_hostserv_priorities hostserv_prio);
enum BIO_lookup_type {
    BIO_LOOKUP_CLIENT, BIO_LOOKUP_SERVER
};
int BIO_lookup(const char *host, const char *service,
               enum BIO_lookup_type lookup_type,
               int family, int socktype, BIO_ADDRINFO **res);
int BIO_lookup_ex(const char *host, const char *service,
                  int lookup_type, int family, int socktype, int protocol,
                  BIO_ADDRINFO **res);
int BIO_sock_error(int sock);
int BIO_socket_ioctl(int fd, long type, void *arg);
int BIO_socket_nbio(int fd, int mode);
int BIO_sock_init(void);
int BIO_set_tcp_ndelay(int sock, int turn_on);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) struct hostent *BIO_gethostbyname(const char *name);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) int BIO_get_port(const char *str, unsigned short *port_ptr);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) int BIO_get_host_ip(const char *str, unsigned char *ip);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) int BIO_get_accept_socket(char *host_port, int mode);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) int BIO_accept(int sock, char **ip_port);
union BIO_sock_info_u {
    BIO_ADDR *addr;
};
enum BIO_sock_info_type {
    BIO_SOCK_INFO_ADDRESS
};
int BIO_sock_info(int sock,
                  enum BIO_sock_info_type type, union BIO_sock_info_u *info);
int BIO_socket(int domain, int socktype, int protocol, int options);
int BIO_connect(int sock, const BIO_ADDR *addr, int options);
int BIO_bind(int sock, const BIO_ADDR *addr, int options);
int BIO_listen(int sock, const BIO_ADDR *addr, int options);
int BIO_accept_ex(int accept_sock, BIO_ADDR *addr, int options);
int BIO_closesocket(int sock);
BIO *BIO_new_socket(int sock, int close_flag);
BIO *BIO_new_connect(const char *host_port);
BIO *BIO_new_accept(const char *host_port);
BIO *BIO_new_fd(int fd, int close_flag);
int BIO_new_bio_pair(BIO **bio1, size_t writebuf1,
                     BIO **bio2, size_t writebuf2);
void BIO_copy_next_retry(BIO *b);
int BIO_printf(BIO *bio, const char *format, ...)
__attribute__((__format__(__gnu_printf__, 2, 3)));
int BIO_vprintf(BIO *bio, const char *format, va_list args)
__attribute__((__format__(__gnu_printf__, 2, 0)));
int BIO_snprintf(char *buf, size_t n, const char *format, ...)
__attribute__((__format__(__gnu_printf__, 3, 4)));
int BIO_vsnprintf(char *buf, size_t n, const char *format, va_list args)
__attribute__((__format__(__gnu_printf__, 3, 0)));
BIO_METHOD *BIO_meth_new(int type, const char *name);
void BIO_meth_free(BIO_METHOD *biom);
int (*BIO_meth_get_write(const BIO_METHOD *biom)) (BIO *, const char *, int);
int (*BIO_meth_get_write_ex(const BIO_METHOD *biom)) (BIO *, const char *, size_t,
                                                size_t *);
int BIO_meth_set_write(BIO_METHOD *biom,
                       int (*write) (BIO *, const char *, int));
int BIO_meth_set_write_ex(BIO_METHOD *biom,
                       int (*bwrite) (BIO *, const char *, size_t, size_t *));
int (*BIO_meth_get_read(const BIO_METHOD *biom)) (BIO *, char *, int);
int (*BIO_meth_get_read_ex(const BIO_METHOD *biom)) (BIO *, char *, size_t, size_t *);
int BIO_meth_set_read(BIO_METHOD *biom,
                      int (*read) (BIO *, char *, int));
int BIO_meth_set_read_ex(BIO_METHOD *biom,
                         int (*bread) (BIO *, char *, size_t, size_t *));
int (*BIO_meth_get_puts(const BIO_METHOD *biom)) (BIO *, const char *);
int BIO_meth_set_puts(BIO_METHOD *biom,
                      int (*puts) (BIO *, const char *));
int (*BIO_meth_get_gets(const BIO_METHOD *biom)) (BIO *, char *, int);
int BIO_meth_set_gets(BIO_METHOD *biom,
                      int (*gets) (BIO *, char *, int));
long (*BIO_meth_get_ctrl(const BIO_METHOD *biom)) (BIO *, int, long, void *);
int BIO_meth_set_ctrl(BIO_METHOD *biom,
                      long (*ctrl) (BIO *, int, long, void *));
int (*BIO_meth_get_create(const BIO_METHOD *bion)) (BIO *);
int BIO_meth_set_create(BIO_METHOD *biom, int (*create) (BIO *));
int (*BIO_meth_get_destroy(const BIO_METHOD *biom)) (BIO *);
int BIO_meth_set_destroy(BIO_METHOD *biom, int (*destroy) (BIO *));
long (*BIO_meth_get_callback_ctrl(const BIO_METHOD *biom))
                                 (BIO *, int, BIO_info_cb *);
int BIO_meth_set_callback_ctrl(BIO_METHOD *biom,
                               long (*callback_ctrl) (BIO *, int,
                                                      BIO_info_cb *));
        
        
        
        
void BN_set_flags(BIGNUM *b, int n);
int BN_get_flags(const BIGNUM *b, int n);
void BN_with_flags(BIGNUM *dest, const BIGNUM *b, int flags);
int BN_GENCB_call(BN_GENCB *cb, int a, int b);
BN_GENCB *BN_GENCB_new(void);
void BN_GENCB_free(BN_GENCB *cb);
void BN_GENCB_set_old(BN_GENCB *gencb, void (*callback) (int, int, void *),
                      void *cb_arg);
void BN_GENCB_set(BN_GENCB *gencb, int (*callback) (int, int, BN_GENCB *),
                  void *cb_arg);
void *BN_GENCB_get_arg(BN_GENCB *cb);
int BN_abs_is_word(const BIGNUM *a, const unsigned long w);
int BN_is_zero(const BIGNUM *a);
int BN_is_one(const BIGNUM *a);
int BN_is_word(const BIGNUM *a, const unsigned long w);
int BN_is_odd(const BIGNUM *a);
void BN_zero_ex(BIGNUM *a);
const BIGNUM *BN_value_one(void);
char *BN_options(void);
BN_CTX *BN_CTX_new_ex(OSSL_LIB_CTX *ctx);
BN_CTX *BN_CTX_new(void);
BN_CTX *BN_CTX_secure_new_ex(OSSL_LIB_CTX *ctx);
BN_CTX *BN_CTX_secure_new(void);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
int BN_rand_ex(BIGNUM *rnd, int bits, int top, int bottom,
               unsigned int strength, BN_CTX *ctx);
int BN_rand(BIGNUM *rnd, int bits, int top, int bottom);
int BN_priv_rand_ex(BIGNUM *rnd, int bits, int top, int bottom,
                    unsigned int strength, BN_CTX *ctx);
int BN_priv_rand(BIGNUM *rnd, int bits, int top, int bottom);
int BN_rand_range_ex(BIGNUM *r, const BIGNUM *range, unsigned int strength,
                     BN_CTX *ctx);
int BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
int BN_priv_rand_range_ex(BIGNUM *r, const BIGNUM *range,
                          unsigned int strength, BN_CTX *ctx);
int BN_priv_rand_range(BIGNUM *rnd, const BIGNUM *range);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_pseudo_rand(BIGNUM *rnd, int bits, int top, int bottom);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_pseudo_rand_range(BIGNUM *rnd, const BIGNUM *range);
int BN_num_bits(const BIGNUM *a);
int BN_num_bits_word(unsigned long l);
int BN_security_bits(int L, int N);
BIGNUM *BN_new(void);
BIGNUM *BN_secure_new(void);
void BN_clear_free(BIGNUM *a);
BIGNUM *BN_copy(BIGNUM *a, const BIGNUM *b);
void BN_swap(BIGNUM *a, BIGNUM *b);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);
int BN_bn2binpad(const BIGNUM *a, unsigned char *to, int tolen);
BIGNUM *BN_lebin2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_bn2lebinpad(const BIGNUM *a, unsigned char *to, int tolen);
BIGNUM *BN_native2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_bn2nativepad(const BIGNUM *a, unsigned char *to, int tolen);
BIGNUM *BN_mpi2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_bn2mpi(const BIGNUM *a, unsigned char *to);
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_usub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
void BN_set_negative(BIGNUM *b, int n);
int BN_is_negative(const BIGNUM *b);
int BN_div(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m, const BIGNUM *d,
           BN_CTX *ctx);
int BN_nnmod(BIGNUM *r, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx);
int BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int BN_mod_add_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m);
int BN_mod_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int BN_mod_sub_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m);
int BN_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int BN_mod_lshift1(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int BN_mod_lshift1_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *m);
int BN_mod_lshift(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m,
                  BN_CTX *ctx);
int BN_mod_lshift_quick(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m);
unsigned long BN_mod_word(const BIGNUM *a, unsigned long w);
unsigned long BN_div_word(BIGNUM *a, unsigned long w);
int BN_mul_word(BIGNUM *a, unsigned long w);
int BN_add_word(BIGNUM *a, unsigned long w);
int BN_sub_word(BIGNUM *a, unsigned long w);
int BN_set_word(BIGNUM *a, unsigned long w);
unsigned long BN_get_word(const BIGNUM *a);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
void BN_free(BIGNUM *a);
int BN_is_bit_set(const BIGNUM *a, int n);
int BN_lshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_lshift1(BIGNUM *r, const BIGNUM *a);
int BN_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
               const BIGNUM *m, BN_CTX *ctx);
int BN_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                    const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int BN_mod_exp_mont_consttime(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
                              const BIGNUM *m, BN_CTX *ctx,
                              BN_MONT_CTX *in_mont);
int BN_mod_exp_mont_word(BIGNUM *r, unsigned long a, const BIGNUM *p,
                         const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int BN_mod_exp2_mont(BIGNUM *r, const BIGNUM *a1, const BIGNUM *p1,
                     const BIGNUM *a2, const BIGNUM *p2, const BIGNUM *m,
                     BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int BN_mod_exp_simple(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                      const BIGNUM *m, BN_CTX *ctx);
int BN_mod_exp_mont_consttime_x2(BIGNUM *rr1, const BIGNUM *a1, const BIGNUM *p1,
                                 const BIGNUM *m1, BN_MONT_CTX *in_mont1,
                                 BIGNUM *rr2, const BIGNUM *a2, const BIGNUM *p2,
                                 const BIGNUM *m2, BN_MONT_CTX *in_mont2,
                                 BN_CTX *ctx);
int BN_mask_bits(BIGNUM *a, int n);
int BN_print_fp(FILE *fp, const BIGNUM *a);
int BN_print(BIO *bio, const BIGNUM *a);
int BN_reciprocal(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx);
int BN_rshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_rshift1(BIGNUM *r, const BIGNUM *a);
void BN_clear(BIGNUM *a);
BIGNUM *BN_dup(const BIGNUM *a);
int BN_ucmp(const BIGNUM *a, const BIGNUM *b);
int BN_set_bit(BIGNUM *a, int n);
int BN_clear_bit(BIGNUM *a, int n);
char *BN_bn2hex(const BIGNUM *a);
char *BN_bn2dec(const BIGNUM *a);
int BN_hex2bn(BIGNUM **a, const char *str);
int BN_dec2bn(BIGNUM **a, const char *str);
int BN_asc2bn(BIGNUM **a, const char *str);
int BN_gcd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_kronecker(const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
BIGNUM *BN_mod_inverse(BIGNUM *ret,
                       const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);
BIGNUM *BN_mod_sqrt(BIGNUM *ret,
                    const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);
void BN_consttime_swap(unsigned long swap, BIGNUM *a, BIGNUM *b, int nwords);
__attribute__((deprecated("Since OpenSSL " "0.9.8")))
BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int safe,
                          const BIGNUM *add, const BIGNUM *rem,
                          void (*callback) (int, int, void *),
                          void *cb_arg);
__attribute__((deprecated("Since OpenSSL " "0.9.8")))
int BN_is_prime(const BIGNUM *p, int nchecks,
                void (*callback) (int, int, void *),
                BN_CTX *ctx, void *cb_arg);
__attribute__((deprecated("Since OpenSSL " "0.9.8")))
int BN_is_prime_fasttest(const BIGNUM *p, int nchecks,
                         void (*callback) (int, int, void *),
                         BN_CTX *ctx, void *cb_arg,
                         int do_trial_division);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_is_prime_ex(const BIGNUM *p, int nchecks, BN_CTX *ctx, BN_GENCB *cb);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_is_prime_fasttest_ex(const BIGNUM *p, int nchecks, BN_CTX *ctx,
                            int do_trial_division, BN_GENCB *cb);
int BN_generate_prime_ex2(BIGNUM *ret, int bits, int safe,
                          const BIGNUM *add, const BIGNUM *rem, BN_GENCB *cb,
                          BN_CTX *ctx);
int BN_generate_prime_ex(BIGNUM *ret, int bits, int safe, const BIGNUM *add,
                         const BIGNUM *rem, BN_GENCB *cb);
int BN_check_prime(const BIGNUM *p, BN_CTX *ctx, BN_GENCB *cb);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_X931_generate_Xpq(BIGNUM *Xp, BIGNUM *Xq, int nbits, BN_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_X931_derive_prime_ex(BIGNUM *p, BIGNUM *p1, BIGNUM *p2,
                            const BIGNUM *Xp, const BIGNUM *Xp1,
                            const BIGNUM *Xp2, const BIGNUM *e, BN_CTX *ctx,
                            BN_GENCB *cb);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int BN_X931_generate_prime_ex(BIGNUM *p, BIGNUM *p1, BIGNUM *p2, BIGNUM *Xp1,
                              BIGNUM *Xp2, const BIGNUM *Xp, const BIGNUM *e,
                              BN_CTX *ctx, BN_GENCB *cb);
BN_MONT_CTX *BN_MONT_CTX_new(void);
int BN_mod_mul_montgomery(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                          BN_MONT_CTX *mont, BN_CTX *ctx);
int BN_to_montgomery(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont,
                     BN_CTX *ctx);
int BN_from_montgomery(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont,
                       BN_CTX *ctx);
void BN_MONT_CTX_free(BN_MONT_CTX *mont);
int BN_MONT_CTX_set(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx);
BN_MONT_CTX *BN_MONT_CTX_copy(BN_MONT_CTX *to, BN_MONT_CTX *from);
BN_MONT_CTX *BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, CRYPTO_RWLOCK *lock,
                                    const BIGNUM *mod, BN_CTX *ctx);
BN_BLINDING *BN_BLINDING_new(const BIGNUM *A, const BIGNUM *Ai, BIGNUM *mod);
void BN_BLINDING_free(BN_BLINDING *b);
int BN_BLINDING_update(BN_BLINDING *b, BN_CTX *ctx);
int BN_BLINDING_convert(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx);
int BN_BLINDING_invert(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx);
int BN_BLINDING_convert_ex(BIGNUM *n, BIGNUM *r, BN_BLINDING *b, BN_CTX *);
int BN_BLINDING_invert_ex(BIGNUM *n, const BIGNUM *r, BN_BLINDING *b,
                          BN_CTX *);
int BN_BLINDING_is_current_thread(BN_BLINDING *b);
void BN_BLINDING_set_current_thread(BN_BLINDING *b);
int BN_BLINDING_lock(BN_BLINDING *b);
int BN_BLINDING_unlock(BN_BLINDING *b);
unsigned long BN_BLINDING_get_flags(const BN_BLINDING *);
void BN_BLINDING_set_flags(BN_BLINDING *, unsigned long);
BN_BLINDING *BN_BLINDING_create_param(BN_BLINDING *b,
                                      const BIGNUM *e, BIGNUM *m, BN_CTX *ctx,
                                      int (*bn_mod_exp) (BIGNUM *r,
                                                         const BIGNUM *a,
                                                         const BIGNUM *p,
                                                         const BIGNUM *m,
                                                         BN_CTX *ctx,
                                                         BN_MONT_CTX *m_ctx),
                                      BN_MONT_CTX *m_ctx);
__attribute__((deprecated("Since OpenSSL " "0.9.8")))
void BN_set_params(int mul, int high, int low, int mont);
__attribute__((deprecated("Since OpenSSL " "0.9.8")))
int BN_get_params(int which);
BN_RECP_CTX *BN_RECP_CTX_new(void);
void BN_RECP_CTX_free(BN_RECP_CTX *recp);
int BN_RECP_CTX_set(BN_RECP_CTX *recp, const BIGNUM *rdiv, BN_CTX *ctx);
int BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y,
                          BN_RECP_CTX *recp, BN_CTX *ctx);
int BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                    const BIGNUM *m, BN_CTX *ctx);
int BN_div_recp(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m,
                BN_RECP_CTX *recp, BN_CTX *ctx);
int BN_GF2m_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_GF2m_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *p);
int BN_GF2m_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_inv(BIGNUM *r, const BIGNUM *b, const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_div(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_sqrt(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                     BN_CTX *ctx);
int BN_GF2m_mod_solve_quad(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                           BN_CTX *ctx);
int BN_GF2m_mod_arr(BIGNUM *r, const BIGNUM *a, const int p[]);
int BN_GF2m_mod_mul_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
int BN_GF2m_mod_sqr_arr(BIGNUM *r, const BIGNUM *a, const int p[],
                        BN_CTX *ctx);
int BN_GF2m_mod_inv_arr(BIGNUM *r, const BIGNUM *b, const int p[],
                        BN_CTX *ctx);
int BN_GF2m_mod_div_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
int BN_GF2m_mod_exp_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
int BN_GF2m_mod_sqrt_arr(BIGNUM *r, const BIGNUM *a,
                         const int p[], BN_CTX *ctx);
int BN_GF2m_mod_solve_quad_arr(BIGNUM *r, const BIGNUM *a,
                               const int p[], BN_CTX *ctx);
int BN_GF2m_poly2arr(const BIGNUM *a, int p[], int max);
int BN_GF2m_arr2poly(const int p[], BIGNUM *a);
int BN_nist_mod_192(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_224(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_256(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_384(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_521(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
const BIGNUM *BN_get0_nist_prime_192(void);
const BIGNUM *BN_get0_nist_prime_224(void);
const BIGNUM *BN_get0_nist_prime_256(void);
const BIGNUM *BN_get0_nist_prime_384(void);
const BIGNUM *BN_get0_nist_prime_521(void);
int (*BN_nist_mod_func(const BIGNUM *p)) (BIGNUM *r, const BIGNUM *a,
                                          const BIGNUM *field, BN_CTX *ctx);
int BN_generate_dsa_nonce(BIGNUM *out, const BIGNUM *range,
                          const BIGNUM *priv, const unsigned char *message,
                          size_t message_len, BN_CTX *ctx);
BIGNUM *BN_get_rfc2409_prime_768(BIGNUM *bn);
BIGNUM *BN_get_rfc2409_prime_1024(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_1536(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_2048(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_3072(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_4096(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_6144(BIGNUM *bn);
BIGNUM *BN_get_rfc3526_prime_8192(BIGNUM *bn);
int BN_bntest_rand(BIGNUM *rnd, int bits, int top, int bottom);
OSSL_PARAM *OSSL_PARAM_locate(OSSL_PARAM *p, const char *key);
const OSSL_PARAM *OSSL_PARAM_locate_const(const OSSL_PARAM *p, const char *key);
OSSL_PARAM OSSL_PARAM_construct_int(const char *key, int *buf);
OSSL_PARAM OSSL_PARAM_construct_uint(const char *key, unsigned int *buf);
OSSL_PARAM OSSL_PARAM_construct_long(const char *key, long int *buf);
OSSL_PARAM OSSL_PARAM_construct_ulong(const char *key, unsigned long int *buf);
OSSL_PARAM OSSL_PARAM_construct_int32(const char *key, int32_t *buf);
OSSL_PARAM OSSL_PARAM_construct_uint32(const char *key, uint32_t *buf);
OSSL_PARAM OSSL_PARAM_construct_int64(const char *key, int64_t *buf);
OSSL_PARAM OSSL_PARAM_construct_uint64(const char *key, uint64_t *buf);
OSSL_PARAM OSSL_PARAM_construct_size_t(const char *key, size_t *buf);
OSSL_PARAM OSSL_PARAM_construct_time_t(const char *key, time_t *buf);
OSSL_PARAM OSSL_PARAM_construct_BN(const char *key, unsigned char *buf,
                                   size_t bsize);
OSSL_PARAM OSSL_PARAM_construct_double(const char *key, double *buf);
OSSL_PARAM OSSL_PARAM_construct_utf8_string(const char *key, char *buf,
                                            size_t bsize);
OSSL_PARAM OSSL_PARAM_construct_utf8_ptr(const char *key, char **buf,
                                         size_t bsize);
OSSL_PARAM OSSL_PARAM_construct_octet_string(const char *key, void *buf,
                                             size_t bsize);
OSSL_PARAM OSSL_PARAM_construct_octet_ptr(const char *key, void **buf,
                                          size_t bsize);
OSSL_PARAM OSSL_PARAM_construct_end(void);
int OSSL_PARAM_allocate_from_text(OSSL_PARAM *to,
                                  const OSSL_PARAM *paramdefs,
                                  const char *key, const char *value,
                                  size_t value_n, int *found);
int OSSL_PARAM_get_int(const OSSL_PARAM *p, int *val);
int OSSL_PARAM_get_uint(const OSSL_PARAM *p, unsigned int *val);
int OSSL_PARAM_get_long(const OSSL_PARAM *p, long int *val);
int OSSL_PARAM_get_ulong(const OSSL_PARAM *p, unsigned long int *val);
int OSSL_PARAM_get_int32(const OSSL_PARAM *p, int32_t *val);
int OSSL_PARAM_get_uint32(const OSSL_PARAM *p, uint32_t *val);
int OSSL_PARAM_get_int64(const OSSL_PARAM *p, int64_t *val);
int OSSL_PARAM_get_uint64(const OSSL_PARAM *p, uint64_t *val);
int OSSL_PARAM_get_size_t(const OSSL_PARAM *p, size_t *val);
int OSSL_PARAM_get_time_t(const OSSL_PARAM *p, time_t *val);
int OSSL_PARAM_set_int(OSSL_PARAM *p, int val);
int OSSL_PARAM_set_uint(OSSL_PARAM *p, unsigned int val);
int OSSL_PARAM_set_long(OSSL_PARAM *p, long int val);
int OSSL_PARAM_set_ulong(OSSL_PARAM *p, unsigned long int val);
int OSSL_PARAM_set_int32(OSSL_PARAM *p, int32_t val);
int OSSL_PARAM_set_uint32(OSSL_PARAM *p, uint32_t val);
int OSSL_PARAM_set_int64(OSSL_PARAM *p, int64_t val);
int OSSL_PARAM_set_uint64(OSSL_PARAM *p, uint64_t val);
int OSSL_PARAM_set_size_t(OSSL_PARAM *p, size_t val);
int OSSL_PARAM_set_time_t(OSSL_PARAM *p, time_t val);
int OSSL_PARAM_get_double(const OSSL_PARAM *p, double *val);
int OSSL_PARAM_set_double(OSSL_PARAM *p, double val);
int OSSL_PARAM_get_BN(const OSSL_PARAM *p, BIGNUM **val);
int OSSL_PARAM_set_BN(OSSL_PARAM *p, const BIGNUM *val);
int OSSL_PARAM_get_utf8_string(const OSSL_PARAM *p, char **val, size_t max_len);
int OSSL_PARAM_set_utf8_string(OSSL_PARAM *p, const char *val);
int OSSL_PARAM_get_octet_string(const OSSL_PARAM *p, void **val, size_t max_len,
                                size_t *used_len);
int OSSL_PARAM_set_octet_string(OSSL_PARAM *p, const void *val, size_t len);
int OSSL_PARAM_get_utf8_ptr(const OSSL_PARAM *p, const char **val);
int OSSL_PARAM_set_utf8_ptr(OSSL_PARAM *p, const char *val);
int OSSL_PARAM_get_octet_ptr(const OSSL_PARAM *p, const void **val,
                             size_t *used_len);
int OSSL_PARAM_set_octet_ptr(OSSL_PARAM *p, const void *val,
                             size_t used_len);
int OSSL_PARAM_get_utf8_string_ptr(const OSSL_PARAM *p, const char **val);
int OSSL_PARAM_get_octet_string_ptr(const OSSL_PARAM *p, const void **val,
                                    size_t *used_len);
int OSSL_PARAM_modified(const OSSL_PARAM *p);
void OSSL_PARAM_set_all_unmodified(OSSL_PARAM *p);
OSSL_PARAM *OSSL_PARAM_dup(const OSSL_PARAM *p);
OSSL_PARAM *OSSL_PARAM_merge(const OSSL_PARAM *p1, const OSSL_PARAM *p2);
void OSSL_PARAM_free(OSSL_PARAM *p);
        
        
        
        
struct stack_st_X509_ALGOR; typedef int (*sk_X509_ALGOR_compfunc)(const X509_ALGOR * const *a, const X509_ALGOR *const *b); typedef void (*sk_X509_ALGOR_freefunc)(X509_ALGOR *a); typedef X509_ALGOR * (*sk_X509_ALGOR_copyfunc)(const X509_ALGOR *a); static __attribute__((unused)) inline X509_ALGOR *ossl_check_X509_ALGOR_type(X509_ALGOR *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_X509_ALGOR_sk_type(const struct stack_st_X509_ALGOR *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_X509_ALGOR_sk_type(struct stack_st_X509_ALGOR *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_X509_ALGOR_compfunc_type(sk_X509_ALGOR_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_X509_ALGOR_copyfunc_type(sk_X509_ALGOR_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_X509_ALGOR_freefunc_type(sk_X509_ALGOR_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct ASN1_ENCODING_st {
    unsigned char *enc;
    long len;
    int modified;
} ASN1_ENCODING;
struct asn1_string_table_st {
    int nid;
    long minsize;
    long maxsize;
    unsigned long mask;
    unsigned long flags;
};
struct stack_st_ASN1_STRING_TABLE; typedef int (*sk_ASN1_STRING_TABLE_compfunc)(const ASN1_STRING_TABLE * const *a, const ASN1_STRING_TABLE *const *b); typedef void (*sk_ASN1_STRING_TABLE_freefunc)(ASN1_STRING_TABLE *a); typedef ASN1_STRING_TABLE * (*sk_ASN1_STRING_TABLE_copyfunc)(const ASN1_STRING_TABLE *a); static __attribute__((unused)) inline ASN1_STRING_TABLE *ossl_check_ASN1_STRING_TABLE_type(ASN1_STRING_TABLE *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_STRING_TABLE_sk_type(const struct stack_st_ASN1_STRING_TABLE *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_STRING_TABLE_sk_type(struct stack_st_ASN1_STRING_TABLE *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_STRING_TABLE_compfunc_type(sk_ASN1_STRING_TABLE_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_STRING_TABLE_copyfunc_type(sk_ASN1_STRING_TABLE_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_STRING_TABLE_freefunc_type(sk_ASN1_STRING_TABLE_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef struct ASN1_TEMPLATE_st ASN1_TEMPLATE;
typedef struct ASN1_TLC_st ASN1_TLC;
typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef void *d2i_of_void(void **, const unsigned char **, long);
typedef int i2d_of_void(const void *, unsigned char **);
typedef const ASN1_ITEM *ASN1_ITEM_EXP (void);
struct asn1_type_st {
    int type;
    union {
        char *ptr;
        ASN1_BOOLEAN boolean;
        ASN1_STRING *asn1_string;
        ASN1_OBJECT *object;
        ASN1_INTEGER *integer;
        ASN1_ENUMERATED *enumerated;
        ASN1_BIT_STRING *bit_string;
        ASN1_OCTET_STRING *octet_string;
        ASN1_PRINTABLESTRING *printablestring;
        ASN1_T61STRING *t61string;
        ASN1_IA5STRING *ia5string;
        ASN1_GENERALSTRING *generalstring;
        ASN1_BMPSTRING *bmpstring;
        ASN1_UNIVERSALSTRING *universalstring;
        ASN1_UTCTIME *utctime;
        ASN1_GENERALIZEDTIME *generalizedtime;
        ASN1_VISIBLESTRING *visiblestring;
        ASN1_UTF8STRING *utf8string;
        ASN1_STRING *set;
        ASN1_STRING *sequence;
        ASN1_VALUE *asn1_value;
    } value;
};
struct stack_st_ASN1_TYPE; typedef int (*sk_ASN1_TYPE_compfunc)(const ASN1_TYPE * const *a, const ASN1_TYPE *const *b); typedef void (*sk_ASN1_TYPE_freefunc)(ASN1_TYPE *a); typedef ASN1_TYPE * (*sk_ASN1_TYPE_copyfunc)(const ASN1_TYPE *a); static __attribute__((unused)) inline ASN1_TYPE *ossl_check_ASN1_TYPE_type(ASN1_TYPE *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_TYPE_sk_type(const struct stack_st_ASN1_TYPE *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_TYPE_sk_type(struct stack_st_ASN1_TYPE *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_TYPE_compfunc_type(sk_ASN1_TYPE_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_TYPE_copyfunc_type(sk_ASN1_TYPE_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_TYPE_freefunc_type(sk_ASN1_TYPE_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
typedef struct stack_st_ASN1_TYPE ASN1_SEQUENCE_ANY;
extern ASN1_SEQUENCE_ANY *d2i_ASN1_SEQUENCE_ANY(ASN1_SEQUENCE_ANY **a, const unsigned char **in, long len); extern int i2d_ASN1_SEQUENCE_ANY(const ASN1_SEQUENCE_ANY *a, unsigned char **out); extern const ASN1_ITEM * ASN1_SEQUENCE_ANY_it(void);
extern ASN1_SEQUENCE_ANY *d2i_ASN1_SET_ANY(ASN1_SEQUENCE_ANY **a, const unsigned char **in, long len); extern int i2d_ASN1_SET_ANY(const ASN1_SEQUENCE_ANY *a, unsigned char **out); extern const ASN1_ITEM * ASN1_SET_ANY_it(void);
typedef struct BIT_STRING_BITNAME_st {
    int bitnum;
    const char *lname;
    const char *sname;
} BIT_STRING_BITNAME;
extern ASN1_TYPE *ASN1_TYPE_new(void); extern void ASN1_TYPE_free(ASN1_TYPE *a);
extern ASN1_TYPE *d2i_ASN1_TYPE(ASN1_TYPE **a, const unsigned char **in, long len); extern int i2d_ASN1_TYPE(const ASN1_TYPE *a, unsigned char **out); extern const ASN1_ITEM * ASN1_ANY_it(void);
int ASN1_TYPE_get(const ASN1_TYPE *a);
void ASN1_TYPE_set(ASN1_TYPE *a, int type, void *value);
int ASN1_TYPE_set1(ASN1_TYPE *a, int type, const void *value);
int ASN1_TYPE_cmp(const ASN1_TYPE *a, const ASN1_TYPE *b);
ASN1_TYPE *ASN1_TYPE_pack_sequence(const ASN1_ITEM *it, void *s, ASN1_TYPE **t);
void *ASN1_TYPE_unpack_sequence(const ASN1_ITEM *it, const ASN1_TYPE *t);
struct stack_st_ASN1_OBJECT; typedef int (*sk_ASN1_OBJECT_compfunc)(const ASN1_OBJECT * const *a, const ASN1_OBJECT *const *b); typedef void (*sk_ASN1_OBJECT_freefunc)(ASN1_OBJECT *a); typedef ASN1_OBJECT * (*sk_ASN1_OBJECT_copyfunc)(const ASN1_OBJECT *a); static __attribute__((unused)) inline ASN1_OBJECT *ossl_check_ASN1_OBJECT_type(ASN1_OBJECT *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_OBJECT_sk_type(const struct stack_st_ASN1_OBJECT *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_OBJECT_sk_type(struct stack_st_ASN1_OBJECT *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_OBJECT_compfunc_type(sk_ASN1_OBJECT_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_OBJECT_copyfunc_type(sk_ASN1_OBJECT_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_OBJECT_freefunc_type(sk_ASN1_OBJECT_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
extern ASN1_OBJECT *ASN1_OBJECT_new(void); extern void ASN1_OBJECT_free(ASN1_OBJECT *a); extern ASN1_OBJECT *d2i_ASN1_OBJECT(ASN1_OBJECT **a, const unsigned char **in, long len); extern int i2d_ASN1_OBJECT(const ASN1_OBJECT *a, unsigned char **out); extern const ASN1_ITEM * ASN1_OBJECT_it(void);
ASN1_STRING *ASN1_STRING_new(void);
void ASN1_STRING_free(ASN1_STRING *a);
void ASN1_STRING_clear_free(ASN1_STRING *a);
int ASN1_STRING_copy(ASN1_STRING *dst, const ASN1_STRING *str);
extern ASN1_STRING *ASN1_STRING_dup(const ASN1_STRING *a);
ASN1_STRING *ASN1_STRING_type_new(int type);
int ASN1_STRING_cmp(const ASN1_STRING *a, const ASN1_STRING *b);
int ASN1_STRING_set(ASN1_STRING *str, const void *data, int len);
void ASN1_STRING_set0(ASN1_STRING *str, void *data, int len);
int ASN1_STRING_length(const ASN1_STRING *x);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void ASN1_STRING_length_set(ASN1_STRING *x, int n);
int ASN1_STRING_type(const ASN1_STRING *x);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) unsigned char *ASN1_STRING_data(ASN1_STRING *x);
const unsigned char *ASN1_STRING_get0_data(const ASN1_STRING *x);
extern ASN1_BIT_STRING *ASN1_BIT_STRING_new(void); extern void ASN1_BIT_STRING_free(ASN1_BIT_STRING *a); extern ASN1_BIT_STRING *d2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_BIT_STRING(const ASN1_BIT_STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_BIT_STRING_it(void);
int ASN1_BIT_STRING_set(ASN1_BIT_STRING *a, unsigned char *d, int length);
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a, int n, int value);
int ASN1_BIT_STRING_get_bit(const ASN1_BIT_STRING *a, int n);
int ASN1_BIT_STRING_check(const ASN1_BIT_STRING *a,
                          const unsigned char *flags, int flags_len);
int ASN1_BIT_STRING_name_print(BIO *out, ASN1_BIT_STRING *bs,
                               BIT_STRING_BITNAME *tbl, int indent);
int ASN1_BIT_STRING_num_asc(const char *name, BIT_STRING_BITNAME *tbl);
int ASN1_BIT_STRING_set_asc(ASN1_BIT_STRING *bs, const char *name, int value,
                            BIT_STRING_BITNAME *tbl);
struct stack_st_ASN1_INTEGER; typedef int (*sk_ASN1_INTEGER_compfunc)(const ASN1_INTEGER * const *a, const ASN1_INTEGER *const *b); typedef void (*sk_ASN1_INTEGER_freefunc)(ASN1_INTEGER *a); typedef ASN1_INTEGER * (*sk_ASN1_INTEGER_copyfunc)(const ASN1_INTEGER *a); static __attribute__((unused)) inline ASN1_INTEGER *ossl_check_ASN1_INTEGER_type(ASN1_INTEGER *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_INTEGER_sk_type(const struct stack_st_ASN1_INTEGER *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_INTEGER_sk_type(struct stack_st_ASN1_INTEGER *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_INTEGER_compfunc_type(sk_ASN1_INTEGER_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_INTEGER_copyfunc_type(sk_ASN1_INTEGER_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_INTEGER_freefunc_type(sk_ASN1_INTEGER_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
extern ASN1_INTEGER *ASN1_INTEGER_new(void); extern void ASN1_INTEGER_free(ASN1_INTEGER *a); extern ASN1_INTEGER *d2i_ASN1_INTEGER(ASN1_INTEGER **a, const unsigned char **in, long len); extern int i2d_ASN1_INTEGER(const ASN1_INTEGER *a, unsigned char **out); extern const ASN1_ITEM * ASN1_INTEGER_it(void);
ASN1_INTEGER *d2i_ASN1_UINTEGER(ASN1_INTEGER **a, const unsigned char **pp,
                                long length);
extern ASN1_INTEGER *ASN1_INTEGER_dup(const ASN1_INTEGER *a);
int ASN1_INTEGER_cmp(const ASN1_INTEGER *x, const ASN1_INTEGER *y);
extern ASN1_ENUMERATED *ASN1_ENUMERATED_new(void); extern void ASN1_ENUMERATED_free(ASN1_ENUMERATED *a); extern ASN1_ENUMERATED *d2i_ASN1_ENUMERATED(ASN1_ENUMERATED **a, const unsigned char **in, long len); extern int i2d_ASN1_ENUMERATED(const ASN1_ENUMERATED *a, unsigned char **out); extern const ASN1_ITEM * ASN1_ENUMERATED_it(void);
int ASN1_UTCTIME_check(const ASN1_UTCTIME *a);
ASN1_UTCTIME *ASN1_UTCTIME_set(ASN1_UTCTIME *s, time_t t);
ASN1_UTCTIME *ASN1_UTCTIME_adj(ASN1_UTCTIME *s, time_t t,
                               int offset_day, long offset_sec);
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s, const char *str);
int ASN1_UTCTIME_cmp_time_t(const ASN1_UTCTIME *s, time_t t);
int ASN1_GENERALIZEDTIME_check(const ASN1_GENERALIZEDTIME *a);
ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,
                                               time_t t);
ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,
                                               time_t t, int offset_day,
                                               long offset_sec);
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, const char *str);
int ASN1_TIME_diff(int *pday, int *psec,
                   const ASN1_TIME *from, const ASN1_TIME *to);
extern ASN1_OCTET_STRING *ASN1_OCTET_STRING_new(void); extern void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a); extern ASN1_OCTET_STRING *d2i_ASN1_OCTET_STRING(ASN1_OCTET_STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_OCTET_STRING(const ASN1_OCTET_STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_OCTET_STRING_it(void);
extern ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(const ASN1_OCTET_STRING *a);
int ASN1_OCTET_STRING_cmp(const ASN1_OCTET_STRING *a,
                          const ASN1_OCTET_STRING *b);
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *str, const unsigned char *data,
                          int len);
struct stack_st_ASN1_UTF8STRING; typedef int (*sk_ASN1_UTF8STRING_compfunc)(const ASN1_UTF8STRING * const *a, const ASN1_UTF8STRING *const *b); typedef void (*sk_ASN1_UTF8STRING_freefunc)(ASN1_UTF8STRING *a); typedef ASN1_UTF8STRING * (*sk_ASN1_UTF8STRING_copyfunc)(const ASN1_UTF8STRING *a); static __attribute__((unused)) inline ASN1_UTF8STRING *ossl_check_ASN1_UTF8STRING_type(ASN1_UTF8STRING *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_UTF8STRING_sk_type(const struct stack_st_ASN1_UTF8STRING *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_UTF8STRING_sk_type(struct stack_st_ASN1_UTF8STRING *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_UTF8STRING_compfunc_type(sk_ASN1_UTF8STRING_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_UTF8STRING_copyfunc_type(sk_ASN1_UTF8STRING_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_UTF8STRING_freefunc_type(sk_ASN1_UTF8STRING_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
extern ASN1_VISIBLESTRING *ASN1_VISIBLESTRING_new(void); extern void ASN1_VISIBLESTRING_free(ASN1_VISIBLESTRING *a); extern ASN1_VISIBLESTRING *d2i_ASN1_VISIBLESTRING(ASN1_VISIBLESTRING **a, const unsigned char **in, long len); extern int i2d_ASN1_VISIBLESTRING(const ASN1_VISIBLESTRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_VISIBLESTRING_it(void);
extern ASN1_UNIVERSALSTRING *ASN1_UNIVERSALSTRING_new(void); extern void ASN1_UNIVERSALSTRING_free(ASN1_UNIVERSALSTRING *a); extern ASN1_UNIVERSALSTRING *d2i_ASN1_UNIVERSALSTRING(ASN1_UNIVERSALSTRING **a, const unsigned char **in, long len); extern int i2d_ASN1_UNIVERSALSTRING(const ASN1_UNIVERSALSTRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_UNIVERSALSTRING_it(void);
extern ASN1_UTF8STRING *ASN1_UTF8STRING_new(void); extern void ASN1_UTF8STRING_free(ASN1_UTF8STRING *a); extern ASN1_UTF8STRING *d2i_ASN1_UTF8STRING(ASN1_UTF8STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_UTF8STRING(const ASN1_UTF8STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_UTF8STRING_it(void);
extern ASN1_NULL *ASN1_NULL_new(void); extern void ASN1_NULL_free(ASN1_NULL *a); extern ASN1_NULL *d2i_ASN1_NULL(ASN1_NULL **a, const unsigned char **in, long len); extern int i2d_ASN1_NULL(const ASN1_NULL *a, unsigned char **out); extern const ASN1_ITEM * ASN1_NULL_it(void);
extern ASN1_BMPSTRING *ASN1_BMPSTRING_new(void); extern void ASN1_BMPSTRING_free(ASN1_BMPSTRING *a); extern ASN1_BMPSTRING *d2i_ASN1_BMPSTRING(ASN1_BMPSTRING **a, const unsigned char **in, long len); extern int i2d_ASN1_BMPSTRING(const ASN1_BMPSTRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_BMPSTRING_it(void);
int UTF8_getc(const unsigned char *str, int len, unsigned long *val);
int UTF8_putc(unsigned char *str, int len, unsigned long value);
struct stack_st_ASN1_GENERALSTRING; typedef int (*sk_ASN1_GENERALSTRING_compfunc)(const ASN1_GENERALSTRING * const *a, const ASN1_GENERALSTRING *const *b); typedef void (*sk_ASN1_GENERALSTRING_freefunc)(ASN1_GENERALSTRING *a); typedef ASN1_GENERALSTRING * (*sk_ASN1_GENERALSTRING_copyfunc)(const ASN1_GENERALSTRING *a); static __attribute__((unused)) inline ASN1_GENERALSTRING *ossl_check_ASN1_GENERALSTRING_type(ASN1_GENERALSTRING *ptr) { return ptr; } static __attribute__((unused)) inline const OPENSSL_STACK *ossl_check_const_ASN1_GENERALSTRING_sk_type(const struct stack_st_ASN1_GENERALSTRING *sk) { return (const OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_STACK *ossl_check_ASN1_GENERALSTRING_sk_type(struct stack_st_ASN1_GENERALSTRING *sk) { return (OPENSSL_STACK *)sk; } static __attribute__((unused)) inline OPENSSL_sk_compfunc ossl_check_ASN1_GENERALSTRING_compfunc_type(sk_ASN1_GENERALSTRING_compfunc cmp) { return (OPENSSL_sk_compfunc)cmp; } static __attribute__((unused)) inline OPENSSL_sk_copyfunc ossl_check_ASN1_GENERALSTRING_copyfunc_type(sk_ASN1_GENERALSTRING_copyfunc cpy) { return (OPENSSL_sk_copyfunc)cpy; } static __attribute__((unused)) inline OPENSSL_sk_freefunc ossl_check_ASN1_GENERALSTRING_freefunc_type(sk_ASN1_GENERALSTRING_freefunc fr) { return (OPENSSL_sk_freefunc)fr; }
extern ASN1_STRING *ASN1_PRINTABLE_new(void); extern void ASN1_PRINTABLE_free(ASN1_STRING *a); extern ASN1_STRING *d2i_ASN1_PRINTABLE(ASN1_STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_PRINTABLE(const ASN1_STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_PRINTABLE_it(void);
extern ASN1_STRING *DIRECTORYSTRING_new(void); extern void DIRECTORYSTRING_free(ASN1_STRING *a); extern ASN1_STRING *d2i_DIRECTORYSTRING(ASN1_STRING **a, const unsigned char **in, long len); extern int i2d_DIRECTORYSTRING(const ASN1_STRING *a, unsigned char **out); extern const ASN1_ITEM * DIRECTORYSTRING_it(void);
extern ASN1_STRING *DISPLAYTEXT_new(void); extern void DISPLAYTEXT_free(ASN1_STRING *a); extern ASN1_STRING *d2i_DISPLAYTEXT(ASN1_STRING **a, const unsigned char **in, long len); extern int i2d_DISPLAYTEXT(const ASN1_STRING *a, unsigned char **out); extern const ASN1_ITEM * DISPLAYTEXT_it(void);
extern ASN1_PRINTABLESTRING *ASN1_PRINTABLESTRING_new(void); extern void ASN1_PRINTABLESTRING_free(ASN1_PRINTABLESTRING *a); extern ASN1_PRINTABLESTRING *d2i_ASN1_PRINTABLESTRING(ASN1_PRINTABLESTRING **a, const unsigned char **in, long len); extern int i2d_ASN1_PRINTABLESTRING(const ASN1_PRINTABLESTRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_PRINTABLESTRING_it(void);
extern ASN1_T61STRING *ASN1_T61STRING_new(void); extern void ASN1_T61STRING_free(ASN1_T61STRING *a); extern ASN1_T61STRING *d2i_ASN1_T61STRING(ASN1_T61STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_T61STRING(const ASN1_T61STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_T61STRING_it(void);
extern ASN1_IA5STRING *ASN1_IA5STRING_new(void); extern void ASN1_IA5STRING_free(ASN1_IA5STRING *a); extern ASN1_IA5STRING *d2i_ASN1_IA5STRING(ASN1_IA5STRING **a, const unsigned char **in, long len); extern int i2d_ASN1_IA5STRING(const ASN1_IA5STRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_IA5STRING_it(void);
extern ASN1_GENERALSTRING *ASN1_GENERALSTRING_new(void); extern void ASN1_GENERALSTRING_free(ASN1_GENERALSTRING *a); extern ASN1_GENERALSTRING *d2i_ASN1_GENERALSTRING(ASN1_GENERALSTRING **a, const unsigned char **in, long len); extern int i2d_ASN1_GENERALSTRING(const ASN1_GENERALSTRING *a, unsigned char **out); extern const ASN1_ITEM * ASN1_GENERALSTRING_it(void);
extern ASN1_UTCTIME *ASN1_UTCTIME_new(void); extern void ASN1_UTCTIME_free(ASN1_UTCTIME *a); extern ASN1_UTCTIME *d2i_ASN1_UTCTIME(ASN1_UTCTIME **a, const unsigned char **in, long len); extern int i2d_ASN1_UTCTIME(const ASN1_UTCTIME *a, unsigned char **out); extern const ASN1_ITEM * ASN1_UTCTIME_it(void);
extern ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_new(void); extern void ASN1_GENERALIZEDTIME_free(ASN1_GENERALIZEDTIME *a); extern ASN1_GENERALIZEDTIME *d2i_ASN1_GENERALIZEDTIME(ASN1_GENERALIZEDTIME **a, const unsigned char **in, long len); extern int i2d_ASN1_GENERALIZEDTIME(const ASN1_GENERALIZEDTIME *a, unsigned char **out); extern const ASN1_ITEM * ASN1_GENERALIZEDTIME_it(void);
extern ASN1_TIME *ASN1_TIME_new(void); extern void ASN1_TIME_free(ASN1_TIME *a); extern ASN1_TIME *d2i_ASN1_TIME(ASN1_TIME **a, const unsigned char **in, long len); extern int i2d_ASN1_TIME(const ASN1_TIME *a, unsigned char **out); extern const ASN1_ITEM * ASN1_TIME_it(void);
extern ASN1_TIME *ASN1_TIME_dup(const ASN1_TIME *a);
extern ASN1_UTCTIME *ASN1_UTCTIME_dup(const ASN1_UTCTIME *a);
extern ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_dup(const ASN1_GENERALIZEDTIME *a);
extern const ASN1_ITEM * ASN1_OCTET_STRING_NDEF_it(void);
ASN1_TIME *ASN1_TIME_set(ASN1_TIME *s, time_t t);
ASN1_TIME *ASN1_TIME_adj(ASN1_TIME *s, time_t t,
                         int offset_day, long offset_sec);
int ASN1_TIME_check(const ASN1_TIME *t);
ASN1_GENERALIZEDTIME *ASN1_TIME_to_generalizedtime(const ASN1_TIME *t,
                                                   ASN1_GENERALIZEDTIME **out);
int ASN1_TIME_set_string(ASN1_TIME *s, const char *str);
int ASN1_TIME_set_string_X509(ASN1_TIME *s, const char *str);
int ASN1_TIME_to_tm(const ASN1_TIME *s, struct tm *tm);
int ASN1_TIME_normalize(ASN1_TIME *s);
int ASN1_TIME_cmp_time_t(const ASN1_TIME *s, time_t t);
int ASN1_TIME_compare(const ASN1_TIME *a, const ASN1_TIME *b);
int i2a_ASN1_INTEGER(BIO *bp, const ASN1_INTEGER *a);
int a2i_ASN1_INTEGER(BIO *bp, ASN1_INTEGER *bs, char *buf, int size);
int i2a_ASN1_ENUMERATED(BIO *bp, const ASN1_ENUMERATED *a);
int a2i_ASN1_ENUMERATED(BIO *bp, ASN1_ENUMERATED *bs, char *buf, int size);
int i2a_ASN1_OBJECT(BIO *bp, const ASN1_OBJECT *a);
int a2i_ASN1_STRING(BIO *bp, ASN1_STRING *bs, char *buf, int size);
int i2a_ASN1_STRING(BIO *bp, const ASN1_STRING *a, int type);
int i2t_ASN1_OBJECT(char *buf, int buf_len, const ASN1_OBJECT *a);
int a2d_ASN1_OBJECT(unsigned char *out, int olen, const char *buf, int num);
ASN1_OBJECT *ASN1_OBJECT_create(int nid, unsigned char *data, int len,
                                const char *sn, const char *ln);
int ASN1_INTEGER_get_int64(int64_t *pr, const ASN1_INTEGER *a);
int ASN1_INTEGER_set_int64(ASN1_INTEGER *a, int64_t r);
int ASN1_INTEGER_get_uint64(uint64_t *pr, const ASN1_INTEGER *a);
int ASN1_INTEGER_set_uint64(ASN1_INTEGER *a, uint64_t r);
int ASN1_INTEGER_set(ASN1_INTEGER *a, long v);
long ASN1_INTEGER_get(const ASN1_INTEGER *a);
ASN1_INTEGER *BN_to_ASN1_INTEGER(const BIGNUM *bn, ASN1_INTEGER *ai);
BIGNUM *ASN1_INTEGER_to_BN(const ASN1_INTEGER *ai, BIGNUM *bn);
int ASN1_ENUMERATED_get_int64(int64_t *pr, const ASN1_ENUMERATED *a);
int ASN1_ENUMERATED_set_int64(ASN1_ENUMERATED *a, int64_t r);
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a, long v);
long ASN1_ENUMERATED_get(const ASN1_ENUMERATED *a);
ASN1_ENUMERATED *BN_to_ASN1_ENUMERATED(const BIGNUM *bn, ASN1_ENUMERATED *ai);
BIGNUM *ASN1_ENUMERATED_to_BN(const ASN1_ENUMERATED *ai, BIGNUM *bn);
int ASN1_PRINTABLE_type(const unsigned char *s, int max);
unsigned long ASN1_tag2bit(int tag);
int ASN1_get_object(const unsigned char **pp, long *plength, int *ptag,
                    int *pclass, long omax);
int ASN1_check_infinite_end(unsigned char **p, long len);
int ASN1_const_check_infinite_end(const unsigned char **p, long len);
void ASN1_put_object(unsigned char **pp, int constructed, int length,
                     int tag, int xclass);
int ASN1_put_eoc(unsigned char **pp);
int ASN1_object_size(int constructed, int length, int tag);
void *ASN1_dup(i2d_of_void *i2d, d2i_of_void *d2i, const void *x);
void *ASN1_item_dup(const ASN1_ITEM *it, const void *x);
int ASN1_item_sign_ex(const ASN1_ITEM *it, X509_ALGOR *algor1,
                      X509_ALGOR *algor2, ASN1_BIT_STRING *signature,
                      const void *data, const ASN1_OCTET_STRING *id,
                      EVP_PKEY *pkey, const EVP_MD *md, OSSL_LIB_CTX *libctx,
                      const char *propq);
int ASN1_item_verify_ex(const ASN1_ITEM *it, const X509_ALGOR *alg,
                        const ASN1_BIT_STRING *signature, const void *data,
                        const ASN1_OCTET_STRING *id, EVP_PKEY *pkey,
                        OSSL_LIB_CTX *libctx, const char *propq);
void *ASN1_d2i_fp(void *(*xnew) (void), d2i_of_void *d2i, FILE *in, void **x);
void *ASN1_item_d2i_fp_ex(const ASN1_ITEM *it, FILE *in, void *x,
                          OSSL_LIB_CTX *libctx, const char *propq);
void *ASN1_item_d2i_fp(const ASN1_ITEM *it, FILE *in, void *x);
int ASN1_i2d_fp(i2d_of_void *i2d, FILE *out, const void *x);
int ASN1_item_i2d_fp(const ASN1_ITEM *it, FILE *out, const void *x);
int ASN1_STRING_print_ex_fp(FILE *fp, const ASN1_STRING *str, unsigned long flags);
int ASN1_STRING_to_UTF8(unsigned char **out, const ASN1_STRING *in);
void *ASN1_d2i_bio(void *(*xnew) (void), d2i_of_void *d2i, BIO *in, void **x);
void *ASN1_item_d2i_bio_ex(const ASN1_ITEM *it, BIO *in, void *pval,
                           OSSL_LIB_CTX *libctx, const char *propq);
void *ASN1_item_d2i_bio(const ASN1_ITEM *it, BIO *in, void *pval);
int ASN1_i2d_bio(i2d_of_void *i2d, BIO *out, const void *x);
int ASN1_item_i2d_bio(const ASN1_ITEM *it, BIO *out, const void *x);
BIO *ASN1_item_i2d_mem_bio(const ASN1_ITEM *it, const ASN1_VALUE *val);
int ASN1_UTCTIME_print(BIO *fp, const ASN1_UTCTIME *a);
int ASN1_GENERALIZEDTIME_print(BIO *fp, const ASN1_GENERALIZEDTIME *a);
int ASN1_TIME_print(BIO *bp, const ASN1_TIME *tm);
int ASN1_TIME_print_ex(BIO *bp, const ASN1_TIME *tm, unsigned long flags);
int ASN1_STRING_print(BIO *bp, const ASN1_STRING *v);
int ASN1_STRING_print_ex(BIO *out, const ASN1_STRING *str, unsigned long flags);
int ASN1_buf_print(BIO *bp, const unsigned char *buf, size_t buflen, int off);
int ASN1_bn_print(BIO *bp, const char *number, const BIGNUM *num,
                  unsigned char *buf, int off);
int ASN1_parse(BIO *bp, const unsigned char *pp, long len, int indent);
int ASN1_parse_dump(BIO *bp, const unsigned char *pp, long len, int indent,
                    int dump);
const char *ASN1_tag2str(int tag);
int ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s);
int ASN1_TYPE_set_octetstring(ASN1_TYPE *a, unsigned char *data, int len);
int ASN1_TYPE_get_octetstring(const ASN1_TYPE *a, unsigned char *data, int max_len);
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a, long num,
                                  unsigned char *data, int len);
int ASN1_TYPE_get_int_octetstring(const ASN1_TYPE *a, long *num,
                                  unsigned char *data, int max_len);
void *ASN1_item_unpack(const ASN1_STRING *oct, const ASN1_ITEM *it);
ASN1_STRING *ASN1_item_pack(void *obj, const ASN1_ITEM *it,
                            ASN1_OCTET_STRING **oct);
void ASN1_STRING_set_default_mask(unsigned long mask);
int ASN1_STRING_set_default_mask_asc(const char *p);
unsigned long ASN1_STRING_get_default_mask(void);
int ASN1_mbstring_copy(ASN1_STRING **out, const unsigned char *in, int len,
                       int inform, unsigned long mask);
int ASN1_mbstring_ncopy(ASN1_STRING **out, const unsigned char *in, int len,
                        int inform, unsigned long mask,
                        long minsize, long maxsize);
ASN1_STRING *ASN1_STRING_set_by_NID(ASN1_STRING **out,
                                    const unsigned char *in, int inlen,
                                    int inform, int nid);
ASN1_STRING_TABLE *ASN1_STRING_TABLE_get(int nid);
int ASN1_STRING_TABLE_add(int, long, long, unsigned long, unsigned long);
void ASN1_STRING_TABLE_cleanup(void);
ASN1_VALUE *ASN1_item_new(const ASN1_ITEM *it);
ASN1_VALUE *ASN1_item_new_ex(const ASN1_ITEM *it, OSSL_LIB_CTX *libctx,
                             const char *propq);
void ASN1_item_free(ASN1_VALUE *val, const ASN1_ITEM *it);
ASN1_VALUE *ASN1_item_d2i_ex(ASN1_VALUE **val, const unsigned char **in,
                             long len, const ASN1_ITEM *it,
                             OSSL_LIB_CTX *libctx, const char *propq);
ASN1_VALUE *ASN1_item_d2i(ASN1_VALUE **val, const unsigned char **in,
                          long len, const ASN1_ITEM *it);
int ASN1_item_i2d(const ASN1_VALUE *val, unsigned char **out, const ASN1_ITEM *it);
int ASN1_item_ndef_i2d(const ASN1_VALUE *val, unsigned char **out,
                       const ASN1_ITEM *it);
void ASN1_add_oid_module(void);
void ASN1_add_stable_module(void);
ASN1_TYPE *ASN1_generate_nconf(const char *str, CONF *nconf);
ASN1_TYPE *ASN1_generate_v3(const char *str, X509V3_CTX *cnf);
int ASN1_str2mask(const char *str, unsigned long *pmask);
int ASN1_item_print(BIO *out, const ASN1_VALUE *ifld, int indent,
                    const ASN1_ITEM *it, const ASN1_PCTX *pctx);
ASN1_PCTX *ASN1_PCTX_new(void);
void ASN1_PCTX_free(ASN1_PCTX *p);
unsigned long ASN1_PCTX_get_flags(const ASN1_PCTX *p);
void ASN1_PCTX_set_flags(ASN1_PCTX *p, unsigned long flags);
unsigned long ASN1_PCTX_get_nm_flags(const ASN1_PCTX *p);
void ASN1_PCTX_set_nm_flags(ASN1_PCTX *p, unsigned long flags);
unsigned long ASN1_PCTX_get_cert_flags(const ASN1_PCTX *p);
void ASN1_PCTX_set_cert_flags(ASN1_PCTX *p, unsigned long flags);
unsigned long ASN1_PCTX_get_oid_flags(const ASN1_PCTX *p);
void ASN1_PCTX_set_oid_flags(ASN1_PCTX *p, unsigned long flags);
unsigned long ASN1_PCTX_get_str_flags(const ASN1_PCTX *p);
void ASN1_PCTX_set_str_flags(ASN1_PCTX *p, unsigned long flags);
ASN1_SCTX *ASN1_SCTX_new(int (*scan_cb) (ASN1_SCTX *ctx));
void ASN1_SCTX_free(ASN1_SCTX *p);
const ASN1_ITEM *ASN1_SCTX_get_item(ASN1_SCTX *p);
const ASN1_TEMPLATE *ASN1_SCTX_get_template(ASN1_SCTX *p);
unsigned long ASN1_SCTX_get_flags(ASN1_SCTX *p);
void ASN1_SCTX_set_app_data(ASN1_SCTX *p, void *data);
void *ASN1_SCTX_get_app_data(ASN1_SCTX *p);
const BIO_METHOD *BIO_f_asn1(void);
BIO *BIO_new_NDEF(BIO *out, ASN1_VALUE *val, const ASN1_ITEM *it);
int i2d_ASN1_bio_stream(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
                        const ASN1_ITEM *it);
int PEM_write_bio_ASN1_stream(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
                              const char *hdr, const ASN1_ITEM *it);
int SMIME_write_ASN1(BIO *bio, ASN1_VALUE *val, BIO *data, int flags,
                     int ctype_nid, int econt_nid,
                     struct stack_st_X509_ALGOR *mdalgs, const ASN1_ITEM *it);
int SMIME_write_ASN1_ex(BIO *bio, ASN1_VALUE *val, BIO *data, int flags,
                        int ctype_nid, int econt_nid,
                        struct stack_st_X509_ALGOR *mdalgs, const ASN1_ITEM *it,
                        OSSL_LIB_CTX *libctx, const char *propq);
ASN1_VALUE *SMIME_read_ASN1(BIO *bio, BIO **bcont, const ASN1_ITEM *it);
ASN1_VALUE *SMIME_read_ASN1_ex(BIO *bio, int flags, BIO **bcont,
                               const ASN1_ITEM *it, ASN1_VALUE **x,
                               OSSL_LIB_CTX *libctx, const char *propq);
int SMIME_crlf_copy(BIO *in, BIO *out, int flags);
int SMIME_text(BIO *in, BIO *out);
const ASN1_ITEM *ASN1_ITEM_lookup(const char *name);
const ASN1_ITEM *ASN1_ITEM_get(size_t i);
        
typedef struct obj_name_st {
    int type;
    int alias;
    const char *name;
    const char *data;
} OBJ_NAME;
int OBJ_NAME_init(void);
int OBJ_NAME_new_index(unsigned long (*hash_func) (const char *),
                       int (*cmp_func) (const char *, const char *),
                       void (*free_func) (const char *, int, const char *));
const char *OBJ_NAME_get(const char *name, int type);
int OBJ_NAME_add(const char *name, int type, const char *data);
int OBJ_NAME_remove(const char *name, int type);
void OBJ_NAME_cleanup(int type);
void OBJ_NAME_do_all(int type, void (*fn) (const OBJ_NAME *, void *arg),
                     void *arg);
void OBJ_NAME_do_all_sorted(int type,
                            void (*fn) (const OBJ_NAME *, void *arg),
                            void *arg);
extern ASN1_OBJECT *OBJ_dup(const ASN1_OBJECT *a);
ASN1_OBJECT *OBJ_nid2obj(int n);
const char *OBJ_nid2ln(int n);
const char *OBJ_nid2sn(int n);
int OBJ_obj2nid(const ASN1_OBJECT *o);
ASN1_OBJECT *OBJ_txt2obj(const char *s, int no_name);
int OBJ_obj2txt(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name);
int OBJ_txt2nid(const char *s);
int OBJ_ln2nid(const char *s);
int OBJ_sn2nid(const char *s);
int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
const void *OBJ_bsearch_(const void *key, const void *base, int num, int size,
                         int (*cmp) (const void *, const void *));
const void *OBJ_bsearch_ex_(const void *key, const void *base, int num,
                            int size,
                            int (*cmp) (const void *, const void *),
                            int flags);
int OBJ_new_nid(int num);
int OBJ_add_object(const ASN1_OBJECT *obj);
int OBJ_create(const char *oid, const char *sn, const char *ln);
int OBJ_create_objects(BIO *in);
size_t OBJ_length(const ASN1_OBJECT *obj);
const unsigned char *OBJ_get0_data(const ASN1_OBJECT *obj);
int OBJ_find_sigid_algs(int signid, int *pdig_nid, int *ppkey_nid);
int OBJ_find_sigid_by_algs(int *psignid, int dig_nid, int pkey_nid);
int OBJ_add_sigid(int signid, int dig_id, int pkey_id);
void OBJ_sigid_free(void);
int EVP_set_default_properties(OSSL_LIB_CTX *libctx, const char *propq);
int EVP_default_properties_is_fips_enabled(OSSL_LIB_CTX *libctx);
int EVP_default_properties_enable_fips(OSSL_LIB_CTX *libctx, int enable);
__attribute__((deprecated("Since OpenSSL " "3.0"))) EVP_MD *EVP_MD_meth_new(int md_type, int pkey_type);
__attribute__((deprecated("Since OpenSSL " "3.0"))) EVP_MD *EVP_MD_meth_dup(const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_MD_meth_free(EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_input_blocksize(EVP_MD *md, int blocksize);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_result_size(EVP_MD *md, int resultsize);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_app_datasize(EVP_MD *md, int datasize);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_flags(EVP_MD *md, unsigned long flags);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_init(EVP_MD *md, int (*init)(EVP_MD_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_update(EVP_MD *md, int (*update)(EVP_MD_CTX *ctx,
                                                     const void *data,
                                                     size_t count));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_final(EVP_MD *md, int (*final)(EVP_MD_CTX *ctx,
                                                   unsigned char *md));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_copy(EVP_MD *md, int (*copy)(EVP_MD_CTX *to,
                                                 const EVP_MD_CTX *from));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_cleanup(EVP_MD *md, int (*cleanup)(EVP_MD_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_MD_meth_set_ctrl(EVP_MD *md, int (*ctrl)(EVP_MD_CTX *ctx, int cmd,
                                                 int p1, void *p2));
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_MD_meth_get_input_blocksize(const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_MD_meth_get_result_size(const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_MD_meth_get_app_datasize(const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0"))) unsigned long EVP_MD_meth_get_flags(const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_init(const EVP_MD *md))(EVP_MD_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_update(const EVP_MD *md))(EVP_MD_CTX *ctx,
                                                const void *data, size_t count);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_final(const EVP_MD *md))(EVP_MD_CTX *ctx,
                                               unsigned char *md);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_copy(const EVP_MD *md))(EVP_MD_CTX *to,
                                              const EVP_MD_CTX *from);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_cleanup(const EVP_MD *md))(EVP_MD_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_meth_get_ctrl(const EVP_MD *md))(EVP_MD_CTX *ctx, int cmd,
                                              int p1, void *p2);
__attribute__((deprecated("Since OpenSSL " "3.0")))
EVP_CIPHER *EVP_CIPHER_meth_new(int cipher_type, int block_size, int key_len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
EVP_CIPHER *EVP_CIPHER_meth_dup(const EVP_CIPHER *cipher);
__attribute__((deprecated("Since OpenSSL " "3.0")))
void EVP_CIPHER_meth_free(EVP_CIPHER *cipher);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_iv_length(EVP_CIPHER *cipher, int iv_len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_flags(EVP_CIPHER *cipher, unsigned long flags);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_impl_ctx_size(EVP_CIPHER *cipher, int ctx_size);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_init(EVP_CIPHER *cipher,
                             int (*init) (EVP_CIPHER_CTX *ctx,
                                          const unsigned char *key,
                                          const unsigned char *iv,
                                          int enc));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_do_cipher(EVP_CIPHER *cipher,
                                  int (*do_cipher) (EVP_CIPHER_CTX *ctx,
                                                    unsigned char *out,
                                                    const unsigned char *in,
                                                    size_t inl));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_cleanup(EVP_CIPHER *cipher,
                                int (*cleanup) (EVP_CIPHER_CTX *));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_set_asn1_params(EVP_CIPHER *cipher,
                                        int (*set_asn1_parameters) (EVP_CIPHER_CTX *,
                                                                    ASN1_TYPE *));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_get_asn1_params(EVP_CIPHER *cipher,
                                        int (*get_asn1_parameters) (EVP_CIPHER_CTX *,
                                                                    ASN1_TYPE *));
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_meth_set_ctrl(EVP_CIPHER *cipher,
                             int (*ctrl) (EVP_CIPHER_CTX *, int type,
                                          int arg, void *ptr));
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_init(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *ctx,
                                                      const unsigned char *key,
                                                      const unsigned char *iv,
                                                      int enc);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_do_cipher(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *ctx,
                                                           unsigned char *out,
                                                           const unsigned char *in,
                                                           size_t inl);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_cleanup(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_set_asn1_params(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *,
                                                                 ASN1_TYPE *);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_get_asn1_params(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *,
                                                                 ASN1_TYPE *);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int
(*EVP_CIPHER_meth_get_ctrl(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *, int type,
                                                      int arg, void *ptr);
typedef struct {
    unsigned char *out;
    const unsigned char *inp;
    size_t len;
    unsigned int interleave;
} EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM;
typedef struct evp_cipher_info_st {
    const EVP_CIPHER *cipher;
    unsigned char iv[16];
} EVP_CIPHER_INFO;
typedef int (EVP_PBE_KEYGEN) (EVP_CIPHER_CTX *ctx, const char *pass,
                              int passlen, ASN1_TYPE *param,
                              const EVP_CIPHER *cipher, const EVP_MD *md,
                              int en_de);
typedef int (EVP_PBE_KEYGEN_EX) (EVP_CIPHER_CTX *ctx, const char *pass,
                                 int passlen, ASN1_TYPE *param,
                                 const EVP_CIPHER *cipher, const EVP_MD *md,
                                 int en_de, OSSL_LIB_CTX *libctx, const char *propq);
int EVP_MD_get_type(const EVP_MD *md);
const char *EVP_MD_get0_name(const EVP_MD *md);
const char *EVP_MD_get0_description(const EVP_MD *md);
int EVP_MD_is_a(const EVP_MD *md, const char *name);
int EVP_MD_names_do_all(const EVP_MD *md,
                        void (*fn)(const char *name, void *data),
                        void *data);
const OSSL_PROVIDER *EVP_MD_get0_provider(const EVP_MD *md);
int EVP_MD_get_pkey_type(const EVP_MD *md);
int EVP_MD_get_size(const EVP_MD *md);
int EVP_MD_get_block_size(const EVP_MD *md);
unsigned long EVP_MD_get_flags(const EVP_MD *md);
const EVP_MD *EVP_MD_CTX_get0_md(const EVP_MD_CTX *ctx);
EVP_MD *EVP_MD_CTX_get1_md(EVP_MD_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const EVP_MD *EVP_MD_CTX_md(const EVP_MD_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int (*EVP_MD_CTX_update_fn(EVP_MD_CTX *ctx))(EVP_MD_CTX *ctx,
                                             const void *data, size_t count);
__attribute__((deprecated("Since OpenSSL " "3.0")))
void EVP_MD_CTX_set_update_fn(EVP_MD_CTX *ctx,
                              int (*update) (EVP_MD_CTX *ctx,
                                             const void *data, size_t count));
EVP_PKEY_CTX *EVP_MD_CTX_get_pkey_ctx(const EVP_MD_CTX *ctx);
void EVP_MD_CTX_set_pkey_ctx(EVP_MD_CTX *ctx, EVP_PKEY_CTX *pctx);
void *EVP_MD_CTX_get0_md_data(const EVP_MD_CTX *ctx);
int EVP_CIPHER_get_nid(const EVP_CIPHER *cipher);
const char *EVP_CIPHER_get0_name(const EVP_CIPHER *cipher);
const char *EVP_CIPHER_get0_description(const EVP_CIPHER *cipher);
int EVP_CIPHER_is_a(const EVP_CIPHER *cipher, const char *name);
int EVP_CIPHER_names_do_all(const EVP_CIPHER *cipher,
                            void (*fn)(const char *name, void *data),
                            void *data);
const OSSL_PROVIDER *EVP_CIPHER_get0_provider(const EVP_CIPHER *cipher);
int EVP_CIPHER_get_block_size(const EVP_CIPHER *cipher);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_CIPHER_impl_ctx_size(const EVP_CIPHER *cipher);
int EVP_CIPHER_get_key_length(const EVP_CIPHER *cipher);
int EVP_CIPHER_get_iv_length(const EVP_CIPHER *cipher);
unsigned long EVP_CIPHER_get_flags(const EVP_CIPHER *cipher);
int EVP_CIPHER_get_mode(const EVP_CIPHER *cipher);
int EVP_CIPHER_get_type(const EVP_CIPHER *cipher);
EVP_CIPHER *EVP_CIPHER_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                             const char *properties);
int EVP_CIPHER_up_ref(EVP_CIPHER *cipher);
void EVP_CIPHER_free(EVP_CIPHER *cipher);
const EVP_CIPHER *EVP_CIPHER_CTX_get0_cipher(const EVP_CIPHER_CTX *ctx);
EVP_CIPHER *EVP_CIPHER_CTX_get1_cipher(EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_is_encrypting(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_nid(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_block_size(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_key_length(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_iv_length(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_tag_length(const EVP_CIPHER_CTX *ctx);
const EVP_CIPHER *EVP_CIPHER_CTX_cipher(const EVP_CIPHER_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const unsigned char *EVP_CIPHER_CTX_iv(const EVP_CIPHER_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const unsigned char *EVP_CIPHER_CTX_original_iv(const EVP_CIPHER_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) unsigned char *EVP_CIPHER_CTX_iv_noconst(EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_updated_iv(EVP_CIPHER_CTX *ctx, void *buf, size_t len);
int EVP_CIPHER_CTX_get_original_iv(EVP_CIPHER_CTX *ctx, void *buf, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
unsigned char *EVP_CIPHER_CTX_buf_noconst(EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_num(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_set_num(EVP_CIPHER_CTX *ctx, int num);
int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out, const EVP_CIPHER_CTX *in);
void *EVP_CIPHER_CTX_get_app_data(const EVP_CIPHER_CTX *ctx);
void EVP_CIPHER_CTX_set_app_data(EVP_CIPHER_CTX *ctx, void *data);
void *EVP_CIPHER_CTX_get_cipher_data(const EVP_CIPHER_CTX *ctx);
void *EVP_CIPHER_CTX_set_cipher_data(EVP_CIPHER_CTX *ctx, void *cipher_data);
           int EVP_Cipher(EVP_CIPHER_CTX *c,
                          unsigned char *out,
                          const unsigned char *in, unsigned int inl);
int EVP_MD_get_params(const EVP_MD *digest, OSSL_PARAM params[]);
int EVP_MD_CTX_set_params(EVP_MD_CTX *ctx, const OSSL_PARAM params[]);
int EVP_MD_CTX_get_params(EVP_MD_CTX *ctx, OSSL_PARAM params[]);
const OSSL_PARAM *EVP_MD_gettable_params(const EVP_MD *digest);
const OSSL_PARAM *EVP_MD_settable_ctx_params(const EVP_MD *md);
const OSSL_PARAM *EVP_MD_gettable_ctx_params(const EVP_MD *md);
const OSSL_PARAM *EVP_MD_CTX_settable_params(EVP_MD_CTX *ctx);
const OSSL_PARAM *EVP_MD_CTX_gettable_params(EVP_MD_CTX *ctx);
int EVP_MD_CTX_ctrl(EVP_MD_CTX *ctx, int cmd, int p1, void *p2);
EVP_MD_CTX *EVP_MD_CTX_new(void);
int EVP_MD_CTX_reset(EVP_MD_CTX *ctx);
void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
 int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out, const EVP_MD_CTX *in);
void EVP_MD_CTX_set_flags(EVP_MD_CTX *ctx, int flags);
void EVP_MD_CTX_clear_flags(EVP_MD_CTX *ctx, int flags);
int EVP_MD_CTX_test_flags(const EVP_MD_CTX *ctx, int flags);
 int EVP_DigestInit_ex2(EVP_MD_CTX *ctx, const EVP_MD *type,
                              const OSSL_PARAM params[]);
 int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type,
                                 ENGINE *impl);
 int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d,
                                size_t cnt);
 int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md,
                                  unsigned int *s);
 int EVP_Digest(const void *data, size_t count,
                          unsigned char *md, unsigned int *size,
                          const EVP_MD *type, ENGINE *impl);
 int EVP_Q_digest(OSSL_LIB_CTX *libctx, const char *name,
                        const char *propq, const void *data, size_t datalen,
                        unsigned char *md, size_t *mdlen);
 int EVP_MD_CTX_copy(EVP_MD_CTX *out, const EVP_MD_CTX *in);
 int EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type);
 int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md,
                           unsigned int *s);
 int EVP_DigestFinalXOF(EVP_MD_CTX *ctx, unsigned char *md,
                              size_t len);
 EVP_MD *EVP_MD_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                            const char *properties);
int EVP_MD_up_ref(EVP_MD *md);
void EVP_MD_free(EVP_MD *md);
int EVP_read_pw_string(char *buf, int length, const char *prompt, int verify);
int EVP_read_pw_string_min(char *buf, int minlen, int maxlen,
                           const char *prompt, int verify);
void EVP_set_pw_prompt(const char *prompt);
char *EVP_get_pw_prompt(void);
 int EVP_BytesToKey(const EVP_CIPHER *type, const EVP_MD *md,
                          const unsigned char *salt,
                          const unsigned char *data, int datal, int count,
                          unsigned char *key, unsigned char *iv);
void EVP_CIPHER_CTX_set_flags(EVP_CIPHER_CTX *ctx, int flags);
void EVP_CIPHER_CTX_clear_flags(EVP_CIPHER_CTX *ctx, int flags);
int EVP_CIPHER_CTX_test_flags(const EVP_CIPHER_CTX *ctx, int flags);
 int EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                           const unsigned char *key, const unsigned char *iv);
           int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx,
                                  const EVP_CIPHER *cipher, ENGINE *impl,
                                  const unsigned char *key,
                                  const unsigned char *iv);
 int EVP_EncryptInit_ex2(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                               const unsigned char *key,
                               const unsigned char *iv,
                               const OSSL_PARAM params[]);
           int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                 int *outl, const unsigned char *in, int inl);
           int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                   int *outl);
           int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                int *outl);
 int EVP_DecryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                           const unsigned char *key, const unsigned char *iv);
           int EVP_DecryptInit_ex(EVP_CIPHER_CTX *ctx,
                                  const EVP_CIPHER *cipher, ENGINE *impl,
                                  const unsigned char *key,
                                  const unsigned char *iv);
 int EVP_DecryptInit_ex2(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                               const unsigned char *key,
                               const unsigned char *iv,
                               const OSSL_PARAM params[]);
           int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                 int *outl, const unsigned char *in, int inl);
 int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                            int *outl);
           int EVP_DecryptFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                                   int *outl);
 int EVP_CipherInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                          const unsigned char *key, const unsigned char *iv,
                          int enc);
           int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,
                                 const EVP_CIPHER *cipher, ENGINE *impl,
                                 const unsigned char *key,
                                 const unsigned char *iv, int enc);
 int EVP_CipherInit_ex2(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                              const unsigned char *key, const unsigned char *iv,
                              int enc, const OSSL_PARAM params[]);
 int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
                            int *outl, const unsigned char *in, int inl);
 int EVP_CipherFinal(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                           int *outl);
 int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                              int *outl);
 int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s,
                         EVP_PKEY *pkey);
 int EVP_SignFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s,
                            EVP_PKEY *pkey, OSSL_LIB_CTX *libctx,
                            const char *propq);
 int EVP_DigestSign(EVP_MD_CTX *ctx, unsigned char *sigret,
                          size_t *siglen, const unsigned char *tbs,
                          size_t tbslen);
 int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sigbuf,
                           unsigned int siglen, EVP_PKEY *pkey);
 int EVP_VerifyFinal_ex(EVP_MD_CTX *ctx, const unsigned char *sigbuf,
                              unsigned int siglen, EVP_PKEY *pkey,
                              OSSL_LIB_CTX *libctx, const char *propq);
 int EVP_DigestVerify(EVP_MD_CTX *ctx, const unsigned char *sigret,
                            size_t siglen, const unsigned char *tbs,
                            size_t tbslen);
int EVP_DigestSignInit_ex(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                          const char *mdname, OSSL_LIB_CTX *libctx,
                          const char *props, EVP_PKEY *pkey,
                          const OSSL_PARAM params[]);
           int EVP_DigestSignInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                                  const EVP_MD *type, ENGINE *e,
                                  EVP_PKEY *pkey);
int EVP_DigestSignUpdate(EVP_MD_CTX *ctx, const void *data, size_t dsize);
 int EVP_DigestSignFinal(EVP_MD_CTX *ctx, unsigned char *sigret,
                               size_t *siglen);
int EVP_DigestVerifyInit_ex(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                            const char *mdname, OSSL_LIB_CTX *libctx,
                            const char *props, EVP_PKEY *pkey,
                            const OSSL_PARAM params[]);
 int EVP_DigestVerifyInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                                const EVP_MD *type, ENGINE *e,
                                EVP_PKEY *pkey);
int EVP_DigestVerifyUpdate(EVP_MD_CTX *ctx, const void *data, size_t dsize);
 int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sig,
                                 size_t siglen);
 int EVP_OpenInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                        const unsigned char *ek, int ekl,
                        const unsigned char *iv, EVP_PKEY *priv);
 int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
 int EVP_SealInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                        unsigned char **ek, int *ekl, unsigned char *iv,
                        EVP_PKEY **pubk, int npubk);
 int EVP_SealFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
EVP_ENCODE_CTX *EVP_ENCODE_CTX_new(void);
void EVP_ENCODE_CTX_free(EVP_ENCODE_CTX *ctx);
int EVP_ENCODE_CTX_copy(EVP_ENCODE_CTX *dctx, const EVP_ENCODE_CTX *sctx);
int EVP_ENCODE_CTX_num(EVP_ENCODE_CTX *ctx);
void EVP_EncodeInit(EVP_ENCODE_CTX *ctx);
int EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
                     const unsigned char *in, int inl);
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl);
int EVP_EncodeBlock(unsigned char *t, const unsigned char *f, int n);
void EVP_DecodeInit(EVP_ENCODE_CTX *ctx);
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
                     const unsigned char *in, int inl);
int EVP_DecodeFinal(EVP_ENCODE_CTX *ctx, unsigned
                    char *out, int *outl);
int EVP_DecodeBlock(unsigned char *t, const unsigned char *f, int n);
EVP_CIPHER_CTX *EVP_CIPHER_CTX_new(void);
int EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *c);
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *c);
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x, int keylen);
int EVP_CIPHER_CTX_set_padding(EVP_CIPHER_CTX *c, int pad);
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr);
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx, unsigned char *key);
int EVP_CIPHER_get_params(EVP_CIPHER *cipher, OSSL_PARAM params[]);
int EVP_CIPHER_CTX_set_params(EVP_CIPHER_CTX *ctx, const OSSL_PARAM params[]);
int EVP_CIPHER_CTX_get_params(EVP_CIPHER_CTX *ctx, OSSL_PARAM params[]);
const OSSL_PARAM *EVP_CIPHER_gettable_params(const EVP_CIPHER *cipher);
const OSSL_PARAM *EVP_CIPHER_settable_ctx_params(const EVP_CIPHER *cipher);
const OSSL_PARAM *EVP_CIPHER_gettable_ctx_params(const EVP_CIPHER *cipher);
const OSSL_PARAM *EVP_CIPHER_CTX_settable_params(EVP_CIPHER_CTX *ctx);
const OSSL_PARAM *EVP_CIPHER_CTX_gettable_params(EVP_CIPHER_CTX *ctx);
const BIO_METHOD *BIO_f_md(void);
const BIO_METHOD *BIO_f_base64(void);
const BIO_METHOD *BIO_f_cipher(void);
const BIO_METHOD *BIO_f_reliable(void);
 int BIO_set_cipher(BIO *b, const EVP_CIPHER *c, const unsigned char *k,
                          const unsigned char *i, int enc);
const EVP_MD *EVP_md_null(void);
const EVP_MD *EVP_md4(void);
const EVP_MD *EVP_md5(void);
const EVP_MD *EVP_md5_sha1(void);
const EVP_MD *EVP_blake2b512(void);
const EVP_MD *EVP_blake2s256(void);
const EVP_MD *EVP_sha1(void);
const EVP_MD *EVP_sha224(void);
const EVP_MD *EVP_sha256(void);
const EVP_MD *EVP_sha384(void);
const EVP_MD *EVP_sha512(void);
const EVP_MD *EVP_sha512_224(void);
const EVP_MD *EVP_sha512_256(void);
const EVP_MD *EVP_sha3_224(void);
const EVP_MD *EVP_sha3_256(void);
const EVP_MD *EVP_sha3_384(void);
const EVP_MD *EVP_sha3_512(void);
const EVP_MD *EVP_shake128(void);
const EVP_MD *EVP_shake256(void);
const EVP_MD *EVP_ripemd160(void);
const EVP_MD *EVP_whirlpool(void);
const EVP_MD *EVP_sm3(void);
const EVP_CIPHER *EVP_enc_null(void);
const EVP_CIPHER *EVP_des_ecb(void);
const EVP_CIPHER *EVP_des_ede(void);
const EVP_CIPHER *EVP_des_ede3(void);
const EVP_CIPHER *EVP_des_ede_ecb(void);
const EVP_CIPHER *EVP_des_ede3_ecb(void);
const EVP_CIPHER *EVP_des_cfb64(void);
const EVP_CIPHER *EVP_des_cfb1(void);
const EVP_CIPHER *EVP_des_cfb8(void);
const EVP_CIPHER *EVP_des_ede_cfb64(void);
const EVP_CIPHER *EVP_des_ede3_cfb64(void);
const EVP_CIPHER *EVP_des_ede3_cfb1(void);
const EVP_CIPHER *EVP_des_ede3_cfb8(void);
const EVP_CIPHER *EVP_des_ofb(void);
const EVP_CIPHER *EVP_des_ede_ofb(void);
const EVP_CIPHER *EVP_des_ede3_ofb(void);
const EVP_CIPHER *EVP_des_cbc(void);
const EVP_CIPHER *EVP_des_ede_cbc(void);
const EVP_CIPHER *EVP_des_ede3_cbc(void);
const EVP_CIPHER *EVP_desx_cbc(void);
const EVP_CIPHER *EVP_des_ede3_wrap(void);
const EVP_CIPHER *EVP_rc4(void);
const EVP_CIPHER *EVP_rc4_40(void);
const EVP_CIPHER *EVP_rc4_hmac_md5(void);
const EVP_CIPHER *EVP_rc2_ecb(void);
const EVP_CIPHER *EVP_rc2_cbc(void);
const EVP_CIPHER *EVP_rc2_40_cbc(void);
const EVP_CIPHER *EVP_rc2_64_cbc(void);
const EVP_CIPHER *EVP_rc2_cfb64(void);
const EVP_CIPHER *EVP_rc2_ofb(void);
const EVP_CIPHER *EVP_bf_ecb(void);
const EVP_CIPHER *EVP_bf_cbc(void);
const EVP_CIPHER *EVP_bf_cfb64(void);
const EVP_CIPHER *EVP_bf_ofb(void);
const EVP_CIPHER *EVP_cast5_ecb(void);
const EVP_CIPHER *EVP_cast5_cbc(void);
const EVP_CIPHER *EVP_cast5_cfb64(void);
const EVP_CIPHER *EVP_cast5_ofb(void);
const EVP_CIPHER *EVP_aes_128_ecb(void);
const EVP_CIPHER *EVP_aes_128_cbc(void);
const EVP_CIPHER *EVP_aes_128_cfb1(void);
const EVP_CIPHER *EVP_aes_128_cfb8(void);
const EVP_CIPHER *EVP_aes_128_cfb128(void);
const EVP_CIPHER *EVP_aes_128_ofb(void);
const EVP_CIPHER *EVP_aes_128_ctr(void);
const EVP_CIPHER *EVP_aes_128_ccm(void);
const EVP_CIPHER *EVP_aes_128_gcm(void);
const EVP_CIPHER *EVP_aes_128_xts(void);
const EVP_CIPHER *EVP_aes_128_wrap(void);
const EVP_CIPHER *EVP_aes_128_wrap_pad(void);
const EVP_CIPHER *EVP_aes_128_ocb(void);
const EVP_CIPHER *EVP_aes_192_ecb(void);
const EVP_CIPHER *EVP_aes_192_cbc(void);
const EVP_CIPHER *EVP_aes_192_cfb1(void);
const EVP_CIPHER *EVP_aes_192_cfb8(void);
const EVP_CIPHER *EVP_aes_192_cfb128(void);
const EVP_CIPHER *EVP_aes_192_ofb(void);
const EVP_CIPHER *EVP_aes_192_ctr(void);
const EVP_CIPHER *EVP_aes_192_ccm(void);
const EVP_CIPHER *EVP_aes_192_gcm(void);
const EVP_CIPHER *EVP_aes_192_wrap(void);
const EVP_CIPHER *EVP_aes_192_wrap_pad(void);
const EVP_CIPHER *EVP_aes_192_ocb(void);
const EVP_CIPHER *EVP_aes_256_ecb(void);
const EVP_CIPHER *EVP_aes_256_cbc(void);
const EVP_CIPHER *EVP_aes_256_cfb1(void);
const EVP_CIPHER *EVP_aes_256_cfb8(void);
const EVP_CIPHER *EVP_aes_256_cfb128(void);
const EVP_CIPHER *EVP_aes_256_ofb(void);
const EVP_CIPHER *EVP_aes_256_ctr(void);
const EVP_CIPHER *EVP_aes_256_ccm(void);
const EVP_CIPHER *EVP_aes_256_gcm(void);
const EVP_CIPHER *EVP_aes_256_xts(void);
const EVP_CIPHER *EVP_aes_256_wrap(void);
const EVP_CIPHER *EVP_aes_256_wrap_pad(void);
const EVP_CIPHER *EVP_aes_256_ocb(void);
const EVP_CIPHER *EVP_aes_128_cbc_hmac_sha1(void);
const EVP_CIPHER *EVP_aes_256_cbc_hmac_sha1(void);
const EVP_CIPHER *EVP_aes_128_cbc_hmac_sha256(void);
const EVP_CIPHER *EVP_aes_256_cbc_hmac_sha256(void);
const EVP_CIPHER *EVP_aria_128_ecb(void);
const EVP_CIPHER *EVP_aria_128_cbc(void);
const EVP_CIPHER *EVP_aria_128_cfb1(void);
const EVP_CIPHER *EVP_aria_128_cfb8(void);
const EVP_CIPHER *EVP_aria_128_cfb128(void);
const EVP_CIPHER *EVP_aria_128_ctr(void);
const EVP_CIPHER *EVP_aria_128_ofb(void);
const EVP_CIPHER *EVP_aria_128_gcm(void);
const EVP_CIPHER *EVP_aria_128_ccm(void);
const EVP_CIPHER *EVP_aria_192_ecb(void);
const EVP_CIPHER *EVP_aria_192_cbc(void);
const EVP_CIPHER *EVP_aria_192_cfb1(void);
const EVP_CIPHER *EVP_aria_192_cfb8(void);
const EVP_CIPHER *EVP_aria_192_cfb128(void);
const EVP_CIPHER *EVP_aria_192_ctr(void);
const EVP_CIPHER *EVP_aria_192_ofb(void);
const EVP_CIPHER *EVP_aria_192_gcm(void);
const EVP_CIPHER *EVP_aria_192_ccm(void);
const EVP_CIPHER *EVP_aria_256_ecb(void);
const EVP_CIPHER *EVP_aria_256_cbc(void);
const EVP_CIPHER *EVP_aria_256_cfb1(void);
const EVP_CIPHER *EVP_aria_256_cfb8(void);
const EVP_CIPHER *EVP_aria_256_cfb128(void);
const EVP_CIPHER *EVP_aria_256_ctr(void);
const EVP_CIPHER *EVP_aria_256_ofb(void);
const EVP_CIPHER *EVP_aria_256_gcm(void);
const EVP_CIPHER *EVP_aria_256_ccm(void);
const EVP_CIPHER *EVP_camellia_128_ecb(void);
const EVP_CIPHER *EVP_camellia_128_cbc(void);
const EVP_CIPHER *EVP_camellia_128_cfb1(void);
const EVP_CIPHER *EVP_camellia_128_cfb8(void);
const EVP_CIPHER *EVP_camellia_128_cfb128(void);
const EVP_CIPHER *EVP_camellia_128_ofb(void);
const EVP_CIPHER *EVP_camellia_128_ctr(void);
const EVP_CIPHER *EVP_camellia_192_ecb(void);
const EVP_CIPHER *EVP_camellia_192_cbc(void);
const EVP_CIPHER *EVP_camellia_192_cfb1(void);
const EVP_CIPHER *EVP_camellia_192_cfb8(void);
const EVP_CIPHER *EVP_camellia_192_cfb128(void);
const EVP_CIPHER *EVP_camellia_192_ofb(void);
const EVP_CIPHER *EVP_camellia_192_ctr(void);
const EVP_CIPHER *EVP_camellia_256_ecb(void);
const EVP_CIPHER *EVP_camellia_256_cbc(void);
const EVP_CIPHER *EVP_camellia_256_cfb1(void);
const EVP_CIPHER *EVP_camellia_256_cfb8(void);
const EVP_CIPHER *EVP_camellia_256_cfb128(void);
const EVP_CIPHER *EVP_camellia_256_ofb(void);
const EVP_CIPHER *EVP_camellia_256_ctr(void);
const EVP_CIPHER *EVP_chacha20(void);
const EVP_CIPHER *EVP_chacha20_poly1305(void);
const EVP_CIPHER *EVP_seed_ecb(void);
const EVP_CIPHER *EVP_seed_cbc(void);
const EVP_CIPHER *EVP_seed_cfb128(void);
const EVP_CIPHER *EVP_seed_ofb(void);
const EVP_CIPHER *EVP_sm4_ecb(void);
const EVP_CIPHER *EVP_sm4_cbc(void);
const EVP_CIPHER *EVP_sm4_cfb128(void);
const EVP_CIPHER *EVP_sm4_ofb(void);
const EVP_CIPHER *EVP_sm4_ctr(void);
int EVP_add_cipher(const EVP_CIPHER *cipher);
int EVP_add_digest(const EVP_MD *digest);
const EVP_CIPHER *EVP_get_cipherbyname(const char *name);
const EVP_MD *EVP_get_digestbyname(const char *name);
void EVP_CIPHER_do_all(void (*fn) (const EVP_CIPHER *ciph,
                                   const char *from, const char *to, void *x),
                       void *arg);
void EVP_CIPHER_do_all_sorted(void (*fn)
                               (const EVP_CIPHER *ciph, const char *from,
                                const char *to, void *x), void *arg);
void EVP_CIPHER_do_all_provided(OSSL_LIB_CTX *libctx,
                                void (*fn)(EVP_CIPHER *cipher, void *arg),
                                void *arg);
void EVP_MD_do_all(void (*fn) (const EVP_MD *ciph,
                               const char *from, const char *to, void *x),
                   void *arg);
void EVP_MD_do_all_sorted(void (*fn)
                           (const EVP_MD *ciph, const char *from,
                            const char *to, void *x), void *arg);
void EVP_MD_do_all_provided(OSSL_LIB_CTX *libctx,
                            void (*fn)(EVP_MD *md, void *arg),
                            void *arg);
EVP_MAC *EVP_MAC_fetch(OSSL_LIB_CTX *libctx, const char *algorithm,
                       const char *properties);
int EVP_MAC_up_ref(EVP_MAC *mac);
void EVP_MAC_free(EVP_MAC *mac);
const char *EVP_MAC_get0_name(const EVP_MAC *mac);
const char *EVP_MAC_get0_description(const EVP_MAC *mac);
int EVP_MAC_is_a(const EVP_MAC *mac, const char *name);
const OSSL_PROVIDER *EVP_MAC_get0_provider(const EVP_MAC *mac);
int EVP_MAC_get_params(EVP_MAC *mac, OSSL_PARAM params[]);
EVP_MAC_CTX *EVP_MAC_CTX_new(EVP_MAC *mac);
void EVP_MAC_CTX_free(EVP_MAC_CTX *ctx);
EVP_MAC_CTX *EVP_MAC_CTX_dup(const EVP_MAC_CTX *src);
EVP_MAC *EVP_MAC_CTX_get0_mac(EVP_MAC_CTX *ctx);
int EVP_MAC_CTX_get_params(EVP_MAC_CTX *ctx, OSSL_PARAM params[]);
int EVP_MAC_CTX_set_params(EVP_MAC_CTX *ctx, const OSSL_PARAM params[]);
size_t EVP_MAC_CTX_get_mac_size(EVP_MAC_CTX *ctx);
size_t EVP_MAC_CTX_get_block_size(EVP_MAC_CTX *ctx);
unsigned char *EVP_Q_mac(OSSL_LIB_CTX *libctx, const char *name, const char *propq,
                         const char *subalg, const OSSL_PARAM *params,
                         const void *key, size_t keylen,
                         const unsigned char *data, size_t datalen,
                         unsigned char *out, size_t outsize, size_t *outlen);
int EVP_MAC_init(EVP_MAC_CTX *ctx, const unsigned char *key, size_t keylen,
                 const OSSL_PARAM params[]);
int EVP_MAC_update(EVP_MAC_CTX *ctx, const unsigned char *data, size_t datalen);
int EVP_MAC_final(EVP_MAC_CTX *ctx,
                  unsigned char *out, size_t *outl, size_t outsize);
int EVP_MAC_finalXOF(EVP_MAC_CTX *ctx, unsigned char *out, size_t outsize);
const OSSL_PARAM *EVP_MAC_gettable_params(const EVP_MAC *mac);
const OSSL_PARAM *EVP_MAC_gettable_ctx_params(const EVP_MAC *mac);
const OSSL_PARAM *EVP_MAC_settable_ctx_params(const EVP_MAC *mac);
const OSSL_PARAM *EVP_MAC_CTX_gettable_params(EVP_MAC_CTX *ctx);
const OSSL_PARAM *EVP_MAC_CTX_settable_params(EVP_MAC_CTX *ctx);
void EVP_MAC_do_all_provided(OSSL_LIB_CTX *libctx,
                             void (*fn)(EVP_MAC *mac, void *arg),
                             void *arg);
int EVP_MAC_names_do_all(const EVP_MAC *mac,
                         void (*fn)(const char *name, void *data),
                         void *data);
EVP_RAND *EVP_RAND_fetch(OSSL_LIB_CTX *libctx, const char *algorithm,
                         const char *properties);
int EVP_RAND_up_ref(EVP_RAND *rand);
void EVP_RAND_free(EVP_RAND *rand);
const char *EVP_RAND_get0_name(const EVP_RAND *rand);
const char *EVP_RAND_get0_description(const EVP_RAND *md);
int EVP_RAND_is_a(const EVP_RAND *rand, const char *name);
const OSSL_PROVIDER *EVP_RAND_get0_provider(const EVP_RAND *rand);
int EVP_RAND_get_params(EVP_RAND *rand, OSSL_PARAM params[]);
EVP_RAND_CTX *EVP_RAND_CTX_new(EVP_RAND *rand, EVP_RAND_CTX *parent);
void EVP_RAND_CTX_free(EVP_RAND_CTX *ctx);
EVP_RAND *EVP_RAND_CTX_get0_rand(EVP_RAND_CTX *ctx);
int EVP_RAND_CTX_get_params(EVP_RAND_CTX *ctx, OSSL_PARAM params[]);
int EVP_RAND_CTX_set_params(EVP_RAND_CTX *ctx, const OSSL_PARAM params[]);
const OSSL_PARAM *EVP_RAND_gettable_params(const EVP_RAND *rand);
const OSSL_PARAM *EVP_RAND_gettable_ctx_params(const EVP_RAND *rand);
const OSSL_PARAM *EVP_RAND_settable_ctx_params(const EVP_RAND *rand);
const OSSL_PARAM *EVP_RAND_CTX_gettable_params(EVP_RAND_CTX *ctx);
const OSSL_PARAM *EVP_RAND_CTX_settable_params(EVP_RAND_CTX *ctx);
void EVP_RAND_do_all_provided(OSSL_LIB_CTX *libctx,
                              void (*fn)(EVP_RAND *rand, void *arg),
                              void *arg);
int EVP_RAND_names_do_all(const EVP_RAND *rand,
                          void (*fn)(const char *name, void *data),
                          void *data);
 int EVP_RAND_instantiate(EVP_RAND_CTX *ctx, unsigned int strength,
                                int prediction_resistance,
                                const unsigned char *pstr, size_t pstr_len,
                                const OSSL_PARAM params[]);
int EVP_RAND_uninstantiate(EVP_RAND_CTX *ctx);
 int EVP_RAND_generate(EVP_RAND_CTX *ctx, unsigned char *out,
                             size_t outlen, unsigned int strength,
                             int prediction_resistance,
                             const unsigned char *addin, size_t addin_len);
int EVP_RAND_reseed(EVP_RAND_CTX *ctx, int prediction_resistance,
                    const unsigned char *ent, size_t ent_len,
                    const unsigned char *addin, size_t addin_len);
 int EVP_RAND_nonce(EVP_RAND_CTX *ctx, unsigned char *out, size_t outlen);
 int EVP_RAND_enable_locking(EVP_RAND_CTX *ctx);
int EVP_RAND_verify_zeroization(EVP_RAND_CTX *ctx);
unsigned int EVP_RAND_get_strength(EVP_RAND_CTX *ctx);
int EVP_RAND_get_state(EVP_RAND_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_PKEY_decrypt_old(unsigned char *dec_key,
                                          const unsigned char *enc_key,
                                          int enc_key_len,
                                          EVP_PKEY *private_key);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_PKEY_encrypt_old(unsigned char *enc_key,
                                          const unsigned char *key,
                                          int key_len, EVP_PKEY *pub_key);
int EVP_PKEY_is_a(const EVP_PKEY *pkey, const char *name);
int EVP_PKEY_type_names_do_all(const EVP_PKEY *pkey,
                               void (*fn)(const char *name, void *data),
                               void *data);
int EVP_PKEY_type(int type);
int EVP_PKEY_get_id(const EVP_PKEY *pkey);
int EVP_PKEY_get_base_id(const EVP_PKEY *pkey);
int EVP_PKEY_get_bits(const EVP_PKEY *pkey);
int EVP_PKEY_get_security_bits(const EVP_PKEY *pkey);
int EVP_PKEY_get_size(const EVP_PKEY *pkey);
int EVP_PKEY_can_sign(const EVP_PKEY *pkey);
int EVP_PKEY_set_type(EVP_PKEY *pkey, int type);
int EVP_PKEY_set_type_str(EVP_PKEY *pkey, const char *str, int len);
int EVP_PKEY_set_type_by_keymgmt(EVP_PKEY *pkey, EVP_KEYMGMT *keymgmt);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_set1_engine(EVP_PKEY *pkey, ENGINE *e);
__attribute__((deprecated("Since OpenSSL " "3.0")))
ENGINE *EVP_PKEY_get0_engine(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_assign(EVP_PKEY *pkey, int type, void *key);
__attribute__((deprecated("Since OpenSSL " "3.0")))
void *EVP_PKEY_get0(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const unsigned char *EVP_PKEY_get0_hmac(const EVP_PKEY *pkey, size_t *len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const unsigned char *EVP_PKEY_get0_poly1305(const EVP_PKEY *pkey, size_t *len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const unsigned char *EVP_PKEY_get0_siphash(const EVP_PKEY *pkey, size_t *len);
struct rsa_st;
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey, struct rsa_st *key);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const struct rsa_st *EVP_PKEY_get0_RSA(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0")))
struct rsa_st *EVP_PKEY_get1_RSA(EVP_PKEY *pkey);
struct dsa_st;
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_set1_DSA(EVP_PKEY *pkey, struct dsa_st *key);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const struct dsa_st *EVP_PKEY_get0_DSA(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0")))
struct dsa_st *EVP_PKEY_get1_DSA(EVP_PKEY *pkey);
struct dh_st;
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_PKEY_set1_DH(EVP_PKEY *pkey, struct dh_st *key);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const struct dh_st *EVP_PKEY_get0_DH(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0"))) struct dh_st *EVP_PKEY_get1_DH(EVP_PKEY *pkey);
struct ec_key_st;
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey, struct ec_key_st *key);
__attribute__((deprecated("Since OpenSSL " "3.0")))
const struct ec_key_st *EVP_PKEY_get0_EC_KEY(const EVP_PKEY *pkey);
__attribute__((deprecated("Since OpenSSL " "3.0")))
struct ec_key_st *EVP_PKEY_get1_EC_KEY(EVP_PKEY *pkey);
EVP_PKEY *EVP_PKEY_new(void);
int EVP_PKEY_up_ref(EVP_PKEY *pkey);
EVP_PKEY *EVP_PKEY_dup(EVP_PKEY *pkey);
void EVP_PKEY_free(EVP_PKEY *pkey);
const char *EVP_PKEY_get0_description(const EVP_PKEY *pkey);
const OSSL_PROVIDER *EVP_PKEY_get0_provider(const EVP_PKEY *key);
EVP_PKEY *d2i_PublicKey(int type, EVP_PKEY **a, const unsigned char **pp,
                        long length);
int i2d_PublicKey(const EVP_PKEY *a, unsigned char **pp);
EVP_PKEY *d2i_PrivateKey_ex(int type, EVP_PKEY **a, const unsigned char **pp,
                            long length, OSSL_LIB_CTX *libctx,
                            const char *propq);
EVP_PKEY *d2i_PrivateKey(int type, EVP_PKEY **a, const unsigned char **pp,
                         long length);
EVP_PKEY *d2i_AutoPrivateKey_ex(EVP_PKEY **a, const unsigned char **pp,
                                long length, OSSL_LIB_CTX *libctx,
                                const char *propq);
EVP_PKEY *d2i_AutoPrivateKey(EVP_PKEY **a, const unsigned char **pp,
                             long length);
int i2d_PrivateKey(const EVP_PKEY *a, unsigned char **pp);
int i2d_KeyParams(const EVP_PKEY *a, unsigned char **pp);
EVP_PKEY *d2i_KeyParams(int type, EVP_PKEY **a, const unsigned char **pp,
                        long length);
int i2d_KeyParams_bio(BIO *bp, const EVP_PKEY *pkey);
EVP_PKEY *d2i_KeyParams_bio(int type, EVP_PKEY **a, BIO *in);
int EVP_PKEY_copy_parameters(EVP_PKEY *to, const EVP_PKEY *from);
int EVP_PKEY_missing_parameters(const EVP_PKEY *pkey);
int EVP_PKEY_save_parameters(EVP_PKEY *pkey, int mode);
int EVP_PKEY_parameters_eq(const EVP_PKEY *a, const EVP_PKEY *b);
int EVP_PKEY_eq(const EVP_PKEY *a, const EVP_PKEY *b);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_cmp_parameters(const EVP_PKEY *a, const EVP_PKEY *b);
__attribute__((deprecated("Since OpenSSL " "3.0")))
int EVP_PKEY_cmp(const EVP_PKEY *a, const EVP_PKEY *b);
int EVP_PKEY_print_public(BIO *out, const EVP_PKEY *pkey,
                          int indent, ASN1_PCTX *pctx);
int EVP_PKEY_print_private(BIO *out, const EVP_PKEY *pkey,
                           int indent, ASN1_PCTX *pctx);
int EVP_PKEY_print_params(BIO *out, const EVP_PKEY *pkey,
                          int indent, ASN1_PCTX *pctx);
int EVP_PKEY_print_public_fp(FILE *fp, const EVP_PKEY *pkey,
                             int indent, ASN1_PCTX *pctx);
int EVP_PKEY_print_private_fp(FILE *fp, const EVP_PKEY *pkey,
                              int indent, ASN1_PCTX *pctx);
int EVP_PKEY_print_params_fp(FILE *fp, const EVP_PKEY *pkey,
                             int indent, ASN1_PCTX *pctx);
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey, int *pnid);
int EVP_PKEY_get_default_digest_name(EVP_PKEY *pkey,
                                     char *mdname, size_t mdname_sz);
int EVP_PKEY_digestsign_supports_digest(EVP_PKEY *pkey, OSSL_LIB_CTX *libctx,
                                        const char *name, const char *propq);
int EVP_PKEY_set1_encoded_public_key(EVP_PKEY *pkey,
                                     const unsigned char *pub, size_t publen);
size_t EVP_PKEY_get1_encoded_public_key(EVP_PKEY *pkey, unsigned char **ppub);
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                       ASN1_TYPE *param, const EVP_CIPHER *cipher,
                       const EVP_MD *md, int en_de);
int PKCS5_PBE_keyivgen_ex(EVP_CIPHER_CTX *cctx, const char *pass, int passlen,
                          ASN1_TYPE *param, const EVP_CIPHER *cipher,
                          const EVP_MD *md, int en_de, OSSL_LIB_CTX *libctx,
                          const char *propq);
int PKCS5_PBKDF2_HMAC_SHA1(const char *pass, int passlen,
                           const unsigned char *salt, int saltlen, int iter,
                           int keylen, unsigned char *out);
int PKCS5_PBKDF2_HMAC(const char *pass, int passlen,
                      const unsigned char *salt, int saltlen, int iter,
                      const EVP_MD *digest, int keylen, unsigned char *out);
int PKCS5_v2_PBE_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                          ASN1_TYPE *param, const EVP_CIPHER *cipher,
                          const EVP_MD *md, int en_de);
int PKCS5_v2_PBE_keyivgen_ex(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                             ASN1_TYPE *param, const EVP_CIPHER *cipher,
                             const EVP_MD *md, int en_de,
                             OSSL_LIB_CTX *libctx, const char *propq);
int EVP_PBE_scrypt(const char *pass, size_t passlen,
                   const unsigned char *salt, size_t saltlen,
                   uint64_t N, uint64_t r, uint64_t p, uint64_t maxmem,
                   unsigned char *key, size_t keylen);
int EVP_PBE_scrypt_ex(const char *pass, size_t passlen,
                      const unsigned char *salt, size_t saltlen,
                      uint64_t N, uint64_t r, uint64_t p, uint64_t maxmem,
                      unsigned char *key, size_t keylen,
                      OSSL_LIB_CTX *ctx, const char *propq);
int PKCS5_v2_scrypt_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass,
                             int passlen, ASN1_TYPE *param,
                             const EVP_CIPHER *c, const EVP_MD *md, int en_de);
int PKCS5_v2_scrypt_keyivgen_ex(EVP_CIPHER_CTX *ctx, const char *pass,
                                int passlen, ASN1_TYPE *param,
                                const EVP_CIPHER *c, const EVP_MD *md, int en_de,
                                OSSL_LIB_CTX *libctx, const char *propq);
void PKCS5_PBE_add(void);
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
                       ASN1_TYPE *param, EVP_CIPHER_CTX *ctx, int en_de);
int EVP_PBE_CipherInit_ex(ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
                          ASN1_TYPE *param, EVP_CIPHER_CTX *ctx, int en_de,
                          OSSL_LIB_CTX *libctx, const char *propq);
int EVP_PBE_alg_add_type(int pbe_type, int pbe_nid, int cipher_nid,
                         int md_nid, EVP_PBE_KEYGEN *keygen);
int EVP_PBE_alg_add(int nid, const EVP_CIPHER *cipher, const EVP_MD *md,
                    EVP_PBE_KEYGEN *keygen);
int EVP_PBE_find(int type, int pbe_nid, int *pcnid, int *pmnid,
                 EVP_PBE_KEYGEN **pkeygen);
int EVP_PBE_find_ex(int type, int pbe_nid, int *pcnid, int *pmnid,
                    EVP_PBE_KEYGEN **pkeygen, EVP_PBE_KEYGEN_EX **pkeygen_ex);
void EVP_PBE_cleanup(void);
int EVP_PBE_get(int *ptype, int *ppbe_nid, size_t num);
int EVP_PKEY_asn1_get_count(void);
const EVP_PKEY_ASN1_METHOD *EVP_PKEY_asn1_get0(int idx);
const EVP_PKEY_ASN1_METHOD *EVP_PKEY_asn1_find(ENGINE **pe, int type);
const EVP_PKEY_ASN1_METHOD *EVP_PKEY_asn1_find_str(ENGINE **pe,
                                                   const char *str, int len);
int EVP_PKEY_asn1_add0(const EVP_PKEY_ASN1_METHOD *ameth);
int EVP_PKEY_asn1_add_alias(int to, int from);
int EVP_PKEY_asn1_get0_info(int *ppkey_id, int *pkey_base_id,
                            int *ppkey_flags, const char **pinfo,
                            const char **ppem_str,
                            const EVP_PKEY_ASN1_METHOD *ameth);
const EVP_PKEY_ASN1_METHOD *EVP_PKEY_get0_asn1(const EVP_PKEY *pkey);
EVP_PKEY_ASN1_METHOD *EVP_PKEY_asn1_new(int id, int flags,
                                        const char *pem_str,
                                        const char *info);
void EVP_PKEY_asn1_copy(EVP_PKEY_ASN1_METHOD *dst,
                        const EVP_PKEY_ASN1_METHOD *src);
void EVP_PKEY_asn1_free(EVP_PKEY_ASN1_METHOD *ameth);
void EVP_PKEY_asn1_set_public(EVP_PKEY_ASN1_METHOD *ameth,
                              int (*pub_decode) (EVP_PKEY *pk,
                                                 const X509_PUBKEY *pub),
                              int (*pub_encode) (X509_PUBKEY *pub,
                                                 const EVP_PKEY *pk),
                              int (*pub_cmp) (const EVP_PKEY *a,
                                              const EVP_PKEY *b),
                              int (*pub_print) (BIO *out,
                                                const EVP_PKEY *pkey,
                                                int indent, ASN1_PCTX *pctx),
                              int (*pkey_size) (const EVP_PKEY *pk),
                              int (*pkey_bits) (const EVP_PKEY *pk));
void EVP_PKEY_asn1_set_private(EVP_PKEY_ASN1_METHOD *ameth,
                               int (*priv_decode) (EVP_PKEY *pk,
                                                   const PKCS8_PRIV_KEY_INFO
                                                   *p8inf),
                               int (*priv_encode) (PKCS8_PRIV_KEY_INFO *p8,
                                                   const EVP_PKEY *pk),
                               int (*priv_print) (BIO *out,
                                                  const EVP_PKEY *pkey,
                                                  int indent,
                                                  ASN1_PCTX *pctx));
void EVP_PKEY_asn1_set_param(EVP_PKEY_ASN1_METHOD *ameth,
                             int (*param_decode) (EVP_PKEY *pkey,
                                                  const unsigned char **pder,
                                                  int derlen),
                             int (*param_encode) (const EVP_PKEY *pkey,
                                                  unsigned char **pder),
                             int (*param_missing) (const EVP_PKEY *pk),
                             int (*param_copy) (EVP_PKEY *to,
                                                const EVP_PKEY *from),
                             int (*param_cmp) (const EVP_PKEY *a,
                                               const EVP_PKEY *b),
                             int (*param_print) (BIO *out,
                                                 const EVP_PKEY *pkey,
                                                 int indent,
                                                 ASN1_PCTX *pctx));
void EVP_PKEY_asn1_set_free(EVP_PKEY_ASN1_METHOD *ameth,
                            void (*pkey_free) (EVP_PKEY *pkey));
void EVP_PKEY_asn1_set_ctrl(EVP_PKEY_ASN1_METHOD *ameth,
                            int (*pkey_ctrl) (EVP_PKEY *pkey, int op,
                                              long arg1, void *arg2));
void EVP_PKEY_asn1_set_item(EVP_PKEY_ASN1_METHOD *ameth,
                            int (*item_verify) (EVP_MD_CTX *ctx,
                                                const ASN1_ITEM *it,
                                                const void *data,
                                                const X509_ALGOR *a,
                                                const ASN1_BIT_STRING *sig,
                                                EVP_PKEY *pkey),
                            int (*item_sign) (EVP_MD_CTX *ctx,
                                              const ASN1_ITEM *it,
                                              const void *data,
                                              X509_ALGOR *alg1,
                                              X509_ALGOR *alg2,
                                              ASN1_BIT_STRING *sig));
void EVP_PKEY_asn1_set_siginf(EVP_PKEY_ASN1_METHOD *ameth,
                              int (*siginf_set) (X509_SIG_INFO *siginf,
                                                 const X509_ALGOR *alg,
                                                 const ASN1_STRING *sig));
void EVP_PKEY_asn1_set_check(EVP_PKEY_ASN1_METHOD *ameth,
                             int (*pkey_check) (const EVP_PKEY *pk));
void EVP_PKEY_asn1_set_public_check(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*pkey_pub_check) (const EVP_PKEY *pk));
void EVP_PKEY_asn1_set_param_check(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*pkey_param_check) (const EVP_PKEY *pk));
void EVP_PKEY_asn1_set_set_priv_key(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*set_priv_key) (EVP_PKEY *pk,
                                                         const unsigned char
                                                            *priv,
                                                         size_t len));
void EVP_PKEY_asn1_set_set_pub_key(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*set_pub_key) (EVP_PKEY *pk,
                                                       const unsigned char *pub,
                                                       size_t len));
void EVP_PKEY_asn1_set_get_priv_key(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*get_priv_key) (const EVP_PKEY *pk,
                                                         unsigned char *priv,
                                                         size_t *len));
void EVP_PKEY_asn1_set_get_pub_key(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*get_pub_key) (const EVP_PKEY *pk,
                                                       unsigned char *pub,
                                                       size_t *len));
void EVP_PKEY_asn1_set_security_bits(EVP_PKEY_ASN1_METHOD *ameth,
                                     int (*pkey_security_bits) (const EVP_PKEY
                                                                *pk));
int EVP_PKEY_CTX_get_signature_md(EVP_PKEY_CTX *ctx, const EVP_MD **md);
int EVP_PKEY_CTX_set_signature_md(EVP_PKEY_CTX *ctx, const EVP_MD *md);
int EVP_PKEY_CTX_set1_id(EVP_PKEY_CTX *ctx, const void *id, int len);
int EVP_PKEY_CTX_get1_id(EVP_PKEY_CTX *ctx, void *id);
int EVP_PKEY_CTX_get1_id_len(EVP_PKEY_CTX *ctx, size_t *id_len);
int EVP_PKEY_CTX_set_kem_op(EVP_PKEY_CTX *ctx, const char *op);
const char *EVP_PKEY_get0_type_name(const EVP_PKEY *key);
int EVP_PKEY_CTX_set_mac_key(EVP_PKEY_CTX *ctx, const unsigned char *key,
                             int keylen);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const EVP_PKEY_METHOD *EVP_PKEY_meth_find(int type);
__attribute__((deprecated("Since OpenSSL " "3.0"))) EVP_PKEY_METHOD *EVP_PKEY_meth_new(int id, int flags);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get0_info(int *ppkey_id, int *pflags,
                                              const EVP_PKEY_METHOD *meth);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_copy(EVP_PKEY_METHOD *dst,
                                         const EVP_PKEY_METHOD *src);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_free(EVP_PKEY_METHOD *pmeth);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_PKEY_meth_add0(const EVP_PKEY_METHOD *pmeth);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int EVP_PKEY_meth_remove(const EVP_PKEY_METHOD *pmeth);
__attribute__((deprecated("Since OpenSSL " "3.0"))) size_t EVP_PKEY_meth_get_count(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const EVP_PKEY_METHOD *EVP_PKEY_meth_get0(size_t idx);
EVP_KEYMGMT *EVP_KEYMGMT_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                               const char *properties);
int EVP_KEYMGMT_up_ref(EVP_KEYMGMT *keymgmt);
void EVP_KEYMGMT_free(EVP_KEYMGMT *keymgmt);
const OSSL_PROVIDER *EVP_KEYMGMT_get0_provider(const EVP_KEYMGMT *keymgmt);
const char *EVP_KEYMGMT_get0_name(const EVP_KEYMGMT *keymgmt);
const char *EVP_KEYMGMT_get0_description(const EVP_KEYMGMT *keymgmt);
int EVP_KEYMGMT_is_a(const EVP_KEYMGMT *keymgmt, const char *name);
void EVP_KEYMGMT_do_all_provided(OSSL_LIB_CTX *libctx,
                                 void (*fn)(EVP_KEYMGMT *keymgmt, void *arg),
                                 void *arg);
int EVP_KEYMGMT_names_do_all(const EVP_KEYMGMT *keymgmt,
                             void (*fn)(const char *name, void *data),
                             void *data);
const OSSL_PARAM *EVP_KEYMGMT_gettable_params(const EVP_KEYMGMT *keymgmt);
const OSSL_PARAM *EVP_KEYMGMT_settable_params(const EVP_KEYMGMT *keymgmt);
const OSSL_PARAM *EVP_KEYMGMT_gen_settable_params(const EVP_KEYMGMT *keymgmt);
EVP_PKEY_CTX *EVP_PKEY_CTX_new(EVP_PKEY *pkey, ENGINE *e);
EVP_PKEY_CTX *EVP_PKEY_CTX_new_id(int id, ENGINE *e);
EVP_PKEY_CTX *EVP_PKEY_CTX_new_from_name(OSSL_LIB_CTX *libctx,
                                         const char *name,
                                         const char *propquery);
EVP_PKEY_CTX *EVP_PKEY_CTX_new_from_pkey(OSSL_LIB_CTX *libctx,
                                         EVP_PKEY *pkey, const char *propquery);
EVP_PKEY_CTX *EVP_PKEY_CTX_dup(const EVP_PKEY_CTX *ctx);
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx);
int EVP_PKEY_CTX_is_a(EVP_PKEY_CTX *ctx, const char *keytype);
int EVP_PKEY_CTX_get_params(EVP_PKEY_CTX *ctx, OSSL_PARAM *params);
const OSSL_PARAM *EVP_PKEY_CTX_gettable_params(const EVP_PKEY_CTX *ctx);
int EVP_PKEY_CTX_set_params(EVP_PKEY_CTX *ctx, const OSSL_PARAM *params);
const OSSL_PARAM *EVP_PKEY_CTX_settable_params(const EVP_PKEY_CTX *ctx);
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int keytype, int optype,
                      int cmd, int p1, void *p2);
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx, const char *type,
                          const char *value);
int EVP_PKEY_CTX_ctrl_uint64(EVP_PKEY_CTX *ctx, int keytype, int optype,
                             int cmd, uint64_t value);
int EVP_PKEY_CTX_str2ctrl(EVP_PKEY_CTX *ctx, int cmd, const char *str);
int EVP_PKEY_CTX_hex2ctrl(EVP_PKEY_CTX *ctx, int cmd, const char *hex);
int EVP_PKEY_CTX_md(EVP_PKEY_CTX *ctx, int optype, int cmd, const char *md);
int EVP_PKEY_CTX_get_operation(EVP_PKEY_CTX *ctx);
void EVP_PKEY_CTX_set0_keygen_info(EVP_PKEY_CTX *ctx, int *dat, int datlen);
EVP_PKEY *EVP_PKEY_new_mac_key(int type, ENGINE *e,
                               const unsigned char *key, int keylen);
EVP_PKEY *EVP_PKEY_new_raw_private_key_ex(OSSL_LIB_CTX *libctx,
                                          const char *keytype,
                                          const char *propq,
                                          const unsigned char *priv, size_t len);
EVP_PKEY *EVP_PKEY_new_raw_private_key(int type, ENGINE *e,
                                       const unsigned char *priv,
                                       size_t len);
EVP_PKEY *EVP_PKEY_new_raw_public_key_ex(OSSL_LIB_CTX *libctx,
                                         const char *keytype, const char *propq,
                                         const unsigned char *pub, size_t len);
EVP_PKEY *EVP_PKEY_new_raw_public_key(int type, ENGINE *e,
                                      const unsigned char *pub,
                                      size_t len);
int EVP_PKEY_get_raw_private_key(const EVP_PKEY *pkey, unsigned char *priv,
                                 size_t *len);
int EVP_PKEY_get_raw_public_key(const EVP_PKEY *pkey, unsigned char *pub,
                                size_t *len);
__attribute__((deprecated("Since OpenSSL " "3.0")))
EVP_PKEY *EVP_PKEY_new_CMAC_key(ENGINE *e, const unsigned char *priv,
                                size_t len, const EVP_CIPHER *cipher);
void EVP_PKEY_CTX_set_data(EVP_PKEY_CTX *ctx, void *data);
void *EVP_PKEY_CTX_get_data(const EVP_PKEY_CTX *ctx);
EVP_PKEY *EVP_PKEY_CTX_get0_pkey(EVP_PKEY_CTX *ctx);
EVP_PKEY *EVP_PKEY_CTX_get0_peerkey(EVP_PKEY_CTX *ctx);
void EVP_PKEY_CTX_set_app_data(EVP_PKEY_CTX *ctx, void *data);
void *EVP_PKEY_CTX_get_app_data(EVP_PKEY_CTX *ctx);
void EVP_SIGNATURE_free(EVP_SIGNATURE *signature);
int EVP_SIGNATURE_up_ref(EVP_SIGNATURE *signature);
OSSL_PROVIDER *EVP_SIGNATURE_get0_provider(const EVP_SIGNATURE *signature);
EVP_SIGNATURE *EVP_SIGNATURE_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                                   const char *properties);
int EVP_SIGNATURE_is_a(const EVP_SIGNATURE *signature, const char *name);
const char *EVP_SIGNATURE_get0_name(const EVP_SIGNATURE *signature);
const char *EVP_SIGNATURE_get0_description(const EVP_SIGNATURE *signature);
void EVP_SIGNATURE_do_all_provided(OSSL_LIB_CTX *libctx,
                                   void (*fn)(EVP_SIGNATURE *signature,
                                              void *data),
                                   void *data);
int EVP_SIGNATURE_names_do_all(const EVP_SIGNATURE *signature,
                               void (*fn)(const char *name, void *data),
                               void *data);
const OSSL_PARAM *EVP_SIGNATURE_gettable_ctx_params(const EVP_SIGNATURE *sig);
const OSSL_PARAM *EVP_SIGNATURE_settable_ctx_params(const EVP_SIGNATURE *sig);
void EVP_ASYM_CIPHER_free(EVP_ASYM_CIPHER *cipher);
int EVP_ASYM_CIPHER_up_ref(EVP_ASYM_CIPHER *cipher);
OSSL_PROVIDER *EVP_ASYM_CIPHER_get0_provider(const EVP_ASYM_CIPHER *cipher);
EVP_ASYM_CIPHER *EVP_ASYM_CIPHER_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                                       const char *properties);
int EVP_ASYM_CIPHER_is_a(const EVP_ASYM_CIPHER *cipher, const char *name);
const char *EVP_ASYM_CIPHER_get0_name(const EVP_ASYM_CIPHER *cipher);
const char *EVP_ASYM_CIPHER_get0_description(const EVP_ASYM_CIPHER *cipher);
void EVP_ASYM_CIPHER_do_all_provided(OSSL_LIB_CTX *libctx,
                                     void (*fn)(EVP_ASYM_CIPHER *cipher,
                                                void *arg),
                                     void *arg);
int EVP_ASYM_CIPHER_names_do_all(const EVP_ASYM_CIPHER *cipher,
                                 void (*fn)(const char *name, void *data),
                                 void *data);
const OSSL_PARAM *EVP_ASYM_CIPHER_gettable_ctx_params(const EVP_ASYM_CIPHER *ciph);
const OSSL_PARAM *EVP_ASYM_CIPHER_settable_ctx_params(const EVP_ASYM_CIPHER *ciph);
void EVP_KEM_free(EVP_KEM *wrap);
int EVP_KEM_up_ref(EVP_KEM *wrap);
OSSL_PROVIDER *EVP_KEM_get0_provider(const EVP_KEM *wrap);
EVP_KEM *EVP_KEM_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                       const char *properties);
int EVP_KEM_is_a(const EVP_KEM *wrap, const char *name);
const char *EVP_KEM_get0_name(const EVP_KEM *wrap);
const char *EVP_KEM_get0_description(const EVP_KEM *wrap);
void EVP_KEM_do_all_provided(OSSL_LIB_CTX *libctx,
                             void (*fn)(EVP_KEM *wrap, void *arg), void *arg);
int EVP_KEM_names_do_all(const EVP_KEM *wrap,
                         void (*fn)(const char *name, void *data), void *data);
const OSSL_PARAM *EVP_KEM_gettable_ctx_params(const EVP_KEM *kem);
const OSSL_PARAM *EVP_KEM_settable_ctx_params(const EVP_KEM *kem);
int EVP_PKEY_sign_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_sign_init_ex(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_sign(EVP_PKEY_CTX *ctx,
                  unsigned char *sig, size_t *siglen,
                  const unsigned char *tbs, size_t tbslen);
int EVP_PKEY_verify_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_verify_init_ex(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_verify(EVP_PKEY_CTX *ctx,
                    const unsigned char *sig, size_t siglen,
                    const unsigned char *tbs, size_t tbslen);
int EVP_PKEY_verify_recover_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_verify_recover_init_ex(EVP_PKEY_CTX *ctx,
                                    const OSSL_PARAM params[]);
int EVP_PKEY_verify_recover(EVP_PKEY_CTX *ctx,
                            unsigned char *rout, size_t *routlen,
                            const unsigned char *sig, size_t siglen);
int EVP_PKEY_encrypt_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_encrypt_init_ex(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_encrypt(EVP_PKEY_CTX *ctx,
                     unsigned char *out, size_t *outlen,
                     const unsigned char *in, size_t inlen);
int EVP_PKEY_decrypt_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_decrypt_init_ex(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx,
                     unsigned char *out, size_t *outlen,
                     const unsigned char *in, size_t inlen);
int EVP_PKEY_derive_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_derive_init_ex(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_derive_set_peer_ex(EVP_PKEY_CTX *ctx, EVP_PKEY *peer,
                                int validate_peer);
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx, EVP_PKEY *peer);
int EVP_PKEY_derive(EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen);
int EVP_PKEY_encapsulate_init(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_encapsulate(EVP_PKEY_CTX *ctx,
                         unsigned char *wrappedkey, size_t *wrappedkeylen,
                         unsigned char *genkey, size_t *genkeylen);
int EVP_PKEY_decapsulate_init(EVP_PKEY_CTX *ctx, const OSSL_PARAM params[]);
int EVP_PKEY_decapsulate(EVP_PKEY_CTX *ctx,
                         unsigned char *unwrapped, size_t *unwrappedlen,
                         const unsigned char *wrapped, size_t wrappedlen);
typedef int EVP_PKEY_gen_cb(EVP_PKEY_CTX *ctx);
int EVP_PKEY_fromdata_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_fromdata(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey, int selection,
                      OSSL_PARAM param[]);
const OSSL_PARAM *EVP_PKEY_fromdata_settable(EVP_PKEY_CTX *ctx, int selection);
int EVP_PKEY_todata(const EVP_PKEY *pkey, int selection, OSSL_PARAM **params);
int EVP_PKEY_export(const EVP_PKEY *pkey, int selection,
                    OSSL_CALLBACK *export_cb, void *export_cbarg);
const OSSL_PARAM *EVP_PKEY_gettable_params(const EVP_PKEY *pkey);
int EVP_PKEY_get_params(const EVP_PKEY *pkey, OSSL_PARAM params[]);
int EVP_PKEY_get_int_param(const EVP_PKEY *pkey, const char *key_name,
                           int *out);
int EVP_PKEY_get_size_t_param(const EVP_PKEY *pkey, const char *key_name,
                              size_t *out);
int EVP_PKEY_get_bn_param(const EVP_PKEY *pkey, const char *key_name,
                          BIGNUM **bn);
int EVP_PKEY_get_utf8_string_param(const EVP_PKEY *pkey, const char *key_name,
                                    char *str, size_t max_buf_sz, size_t *out_sz);
int EVP_PKEY_get_octet_string_param(const EVP_PKEY *pkey, const char *key_name,
                                    unsigned char *buf, size_t max_buf_sz,
                                    size_t *out_sz);
const OSSL_PARAM *EVP_PKEY_settable_params(const EVP_PKEY *pkey);
int EVP_PKEY_set_params(EVP_PKEY *pkey, OSSL_PARAM params[]);
int EVP_PKEY_set_int_param(EVP_PKEY *pkey, const char *key_name, int in);
int EVP_PKEY_set_size_t_param(EVP_PKEY *pkey, const char *key_name, size_t in);
int EVP_PKEY_set_bn_param(EVP_PKEY *pkey, const char *key_name,
                          const BIGNUM *bn);
int EVP_PKEY_set_utf8_string_param(EVP_PKEY *pkey, const char *key_name,
                                   const char *str);
int EVP_PKEY_set_octet_string_param(EVP_PKEY *pkey, const char *key_name,
                                    const unsigned char *buf, size_t bsize);
int EVP_PKEY_get_ec_point_conv_form(const EVP_PKEY *pkey);
int EVP_PKEY_get_field_type(const EVP_PKEY *pkey);
EVP_PKEY *EVP_PKEY_Q_keygen(OSSL_LIB_CTX *libctx, const char *propq,
                            const char *type, ...);
int EVP_PKEY_paramgen_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_paramgen(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey);
int EVP_PKEY_keygen_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey);
int EVP_PKEY_generate(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey);
int EVP_PKEY_check(EVP_PKEY_CTX *ctx);
int EVP_PKEY_public_check(EVP_PKEY_CTX *ctx);
int EVP_PKEY_public_check_quick(EVP_PKEY_CTX *ctx);
int EVP_PKEY_param_check(EVP_PKEY_CTX *ctx);
int EVP_PKEY_param_check_quick(EVP_PKEY_CTX *ctx);
int EVP_PKEY_private_check(EVP_PKEY_CTX *ctx);
int EVP_PKEY_pairwise_check(EVP_PKEY_CTX *ctx);
int EVP_PKEY_set_ex_data(EVP_PKEY *key, int idx, void *arg);
void *EVP_PKEY_get_ex_data(const EVP_PKEY *key, int idx);
void EVP_PKEY_CTX_set_cb(EVP_PKEY_CTX *ctx, EVP_PKEY_gen_cb *cb);
EVP_PKEY_gen_cb *EVP_PKEY_CTX_get_cb(EVP_PKEY_CTX *ctx);
int EVP_PKEY_CTX_get_keygen_info(EVP_PKEY_CTX *ctx, int idx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_init(EVP_PKEY_METHOD *pmeth,
                                             int (*init) (EVP_PKEY_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_copy
    (EVP_PKEY_METHOD *pmeth, int (*copy) (EVP_PKEY_CTX *dst,
                                          const EVP_PKEY_CTX *src));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_cleanup
    (EVP_PKEY_METHOD *pmeth, void (*cleanup) (EVP_PKEY_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_paramgen
    (EVP_PKEY_METHOD *pmeth, int (*paramgen_init) (EVP_PKEY_CTX *ctx),
     int (*paramgen) (EVP_PKEY_CTX *ctx, EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_keygen
    (EVP_PKEY_METHOD *pmeth, int (*keygen_init) (EVP_PKEY_CTX *ctx),
     int (*keygen) (EVP_PKEY_CTX *ctx, EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_sign
    (EVP_PKEY_METHOD *pmeth, int (*sign_init) (EVP_PKEY_CTX *ctx),
     int (*sign) (EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
                  const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_verify
    (EVP_PKEY_METHOD *pmeth, int (*verify_init) (EVP_PKEY_CTX *ctx),
     int (*verify) (EVP_PKEY_CTX *ctx, const unsigned char *sig, size_t siglen,
                    const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_verify_recover
    (EVP_PKEY_METHOD *pmeth, int (*verify_recover_init) (EVP_PKEY_CTX *ctx),
     int (*verify_recover) (EVP_PKEY_CTX *ctx, unsigned char *sig,
                            size_t *siglen, const unsigned char *tbs,
                            size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_signctx
    (EVP_PKEY_METHOD *pmeth, int (*signctx_init) (EVP_PKEY_CTX *ctx,
                                                  EVP_MD_CTX *mctx),
     int (*signctx) (EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
                     EVP_MD_CTX *mctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_verifyctx
    (EVP_PKEY_METHOD *pmeth, int (*verifyctx_init) (EVP_PKEY_CTX *ctx,
                                                    EVP_MD_CTX *mctx),
     int (*verifyctx) (EVP_PKEY_CTX *ctx, const unsigned char *sig, int siglen,
                       EVP_MD_CTX *mctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_encrypt
    (EVP_PKEY_METHOD *pmeth, int (*encrypt_init) (EVP_PKEY_CTX *ctx),
     int (*encryptfn) (EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen,
                       const unsigned char *in, size_t inlen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_decrypt
    (EVP_PKEY_METHOD *pmeth, int (*decrypt_init) (EVP_PKEY_CTX *ctx),
     int (*decrypt) (EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen,
                     const unsigned char *in, size_t inlen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_derive
    (EVP_PKEY_METHOD *pmeth, int (*derive_init) (EVP_PKEY_CTX *ctx),
     int (*derive) (EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_ctrl
    (EVP_PKEY_METHOD *pmeth, int (*ctrl) (EVP_PKEY_CTX *ctx, int type, int p1,
                                          void *p2),
     int (*ctrl_str) (EVP_PKEY_CTX *ctx, const char *type, const char *value));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_digestsign
    (EVP_PKEY_METHOD *pmeth,
     int (*digestsign) (EVP_MD_CTX *ctx, unsigned char *sig, size_t *siglen,
                        const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_digestverify
    (EVP_PKEY_METHOD *pmeth,
     int (*digestverify) (EVP_MD_CTX *ctx, const unsigned char *sig,
                          size_t siglen, const unsigned char *tbs,
                          size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_check
    (EVP_PKEY_METHOD *pmeth, int (*check) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_public_check
    (EVP_PKEY_METHOD *pmeth, int (*check) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_param_check
    (EVP_PKEY_METHOD *pmeth, int (*check) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_set_digest_custom
    (EVP_PKEY_METHOD *pmeth, int (*digest_custom) (EVP_PKEY_CTX *ctx,
                                                   EVP_MD_CTX *mctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_init
    (const EVP_PKEY_METHOD *pmeth, int (**pinit) (EVP_PKEY_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_copy
    (const EVP_PKEY_METHOD *pmeth, int (**pcopy) (EVP_PKEY_CTX *dst,
                                                  const EVP_PKEY_CTX *src));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_cleanup
    (const EVP_PKEY_METHOD *pmeth, void (**pcleanup) (EVP_PKEY_CTX *ctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_paramgen
    (const EVP_PKEY_METHOD *pmeth, int (**pparamgen_init) (EVP_PKEY_CTX *ctx),
     int (**pparamgen) (EVP_PKEY_CTX *ctx, EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_keygen
    (const EVP_PKEY_METHOD *pmeth, int (**pkeygen_init) (EVP_PKEY_CTX *ctx),
     int (**pkeygen) (EVP_PKEY_CTX *ctx, EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_sign
    (const EVP_PKEY_METHOD *pmeth, int (**psign_init) (EVP_PKEY_CTX *ctx),
     int (**psign) (EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
                    const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_verify
    (const EVP_PKEY_METHOD *pmeth, int (**pverify_init) (EVP_PKEY_CTX *ctx),
     int (**pverify) (EVP_PKEY_CTX *ctx, const unsigned char *sig,
                      size_t siglen, const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_verify_recover
    (const EVP_PKEY_METHOD *pmeth,
     int (**pverify_recover_init) (EVP_PKEY_CTX *ctx),
     int (**pverify_recover) (EVP_PKEY_CTX *ctx, unsigned char *sig,
                              size_t *siglen, const unsigned char *tbs,
                              size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_signctx
    (const EVP_PKEY_METHOD *pmeth,
     int (**psignctx_init) (EVP_PKEY_CTX *ctx, EVP_MD_CTX *mctx),
     int (**psignctx) (EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
                       EVP_MD_CTX *mctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_verifyctx
    (const EVP_PKEY_METHOD *pmeth,
     int (**pverifyctx_init) (EVP_PKEY_CTX *ctx, EVP_MD_CTX *mctx),
     int (**pverifyctx) (EVP_PKEY_CTX *ctx, const unsigned char *sig,
                          int siglen, EVP_MD_CTX *mctx));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_encrypt
    (const EVP_PKEY_METHOD *pmeth, int (**pencrypt_init) (EVP_PKEY_CTX *ctx),
     int (**pencryptfn) (EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen,
                         const unsigned char *in, size_t inlen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_decrypt
    (const EVP_PKEY_METHOD *pmeth, int (**pdecrypt_init) (EVP_PKEY_CTX *ctx),
     int (**pdecrypt) (EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen,
                       const unsigned char *in, size_t inlen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_derive
    (const EVP_PKEY_METHOD *pmeth, int (**pderive_init) (EVP_PKEY_CTX *ctx),
     int (**pderive) (EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_ctrl
    (const EVP_PKEY_METHOD *pmeth,
     int (**pctrl) (EVP_PKEY_CTX *ctx, int type, int p1, void *p2),
     int (**pctrl_str) (EVP_PKEY_CTX *ctx, const char *type,
                        const char *value));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_digestsign
    (const EVP_PKEY_METHOD *pmeth,
     int (**digestsign) (EVP_MD_CTX *ctx, unsigned char *sig, size_t *siglen,
                         const unsigned char *tbs, size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_digestverify
    (const EVP_PKEY_METHOD *pmeth,
     int (**digestverify) (EVP_MD_CTX *ctx, const unsigned char *sig,
                           size_t siglen, const unsigned char *tbs,
                           size_t tbslen));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_check
    (const EVP_PKEY_METHOD *pmeth, int (**pcheck) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_public_check
    (const EVP_PKEY_METHOD *pmeth, int (**pcheck) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_param_check
    (const EVP_PKEY_METHOD *pmeth, int (**pcheck) (EVP_PKEY *pkey));
__attribute__((deprecated("Since OpenSSL " "3.0"))) void EVP_PKEY_meth_get_digest_custom
    (const EVP_PKEY_METHOD *pmeth,
     int (**pdigest_custom) (EVP_PKEY_CTX *ctx, EVP_MD_CTX *mctx));
void EVP_KEYEXCH_free(EVP_KEYEXCH *exchange);
int EVP_KEYEXCH_up_ref(EVP_KEYEXCH *exchange);
EVP_KEYEXCH *EVP_KEYEXCH_fetch(OSSL_LIB_CTX *ctx, const char *algorithm,
                               const char *properties);
OSSL_PROVIDER *EVP_KEYEXCH_get0_provider(const EVP_KEYEXCH *exchange);
int EVP_KEYEXCH_is_a(const EVP_KEYEXCH *keyexch, const char *name);
const char *EVP_KEYEXCH_get0_name(const EVP_KEYEXCH *keyexch);
const char *EVP_KEYEXCH_get0_description(const EVP_KEYEXCH *keyexch);
void EVP_KEYEXCH_do_all_provided(OSSL_LIB_CTX *libctx,
                                 void (*fn)(EVP_KEYEXCH *keyexch, void *data),
                                 void *data);
int EVP_KEYEXCH_names_do_all(const EVP_KEYEXCH *keyexch,
                             void (*fn)(const char *name, void *data),
                             void *data);
const OSSL_PARAM *EVP_KEYEXCH_gettable_ctx_params(const EVP_KEYEXCH *keyexch);
const OSSL_PARAM *EVP_KEYEXCH_settable_ctx_params(const EVP_KEYEXCH *keyexch);
void EVP_add_alg_module(void);
int EVP_PKEY_CTX_set_group_name(EVP_PKEY_CTX *ctx, const char *name);
int EVP_PKEY_CTX_get_group_name(EVP_PKEY_CTX *ctx, char *name, size_t namelen);
int EVP_PKEY_get_group_name(const EVP_PKEY *pkey, char *name, size_t name_sz,
                            size_t *gname_len);
OSSL_LIB_CTX *EVP_PKEY_CTX_get0_libctx(EVP_PKEY_CTX *ctx);
const char *EVP_PKEY_CTX_get0_propq(const EVP_PKEY_CTX *ctx);
const OSSL_PROVIDER *EVP_PKEY_CTX_get0_provider(const EVP_PKEY_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) size_t HMAC_size(const HMAC_CTX *e);
__attribute__((deprecated("Since OpenSSL " "3.0"))) HMAC_CTX *HMAC_CTX_new(void);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int HMAC_CTX_reset(HMAC_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void HMAC_CTX_free(HMAC_CTX *ctx);
__attribute__((deprecated("Since OpenSSL " "1.1.0"))) int HMAC_Init(HMAC_CTX *ctx,
                                             const void *key, int len,
                                             const EVP_MD *md);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int len,
                                       const EVP_MD *md, ENGINE *impl);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data,
                                      size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int HMAC_Final(HMAC_CTX *ctx, unsigned char *md,
                                     unsigned int *len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int HMAC_CTX_copy(HMAC_CTX *dctx, HMAC_CTX *sctx);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void HMAC_CTX_set_flags(HMAC_CTX *ctx, unsigned long flags);
__attribute__((deprecated("Since OpenSSL " "3.0"))) const EVP_MD *HMAC_CTX_get_md(const HMAC_CTX *ctx);
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len,
                    const unsigned char *data, size_t data_len,
                    unsigned char *md, unsigned int *md_len);

typedef __useconds_t useconds_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t write (int __fd, const void *__buf, size_t __n) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 1)));
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_MINSIGSTKSZ,
    _SC_SIGSTKSZ
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) __attribute__ ((__warn_unused_result__));
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) __attribute__ ((__warn_unused_result__));
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__access__ (__write_only__, 3, 4)));
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));



extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int lockf (int __fd, int __cmd, __off_t __len) __attribute__ ((__warn_unused_result__));
extern int fdatasync (int __fildes);
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
int getentropy (void *__buffer, size_t __length) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern ssize_t __read_chk (int __fd, void *__buf, size_t __nbytes,
      size_t __buflen)
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __read_alias (int __fd, void *__buf, size_t __nbytes) __asm__ ("" "read")
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __read_chk_warn (int __fd, void *__buf, size_t __nbytes, size_t __buflen) __asm__ ("" "__read_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("read called with bigger length than size of " "the destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) ssize_t
read (int __fd, void *__buf, size_t __nbytes)
{
  return ((((__typeof (__nbytes)) 0 < (__typeof (__nbytes)) -1 || (__builtin_constant_p (__nbytes) && (__nbytes) > 0)) && __builtin_constant_p ((((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) && (((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) ? __read_alias (__fd, __buf, __nbytes) : ((((__typeof (__nbytes)) 0 < (__typeof (__nbytes)) -1 || (__builtin_constant_p (__nbytes) && (__nbytes) > 0)) && __builtin_constant_p ((((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) && !(((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) ? __read_chk_warn (__fd, __buf, __nbytes, __builtin_object_size (__buf, 0)) : __read_chk (__fd, __buf, __nbytes, __builtin_object_size (__buf, 0))));
}
extern ssize_t __pread_chk (int __fd, void *__buf, size_t __nbytes,
       __off_t __offset, size_t __bufsize)
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __pread64_chk (int __fd, void *__buf, size_t __nbytes,
         __off64_t __offset, size_t __bufsize)
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __pread_alias (int __fd, void *__buf, size_t __nbytes, __off_t __offset) __asm__ ("" "pread")
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __pread64_alias (int __fd, void *__buf, size_t __nbytes, __off64_t __offset) __asm__ ("" "pread64")
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __pread_chk_warn (int __fd, void *__buf, size_t __nbytes, __off_t __offset, size_t __bufsize) __asm__ ("" "__pread_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("pread called with bigger length than size of " "the destination buffer")));
extern ssize_t __pread64_chk_warn (int __fd, void *__buf, size_t __nbytes, __off64_t __offset, size_t __bufsize) __asm__ ("" "__pread64_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("pread64 called with bigger length than size of " "the destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) ssize_t
pread (int __fd, void *__buf, size_t __nbytes, __off_t __offset)
{
  return ((((__typeof (__nbytes)) 0 < (__typeof (__nbytes)) -1 || (__builtin_constant_p (__nbytes) && (__nbytes) > 0)) && __builtin_constant_p ((((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) && (((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) ? __pread_alias (__fd, __buf, __nbytes, __offset) : ((((__typeof (__nbytes)) 0 < (__typeof (__nbytes)) -1 || (__builtin_constant_p (__nbytes) && (__nbytes) > 0)) && __builtin_constant_p ((((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) && !(((long unsigned int) (__nbytes)) <= (__builtin_object_size (__buf, 0)) / (sizeof (char)))) ? __pread_chk_warn (__fd, __buf, __nbytes, __offset, __builtin_object_size (__buf, 0)) : __pread_chk (__fd, __buf, __nbytes, __offset, __builtin_object_size (__buf, 0))));
}
extern ssize_t __readlink_chk (const char *__restrict __path,
          char *__restrict __buf, size_t __len,
          size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __readlink_alias (const char *__restrict __path, char *__restrict __buf, size_t __len) __asm__ ("" "readlink") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t __readlink_chk_warn (const char *__restrict __path, char *__restrict __buf, size_t __len, size_t __buflen) __asm__ ("" "__readlink_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("readlink called with bigger length " "than size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) ssize_t
__attribute__ ((__nothrow__ , __leaf__)) readlink (const char *__restrict __path, char *__restrict __buf, size_t __len)
{
  return ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __readlink_alias (__path, __buf, __len) : ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __readlink_chk_warn (__path, __buf, __len, __builtin_object_size (__buf, 2 > 1)) : __readlink_chk (__path, __buf, __len, __builtin_object_size (__buf, 2 > 1))));
}
extern ssize_t __readlinkat_chk (int __fd, const char *__restrict __path,
     char *__restrict __buf, size_t __len,
     size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 3, 4)));
extern ssize_t __readlinkat_alias (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len) __asm__ ("" "readlinkat") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 3, 4)));
extern ssize_t __readlinkat_chk_warn (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len, size_t __buflen) __asm__ ("" "__readlinkat_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("readlinkat called with bigger " "length than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) ssize_t
__attribute__ ((__nothrow__ , __leaf__)) readlinkat (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len)
{
  return ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __readlinkat_alias (__fd, __path, __buf, __len) : ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __readlinkat_chk_warn (__fd, __path, __buf, __len, __builtin_object_size (__buf, 2 > 1)) : __readlinkat_chk (__fd, __path, __buf, __len, __builtin_object_size (__buf, 2 > 1))));
}
extern char *__getcwd_chk (char *__buf, size_t __size, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__getcwd_alias (char *__buf, size_t __size) __asm__ ("" "getcwd") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__getcwd_chk_warn (char *__buf, size_t __size, size_t __buflen) __asm__ ("" "__getcwd_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getcwd caller with bigger length than size of " "destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) getcwd (char *__buf, size_t __size)
{
  return ((((__typeof (__size)) 0 < (__typeof (__size)) -1 || (__builtin_constant_p (__size) && (__size) > 0)) && __builtin_constant_p ((((long unsigned int) (__size)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__size)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getcwd_alias (__buf, __size) : ((((__typeof (__size)) 0 < (__typeof (__size)) -1 || (__builtin_constant_p (__size) && (__size) > 0)) && __builtin_constant_p ((((long unsigned int) (__size)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__size)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getcwd_chk_warn (__buf, __size, __builtin_object_size (__buf, 2 > 1)) : __getcwd_chk (__buf, __size, __builtin_object_size (__buf, 2 > 1))));
}
extern char *__getwd_chk (char *__buf, size_t buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *__getwd_warn (char *__buf) __asm__ ("" "getwd") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("please use getcwd instead, as getwd " "doesn't specify buffer size")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) getwd (char *__buf)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    return __getwd_chk (__buf, __builtin_object_size (__buf, 2 > 1));
  return __getwd_warn (__buf);
}
extern size_t __confstr_chk (int __name, char *__buf, size_t __len,
        size_t __buflen) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 2, 3)));
extern size_t __confstr_alias (int __name, char *__buf, size_t __len) __asm__ ("" "confstr") __attribute__ ((__nothrow__ , __leaf__))
   __attribute__ ((__access__ (__write_only__, 2, 3)));
extern size_t __confstr_chk_warn (int __name, char *__buf, size_t __len, size_t __buflen) __asm__ ("" "__confstr_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("confstr called with bigger length than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) confstr (int __name, char *__buf, size_t __len)
{
  return ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __confstr_alias (__name, __buf, __len) : ((((__typeof (__len)) 0 < (__typeof (__len)) -1 || (__builtin_constant_p (__len) && (__len) > 0)) && __builtin_constant_p ((((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__len)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __confstr_chk_warn (__name, __buf, __len, __builtin_object_size (__buf, 2 > 1)) : __confstr_chk (__name, __buf, __len, __builtin_object_size (__buf, 2 > 1))));
}
extern int __getgroups_chk (int __size, __gid_t __list[], size_t __listlen)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int __getgroups_alias (int __size, __gid_t __list[]) __asm__ ("" "getgroups") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int __getgroups_chk_warn (int __size, __gid_t __list[], size_t __listlen) __asm__ ("" "__getgroups_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getgroups called with bigger group count than what " "can fit into destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) getgroups (int __size, __gid_t __list[])
{
  return ((((__typeof (__size)) 0 < (__typeof (__size)) -1 || (__builtin_constant_p (__size) && (__size) > 0)) && __builtin_constant_p ((((long unsigned int) (__size)) <= (__builtin_object_size (__list, 2 > 1)) / (sizeof (__gid_t)))) && (((long unsigned int) (__size)) <= (__builtin_object_size (__list, 2 > 1)) / (sizeof (__gid_t)))) ? __getgroups_alias (__size, __list) : ((((__typeof (__size)) 0 < (__typeof (__size)) -1 || (__builtin_constant_p (__size) && (__size) > 0)) && __builtin_constant_p ((((long unsigned int) (__size)) <= (__builtin_object_size (__list, 2 > 1)) / (sizeof (__gid_t)))) && !(((long unsigned int) (__size)) <= (__builtin_object_size (__list, 2 > 1)) / (sizeof (__gid_t)))) ? __getgroups_chk_warn (__size, __list, __builtin_object_size (__list, 2 > 1)) : __getgroups_chk (__size, __list, __builtin_object_size (__list, 2 > 1))));
}
extern int __ttyname_r_chk (int __fd, char *__buf, size_t __buflen,
       size_t __nreal) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
   __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int __ttyname_r_alias (int __fd, char *__buf, size_t __buflen) __asm__ ("" "ttyname_r") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2)));
extern int __ttyname_r_chk_warn (int __fd, char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__ttyname_r_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2))) __attribute__((__warning__ ("ttyname_r called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) ttyname_r (int __fd, char *__buf, size_t __buflen)
{
  return ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __ttyname_r_alias (__fd, __buf, __buflen) : ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __ttyname_r_chk_warn (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1)) : __ttyname_r_chk (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1))));
}
extern int __getlogin_r_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __getlogin_r_alias (char *__buf, size_t __buflen) __asm__ ("" "getlogin_r") __attribute__ ((__nonnull__ (1)));
extern int __getlogin_r_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__getlogin_r_chk")
     __attribute__ ((__nonnull__ (1))) __attribute__((__warning__ ("getlogin_r called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
getlogin_r (char *__buf, size_t __buflen)
{
  return ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getlogin_r_alias (__buf, __buflen) : ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getlogin_r_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1)) : __getlogin_r_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1))));
}
extern int __gethostname_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __gethostname_alias (char *__buf, size_t __buflen) __asm__ ("" "gethostname") __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __gethostname_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__gethostname_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__((__warning__ ("gethostname called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) gethostname (char *__buf, size_t __buflen)
{
  return ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __gethostname_alias (__buf, __buflen) : ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __gethostname_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1)) : __gethostname_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1))));
}
extern int __getdomainname_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __getdomainname_alias (char *__buf, size_t __buflen) __asm__ ("" "getdomainname") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__warn_unused_result__)) __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int __getdomainname_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__getdomainname_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getdomainname called with bigger " "buflen than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) getdomainname (char *__buf, size_t __buflen)
{
  return ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && (((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getdomainname_alias (__buf, __buflen) : ((((__typeof (__buflen)) 0 < (__typeof (__buflen)) -1 || (__builtin_constant_p (__buflen) && (__buflen) > 0)) && __builtin_constant_p ((((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) && !(((long unsigned int) (__buflen)) <= (__builtin_object_size (__buf, 2 > 1)) / (sizeof (char)))) ? __getdomainname_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1)) : __getdomainname_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1))));
}

static inline char *jwt_CreateHeader();
void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize);
static inline size_t jwt_Base64_Size(size_t sz);
static inline void jwt_EncodeElement(JsonElement payload, uint8_t *code, size_t *sz);
void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize);
void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz);
void jwt_DecodeBase64(HttpString str, uint8_t *response, size_t *responseSz);
void jwt_FromBase64URLEncodedToNormal(HttpString str, uint8_t *response, size_t *sz);
static inline uint8_t jwt_CharValid(char chr);
uint8_t jwt_IsJWTCorrectlyFormatted(HttpString str);
static inline void jwt_Add_String(Array strDrt, HttpString str) {
  for(size_t i = 0, c = str.sz; i < c; i++) {
    arr_Push(strDrt, &str.buffer[i]);
  }
}
static inline void jwt_Add_Char(Array strDrt, char chr) {
  arr_Push(strDrt, &chr);
}
static inline void jwt_Add_Header(Array strDrt) {
  char *header = jwt_CreateHeader();
  size_t sz = strlen(header);
  size_t headerBase64Size = jwt_Base64_Size(sz);
  size_t newB64Size;
  uint8_t headerBase64[headerBase64Size + 2];
  jwt_ToBase64UrlEncoded((HttpString) {
    .buffer = header,
    .sz = sz
  }, headerBase64, &newB64Size);
  jwt_Add_String(strDrt, (HttpString) {
    .buffer = (char *)headerBase64,
    .sz = newB64Size
  });
}
void jwt_AddSignature(Array str, HttpString secret) {
  HttpString newStr = {
    .buffer = str->buffer,
    .sz = str->size
  };
  const size_t csz = jwt_Base64_Size(32);
  uint8_t hmacResult[csz + 2];
  size_t newB64Size;
  jwt_HMAC(newStr, secret, hmacResult, &newB64Size);
  jwt_Add_Char(str, '.');
  for(size_t i = 0; i < newB64Size; i++) {
    arr_Push(str, &hmacResult[i]);
  }
}
HttpString jwt_Encode_t(JsonElement payload, HttpString secret, uint64_t iam, uint64_t expirationInMS) {
  Array response = arr_Init(sizeof(char));
  jwt_Add_Header(response);
  jwt_Add_Char(response, '.');
  json_Map_Add(payload, "iat", json_Integer_Create((int64_t)iam));
  json_Map_Add(payload, "exp", json_Integer_Create((int64_t)expirationInMS + iam));
  HttpString payloadString = json_Element_ToString(payload);
  size_t payloadBase64Size = jwt_Base64_Size(payloadString.sz);
  uint8_t payloadBase64[payloadBase64Size + 1];
  size_t cB64Sz;
  jwt_EncodeElement(payload, payloadBase64, &cB64Sz);
  jwt_Add_String(response, (HttpString) {
    .buffer = (char *)payloadBase64,
    .sz = cB64Sz
  });
  jwt_AddSignature(response, secret);
  char *bff = response->buffer;
  size_t sz = response->size;
  arr_DeleteWOBuffer(response);
  free(payloadString.buffer);
  return (HttpString){
    .buffer = bff,
    .sz = sz
  };
}
void jwt_FromBase64URLEncodedToNormal(HttpString str, uint8_t *response, size_t *sz) {
  size_t paddingNeeded = (4 - (str.sz % 4)) % 4;
  size_t z = 0;
  for(size_t i = 0, c = str.sz; i < c; i++) {
    switch (str.buffer[i])
    {
      case '-': {
        response[i] = '+';
        break;
      }
      case '_': {
        response[i] = '/';
        break;
      }
      default: {
        response[i] = str.buffer[i];
        break;
      }
    }
    z++;
  }
  for(size_t p = 0; p < paddingNeeded; p++) {
    response[z++] = '=';
  }
  *sz = z;
}
void jwt_DecodeBase64(HttpString str, uint8_t *response, size_t *responseSz) {
  BIO *bio, *b64;
  b64 = BIO_new(BIO_f_base64());
  BIO_set_flags(b64, 0x100);
  bio = BIO_new_mem_buf((void*)str.buffer, str.sz);
  bio = BIO_push(b64, bio);
  ssize_t currentResponseSize = BIO_read(bio, response, str.sz);
  BIO_free_all(bio);
  if(currentResponseSize <= 0) {
    *responseSz = 0;
    return ;
  }
  *responseSz = (size_t)currentResponseSize;
}
uint8_t jwt_DecodeURLEncodedBase64(HttpString str, uint8_t *response, size_t *responseSz) {
  uint8_t decoded[str.sz + 5];
  size_t sz;
  jwt_FromBase64URLEncodedToNormal(str, decoded, &sz);
  jwt_DecodeBase64((HttpString) {
    .buffer = (char *)decoded,
    .sz = sz
  }, response, responseSz);
  return *responseSz != 0;
}
size_t jwt_ExtractStringChecker(HttpString str) {
  size_t sz = 0;
  while(sz < str.sz && str.buffer[sz] != '.') {
    sz++;
  }
  return sz;
}
uint8_t jwt_IsHeaderValid(HttpString str) {
  size_t headerSize = jwt_ExtractStringChecker(str);
  size_t headerDecodedSize;
  uint8_t headerResponse[str.sz + 1];
  jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)str.buffer,
    .sz = headerSize
  }, headerResponse, &headerDecodedSize);
  if(!headerDecodedSize) {
    return 0;
  }
  JsonElement headerJson = json_Parse((HttpString) {
    .buffer = (char *)headerResponse,
    .sz = headerDecodedSize
  }, ((void *)0));
  if(headerJson.type != JSON_JSON) {
    json_DeleteElement(headerJson);
    return 0;
  }
  JsonElement encryptionType = json_Map_GetString(headerJson, "alg");
  if(encryptionType.type != JSON_STRING) {
    json_DeleteElement(headerJson);
    return 0;
  }
  char *acceptedAlgorithm = "HS256";
  size_t acceptedAlgorithmSize = strlen(acceptedAlgorithm);
  PHttpString algoString = (PHttpString)encryptionType.value;
  if(algoString->sz != acceptedAlgorithmSize) {
    json_DeleteElement(headerJson);
    return 0;
  }
  if(memcmp(acceptedAlgorithm, algoString->buffer, acceptedAlgorithmSize)) {
    json_DeleteElement(headerJson);
    return 0;
  }
  json_DeleteElement(headerJson);
  return 1;
}
uint8_t jwt_Payload_AreTokensValid(JsonElement payload) {
  JsonElement exp = json_Map_GetString(payload, "exp");
  if(exp.type == JSON_INVALID) {
    return 1;
  }
  if(exp.type != JSON_INTEGER) {
    return 0;
  }
  int64_t expDate = json_Integer_Get(exp);
  if(expDate <= tf_CurrentTimeMS()) {
    return 0;
  }
  return 1;
}
static inline uint8_t jwt_CharValid(char chr) {
  return (chr >= '0' && chr <= '9') ||
         (chr >= 'A' && chr <= 'Z') ||
         (chr >= 'a' && chr <= 'z') ||
          chr == '_' || chr == '-';
}
uint8_t jwt_IsJWTCorrectlyFormatted(HttpString str) {
  if(str.sz >= 1024 * 1024 * 10) {
    return 0;
  }
  int8_t pnt = 0;
  size_t index = 0;
  int8_t checker = 0;
  while(index < str.sz) {
    if(jwt_CharValid(str.buffer[index])) {
      checker = 1;
    } else if(str.buffer[index] == '.') {
      if(!checker) {
        return 0;
      }
      checker = 0;
      pnt++;
    } else {
      return 0;
    }
    index++;
  }
  return pnt == 2 && checker;
}
uint8_t jwt_IsPayloadValid(HttpString str) {
  size_t headerSize = jwt_ExtractStringChecker(str);
  HttpString payloadString = {
    .buffer = headerSize + str.buffer + 1,
    .sz = str.sz - headerSize - 1
  };
  ssize_t cSz = payloadString.sz - 1;
  while(cSz >= 0 && payloadString.buffer[cSz] != '.') {
    cSz--;
  }
  payloadString.sz = cSz;
  size_t payloadDecodedSize;
  uint8_t payloadResponse[payloadString.sz + 1];
  jwt_DecodeURLEncodedBase64(payloadString, payloadResponse, &payloadDecodedSize);
  if(!payloadDecodedSize) {
    return 0;
  }
  JsonElement payloadJson = json_Parse((HttpString) {
    .buffer = (char *)payloadResponse,
    .sz = payloadDecodedSize
  }, ((void *)0));
  if(payloadJson.type != JSON_JSON) {
    json_DeleteElement(payloadJson);
    return 0;
  }
  if(!jwt_Payload_AreTokensValid(payloadJson)) {
    json_DeleteElement(payloadJson);
    return 0;
  }
  json_DeleteElement(payloadJson);
  return 1;
}
uint8_t jwt_IsValid(HttpString str, HttpString secret) {
  if(!jwt_IsJWTCorrectlyFormatted(str)) {
    return 0;
  }
  if(!jwt_IsHeaderValid(str) || !jwt_IsPayloadValid(str)) {
    return 0;
  }
  return jwt_IsSigned(str, secret);
}
static inline void jwt_HeaderPayload(HttpString jwtStr, HttpString *headerPtr, HttpString *payloadPtr) {
  size_t firstPointIndex = 0;
  while(firstPointIndex < jwtStr.sz && jwtStr.buffer[firstPointIndex] != '.') {
    firstPointIndex++;
  }
  size_t secondPointIndex = firstPointIndex + 1;
  while(secondPointIndex < jwtStr.sz && jwtStr.buffer[secondPointIndex] != '.') {
    secondPointIndex++;
  }
  headerPtr->buffer = jwtStr.buffer;
  headerPtr->sz = firstPointIndex;
  payloadPtr->buffer = jwtStr.buffer + firstPointIndex + 1;
  payloadPtr->sz = secondPointIndex - firstPointIndex - 1;
}
PJWT jwt_Parse(HttpString jwtStr, HttpString secret) {
  if(!jwt_IsValid(jwtStr, secret)) {
    return ((void *)0);
  }
  PJWT response = malloc(sizeof(JWT));
  memset(response, 0, sizeof(JWT));
  HttpString header;
  HttpString payload;
  jwt_HeaderPayload(jwtStr, &header, &payload);
  uint8_t headerStr[header.sz];
  size_t headerSize;
  if(!jwt_DecodeURLEncodedBase64(header, headerStr, &headerSize)) {
    jwt_Delete(response);
    return ((void *)0);
  }
  uint8_t payloadStr[payload.sz];
  size_t payloadSize;
  if(!jwt_DecodeURLEncodedBase64(payload, payloadStr, &payloadSize)) {
    jwt_Delete(response);
    return ((void *)0);
  }
  JsonElement headerJson = json_Parse((HttpString) {
    .buffer = (char *)headerStr,
    .sz = headerSize
  }, ((void *)0));
  JsonElement payloadJson = json_Parse((HttpString) {
    .buffer = (char *)payloadStr,
    .sz = payloadSize
  }, ((void *)0));
  response->header = headerJson;
  response->payload = payloadJson;
  if(payloadJson.type != JSON_JSON || headerJson.type != JSON_JSON) {
    jwt_Delete(response);
    return ((void *)0);
  }
  return response;
}
void jwt_Delete(PJWT self) {
  json_DeleteElement(self->header);
  json_DeleteElement(self->payload);
  free(self);
}
HttpString jwt_Encode(JsonElement payload, HttpString secret, uint64_t expirationInMS) {
  return jwt_Encode_t(payload, secret, tf_CurrentTimeMS(), expirationInMS);
}
static inline void jwt_EncodeElement(JsonElement payload, uint8_t *code, size_t *sz) {
  HttpString payloadString = json_Element_ToString(payload);
  jwt_ToBase64UrlEncoded(payloadString, code, sz);
  free(payloadString.buffer);
}
void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize) {
  unsigned int hmac_length = 0;
  uint8_t hmalRes[50];
  HMAC(
    EVP_sha256(),
    (uint8_t *)secret.buffer, secret.sz,
    (uint8_t *)key.buffer, key.sz,
    hmalRes, &hmac_length
  );
  jwt_ToBase64UrlEncoded((HttpString) {
    .buffer = (char *)hmalRes,
    .sz = 32
  }, hmacResult, currentSize);
}
void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz) {
  printf("HMAC-SHA256: ");
  for (unsigned int i = 0; i < sz; i++)
    printf("%c", hmacCode[i]);
  printf("\n");
}
static inline size_t jwt_Base64_Size(size_t sz) {
  return 4 * ((sz + 2) / 3);
}
size_t jwt_Base64_Size_Public(size_t sz) {
  return jwt_Base64_Size(sz);
}
void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize) {
  const size_t cSize = jwt_Base64_Size(str.sz);
  EVP_EncodeBlock(response, (uint8_t *)str.buffer, str.sz);
  for(size_t i = 0; i < cSize; i++) {
    if (response[i] == '+') {
      response[i] = '-';
    }
    else if (response[i] == '/') {
      response[i] = '_';
    }
  }
  if(!finalSize) {
    return ;
  }
  *finalSize = cSize;
  while(*finalSize > 0 && response[(*finalSize) - 1] == '=') {
    (*finalSize)--;
  }
}
uint8_t jwt_IsSigned(HttpString str, HttpString secret) {
  char *buffer = str.buffer;
  size_t sz = 0;
  int8_t pnt = 0;
  while(sz < str.sz && pnt < 2) {
    if(buffer[sz] == '.') {
      pnt++;
    }
    sz++;
  }
  size_t sigSize = str.sz - sz;
  if(pnt != 2 || sigSize <= 30) {
    return 0;
  }
  const size_t csz = jwt_Base64_Size(32);
  uint8_t hmacResult[csz + 2];
  size_t newB64Size;
  jwt_HMAC((HttpString) {
    .buffer = buffer,
    .sz = sz - 1
  }, secret, hmacResult, &newB64Size);
  if(newB64Size != sigSize) {
    return 0;
  }
  return !memcmp(buffer + sz, hmacResult, newB64Size);
}
static inline char *jwt_CreateHeader() {
  return "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
}
static inline size_t tpd_Min(const size_t a, const size_t b) {
  return a < b ? a : b;
}
PNetworkBuffer tpd_Create(size_t maxSizeB) {
  PNetworkBuffer self = malloc(sizeof(NetworkBuffer));
  const size_t capacity = 16;
  self->buffer = malloc(capacity);
  self->currentBuffer = self->buffer;
  self->size = 0;
  self->capacity = capacity;
  self->maxRetriedSize = 0;
  self->maxSizeB = maxSizeB;
  return self;
}
void tpd_Delete(PNetworkBuffer self) {
  free(self->buffer);
  free(self);
}
size_t tpd_Size(PNetworkBuffer self) {
  return self->size;
}
static inline void tpd_Retract_Realloc(const PNetworkBuffer self) {
  self->capacity = self->size * 2 + 1;
  void *newBuffer = malloc(self->capacity);
  memcpy(newBuffer, self->currentBuffer, (size_t)(self->size));
  free(self->buffer);
  self->buffer = newBuffer;
  self->currentBuffer = newBuffer;
  self->maxRetriedSize = self->size;
}
void tpd_Retract(PNetworkBuffer self, size_t bytes) {
  bytes = tpd_Min(bytes, self->size);
  self->size -= bytes;
  self->currentBuffer += bytes;
  if(self->maxRetriedSize >= (self->size << 1)) {
    tpd_Retract_Realloc(self);
    return ;
  }
}
void *tpd_StartingBuffer(PNetworkBuffer self) {
  return self->currentBuffer;
}
static inline void tpd_OverPush(const PNetworkBuffer self, const void *buffer, const size_t size) {
  while(self->capacity <= size + self->maxRetriedSize) {
    self->capacity <<= 1;
  }
  void *newBuffer = malloc(self->capacity);
  memcpy(newBuffer, self->currentBuffer, self->size);
  free(self->buffer);
  self->buffer = newBuffer;
  self->currentBuffer = newBuffer;
}
static inline void *tpd_EndBuffer(const PNetworkBuffer self) {
  return (void *)(self->currentBuffer + self->size);
}
uint8_t tpd_Push(PNetworkBuffer self, void *buffer, size_t size) {
  if(self->size + size >= self->maxSizeB) {
    return 0;
  }
  if(self->maxRetriedSize + size >= self->capacity) {
    tpd_OverPush(self, buffer, size);
  }
  memcpy(tpd_EndBuffer(self), buffer, size);
  self->size += size;
  self->maxRetriedSize += size;
  return 1;
}

struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
enum __socket_type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 00004000
};
typedef unsigned short int sa_family_t;
struct sockaddr
  {
    sa_family_t sa_family;
    char sa_data[14];
  };
struct sockaddr_storage
  {
    sa_family_t ss_family;
    char __ss_padding[(128 - (sizeof (unsigned short int)) - sizeof (unsigned long int))];
    unsigned long int __ss_align;
  };
enum
  {
    MSG_OOB = 0x01,
    MSG_PEEK = 0x02,
    MSG_DONTROUTE = 0x04,
    MSG_CTRUNC = 0x08,
    MSG_PROXY = 0x10,
    MSG_TRUNC = 0x20,
    MSG_DONTWAIT = 0x40,
    MSG_EOR = 0x80,
    MSG_WAITALL = 0x100,
    MSG_FIN = 0x200,
    MSG_SYN = 0x400,
    MSG_CONFIRM = 0x800,
    MSG_RST = 0x1000,
    MSG_ERRQUEUE = 0x2000,
    MSG_NOSIGNAL = 0x4000,
    MSG_MORE = 0x8000,
    MSG_WAITFORONE = 0x10000,
    MSG_BATCH = 0x40000,
    MSG_ZEROCOPY = 0x4000000,
    MSG_FASTOPEN = 0x20000000,
    MSG_CMSG_CLOEXEC = 0x40000000
  };
struct msghdr
  {
    void *msg_name;
    socklen_t msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    int msg_flags;
  };
struct cmsghdr
  {
    size_t cmsg_len;
    int cmsg_level;
    int cmsg_type;
    __extension__ unsigned char __cmsg_data [];
  };
extern struct cmsghdr *__cmsg_nxthdr (struct msghdr *__mhdr,
          struct cmsghdr *__cmsg) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) struct cmsghdr *
__attribute__ ((__nothrow__ , __leaf__)) __cmsg_nxthdr (struct msghdr *__mhdr, struct cmsghdr *__cmsg)
{
  if ((size_t) __cmsg->cmsg_len < sizeof (struct cmsghdr))
    return (struct cmsghdr *) 0;
  __cmsg = (struct cmsghdr *) ((unsigned char *) __cmsg
          + (((__cmsg->cmsg_len) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)));
  if ((unsigned char *) (__cmsg + 1) > ((unsigned char *) __mhdr->msg_control
     + __mhdr->msg_controllen)
      || ((unsigned char *) __cmsg + (((__cmsg->cmsg_len) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1))
   > ((unsigned char *) __mhdr->msg_control + __mhdr->msg_controllen)))
    return (struct cmsghdr *) 0;
  return __cmsg;
}
enum
  {
    SCM_RIGHTS = 0x01
  };
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned long __kernel_old_dev_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
 int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
struct linger
  {
    int l_onoff;
    int l_linger;
  };
struct osockaddr
{
  unsigned short int sa_family;
  unsigned char sa_data[14];
};
enum
{
  SHUT_RD = 0,
  SHUT_WR,
  SHUT_RDWR
};
extern int socket (int __domain, int __type, int __protocol) __attribute__ ((__nothrow__ , __leaf__));
extern int socketpair (int __domain, int __type, int __protocol,
         int __fds[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int bind (int __fd, const struct sockaddr * __addr, socklen_t __len)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getsockname (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__ , __leaf__));
extern int connect (int __fd, const struct sockaddr * __addr, socklen_t __len);
extern int getpeername (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto (int __fd, const void *__buf, size_t __n,
         int __flags, const struct sockaddr * __addr,
         socklen_t __addr_len);
extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n,
    int __flags, struct sockaddr *__restrict __addr,
    socklen_t *__restrict __addr_len);
extern ssize_t sendmsg (int __fd, const struct msghdr *__message,
   int __flags);
extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags);
extern int getsockopt (int __fd, int __level, int __optname,
         void *__restrict __optval,
         socklen_t *__restrict __optlen) __attribute__ ((__nothrow__ , __leaf__));
extern int setsockopt (int __fd, int __level, int __optname,
         const void *__optval, socklen_t __optlen) __attribute__ ((__nothrow__ , __leaf__));
extern int listen (int __fd, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int accept (int __fd, struct sockaddr *__restrict __addr,
     socklen_t *__restrict __addr_len);
extern int shutdown (int __fd, int __how) __attribute__ ((__nothrow__ , __leaf__));
extern int sockatmark (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int isfdtype (int __fd, int __fdtype) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t __recv_chk (int __fd, void *__buf, size_t __n, size_t __buflen,
      int __flags);
extern ssize_t __recv_alias (int __fd, void *__buf, size_t __n, int __flags) __asm__ ("" "recv");
extern ssize_t __recv_chk_warn (int __fd, void *__buf, size_t __n, size_t __buflen, int __flags) __asm__ ("" "__recv_chk")
     __attribute__((__warning__ ("recv called with bigger length than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) ssize_t
recv (int __fd, void *__buf, size_t __n, int __flags)
{
  size_t sz = __builtin_object_size (__buf, 0);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && (((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __recv_alias (__fd, __buf, __n, __flags);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __recv_chk_warn (__fd, __buf, __n, sz, __flags);
  return __recv_chk (__fd, __buf, __n, sz, __flags);
}
extern ssize_t __recvfrom_chk (int __fd, void *__restrict __buf, size_t __n,
          size_t __buflen, int __flags,
          struct sockaddr *__restrict __addr,
          socklen_t *__restrict __addr_len);
extern ssize_t __recvfrom_alias (int __fd, void *__restrict __buf, size_t __n, int __flags, struct sockaddr *__restrict __addr, socklen_t *__restrict __addr_len) __asm__ ("" "recvfrom");
extern ssize_t __recvfrom_chk_warn (int __fd, void *__restrict __buf, size_t __n, size_t __buflen, int __flags, struct sockaddr *__restrict __addr, socklen_t *__restrict __addr_len) __asm__ ("" "__recvfrom_chk")
     __attribute__((__warning__ ("recvfrom called with bigger length than size of " "destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) ssize_t
recvfrom (int __fd, void *__restrict __buf, size_t __n, int __flags,
   struct sockaddr *__restrict __addr, socklen_t *__restrict __addr_len)
{
  size_t sz = __builtin_object_size (__buf, 0);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && (((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __recvfrom_alias (__fd, __buf, __n, __flags, __addr, __addr_len);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __recvfrom_chk_warn (__fd, __buf, __n, sz, __flags, __addr,
    __addr_len);
  return __recvfrom_chk (__fd, __buf, __n, sz, __flags, __addr, __addr_len);
}


typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
struct ip_opts
  {
    struct in_addr ip_dst;
    char ip_opts[40];
  };
struct ip_mreqn
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
  };
struct in_pktinfo
  {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
  };
enum
  {
    IPPROTO_IP = 0,
    IPPROTO_ICMP = 1,
    IPPROTO_IGMP = 2,
    IPPROTO_IPIP = 4,
    IPPROTO_TCP = 6,
    IPPROTO_EGP = 8,
    IPPROTO_PUP = 12,
    IPPROTO_UDP = 17,
    IPPROTO_IDP = 22,
    IPPROTO_TP = 29,
    IPPROTO_DCCP = 33,
    IPPROTO_IPV6 = 41,
    IPPROTO_RSVP = 46,
    IPPROTO_GRE = 47,
    IPPROTO_ESP = 50,
    IPPROTO_AH = 51,
    IPPROTO_MTP = 92,
    IPPROTO_BEETPH = 94,
    IPPROTO_ENCAP = 98,
    IPPROTO_PIM = 103,
    IPPROTO_COMP = 108,
    IPPROTO_SCTP = 132,
    IPPROTO_UDPLITE = 136,
    IPPROTO_MPLS = 137,
    IPPROTO_ETHERNET = 143,
    IPPROTO_RAW = 255,
    IPPROTO_MPTCP = 262,
    IPPROTO_MAX
  };
enum
  {
    IPPROTO_HOPOPTS = 0,
    IPPROTO_ROUTING = 43,
    IPPROTO_FRAGMENT = 44,
    IPPROTO_ICMPV6 = 58,
    IPPROTO_NONE = 59,
    IPPROTO_DSTOPTS = 60,
    IPPROTO_MH = 135
  };
typedef uint16_t in_port_t;
enum
  {
    IPPORT_ECHO = 7,
    IPPORT_DISCARD = 9,
    IPPORT_SYSTAT = 11,
    IPPORT_DAYTIME = 13,
    IPPORT_NETSTAT = 15,
    IPPORT_FTP = 21,
    IPPORT_TELNET = 23,
    IPPORT_SMTP = 25,
    IPPORT_TIMESERVER = 37,
    IPPORT_NAMESERVER = 42,
    IPPORT_WHOIS = 43,
    IPPORT_MTP = 57,
    IPPORT_TFTP = 69,
    IPPORT_RJE = 77,
    IPPORT_FINGER = 79,
    IPPORT_TTYLINK = 87,
    IPPORT_SUPDUP = 95,
    IPPORT_EXECSERVER = 512,
    IPPORT_LOGINSERVER = 513,
    IPPORT_CMDSERVER = 514,
    IPPORT_EFSSERVER = 520,
    IPPORT_BIFFUDP = 512,
    IPPORT_WHOSERVER = 513,
    IPPORT_ROUTESERVER = 520,
    IPPORT_RESERVED = 1024,
    IPPORT_USERRESERVED = 5000
  };
struct in6_addr
  {
    union
      {
 uint8_t __u6_addr8[16];
 uint16_t __u6_addr16[8];
 uint32_t __u6_addr32[4];
      } __in6_u;
  };
extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
struct sockaddr_in
  {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[sizeof (struct sockaddr)
      - (sizeof (unsigned short int))
      - sizeof (in_port_t)
      - sizeof (struct in_addr)];
  };
struct sockaddr_in6
  {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
  };
struct ip_mreq
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
  };
struct ip_mreq_source
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
    struct in_addr imr_sourceaddr;
  };
struct ipv6_mreq
  {
    struct in6_addr ipv6mr_multiaddr;
    unsigned int ipv6mr_interface;
  };
struct group_req
  {
    uint32_t gr_interface;
    struct sockaddr_storage gr_group;
  };
struct group_source_req
  {
    uint32_t gsr_interface;
    struct sockaddr_storage gsr_group;
    struct sockaddr_storage gsr_source;
  };
struct ip_msfilter
  {
    struct in_addr imsf_multiaddr;
    struct in_addr imsf_interface;
    uint32_t imsf_fmode;
    uint32_t imsf_numsrc;
    struct in_addr imsf_slist[1];
  };
struct group_filter
  {
    uint32_t gf_interface;
    struct sockaddr_storage gf_group;
    uint32_t gf_fmode;
    uint32_t gf_numsrc;
    struct sockaddr_storage gf_slist[1];
};
extern uint32_t ntohl (uint32_t __netlong) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint16_t ntohs (uint16_t __netshort)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint32_t htonl (uint32_t __hostlong)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint16_t htons (uint16_t __hostshort)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int bindresvport (int __sockfd, struct sockaddr_in *__sock_in) __attribute__ ((__nothrow__ , __leaf__));
extern int bindresvport6 (int __sockfd, struct sockaddr_in6 *__sock_in)
     __attribute__ ((__nothrow__ , __leaf__));


extern in_addr_t inet_addr (const char *__cp) __attribute__ ((__nothrow__ , __leaf__));
extern in_addr_t inet_lnaof (struct in_addr __in) __attribute__ ((__nothrow__ , __leaf__));
extern struct in_addr inet_makeaddr (in_addr_t __net, in_addr_t __host)
     __attribute__ ((__nothrow__ , __leaf__));
extern in_addr_t inet_netof (struct in_addr __in) __attribute__ ((__nothrow__ , __leaf__));
extern in_addr_t inet_network (const char *__cp) __attribute__ ((__nothrow__ , __leaf__));
extern char *inet_ntoa (struct in_addr __in) __attribute__ ((__nothrow__ , __leaf__));
extern int inet_pton (int __af, const char *__restrict __cp,
        void *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern const char *inet_ntop (int __af, const void *__restrict __cp,
         char *__restrict __buf, socklen_t __len)
     __attribute__ ((__nothrow__ , __leaf__));
extern int inet_aton (const char *__cp, struct in_addr *__inp) __attribute__ ((__nothrow__ , __leaf__));
extern char *inet_neta (in_addr_t __net, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use inet_ntop instead")));
extern char *inet_net_ntop (int __af, const void *__cp, int __bits,
       char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int inet_net_pton (int __af, const char *__cp,
     void *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int inet_nsap_addr (const char *__cp,
        unsigned char *__buf, int __len) __attribute__ ((__nothrow__ , __leaf__));
extern char *inet_nsap_ntoa (int __len, const unsigned char *__cp,
        char *__buf) __attribute__ ((__nothrow__ , __leaf__));


typedef __sig_atomic_t sig_atomic_t;
union sigval
{
  int sival_int;
  void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct
  {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {
  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;
  __uint32_t _pkey;
       } _bounds;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,
  SI_TKILL,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK,
  ILL_BADIADDR
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB,
  FPE_FLTUNK = 14,
  FPE_CONDTRAP
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR,
  SEGV_BNDERR,
  SEGV_PKUERR,
  SEGV_ACCADI,
  SEGV_ADIDERR,
  SEGV_ADIPERR,
  SEGV_MTEAERR,
  SEGV_MTESERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR,
  BUS_MCEERR_AR,
  BUS_MCEERR_AO
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef __sigval_t sigval_t;
typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern void psignal (int __sig, const char *__s);
extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));
extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};
struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};
struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};
struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};
struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};
struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));
typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];
struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};
struct _libc_xmmreg
{
  __uint32_t element[4];
};
struct _libc_fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct
  {
    gregset_t gregs;
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;
typedef struct ucontext_t
  {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
    __extension__ unsigned long long int __ssp[4];
  } ucontext_t;
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use sigaction with SA_RESTART instead")));
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
extern int sigaltstack (const stack_t *__restrict __ss,
   stack_t *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));


struct rpcent
{
  char *r_name;
  char **r_aliases;
  int r_number;
};
extern void setrpcent (int __stayopen) __attribute__ ((__nothrow__ , __leaf__));
extern void endrpcent (void) __attribute__ ((__nothrow__ , __leaf__));
extern struct rpcent *getrpcbyname (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern struct rpcent *getrpcbynumber (int __number) __attribute__ ((__nothrow__ , __leaf__));
extern struct rpcent *getrpcent (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getrpcbyname_r (const char *__name, struct rpcent *__result_buf,
      char *__buffer, size_t __buflen,
      struct rpcent **__result) __attribute__ ((__nothrow__ , __leaf__));
extern int getrpcbynumber_r (int __number, struct rpcent *__result_buf,
        char *__buffer, size_t __buflen,
        struct rpcent **__result) __attribute__ ((__nothrow__ , __leaf__));
extern int getrpcent_r (struct rpcent *__result_buf, char *__buffer,
   size_t __buflen, struct rpcent **__result) __attribute__ ((__nothrow__ , __leaf__));

struct netent
{
  char *n_name;
  char **n_aliases;
  int n_addrtype;
  uint32_t n_net;
};

extern int *__h_errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern void herror (const char *__str) __attribute__ ((__nothrow__ , __leaf__));
extern const char *hstrerror (int __err_num) __attribute__ ((__nothrow__ , __leaf__));
struct hostent
{
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};
extern void sethostent (int __stay_open);
extern void endhostent (void);
extern struct hostent *gethostent (void);
extern struct hostent *gethostbyaddr (const void *__addr, __socklen_t __len,
          int __type);
extern struct hostent *gethostbyname (const char *__name);
extern struct hostent *gethostbyname2 (const char *__name, int __af);
extern int gethostent_r (struct hostent *__restrict __result_buf,
    char *__restrict __buf, size_t __buflen,
    struct hostent **__restrict __result,
    int *__restrict __h_errnop);
extern int gethostbyaddr_r (const void *__restrict __addr, __socklen_t __len,
       int __type,
       struct hostent *__restrict __result_buf,
       char *__restrict __buf, size_t __buflen,
       struct hostent **__restrict __result,
       int *__restrict __h_errnop);
extern int gethostbyname_r (const char *__restrict __name,
       struct hostent *__restrict __result_buf,
       char *__restrict __buf, size_t __buflen,
       struct hostent **__restrict __result,
       int *__restrict __h_errnop);
extern int gethostbyname2_r (const char *__restrict __name, int __af,
        struct hostent *__restrict __result_buf,
        char *__restrict __buf, size_t __buflen,
        struct hostent **__restrict __result,
        int *__restrict __h_errnop);
extern void setnetent (int __stay_open);
extern void endnetent (void);
extern struct netent *getnetent (void);
extern struct netent *getnetbyaddr (uint32_t __net, int __type);
extern struct netent *getnetbyname (const char *__name);
extern int getnetent_r (struct netent *__restrict __result_buf,
   char *__restrict __buf, size_t __buflen,
   struct netent **__restrict __result,
   int *__restrict __h_errnop);
extern int getnetbyaddr_r (uint32_t __net, int __type,
      struct netent *__restrict __result_buf,
      char *__restrict __buf, size_t __buflen,
      struct netent **__restrict __result,
      int *__restrict __h_errnop);
extern int getnetbyname_r (const char *__restrict __name,
      struct netent *__restrict __result_buf,
      char *__restrict __buf, size_t __buflen,
      struct netent **__restrict __result,
      int *__restrict __h_errnop);
struct servent
{
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};
extern void setservent (int __stay_open);
extern void endservent (void);
extern struct servent *getservent (void);
extern struct servent *getservbyname (const char *__name, const char *__proto);
extern struct servent *getservbyport (int __port, const char *__proto);
extern int getservent_r (struct servent *__restrict __result_buf,
    char *__restrict __buf, size_t __buflen,
    struct servent **__restrict __result);
extern int getservbyname_r (const char *__restrict __name,
       const char *__restrict __proto,
       struct servent *__restrict __result_buf,
       char *__restrict __buf, size_t __buflen,
       struct servent **__restrict __result);
extern int getservbyport_r (int __port, const char *__restrict __proto,
       struct servent *__restrict __result_buf,
       char *__restrict __buf, size_t __buflen,
       struct servent **__restrict __result);
struct protoent
{
  char *p_name;
  char **p_aliases;
  int p_proto;
};
extern void setprotoent (int __stay_open);
extern void endprotoent (void);
extern struct protoent *getprotoent (void);
extern struct protoent *getprotobyname (const char *__name);
extern struct protoent *getprotobynumber (int __proto);
extern int getprotoent_r (struct protoent *__restrict __result_buf,
     char *__restrict __buf, size_t __buflen,
     struct protoent **__restrict __result);
extern int getprotobyname_r (const char *__restrict __name,
        struct protoent *__restrict __result_buf,
        char *__restrict __buf, size_t __buflen,
        struct protoent **__restrict __result);
extern int getprotobynumber_r (int __proto,
          struct protoent *__restrict __result_buf,
          char *__restrict __buf, size_t __buflen,
          struct protoent **__restrict __result);
extern int setnetgrent (const char *__netgroup);
extern void endnetgrent (void);
extern int getnetgrent (char **__restrict __hostp,
   char **__restrict __userp,
   char **__restrict __domainp);
extern int innetgr (const char *__netgroup, const char *__host,
      const char *__user, const char *__domain);
extern int getnetgrent_r (char **__restrict __hostp,
     char **__restrict __userp,
     char **__restrict __domainp,
     char *__restrict __buffer, size_t __buflen);
extern int rcmd (char **__restrict __ahost, unsigned short int __rport,
   const char *__restrict __locuser,
   const char *__restrict __remuser,
   const char *__restrict __cmd, int *__restrict __fd2p);
extern int rcmd_af (char **__restrict __ahost, unsigned short int __rport,
      const char *__restrict __locuser,
      const char *__restrict __remuser,
      const char *__restrict __cmd, int *__restrict __fd2p,
      sa_family_t __af);
extern int rexec (char **__restrict __ahost, int __rport,
    const char *__restrict __name,
    const char *__restrict __pass,
    const char *__restrict __cmd, int *__restrict __fd2p);
extern int rexec_af (char **__restrict __ahost, int __rport,
       const char *__restrict __name,
       const char *__restrict __pass,
       const char *__restrict __cmd, int *__restrict __fd2p,
       sa_family_t __af);
extern int ruserok (const char *__rhost, int __suser,
      const char *__remuser, const char *__locuser);
extern int ruserok_af (const char *__rhost, int __suser,
         const char *__remuser, const char *__locuser,
         sa_family_t __af);
extern int iruserok (uint32_t __raddr, int __suser,
       const char *__remuser, const char *__locuser);
extern int iruserok_af (const void *__raddr, int __suser,
   const char *__remuser, const char *__locuser,
   sa_family_t __af);
extern int rresvport (int *__alport);
extern int rresvport_af (int *__alport, sa_family_t __af);
struct addrinfo
{
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  socklen_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_canonname;
  struct addrinfo *ai_next;
};
extern int getaddrinfo (const char *__restrict __name,
   const char *__restrict __service,
   const struct addrinfo *__restrict __req,
   struct addrinfo **__restrict __pai);
extern void freeaddrinfo (struct addrinfo *__ai) __attribute__ ((__nothrow__ , __leaf__));
extern const char *gai_strerror (int __ecode) __attribute__ ((__nothrow__ , __leaf__));
extern int getnameinfo (const struct sockaddr *__restrict __sa,
   socklen_t __salen, char *__restrict __host,
   socklen_t __hostlen, char *__restrict __serv,
   socklen_t __servlen, int __flags);


struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };


struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
  };
extern int fcntl (int __fd, int __cmd, ...);
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
extern int __open_2 (const char *__path, int __oflag) __attribute__ ((__nonnull__ (1)));
extern int __open_alias (const char *__path, int __oflag, ...) __asm__ ("" "open") __attribute__ ((__nonnull__ (1)));
extern void __open_too_many_args (void) __attribute__((__error__ ("open can be called either with 2 or 3 arguments, not more")));
extern void __open_missing_mode (void) __attribute__((__error__ ("open with O_CREAT or O_TMPFILE in second argument needs 3 arguments")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
open (const char *__path, int __oflag, ...)
{
  if (__builtin_va_arg_pack_len () > 1)
    __open_too_many_args ();
  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __open_missing_mode ();
   return __open_2 (__path, __oflag);
 }
      return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
    }
  if (__builtin_va_arg_pack_len () < 1)
    return __open_2 (__path, __oflag);
  return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
}
extern int __openat_2 (int __fd, const char *__path, int __oflag)
     __attribute__ ((__nonnull__ (2)));
extern int __openat_alias (int __fd, const char *__path, int __oflag, ...) __asm__ ("" "openat")
     __attribute__ ((__nonnull__ (2)));
extern void __openat_too_many_args (void) __attribute__((__error__ ("openat can be called either with 3 or 4 arguments, not more")));
extern void __openat_missing_mode (void) __attribute__((__error__ ("openat with O_CREAT or O_TMPFILE in third argument needs 4 arguments")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
openat (int __fd, const char *__path, int __oflag, ...)
{
  if (__builtin_va_arg_pack_len () > 1)
    __openat_too_many_args ();
  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __openat_missing_mode ();
   return __openat_2 (__fd, __path, __oflag);
 }
      return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
    }
  if (__builtin_va_arg_pack_len () < 1)
    return __openat_2 (__fd, __path, __oflag);
  return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
}


struct winsize
  {
    unsigned short int ws_row;
    unsigned short int ws_col;
    unsigned short int ws_xpixel;
    unsigned short int ws_ypixel;
  };
struct termio
  {
    unsigned short int c_iflag;
    unsigned short int c_oflag;
    unsigned short int c_cflag;
    unsigned short int c_lflag;
    unsigned char c_line;
    unsigned char c_cc[8];
};
extern int ioctl (int __fd, unsigned long int __request, ...) __attribute__ ((__nothrow__ , __leaf__));

typedef struct CloseConnStruct_t {
  PSocketServer self;
  Connection conn;
  size_t index;
} CloseConnStruct;
typedef CloseConnStruct *PCloseConnStruct;
uint8_t _sock_StartConnections(PSocketServer self);
void sigpipe_handler(int signum) {
  return ;
}
PSocketServer sock_Create(uint16_t port) {
  PSocketServer server = malloc(sizeof(SocketServer));
  memset(server, 0, sizeof(SocketServer));
  server->connections = arr_Init(sizeof(Connection));
  server->port = port;
  server->maxActiveConnections = 16;
  server->maxBytesPerReadConnection = 1024 * 1024 * 10;
  server->inputReads = arr_Init(sizeof(DataFragment));
  server->outputCommands = arr_Init(sizeof(DataFragment));
  server->closeConnectionsQueue = arr_Init(sizeof(Connection));
  if(!_sock_StartConnections(server)) {
    sock_Delete(server);
    return ((void *)0);
  }
  return server;
}
void _sock_CloseConnection(void *buffer) {
  PCloseConnStruct conn = buffer;
  close(conn->conn.fd);
  arr_RemoveElement(conn->self->connections, conn->index);
  free(buffer);
}
void sock_PushCloseConnMethod(PSocketServer self, Connection conn, size_t index) {
  if(!self->timeServer.timeServer) {
    return ;
  }
  PCloseConnStruct closeCmd = malloc(sizeof(CloseConnStruct));
  closeCmd->conn = conn;
  closeCmd->self = self;
  closeCmd->index = index;
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)_sock_CloseConnection,
    .buffer = closeCmd
  };
  tf_ExecuteAfter(self->timeServer.timeServer, timeFragment, self->timeServer.timeout);
}
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections) {
  ((void) sizeof ((maxActiveConnections < 1024) ? 1 : 0), __extension__ ({ if (maxActiveConnections < 1024) ; else __assert_fail ("maxActiveConnections < MAX_CONNECTIONS_PER_SERVER", "bin/svv.c", 3665, __extension__ __PRETTY_FUNCTION__); }));
  self->maxActiveConnections = maxActiveConnections;
}
void sock_Write_Push(PSocketServer self, DataFragment *dt) {
  char *memory = dt->data;
  if(dt->persistent) {
    memory = malloc(dt->size);
    memcpy(memory, dt->data, dt->size);
  }
  DataFragment newDt = *dt;
  newDt.data = memory;
  arr_Push(self->outputCommands, &newDt);
}
Connection sock_InvalidConnection() {
  return (Connection) {
    .fd = -1
  };
}
uint8_t _sock_StartConnections(PSocketServer self) {
  int32_t sockfd;
  struct sockaddr_in servaddr;
  sockfd = socket(2, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return 0;
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = 2;
  servaddr.sin_addr.s_addr = __bswap_32 (((in_addr_t) 0x00000000));
  servaddr.sin_port = __bswap_16 (self->port);
  signal(13, sigpipe_handler);
  const int32_t trueFlag = 1;
  if (setsockopt(sockfd, 1, 2, &trueFlag, sizeof(int)) < 0) {
    return 0;
  }
  if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
    return 0;
  }
  if ((listen(sockfd, 5)) != 0) {
    return 0;
  }
  self->serverFD.fd = sockfd;
  fcntl(sockfd, 4, fcntl(sockfd, 3, 0) | 04000);
  return 1;
}
static inline void sock_ExecuteMetaMethod(Connection *conn, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(Connection, void *) = routine->method;
  method(*conn, routine->mirrorBuffer);
}
static inline void sock_ExecuteOnReceiveMethod(DataFragment *dataFragment, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(DataFragment *, void *) = routine->method;
  method(dataFragment, routine->mirrorBuffer);
}
static inline void sock_ReadData(PSocketServer self, Connection *conn, char *buffer, size_t count) {
  (void)!read(conn->fd, buffer, count);
  DataFragment dt = (DataFragment) {
    .conn = *conn,
    .data = buffer,
    .persistent = 0,
    .size = count
  };
  sock_ExecuteOnReceiveMethod(&dt, self->onReceiveMessage);
}
static inline ssize_t sock_FindConnIndex(PSocketServer self, PConnection conn) {
  Connection *connections = self->connections->buffer;
  for(ssize_t i = 0, c = (ssize_t)self->connections->buffer; i < c; i++) {
    if(conn->fd == connections[i].fd) {
      return i;
    }
  }
  return -1;
}
void sock_CloseConnection(PSocketServer self, size_t index) {
  Connection conn = ((Connection *)self->connections->buffer)[index];
  close(conn.fd);
  arr_RemoveElement(self->connections, index);
}
void sock_PushCloseConnections(PSocketServer self, PConnection conn) {
  arr_Push(self->closeConnectionsQueue, conn);
}
size_t sock_DoesConnectionExists(PSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  Connection *connections = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    if(connections[i].fd == conn->fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}
void sock_ClearPushedConnections(PSocketServer self) {
  Connection *connections = self->closeConnectionsQueue->buffer;
  Array indexes = arr_Init(sizeof(size_t));
  uint8_t found;
  for(size_t i = 0, c = self->closeConnectionsQueue->size; i < c; i++) {
    size_t connIndex = sock_DoesConnectionExists(self, &connections[i], &found);
    if(found) {
      close(connections[i].fd);
      arr_Push(indexes, &connIndex);
    }
  }
  arr_RemoveElementsWithReplacing(&self->connections, indexes);
  arr_Delete(indexes);
  arr_Clear(self->closeConnectionsQueue);
}
static inline void sock_OnReceiveMessage(PSocketServer self, Connection *conn, size_t index) {
  size_t count = 0;
  int32_t error = ioctl(conn->fd, 0x541B, &count);
  if(!count || error == -1) {
    return ;
  }
  if(count >= self->maxBytesPerReadConnection) {
    sock_ExecuteMetaMethod(conn, self->onConnectionRelease);
    sock_CloseConnection(self, index);
    return ;
  }
  if(count <= (1<<12)) {
    char buffer[(1<<12)];
    sock_ReadData(self, conn, buffer, count);
    return ;
  }
  void *buffer = malloc(count);
  sock_ReadData(self, conn, buffer, count);
  free(buffer);
}
void sock_ProcessReadMessage(PSocketServer self) {
  Connection *conn = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    sock_OnReceiveMessage(self, &conn[i], i);
  }
}
static inline void sock_AcceptConnectionsRoutine(PSocketServer self) {
  if(self->maxActiveConnections <= self->connections->size) {
    return ;
  }
  struct sockaddr_in cli;
  socklen_t len;
  int32_t sockfd = self->serverFD.fd;
  len = sizeof( (struct sockaddr *) &len);
  int32_t connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
  if (connfd < 0) {
    return ;
  }
  Connection currentCon = (Connection) {
    .fd = connfd
  };
  sock_PushCloseConnMethod(self, currentCon, self->connections->size);
  arr_Push(self->connections, &currentCon);
  sock_ExecuteMetaMethod(&currentCon, self->onConnectionAquire);
}
static inline void sock_WriteBufferCleanup(PSocketServer self) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(dataFragments[i].persistent) {
      free(dataFragments[i].data);
    }
  }
  arr_Clear(self->outputCommands);
}
PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer) {
  PSocketMethod self = malloc(sizeof(SocketMethod));
  self->method = method;
  self->mirrorBuffer = mirrorBuffer;
  return self;
}
void sock_Method_Delete(PSocketMethod self) {
  free(self);
}
void sock_ProcessWriteRequests_t(PSocketServer self, Array markedForDeletionRequests) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    ssize_t response = send(dataFragments[i].conn.fd, dataFragments[i].data, dataFragments[i].size, MSG_DONTWAIT);
    if(response < 0) {
      arr_Push(markedForDeletionRequests, &i);
      sock_ExecuteMetaMethod(&dataFragments[i].conn, self->onConnectionRelease);
      close(dataFragments[i].conn.fd);
    }
  }
}
size_t sock_ConnectionCount(PSocketServer self) {
  return self->connections->size;
}
static inline void sock_ProcessWriteRequests(PSocketServer self) {
  Array markedForDeletionRequests = arr_Init(sizeof(size_t));
  sock_ProcessWriteRequests_t(self, markedForDeletionRequests);
  sock_WriteBufferCleanup(self);
  Array prunnedArray = arr_RemoveElements(self->connections, markedForDeletionRequests);
  arr_Delete(self->connections);
  arr_Delete(markedForDeletionRequests);
  self->connections = prunnedArray;
}
static inline void sock_ClearConnections(PSocketServer self) {
  Connection *conn = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    close(conn[i].fd);
  }
  arr_Delete(self->closeConnectionsQueue);
  arr_Delete(self->connections);
}
PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index) {
  if(index >= self->connections->size) {
    return ((void *)0);
  }
  Connection *conn = self->connections->buffer;
  return conn + index;
}
static inline void sock_Time_OnFrame(PSocketServer self, uint64_t deltaMS) {
  if(self->timeServer.timeServer) {
    tf_OnFrame(self->timeServer.timeServer, deltaMS);
  }
}
void sock_OnFrame(PSocketServer self, uint64_t deltaMS) {
  sock_AcceptConnectionsRoutine(self);
  sock_ProcessReadMessage(self);
  sock_ProcessWriteRequests(self);
  sock_ClearPushedConnections(self);
  sock_Time_OnFrame(self, deltaMS);
}
static inline void sock_Time_Delete(PSocketServer self) {
  if(self->timeServer.timeServer) {
    tf_Delete(self->timeServer.timeServer);
  }
}
int32_t _sock_Client_Conn(uint16_t port, char *ip) {
  int32_t sock;
  struct sockaddr_in server_addr;
  sock = socket(2, SOCK_STREAM, 0);
  if (sock < 0) {
    return -1;
  }
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = 2;
  server_addr.sin_port = __bswap_16 (port);
  if (inet_pton(2, ip, &server_addr.sin_addr) <= 0) {
    close(sock);
    return -1;
  }
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    close(sock);
    return -1;
  }
  fcntl(sock, 4, fcntl(sock, 3, 0) | 04000);
  return sock;
}
PConnection sock_Client_Connect(uint16_t port, char *ip) {
  int32_t fd = _sock_Client_Conn(port, ip);
  if(fd == -1) {
    return ((void *)0);
  }
  PConnection conn = malloc(sizeof(Connection));
  conn->fd = fd;
  return conn;
}
void sock_Client_SendMessage(PDataFragment frag) {
  (void)!send(frag->conn.fd, frag->data, frag->size, MSG_DONTWAIT);
}
DataFragment sock_Client_Receive(PConnection conn) {
  Array dataToRead = arr_Init(sizeof(char));
  char bufferChunk[1024];
  ssize_t bytesRead = -1;
  while((bytesRead = recv(conn->fd, bufferChunk, sizeof(bufferChunk), 0)) && bytesRead != -1) {
    for(size_t i = 0; i < bytesRead; i++) {
      arr_Push(dataToRead, &bufferChunk[i]);
    }
  }
  DataFragment fragment = {
    .conn = *conn,
    .data = dataToRead->buffer,
    .persistent = 0,
    .size = dataToRead->size
  };
  arr_DeleteWOBuffer(dataToRead);
  return fragment;
}
HttpString sock_Client_ReceiveWithErrors(PConnection conn) {
  DataFragment dt = sock_Client_Receive(conn);
  if(!dt.size) {
    free(dt.data);
    return (HttpString) {
      .buffer = ((void *)0),
    };
  }
  return (HttpString) {
    .buffer = dt.data,
    .sz = dt.size
  };
}
void sock_Client_Free(PConnection conn) {
  close(conn->fd);
  free(conn);
}
static inline void sock_Delete_OutputCommands(PSocketServer self) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(dataFragments[i].persistent) {
      free(dataFragments[i].data);
    }
  }
  arr_Delete(self->outputCommands);
}
void sock_Delete(PSocketServer self) {
  arr_Delete(self->inputReads);
  sock_ClearConnections(self);
  sock_Delete_OutputCommands(self);
  close(self->serverFD.fd);
  sock_Time_Delete(self);
  free(self);
}
HttpString string_DeepCopy(HttpString str) {
  HttpString response = {
    .buffer = ((void *)0),
    .sz = 0
  };
  if(!str.buffer) {
    return response;
  }
  response.buffer = malloc(str.sz);
  memcpy(response.buffer, str.buffer, str.sz);
  response.sz = str.sz;
  return response;
}
void string_Print(HttpString str) {
  printf("%.*s\n", (int32_t)str.sz, str.buffer);
}

struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
extern int gettimeofday (struct timeval *__restrict __tv,
    void *__restrict __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef int __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));

uint64_t tf_CurrentTimeMS() {
  struct timeval tv;
  gettimeofday(&tv, ((void *)0));
  return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}
PTimeServer tf_Create() {
  PTimeServer self = malloc(sizeof(TimeServer));
  self->methods = arr_Init(sizeof(TimeFragment));
  self->loopMethods = arr_Init(sizeof(TimeFragment));
  return self;
}
void tf_Delete(PTimeServer self) {
  arr_Delete(self->methods);
  arr_Delete(self->loopMethods);
  free(self);
}
void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod
  };
  arr_Push(self->methods, &fragment);
}
static inline void tf_ExecuteFragMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->methods->buffer;
  Array fragmentsToRemove = arr_Init(sizeof(size_t));
  for(size_t i = 0, c = self->methods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      arr_Push(fragmentsToRemove, &i);
    }
  }
  Array cpyVector = arr_RemoveElements(self->methods, fragmentsToRemove);
  arr_Delete(self->methods);
  self->methods = cpyVector;
  arr_Delete(fragmentsToRemove);
}
static inline void tf_ExecuteLoopMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->loopMethods->buffer;
  for(size_t i = 0, c = self->loopMethods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      fragment[i].executeAfter = fragment[i].time;
    }
  }
}
void tf_ExecuteLoop(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod,
    .time = afterMS
  };
  arr_Push(self->loopMethods, &fragment);
}
void tf_OnFrame(PTimeServer self, uint64_t deltaMS) {
  tf_ExecuteFragMethods(self, deltaMS);
  tf_ExecuteLoopMethods(self, deltaMS);
}
PUser usr_Create(PUserData parent) {
  PUser self = malloc(sizeof(User));
  memset(self, 0, sizeof(User));
  return self;
}
PUserData usrs_Create() {
  PUserData self = malloc(sizeof(UserData));
  memset(self, 0, sizeof(UserData));
  self->users = arr_Init(sizeof(User));
  return self;
}
static void usrs_DeleteAllUsers(const PUserData self) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    free(users[i]);
  }
  arr_Delete(self->users);
}
void usrs_AddUser(PUserData self, uint64_t ID) {
  PUser usr = malloc(sizeof(User));
  usr->active = 0;
  usr->conn = ((void *)0);
  usr->ID = ID;
  arr_Push(self->users, &usr);
}
void usrs_Delete(PUserData self) {
  usrs_DeleteAllUsers(self);
  free(self);
}
static inline PUser usrs_PlyByID(PUserData self, uint64_t ID) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->ID == ID) {
      return users[i];
    }
  }
  return ((void *)0);
}
size_t usrs_ConnID(PUserData self, PConnection conn, uint8_t *ok) {
  PUser *users = self->users->buffer;
  *ok = 0;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->conn && users[i]->conn->fd == conn->fd) {
      *ok = 1;
      return i;
    }
  }
  return 0;
}
PUser usrs_ByIndex(PUserData self, uint64_t index) {
  PUser *users = self->users->buffer;
  if(index >= self->users->size) {
    return ((void *)0);
  }
  return users[index];
}
PUser usrs_Activate(PUserData self, uint64_t ID, PConnection conn) {
  PUser currentUser = usrs_PlyByID(self, ID);
  if(!currentUser) {
    return 0;
  }
  currentUser->active = 1;
  currentUser->conn = conn;
  return currentUser;
}
PUser usrs_Get(PUserData self, uint64_t ID) {
  return usrs_PlyByID(self, ID);
}
void usrs_Deactivate(PUserData self, PConnection conn) {
  User *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i].conn->fd == conn->fd) {
      users[i].conn = ((void *)0);
      users[i].active = 0;
      return ;
    }
  }
}
void usr_Deactivate(PUser self) {
  self->conn = ((void *)0);
  self->active = 0;
}
PUser usrs_ByConnection(PUserData self, PConnection conn) {
  PUser *users = self->users->buffer;
  for(size_t i = 0, c = self->users->size; i < c; i++) {
    if(users[i]->conn->fd == conn->fd) {
      return users[i];
    }
  }
  return ((void *)0);
}
        
typedef struct SHAstate_st {
    unsigned int h0, h1, h2, h3, h4;
    unsigned int Nl, Nh;
    unsigned int data[16];
    unsigned int num;
} SHA_CTX;
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA1_Init(SHA_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA1_Update(SHA_CTX *c, const void *data, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA1_Final(unsigned char *md, SHA_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void SHA1_Transform(SHA_CTX *c, const unsigned char *data);
unsigned char *SHA1(const unsigned char *d, size_t n, unsigned char *md);
typedef struct SHA256state_st {
    unsigned int h[8];
    unsigned int Nl, Nh;
    unsigned int data[16];
    unsigned int num, md_len;
} SHA256_CTX;
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA224_Init(SHA256_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA224_Update(SHA256_CTX *c,
                                        const void *data, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA224_Final(unsigned char *md, SHA256_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA256_Init(SHA256_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA256_Update(SHA256_CTX *c,
                                        const void *data, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA256_Final(unsigned char *md, SHA256_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void SHA256_Transform(SHA256_CTX *c,
                                            const unsigned char *data);
unsigned char *SHA224(const unsigned char *d, size_t n, unsigned char *md);
unsigned char *SHA256(const unsigned char *d, size_t n, unsigned char *md);
typedef struct SHA512state_st {
    unsigned long long h[8];
    unsigned long long Nl, Nh;
    union {
        unsigned long long d[16];
        unsigned char p[(16*8)];
    } u;
    unsigned int num, md_len;
} SHA512_CTX;
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA384_Init(SHA512_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA384_Update(SHA512_CTX *c,
                                        const void *data, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA384_Final(unsigned char *md, SHA512_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA512_Init(SHA512_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA512_Update(SHA512_CTX *c,
                                        const void *data, size_t len);
__attribute__((deprecated("Since OpenSSL " "3.0"))) int SHA512_Final(unsigned char *md, SHA512_CTX *c);
__attribute__((deprecated("Since OpenSSL " "3.0"))) void SHA512_Transform(SHA512_CTX *c,
                                            const unsigned char *data);
unsigned char *SHA384(const unsigned char *d, size_t n, unsigned char *md);
unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md);
       
char *wbs_ToWebSocket(WebSocketObject self);
Array wbs_FromWebSocket(char *msg, size_t bufferSize);
void wbs_Print(char *buffer);
size_t wbs_FullMessageSize(char *buffer);
char *wbs_NextMessageIterator(char *st, size_t maxMessageSize);
uint8_t wbs_IsBufferValid(char *buffer, size_t sz);
void wbs_Clear_FromWebSocket(Array objects);
char *wbs_Masked_ToWebSocket(WebSocketObject self);
void wbs_MaskSwitch(char *buffer);
char *wbs_Ping(WebSocketObject self);
WebSocketObject wbs_Get(char *left, char *right);
size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Raw_Public_HeaderSize(char *buffer);
char *wbs_Public_PayloadBuffer(char *buffer);
uint8_t wbs_Public_GetCode(char *buffer);
Array wbs_Public_ParseData(PNetworkBuffer self);
void wbs_Public_FreeParseData(Array arr);
typedef struct PingConnData_t {
  Connection conn;
  uint64_t payload;
  int64_t remainingTime;
} PingConnData;
typedef struct ConnectionProtocol_t {
  Connection conn;
  PNetworkBuffer buff;
} ConnectionProtocol;
void wss_SetMethods(PWebSocketServer self);
void _wss_OnConnect(Connection connection, void *buffer);
void _wss_OnReceive(PDataFragment dt, void *buffer);
void _wss_OnRelease(Connection conn, void *buffer);
static inline void wss_RunCloseConnRoutine(PWebSocketServer self, Connection conn);
static inline uint8_t wss_RemovePingRequest(PWebSocketServer self, PDataFragment dt);
static inline uint8_t wss_IsPingRequestIssued(PWebSocketServer self, PDataFragment dt);
static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found);
static inline void wss_FreeConn(const ConnectionProtocol conn);
static inline void wss_RemoveConnBuffer(const Array arr, const size_t index);
static inline ConnectionProtocol *wss_FindConn(const PWebSocketServer self, const PDataFragment dt);
static inline uint64_t _wss_Rand() {
  uint64_t response;
  char *buffer = (char *)&response;
  for(size_t i = 0; i < sizeof(uint64_t); i++) {
    buffer[i] = (rand() & 255);
  }
  return response;
}
PWebSocketServer wss_Create(uint16_t port) {
  PWebSocketServer self = malloc(sizeof(WebSocketServer));
  memset(self, 0, sizeof(WebSocketServer));
  self->socketServer = sock_Create(port);
  self->pendingConnections = arr_Init(sizeof(ConnectionProtocol));
  self->pendingPingRequests = arr_Init(sizeof(PingConnData));
  self->activeConnections = arr_Init(sizeof(ConnectionProtocol));
  self->maxBSize = 1024 * 1024;
  self->maxBSizeForHttpReq = 1024 * 4;
  wss_SetMethods(self);
  return self;
}
void _wss_LoopPingPong(void *buffer) {
  PWebSocketServer self = buffer;
  Connection *conns = self->socketServer->connections->buffer;
  for(size_t i = 0, c = self->socketServer->connections->size; i < c; i++) {
    uint8_t found;
    (void)!wss_FindConnectionOnThePull(self, &conns[i], &found);
    if(found) {
      continue;
    }
    PingConnData pingDt = (PingConnData) {
      .conn = conns[i],
      .remainingTime = self->timeServer->timeout / 2,
      .payload = _wss_Rand()
    };
    arr_Push(self->pendingPingRequests, &pingDt);
    char *pingRequest = wbs_ToWebSocket((WebSocketObject) {
      .buffer = (char *)&((PingConnData *)arr_Last(self->pendingPingRequests))->payload,
      .sz = sizeof(uint64_t),
      .opcode = OPCODE_PING
    });
    DataFragment fragment = {
      .conn = conns[i],
      .data = pingRequest,
      .size = wbs_FullMessageSize(pingRequest),
      .persistent = 1
    };
    sock_Write_Push(self->socketServer, &fragment);
    free(pingRequest);
  }
}
void wss_SetMethod(PWebSocketServer self) {
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)_wss_LoopPingPong,
    .buffer = self
  };
  tf_ExecuteLoop(self->timeServer->server, timeFragment, self->timeServer->timeout);
}
void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout) {
  if(!self->timeServer) {
    self->timeServer = malloc(sizeof(Timers));
    self->timeServer->server = tf_Create();
  }
  self->timeServer->timeout = timeout;
  wss_SetMethod(self);
}
void wss_SetMethods(PWebSocketServer self) {
  PSocketMethod _onConnect = sock_Method_Create(
    _wss_OnConnect,
    self
  );
  self->methodsBundle._onConnect = _onConnect;
  self->socketServer->onConnectionAquire = _onConnect;
  PSocketMethod _onReceive = sock_Method_Create(
    _wss_OnReceive,
    self
  );
  self->methodsBundle._onReceive = _onReceive;
  self->socketServer->onReceiveMessage = _onReceive;
  PSocketMethod _onRelease = sock_Method_Create(
    _wss_OnRelease,
    self
  );
  self->methodsBundle._onRelease = _onRelease;
  self->socketServer->onConnectionRelease = _onRelease;
}
static inline void wss_Tf_Delete(PWebSocketServer self) {
  if(!self->timeServer) {
    return ;
  }
  tf_Delete(self->timeServer->server);
  free(self->timeServer);
}
static inline void wss_CloseConnections(PWebSocketServer self, Connection conn) {
  wss_RunCloseConnRoutine(self, conn);
  sock_PushCloseConnections(self->socketServer, &conn);
}
void wss_ProcessTimeoutPingRequests(PWebSocketServer self, uint64_t deltaMS) {
  PingConnData *pings = self->pendingPingRequests->buffer;
  Array indexesToRemove = arr_Init(sizeof(size_t));
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    pings[i].remainingTime -= (int64_t)deltaMS;
    if(pings[i].remainingTime <= 0) {
      arr_Push(indexesToRemove, &i);
      wss_CloseConnections(self, pings[i].conn);
    }
  }
  Array cpyVector = arr_RemoveElements(self->pendingPingRequests, indexesToRemove);
  arr_Delete(self->pendingPingRequests);
  self->pendingPingRequests = cpyVector;
  arr_Delete(indexesToRemove);
}
static inline void wss_ReleaseActiveConnections(const PWebSocketServer self) {
  ConnectionProtocol *conns = self->activeConnections->buffer;
  for(size_t i = 0, c = self->activeConnections->size; i < c; i++) {
    tpd_Delete(conns[i].buff);
  }
  arr_Delete(self->activeConnections);
}
static inline void wss_FreeConn(const ConnectionProtocol conn) {
  if(conn.buff) {
    tpd_Delete(conn.buff);
  }
}
void wss_FreeConnectionPayload(const Array arr) {
  const ConnectionProtocol *cp = arr->buffer;
  for(size_t i = 0, c = arr->size; i < c; i++) {
    wss_FreeConn(cp[i]);
  }
  arr_Delete(arr);
}
void wss_Delete(PWebSocketServer self) {
  sock_Method_Delete(self->methodsBundle._onReceive);
  sock_Method_Delete(self->methodsBundle._onConnect);
  sock_Method_Delete(self->methodsBundle._onRelease);
  wss_Tf_Delete(self);
  wss_FreeConnectionPayload(self->pendingConnections);
  arr_Delete(self->pendingPingRequests);
  wss_ReleaseActiveConnections(self);
  sock_Delete(self->socketServer);
  free(self);
}
static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  ConnectionProtocol *connections = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(conn->fd == connections[i].conn.fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}
char *webSocketKey(PHttpString sec_websocket_key) {
  static const char *GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
  if (!sec_websocket_key->buffer) return ((void *)0);
  size_t key_len = sec_websocket_key->sz;
  size_t guid_len = strlen(GUID);
  size_t cat_len = key_len + guid_len;
  char *cat = (char *)malloc(cat_len + 1);
  if (!cat) return ((void *)0);
  memcpy(cat, sec_websocket_key->buffer, key_len);
  memcpy(cat + key_len, GUID, guid_len);
  cat[cat_len] = '\0';
  unsigned char sha1_digest[20];
  SHA1((const unsigned char *)cat, cat_len, sha1_digest);
  free(cat);
  int b64_len = 4 * ((20 + 2) / 3);
  char *accept = (char *)malloc(b64_len + 1);
  if (!accept) return ((void *)0);
  EVP_EncodeBlock((unsigned char *)accept, sha1_digest, 20);
  accept[b64_len] = '\0';
  return accept;
}
PHttpResponse wss_Response(PWebSocketServer self, PHttpRequest req) {
  PHttpResponse response = http_Response_Empty();
  response->response = 101;
  http_Response_Set(response, "Upgrade", sizeof("Upgrade") - 1, "websocket", sizeof("websocket") - 1);
  http_Response_Set(response, "Connection", sizeof("Connection") - 1, "Upgrade", sizeof("Upgrade") - 1);
  HttpString key = http_Request_GetValue(req, "Sec-WebSocket-Key");
  if(!key.buffer) {
    http_Response_Delete(response);
    return ((void *)0);
  }
  char *newKey = webSocketKey(&key);
  http_Response_Set(response, "Sec-WebSocket-Accept", sizeof("Sec-WebSocket-Accept") - 1, newKey, strlen(newKey));
  free(newKey);
  return response;
}
void wss_SendMessage(PWebSocketServer self, PDataFragment dt) {
  WebSocketObject objs = {
    .buffer = dt->data,
    .sz = dt->size,
    .opcode = OPCODE_BINARY
  };
  char *response = wbs_ToWebSocket(objs);
  DataFragment fragment = {
    .conn = dt->conn,
    .data = response,
    .size = wbs_FullMessageSize(response),
    .persistent = 1
  };
  sock_Write_Push(self->socketServer, &fragment);
  free(response);
}
static inline ConnectionProtocol *wss_FindConn(const PWebSocketServer self, const PDataFragment dt) {
  ConnectionProtocol *protocol = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(protocol[i].conn.fd == dt->conn.fd) {
      return &protocol[i];
    }
  }
  return ((void *)0);
}
PHttpRequest wss_ProcessHttpRequest(const PWebSocketServer self, const PDataFragment dt, uint8_t *incomplete) {
  *incomplete = 0;
  ConnectionProtocol *proto = wss_FindConn(self, dt);
  if(!proto) {
    return ((void *)0);
  }
  if(!tpd_Push(proto->buff, dt->data, dt->size)) {
    return ((void *)0);
  }
  PHttpRequest req = http_Request_NB_Get(proto->buff);
  if(!req) {
    *incomplete = 1;
    return ((void *)0);
  }
  return req;
}
uint8_t wss_ProcessConnectionRequest(PWebSocketServer self, PDataFragment dt, uint8_t *incomplete) {
  PHttpRequest req = wss_ProcessHttpRequest(self, dt, incomplete);
  if(!req) {
    return 0;
  }
  PHttpResponse response = wss_Response(self, req);
  http_Request_Delete(req);
  if(!response) {
    return 0;
  }
  HttpString responseChar = http_Response_ToString(response);
  DataFragment frag = {
    .conn = dt->conn,
    .data = responseChar.buffer,
    .persistent = 1,
    .size = responseChar.sz
  };
  sock_Write_Push(self->socketServer, &frag);
  http_Response_Delete(response);
  free(responseChar.buffer);
  return 1;
}
PNetworkBuffer wss_FindPayloadChecker(const PWebSocketServer self, const PDataFragment dt) {
  ConnectionProtocol *conns = self->activeConnections->buffer;
  for(size_t i = 0, c = self->activeConnections->size; i < c; i++) {
    if(dt->conn.fd == conns[i].conn.fd) {
      return conns[i].buff;
    }
  }
  return ((void *)0);
}
PNetworkBuffer wss_NetworkBuffer(const PWebSocketServer self, const PDataFragment dt) {
  PNetworkBuffer buff = wss_FindPayloadChecker(self, dt);
  if(!buff) {
    return ((void *)0);
  }
  if(!tpd_Push(buff, dt->data, dt->size)) {
    return ((void *)0);
  }
  return buff;
}
Array wss_GetObject(const PWebSocketServer self, const PDataFragment dt) {
  PNetworkBuffer protoBuff = wss_NetworkBuffer(self, dt);
  if(!protoBuff) {
    return ((void *)0);
  }
  return wbs_Public_ParseData(protoBuff);
}
static inline void wss_CleanMessages(const Array arr) {
  wbs_Public_FreeParseData(arr);
}
int8_t wss_ReceiveMessages(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  Array messages = wss_GetObject(self, dt);
  if(!messages) {
    return 0;
  }
  WebSocketObject *objects = messages->buffer;
  DataFragment responseDt = {
    .conn = dt->conn,
    .data = ((void *)0),
    .persistent = 0,
    .size = 0
  };
  uint8_t validConnection = !wss_IsPingRequestIssued(self, &responseDt);
  for(size_t i = 0, c = messages->size; i < c; i++) {
    responseDt.data = objects[i].buffer;
    responseDt.size = objects[i].sz;
    if(objects[i].opcode == OPCODE_CONNECTION_CLOSE) {
      wss_CloseConnections(self, responseDt.conn);
      continue;
    }
    if(!validConnection && objects[i].opcode == OPCODE_PONG && wss_RemovePingRequest(self, &responseDt)) {
      validConnection = 1;
      continue;
    }
    if(!routine || (objects[i].opcode != OPCODE_BINARY && objects[i].opcode != OPCODE_TEXT_FRAME)) {
      continue;
    }
    void (*cMethod)(PDataFragment, void *) = routine->method;
    cMethod(&responseDt, routine->mirrorBuffer);
  }
  wss_CleanMessages(messages);
  return validConnection;
}
static inline void wss_ProcessReleaseMethod(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(self->onRelease) {
    void (*cMethod)(Connection, void *) = self->onRelease->method;
    cMethod(dt->conn, self->onRelease->mirrorBuffer);
  }
}
static inline uint8_t wss_IsPingRequestIssued(PWebSocketServer self, PDataFragment dt) {
  PingConnData *pingBuffer = self->pendingPingRequests->buffer;
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    if(pingBuffer[i].conn.fd == dt->conn.fd) {
      return 1;
    }
  }
  return 0;
}
static inline uint8_t wss_RemovePingRequest(PWebSocketServer self, PDataFragment dt) {
  PingConnData *pingBuffer = self->pendingPingRequests->buffer;
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    if(dt->size == sizeof(uint64_t) && pingBuffer[i].payload == *(uint64_t *)dt->data) {
      arr_RemoveElement(self->pendingPingRequests, i);
      return 1;
    }
  }
  return 0;
}
static inline void wss_ProcessWsRequests(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(!wss_ReceiveMessages(self, dt, routine)) {
    wss_ProcessReleaseMethod(self, dt, routine);
    sock_PushCloseConnections(self->socketServer, &dt->conn);
  }
}
void wss_SetMaxBSizeSocket(PWebSocketServer self, size_t bytesSize) {
  self->maxBSize = bytesSize;
}
static inline void wss_AddConnection(const PWebSocketServer self, const Connection conn) {
  ConnectionProtocol conns = {
    .conn = conn,
    .buff = tpd_Create(self->maxBSize)
  };
  arr_Push(self->activeConnections, &conns);
}
void _wss_OnReceive(PDataFragment dt, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &dt->conn, &found);
  if(!found) {
    wss_ProcessWsRequests(self, dt, self->onReceiveMessage);
    return ;
  }
  uint8_t incomplete;
  uint8_t request = wss_ProcessConnectionRequest(self, dt, &incomplete);
  if(incomplete) {
    return ;
  }
  wss_RemoveConnBuffer(self->pendingConnections, connIndex);
  if(!request) {
    sock_PushCloseConnections(self->socketServer, &dt->conn);
    return ;
  }
  if(self->onConnect) {
    void (*cMethod)(PConnection, void *) = self->onConnect->method;
    cMethod(&dt->conn, self->onConnect->mirrorBuffer);
  }
  wss_AddConnection(self, dt->conn);
}
size_t wss_ConnectionsCount(PWebSocketServer self) {
  return sock_ConnectionCount(self->socketServer);
}
void _wss_OnConnect(Connection connection, void *buffer) {
  PWebSocketServer self = buffer;
  ConnectionProtocol conn = {
    .conn = connection,
    .buff = tpd_Create(self->maxBSizeForHttpReq)
  };
  arr_Push(self->pendingConnections, &conn);
}
static inline void wss_RunCloseConnRoutine(PWebSocketServer self, Connection conn) {
  if(self->onRelease) {
    void (*cMethod)(Connection, void *) = self->onRelease->method;
    cMethod(conn, self->onRelease->mirrorBuffer);
  }
}
static inline void wss_RemoveConnBuffer(const Array arr, const size_t index) {
  wss_FreeConn(((ConnectionProtocol *)arr->buffer)[index]);
  arr_RemoveElement(arr, index);
}
void _wss_OnRelease(Connection conn, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &conn, &found);
  if(found) {
    wss_RemoveConnBuffer(self->pendingConnections, connIndex);
    return ;
  }
  wss_RunCloseConnRoutine(self, conn);
}
static inline void wss_Tf_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  if(self->timeServer) {
    tf_OnFrame(self->timeServer->server, deltaMS);
  }
}
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  wss_Tf_OnFrame(self, deltaMS);
  wss_ProcessTimeoutPingRequests(self, deltaMS);
  sock_OnFrame(self->socketServer, deltaMS);
}
static inline char *wbs_PayloadBuffer(char *buffer);
static inline uint8_t wbs_IsMasked(char *buffer);
static inline char *wbs_MaskOffset(char *msg);
static inline void wbs_SetOpcodeTo(char *buffer, Opcode code) {
  buffer[0] |= code;
}
static inline void wbs_SetFin(char *buffer) {
  buffer[0] |= (1<<7);
}
static inline uint8_t wbs_GetCode(char *buffer) {
  return buffer[0] & ((1<<7) - 1);
}
uint8_t wbs_Public_GetCode(char *buffer) {
  return wbs_GetCode(buffer);
}
static inline void wbs_ClearHeaderBytes(char *buffer) {
  buffer[0] = 0;
  buffer[1] = 0;
}
static inline void wbs_SetMaskFlag(char *buffer) {
  buffer[1] |= (1<<7);
}
static inline uint8_t wbs_SizeCode(char *buffer) {
  return (buffer[1] & ((1<<7) - 1));
}
static inline void wbs_RevertBytes(char *st, char *end, char *dst) {
  end--;
  for(char *it = end; it >= st; it--) {
    *dst = *it;
    dst++;
  }
}
static inline size_t wbs_SetPayloadSize(char *buffer, const PWebSocketObject obj) {
  char *currentNumberPointer = (char *)&obj->sz;
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  switch (wbs_SizeCode(buffer))
  {
    case 126: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint16_t), buffer + 2);
      return sizeof(uint16_t) + maskSize;
      break;
    }
    case 127: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint64_t), buffer + 2);
      return sizeof(uint64_t) + maskSize;
      break;
    }
    default:
      break;
  }
  return maskSize;
}
static inline void wbs_WritePayload(char *buffer, const PWebSocketObject obj) {
  memcpy(buffer, obj->buffer, obj->sz);
}
static inline size_t wbs_Object_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  size_t maskData = shouldBeMasked * 4;
  if(obj->sz <= 125) {
    return obj->sz + 2 + maskData;
  }
  if(obj->sz <= (1<<16)) {
    return obj->sz + 4 + maskData;
  }
  return obj->sz + 10 + maskData;
}
static inline size_t wbs_Raw_HeaderSize(char *buffer) {
  return (size_t)(wbs_PayloadBuffer(buffer) - buffer);
}
size_t wbs_Raw_Public_HeaderSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer);
}
size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  return wbs_Object_HeaderSize(obj, shouldBeMasked);
}
static inline char *wbs_SetPayloadCode(char *buffer, const PWebSocketObject obj) {
  if(obj->sz <= 125) {
    buffer[1] |= obj->sz;
  }
  else if(obj->sz <= (1<<16)) {
    buffer[1] |= 126;
  } else {
    buffer[1] |= 127;
  }
  return buffer + 1 + wbs_SetPayloadSize(buffer, obj);
}
void _wbs_PrintNextBytes(char *buffer, size_t sz) {
  printf("(");
  for(size_t i = 0; i < sz; i++) {
    printf("0x%x ", (uint8_t)buffer[i]);
  }
  printf(")\n");
}
static inline uint8_t wbs_IsMasked(char *buffer) {
  return (buffer[1] & (1<<7)) > 0;
}
static inline size_t wbs_PayloadSize(char *buffer) {
  size_t result = 0;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return size;
  }
  if(size == 126) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint16_t), (char *)&result);
    return result;
  }
  if(size == 127) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint64_t), (char *)&result);
    return result;
  }
  return 0;
}
size_t wbs_Public_PayloadSize(char *buffer) {
  return wbs_PayloadSize(buffer);
}
static inline char *wbs_PayloadBuffer(char *buffer) {
  size_t maskOffset = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return buffer + 2 + maskOffset;
  }
  if(size == 126) {
    return buffer + 4 + maskOffset;
  }
  return buffer + 10 + maskOffset;
}
char *wbs_Public_PayloadBuffer(char *buffer) {
  return wbs_PayloadBuffer(buffer);
}
uint8_t wbs_IsBufferValid(char *buffer, size_t sz) {
  char *endBuffer = buffer + sz;
  while(buffer < endBuffer) {
    size_t currentSize = (size_t)(endBuffer - buffer);
    char *nextBuffer = wbs_NextMessageIterator(buffer, currentSize);
    if(!nextBuffer) {
      return 0;
    }
    buffer = nextBuffer;
  }
  return buffer == endBuffer;
}
static inline size_t wbs_ValidMinimumSize(char *buffer) {
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return 2 + maskSize;
  }
  if(size == 126) {
    return 4 + maskSize;
  }
  return 10 + maskSize;
}
char *wbs_NextMessageIterator(char *st, size_t maxMessageSize) {
  if(maxMessageSize < 2) {
    return ((void *)0);
  }
  if(wbs_ValidMinimumSize(st) > maxMessageSize) {
    return ((void *)0);
  }
  size_t messageSz = wbs_FullMessageSize(st);
  if(messageSz > maxMessageSize) {
    return ((void *)0);
  }
  return st + messageSz;
}
size_t wbs_FullMessageSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer) + wbs_PayloadSize(buffer);
}
void wbs_Print(char *buffer) {
  printf("First byte 0x%x\n", (uint8_t)buffer[0]);
  uint8_t size = wbs_SizeCode(buffer);
  printf("Size cateogry byte is 0x%x\n", size);
  switch (size)
  {
    case 126:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint16_t));
      break;
    case 127:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint64_t));
      break;
    default:
      break;
  }
  printf("Mask bit is 0x%x\n", wbs_IsMasked(buffer));
  const size_t payloadSize = wbs_PayloadSize(buffer), messageSize = wbs_FullMessageSize(buffer);
  printf("Payload is size is %ld\n", payloadSize);
  _wbs_PrintNextBytes(wbs_PayloadBuffer(buffer), payloadSize);
  printf("Full message size is %ld\n", messageSize);
  _wbs_PrintNextBytes(buffer, messageSize);
}
static inline char *_wbs_ToWebSocket(WebSocketObject self, Opcode opcode) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 0));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetOpcodeTo(response, opcode);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 ;
  wbs_WritePayload(cpyResponse, &self);
  return response;
}
WebSocketObject wbs_Get(char *left, char *right) {
  return (WebSocketObject) {};
}
char *wbs_ToWebSocket(WebSocketObject self) {
  return _wbs_ToWebSocket(self, self.opcode);
}
void wbs_MaskSwitch(char *buffer) {
  char *maskOffset = wbs_MaskOffset(buffer);
  char *payloadOffset = wbs_PayloadBuffer(buffer);
  for(size_t i = 0, c = 0, z = wbs_PayloadSize(buffer); i < z; i++, c = ((c + 1) & 3)) {
    payloadOffset[i] ^= maskOffset[c];
  }
}
static inline void wbs_Mask_Set(char *buffer) {
  if(!wbs_IsMasked(buffer)) {
    return ;
  }
  char *maskOffset = wbs_MaskOffset(buffer);
  for(size_t i = 0; i < sizeof(uint32_t); i++) {
    maskOffset[i] = (rand() & 0xFF);
  }
  wbs_MaskSwitch(buffer);
}
char *wbs_Masked_ToWebSocket(WebSocketObject self) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 1));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetMaskFlag(response);
  wbs_SetOpcodeTo(response, self.opcode);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 ;
  wbs_WritePayload(cpyResponse, &self);
  wbs_Mask_Set(response);
  return response;
}
char *wbs_Ping(WebSocketObject self) {
  return _wbs_ToWebSocket(self, OPCODE_PING);
}
static inline char *wbs_UnmaskedBuffer(char *msg) {
  return wbs_PayloadBuffer(msg);
}
static inline char *wbs_MaskOffset(char *msg) {
  return wbs_PayloadBuffer(msg) - sizeof(uint32_t);
}
static inline char *wbs_MaskedPayload(char *msg) {
  wbs_MaskSwitch(msg);
  return wbs_PayloadBuffer(msg);
}
char *wbs_ExtractPayload(char *msg) {
  if(!wbs_IsMasked(msg)) {
    return wbs_UnmaskedBuffer(msg);
  }
  return wbs_MaskedPayload(msg);
}
void wbs_Clear_FromWebSocket(Array objects) {
  arr_Delete(objects);
}
Array wbs_FromWebSocket(char *msg, size_t bufferSize) {
  if(!wbs_IsBufferValid(msg, bufferSize)) {
    return ((void *)0);
  }
  char *endBuffer = msg + bufferSize;
  Array buffer = arr_Init(sizeof(WebSocketObject));
  while(msg < endBuffer) {
    WebSocketObject obj = (WebSocketObject) {
      .buffer = wbs_ExtractPayload(msg),
      .sz = wbs_PayloadSize(msg),
      .opcode = wbs_GetCode(msg)
    };
    if(!obj.buffer) {
      wbs_Clear_FromWebSocket(buffer);
      return ((void *)0);
    }
    arr_Push(buffer, &obj);
    msg += wbs_FullMessageSize(msg);
  }
  return buffer;
}
Array wbs_Public_ParseData(PNetworkBuffer self) {
  size_t sz = tpd_Size(self);
  Array response = arr_Init(sizeof(WebSocketObject));
  while((sz = tpd_Size(self)) && sz) {
    char *bff = tpd_StartingBuffer(self);
    char *nxt = wbs_NextMessageIterator(bff, sz);
    if(!nxt) {
      return response;
    }
    size_t currentSliceSize = (size_t)(nxt - bff);
    char *checkerBuffer = malloc(currentSliceSize);
    memcpy(checkerBuffer, bff, currentSliceSize);
    WebSocketObject obj = (WebSocketObject) {
      .buffer = wbs_ExtractPayload(checkerBuffer),
      .sz = wbs_PayloadSize(checkerBuffer),
      .opcode = wbs_GetCode(checkerBuffer),
      ._fullMessage = checkerBuffer
    };
    arr_Push(response, &obj);
    tpd_Retract(self, currentSliceSize);
    sz = tpd_Size(self);
  }
  return response;
}
void wbs_Public_FreeParseData(Array arr) {
  WebSocketObject *objs = arr->buffer;
  for(size_t i = 0, c = arr->size; i < c; i++) {
    free(objs[i]._fullMessage);
  }
  arr_Delete(arr);
}

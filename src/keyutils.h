#define FFI_SCOPE "keyutils"
#define FFI_LIB "libkeyutils.so.1"

// How to re-generate the definitions below:
// 1. cpp -P /usr/include/keyutils.h
// 2. Manually remove:
//     a) __attribute__ declarations (typedef int register_t ...)
//     b) inline functions (static __inline ...)

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
typedef long unsigned int size_t;
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

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
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
  __extension__ union
  {
    __extension__ unsigned long long int __wseq;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union
  {
    __extension__ unsigned long long int __g1_start;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
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
extern const char keyutils_version_string[];
extern const char keyutils_build_string[];
typedef int32_t key_serial_t;
typedef uint32_t key_perm_t;
struct keyctl_dh_params {
 key_serial_t priv;
 key_serial_t prime;
 key_serial_t base;
};
struct keyctl_kdf_params {
 char *hashname;
 char *otherinfo;
 uint32_t otherinfolen;
 uint32_t __spare[8];
};
struct keyctl_pkey_query {
 unsigned int supported_ops;
 unsigned int key_size;
 unsigned short max_data_size;
 unsigned short max_sig_size;
 unsigned short max_enc_size;
 unsigned short max_dec_size;
 unsigned int __spare[10];
};
struct keyctl_pkey_params {
 key_serial_t key_id;
 unsigned int in_len;
 union {
  unsigned int out_len;
  unsigned int in2_len;
 };
 unsigned int __spare[7];
};
extern key_serial_t add_key(const char *type,
       const char *description,
       const void *payload,
       size_t plen,
       key_serial_t ringid);
extern key_serial_t request_key(const char *type,
    const char *description,
    const char *callout_info,
    key_serial_t destringid);
extern long keyctl(int cmd, ...);
extern key_serial_t keyctl_get_keyring_ID(key_serial_t id, int create);
extern key_serial_t keyctl_join_session_keyring(const char *name);
extern long keyctl_update(key_serial_t id, const void *payload, size_t plen);
extern long keyctl_revoke(key_serial_t id);
extern long keyctl_chown(key_serial_t id, uid_t uid, gid_t gid);
extern long keyctl_setperm(key_serial_t id, key_perm_t perm);
extern long keyctl_describe(key_serial_t id, char *buffer, size_t buflen);
extern long keyctl_clear(key_serial_t ringid);
extern long keyctl_link(key_serial_t id, key_serial_t ringid);
extern long keyctl_unlink(key_serial_t id, key_serial_t ringid);
extern long keyctl_search(key_serial_t ringid,
     const char *type,
     const char *description,
     key_serial_t destringid);
extern long keyctl_read(key_serial_t id, char *buffer, size_t buflen);
extern long keyctl_instantiate(key_serial_t id,
          const void *payload,
          size_t plen,
          key_serial_t ringid);
extern long keyctl_negate(key_serial_t id, unsigned timeout, key_serial_t ringid);
extern long keyctl_set_reqkey_keyring(int reqkey_defl);
extern long keyctl_set_timeout(key_serial_t key, unsigned timeout);
extern long keyctl_assume_authority(key_serial_t key);
extern long keyctl_get_security(key_serial_t key, char *buffer, size_t buflen);
extern long keyctl_session_to_parent(void);
extern long keyctl_reject(key_serial_t id, unsigned timeout, unsigned error,
     key_serial_t ringid);
struct iovec;
extern long keyctl_instantiate_iov(key_serial_t id,
       const struct iovec *payload_iov,
       unsigned ioc,
       key_serial_t ringid);
extern long keyctl_invalidate(key_serial_t id);
extern long keyctl_get_persistent(uid_t uid, key_serial_t id);
extern long keyctl_dh_compute(key_serial_t priv, key_serial_t prime,
         key_serial_t base, char *buffer, size_t buflen);
extern long keyctl_dh_compute_kdf(key_serial_t priv, key_serial_t prime,
      key_serial_t base, char *hashname,
      char *otherinfo, size_t otherinfolen,
      char *buffer, size_t buflen);
extern long keyctl_restrict_keyring(key_serial_t keyring, const char *type,
        const char *restriction);
extern long keyctl_pkey_query(key_serial_t key_id,
         const char *info,
         struct keyctl_pkey_query *result);
extern long keyctl_pkey_encrypt(key_serial_t key_id,
    const char *info,
    const void *data, size_t data_len,
    void *enc, size_t enc_len);
extern long keyctl_pkey_decrypt(key_serial_t key_id,
    const char *info,
    const void *enc, size_t enc_len,
    void *data, size_t data_len);
extern long keyctl_pkey_sign(key_serial_t key_id,
        const char *info,
        const void *data, size_t data_len,
        void *sig, size_t sig_len);
extern long keyctl_pkey_verify(key_serial_t key_id,
          const char *info,
          const void *data, size_t data_len,
          const void *sig, size_t sig_len);
extern long keyctl_move(key_serial_t id,
   key_serial_t from_ringid,
   key_serial_t to_ringid,
   unsigned int flags);
extern long keyctl_capabilities(unsigned char *buffer, size_t buflen);
extern long keyctl_watch_key(key_serial_t id, int watch_queue_fd, int watch_id);
extern int keyctl_describe_alloc(key_serial_t id, char **_buffer);
extern int keyctl_read_alloc(key_serial_t id, void **_buffer);
extern int keyctl_get_security_alloc(key_serial_t id, char **_buffer);
extern int keyctl_dh_compute_alloc(key_serial_t priv, key_serial_t prime,
       key_serial_t base, void **_buffer);
typedef int (*recursive_key_scanner_t)(key_serial_t parent, key_serial_t key,
           char *desc, int desc_len, void *data);
extern int recursive_key_scan(key_serial_t key, recursive_key_scanner_t func, void *data);
extern int recursive_session_key_scan(recursive_key_scanner_t func, void *data);
extern key_serial_t find_key_by_type_and_desc(const char *type, const char *desc,
           key_serial_t destringid);

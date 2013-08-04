#include_next <sys/time.h>

# ifdef __FreeBSD_kernel__
#  include <sys/kern/time.h>
# else
#ifndef _SYS_TIME_H_
#  define _SYS_TIME_H_

/* On FreeBSD, <sys/time.h> is expected to CLOCK_MONOTONIC, etc,
   which on Glibc are defined in <bits/time.h>. Glibc's <sys/time.h>
   doesn't include <bits/time.h> in full mode, but Glibc's <time.h>
   does. */
#  include <time.h>

/* FreeBSD code expects that this file includes... */
#  include <sys/types.h>

#endif /* _SYS_TIME_H_ */

#endif /* __FreeBSD_kernel__ */

@BOTTOM@

#ifdef HAVE_STDLIB_H
#  include <stdlib.h>
#endif

/*
 * If EXIT_FAILURE is not defined (required by POSIX to be in <stdlib.h>)
 * then we define it here.
 */

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif


/* This defines limits for integer data types on POSIX systems. */

#ifdef HAVE_LIMITS_H
#  include <limits.h>
#endif

/*
 * Make sure that we have DBL_MAX and FLT_MAX available even on non-ANSI 
 * systems.  Note that the configure script dies with a fatal error
 * if we don't have at least one of float.h or values.h.
 */

#ifdef HAVE_FLOAT_H
#  include <float.h>
#endif

/* This is set if either <float.h> or <limits.h> is missing 
   and not set otherwise.
*/
#ifdef HAVE_VALUES_H
#  include <values.h>
#  define DBL_MAX MAXDOUBLE
#  define FLT_MAX MAXFLOAT
#endif


/* 
 * If M_PI wasn't defined in <math.h>, define it here (this value comes
 * from <math.h> on IRIX, Linux, SunOS, and Solaris -- somehow, I'm 
 * surprised that they're all the same ... ;-)
 */
#if HAVE_MATH_H
#  include <math.h>
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


/*
 * This macro is needed for direct access to the 3-D voxel array
 * provided by Volume_io.  *This is a rude, nasty kludge!!*  It is
 * only here for historical reasons, and its presence should *not* 
 * be construed as encouragement for future code to meddle in
 * Volume_io's private affairs!
 * 
 * Also, this is different from the GET_VOXEL_PTR macros provided
 * by Volume_io in a couple of ways:
 *  - the Volume_io macros pay attention to whether the volume
 *    is cached or not, and fail appropriately if so;
 *  - for that reason, they may not be used as lvalues, while
 *    VOXEL_DATA may (which is why it's needed)
 *  - most importantly, the GET_VOXEL_PTR macros follow n levels
 *    of indirection (for an n dimensional volume) and return just
 *    the bare voxel data; VOXEL_DATA returns the highest pointer
 *    in the multidimensional array, allowing full array-like 
 *    operations
 */

#ifdef VOLIO_HAVE_VOLUME_ARRAY_DATA
#  define VOXEL_DATA(vol) ((vol)->array.data)
#else
#  ifndef VOLIO_HAVE_VOLUME_DATA
#    error Help!  Can not find raw volume data.
#  endif
#  define VOXEL_DATA(vol) ((vol)->data)
#endif


/* 
 * Version strings 
 */

#define MNI_AUTOREG_VERSION VERSION
#define MNI_AUTOREG_LONG_VERSION \
   "Package MNI AutoReg, version " MNI_AUTOREG_VERSION \
   ", compiled by " MNI_AUTOREG_COMPILE_USER \
   "@" MNI_AUTOREG_COMPILE_HOST \
   " (" MNI_AUTOREG_COMPILE_SYSTEM ")" \
   " on " MNI_AUTOREG_COMPILE_DATE \
   " at " MNI_AUTOREG_COMPILE_TIME


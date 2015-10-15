#ifndef  OS_TYPES_H
#define  OS_TYPES_H

#include <string>

namespace XPLAT
{


typedef unsigned char    BYTE;
typedef unsigned short      WORD16;
typedef signed short        SWORD16;
typedef unsigned int        WORD32;
typedef signed int          SWORD32;
typedef unsigned long long  WORD64;
typedef long long           SWORD64;

#ifndef WIN32
typedef int              INT;
typedef char             CHAR;
typedef unsigned char    BYTE;
typedef signed   char    SBYTE;
typedef unsigned char    BOOLEAN;
typedef unsigned char    T_PAD;
typedef void*            LPVOID;
#endif


#if defined (WIN32)
   typedef unsigned long XPLAT_EXIT_CODE;
#else
   typedef int XPLAT_EXIT_CODE;
#endif /* WIN32 */


#if defined (WIN32)
typedef int XPLAT_PID_T;
#endif /* WIN32 */

# if !defined (XPLAT_INVALID_PID)
# define XPLAT_INVALID_PID ((XPLAT_PID_T) -1)
# endif /* XPLAT_INVALID_PID */


#if defined (UNICODE)
typedef wchar_t XPLAT_TCHAR;
#define XPLAT_TEXT(quote) L##quote
typedef std::wstring  tstring;
#elif
typedef char XPLAT_TCHAR;
#define XPLAT_TEXT(quote) quote
typedef std::string  tstring;
#endif /* UNICODE */


}   /* namespace XPLAT */

#endif  /* OS_TYPES_H */


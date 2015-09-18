

#ifndef  SOCKET_DEFS_H
#define  SOCKET_DEFS_H


#define  XPLAT_SOCKET_SUCCESS    0


#if defined(WIN32)
	#include <winsock2.h>
	
	#define XPLAT_INVALID_SOCKET        INVALID_SOCKET
	#define XPLAT_SOCKET_T              SOCKET
	#define XPLAT_SOCKLEN_T             int
	#define XPLAT_ioctl_request_t       int
	#define XPLAT_CLOSESOCKET(s)        closesocket(s)

	#define XPLAT_ERROR_INTR            WSAEINTR
	#define XPLAT_ERROR_ACCES           WSAEACCES
	#define XPLAT_ERROR_FAULT           WSAEFAULT
	#define XPLAT_ERROR_INVAL           WSAEINVAL
	#define XPLAT_ERROR_MFILE           WSAEMFILE
	#define XPLAT_ERROR_AGAIN           WSAEWOULDBLOCK
	#define XPLAT_ERROR_WOULDBLOCK      WSAEWOULDBLOCK
	#define XPLAT_ERROR_INPROGRESS      WSAEINPROGRESS
	#define XPLAT_ERROR_ALREADY         WSAEALREADY
	#define XPLAT_ERROR_NOTSOCK         WSAENOTSOCK
	#define XPLAT_ERROR_DESTADDRREQ     WSAEDESTADDRREQ
	#define XPLAT_ERROR_MSGSIZE         WSAEMSGSIZE
	#define XPLAT_ERROR_PROTOTYPE       WSAEPROTOTYPE
	#define XPLAT_ERROR_NOPROTOOPT      WSAENOPROTOOPT
	#define XPLAT_ERROR_PROTONOSUPPORT  WSAEPROTONOSUPPORT
	#define XPLAT_ERROR_SOCKTNOSUPPORT  WSAESOCKTNOSUPPORT
	#define XPLAT_ERROR_NOTSUP          WSAEOPNOTSUPP
	#define XPLAT_ERROR_PFNOSUPPORT     WSAEPFNOSUPPORT
	#define XPLAT_ERROR_AFNOSUPPORT     WSAEAFNOSUPPORT
	#define XPLAT_ERROR_ADDRINUSE       WSAEADDRINUSE
	#define XPLAT_ERROR_ADDRNOTAVAIL    WSAEADDRNOTAVAIL
	#define XPLAT_ERROR_NETDOWN         WSAENETDOWN
	#define XPLAT_ERROR_NETUNREACH      WSAENETUNREACH
	#define XPLAT_ERROR_NETRESET        WSAENETRESET
	#define XPLAT_ERROR_CONNABORTED     WSAECONNABORTED
	#define XPLAT_ERROR_CONNRESET       WSAECONNRESET
	#define XPLAT_ERROR_NOBUFS          WSAENOBUFS
	#define XPLAT_ERROR_ISCONN          WSAEISCONN
	#define XPLAT_ERROR_NOTCONN         WSAENOTCONN
	#define XPLAT_ERROR_SHUTDOWN        WSAESHUTDOWN
	#define XPLAT_ERROR_TIMEDOUT        WSAETIMEDOUT
	#define XPLAT_ERROR_CONNREFUSED     WSAECONNREFUSED
	#define XPLAT_ERROR_HOSTDOWN        WSAEHOSTDOWN
	#define XPLAT_ERROR_HOSTUNREACH     WSAEHOSTUNREACH
	#define XPLAT_ERROR_SYSNOTREADY     WSASYSNOTREADY
	#define XPLAT_ERROR_NOTINIT         WSANOTINITIALISED
	#define XPLAT_ERROR_HOST_NOT_FOUND  WSAHOST_NOT_FOUND
	#define XPLAT_ERROR_TRY_AGAIN       WSATRY_AGAIN
	#define XPLAT_ERROR_NO_RECOVERY     WSANO_RECOVERY
	#define XPLAT_ERROR_NO_DATA         WSANO_DATA
#endif



#endif   /* SOCKET_DEFS_H */

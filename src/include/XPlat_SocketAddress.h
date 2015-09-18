#ifndef XPLAT_SOCKET_ADDRESS_H
#define XPLAT_SOCKET_ADDRESS_H


#include <string>


namespace XPLAT
{


class ISocketAddress
{
public:
	static ISocketAddress * Create(const std::string & strIPAddr, unsigned short u16Port);
    
    virtual std::string GetIPAddr() const = 0;
    virtual unsigned short  GetPort() const = 0;

	virtual void SetPortNum(unsigned int u16Port) = 0;

	virtual void Release() = 0;
};


}


#endif /* XPLAT_SOCKET_ADDRESS_H */



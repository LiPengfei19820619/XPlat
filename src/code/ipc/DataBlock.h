#ifndef  XPLAT_DATA_BLOCK_H
#define  XPLAT_DATA_BLOCK_H


#include "os_types.h"


namespace XPLAT
{


class CDataBlock
{
public:
	CDataBlock(void);
	CDataBlock(size_t size);

	virtual ~CDataBlock();

	char * GetData() const;
	void SetData(char * data, size_t size);

	size_t GetSize() const;
	void SetSize(size_t size);

	size_t GetCapacity(void) const;

private:
	char    * m_pchData;
	size_t    m_uiCurSize;
	size_t    m_uiMaxSize;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_DATA_BLOCK_H */



#include "DataBlock.h"


using namespace XPLAT;


CDataBlock::CDataBlock()
	: m_pchData(NULL),
	  m_uiCurSize(0),
	  m_uiMaxSize(0)
{
}


CDataBlock::CDataBlock(size_t size)
	: m_pchData(NULL),
	  m_uiCurSize(0),
	  m_uiMaxSize(0)
{
	m_pchData = (char *)malloc(size);
	if(m_pchData != NULL)
	{
		m_uiCurSize = size;
		m_uiMaxSize = size;
	}
}


CDataBlock::~CDataBlock()
{
	if(m_pchData != NULL)
	{
		free(m_pchData);
		m_uiCurSize = 0;
		m_uiMaxSize = 0;
	}
}


char * CDataBlock::GetData() const
{
	return m_pchData;
}


bool CDataBlock::SetData(const char * data, size_t size)
{
	if(data == NULL || size == 0)
	{
		return false;
	}

	m_pchData = (char *)malloc(size);
	if(m_pchData == NULL)
	{
		return false;
	}

	memcpy(m_pchData, data, size);
	m_uiCurSize = size;
	m_uiMaxSize = size;

	return true;
}


size_t CDataBlock::GetSize() const
{
	return m_uiCurSize;
}


void CDataBlock::SetSize(size_t size)
{
}


size_t CDataBlock::GetCapacity(void) const
{
	return m_uiMaxSize;
}


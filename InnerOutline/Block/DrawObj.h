#pragma once
#include "BlockTest.h"
THDRAW_INNEROUTLINE_BEGIN
class TestDrawObj : public CBWDrawObjBase
{
public:
	TestDrawObj() :m_pBlock(NULL){}
	explicit TestDrawObj(const TestBlockGJ* m_pBlk);
	virtual ~TestDrawObj(){}
public:
	virtual void Draw(CBWDrawGroup* pGroup)const;
protected:
	const TestBlockGJ* m_pBlock;
};
THDRAW_INNEROUTLINE_END

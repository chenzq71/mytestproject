#ifndef _MACRO_TEST_GOUZAO
#define _MACRO_TEST_GOUZAO
THDRAW_INNEROUTLINE_BEGIN
class CComponentGJP0;
class CGouZao
{
public:
	CGouZao();
	virtual ~CGouZao();
public:
	void SetComponentP0(const CComponentGJP0* gjp0);
	const CComponentGJP0* GetCompGJP0();
private:
	const CComponentGJP0* CompGJP0;//¹¹ÔìËã·¨Æ÷
public:
	void CreateTestBlock(CBWRefLineMan* pRefLineMan);
};
THDRAW_INNEROUTLINE_END
#endif
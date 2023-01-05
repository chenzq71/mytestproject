#pragma once
#include "Data.h"
THDRAW_INNEROUTLINE_BEGIN
//所有的线
class INNEROUTLINE_API CLines{
public:
	CTHAnyLine topline;
	CTHAnyLine leftline;
	CTHAnyLine rightline;
	CTHAnyLine leftsideline;
	CTHAnyLine rightsideline;
	CTHAnyLine leftjoinline;
	CTHAnyLine rightjoinline;
	CTHAnyLine botline;
};
class INNEROUTLINE_API CStructAlogorithm
{
public:
	CStructAlogorithm();
	virtual ~CStructAlogorithm();
private:
	CData GZData;//数据
	CLines GZLines;//构造线
public:
	void SetData(const CData& outgzdata);
	void GetData(CData& copyone)const;
	void GetLines(CLines& copyone)const;
	
	void Design();
	void DesignLines();
};
THDRAW_INNEROUTLINE_END

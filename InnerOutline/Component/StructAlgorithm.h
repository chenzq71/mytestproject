#pragma once
#include "Data.h"
THDRAW_INNEROUTLINE_BEGIN
//���е���
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
	CData GZData;//����
	CLines GZLines;//������
public:
	void SetData(const CData& outgzdata);
	void GetData(CData& copyone)const;
	void GetLines(CLines& copyone)const;
	
	void Design();
	void DesignLines();
};
THDRAW_INNEROUTLINE_END

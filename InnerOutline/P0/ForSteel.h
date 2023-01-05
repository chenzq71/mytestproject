#pragma once
#include "GouZao.h"
THDRAW_INNEROUTLINE_BEGIN
class CComponentGJ;
class CP0ForSteel
{
public:
	CP0ForSteel(CString str,CComponentGJ* comp);
	virtual ~CP0ForSteel();
public:
	CGouZao m_GZ;
	CComponentGJ* m_CompGJ;
	CString TypeName;
public:
	void GetSteelP0FromUI()const;//
	void CreateBlock(CBWRefLineMan* pRefLineMan, const CString& BlockName);//
public:
	CBWComponentSteelP0* GetBWComponentSteelP0()const;
};
THDRAW_INNEROUTLINE_END

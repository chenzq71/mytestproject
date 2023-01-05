#pragma once
#include "stdafx.h"
#include "GouZao.h"
#include "..\Component\ComponentP0.h"
THDRAW_INNEROUTLINE_BEGIN
void AddReflineWithCheck(CBWRefLineMan* pRefLineMan, const CString& Name, const CBWRefLine& RefLine, BOOL bReverse = FALSE)
{
	if (bReverse)
	{
		CTHAnyLine anyLine(RefLine.GetCurve());
		anyLine.SelfReverse();
		pRefLineMan->AddRefline(Name, CBWRefLine(anyLine));
	}
	else
	{
		pRefLineMan->AddRefline(Name, RefLine);
	}
}
CGouZao::CGouZao() :CompGJP0(NULL)
{

}
CGouZao::~CGouZao()
{

}
void CGouZao::SetComponentP0(const CComponentGJP0* gjp0)
{
	CompGJP0 = gjp0;
}
const CComponentGJP0* CGouZao::GetCompGJP0()
{
	return CompGJP0;
}
void CGouZao::CreateTestBlock(CBWRefLineMan* pRefLineMan)
{
	if (CompGJP0)
	{
		CLines gjlines;
		CompGJP0->m_StructAlogorithm.GetLines(gjlines);
		AddReflineWithCheck(pRefLineMan, gjlines.topline.GetLineName(), CBWRefLine(gjlines.topline));
		AddReflineWithCheck(pRefLineMan, gjlines.leftsideline.GetLineName(), CBWRefLine(gjlines.leftsideline));
		AddReflineWithCheck(pRefLineMan, gjlines.leftjoinline.GetLineName(), CBWRefLine(gjlines.leftjoinline));
		AddReflineWithCheck(pRefLineMan, gjlines.botline.GetLineName(), CBWRefLine(gjlines.botline));
		AddReflineWithCheck(pRefLineMan, gjlines.rightjoinline.GetLineName(), CBWRefLine(gjlines.rightjoinline));
		AddReflineWithCheck(pRefLineMan, gjlines.rightsideline.GetLineName(), CBWRefLine(gjlines.rightsideline));
	}
}
THDRAW_INNEROUTLINE_END

#pragma once
#include "stdafx.h"
#include "..\Component\Component.h"
#include "BlockAndGJ.h"
#include "ForSteel.h"
THDRAW_INNEROUTLINE_BEGIN
CP0ForSteel::CP0ForSteel(CString str, CComponentGJ* comp) :TypeName(str),m_CompGJ(comp)
{

}
CP0ForSteel::~CP0ForSteel()
{

}
void CP0ForSteel::GetSteelP0FromUI()const
{
	CBWComponentSteelP0* SteelP0 = GetBWComponentSteelP0();
	if (!SteelP0)
	{
		return;
	}
	//给钢筋界面赋值
}
CBWComponentSteelP0* CP0ForSteel::GetBWComponentSteelP0()const
{
	CBWComponentSteelP0* steelp0 = NULL;
	if (m_CompGJ)
	{
		steelp0 = m_CompGJ->GetSteelP0(TypeName);
	}
	return steelp0;
}
void CP0ForSteel::CreateBlock(CBWRefLineMan* pRefLineMan, const CString& BlockName)
{
	if (BlockName == BlockGJTest() || BlockName.IsEmpty())
	{
		m_GZ.CreateTestBlock(pRefLineMan);
	}
}
THDRAW_INNEROUTLINE_END

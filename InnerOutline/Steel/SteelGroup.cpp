#pragma once
#include "stdafx.h"
#include "SteelGroup.h"
#include "..\P0\BlockAndGJ.h"
#include "..\P0\ForSteel.h"
THDRAW_INNEROUTLINE_BEGIN
CSteelGroup::CSteelGroup()
{

}
CSteelGroup::~CSteelGroup()
{

}
void CSteelGroup::SetP0(CP0ForSteel* p0)
{
	gzP0 = p0;
}
CString CSteelGroup::BlockSteelSign(const CString& BlockName, const CString& SteelName)
{
	return "";
}
void CSteelGroup::DesignSteel()
{
	SetSteelEdge();
	DesignSteel_test();
}
void CSteelGroup::DesignBlock()
{
	DesignBlock_test();
}
void CSteelGroup::DesignSteel_test()
{
	//已经在设置钢筋边距处从界面取得了钢筋信息，故此处直接GET概念筋即可
}
void CSteelGroup::DesignBlock_test()
{

}
CBWSteel& CSteelGroup::SetSteelByGNJ(const CString& GaiNianJin, int index, bool bSetUIProp)
{
	CBWSteel& Steel = GetSteel(GaiNianJin);
	if (bSetUIProp)
	{
		CBWComponentSteelP0* UIP0 = gzP0->GetBWComponentSteelP0();
		CBWP0_SteelBase* pP0_SteelBase = NULL;
		if (UIP0)
		{
			CString indexstr = GetUISteelIndexStr(GaiNianJin,index);
			pP0_SteelBase = UIP0->GetSteelBase(indexstr);
		}
		if (pP0_SteelBase)
		{
			Steel.SetBaseInfo(*pP0_SteelBase);
		}
		else
		{
			//没有从界面取得钢筋信息
		}
	}
	return Steel;
}
CBWSteel& CSteelGroup::GetSteelByGNJ(const CString& GaiNianJin, int index)
{
	return SetSteelByGNJ(GaiNianJin, index, false);
}
void CSteelGroup::SetSteelEdge()
{
	SetSteelDYProp();
	//
}
void CSteelGroup::SetSteelDYProp()
{
	//设置大样属性不需要界面信息，故使用GetSteelByGNJ（）
}
THDRAW_INNEROUTLINE_END

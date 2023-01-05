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
	//�Ѿ������øֽ�߾ദ�ӽ���ȡ���˸ֽ���Ϣ���ʴ˴�ֱ��GET������
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
			//û�дӽ���ȡ�øֽ���Ϣ
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
	//���ô������Բ���Ҫ������Ϣ����ʹ��GetSteelByGNJ����
}
THDRAW_INNEROUTLINE_END

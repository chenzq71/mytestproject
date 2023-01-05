#pragma once
#include "stdafx.h"
#include "SteelQun.h"
#include "..\P0\ForSteel.h"
#include "SteelGroup.h"
#include "..\P0\BlockAndGJ.h"
THDRAW_INNEROUTLINE_BEGIN
CSteelQun :: CSteelQun() : m_pP0(NULL)
{

}
CSteelQun::~CSteelQun()
{

}
void CSteelQun::SetP0(CP0ForSteel* pP0)
{
	m_pP0 = pP0;
}
void CSteelQun::BlockSteelProp()
{

}
void CSteelQun::DesignSteelGroup()
{
	if (m_pP0)
	{
		CSteelGroup* pSteelGroup = new CSteelGroup();
		pSteelGroup->SetP0(m_pP0);
		CString GroupName = "TestGroup";
		Add(GroupName,pSteelGroup);
	}
}
vector<CString> CSteelQun::GetSteelName(const CString& GaiNianJin)
{
	return GetSteelVec(GaiNianJin,"");
}
void CSteelQun::GouZaoRefLine(CBWRefLineMan* pRefLineMan, const CString& BlockName)
{
	m_pP0->CreateBlock(pRefLineMan, BlockName);
}
void CSteelQun::GetNumOrderData(CSteelDataForNumOrder& NumOrderData)
{
	//TODO:¸Ö½î±àºÅ
	CSteelDataForNumOrderi NumOrderGJ;
	NumOrderGJ.m_bFirstA = FALSE;
	NumOrderGJ.m_StartNum = 1;//ÆðÊ¼±àºÅ 	
	vector<CString> GaiNianJinVec;
	GaiNianJinVec = GetGJOrder();
	for (size_t i = 0; i<GaiNianJinVec.size(); i++)//°´Ðò±àºÅµÄ¸ÅÄî½îÃû³Æ	
	{
		NumOrderGJ.m_OrderSteelVec.push_back(GaiNianJinVec[i]);
	}
	NumOrderData.AddNumOrder(NumOrderGJ);
}
THDRAW_INNEROUTLINE_END

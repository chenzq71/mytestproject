#pragma once
#include "stdafx.h"
#include "DrawObj.h"
THDRAW_INNEROUTLINE_BEGIN

TestDrawObj::TestDrawObj(const TestBlockGJ* m_pBlk) :m_pBlock(m_pBlk)
{

}
void TestDrawObj::Draw(CBWDrawGroup* pGroup)const
{
	CBWLineGroup gzGroup;
	std::vector<CTHAnyLine> lines;
	std::vector<CString> specs;
	//specs.push_back("");
	if (m_pBlock&&m_pBlock->GetGZ())
	{
		m_pBlock->GetGZ()->GetData().GetAllLinesExceptSpecial(lines, specs);
	}
	for (size_t i = 0; i<lines.size(); ++i)
	{
		gzGroup.AddTHAnyLine(lines[i], GetRuleLineObjName().m_GZ_ConLine);
	}
	pGroup->AddElement(&gzGroup);
}
THDRAW_INNEROUTLINE_END

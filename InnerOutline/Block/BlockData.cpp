#pragma once 
#include "stdafx.h"
#include "BlockData.h"
#include "THGridControl\THGridControlMac.h"
#include "THGridControl\StringParserTools.h"
//using namespace ZYH_GRID;
THDRAW_INNEROUTLINE_BEGIN
void ConvertRefLineToTHAnyLine(const CBWRefLine& refLine, CTHAnyLine& anyLine)
{
	CTHAnyLine shapeLine(refLine.GetCurve());
	anyLine = shapeLine;
	anyLine.SetLineName(refLine.GetName());
}
TestBlockData::TestBlockData()
{

}
TestBlockData::~TestBlockData()
{

}
void TestBlockData::FindRefLines(const CBWRefLineMan* refLineMan, std::vector<CTHAnyLine>& lineVec, CString preStr)
{
	lineVec.clear();
	if (refLineMan == NULL)
	{
		return;
	}
	std::vector<CString> allName = refLineMan->GetReflineName();
	if (!preStr.IsEmpty())
	{
		for (size_t i = 0; i<allName.size(); ++i)
		{
			int index = allName[i].Find(preStr);

			if (index == 0)
			{
				const CBWRefLine*pRefLine = refLineMan->GetRefLine(allName[i]);
				if (pRefLine)
				{
					CTHAnyLine resLine;
					ConvertRefLineToTHAnyLine(*pRefLine, resLine);

					lineVec.push_back(resLine);
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i<allName.size(); ++i)
		{
			const CBWRefLine*pRefLine = refLineMan->GetRefLine(allName[i]);
			if (pRefLine)
			{
				CTHAnyLine resLine;
				ConvertRefLineToTHAnyLine(*pRefLine, resLine);

				lineVec.push_back(resLine);
			}
		}
	}
}
void TestBlockData::FindRefLinesExceptSpecial(const CBWRefLineMan* refLineMan,
	std::vector<CTHAnyLine>& lineVec,
	CString preStr,
	const std::vector<CString>& special_prestr_vec /* = std::vector<CString> */
	)
{
	lineVec.clear();
	if (refLineMan == NULL)
	{
		return;
	}
	std::vector<CString> allName = refLineMan->GetReflineName();
	if (!preStr.IsEmpty())
	{
		for (size_t i = 0; i<allName.size(); ++i)
		{
			int index = allName[i].Find(preStr);
			//
			bool bspecial = false;
			for (size_t k = 0; k<special_prestr_vec.size(); k++)
			{
				CString tempstr = special_prestr_vec[k];
				if (allName[i].Find(tempstr) >= 0)//找到了,不再判断。
				{
					bspecial = true;
					break;
				}
			}
			//
			if (index == 0 && bspecial == false)//找到了，但不过滤
			{
				const CBWRefLine*pRefLine = refLineMan->GetRefLine(allName[i]);
				if (pRefLine)
				{
					CTHAnyLine resLine;
					ConvertRefLineToTHAnyLine(*pRefLine, resLine);
					lineVec.push_back(resLine);
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i<allName.size(); ++i)
		{
			bool bspecial = false;
			for (size_t k = 0; k<special_prestr_vec.size(); k++)
			{
				CString tempstr = special_prestr_vec[k];
				if (allName[i].Find(tempstr) >= 0)//找到了,不再判断。
				{
					bspecial = true;
					break;
				}
			}
			//
			if (bspecial == false)
			{
				const CBWRefLine*pRefLine = refLineMan->GetRefLine(allName[i]);
				if (pRefLine)
				{
					CTHAnyLine resLine;
					ConvertRefLineToTHAnyLine(*pRefLine, resLine);
					lineVec.push_back(resLine);
				}
			}
		}
	}
}
void TestBlockData::AddRefLines(std::vector<CTHAnyLine>& lineVec)
{
	for (size_t i = 0; i<lineVec.size(); ++i)
	{
		const CTHAnyLine& line = lineVec[i];
		CString name = line.GetLineName();
		m_refLineMap.insert(make_pair(name, line));
	}
}
void TestBlockData::GetAllLinesExceptSpecial(std::vector<CTHAnyLine>& lineVec, const std::vector<CString>& special_prestr_vec)const
{
	lineVec.clear();
	for (std::map<CString, CTHAnyLine>::const_iterator iter = m_refLineMap.begin(); iter != m_refLineMap.end(); ++iter)
	{
		CString refLineName = iter->first;
		CTHAnyLine refLine = iter->second;
		bool bspecial = false;
		for (size_t k = 0; k<special_prestr_vec.size(); k++)
		{
			CString tempstr = special_prestr_vec[k];
			if (refLineName.Find(tempstr) >= 0)//找到了,不再判断。
			{
				bspecial = true;
				break;
			}
		}
		if (bspecial == false)
		{
			lineVec.push_back(refLine);
		}
	}
}
CTHAnyLine TestBlockData::GetLine(const CString& lineName)const
{
	CTHAnyLine resLine;
	if (!lineName.IsEmpty())
	{
		std::map<CString, CTHAnyLine>::const_iterator iter = m_refLineMap.find(lineName);
		if (iter != m_refLineMap.end())
		{
			resLine = iter->second;
		}
	}
	return resLine;
}
void TestBlockData::GetLines(std::vector<CTHAnyLine>& lineVec, const CString& keystr)
{
	lineVec.clear();
	if (!keystr.IsEmpty())
	{
		std::vector<CString> vect_key;
		CString source = keystr;
		CString splits = "||";
		SplitString(source, splits, vect_key);
		std::map<CString, CTHAnyLine>::const_iterator it = m_refLineMap.begin();
		for (; it != m_refLineMap.end(); ++it)
		{
			for (size_t k = 0; k<vect_key.size(); ++k)
			{
				if (it->first.Find(vect_key[k]) >= 0)
				{
					lineVec.push_back(it->second); break;
				}
			}
		}
	}
}
THDRAW_INNEROUTLINE_END

#pragma once
#include "stdafx.h"
#include "BlockAndGJ.h"
THDRAW_INNEROUTLINE_BEGIN
CString Steel_Test()
{
	return "Steel_Test";
}
vector<CString> GetGJOrder()
{
	vector<CString> gjvec;
	gjvec.push_back(Steel_Test());
	return gjvec;
}
vector<CString> GetSteelVec(const CString& GJName, const CString& PreName, int index)
{
	vector<CString> onetypegj;
	if (GJName == Steel_Test())
	{
		CString indexstr;
		indexstr.Format("#%d",index);
		CString steelname = PreName + GJName + indexstr;
		onetypegj.push_back(steelname);
	}
	return onetypegj;
}
CString GetUISteelIndexStr(const CString& GJName, int index)
{
	CString UIindexname;
	if (GJName == Steel_Test())
	{
		UIindexname = "Steel_Test" + IntToStr(index);
	}
	return UIindexname;
}
CString BlockGJTest()
{
	return "BlockTest";
}
CString Blocktable()
{
	return "TestTable";
}
void GetBlockProp(vector<int>& blocktypevec, vector<CString>& blocknamevec, int index)
{
	blocktypevec.clear();
	blocknamevec.clear();
	blocknamevec.push_back(BlockGJTest());
	blocknamevec.push_back(Blocktable());
	for (size_t i = 0; i < blocknamevec.size();++i)
	{
		////ͼ�����ͣ�0��ʾ��ͨ��1��ʾ�Զ��γɵı����ϸ����2��ʾ�ֽ����,-1��ʾ�Զ���ı��
		int type = 0;
		if (blocknamevec[i] == Blocktable())
		{
			type = 1;
		}
		blocktypevec.push_back(type);
	}
}
THDRAW_INNEROUTLINE_END

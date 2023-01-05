#pragma once
#include "stdafx.h"
#include "Component.h"
#include "..\P0\ForSteel.h"
#include "..\P0\BlockAndGJ.h"
#include "..\Steel\SteelQun.h"
#include "..\Block\BlockTest.h"
#include "..\Block\BlockData.h"
THDRAW_INNEROUTLINE_BEGIN
CComponentGJ::CComponentGJ()
{

}
CComponentGJ::~CComponentGJ()
{

}
CComponentGJ::CComponentGJ(CComponentGJP0* P0) :CBWComponentGJ(P0)
{

}
CComponentGJ::CComponentGJ(std::shared_ptr<CComponentGJP0> P0) : CBWComponentGJ(P0)
{

}
const CComponentGJP0* CComponentGJ::GetP0()const
{
	return dynamic_cast<const CComponentGJP0*>(m_DrawP0.get());
}
void CComponentGJ::Design()
{
	CBWComponentGJ::Design();//重写Design()需要先调用纯虚基类的Design()
	if (m_pP0ForSteel==NULL)
	{
		m_pP0ForSteel.reset(new CP0ForSteel("Test",this));
	}
	m_pP0ForSteel->m_GZ.SetComponentP0(GetP0());
	{
		CSteelQun* pSteelQun = new CSteelQun();
		pSteelQun->SetP0(m_pP0ForSteel.get());
		GetSteelMan().Add("TestQun", pSteelQun);
	}
}
void CComponentGJ::DesignPost()
{
	vector<int> BlockTypeVec;
	vector<CString> BlockNameVec;
	GetBlockProp(BlockTypeVec, BlockNameVec,0);
	vector<std::shared_ptr<CBWDWGJBlock>> QXDGJBlockVec;
	for (int i = 0; i != BlockNameVec.size();++i)
	{
		std::shared_ptr<CBWDWGJBlock> Blocki(new CBWDWGJBlock);
		Blocki->SetName(BlockNameVec[i]);
		QXDGJBlockVec.push_back(Blocki);
	}
	GetSteelMan().SetGJBlcok("TestQun", QXDGJBlockVec, BlockTypeVec);
	GetBlockP0(m_blkAll);//从钢群获得所有的gjblock
}
void CComponentGJ::Draw(const CString& blockname)
{
	CBWSteelQun* pSteelQun = dynamic_cast<CBWSteelQun*>(GetSteelMan().GetQun("TestQun"));
	if (pSteelQun)
	{
		CBWRefLineMan* pRefMan = pSteelQun->GetRefLineMan();
		if (pRefMan)
		{
			if (blockname.IsEmpty() || blockname == BlockGJTest())
			{
				TestBlockData blkdata;
				vector<CTHAnyLine> linevec;
				TestBlockData::FindRefLines(pRefMan,linevec,"INNER");
				blkdata.AddRefLines(linevec);
				TestBlockGJ* pBlk = new TestBlockGJ(BlockGJTest());
				////////////////////////
				Test_GGBlock* pgg = new Test_GGBlock();
				Test_GZBlock* pgz = new Test_GZBlock();
				pgz->SetData(blkdata);
				Test_GJBlock* pgj = new Test_GJBlock();
				pgj->Set(FindBlockP0(BlockGJTest()));
				Test_GRBlock* pgr = new Test_GRBlock();
				//////////////////////////
				pBlk->Set(pgg,pgz,pgj,pgr);
				pBlk->SetScale(50);
				Add(pBlk);
			}
		}
	}
}
void CComponentGJ::CreatPaper(OUT vector<CBWPaper*>& papervec)
{
	//
	//system("md D:\\TESTPAPER\\");
	//ExportDesignDxf("D:\\TESTPAPER\\");
	papervec.clear();
	CBWPaper* paper = new CBWPaper();
	paper->SetPaperName("测试图纸");
	papervec.push_back(paper);

	//排图	   
	CBWLayerOutInfo LayoutInfo;
	LayoutInfo.ReArrange(GetCompDrawSet());
	LayoutInfo.SetName("测试图纸", "钢筋", 0);

	CString expr = "(" + BlockGJTest() + ")";
	CBWLayOut* layout = new CBWLayOut();
	CString strIndex; strIndex.Format("%s%s%s", "(", IntToStr(++LayoutInfo.m_mainNameIndex, 3), ")");
	layout->SetProp(*(LayoutInfo.toTKPorp()), LayoutInfo.m_mainNamePre + strIndex);
	layout->SetExpression(expr, FALSE);
	paper->AddLayout(layout);
}
THDRAW_INNEROUTLINE_END

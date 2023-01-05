#pragma once
#include "stdafx.h"
#include "StructAlgorithm.h"
#include "..\P0\RefLineName.h"
#include "TunnelData\Section\ArcWallSectionLines.h"
THDRAW_INNEROUTLINE_BEGIN
CStructAlogorithm::CStructAlogorithm()
{

}
CStructAlogorithm::~CStructAlogorithm()
{

}
void CStructAlogorithm::SetData(const CData& outgzdata)
{
	GZData = outgzdata;
}
void CStructAlogorithm::GetData(CData& copyone)const
{
	copyone = GZData;
}
void CStructAlogorithm::GetLines(CLines& copyone)const
{
	copyone = GZLines;
}
void CStructAlogorithm::DesignLines()
{
	CSectionData sectiondata;
	if (GZData.TunnelData->m_TunnelBodyData.size() == 0)return;
	sectiondata = GZData.TunnelData->m_TunnelBodyData[0].m_SectionData;
	CArcWallSectionLines sectionlines;
	sectionlines.Draw(sectiondata);
	GZLines.topline.AddTHArc(sectionlines.toparc);
	GZLines.topline.SetLineName(INNER_TOPLINE());
	GZLines.leftsideline.AddTHArc(sectionlines.leftarc);
	GZLines.leftsideline.SetLineName(INNER_LEFTSIDELINE());
	GZLines.leftjoinline.AddTHArc(sectionlines.leftjoinarc);
	GZLines.leftjoinline.SetLineName(INNER_LEFTJOINLINE());
	GZLines.botline.AddTHAnyLine(sectionlines.botline);
	GZLines.botline.SetLineName(INNER_BOTLINE());
	GZLines.rightjoinline.AddTHArc(sectionlines.rightjoinarc);
	GZLines.rightjoinline.SetLineName(INNER_RIGHTJOINLINE());
	GZLines.rightsideline.AddTHArc(sectionlines.rightarc);
	GZLines.rightsideline.SetLineName(INNER_RIGHTSIDELINE());

	//GZLines.botline = CTHAnyLine(CDblPoint(0, 0), CDblPoint(GZData.x,0));
	//GZLines.botline.SetLineName(BOTLINE());
	//GZLines.rightline = CTHAnyLine(CDblPoint(GZData.x, 0),CDblPoint(GZData.x,GZData.y));
	//GZLines.rightline.SetLineName(RIGHTLINE());
	//GZLines.topline = CTHAnyLine(CDblPoint(GZData.x,GZData.y),CDblPoint(0,GZData.y));
	//GZLines.topline.SetLineName(TOPLINE());
	//GZLines.leftline = CTHAnyLine(CDblPoint(0,GZData.y),CDblPoint(0,0));
	//GZLines.leftline.SetLineName(LEFTLINE());
}
void CStructAlogorithm::Design()
{
	DesignLines();
}
THDRAW_INNEROUTLINE_END

#pragma once
#include "TunnelData\outputInc.h"
using namespace TUNNELDATA;
THDRAW_INNEROUTLINE_BEGIN
class INNEROUTLINE_API CData
{
public:
	CData();
	virtual ~CData(){};//基类，实现多态时，需要逐层析构
public:
	void SetData(const shared_ptr<CTunnelDesignData>& outtunneldata);
	void GetData(CData &copydata);
	const CData& GetData()const;
public:
	shared_ptr<CTunnelDesignData> TunnelData;
};

THDRAW_INNEROUTLINE_END
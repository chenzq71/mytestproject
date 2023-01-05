#include "stdafx.h"
#include "Data.h"
THDRAW_INNEROUTLINE_BEGIN
CData::CData()
{
    
}
void CData::SetData(const shared_ptr<CTunnelDesignData>& outTunneldata)
{
	TunnelData = outTunneldata;
}
void CData::GetData(CData& copydata)
{
	copydata = *this;
}
const CData& CData::GetData()const
{
	return *this;
}

THDRAW_INNEROUTLINE_END

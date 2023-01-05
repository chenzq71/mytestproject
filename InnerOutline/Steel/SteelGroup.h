#pragma once
THDRAW_INNEROUTLINE_BEGIN
class CP0ForSteel;
class CSteelGroup : public CBWSteelGroup
{
public:
	CSteelGroup();
	virtual ~CSteelGroup();
public:
	void SetP0(CP0ForSteel* p0);
	virtual CString BlockSteelSign(const CString& BlockName, const CString& SteelName);//不同钢筋block上，钢筋的标示
	virtual void DesignSteel();
	virtual void DesignBlock();
	void DesignSteel_test();
	void DesignBlock_test();
private:
	CBWSteel& SetSteelByGNJ(const CString& GaiNianJin, int index = 0, bool bSetUIProp = true);
	CBWSteel& GetSteelByGNJ(const CString& GaiNianJin, int index = 0);
	void SetSteelEdge();
	void SetSteelDYProp();
private:
	CP0ForSteel* gzP0;
};
THDRAW_INNEROUTLINE_END

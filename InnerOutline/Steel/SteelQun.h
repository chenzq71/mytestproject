#pragma once
THDRAW_INNEROUTLINE_BEGIN
class CP0ForSteel;
class CSteelQun : public CBWSteelQun
{
public:
	CSteelQun();
	virtual ~CSteelQun();
	void SetP0(CP0ForSteel* pP0);
public:
	virtual void DesignSteelGroup();//向钢群中添加钢组
	virtual void GouZaoRefLine(CBWRefLineMan* pRefLineMan, const CString& BlockName);//添加参考线到参考线管理器
	virtual vector<CString> GetSteelName(const CString& GaiNianJin);//根据概念筋名称取得与之相关的所有钢筋名字
	virtual void GetNumOrderData(CSteelDataForNumOrder& NumOrderData);//给钢筋编号
	virtual void BlockSteelProp();
private:
	CP0ForSteel* m_pP0;
};
THDRAW_INNEROUTLINE_END

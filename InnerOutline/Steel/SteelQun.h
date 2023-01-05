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
	virtual void DesignSteelGroup();//���Ⱥ����Ӹ���
	virtual void GouZaoRefLine(CBWRefLineMan* pRefLineMan, const CString& BlockName);//��Ӳο��ߵ��ο��߹�����
	virtual vector<CString> GetSteelName(const CString& GaiNianJin);//���ݸ��������ȡ����֮��ص����иֽ�����
	virtual void GetNumOrderData(CSteelDataForNumOrder& NumOrderData);//���ֽ���
	virtual void BlockSteelProp();
private:
	CP0ForSteel* m_pP0;
};
THDRAW_INNEROUTLINE_END

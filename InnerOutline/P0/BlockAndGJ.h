#pragma once
THDRAW_INNEROUTLINE_BEGIN
//�ֽ�
CString Steel_Test();
vector<CString> GetGJOrder();//��˳���øֽ������
vector<CString> GetSteelVec(const CString& GJName,const CString& PreName,int index=0);//���иֽ�������������
CString GetUISteelIndexStr(const CString& GJName,int index=0);//��ý���ֽ���Ϣ�����ַ���

//ͼ��
CString BlockGJTest();
CString Blocktable();
void GetBlockProp(vector<int>& blocktypevec,vector<CString>& blocknamevec,int index);

THDRAW_INNEROUTLINE_END

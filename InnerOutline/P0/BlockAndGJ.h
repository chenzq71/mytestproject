#pragma once
THDRAW_INNEROUTLINE_BEGIN
//钢筋
CString Steel_Test();
vector<CString> GetGJOrder();//按顺序获得钢筋的名字
vector<CString> GetSteelVec(const CString& GJName,const CString& PreName,int index=0);//所有钢筋具体的类型名字
CString GetUISteelIndexStr(const CString& GJName,int index=0);//获得界面钢筋信息索引字符串

//图块
CString BlockGJTest();
CString Blocktable();
void GetBlockProp(vector<int>& blocktypevec,vector<CString>& blocknamevec,int index);

THDRAW_INNEROUTLINE_END

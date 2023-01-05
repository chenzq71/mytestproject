#pragma once 
THDRAW_INNEROUTLINE_BEGIN
class TestBlockData
{
public:
	TestBlockData();
	~TestBlockData();
public:
	static void FindRefLines(const CBWRefLineMan* refLineMan,std::vector<CTHAnyLine>& lineVec,CString preStr);
	static void FindRefLinesExceptSpecial(const CBWRefLineMan* refLineMan,std::vector<CTHAnyLine>& lineVec,CString preStr,const std::vector<CString>& special_prestr_vec = std::vector<CString>());
public:
	void AddRefLines(std::vector<CTHAnyLine>& lineVec);//Ìí¼Ó²Î¿¼Ïß
	void GetAllLinesExceptSpecial(std::vector<CTHAnyLine>& lineVec, const std::vector<CString>& special_prestr_vec = std::vector<CString>())const;
	CTHAnyLine GetLine(const CString& lineName)const;
	void GetLines(std::vector<CTHAnyLine>& lineVec, const CString& keystr = "");
private:
	std::map<CString, CTHAnyLine> m_refLineMap;
};
THDRAW_INNEROUTLINE_END

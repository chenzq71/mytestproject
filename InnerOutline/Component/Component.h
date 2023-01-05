#pragma once
#include "ComponentP0.h"
THDRAW_INNEROUTLINE_BEGIN
class CP0ForSteel;
class INNEROUTLINE_API CComponentGJ : public CBWComponentGJ
{
public:
	CComponentGJ();
	virtual ~CComponentGJ();
	explicit CComponentGJ(CComponentGJP0 *P0);
	explicit CComponentGJ(std::shared_ptr<CComponentGJP0> P0);

public:
	virtual const CComponentGJP0* GetP0()const;
private:
	shared_ptr<CP0ForSteel> m_pP0ForSteel;

protected:
	virtual void Design();
	virtual void DesignPost();
	virtual void Draw(const CString& BlockName="");
	virtual void CreatPaper(OUT vector<CBWPaper*>& papervec);
	virtual void Design2Draw(){}
	virtual void CreateConceptBlock(const CTHObjProp &prop){}
	virtual void BlockDesign(CTHObjProp &prop)const{}
};
THDRAW_INNEROUTLINE_END
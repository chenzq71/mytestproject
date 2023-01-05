#pragma once 
#include "BlockData.h"
THDRAW_INNEROUTLINE_BEGIN
////��ͼ���û���
class Test_GGBlock :public CBWGGBlockBase
{
	friend class boost::serialization::access;
public:
	Test_GGBlock(){}
	virtual ~Test_GGBlock(){}
	virtual Test_GGBlock* clone()const;
protected:
	template<class Archive> void serialize(Archive &ar, const unsigned int)
	{
		BSTSERILIZEBASE(CHPD_GGBlockBase);
	}
};
//����
class Test_GZBlock :public CBWGZBlockBase
{
	friend class boost::serialization::access;
public:
	Test_GZBlock(){}
	explicit Test_GZBlock(const TestBlockData& data):m_Data(data){}
	virtual ~Test_GZBlock(){}
	virtual Test_GZBlock* clone()const;
	virtual void CalculateDrawObjGZ();
	virtual void CalculateGeneratrix();
	void SetData(const TestBlockData& data){ m_Data = data; }
	const TestBlockData& GetData()const{ return m_Data; }

protected:
	template<class Archive>	void serialize(Archive &ar, const unsigned int)
	{
		BSTSERILIZEBASE(CHPD_GZBlockBase);
	}
private:
	TestBlockData m_Data;
};
////�ֽ�
class Test_GJBlock :public CBWGJBlockBase
{
	friend  class  boost::serialization::access;
public:
	Test_GJBlock(){}
	explicit Test_GJBlock(std::shared_ptr<CBWDWGJBlock> pData) :CBWGJBlockBase(pData){}
	explicit Test_GJBlock(CBWDWGJBlock* pData) :CBWGJBlockBase(pData){}
	virtual ~Test_GJBlock(){}
	virtual Test_GJBlock* clone()const;
protected:
	template<class Archive>	void serialize(Archive &ar, const unsigned int)
	{
		BSTSERILIZEBASE(CBWGGBlockBase);
	}
};
//�ο��߻���
class Test_GRBlock :public CBWGRBlockBase
{
	friend  class  boost::serialization::access;
public:
	Test_GRBlock(){}
	virtual ~Test_GRBlock(){}
	virtual Test_GRBlock* clone()const;
protected:
	template<class Archive>	void serialize(Archive &ar, const unsigned int)
	{
		BSTSERILIZEBASE(CBWGRBlockBase);
	}
};

//ͼ��
class TestBlockGJ :public CBWBlockGJ
{
public:
	TestBlockGJ(const CString& BlockIndexName, const CString& BlockDrawName = "", bool bVirtualBlock = true)
		:CBWBlockGJ(BlockIndexName, BlockDrawName, bVirtualBlock){}
	virtual ~TestBlockGJ(){}
public:
	virtual const Test_GGBlock* GetGG() const;
	virtual const Test_GZBlock* GetGZ() const;
	virtual const Test_GJBlock* GetGJ() const;
	virtual const Test_GRBlock* GetGR() const;

	virtual void Draw(OUT CBWDrawGroup &);
	virtual void CreatDrawObjects();
};
THDRAW_INNEROUTLINE_END

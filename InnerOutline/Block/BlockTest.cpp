#pragma once
#include "stdafx.h"
#include "BlockTest.h"
#include "DrawObj.h"
THDRAW_INNEROUTLINE_BEGIN
Test_GGBlock* Test_GGBlock::clone()const
{
	return new Test_GGBlock(*this);
}
Test_GZBlock* Test_GZBlock::clone()const
{
	return new Test_GZBlock(*this);
}
void Test_GZBlock::CalculateDrawObjGZ()
{

}
void Test_GZBlock::CalculateGeneratrix()
{

}
Test_GJBlock* Test_GJBlock::clone()const
{
	return new Test_GJBlock(*this);
}
Test_GRBlock* Test_GRBlock::clone()const
{
	return new Test_GRBlock(*this);
}
const Test_GGBlock* TestBlockGJ::GetGG()const
{
	return dynamic_cast<Test_GGBlock*>(m_pGG.get());
	//����ת��dynamic_cast��static_cast��Ч����һ����
	//�������м��ʱdynamic_cast������ʱ�������ͼ�鹦�ܣ�����ȫ//
	//���m_pGG�ǻ���ָ�룬�þ�̬ת���õ��Ľ����ʹ���оͱȽ�Σ�գ�����̬ת���õ����ǿ�ָ����
	//��̬ת���л���������麯��������������̬ת��û���������
	//������������ʱ���ͼ����Ҫ����ʱ������Ϣ���������Ϣ�洢������麯���������麯����ĸ����ϸ�ɼ�<Inside c++ object model>���У�
	//ֻ�ж������麯����������麯����û�ж����麯��������û���麯����ġ�
}
const Test_GZBlock* TestBlockGJ::GetGZ()const
{
	return dynamic_cast<Test_GZBlock*>(m_pGZ.get());
}
const Test_GJBlock* TestBlockGJ::GetGJ()const
{
	return dynamic_cast<Test_GJBlock*>(m_pGJ.get());
}
const Test_GRBlock* TestBlockGJ::GetGR()const
{
	return dynamic_cast<Test_GRBlock*>(m_pGR.get());
}
void TestBlockGJ::Draw(OUT CBWDrawGroup &)
{

}
void TestBlockGJ::CreatDrawObjects()
{
	//��ӹ�����
	std::shared_ptr<TestDrawObj> gzlines(new TestDrawObj(this));
	Add(gzlines);
}
THDRAW_INNEROUTLINE_END

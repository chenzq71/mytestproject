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
	//上行转换dynamic_cast和static_cast的效果是一样的
	//再做下行检查时dynamic_cast在运行时具有类型检查功能，更安全//
	//如果m_pGG是基类指针，用静态转换得到的结果在使用中就比较危险，而动态转换得到的是空指针结果
	//动态转换中基类必须有虚函数，否则会出错，静态转换没有这个限制
	//这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表（关于虚函数表的概念，详细可见<Inside c++ object model>）中，
	//只有定义了虚函数的类才有虚函数表，没有定义虚函数的类是没有虚函数表的。
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
	//添加构造线
	std::shared_ptr<TestDrawObj> gzlines(new TestDrawObj(this));
	Add(gzlines);
}
THDRAW_INNEROUTLINE_END

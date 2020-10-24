#pragma once
//#ifdef __windows__
//#undef __windows__
//#endif

#include "pch.h"
//Md == _MT
#if defined(_DLL) && !defined(_AFXDLL)
#define _AFXDLL
#endif
#include <afx.h> 
#include <afxwin.h>
#include "CppUnitTest.h"
#include "../2DViewer/Square.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2DViewer
{
	TEST_CLASS(UnitTest2DViewer)
	{
	public:		
		TEST_METHOD(TestMethod1)
		{
			auto t = Square(SquareEB(5), { 0,0 });
			Assert::IsTrue(t.isInBorder({ 0,6 }), L"error");
		}
	};
}
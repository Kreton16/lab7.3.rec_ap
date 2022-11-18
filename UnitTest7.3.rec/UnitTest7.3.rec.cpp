#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int** a = new int* [5];
			for (int i = 0; i < 5; i++)
				a[i] = new int[2];
			int Low = -26;
			int High = 23;
			int sum = 0;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 2; j++)
					a[i][j] = Low + rand() % (High - Low + 1);
			int suma = SumAbsDiag(a, 5, sum, 0, 0);
			Assert::AreEqual(suma, sum);
		}
	};
}

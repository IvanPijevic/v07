#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace test
{
	TEST_CLASS(test)
	{
	public:

		TEST_METHOD(Plus)
		{
			money sum(1, 02);

			sum += money(1, 96);
			std::stringstream ss1;
			ss1 << sum;
			Assert::AreEqual("2 euro, 98 cent"s, ss1.str());

			sum += money(1, 00);
			std::stringstream ss2;
			ss2 << sum;
			Assert::AreEqual("3 euro, 98 cent"s, ss2.str());

		}

		TEST_METHOD(Minus)
		{
			money sum(1, 00);

			sum -= money(1, 96);
			std::stringstream ss1;
			ss1 << sum;
			Assert::AreEqual("-96 cent"s, ss1.str());

			sum -= money(1, 00);
			std::stringstream ss2;
			ss2 << sum;
			Assert::AreEqual("-1 euro, 96 cent"s, ss2.str());
		}

		TEST_METHOD(Mix)
		{
			money sum(1, 00);

			sum -= money(1, 96);
			std::stringstream ss1;
			ss1 << sum;
			Assert::AreEqual("-96 cent"s, ss1.str());

			sum += money(1, 00);
			std::stringstream ss2;
			ss2 << sum;
			Assert::AreEqual("04 cent"s, ss2.str());
		}
	};
}

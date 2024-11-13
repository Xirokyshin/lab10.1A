#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.1.A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountLowAverageStudents)
        {
            Student students[3] = {
                { "Ivanenko", 1, RI, {5, 4, 3} },
                { "Petrenko", 2, PZ, {3, 3, 3} },
                { "Shevchenko", 3, IR, {4, 4, 4} }
            };

            int count = CountHighAverageStudents(students, 3);
            Assert::AreEqual(0, count);
        }

        TEST_METHOD(TestFindSubjectWithLowestAverage)
        {
            Student students[3] = {
                { "Ivanenko", 1, RI, {5, 4, 3} },
                { "Petrenko", 2, PZ, {3, 3, 3} },
                { "Shevchenko", 3, IR, {4, 4, 4} }
            };

            string lowestAvgSubject = FindSubjectWithHighestAverage(students, 3);
            Assert::AreEqual(string("Фізика"), lowestAvgSubject);
        }
    };
}
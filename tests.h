#ifndef __SIMPLETEST_H
#define __SIMPLETEST_H

#include <cxxtest/TestSuite.h>

//
// A simple test suite: Just inherit CxxTest::TestSuite and write tests!
//

class SimpleTest : public CxxTest::TestSuite {
public:
    void testEquality() {
        TS_ASSERT_EQUALS(1, 1);
        TS_ASSERT_EQUALS(1, 2);
        TS_ASSERT_EQUALS('a', 'A');
        TS_ASSERT_EQUALS(1.0, -12345678900000000000000000000000000000000000000000.1234);
        const char* tmp = "foo";
        TS_ASSERT_EQUALS("foo", tmp);
    }

    void testBDD() {
        GSTEPS("Calc*") { // "Calc Addition.Add two numbers"
        auto result = 0;

        Given("I created a calculator with value {n}") = [&](int n) {
            Calculator calc{n};

            Given("I have entered {n} into the calculator") = [&](int n) {
            calc.push(n);
            };

            When("I press add") = [&] {
            result = calc.add();
            };

            Then("The result should be {expected}") = [&](int expected) {
            EXPECT_EQ(expected, result);
            };
        };
        }
    }

    void testAddition() {
        TS_ASSERT_EQUALS(1 + 1, 2);
        TS_ASSERT_EQUALS(2 + 2, 5);
    }

    void TestMultiplication() {
        TS_ASSERT_EQUALS(2 * 2, 4);
        TS_ASSERT_EQUALS(4 * 4, 44);
        TS_ASSERT_DIFFERS(-2 * -2, 4);
    }

    void testComparison() {
        TS_ASSERT_LESS_THAN((int)1, (unsigned long)2);
        TS_ASSERT_LESS_THAN(-1, -2);
    }

    void testTheWorldIsCrazy() {
        TS_ASSERT_EQUALS(true, false);
    }

    void test_Failure() {
        TS_FAIL("Not implemented");
        TS_FAIL(1569779912);
    }

    void test_TS_SKIP_macro() {
        TS_SKIP("Simply skip this test");
        TS_WARN("Skipping will abort the test");
    }

    void test_TS_WARN_macro() {
        TS_WARN("Just a friendly warning");
        TS_WARN("Warnings don't abort the test");
    }
};


#endif // __SIMPLETEST_H
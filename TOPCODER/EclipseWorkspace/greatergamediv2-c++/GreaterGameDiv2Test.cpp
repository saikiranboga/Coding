#include "GreaterGameDiv2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class GreaterGameDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    GreaterGameDiv2 solution;

    void testCase0() {
        int snuke_[] = {1, 3};
        vector<int> snuke(snuke_, snuke_ + (sizeof(snuke_) / sizeof(snuke_[0])));
        int sothe_[] = {4, 2};
        vector<int> sothe(sothe_, sothe_ + (sizeof(sothe_) / sizeof(sothe_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.calc(snuke, sothe));
    }

    void testCase1() {
        int snuke_[] = {1, 3, 5, 7, 9};
        vector<int> snuke(snuke_, snuke_ + (sizeof(snuke_) / sizeof(snuke_[0])));
        int sothe_[] = {2, 4, 6, 8, 10};
        vector<int> sothe(sothe_, sothe_ + (sizeof(sothe_) / sizeof(sothe_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.calc(snuke, sothe));
    }

    void testCase2() {
        int snuke_[] = {2};
        vector<int> snuke(snuke_, snuke_ + (sizeof(snuke_) / sizeof(snuke_[0])));
        int sothe_[] = {1};
        vector<int> sothe(sothe_, sothe_ + (sizeof(sothe_) / sizeof(sothe_[0])));
		int expected_ = 1;
        assertEquals(2, expected_, solution.calc(snuke, sothe));
    }

    void testCase3() {
        int snuke_[] = {3, 5, 9, 16, 14, 20, 15, 17, 13, 2};
        vector<int> snuke(snuke_, snuke_ + (sizeof(snuke_) / sizeof(snuke_[0])));
        int sothe_[] = {6, 18, 1, 8, 7, 10, 11, 19, 12, 4};
        vector<int> sothe(sothe_, sothe_ + (sizeof(sothe_) / sizeof(sothe_[0])));
		int expected_ = 6;
        assertEquals(3, expected_, solution.calc(snuke, sothe));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        GreaterGameDiv2Test test;
        test.runTest(i);
    }
}

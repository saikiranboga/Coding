#include "PathGameDiv2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PathGameDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    PathGameDiv2 solution;

    void testCase0() {
        string board_[] = {"#....", "...#."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.calc(board));
    }

    void testCase1() {
        string board_[] = {"#", "."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.calc(board));
    }

    void testCase2() {
        string board_[] = {".", "."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 1;
        assertEquals(2, expected_, solution.calc(board));
    }

    void testCase3() {
        string board_[] = {"....#.##.....#...........", "..#......#.......#..#...."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 13;
        assertEquals(3, expected_, solution.calc(board));
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
        PathGameDiv2Test test;
        test.runTest(i);
    }
}

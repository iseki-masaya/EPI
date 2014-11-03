#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

bool parityCheck(long long v) {
    bool result = 0;
    while (v) {
        result ^= (v&1);
        v >>= 1;
    }
    return result;
}

int main() {
    map<long long, bool> test_suite = {
        {1LL<<34 | 1LL<< 60, 0},
        {1LL<<31 | 1LL<< 34 | 1LL<<36 | 1LL<< 40, 0},
        {1LL<<14 | 1LL<< 20 | 1LL<<23, 1},
        {1LL<<2  | 1LL<< 10 | 1LL<<16 | 1LL<< 24 | 1LL<<30 | 1LL<< 40, 0},
        {1LL<<5  | 1LL<< 13 | 1LL<<16 | 1LL<< 20 | 1LL<<24 | 1LL<< 26 | 1LL<<30, 1},
        {1LL<<34 | 1LL<< 40, 0},
    };
    for (auto test: test_suite) {
        if (test.second == parityCheck(test.first))
            cout << "PASS" << endl;
        else
            cout << "FAIL" << endl;
    }
}
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

void rearrange(vector<int> &A, int i) {
    int N = (int)A.size();
    int small = 0, equal = 0, large = N-1;
    int pivot = A[i];
    while (equal < large) {
        if (A[equal] < pivot)
            swap(A[small++], A[equal++]);
        else if (A[equal] == pivot)
            equal++;
        else
            swap(A[equal], A[large--]);
    }
}

bool evaluate(vector<int> &A, int pivot) {
    int N = (int)A.size();
    int s = 0;
    while (A[s] < pivot ) s++;
    while (A[s] == pivot) s++;
    while (A[s] > pivot && s<N ) s++;
    return s == N;
}

int main() {

    vector<pair<vector<int>, int> > test_suite = {
        {{1, 7, 4, 5, 9, 4, 3, 10, 2}, 5},
        {{1, 1, 1, 1, 1, 1, 1}, 3},
        {{109534, 654364342, 7564724, 7456734, 4342, 43, 52435}, 5}
    };
    for (auto test: test_suite) {
        vector<int> v(test.first);
        int i = test.second;
        int pivot = v[i];
        rearrange(v, i);
        if (evaluate(v, pivot))
            cout << "PASS" << endl;
        else
            cout << "FAIL" << endl;
    }
}
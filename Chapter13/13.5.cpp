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
#include <unordered_map>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

// O(max(N,M))
template <typename T>
vector<T> func1(const vector<T> &A, const vector<T> &B) {
    unordered_map<T, int> hash;
    for_each(A.begin(), A.end(), [&hash](const T &v){hash[v]++; });

    vector<T> C;
    shared_ptr<T> prv(new T);
    for (T v: B) {
        if (*prv != v && hash[v]) {
            C.push_back(v);
        }
        *prv = v;
    }
    return C;
}

// O(NlogM)
template <typename T>
vector<T> func2(const vector<T> &A, const vector<T> &B) {
    vector<T> C;
    shared_ptr<T> prv(new T);
    for (T v: A) {
        if (v == *prv)
            continue;
        auto it = lower_bound(B.begin(), B.end(), v);
        if (*it == v)
            C.push_back(v);
        *prv = v;
    }
    return C;
}

// O(max(N,M))
template <typename T>
vector<T> func3(const vector<T> &A, const vector<T> &B) {
    vector<T> C;
    size_t i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j] && (i == 0 || A[i] != A[i-1]) )
            C.push_back(A[i++]);
        else if (A[i] > B[j])
            ++j;
        else
            ++i;
    }
    return C;
}

int main() {
    vector<int> A = {1,2,3,4,5,5,6,6,7};
    vector<int> B = {1,2,3,4,5,5,6,6,7,8,9,10};
    vector<int> ans(func3(A, B));
    for (int v: ans) {
        cout << v << endl;
    }
}
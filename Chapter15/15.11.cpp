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

int count2(const string &A, const string &B) {
    int N = (int)A.size(), M = (int)B.size();
    vector<int> next(M+1, INF), prev(M+1, 0);
    next[0] = 1;
    iota(prev.begin(), prev.end(), 1);
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            int cost = A[i-1] == B[j-1] ? 0 : 1;
            next[j] = min(prev[j-1]+cost, min(prev[j] + 1, next[j-1] + 1));
        }
        prev = next;
    }
    return next[M];
}

int count1(const string &A, const string &B) {
    int N = (int)A.size(), M = (int)B.size();
    vector<vector<int> > dp(N+1, vector<int>(M+1, INF));
    for (int i=0; i<=N; ++i)
        dp[i][0] = i;
    for (int j=0; j<=M; ++j)
        dp[0][j] = j;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            int cost = A[i-1] == B[j-1] ? 0 : 1;
            dp[i][j] = min(dp[i-1][j-1]+cost, min(dp[i-1][j] + 1, dp[i][j-1] + 1) );
        }
    }
    return dp[N][M];
}

int main() {
    string A = "Carthorse";
    string B = "Orchestra";
    cout << count(A, B) << endl;
}
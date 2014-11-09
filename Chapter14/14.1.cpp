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

template <typename T>
class BinaryTree {
public:
    BinaryTree(T d) : data(d) {}
    T data;
    shared_ptr<BinaryTree<T> > left, right;
};

/** Morris in-order traversal
 *  Time compexity: O(N)
 *  N: vertices
 *  Space complexity: O(1)
 */
template <typename T>
bool check3(shared_ptr<BinaryTree<T>> n) {
    T last = numeric_limits<T>::min();
    bool res = true;
    while (n) {
        if (n->left) {
            shared_ptr<BinaryTree<T>> pre = n->left;
            while (pre->right && pre->right != n) {
                pre = pre->right;
            }

            if (pre->right) {
                pre->right = nullptr;
                if (last > n->data) {
                    res = false;
                }
                last = n->data;
                n = n->right;
            } else {
                pre->right = n;
                n = n->left;
            }
        } else {
            if (last > n->data) {
                res = false;
            }
            last = n->data;
            n = n->right;
        }
    }
    return res;
}

/** Recursive
 *  Time compexity: O(N)
 *  N: vertices
 *  Space complexity: O(H)
 *  H: Height of a tree
 */
template <typename T>
bool range(const shared_ptr<BinaryTree<T> > r, const T& lower, const T& upper) {
    if (!r)
        return true;
    else if (r->data < lower || upper < r->data)
        return false;
    return range(r->left, lower, r->data) &&
    range(r->right, r->data, upper);
}

template <typename T>
bool check1(const shared_ptr<BinaryTree<T> > parent) {
    return range(parent, numeric_limits<T>::min(), numeric_limits<T>::max());
}

/** Recursive
 *  Time compexity: O(N^2)
 *  N: vertices
 *  Space complexity: O(H)
 *  H: Height of a tree
 */
template <typename T>
T max(const shared_ptr<BinaryTree<T> > parent) {
    T mx = parent->data;
    if (parent->left)
        mx = max(mx, max<T>(parent->left));
    if (parent->right)
        mx = max(mx, max<T>(parent->right));
    return mx;
}

template <typename T>
T min(const shared_ptr<BinaryTree<T> > parent) {
    T mn = parent->data;
    if (parent->left)
        mn = min(mn, min<T>(parent->left));
    if (parent->right)
        mn = min(mn, min<T>(parent->right));
    return mn;
}

template <typename T>
bool check2(const shared_ptr<BinaryTree<T> > parent) {
    if ( (!parent->left  || max<T>(parent->left) <= parent->data) &&
            (!parent->right || parent->data <= min<T>(parent->right)) ) {
        return ( !parent->left || check2(parent->left) ) && ( !parent->right || check2(parent->right));
    } else {
        return false;
    }
}



int main() {
    shared_ptr<BinaryTree<int>> A(new BinaryTree<int>(19));
    shared_ptr<BinaryTree<int>> B(new BinaryTree<int>(7));
    shared_ptr<BinaryTree<int>> C(new BinaryTree<int>(3));
    shared_ptr<BinaryTree<int>> D(new BinaryTree<int>(2));
    shared_ptr<BinaryTree<int>> E(new BinaryTree<int>(5));
    shared_ptr<BinaryTree<int>> F(new BinaryTree<int>(11));
    shared_ptr<BinaryTree<int>> G(new BinaryTree<int>(17));
    shared_ptr<BinaryTree<int>> H(new BinaryTree<int>(13));
    shared_ptr<BinaryTree<int>> I(new BinaryTree<int>(43));
    shared_ptr<BinaryTree<int>> J(new BinaryTree<int>(23));
    shared_ptr<BinaryTree<int>> K(new BinaryTree<int>(37));
    shared_ptr<BinaryTree<int>> L(new BinaryTree<int>(29));
    shared_ptr<BinaryTree<int>> M(new BinaryTree<int>(31));
    shared_ptr<BinaryTree<int>> N(new BinaryTree<int>(41));
    shared_ptr<BinaryTree<int>> O(new BinaryTree<int>(47));
    shared_ptr<BinaryTree<int>> P(new BinaryTree<int>(53));
    A->left = B;
    A->right = I;

    B->left = C;
    B->right = F;

    C->left = D;
    C->right = E;

    F->right = G;

    G->left = H;

    I->left = J;
    I->right = O;

    J->right = K;

    K->left = L;
    K->right = N;

    L->right = M;

    O->right = P;

    cout << check1(A) << endl;
    check3(A);
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <climits>
#include <cstdint>
#include <algorithm>
#include <queue>

#define KK 6
using namespace std;

// UVa 441 Lotto
// Generating all combinations of a set + lexicographic sorting
// What I did: use bit vectors to generate all 2^n subsets, and then lexicographically sort everything
// Potential improvement: implement the combinations backtrack algorithm? we just need to
// differentiate between n and k.
int main()
{
    int k, S[14];
    bool p = false;
    while (true) {
        vector<vector<int> > solutions;
        cin >> k;
        if (k < 6 || k > 13)
            break;
        for (int i = 0; i < k; ++i)
            cin >> S[i];
        if (p) {
            printf("\n");
        } else
            p = true;
        for (int i = 0; i < (1 << k); ++i) {
            vector<int> solution;
            unsigned count = 0;
            for (int j = 0; j < k; ++j)
                if (i >> j & 1) ++count;
            if (count == KK) {
                for (int j = 0; j < k; ++j) {
                    if (i >> j & 1) {
                        solution.push_back(S[j]);
                    }
                }
                solutions.push_back(solution);
            }
        }
        //lexisort
        sort(solutions.begin(), solutions.end(), [](const vector<int> &v1, const vector<int> &v2) {
            unsigned i = 0;
            while (i < KK && v1[i] == v2[i])
                ++i;
            return v1[i] < v2[i];
        });
        //lexiprint
        for (unsigned i = 0; i < solutions.size() - 1; ++i) {
            for(unsigned j = 0; j < solutions[i].size() - 1; ++j)
                cout << solutions[i][j] << " ";
            cout << solutions[i][solutions[i].size() - 1];
            cout << "\n";
        }
        {
            const auto &v = *(solutions.end() - 1);
            for(unsigned j = 0; j < v.size() - 1; ++j)
                cout << v[j] << " ";
            cout << v[v.size() - 1];
            cout << "\n";
        }
    }
    return 0;
}
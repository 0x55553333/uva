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
#include <string>

using namespace std;

char table[256][5];

int n(char c)
{
    switch (c) {
        case 'r':
            return 0;
        case 'o':
            return 1;
        case 'y':
            return 2;
        case 'g':
            return 3;
        case 'b':
            return 4;
        default:
            return -1;
    }
}
//
// UVa 154 Recycling
// **IMPORTANT**: Do not overthink!!
// another solution I came up with was to record the most popular ones, sort, and then start searching
// from top. But that's more costly to implement, and actually not as efficient as this one.
int main()
{
    string s;
    int k = 0, min = INT_MAX, min_city = -1, len;
    do {
        cin >> s;
        if (s[0] == '#') break;
        if (s[0] == 'e') {
            for (int i = 0; i < k; ++i) {
                int diff = 0;
                char r = table[i][0], o = table[i][1], y = table[i][2], g = table[i][3], b = table[i][4];
                for (int j = 0; j < k; ++j) {
                    if (r != table[j][0]) ++diff;
                    if (o != table[j][1]) ++diff;
                    if (y != table[j][2]) ++diff;
                    if (g != table[j][3]) ++diff;
                    if (b != table[j][4]) ++diff;

                }
                if (diff < min) {
                    min = diff;
                    min_city = i + 1;
                }
            }
            cout << min_city << endl;
            // finalize
            min = INT_MAX;
            min_city = -1;
            k = 0;
        } else {
            for (int i = 0; i < 5; ++i) {
                table[k][n(s[i * 4])] = *(s.begin() + i * 4 + 2);
            }
            ++k;
        }
    } while (s[0]!='#');
    return 0;
}
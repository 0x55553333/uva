#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <climits>
#include <cstdint>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;
char board[16]; //4*4
int N, NxN;

// i = row, j = column
bool is_valid(int i, int j, char board2[])
{
    bool valid = true;
    if (i >= N || j >= N || board2[i * 4 + j] != '.')
        return false;
    // column attack
    for (int k = 0; k < i; ++k) {
        if (board2[k * 4 + j] == '*')
            valid = false;
        else if (board2[k * 4 + j] == 'X')
            valid = true;
    }
    if (!valid) return false;
    for (int k = N - 1; k > i; --k) {
        if (board2[k * 4 + j] == '*')
            valid = false;
        else if (board2[k * 4 + j] == 'X')
            valid = true;
    }
    if (!valid) return false;
    for (int k = 0; k < j; ++k) {
        if (board2[i * 4 + k] == '*')
            valid = false;
        else if (board2[k * 4 + j] == 'X')
            valid = true;
    }
    if (!valid) return false;
    for (int k = N - 1; k > j; --k) {
        if (board2[i * 4 + k] == '*')
            valid = false;
        else if (board2[i * 4 + k] == 'X')
            valid = true;
    }
    return valid;
}

int place(int i, int j)
{

    if (!is_valid(i, j, board))
        return 0;
    board[i * 4 + j] = '*'; // place this
    int max = 0;
    for (int k = 0; k < N; ++k) {
        for (int l = 0; l < N; ++l) {
            int g = place(l, k);
            if (g > max)
                max = g;
        }
    }
    board[i * 4 + j] = '.'; // unplace this
    return max + 1;
}

// UVa 639
// Don't get rooked!
// This is quite a strange backtracking problem...
// it requires doing the same work (same loops!) around different corners
// it's still strange thinking how I did it
int main()
{
    do {
        cin >> N;
        if (N <= 0)
            break;
        NxN = N * N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                cin >> board[i * 4 + j];
            }

        int max = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int g = place(i, j);
                if (g > max)
                    max = g;
            }
        }
        cout << max << endl;
        // clean up
        memset(board, 0, 16);
        N = 0;
    } while (true);
    return 0;
}
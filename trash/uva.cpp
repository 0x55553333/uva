#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

int g[32][32][4];
char dirName[1024] = "NESW";
const int dx[] = {-1, 0, 1, 0}; // N, E, S, W
const int dy[] = {0, 1, 0, -1};
void bfs(int sx, int sy, int sdir, int ex, int ey) {
    int visited[32][32][4] = {};
    int fdir[] = {-1, 1, 0}, tx, ty;
    queue<int> X, Y, D;
    pair<int, pair<int, int> > from[32][32][4];
    int ox = sx, oy = sy;
    sx += dx[sdir], sy += dy[sdir];
    X.push(sx), Y.push(sy), D.push(sdir);
    visited[sx][sy][sdir] = 1;
    from[sx][sy][sdir] = make_pair(-1, make_pair(-1, -1));
    while (!X.empty()) {
        sx = X.front(), X.pop();
        sy = Y.front(), Y.pop();
        sdir = D.front(), D.pop();
        if (sx == ex && sy == ey) {
            int tx, ty, dir;
            stack< pair<int, int> > stk;
            tx = sx, ty = sy, dir = sdir;
            while (tx >= 0) {
                stk.push(make_pair(tx, ty));
                int ttx = from[tx][ty][dir].second.first;
                int tty = from[tx][ty][dir].second.second;
                int tdd = from[tx][ty][dir].first;
                tx = ttx, ty = tty, dir = tdd;
            }
            stk.push(make_pair(ox, oy));
            int output = 0;
            while (!stk.empty()) {
                if (output%10 == 0) {
                    printf("\n ");
                }
                pair<int, int> pt = stk.top();
                stk.pop();
                printf(" (%d,%d)", pt.first, pt.second);
                output++;
            }
            puts("");
            return ;
        }

        for (int i = 0; i < 3; i++) {
            if (g[sx][sy][sdir]&(1<<i)) {
                int dir = (sdir + fdir[i] + 4)%4;
                tx = sx + dx[dir], ty = sy + dy[dir];
                if (visited[tx][ty][dir] == 0) {
                    visited[tx][ty][dir] = 1;
                    X.push(tx), Y.push(ty), D.push(dir);
                    from[tx][ty][dir] = make_pair(sdir, make_pair(sx, sy));
                }
            }
        }
    }
    printf("\n  No Solution Possible\n");
}
int main() {
    char testcase[1024], sdir[1024];
    int x, y, sx, sy, ex, ey;
    while (gets(testcase) && strcmp("END", testcase)) {
        memset(g, 0, sizeof(g));
        scanf("%d %d %s %d %d", &sx, &sy, sdir, &ex, &ey);
        while (scanf("%d", &x) == 1 && x) {
            scanf("%d", &y);
            char token[10];
            while (scanf("%s", token) == 1 && token[0] != '*') {
                int dir = find(dirName, dirName+4, token[0]) - dirName;
                int follow = 0;
                for (int i = 1; token[i]; i++) {
                    switch (token[i]) {
                        case 'L': follow |= 1; break;
                        case 'R': follow |= 2; break;
                        case 'F': follow |= 4; break;
                    }
                }
                g[x][y][dir] = follow;
            }
        }
        int dir = find(dirName, dirName+4, sdir[0]) - dirName;
        printf("%s", testcase);
        bfs(sx, sy, dir, ex, ey);
        while (getchar() != '\n');
    }
    return 0;
}


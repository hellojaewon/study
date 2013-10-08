#include <cstdio>

char board[20][20];
int h, w;

int blocks[4][3][2] = {
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

int solve () {
    int start_h = -1;
    int start_w = -1;
    bool found = false;
    for (unsigned i = 0; i < h; i++) {
        for (unsigned j = 0; j < w; j++) {
            if (board[i][j] == '.') {
                start_h = i;
                start_w = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found) return 1;
    if (start_h == h-1) return 0;

    int cases = 0;
    if (start_w == 0) {
        for (unsigned k = 0; k < 3; k++) {
            if (board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] == '.' &&
                board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] == '.' &&
                board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] == '.') {
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '#';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '#';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '#';
                    cases += solve();
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '.';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '.';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '.';
            }
        }
    } else if (start_w == w-1) {
        for (unsigned k = 3; k < 4; k++) {
            if (board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] == '.' &&
                board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] == '.' &&
                board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] == '.') {
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '#';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '#';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '#';
                    cases += solve();
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '.';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '.';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '.';
            }
        }
    } else {
        for (unsigned k = 0; k < 4; k++) {
            if (board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] == '.' &&
                board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] == '.' &&
                board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] == '.') {
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '#';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '#';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '#';
                    cases += solve();
                    board[start_h+blocks[k][0][0]][start_w+blocks[k][0][1]] = '.';
                    board[start_h+blocks[k][1][0]][start_w+blocks[k][1][1]] = '.';
                    board[start_h+blocks[k][2][0]][start_w+blocks[k][2][1]] = '.';
            }
        }
    }
    return cases;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d", &h, &w);
        for (unsigned i = 0; i < h; i++) {
            char buf[21];
            scanf("%s", buf);
            for (unsigned j = 0; j < w; j++) {
                board[i][j] = buf[j];
            }
        }

        int white = 0;
        for (unsigned i = 0; i < h; i++) {
            for (unsigned j = 0; j < w; j++) {
                if (board[i][j] == '.')
                    white++;
            }
        }
        printf("%d\n", white % 3 == 0 ? solve() : 0);
    }

    return 0;
}

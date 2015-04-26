#include <cstdio>
#include <cstring>
#include <cassert>

char left[10], right[10], operation, equals, result[11];

struct digit {
    char s[11];
    int  i;
};

int convert (char * str, bool toStr, int source, char ** dest) {
    static struct digit digits[11] = {
        {"zero",  0},
        {"one",   1},
        {"two",   2},
        {"three", 3},
        {"four",  4},
        {"five",  5},
        {"six",   6},
        {"seven", 7},
        {"eight", 8},
        {"nine",  9},
        {"ten",  10}
    };

    if (toStr) {
        for (unsigned i = 0; i < 11; i++) {
            if (source == digits[i].i) {
                *dest = digits[i].s;
                return true;
            }
        }
        assert(0);
    } else {
        for (unsigned i = 0; i < 11; i++) {
            if (!strcmp(digits[i].s, str))
                return digits[i].i;
        }
        assert(0);
    }
    return -1;
}

int calculate (int l, int r) {
    switch (operation) {
        case '+':
            return l+r;
        case '-':
            return l-r;
        case '*':
            return l*r;
    }
    assert(0);
    return -1;
}

bool solve () {
    int l = convert(left, false, 0, NULL);
    int r = convert(right, false, 0, NULL);
    int res = calculate(l, r);
    if (res < 0 || res > 10)
        return false;

    char * resStr = NULL;
    convert(NULL, true, res, &resStr);

    if (strlen(resStr) != strlen(result))
        return false;

    int tmp[128];
    for (unsigned i = 0; i < 128; i++)
        tmp[i] = 0;
    int len = strlen(resStr);
    for (unsigned i = 0; i < len; i++)
        tmp[resStr[i]]++;
    len = strlen(result);
    for (unsigned i = 0; i < len; i++)
        tmp[result[i]]--;
    for (unsigned i = 0; i < 128; i++) {
        if (tmp[i] != 0)
            return false;
    }
    return true;
}

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %c %s %c %s", left, &operation, right, &equals, result);
        printf("%s\n", solve() ? "Yes" : "No");
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> serials;

int sum (const string & str) {
    int sumStr = 0;
    for (auto x : str) {
        if (!std::isalpha(x))
            sumStr += x - '0';
    }
    return sumStr;
}

bool cmp (const string & a, const string & b) {
    if (a.size() != b.size())
        return a.size() < b.size();

    int sumA = sum(a);
    int sumB = sum(b);
    return (sumA == sumB) ? a < b : sumA < sumB;
}

int main () {
    int n;
    scanf("%d", &n);
    char tmp[51];
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        serials.push_back(tmp);
    }
    std::sort(serials.begin(), serials.end(), cmp);
    for (string serial : serials)
        cout<<serial<<endl;

    return 0;
}

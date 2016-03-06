#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> words;

bool cmp (const string & a, const string & b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main () {
    int n;
    scanf("%d", &n);
    char tmp[51];
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        words.push_back(tmp);
    }
    std::sort(words.begin(), words.end(), cmp);
    string prev = "";
    for (auto word : words) {
        if (prev != word) {
            printf("%s\n", word.c_str());
            prev = word;
        }
    }
    return 0;
}

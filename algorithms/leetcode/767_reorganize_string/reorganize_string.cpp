#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define PUSH(v, p, c) v.push_back(p); std::push_heap(v.begin(), v.end(), c);
#define POP(v, c)        std::pop_heap(v.begin(), v.end(), c); v.pop_back();

int charToIndex (char c) {
    return c-'a';
}

string reorganizeString(string S) {
    vector<pair<char,int>> t(26);
    for (auto c : S) {
        t[charToIndex(c)].first = c;
        t[charToIndex(c)].second++;
    }

    auto comparator = [](const pair<char,int> & lhs, const pair<char,int> & rhs) { return lhs.second < rhs.second; };

    std::make_heap(t.begin(), t.end(), comparator);

    string result = "";
    bool done = false;
    while (true) {
        pair<char,int> p = t.front();
        POP(t, comparator);
        if (p.second == 0) {
            done = true;
            break;
        }

        if (!result.empty() && result.back() == p.first) {
            pair<char,int> p2 = t.front();
            POP(t, comparator);
            if (p2.second == 0)
                break;
            p2.second--;
            PUSH(t, p, comparator);
            PUSH(t, p2, comparator);
            result.push_back(p2.first);
        } else {
            p.second--;
            PUSH(t, p, comparator);
            result.push_back(p.first);
        }
    }
    return done ? result : "";
}

int main () {
    assert(reorganizeString("aab") == "aba");
    assert(reorganizeString("aaab") == "");
    assert(reorganizeString("bbbbaaaaababaababab") == "abababababababababa");
    assert(reorganizeString("vvvlo") == "vlvov");
    return 0;
}

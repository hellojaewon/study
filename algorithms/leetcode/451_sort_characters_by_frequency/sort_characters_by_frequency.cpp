#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> table;
    for (auto c : s)
        table[c]++;

    vector<pair<char,int>> v;
    for (auto & p : table)
        v.push_back(p);

    sort(
        v.begin(),
        v.end(),
        [](const pair<char,int> & lhs, const pair<char,int> & rhs) { return lhs.second > rhs.second; }
    );

    string result;
    for (auto & p : v)
        result.insert(result.end(), p.second, p.first);

    return result;
}

int main () {
    auto res1 = frequencySort("tree");
    assert(res1 == "eert" || res1 == "eetr");
    auto res2 = frequencySort("cccaaa");
    assert(res2 == "cccaaa" || res2 == "aaaccc");
    auto res3 = frequencySort("Aabb");
    assert(res3 == "bbAa" || res3 == "bbaA");
    return 0;
}

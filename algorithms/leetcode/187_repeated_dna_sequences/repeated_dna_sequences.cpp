#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    int start = 0, end = 9;
    int size = s.size();
    unordered_map<string, int> table;
    while (end < size) {
        table[s.substr(start, 10)]++;
        start++;
        end++;
    }

    vector<string> result;
    for (auto & p : table)
        if (p.second > 1)
            result.push_back(p.first);

    return result;
}

int main () {
    auto res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    assert(res.size() == 2);
    assert(   res[0] == "AAAAACCCCC" && res[1] == "CCCCCAAAAA"
           || res[1] == "AAAAACCCCC" || res[0] == "CCCCCAAAAA"
    );

    return 0;
}

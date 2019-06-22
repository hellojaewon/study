#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> table;
    for (string & s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        auto found = table.find(sorted);
        if (found == table.end()) {
            vector<string> v;
            v.push_back(s);
            table.insert(make_pair(sorted, v));
        } else {
            found->second.push_back(s);
        }
    }

    vector<vector<string>> result;
    for (auto & p : table) {
        vector<string> row;
        for (auto & s : p.second)
            row.push_back(s);
        result.push_back(row);
    }

    return result;
}

int main () {

    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(strs);
    assert(res.size() == 3);
    return 0;
}

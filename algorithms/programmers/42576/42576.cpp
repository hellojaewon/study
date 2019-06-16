#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> table;
    for (auto & c : completion) {
        table[c]++;
    }
    for (auto & p : participant) {
        auto found = table.find(p);
        if (found == table.end())
            return p;
        found->second--;
        if (found->second == 0)
            table.erase(found);
    }
    return table.begin()->first;
}

int main () {
    vector<string> p1{"leo", "kiki", "eden"};
    vector<string> c1{"eden", "kiki"};
    string r1 = "leo";

    vector<string> p2{"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> c2{"josipa", "filipa", "marina", "nikola"};
    string r2 = "vinko";

    vector<string> p3{"mislav", "stanko", "mislav", "ana"};
    vector<string> c3{"stanko", "ana", "mislav"};
    string r3 = "mislav";

    assert(solution(p1, c1) == r1);
    assert(solution(p2, c2) == r2);
    assert(solution(p3, c3) == r3);
    return 0;
}

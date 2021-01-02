#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void printVector(const vector<int> & v) {
    for (auto x : v)
        cout<<x<<", ";
    cout<<endl;
}

vector<int> partitionLabels(string S) {
    vector<int> result;
    vector<int> last(26,0);

    for (int i = 0; i < S.size(); i++)
        last[S[i]-'a'] = i;

    int i = 0;
    while (i < S.size()) {
        int start = i;
        int end = last[S[i]-'a'];
        for (int j = start; j < S.size(); j++) {
            if (j == end)
                break;
            int newEnd = last[S[j]-'a'];
            if (end < newEnd)
                end = newEnd;
        }
        result.push_back(end-start+1);
        i = end + 1;
    }

    return result;
}

int main () {
    auto result = partitionLabels("ababcbacadefegdehijhklij");
    assert(result.size() == 3);

    result = partitionLabels("aaa");
    assert(result.size() == 1);

    result = partitionLabels("abcdefg");
    assert(result.size() == 7);

    result = partitionLabels("ab");
    assert(result.size() == 2);

    result = partitionLabels("a");
    assert(result.size() == 1);

    result = partitionLabels("aaa");
    assert(result.size() == 1);

    return 0;
}

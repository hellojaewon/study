#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

void addMapping (unordered_map<char, char> & mapped, char from, char to) {
    if (mapped.find(from) != mapped.end())
        return;
    mapped.insert(make_pair(from, to));
}

bool match (string & word, string pattern) {
    unordered_map<char, char> mapped;
    unordered_map<char, char> r_mapped;
    for (int i = 0; i < word.size(); i++) {
        addMapping(mapped, pattern[i], word[i]);
        addMapping(r_mapped, word[i], pattern[i]);
        if (   mapped.find(pattern[i])->second != word[i]
            || r_mapped.find(word[i])->second != pattern[i]
        )
            return false;
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> result;
    for (auto & word : words) {
        if (match(word, pattern))
            result.push_back(word);
    }
    return result;
}

int main () {
    vector<string> words1{"abc","deq","mee","aqq","dkd","ccc"};
    string pattern1 = "abb";
    auto result = findAndReplacePattern(words1, pattern1);
    assert(result.size() == 2);
    assert(result[0] == "mee");
    assert(result[1] == "aqq");

    vector<string> words2{"abc","cba","xyx","yxx","yyx"};
    string pattern2 = "abc";
    result = findAndReplacePattern(words2, pattern2);
    assert(result.size() == 2);
    assert(result[0] == "abc");
    assert(result[1] == "cba");
    return 0;
}

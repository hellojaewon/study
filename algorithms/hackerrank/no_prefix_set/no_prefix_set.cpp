#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <memory>

using namespace std;

struct Trie {
    char c;
    bool leaf;
    shared_ptr<Trie> child[10];
    Trie (char c) : c(c) {
        for (int i = 0; i < 10; i++)
            child[i] = nullptr;
        leaf = false;
    }
};

int ToIndex (char c) {
    return c-'a';
}

bool Find (shared_ptr<Trie> root, const string & s) {
    if (!s.size())
        return true;

    int i = ToIndex(s[0]);
    if (root->child[i] == nullptr)
        return false;
    return Find(root->child[i], s.substr(1));
}

bool Add (shared_ptr<Trie> root, const string & s) {
    if (!s.size()) {
        root->leaf = true;
        return true;
    }

    if (root->leaf) return false;

    int i = ToIndex(s[0]);
    if (root->child[i] == nullptr)
        root->child[i] = make_shared<Trie>(s[0]);
    return Add(root->child[i], s.substr(1));
}

vector<string> solve (vector<string> & ss) {
    vector<string> result;
    auto root = make_shared<Trie>('x');
    for (auto & s : ss) {
        if (Find(root, s) || !Add(root, s)) {
            result.push_back("BAD SET");
            result.push_back(s);
            return result;
        }
    }
    result.push_back("GOOD SET");
    return result;
}

int main () {
    int n;
    cin>>n;
    vector<string> ss;
    while (n--) {
        char tmp[61] = {0,};
        scanf("%s", tmp);
        ss.push_back(tmp);
    }
    auto result = solve(ss);
    for (auto r : result) {
        cout<<r<<endl;
    }

//    vector<string> ss{"aab", "defgab", "abcde", "aabcde", "cedaaa", "bbbbbbbbbb", "jabjjjad"};
//    auto result = solve(ss);
//    for (auto x : result) {
//        cout<<x<<endl;
//    }
//    assert(result.size() == 2);
//    assert(result[0] == "BAD SET");
//    assert(result[1] == "aabcde");
    return 0;
}

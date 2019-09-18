#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

static unsigned count = 0;
static std::unordered_map<string, string> encodes;
static std::unordered_map<string, string> decodes;

string encode(string longUrl) {
    auto found = encodes.find(longUrl);
    if (found != encodes.end())
        return found->second;

    string shortUrl = std::to_string(++count);
    encodes.insert(std::make_pair(longUrl, shortUrl));
    decodes.insert(std::make_pair(shortUrl, longUrl));
    return shortUrl;
}

string decode(string shortUrl) {
    auto found = decodes.find(shortUrl);
    if (found != decodes.end())
        return found->second;
    return {};
}

int main () {
    std::string url = "https://leetcode.com/problems/design-tinyurl";
    assert(decode(encode(url)) == url);
    return 0;
}

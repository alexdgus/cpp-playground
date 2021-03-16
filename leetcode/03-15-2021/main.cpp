/* TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk. */

/* Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need to
 * ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL. */

class Solution {
public:
    string generateHash(string url) {
        string hash;
        for(int i = 0; i < 7; i++) {
            hash.push_back(hashChars[rand() % 35]);
        }
        return hash;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string hash;
        do {
            hash = generateHash(longUrl);
        } while(tinyMap.find(hash) != tinyMap.end());
        tinyMap.insert(pair<string, string>(hash, longUrl));
        return "http://tinyurl.com/" + hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string hash;
        if(0 == shortUrl.find("http://tinyurl.com/")) {
            hash = shortUrl.substr(19, 7);
            unordered_map<string, string>::const_iterator it = tinyMap.find(hash);
            if(it != tinyMap.end()) {
                return it->second;
            }
        }
        return "";
    }

private:
    const std::array<char, 35> hashChars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    unordered_map<string, string> tinyMap;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
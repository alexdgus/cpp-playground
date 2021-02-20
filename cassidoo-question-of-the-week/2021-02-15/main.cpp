#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

void findSentences(std::vector<std::string> &sentences, std::string prefix, std::string remainder, std::unordered_set<std::string> &dict) {
    for(size_t i = 0; i < remainder.size(); i++) {
        if(dict.count(remainder.substr(0, i))) {
            findSentences(sentences, prefix + remainder.substr(0,i) + " ", remainder.substr(i, remainder.size() - 1), dict);
        }
    }
    if(dict.count(remainder)) {
        sentences.push_back(prefix + " " + remainder);
    }
}

std::vector<std::string> makeSentence(std::string str, std::unordered_set<std::string> &dict) {
    std::vector<std::string> sentences;
    findSentences(sentences, "", str, dict);
    return sentences;
}

int main(int argc, char *argv[]) {
    std::string str = "penpineapplepenapple";
    std::unordered_set<std::string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    std::vector<std::string> sentences = makeSentence(str, dict);
    for(auto &s : sentences) {
        std::cout << s << "\n";
    }
    return 0;
}
/* Given a string str containing only the characters x and y, change it into a
 * string such that there are no matching adjacent characters. You’re allowed to
 * delete zero or more characters in the string. Find the minimum number of
 * required deletions. */

#include <iostream>
#include <string>

int everyOther(std::string str) {
    char cur;
    int deleted = 0;
    if(str.size() > 0) { cur = str[0]; }

    for(int i = 1; i < str.size(); i++) {
        if(str[i] == cur) {
            deleted++;
        } else {
            cur = str[i];
        }
    }
    return deleted;
}


int main(int argc, char* argv[]) {
    std::string test1 = "xxyxxy";
    int t1 = everyOther(test1);
    std::cout << "Test 1: " << t1 << "\n";
    std::string test2 = "yyyyy";
    int t2 = everyOther(test2);
    std::cout << "Test 2: " << t2 << "\n";
    std::string test3 = "yxyxyxyxxxxyyyyxyxyxyxyxyxyyyyxyxxxyyxyxyxyyxyxxyxyxyyxyxyxyxyxxyy";
    int t3 = everyOther(test3);
    std::cout << "Test 3: " << t3 << "\n";
}
#ifndef __SRC_01451_REARRAGE_WORDS_IN_A_SENTENCE_H
#define __SRC_01451_REARRAGE_WORDS_IN_A_SENTENCE_H

#include <string>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        if (text.empty()) return "";
    
        text.front() = text.front() - 'A' + 'a';
        
        auto myLess = [](const string & s1, const string & s2) {
            if (s1.size() < s2.size()) return true;
            //else if (s1.size() == s2.size()) return true;
            else return false;
        };
        multiset<string, decltype(myLess)> words(myLess);
        
        istringstream iss(text);
        
        for (string word{""}; iss >> word; ) words.insert(word);
                
        string res{""};
        for (const auto & word : words) res.append(word).append(" ");
    
        if (res.front() - 'a' >= 0)
            res.front() = res.front() -'a' + 'A';
        
        return res.substr(0, res.size()-1);
              
    }
};

#endif
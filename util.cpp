#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<std::string> allWords;
    std::string currWord;
    rawWords = convToLower(rawWords);

    for(size_t i = 0; i < rawWords.length(); i++) {
        //check for punctuation first 
        if(ispunct(rawWords[i])) {
            //split into two words from the punctuation
            std::string first = rawWords.substr(0, i);
            std::string second = rawWords.substr(i + 1);

            //compare sizes of the two and select the bigger one
            if(first.length() <= second.length()) currWord = second.substr(0, second.find_first_of(' ')); //split by spaces for the word
            else currWord = first.substr(first.find_last_of(' ') + 1);

            if(!currWord.empty()) allWords.insert(currWord);

            currWord.clear();
        }
        //check for spaces
        else if(isspace(rawWords[i])) {
            if(!currWord.empty()) {
                allWords.insert(currWord);
            }
            currWord.clear();
        } else {
            //no spaces or punctuation
            currWord = currWord + rawWords[i];
        }
    }

    return allWords;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

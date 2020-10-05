#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

bool is_ignore(char c) { return (!((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))); }
bool is_upper(char c) { return (c > 'A' && c < 'Z'); }

std::string preprocess(std::string w)
{
    std::string ignore_special, ignore_case;

    std::copy_if(
        w.begin(),
        w.end(),
        std::back_inserter(ignore_special),
        [](char c) { return !is_ignore(c); });

    std::transform(
        ignore_special.begin(),
        ignore_special.end(),
        std::back_inserter(ignore_case),
        [](char c) { return is_upper(c) ? (c - 'A' + 'a') : c; });

    return ignore_case;
}

bool anagram(std::string word1, std::string word2)
{
    std::string w1 = preprocess(word1), w2 = preprocess(word2);

    if (w1.size() != w2.size())
        return false;

    for (char c1 : w1)
    {
        bool found = false;

        for (char c2 : w2)
        {
            if (c1 == c2)
                found = true;
        }

        if (found == false)
            return false;
    }

    return true;
}

int main()
{
    std::cout << "friend is anagram of friend? " << (anagram("friend", "friend") ? "yes" : "no") << std::endl;
    std::cout << "friend is anagram of finder? " << (anagram("friend", "finder") ? "yes" : "no") << std::endl;
    std::cout << "finder is anagram of friend? " << (anagram("finder", "friend") ? "yes" : "no") << std::endl;
    std::cout << "finder# is anagram of friend*? " << (anagram("finder#", "friend*") ? "yes" : "no") << std::endl;
    std::cout << "finDEr# is anagram of fRienD*? " << (anagram("finDEr#", "fRienD*") ? "yes" : "no") << std::endl;

    std::cout << "house is anagram of white? " << (anagram("house", "white") ? "yes" : "no") << std::endl;
    return 0;
}
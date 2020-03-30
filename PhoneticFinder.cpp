#include "PhoneticFinder.hpp"

#include <iostream>

using namespace std;


char replace(char x)
{
    x = tolower(x);
    if (x=='v' || x=='w')
    {
        return 'v';
    }
    else if (x=='b' || x=='f' || x=='p')
    {
        return 'b';
    }
    else if (x=='g' || x=='j')
    {
        return 'g';
    }
    else if (x=='c' || x=='k' || x=='q')
    {
        return 'c';
    }
    else if (x=='s' || x=='z')
    {
        return 's';
    }
    else if (x=='d' || x=='t')
    {
        return 'd';
    }
    else if (x=='o' || x=='u')
    {
        return 'o';
    }
    else if (x=='i' || x=='y')
    {
        return 'i';
    }
    else
    {
        return x;
    }
}

string phonetic::find(string sentence ,string word)
{
    int i, j;
    bool issame;
    string this_word;
    for (j=0;j<sentence.length();j++)
    {
        if (sentence[j] == ' ' || sentence.length() == j + 1)
        {
            if ((sentence.length() == j + 1) && (sentence[j] != ' ')) {
                this_word = this_word + sentence[j];
            }
            if (word.length() == this_word.length())
            {
                issame = true;
                for (i=0;i<word.length();i++)
                {
                    if (replace(word[i]) != replace(this_word[i]))
                    {
                        issame = false;
                        break;
                    }
                }
                if (issame)
                {
                    return this_word;
                }
            }
            this_word = "";
        }
        else
        {
            this_word = this_word + sentence[j];
        }
    }
    throw std::exception();
}

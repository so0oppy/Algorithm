#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> mp;

int dictionary(int index, string currentWord, string target)
{
    if(currentWord == target)
        return index;
    
    if(currentWord.length() < 5)
    {
        currentWord += "A";
    }
    else
    {
        int i = 4;
        while(true)
        {
            if(currentWord[i] == 'U')
            {
                currentWord = currentWord.substr(0, i);
                i--;
                continue;
            }
            else
            {
                currentWord[i] = mp[currentWord[i]];
                break;
            }
        }
    }
    
    return dictionary(index+1, currentWord, target);
}

int solution(string word) {
    int index = 0;
    
    mp['A'] = 'E';
    mp['E'] = 'I';
    mp['I'] = 'O';
    mp['O'] = 'U';
    
    return dictionary(index+1, "A", word);
}
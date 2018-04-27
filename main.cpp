#include <algorithm> // reverse
#include <cctype> // isalpha
#include <iostream>
#include <string>

using namespace std;

void reverseWords(string& line){
    string::iterator left = line.begin();
    string::iterator right;

    while (left != line.end()){
        // ignore all leading non alpha
        while(!isalpha(*left) && left != line.end())
            ++left;
        if (left == line.end())
            break;
        // left points to the beginning of first word
        right = left + 1;

        // advance right iterator to the end of the word
        while(isalpha(*right) || *right == '-')
            ++right;

        // reverse elements using iterators
        reverse(left, right);

        // advance left to the end of previous word
        left = right;
    }
}

int main()
{
    cout << "Input line to reverse all words: ";
    string line;
    getline(cin, line);

    reverseWords(line);

    cout << "All words reversed is          : ";
    cout << line << endl;
    return 0;
}

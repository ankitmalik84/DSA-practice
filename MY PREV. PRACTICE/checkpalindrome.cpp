#include <iostream>
using namespace std;
bool checkPalindrome(string &str, int i, int j)
{
    // base case
    if (i > j)
        return true;

    if (str[i] != str[j])
    {
        return false;
    }
    i++;
    j--;
    // recursion call
    checkPalindrome(str, i, j);
}

int main()
{
    string name;
    cout << "Enter the String" << endl;
    // getline(cin, name);    another method of input string because cin not take value after space
    cin >> name;
    bool n = checkPalindrome(name, 0, name.length() - 1);
    if (n)
        cout << "Your String is palindrome";
    else
        cout << "Your String is not palindrome";
    return 0;
}
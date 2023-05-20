#include <iostream>
using namespace std;
void reverse(string &str, int i, int j)
{
    // base case
    if (i > j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;

    // recursion call
    reverse(str, i, j);
}

int main()
{
    string name;
    cout << "Enter the string" << endl;
    // getline(cin, name);    another method of input string because cin not take value after space
    cin >> name;
    reverse(name, 0, name.length() - 1);
    cout << "Your reverse String is :- " << name;
    return 0;
}
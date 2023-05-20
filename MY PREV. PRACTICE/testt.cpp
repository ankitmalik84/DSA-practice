#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // create an array to represent the state of each bulb
    bool bulbs[n] = {false};

    // iterate through each fluctuation in voltage
    for (int i = 1; i <= n; i++)
    {
        // toggle the state of every i-th bulb
        for (int j = i - 1; j < n; j += i)
        {
            bulbs[j] = !bulbs[j];
        }
    }

    // print the index of every bulb that is switched on
    for (int i = 0; i < n; i++)
    {
        if (sqrt(i + 1) == (int)sqrt(i + 1) && bulbs[i])
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}

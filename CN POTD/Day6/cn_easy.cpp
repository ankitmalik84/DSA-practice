#include <bits/stdc++.h>
string findShortestRoute(string &str)
{
    int x = 0, y = 0; // Initial position at origin
    for (char direction : str)
    {
        if (direction == 'E')
        {
            x++;
        }
        else if (direction == 'W')
        {
            x--;
        }
        else if (direction == 'N')
        {
            y++;
        }
        else if (direction == 'S')
        {
            y--;
        }
    }

    // Generate the shortest route back to the origin
    string shortestRoute;
    if (x > 0)
    {
        shortestRoute += string(x, 'E');
    }
    if (y > 0)
    {
        shortestRoute += string(y, 'N');
    }
    if (y < 0)
    {
        shortestRoute += string(-y, 'S');
    }
    if (x < 0)
    {
        shortestRoute += string(-x, 'W');
    }

    return shortestRoute;
}
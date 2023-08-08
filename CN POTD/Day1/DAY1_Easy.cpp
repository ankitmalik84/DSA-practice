bool reachDestination(int sx, int sy, int dx, int dy)
{
    // Write your code here
    while (dx >= sx && dy >= sy)
    {
        if (dx == sx && dy == sy)
        {
            return true;
        }
        if (dx > dy)
        {
            dx -= dy;
        }
        else
        {
            dy -= dx;
        }
    }

    return false;
}
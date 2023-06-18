// ==================================================== CODE INFINITY ===============================================================

// Ticket Counter
// EasyAccuracy: 55.31%Submissions: 20K+Points: 2
// N people from 1 to N are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

// Example 1

// Input:
// N = 9
// K = 3
// Output:
// 6
// Explanation:
// Starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}. After the first distribution queue will look like {4, 5, 6, 7, 8, 9}. And after the second distribution queue will look like {4, 5, 6}. The last person to get the ticket will be 6.
// Example 2

// Input:
// N = 5
// K = 1
// Output:
// 3
// Explanation:
// Queue start as {1, 2, 3, 4, 5} -> {2, 3, 4, 5} -> {2, 3, 4} -> {3, 4} -> {3}
// Last person to get ticket will be 3.

// =======================APPROACH===================>>>>>>>>>>

// Divide N by K and round up to count the amount of segments the queue can be divided into(any segment smaller than K people is still counted as one)
//         Fork into two paths by applying the modulo of 2(even / uneven)
//         operator to the number of segments
//     If there is an uneven number of segments count from the back of the queue the amount of people that fit inside half the number of segments(rounded down by integer division)
//         Else If there is an even number of segments count from the front instead(+1 to avoid OB1 error)
//             This works since half the number of segments are in front of the middle segment while the other half is behind the middle segment.If the queue has an uneven number of segments the middle segment is evaluated front
//     - to - back,
//     so the last person in the queue is the last person in the middle segment.If the queue has an even number of segments the middle segment is evaluated back - to - front, so the last person in the queue is the first person in the middle segment.

// .
// ================= CODE ==================>>>>>>>
// .

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeTicket(int N, int K)
    {
        int segments = ceil((float)N / K);
        if (segments % 2 == 1)
        {
            return N - segments / 2 * K;
        }
        else
        {
            return segments / 2 * K + 1;
        }
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        Solution obj;
        int res = obj.distributeTicket(N, K);

        cout << res << endl;
    }
}

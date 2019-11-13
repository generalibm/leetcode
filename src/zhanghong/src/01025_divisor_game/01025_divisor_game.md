## 1025. Divisor Game[Easy]

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `N` on the chalkboard.  On each player's turn, that player makes a *move* consisting of:

-   Choosing any `x` with `0 < x < N` and `N % x == 0`.
-   Replacing the number `N` on the chalkboard with `N - x`.

Also, if a player cannot make a move, they lose the game.

Return `True` if and only if Alice wins the game, assuming both players play optimally.

 

 

**Example 1:**

```
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
```

**Example 2:**

```
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
```

 

**Note:**

1.  `1 <= N <= 1000`

### Solution Analysis

**Math approach**

-   Time: O(1)
-   Space: O(1)
-   Result: AC
>1.  If Alice will lose for `N`, then Alice will must win for `N+1,` since Alice an first just make `N` decrease 1.
>
>2.  for any odd number `N`, it only has odd factor, so after the first move, it will be an even number. Bob will win.
>3.  for any even number `N`, Alice will win.

```c++
class Solution {
public:
    bool divisorGame(int N) {
        return 0 == N % 2;
    }
};
```



**Dynamic programming approach**

-   Time: O(n)
-   Space: O(n^2)
-   Result: AC
>`dp[i]` indicates the result of the game for the given number `i` and for the player who started the game.
>
>Alice will try all factors and choose the one which gives her opponent a losing value.

-   Code sample

```c++
class Solution {
public:
    bool divisorGame(int N) {
        if (N < 2) return false;
        
        std::vector<bool> dp = {false, false};
        dp.resize(N+1);
        
        for (int i = 2; i <= N; i++)
            for (int j = 1; j * j < i; j++)
            {
                if (0 == i % j && dp.at(i-j) == false)
                {
                    dp.at(i) = true;
                    break;
                }
            }

        return dp.back();
    }
};
```


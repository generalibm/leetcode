## 703. Kth Largest Element in a Stream[Easy]

Design a class to find the **k**th largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your `KthLargest` class will have a constructor which accepts an integer `k` and an integer array `nums`, which contains initial elements from the stream. For each call to the method `KthLargest.add`, return the element representing the kth largest element in the stream.

**Example:**

```
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
```

**Note:** 
 You may assume that `nums`' length ≥ `k-1` and `k` ≥ 1.



### Solution Analysis

**Approach 1**: Priority Queue

It is quite easy to get the largest element in a P.Q. , it is `K*O(1)` to get the Kth largest element. But in a stream, every time you add a new element, it would cost `O(logN)`and spend another `O(logN)` in keeping order(when you get the Kth largest elements, they would not in the P.Q. , you should add them into the P.Q. again to keep the whole P.Q. order globally), so the total time complex is `O(K*(logN)^2)`. When the K was big enough, the efficiency might very low.

-   Time: `O(K*(logN)^2)`

-   Space: `O(N)`
-   Result: `TLE`
-   Code sample:

```c++
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : _k(k), _q() {
        for (auto e : nums)
            _q.push(e);
    }
    
    int add(int val) {
        _q.push(val);
        
        if (_q.size() < _k) return 0;
        
        vector<int> tmp;            
        int i = _k;
        while (--i)
        {
            tmp.push_back(_q.top()); _q.pop();
        }
        
        int res = _q.top();
        for (auto e : tmp) _q.push(e);
        return res;
    }
private:
    int _k;
    priority_queue<int> _q;
};
```



**Approach 2**: 2-ways P.Q.

In approach 1, when K is big enough, the time complexity would be extended. Unfortunately, we can not decrease `K`, but we could avoid another `O(logN)` in keeping the global order in a stream so long as we using a small P.Q. to track the K largest elements and a big P.Q. to keep the stream.

Every time, a new element is added, we just need to pick up the biggest element in the big P.Q.(called `bigPeek`) in `O(1)` and add it into the small P.Q.(if the top of it, called `smallPeek`,is smaller, then drop `smallPeek` and add `bigPeek` into the small P.Q.), which is `O((logN)/K)`. In this way, the time complex would be `O(K(logN)* (logN)/K) = O((logN)^2)` . Eventually, this actually dismiss the `K`.

-   Time: `O((logN)^2)`
-   Space: `O(K+N)`
-   Result: `AC`
-   Code sample:

```c++
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : _k(k), _Bq(), _Sq() 
    {
        for (auto e : nums)
            _Bq.push(e);
        
        int len = min((int)_Bq.size(), (int)_k);
        for (int i = 0; i < len; i++)
        {
            _Sq.push(_Bq.top());
            _Bq.pop();
        }
    }
    
    int add(int val) {
        _Bq.push(val);
        
        int bigPeek = _Bq.top(); _Bq.pop();
        
        if (_Sq.size() < _k)
        {
            _Sq.push(bigPeek);
        }
        else
        {
            if (_Sq.top() < bigPeek)
            {
                _Sq.pop();
                _Sq.push(bigPeek);
            }
        }        
        
        if (_Sq.size() < _k) return -1;
        else return _Sq.top();       
    }
private:
    int _k;    
    priority_queue<int> _Bq;
    priority_queue<int, vector<int>, greater<int>> _Sq;
};
```


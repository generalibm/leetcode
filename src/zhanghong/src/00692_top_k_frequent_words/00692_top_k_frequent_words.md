## f692. Top K Frequent Words[Medium]

- Given a non-empty list of words, return the k most frequent elements.

- Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

**Example 1:**
- Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
- Output: ["i", "love"]
- Explanation: "i" and "love" are the two most frequent words. Note that "i" comes before "love" due to a lower alphabetical order.

**Example 2:**
- Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
- Output: ["the", "is", "sunny", "day"]
- Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

***Note:***
- You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
- Input words contain only lowercase letters.
**Follow up:**
Try to solve it in O(n log k) time and O(n) extra space.

## Solution Analysis
### approach 1 - AC, O(NlogN) time complexity
```c++
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> recds;
    for (const string & word : words) recds[word]++;

    /// Big heap
    /// stores keys in a order that are expected
    auto comp = [](const pair<int, string> & l, const pair<int, string> & r){
        if (l.first == r.first) return l.second > r.second;
        else return l.first < r.first;
    };

    /// O(NlogN)
    priority_queue<pair<int, string>,vector<pair<int, string>>, decltype(comp)> q(comp);
    for (const auto & recd : recds) q.push({recd.second, recd.first});

    /// O(KlogN)
    vector<string> res;
    while (k--) { res.push(q.top().second); q.pop()}

    return res;  
}
```


### approach 2 - AC, O(NlogK) time complexity
```c++
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> recds;
    for (const string & word : words) recds[word]++;

    /// Small heap
    /// stores keys in a order that are not expected
    auto comp = [](const pair<int, string> & l, const pair<int, string> & r){
        if (l.first == r.first) return l.second < r.second;
        else return l.first > r.first;
    };

    /// O(NlogK)
    priority_queue<pair<int, string>,vector<pair<int, string>>, decltype(comp)> q(comp);
    for (const auto & recd : recds) 
    {            
        q.push({recd.second, recd.first});
        if (q.size() > k) q.pop();/// In which the poped elements are not desired
    }
	
    /// O(KlogK)
    vector<string> res(k);
    int i = k-1;
    while (!q.empty())             
    {
        res[i] = q.top().second;
        q.pop();
        i--;
    }

    return res;  
}
```
# leetcode

leetcode online practice, which is a algorithm  design routine that could help developers to build potentialities and  improve productivities, will push developers to devote themselves to deal with quizzes every day.

### How to join

- find the right location

  Your workspace may locate in `leetcode/src/username/`(if it does not exist, you should create yours on your own), there are three directories there(`data`,`src`, `test`), you are now expected to write your code and your unit test in the `src` dir with a specific name. (`leetcode/src/zhanghong/src/echo` would show the files you should create then.)

- write your header file

  - using `SRC_USERNAME_SRC_XXX_H_` include guider please
  - keep `Solution` be all your class name 
  - pre declaration should be here

- write your implementation file

  - function implementation here
  - you could keep multiple version(with or without third-party libs)

- write your unit test file

  - you should handle the input and the output now
  - you should prepare all the parameters for you `Solution` member function here
  - sample in `leetcode/src/zhanghong/src/echo/echo_test.cc` will how to write a proper test file

- run all your test

  When you have done all your code jobs, you may use the following commands to run your unit tests.

  - compile them by `g++ xxx_test.cc xxx.cc -I./ -I/usr/local/include/ -o main -lgtest -lgtest_main -lpthread -g`
  - execute it by `/main`
  - you will see whether all your test passed or you might check your implementation file

- upload your code to *git ropository*

  - tool kits, like *sourceTree* / *gitKraken*, are highly recommended
  - you should only do your all coding job **in your own branch**(such as `dev`)
  - you should `@someone` for `peer review/code review`

- hope you enjoy it

### Join Sample
- create a **code directory** in your working path(`src/username/`), which looks like `00004_median_of_two_sorted_arrays`

- create a **Markdown file** to record the problem's descriptions in the above directory, such as `00004_median_of_two_sorted_arrays.md`

- create your **test code file**, such as `00004_median_of_two_sorted_arrays_test.cc`; it may look like the following:

  ```c++
  #include "gtest/gtest.h"
  
  #include <vector>
  
  using namespace std；
  
  class Solution {
   public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
      {
          return 2.0;
      }
  };
  
  TEST(SolutionTest, ExampleTest1)
  {
      Solution sol;
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  ```

  then, compile it with `g++00004_median_of_two_sorted_arrays_test.cc -lgtest -lgtest_main -lpthread -std=c++11` and run it with `./a.out`, which will generate **googletest framework** output message, like the following:

  ```bash
  Running main() from gtest_main.cc
  [==========] Running 1 test from 1 test case.
  [----------] Global test environment set-up.
  [----------] 1 test from SolutionTest
  [ RUN      ] SolutionTest.ExampleTest1
  [       OK ] SolutionTest.ExampleTest1 (0 ms)
  [----------] 1 test from SolutionTest (0 ms total)
  
  [----------] Global test environment tear-down
  [==========] 1 test from 1 test case ran. (0 ms total)
  [  PASSED  ] 1 test.
  ```

  it works now. BUT, that is not the solution of the real problem. Let add the 2nd example test case.

  ```c++
  #include "gtest/gtest.h"
  
  #include <vector>
  
  using namespace std；
  
  class Solution {
   public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
      {
          return 2.0;
      }
  };
  
  TEST(SolutionTest, ExampleTest1)
  {
      Solution sol;
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  
  TEST(SolutionTest, ExampleTest)
  {
      Solution sol;
      EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
  }
  ```

  compile it and run again, it actually will fail at the 2nd test. Obviously because of algorithm's logic(it did nothing just returns `2.0`). BUT, before thinking about it, we need to refactoring with test fixture to fix code bad smell since we will need more test cases in the future, which means there will be multiple copies of code snips like ` Solution sol;` and it call constructor and destructor every time that will cause performance problems. So, do it now:

  ```c++
  #include "gtest/gtest.h"
  
  #include <vector>
  
  using namespace std；
  
  class Solution {
  public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
      {
          return 2.0;
      }
  };
  
  class SolutionTest : public ::testing::Test {
  protected:
      Solution sol;   
  };
  
  TEST_F(SolutionTest, ExampleTest1)
  {
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  
  TEST_F(SolutionTest, ExampleTest2)
  {
      EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
  }
  ```

  it is easy -- let `SolutionTest` inherit from `::testing::Test` and the declare an instance of Solution class then update function signature  from `TEST`  to `TEST_F`, `F` here means `fixture`. 

  let us now consider about algorithm's logic. 

  a brute impulse is sort the two sorted vector with a bigger one in O(m+n) by **merge sort** algorithm, and then return the median in O(1). 

  ```c++
  #include "gtest/gtest.h"
  
  #include <vector>
  
  using namespace std；
  
  class Solution {
  public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
      {
  		const vector<int> res = mergeSort(nums1, nums2);
  		
  		double median = res.size() % 2 != 0 ？(double)res.at(res.size()/2) : (res.at(res.size()/2)+res.at(res.size()/2 - 1))/2.0;
      	return median;
      }
  private:
      vector<int> mergeSort(const vector<int>& nums1, const vector<int>& nums2)
      {
          /// assert nums1 and nums2 are sorted and not empty
          vector<int> res(nums1.size() + nums2.size());
          int i = 0, j = 0, k = 0;
          while (i < nums1.size() && j < nums2.size())
          {
              if (nums1[i] < nums2[j])
                  res[k++] = nums1[i++];
              else
                  res[k++] = nums2[j++];
          }
          while (i < nums1.size())
              res[k++] = nums1[i++];
          while (j < nums2.size())
              res[k++] = nums2[j++];
          
          return res;        
      }
  };
  
  class SolutionTest : public ::testing::Test {
  protected:
      Solution sol;    
  };
  
  TEST_F(SolutionTest, ExampleTest1)
  {
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  
  TEST_F(SolutionTest, ExampleTest2)
  {
      EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
  }
  ```

  Oh, we should refactoring it into multiple files:

  ```c++
  /// 00004_median_of_two_sorted_arrays_test.cc
  #include "gtest/gtest.h"
  
  #include "00004_median_of_two_sorted_arrays.h"
  
  class SolutionTest : public ::testing::Test {
  protected:
      Solution sol;    
  };
  
  TEST_F(SolutionTest, ExampleTest1)
  {
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  
  TEST_F(SolutionTest, ExampleTest2)
  {
      EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
  }
  ```

  ```c++
  /// 00004_median_of_two_sorted_arrays.h
  #include <vector>
  
  using namespace std；
  
  class Solution {
  public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2);    
  private:
      vector<int> mergeSort(const vector<int>& nums1, const vector<int>& nums2);   
  };
  ```

  ```c++
  /// 00004_median_of_two_sorted_arrays.cc
  #include "00004_median_of_two_sorted_arrays.h"
  
  double Solution::findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
  {
  	const vector<int> res = mergeSort(nums1, nums2);
  
  	double median = res.size() % 2 != 0 ？(double)res.at(res.size()/2) :   (res.at(res.size()/2)+res.at(res.size()/2 - 1))/2.0;
  	return median;
  }
  
  vector<int> Solution::mergeSort(const vector<int>& nums1, const vector<int>& nums2)
  {
  /// assert nums1 and nums2 are sorted and not empty
  	vector<int> res(nums1.size() + nums2.size());
  	int i = 0, j = 0, k = 0;
  	while (i < nums1.size() && j < nums2.size())
  	{
  		if (nums1[i] < nums2[j])
  			res[k++] = nums1[i++];
  		else
  			res[k++] = nums2[j++];
  	}
  	while (i < nums1.size())
  		res[k++] = nums1[i++];
  	while (j < nums2.size())
  		res[k++] = nums2[j++];
  
  	return res;        
  }
  
  ```

  Now, compile it with `g++ 00004_median_of_two_sorted_arrays.cc 00004_median_of_two_sorted_arrays_test.cc -I./ -lgtest -lgtest_main -lpthread -std=c++11  `.

  Then it actually will pass the two test cases. BUT when realized that the problem should be solved with **O(log(m+n))**, we would suddenly reach the `binary search` category(the following reasonable text could be put into the *.md file).

  >To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for `dividing a set into two equal length subsets, that one subset is always greater than the other`. If we understand the use of median for dividing, we are very close to the answer.
  >
  > 
  >
  >First let's cut **A** into two parts at a random position **i**:
  >
  > 
  >
  >```python
  >      left_A             |        right_A
  >A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
  >```
  >
  >
  >
  >Since **A** has **m** elements, so there are **m+1** kinds of cutting( **i = 0 ~ m** ). And we know: **len(left_A) = i, len(right_A) = m - i** . Note: when **i = 0** , **left_A** is empty, and when **i = m** , **right_A** is empty.
  >
  > 
  >
  >With the same way, cut **B** into two parts at a random position **j**:
  >
  > 
  >
  >```python
  >      left_B             |        right_B
  >B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
  >```
  >
  >
  >
  >Put **left_A** and **left_B** into one set, and put **right_A** and **right_B** into another set. Let's name them **left_part** and **right_part** :
  >
  > 
  >
  >```python
  >      left_part          |        right_part
  >A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
  >B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
  >```
  >
  >
  >
  >If we can ensure:
  >
  > 
  >
  >```python
  >1) len(left_part) == len(right_part)
  >2) max(left_part) <= min(right_part)
  >```
  >
  >
  >
  >then we divide all elements in **{A, B}** into two parts with equal length, and one part is always greater than the other. Then **median = (max(left_part) + min(right_part))/2**.
  >
  > 
  >
  >To ensure these two conditions, we just need to ensure:
  >
  > 
  >
  >```python
  >(1) i + j == m - i + n - j (or: m - i + n - j + 1)
  >    if n >= m, we just need to set: i = 0 ~ m, j = (m + n + 1)/2 - i
  >(2) B[j-1] <= A[i] and A[i-1] <= B[j]
  >```
  >
  >
  >
  >ps.1 For simplicity, I presume **A[i-1],B[j-1],A[i],B[j]** are always valid even if **i=0/i=m/j=0/j=n** . I will talk about how to deal with these edge values at last.
  >
  > 
  >
  >ps.2 Why n >= m? Because I have to make sure j is non-nagative  since 0 <= i <= m and j = (m + n + 1)/2 - i. If n < m , then j  may be nagative, that will lead to wrong result.
  >
  > 
  >
  >So, all we need to do is:
  >
  > 
  >
  >```python
  >Searching i in [0, m], to find an object `i` that:
  >    B[j-1] <= A[i] and A[i-1] <= B[j], ( where j = (m + n + 1)/2 - i )
  >```
  >
  >
  >
  >And we can do a binary search following steps described below:
  >
  > 
  >
  >```python
  ><1> Set imin = 0, imax = m, then start searching in [imin, imax]
  >
  ><2> Set i = (imin + imax)/2, j = (m + n + 1)/2 - i
  >
  ><3> Now we have len(left_part)==len(right_part). And there are only 3 situations
  >     that we may encounter:
  >    <a> B[j-1] <= A[i] and A[i-1] <= B[j]
  >        Means we have found the object `i`, so stop searching.
  >    <b> B[j-1] > A[i]
  >        Means A[i] is too small. We must `ajust` i to get `B[j-1] <= A[i]`.
  >        Can we `increase` i?
  >            Yes. Because when i is increased, j will be decreased.
  >            So B[j-1] is decreased and A[i] is increased, and `B[j-1] <= A[i]` may
  >            be satisfied.
  >        Can we `decrease` i?
  >            `No!` Because when i is decreased, j will be increased.
  >            So B[j-1] is increased and A[i] is decreased, and B[j-1] <= A[i] will
  >            be never satisfied.
  >        So we must `increase` i. That is, we must ajust the searching range to
  >        [i+1, imax]. So, set imin = i+1, and goto <2>.
  >    <c> A[i-1] > B[j]
  >        Means A[i-1] is too big. And we must `decrease` i to get `A[i-1]<=B[j]`.
  >        That is, we must ajust the searching range to [imin, i-1].
  >        So, set imax = i-1, and goto <2>.
  >```
  >
  >
  >
  >When the object **i** is found, the median is:
  >
  > 
  >
  >```python
  >max(A[i-1], B[j-1]) (when m + n is odd)
  >or (max(A[i-1], B[j-1]) + min(A[i], B[j]))/2 (when m + n is even)
  >```
  >
  >
  >
  >Now let's consider the edges values **i=0,i=m,j=0,j=n** where **A[i-1],B[j-1],A[i],B[j]** may not exist. Actually this situation is easier than you think.
  >
  > 
  >
  >What we need to do is ensuring that `max(left_part) <= min(right_part)`. So, if **i** and **j** are not edges values(means **A[i-1],B[j-1],A[i],B[j]** all exist), then we must check both **B[j-1] <= A[i]** and **A[i-1] <= B[j]**. But if some of **A[i-1],B[j-1],A[i],B[j]** don't exist, then we don't need to check one(or both) of these two conditions. For example, if **i=0**, then **A[i-1]** doesn't exist, then we don't need to check **A[i-1] <= B[j]**. So, what we need to do is:
  >
  > 
  >
  >```python
  >Searching i in [0, m], to find an object `i` that:
  >    (j == 0 or i == m or B[j-1] <= A[i]) and
  >    (i == 0 or j == n or A[i-1] <= B[j])
  >    where j = (m + n + 1)/2 - i
  >```
  >
  >
  >
  >And in a searching loop, we will encounter only three situations:
  >
  > 
  >
  >```python
  ><a> (j == 0 or i == m or B[j-1] <= A[i]) and
  >    (i == 0 or j = n or A[i-1] <= B[j])
  >    Means i is perfect, we can stop searching.
  >
  ><b> j > 0 and i < m and B[j - 1] > A[i]
  >    Means i is too small, we must increase it.
  >
  ><c> i > 0 and j < n and A[i - 1] > B[j]
  >    Means i is too big, we must decrease it.
  >```
  >
  >
  >
  >Note that `i < m ==> j > 0` and `i > 0 ==> j < n` . Because:
  >
  > 
  >
  >```python
  >m <= n, i < m ==> j = (m+n+1)/2 - i > (m+n+1)/2 - m >= (2*m+1)/2 - m >= 0    
  >m <= n, i > 0 ==> j = (m+n+1)/2 - i < (m+n+1)/2 <= (2*n+1)/2 <= n
  >```
  >
  >
  >
  >So in situation <b> and <c>, we don't need to check whether `j > 0` and whether `j < n`.

  the following is O(log(m+n)) solution:

  ```c++
  /// 00004_median_of_two_sorted_arrays.h
  #include <vector>
  
  using namespace std；
  
  class Solution {
  public:
      double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2);    
  private:
      double findMedian(const vector<int>& longArray, const vector<int> & shortArray, bool isEven);     
  };
  ```

  Then implementation could be:

  ```c++
  /// 00004_median_of_two_sorted_arrays.cc
  #include "00004_median_of_two_sorted_arrays.h"
  
  double Solution::findMedianSortedArrays(const vector<int> & nums1, const vector<int> & nums2) 
  {
      // assert nums1 and nums2 are not empty
      int m = nums1.size();
      int n = nums2.size();
      bool isEven = ((m+n)%2 == 0);
      if(m > n)
          return findMedian(nums1,nums2,isEven);
      else
          return findMedian(nums2,nums1,isEven);
  }
  
  double Solution::findMedian(const vector<int>& longArray, const vector<int> & shortArray, bool isEven)
  {
      // shortArray is A, A's length is m
      // longArray is B , B's length is n
      int m = shortArray.size();
      int n = longArray.size();
      int imin = 0;
      int imax = m;
      double left_max;
      double right_min;
      while(imin <= imax){
          int i = (imin + imax)/2;
          int j = (m + n)/2 - i;
          // if i<m and m < n, then we can calculate j>0
          // if i>0 and m < n, then we can calculate j<n
          if(i<m && longArray[j-1] > shortArray[i])  imin = i+1;
          else if (i>0 && shortArray[i-1] > longArray[j]) imax = i-1;
          else{
              //here, if isEven : median = (max(A[i-1],B[j-1]) + min(A[i],B[i])) / 2
              //      else      : median = min(A[i],B[j])
              //however, i,j maybe equal 0,0 or m,n
              //so, we need to classify them
              if(i==m)        right_min = longArray[j]; 
              else if(j==n)   right_min = shortArray[i];
              else            right_min = std::min(shortArray[i],longArray[j]);//c++14
  
              if(!isEven)     return right_min;
  
              if(i==0)        left_max = longArray[j-1];
              else if(j==0)   left_max = shortArray[i-1];
              else            left_max = std::max(shortArray[i-1],longArray[j-1]);//c++14 
  
              return (right_min + left_max) / 2.0;
          }
      }
      return 0.0;
  }
  
  ```

  notice that `std::min()` is just support in after `c++14` not `c++11` , so we should compile the code using `g++ 00004_median_of_two_sorted_arrays_test.cc 00004_median_of_two_sorted_arrays.cc -I./ -lgtest -lgtest_main -lpthread -std=c++14` and run it `./a.out`, now we can see what **googletest framework** tells us. May it be 

  ```bash
  Running main() from gtest_main.cc
  [==========] Running 2 tests from 1 test case.
  [----------] Global test environment set-up.
  [----------] 2 tests from SolutionTest
  [ RUN      ] SolutionTest.ExampleTest1
  [       OK ] SolutionTest.ExampleTest1 (0 ms)
  [ RUN      ] SolutionTest.ExampleTest2
  [       OK ] SolutionTest.ExampleTest2 (0 ms)
  [----------] 2 tests from SolutionTest (0 ms total)
  
  [----------] Global test environment tear-down
  [==========] 2 tests from 1 test case ran. (0 ms total)
  [  PASSED  ] 2 tests.
  ```

  Now, we can write another test cases for the boundary testing.

  ```c++
  /// 00004_median_of_two_sorted_arrays_test.cc
  
  #include "gtest/gtest.h"
  
  #include "00004_median_of_two_sorted_arrays.h"
  
  class SolutionTest : public ::testing::Test {
  protected:
      Solution sol; 
  };
  
  TEST_F(SolutionTest, ExampleTest1)
  {
      EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
  }
  
  TEST_F(SolutionTest, ExampleTest2)
  {
      EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
  }
  
  TEST_F(SolutionTest, OneEmptyTest)
  {
      EXPECT_EQ(3.5, sol.findMedianSortedArrays({}, {3, 4}));
  }
  
  TEST_F(SolutionTest, AllElemLessThanOtherTest)
  {
      EXPECT_EQ(3.0, sol.findMedianSortedArrays({1, 2, 3}, {4, 5}));
  }
  ```

  And check whether all of these could be passed.


### Upload code & commit format

You are recommend to use git tool(like *sourceTree*, *gitKraken*, etc) to track and to deploy your code. But here , you should follow the **team commit format**.

For instance:

```bash
[ADD] Add leetcode 72, edit distance, Hard, AC, O(n^2), O(n^2)
[MOD] mod leetcode 72, add dynamic programming approach, AC, optimized time complexity to O(n)
```



### Write and run/debug codes with VScode

You would perhaps want to write your code with IDE, here VScode can be a alternative. 

Step1: add a workspace folder into the VScode, for example, choose `00733_flood_fill`

Step2: build your coding files in the above folder, for example `clang++ -std=c++17 -lgtest -lgtest_main -g *.cc`

Step2: configure the launch json file like this

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb"
        }
    ]
}
```

then, you can debug your codes with `F5`.

### Write and run/debug codes with Eclipse
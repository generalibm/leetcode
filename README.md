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

- run all your test

  When you have done all your code jobs, you may use the following commands to run your unit tests.

  - compile them by `g++ xxx_test.cc -o main -lgtest_main -lpthread`
  - execute it by `/main`
  - you will see whether all your test all passed or you should check your implementation file

- upload your code to `gitlab`

  - tool kits, like`sourceTree`, are highly recommended
  - you should only do your  all job **in your own branch**
  - you should `@someone` for `peer review/code review`

- hope you enjoy it
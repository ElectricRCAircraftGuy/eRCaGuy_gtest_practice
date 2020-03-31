/*
Testing some of @luantkow's tests in his answer here: 
https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object/44035118#44035118
*/

#include "gmock_test3.h"

using namespace ::testing;

TEST(Examples, InSequenceExample)
{
    SomeMock mock;

    Sequence seq;

    EXPECT_CALL(mock, foo(4)).Times(1).InSequence(seq); //exp#1
    EXPECT_CALL(mock, foo(4)).Times(1).InSequence(seq); //exp#2

    mock.foo(4); // call#1
    mock.foo(4); // call#2
}

TEST(Examples, InSequenceExampleSecondApproach)
{
    SomeMock mock;

    InSequence seq;

    EXPECT_CALL(mock, foo(4)).Times(1); //exp#1
    EXPECT_CALL(mock, foo(4)).Times(1); //exp#2

    mock.foo(4); // call#1
    mock.foo(4); // call#2
}

TEST(Examples, RetiresOnSaturationExample)
{
    SomeMock mock;

    EXPECT_CALL(mock, foo(4)).Times(1); //exp#1
    EXPECT_CALL(mock, foo(4)).Times(1).RetiresOnSaturation(); //exp#2

    mock.foo(4); // call#1
    mock.foo(4); // call#2
}

TEST(Examples, AfterExample)
{
    SomeMock mock;

    auto& exp1 = EXPECT_CALL(mock, foo(4)).Times(1); //exp#1
    EXPECT_CALL(mock, foo(4)).Times(1).After(exp1); //exp#2

    mock.foo(4); // call#1
    mock.foo(4); // call#2
}

/*
SAMPLE OUTPUT:

$ time bazel test --test_output=all --test_arg=--gtest_color=yes //:gmock_test3
INFO: Analyzed target //:gmock_test3 (0 packages loaded, 0 targets configured).
INFO: Found 1 test target...
Target //:gmock_test3 up-to-date:
  bazel-bin/gmock_test3
INFO: Elapsed time: 0.278s, Critical Path: 0.01s
INFO: 0 processes.
INFO: Build completed successfully, 1 total action
PASSED: //:gmock_test3 (see /home/gabriel/.cache/bazel/_bazel_gabriel/0dc09bc4a514eaff2885980178dd3bac/execroot/ercaguy_gtest_practice/bazel-out/k8-fastbuild/testlogs/gmock_test3/test.log)
INFO: From Testing //:gmock_test3
==================== Test output for //:gmock_test3:
Running main() from gmock_main.cc
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from Examples
[ RUN      ] Examples.InSequenceExample
[       OK ] Examples.InSequenceExample (1 ms)
[ RUN      ] Examples.InSequenceExampleSecondApproach
[       OK ] Examples.InSequenceExampleSecondApproach (0 ms)
[ RUN      ] Examples.RetiresOnSaturationExample
[       OK ] Examples.RetiresOnSaturationExample (0 ms)
[ RUN      ] Examples.AfterExample
[       OK ] Examples.AfterExample (0 ms)
[----------] 4 tests from Examples (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 4 tests.
================================================================================
//:gmock_test3                                                  (cached) PASSED in 0.1s

Executed 0 out of 1 test: 1 test passes.
INFO: Build completed successfully, 1 total action

real    0m0.359s
user    0m0.032s
sys 0m0.019s

*/
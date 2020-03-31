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

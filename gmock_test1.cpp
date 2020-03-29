// From: https://gist.github.com/lukant/376df8c49a3aba8179879fadcea77dea

#include "gmock/gmock.h"

using namespace ::testing;

struct SomeMock
{
    MOCK_CONST_METHOD1(foo, void(int));
};

TEST(Examples, TheSameArgumentsGoingToFail)
{
    SomeMock mock;

    EXPECT_CALL(mock, foo(4)).Times(1);
    EXPECT_CALL(mock, foo(4)).Times(1);

    mock.foo(4);
    mock.foo(4);
}

TEST(Examples, theTestWillFailWhenOnlyLastExpectancyWasSatisfied)
{
    SomeMock mock;

    EXPECT_CALL(mock, foo(4)).Times(1);
    EXPECT_CALL(mock, foo(4)).Times(2);

    mock.foo(4);
    mock.foo(4);
}

TEST(Examples, theTestWillFailWhenOnlyLastExpectancyWasSatisfied_theSameCardinality)
{
    SomeMock mock;

    EXPECT_CALL(mock, foo(4)).Times(2);
    EXPECT_CALL(mock, foo(4)).Times(2);

    mock.foo(4);
    mock.foo(4);
}

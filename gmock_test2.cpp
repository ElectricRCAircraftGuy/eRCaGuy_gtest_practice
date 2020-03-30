// Originally from: https://gist.github.com/lukant/376df8c49a3aba8179879fadcea77dea
// I'm playing around in this file a bunch to look at the various error mechanisms and error messages
// produced by them. I now see @lukant's point perfectly and see where he was coming from.

#include "gmock/gmock.h"

using namespace ::testing;

struct SomeMock
{
    MOCK_CONST_METHOD1(foo, void(int));
};

// TEST(Examples, TheSameArgumentsGoingToFail2)
// {
//     SomeMock mock;

//     // EXPECT_CALL(mock, foo(4)).Times(1);
//     // EXPECT_CALL(mock, foo(4)).Times(1);
//     // EXPECT_CALL(mock, foo(4)).Times(1);

//     // EXPECT_CALL(mock, foo(4));
//     EXPECT_CALL(mock, foo(4));

//     mock.foo(4);
//     mock.foo(4);
// }

// TEST(Examples, theTestWillFailWhenOnlyLastExpectancyWasSatisfied2)
// {
//     SomeMock mock;

//     // EXPECT_CALL(mock, foo(4)).Times(1);
//     EXPECT_CALL(mock, foo(4)).Times(2);
//     // EXPECT_CALL(mock, foo(4));

//     mock.foo(4);
//     mock.foo(4);
// }

// Intentionally fails
TEST(Examples, theTestWillFailWhenOnlyLastExpectancyWasSatisfied_theSameCardinality2)
{
    SomeMock mock;

    EXPECT_CALL(mock, foo(4)).Times(2);
    EXPECT_CALL(mock, foo(4)).Times(2);

    mock.foo(4);
    // mock.foo(4);
}

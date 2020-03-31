/*
Testing some of @luantkow's tests in his answer here: 
https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object/44035118#44035118
*/

#include <gmock/gmock.h>

using namespace ::testing;

struct SomeMock
{
    MOCK_CONST_METHOD1(foo, void(int));
};
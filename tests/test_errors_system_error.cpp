//
// Created by Ivan Shynkarenka on 10.02.2016
//

#include "catch.hpp"

#include "errors/system_error.h"

using namespace CppCommon;

TEST_CASE("System error wrapper", "[CppCommon][Errors]")
{
    SystemError::SetLast(123);
    REQUIRE(SystemError::GetLast() == 123);
    SystemError::ClearLast();

    REQUIRE(SystemError::GetLast() == 0);

    REQUIRE(SystemError::Description().size() >= 0);
    REQUIRE(SystemError::Description(SystemError::GetLast()).size() >= 0);
}

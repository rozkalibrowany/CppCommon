//
// Created by Ivan Shynkarenka on 13.08.2016
//

#include "catch.hpp"

#include "string/encoding.h"

using namespace CppCommon;

void test(const std::string& utf8, const std::u16string& utf16, const std::u32string& utf32)
{
    REQUIRE(Encoding::UTF8toUTF16(utf8) == utf16);
    REQUIRE(Encoding::UTF8toUTF32(utf8) == utf32);
    REQUIRE(Encoding::UTF16toUTF8(utf16) == utf8);
    REQUIRE(Encoding::UTF16toUTF32(utf16) == utf32);
    REQUIRE(Encoding::UTF32toUTF8(utf32) == utf8);
    REQUIRE(Encoding::UTF32toUTF16(utf32) == utf16);

    std::wstring wstr = Encoding::FromUTF8(utf8);
    std::string str = Encoding::ToUTF8(wstr);
    REQUIRE(str == utf8);
}


TEST_CASE("Encoding", "[CppCommon][String]")
{
    test("\x61", u"\x0061", U"\x00000061");
    test("\xEF\xBD\x81", u"\xFF41", U"\x0000FF41");
    test("\xC4\x8D", u"\x010D", U"\x010D");
    test("\x63\xCC\x8C", u"\x0063\x030C", U"\x00000063\x0000030C");
    test("\xC4\xB3", u"\x0133", U"\x00000133");
    test("\x69\x6A", u"\x0069\x006A", U"\x00000069\x0000006A");
    test("\xCE\xA9", u"\x03A9", U"\x000003A9");
    test("\xE2\x84\xA6", u"\x2126", U"\x00002126");
    test("\xF0\x9D\x93\x83", u"\xD835\xDCC3", U"\x0001D4C3");
}

#include "gtest/gtest.h"
#include "roman_numeral.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(RomanNumeralTest, TestRomansDidntHave0) {
    ASSERT_STREQ(romanNumeralOf(0).c_str(), "");
}

TEST(RomanNumeralTest, TestInvalidArgument) {
    ASSERT_THROW(romanNumeralOf(-1), InvalidArgumentException);
    ASSERT_THROW(romanNumeralOf(4000), InvalidArgumentException);
}

TEST(RomanNumeralTest, TestLessThanFourGivesI) {
    ASSERT_STREQ(romanNumeralOf(1).c_str(), "I");
    ASSERT_STREQ(romanNumeralOf(2).c_str(), "II");
    ASSERT_STREQ(romanNumeralOf(3).c_str(), "III");
}

TEST(RomanNumeralTest, TestFiveOrMoreGivesV) {
    ASSERT_STREQ(romanNumeralOf(5).c_str(), "V");
    ASSERT_STREQ(romanNumeralOf(6).c_str(), "VI");
}

TEST(RomanNumeralTest, TestFourGivesIV) {
    ASSERT_STREQ(romanNumeralOf(4).c_str(), "IV");
}

TEST(RomanNumeralTest, TestTenOrMoreGivesX) {
    ASSERT_STREQ(romanNumeralOf(10).c_str(), "X");
    ASSERT_STREQ(romanNumeralOf(15).c_str(), "XV");
    ASSERT_STREQ(romanNumeralOf(16).c_str(), "XVI");
    ASSERT_STREQ(romanNumeralOf(20).c_str(), "XX");
}

TEST(RomanNumeralTest, TestNineGivesIX) {
    ASSERT_STREQ(romanNumeralOf(9).c_str(), "IX");
}

TEST(RomanNumeralTest, TestFiftyOrMoreGivesL) {
    ASSERT_STREQ(romanNumeralOf(50).c_str(), "L");
    ASSERT_STREQ(romanNumeralOf(60).c_str(), "LX");
    ASSERT_STREQ(romanNumeralOf(65).c_str(), "LXV");
}

TEST(RomanNumeralTest, TestFortyGivesXL) {
    ASSERT_STREQ(romanNumeralOf(40).c_str(), "XL");
    ASSERT_STREQ(romanNumeralOf(45).c_str(), "XLV");
    ASSERT_STREQ(romanNumeralOf(46).c_str(), "XLVI");
}

TEST(RomanNumeralTest, TestHundredOrMoreGivesC) {
    ASSERT_STREQ(romanNumeralOf(100).c_str(), "C");
    ASSERT_STREQ(romanNumeralOf(150).c_str(), "CL");
    ASSERT_STREQ(romanNumeralOf(160).c_str(), "CLX");
    ASSERT_STREQ(romanNumeralOf(165).c_str(), "CLXV");
    ASSERT_STREQ(romanNumeralOf(166).c_str(), "CLXVI");
    ASSERT_STREQ(romanNumeralOf(200).c_str(), "CC");
    ASSERT_STREQ(romanNumeralOf(300).c_str(), "CCC");
}

TEST(RomanNumeralTest, TestNinetyGivesXC) {
    ASSERT_STREQ(romanNumeralOf(90).c_str(), "XC");
    ASSERT_STREQ(romanNumeralOf(95).c_str(), "XCV");
    ASSERT_STREQ(romanNumeralOf(96).c_str(), "XCVI");
}

TEST(RomanNumeralTest, TestFiveHundredOrMoreGivesD) {
    ASSERT_STREQ(romanNumeralOf(500).c_str(), "D");
    ASSERT_STREQ(romanNumeralOf(600).c_str(), "DC");
    ASSERT_STREQ(romanNumeralOf(650).c_str(), "DCL");
}

TEST(RomanNumeralTest, TestFourHundredOrMoreGivesCD) {
    ASSERT_STREQ(romanNumeralOf(400).c_str(), "CD");
}

TEST(RomanNumeralTest, TestThousandOrMoreGivesM) {
    ASSERT_STREQ(romanNumeralOf(1000).c_str(), "M");
    ASSERT_STREQ(romanNumeralOf(2000).c_str(), "MM");
    ASSERT_STREQ(romanNumeralOf(3000).c_str(), "MMM");
}

TEST(RomanNumeralTest, TestNineHundredGivesCM) {
    ASSERT_STREQ(romanNumeralOf(900).c_str(), "CM");
}

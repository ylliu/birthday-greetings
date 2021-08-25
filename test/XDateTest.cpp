#include "gtest/gtest.h"
#include "../src/XDate.h"

class XDateTest : public ::testing::Test {

};

TEST_F(XDateTest, parse_day_and_month_from_yyyyMMdd_string) {
    XDate xDate("1990/08/10");
    EXPECT_EQ(xDate.month(), 8);
    EXPECT_EQ(xDate.day(), 10);
}


TEST_F(XDateTest, is_same_date) {
    XDate xDate("1990/08/10");
    XDate sameDay("2021/08/10");
    XDate notSameDay("2021/08/11");
    XDate notSameMonth("2021/09/10");

    EXPECT_TRUE(xDate.isSameDay(sameDay));
    EXPECT_FALSE(xDate.isSameDay(notSameDay));
    EXPECT_FALSE(xDate.isSameDay(notSameMonth));
}
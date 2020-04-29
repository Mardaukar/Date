#include "pch.h"
#include "../Date.h"

TEST(TestNextDay, Day) {
    Date date1 = Date(1, 1, 2020);
    Date date2 = Date(2, 1, 2020);
    date1.next_day();
    EXPECT_EQ(date1.get_day(), date2.get_day());
}

TEST(TestNextDay, Month) {
    Date date1 = Date(31, 1, 2020);
    Date date2 = Date(1, 2, 2020);
    date1.next_day();
    EXPECT_EQ(date1.get_month(), date2.get_month());
}

TEST(TestNextDay, Year) {
    Date date1 = Date(31, 12, 2020);
    Date date2 = Date(1, 1, 2021);
    date1.next_day();
    EXPECT_EQ(date1.get_year(), date2.get_year());
}

TEST(TestLeapYear, LeapYear_must_pass) {
    Date date1 = Date(28, 2, 2020);
    Date date2 = Date(29, 2, 2020);
    date1.next_day();
    EXPECT_EQ(date1.get_day(), date2.get_day());
    EXPECT_EQ(date1.get_month(), date2.get_month());
    EXPECT_EQ(date1.get_year(), date2.get_year());
}

TEST(TestLeapYear, LeapYear_must_fail) {
    Date date1 = Date(28, 2, 2021);
    Date date2 = Date(29, 2, 2021);
    date1.next_day();
    EXPECT_EQ(date1.get_day(), date2.get_day());
    EXPECT_EQ(date1.get_month(), date2.get_month());
    EXPECT_EQ(date1.get_year(), date2.get_year());
}

TEST(DaysSinceNY, TestDaysSinceNY) {
    Date date1 = Date(29, 2, 2020);
    EXPECT_EQ(date1.days_since_newyear(), 59);
}

TEST(DaysSinceNY, TestDaysSinceNY_leapYear) {
    Date date1 = Date(31, 12, 2020);
    EXPECT_EQ(date1.days_since_newyear(), 365);
}

TEST(DaysSinceNY, TestDaysSinceNY_notLeapYear) {
    Date date1 = Date(31, 12, 2021);
    EXPECT_EQ(date1.days_since_newyear(), 364);
}

TEST(DaysBetween, TestDaysBetween_must_pass) {
    Date date1 = Date(29, 2, 2020);
    Date date2 = Date(1, 9, 2020);
    EXPECT_EQ(date1.days_between(date2), 185);
}

TEST(DaysBetween, TestDaysBetween_must_fail) {
    Date date1 = Date(29, 2, 2020);
    Date date2 = Date(1, 9, 2025);
    EXPECT_EQ(date1.days_between(date2), 2000);
}

TEST(DaysBetween, TestLesserThan_must_pass) {
    Date date1 = Date(30, 4, 2020);
    Date date2 = Date(30, 4, 2022);
    EXPECT_LT(date1.days_between(date2), 1000);
}


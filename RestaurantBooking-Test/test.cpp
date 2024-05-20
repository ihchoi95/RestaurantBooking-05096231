#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <stdexcept>
#include "../ResttaurantBooking/BookingScheduler.cpp"

using namespace std;

TEST(BookingSchedulerTest, 예약은_정시에만_가능하다_정시가_아닌경우_예약불가) {
	// arrange
	tm notOnTheHour = { 0 };
	notOnTheHour.tm_year = 2021 - 1900;
	notOnTheHour.tm_mon = 03 - 1;
	notOnTheHour.tm_mday = 26;
	notOnTheHour.tm_hour = 9;
	notOnTheHour.tm_min = 5;
	notOnTheHour.tm_isdst = -1;
	mktime(&notOnTheHour);

	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ notOnTheHour , 1, customer };
	BookingScheduler bookingScheduler{ 3 };

	// act
	EXPECT_THROW(bookingScheduler.addSchedule(schedule), runtime_error);
}

TEST(BookingSchedulerTest, 예약은_정시에만_가능하다_정시인_경우_예약가능) {
	// arrange
	tm onTheHour = { 0 };
	onTheHour.tm_year = 2021 - 1900;
	onTheHour.tm_mon = 03 - 1;
	onTheHour.tm_mday = 26;
	onTheHour.tm_hour = 9;
	onTheHour.tm_min = 0;
	onTheHour.tm_isdst = -1;
	mktime(&onTheHour);

	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ onTheHour , 1, customer };
	BookingScheduler bookingScheduler{ 3 };

	// act
	bookingScheduler.addSchedule(schedule);

	// assert
	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST(BookingSchedulerTest, 시간대별_인원제한이_있다_같은_시간대에_Capacity_초과할_경우_예외발생) {

}

TEST(BookingSchedulerTest, 시간대별_인원제한이_있다_같은_시간대가_다르면_Capacity_차있어도_스케쥴_추가_성공) {

}

TEST(BookingSchedulerTest, 예약완료시_SMS는_무조건_발송) {

}

TEST(BookingSchedulerTest, 이메일이_없는_경우에는_이메일_미발송) {

}

TEST(BookingSchedulerTest, 이메일이_있는_경우에는_이메일_발송) {

}

TEST(BookingSchedulerTest, 현재날짜가_일요일인_경우_예약불가_예외처리) {

}

TEST(BookingSchedulerTest, 현재날짜가_일요일이_아닌경우_예약가능) {

}
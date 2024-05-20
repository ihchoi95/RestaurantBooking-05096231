#include<iostream>
#include "../ResttaurantBooking/Schedule.cpp"
#include "../ResttaurantBooking/SmsSender.cpp"

using namespace std;

class TestableSmsSender : public SmsSender {
public:
	void send(Schedule* schedule) override {
		cout << " 테스트용  SmsSender class의 send메서드 실행됨\n";
		sendMethodIsCalled = true;
	}
	bool isSendorMethodIsCalled() {
		return sendMethodIsCalled;
	}
private :
	bool sendMethodIsCalled;
};
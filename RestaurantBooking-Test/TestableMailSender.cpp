#include "../ResttaurantBooking/Schedule.cpp"
#include "../ResttaurantBooking/MailSender.cpp"

class TestableMailSender : public MailSender {
public:
	void sendMail(Schedule* scheudle) override {
		countSendMailMethodIsCalled++;
	}

	int getCountSendMailMethodIsCalled() {
		return countSendMailMethodIsCalled;
	}
private:
	int countSendMailMethodIsCalled;
};
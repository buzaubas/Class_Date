#pragma once
class Date
{
public:
	Date();
	Date(long long time);
	Date(size_t d, size_t m, size_t y);
	void currentTime();
	void show();
	size_t operator-(const Date& obj);
	Date operator+(const size_t obj);
	Date operator=(const Date& obj);
	void operator+=(const size_t obj);
	bool operator<(const Date& obj);
	bool operator>(const Date& obj);
	bool operator==(const Date& obj);
	bool operator!=(const Date& obj);
private:
	long long time;
};


#pragma once
#include <ctime>
#include <iostream>

using namespace std;

class Request
{
public:
	Request(int id, float due_date, float price, char* subject, char* status);
	Request();

	Request(const Request& other);
	Request& operator=(Request& other);
	virtual ~Request();

	inline int getId() const {
		return id;
	}
	inline void setId(int id) {
		this->id = id;
	}
	inline float getPrice() const{
		return price;
	}
	inline void setPrice(float price) {
		this->price = price;
	}
	inline float getDate() const {
		return due_date;
	}
	inline void setDate(float date) {
		this->due_date = date;
	}

private:
	int id;
	char* status;
	char* subject;
	float price;
	float due_date;
};


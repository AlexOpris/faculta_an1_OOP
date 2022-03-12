#pragma once
#include "Request.h"

class OnlineSession :public Request
{
public:
	OnlineSession(int id, float due_date, float price, char* subject, char* status, char* url, int duration);

	OnlineSession(const OnlineSession& other);
	OnlineSession& operator=(OnlineSession& other);
	virtual ~OnlineSession();

private:
	char* url;
	int duration;
};


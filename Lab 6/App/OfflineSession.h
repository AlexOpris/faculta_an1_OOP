#pragma once

#include "Request.h"

class OfflineSession:public Request
{
private:
	char* url_offline;

public:
	OfflineSession(int id, float due_date, float price, char* subject, char* status, char* url_offline);


};


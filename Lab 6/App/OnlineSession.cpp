#include "OnlineSession.h"

OnlineSession::OnlineSession(int id, float due_date, float price, char* subject, char* status, char* url, int duration):Request(id, due_date, price, subject, status)
{
	this->duration = duration;
	this->url = new char[strlen(url) + 1];
	for (int i = 0; i < strlen(url); i++)
		this->url[i] = url[i];
	this->url[strlen(url) + 1] = '\0';
}



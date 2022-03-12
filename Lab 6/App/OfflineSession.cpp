#include "OfflineSession.h"

OfflineSession::OfflineSession(int id, float due_date, float price, char* subject, char* status, char* url):Request(id, due_date, price, subject, status)
{
	this->url_offline = new char[strlen(url) + 1];
	for (int i = 0; i < strlen(url); i++)
		this->url_offline[i] = url[i];
	this->url_offline[strlen(url) + 1] = '\0';
}

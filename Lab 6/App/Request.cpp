#include "Request.h"

Request::Request(int id, float due_date, float price, char* subject, char* status)
{
	this->id = id;
	this->due_date = due_date;
	this->price = price;
	this->subject = new char[strlen(subject) + 1];
	for (int i = 0; i < strlen(subject); i++)
		this->subject[i] = subject[i];
	this->subject[strlen(subject)] = '\0';
	this->status = new char[strlen(status) + 1];
	for (int i = 0; i < strlen(status); i++)
		this->status[i] = status[i];
	this->status[strlen(status)] = '\0';
}

Request::Request()
{
	this->id = 0;
	this->due_date = 0;
	this->price = 0;
	this->subject = new char[];
	this->status = new char[];
}

Request::Request(const Request& other)
{
	this->id = other.id;
	this->due_date = other.due_date;
	this->price = other.price;

	this->subject = new char[strlen(other.subject) + 1];
	for (int i = 0; i < strlen(other.subject); i++)
		this->subject[i] = other.subject[i];
	this->subject[strlen(other.subject)] = '\0';

	this->status = new char[strlen(other.status) + 1];
	for (int i = 0; i < strlen(other.status); i++)
		this->status[i] = other.status[i];
	this->status[strlen(other.status)] = '\0';
}

Request& Request::operator=(Request& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->due_date = other.due_date;
		this->price = other.price;

		delete[] this->status;
		delete[] this->subject;
		this->subject = new char[strlen(other.subject) + 1];
		for (int i = 0; i < strlen(other.subject); i++)
			this->subject[i] = other.subject[i];
		this->subject[strlen(other.subject)] = '\0';

		this->status = new char[strlen(other.status) + 1];
		for (int i = 0; i < strlen(other.status); i++)
			this->status[i] = other.status[i];
		this->status[strlen(other.status)] = '\0';
	}
	return *this;
}

Request::~Request()
{
	delete[] this->status;
	delete[] this->subject;
}

#ifndef _EVENTLISTENER_H_
#define _EVENTLISTENER_H_

#pragma once
#include <iostream>
#include <list>

class EventListener
{

public:
	EventListener() {};
	~EventListener() {};
	
	bool English = false;
	bool French = false;
	bool Spanish = false;
};
#endif
#pragma once

#include "../include/Display.h"
#include "ECS/Base/Component.h"

struct Canvas : public ECS::Component
{

	Canvas(int width, int height, std::string& tittle) 
	{
		 _width = width;
		_height = height;
		_tittle = tittle;
		_display = nullptr;
	}

	virtual ~Canvas() {}

	int _width;
	int _height; 
	std::string _tittle;
	Display* _display;
};

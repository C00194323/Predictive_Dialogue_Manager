#pragma once


#pragma once

#include "Renderer.h"
#include "TextureContainer.h"
#include "math.h"
#include <string>
#include <iostream>

// ------------------------------------------------------------------ 
//
// PLATFORM : ALL
// PRODUCT : RWM_1718_P2
// VISIBILITY : PUBLIC
//
// ------------------------------------------------------------------ 
// PURPOSE : Base class for use in almost all objects in use in the program,
// for ease of use in updating and rendering objects

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void Render(Renderer& r) = 0;
	virtual void Update(unsigned int deltaTime) = 0;
};


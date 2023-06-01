#pragma once
#include "PrecompileHeader.h"


enum class DogAirplaneType
{
	Sky,
	Cloulds,
	Ground,

	
	Boss,
	BulDogIntro,
	DogCopterIntro, 
	ChinookIntro,
	Airplane, 
	AirplaneSpin,
	BulDogIdle,
	Player,
};

enum class CollisionType
{
	Player,
	Bullet,
	NpcAirPlane, 
	DogAirPlane_Pase1,

};
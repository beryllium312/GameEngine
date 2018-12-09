#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include <SDL.h>
#include <SDL_image.h>
#include "VMATH.h"
using namespace MATH;

class Body {
public:
	Vec3 pos;
	Vec3 vel;
	float mass;
	float radius;
	float stat;

private:
	Vec3 accel;
	SDL_Surface *bodyImage;

public:
	Body(float stat_);
	Body(std::string imageName, Vec3 pos_);
	Body(char* imageName, float mass_, float radius_, Vec3 pos_, Vec3 vel_, Vec3 accel_);
	void Update(const float deltaTime);
	void ApplyForce(Vec3 force);

	SDL_Surface* getImage();
};


#endif

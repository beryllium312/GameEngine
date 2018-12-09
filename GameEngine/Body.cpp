#include "Body.h" 
#include <string.h>
using namespace MATH;
using namespace std;

Body::Body(float stat_) {//health or mana
	stat = stat_;

}

Body::Body(std::string imageName, Vec3 pos_) {
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;
	
	bodyImage = IMG_Load(imageName.c_str());//IMG_Init(IMG_INIT_PNG)
	if (bodyImage == nullptr) {}
}

Body::Body(char* imageName, float mass_, float radius_, Vec3 pos_, Vec3 vel_, Vec3 accel_) {

	mass = mass_;
	radius = radius_;
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;

	bodyImage = IMG_Load(imageName);
	if (bodyImage == nullptr) {

	}
}

void Body::Update(const float deltaTime) {
	pos.x += (vel.x * deltaTime) + (0.5f * accel.x * (deltaTime * deltaTime));
	pos.y += (vel.y * deltaTime) + (0.5f * accel.y * (deltaTime * deltaTime));
	pos.z += (vel.z * deltaTime) + (0.5f * accel.z * (deltaTime * deltaTime));

	//to add gravity put 0.5(accel + gravity)t^2

	vel.x += accel.x * deltaTime;
	vel.y += accel.y * deltaTime;
	vel.z += accel.z * deltaTime;

	/// Assuming all acceleration comes from an applied force - maybe not in the future - gravity!!
	accel.x = 0.0f;
	accel.y = 0.0f;
	accel.z = 0.0f;

}

void Body::ApplyForce(Vec3 force) {
	accel.x += force.x / mass;
	accel.y += force.y / mass;
	accel.z += force.z / mass;
}


SDL_Surface* Body::getImage() {
	return bodyImage;
}
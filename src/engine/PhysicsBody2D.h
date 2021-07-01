#pragma once

#include <glm/glm.hpp>
#include <algorithm>

#include "../misc/utils.h"
#include "SceneObject.h"

// WARNING: THIS CLASS IS CURRENTLY OBSOLETE! 


constexpr float DEFAULT_TERM_LIN_VEL = 0.5f;
constexpr float DEFAULT_TERM_ANG_VEL = 4*PI;

/// <summary>
/// Struct that holds several kinematic properties like
/// linear and angular velocity, acceleration and drag.
/// </summary>
struct KinematicProperties {
	float linearVelocity;			// World space units per second
	float angularVelocity;			// Radians per second
	float linearAcceleration;		// World space units per second^2
	float angularAcceleration;		// Radians per second^2
	float angularDrag;				// World space units per second
	float linearDrag;				// Radians per second
	float terminalLinearVelocity;	// World space units per second
	float terminalAngularVelocity;	// Radians per second

	KinematicProperties(float linearVelocity = 0, float angularVelocity = 0,
		float linearAcceleration = 0, float angularAcceleration = 0,
		float linearDrag = 0, float angularDrag = 0,
		float terminalLinearVelocity = DEFAULT_TERM_LIN_VEL, float terminalAngularVelocity = DEFAULT_TERM_ANG_VEL)
		: linearVelocity(linearVelocity), angularVelocity(angularVelocity),
		linearAcceleration(linearAcceleration), angularAcceleration(angularAcceleration),
		linearDrag(linearDrag), angularDrag(angularDrag),
		terminalLinearVelocity(terminalLinearVelocity), terminalAngularVelocity(terminalAngularVelocity) { }

	/// <summary>
	/// Updates the kinematic properties according to
	/// the acceleration and drag parameters.
	/// </summary>
	void kinematicsUpdate();
};

class PhysicsBody2D: public Component {
public:
	KinematicProperties kinematics;

	PhysicsBody2D(SceneObject* obj)
		: Component(obj), kinematics() { }


	PhysicsBody2D(SceneObject* obj, KinematicProperties kinematics)
		: Component(obj), kinematics(kinematics) { }

	void update();
};
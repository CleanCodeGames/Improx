#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"
// Эластичная веревка (Резинка)

B2ObjectElasticRope::B2ObjectElasticRope(B2OBJECT_ARGS, b2Body* bodyA, b2Body* bodyB, const size_t segments_count, b2World& world) : B2OBJECT_INHERITANCE
{
	this->bodyA = bodyA;
	this->bodyB = bodyB;
	this->segments_count = segments_count;
	vec_rope_segments.reserve(segments_count);

	for (size_t i = 0; i < segments_count; i++) 
	{
		vec_rope_segments.push_back({ position, size, type, world });
		vec_rope_segments[i].body->SetFixedRotation(false);
		B2ObjectCircle& box = vec_rope_segments[i];
		box.body->GetFixtureList()->SetFriction(0.35f);
		box.body->GetFixtureList()->SetDensity(0.f);
		box.body->GetFixtureList()->SetRestitution(0.f);
	}

	rope_joint_def.bodyA = this->bodyA;
	rope_joint_def.bodyB = vec_rope_segments[0].body;
	rope_joint_def.localAnchorA = this->bodyA->GetWorldCenter();
	rope_joint_def.localAnchorB = vec_rope_segments[0].body->GetWorldCenter();
	rope_joint_def.maxLength = 125.f / SCALE_B2D / 1.41421356237f;
	rope_joint_def.type = b2JointType::e_ropeJoint; 
	rope_joint_def.collideConnected = false;
	rope_joint = static_cast<b2RopeJoint*>(world.CreateJoint(&rope_joint_def));

	rope_joint_def.maxLength = 2.f * size.x / SCALE_B2D;

	for (size_t i = 1; i < segments_count; i++)
	{
		rope_joint_def.bodyA = vec_rope_segments[i - 1].body;
		rope_joint_def.bodyB = vec_rope_segments[i].body;
		rope_joint_def.localAnchorA = vec_rope_segments[i - 1].body->GetWorldCenter();
		rope_joint_def.localAnchorB = vec_rope_segments[i].body->GetWorldCenter();
		rope_joint = static_cast<b2RopeJoint*>(world.CreateJoint(&rope_joint_def));
	}

	rope_joint_def.bodyA = vec_rope_segments[segments_count - 1].body;
	rope_joint_def.bodyB = this->bodyB;
	rope_joint_def.localAnchorA = vec_rope_segments[segments_count - 1].body->GetWorldCenter();
	rope_joint_def.localAnchorB = this->bodyB->GetWorldCenter();
	rope_joint = static_cast<b2RopeJoint*>(world.CreateJoint(&rope_joint_def));
}

void B2ObjectElasticRope::Update(const b2World& world)
{
	for (auto& segment : vec_rope_segments)
		segment.Update(world);
}

void B2ObjectElasticRope::Render(const sf::Texture* texture)
{
	for (auto& segment : vec_rope_segments)
	{
		segment.Render(texture);
	}
}

B2ObjectElasticRope::~B2ObjectElasticRope()
{

}
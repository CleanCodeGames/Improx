#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Engine/System/Geometry/Geometry.h"

typedef std::unordered_map<std::string, std::tuple<sf::RectangleShape, int>> BodyParts;

class PlayerBody : public BodyParts
{
private:

public:

	PlayerBody()
	{
	}

	std::tuple<sf::RectangleShape, int>* Get(const std::string& name) 
	{
		const auto& it = find(name); 
		return it != end() ? &it->second : nullptr;
	}

	void AddPart(const std::string& part_name, int hp = 100)
	{
		insert({ part_name, std::make_tuple(sf::RectangleShape(), hp)});
	}
};

class Player
{
private:

	void BuildBody()
	{
		
		std::get<0>(*body.Get("")).setSize(sf::Vector2f(100,100));
		std::get<1>(*body.Get("")) = 100;

		body.AddPart("hair");						// Волосы (скальп)
		body.AddPart("head");						// Голова

		body.AddPart("left_eye");					// Левый  глаз
		body.AddPart("right_eye");					// Правый глаз

		body.AddPart("corpus");						// Туловище

		body.AddPart("left_hand_arm");				// Левое  плечо
		body.AddPart("right_hand_arm");				// Правое пплечо

		body.AddPart("left_hand_forearm");			// Левое  предплечье
		body.AddPart("right_hand_forearm");			// Правое предплечье

		body.AddPart("left_hand_wrist");			// Левое  запястье (кисть)
		body.AddPart("right_hand_wrist");			// Правое запястье (кисть)

		body.AddPart("left_hand_finger_pinkie");	// Палец левой руки (мизинец)
		body.AddPart("left_hand_finger_ring");		// Палец левой руки (безымянный)
		body.AddPart("left_hand_finger_middle");	// Палец левой руки (средний)
		body.AddPart("left_hand_finger_index");		// Палец левой руки (указательный)
		body.AddPart("left_hand_finger_big");		// Палец левой руки (большой)

		body.AddPart("right_hand_finger_pinkie");	// Палец правой руки (мизинец)
		body.AddPart("right_hand_finger_ring");		// Палец правой руки (безымянный)
		body.AddPart("right_hand_finger_middle");	// Палец правой руки (средний)
		body.AddPart("right_hand_finger_index");	// Палец правой руки (указательный)
		body.AddPart("right_hand_finger_big");		// Палец правой руки (большой)

		body.AddPart("left_leg_hip");				// Левое  бедро
		body.AddPart("right_leg_hip");				// Правое бедро

		body.AddPart("left_leg_shin");				// Левая  голень
		body.AddPart("right_leg_shin");				// Правая голень

		body.AddPart("left_leg_foot");				// Левая  стопа
		body.AddPart("right_leg_foot");				// Правая стопа

		body.AddPart("left_leg_finger_pinkie");		// Палец левой ноги (мизинец)
		body.AddPart("left_leg_finger_ring");		// Палец левой ноги (безымянный)
		body.AddPart("left_leg_finger_middle");		// Палец левой ноги (средний)
		body.AddPart("left_leg_finger_index");		// Палец левой ноги (указательный)
		body.AddPart("left_leg_finger_big");		// Палец левой ноги (большой)

		body.AddPart("right_leg_finger_pinkie");	// Палец правой ноги (мизинец)
		body.AddPart("right_leg_finger_ring");		// Палец правой ноги (безымянный)
		body.AddPart("right_leg_finger_middle");	// Палец правой ноги (средний)
		body.AddPart("right_leg_finger_index");		// Палец правой ноги (указательный)
		body.AddPart("right_leg_finger_big");		// Палец правой ноги (большой)


		body.rehash(body.size());
	}

protected:

	PlayerBody body;

public:

	Player()
	{
		BuildBody();
	}

	void ChangeWeapon(const std::string name) {}
	void Update(){}
	void Action(){}
	void Render(){}
	~Player() {}
};


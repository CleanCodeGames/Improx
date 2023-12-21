#include "Suspect.h"

#define COMPONENT(index, name) std::get<index>(*Get(name))

enum PartIndex
{
	SHAPE,
	HP,
	POSITION,
	ORIGIN
};

Suspect::Suspect()
{
	AddPart("hair");						// Волосы (скальп)
	AddPart("head");						// Голова

	AddPart("left_eye");					// Левый  глаз
	AddPart("right_eye");					// Правый глаз

	AddPart("corpus");						// Туловище

	AddPart("left_hand_arm");				// Левое  плечо
	AddPart("right_hand_arm");				// Правое пплечо

	AddPart("left_hand_forearm");			// Левое  предплечье
	AddPart("right_hand_forearm");			// Правое предплечье

	AddPart("left_hand_wrist");				// Левое  запястье (кисть)
	AddPart("right_hand_wrist");			// Правое запястье (кисть)

	AddPart("left_hand_finger_pinkie");		// Палец левой руки (мизинец)
	AddPart("left_hand_finger_ring");		// Палец левой руки (безымянный)
	AddPart("left_hand_finger_middle");		// Палец левой руки (средний)
	AddPart("left_hand_finger_index");		// Палец левой руки (указательный)
	AddPart("left_hand_finger_big");		// Палец левой руки (большой)

	AddPart("right_hand_finger_pinkie");	// Палец правой руки (мизинец)
	AddPart("right_hand_finger_ring");		// Палец правой руки (безымянный)
	AddPart("right_hand_finger_middle");	// Палец правой руки (средний)
	AddPart("right_hand_finger_index");		// Палец правой руки (указательный)
	AddPart("right_hand_finger_big");		// Палец правой руки (большой)

	AddPart("left_leg_hip");				// Левое  бедро
	AddPart("right_leg_hip");				// Правое бедро

	AddPart("left_leg_shin");				// Левая  голень
	AddPart("right_leg_shin");				// Правая голень

	AddPart("left_leg_foot");				// Левая  стопа
	AddPart("right_leg_foot");				// Правая стопа

	AddPart("left_leg_finger_pinkie");		// Палец левой ноги (мизинец)
	AddPart("left_leg_finger_ring");		// Палец левой ноги (безымянный)
	AddPart("left_leg_finger_middle");		// Палец левой ноги (средний)
	AddPart("left_leg_finger_index");		// Палец левой ноги (указательный)
	AddPart("left_leg_finger_big");			// Палец левой ноги (большой)

	AddPart("right_leg_finger_pinkie");		// Палец правой ноги (мизинец)
	AddPart("right_leg_finger_ring");		// Палец правой ноги (безымянный)
	AddPart("right_leg_finger_middle");		// Палец правой ноги (средний)
	AddPart("right_leg_finger_index");		// Палец правой ноги (указательный)
	AddPart("right_leg_finger_big");		// Палец правой ноги (большой)

	m_body.rehash(m_body.size());
}

Suspect::BodyPart* Suspect::Get(const std::string& name)
{
	const auto& it = m_body.find(name);
	return it != m_body.end() ? &it->second : nullptr;
}

void Suspect::AddPart(const std::string& part_name)
{
	const BodyPart& part = std::make_tuple(sf::RectangleShape(), int(), sf::Vector2f(), sf::Vector2f());
	m_body.insert({ part_name,  part });
}

Suspect::~Suspect()
{

}
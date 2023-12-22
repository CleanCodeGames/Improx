#include "Suspect.h"
#define COMPONENT(index, name) std::get<index>(*GetBodyPart(name))

enum PartIndex
{
	SHAPE,
	HIT_POINT
};

Suspect::Suspect()
{
	BuildBody();
}

void Suspect::BuildBody()
{
	// Волосы (скальп)
	AddBodyPart("hair");					

	// Голова
	AddBodyPart("head");

	// Левый  глаз
	AddBodyPart("left_eye");

	// Правый глаз
	AddBodyPart("right_eye");

	// Туловище
	AddBodyPart("corpus");

	// Левое  плечо
	AddBodyPart("left_hand_arm");

	AddBodyPart("right_hand_arm");							// Правое пплечо
	AddBodyPart("left_hand_forearm");						// Левое  предплечье
	AddBodyPart("right_hand_forearm");						// Правое предплечье
	AddBodyPart("left_hand_wrist");							// Левое  запястье (кисть)
	AddBodyPart("right_hand_wrist");						// Правое запястье (кисть)
	AddBodyPart("left_hand_finger_pinkie");					// Палец левой руки (мизинец)
	AddBodyPart("left_hand_finger_ring");					// Палец левой руки (безымянный)
	AddBodyPart("left_hand_finger_middle");					// Палец левой руки (средний)
	AddBodyPart("left_hand_finger_index");					// Палец левой руки (указательный)
	AddBodyPart("left_hand_finger_big");					// Палец левой руки (большой)
	AddBodyPart("right_hand_finger_pinkie");				// Палец правой руки (мизинец)
	AddBodyPart("right_hand_finger_ring");					// Палец правой руки (безымянный)
	AddBodyPart("right_hand_finger_middle");				// Палец правой руки (средний)
	AddBodyPart("right_hand_finger_index");					// Палец правой руки (указательный)
	AddBodyPart("right_hand_finger_big");					// Палец правой руки (большой)
	AddBodyPart("left_leg_hip");							// Левое  бедро
	AddBodyPart("right_leg_hip");							// Правое бедро
	AddBodyPart("left_leg_shin");							// Левая  голень
	AddBodyPart("right_leg_shin");							// Правая голень
	AddBodyPart("left_leg_foot");							// Левая  стопа
	AddBodyPart("right_leg_foot");							// Правая стопа
	AddBodyPart("left_leg_finger_pinkie");					// Палец левой ноги (мизинец)
	AddBodyPart("left_leg_finger_ring");					// Палец левой ноги (безымянный)
	AddBodyPart("left_leg_finger_middle");					// Палец левой ноги (средний)
	AddBodyPart("left_leg_finger_index");					// Палец левой ноги (указательный)
	AddBodyPart("left_leg_finger_big");						// Палец левой ноги (большой)
	AddBodyPart("right_leg_finger_pinkie");					// Палец правой ноги (мизинец)
	AddBodyPart("right_leg_finger_ring");					// Палец правой ноги (безымянный)
	AddBodyPart("right_leg_finger_middle");					// Палец правой ноги (средний)
	AddBodyPart("right_leg_finger_index");					// Палец правой ноги (указательный)
	AddBodyPart("right_leg_finger_big");					// Палец правой ноги (большой)

	m_body.rehash(m_body.size());
}

Suspect::BodyPart* Suspect::GetBodyPart(const std::string& body_part_name)
{
	const auto& it = m_body.find(body_part_name);
	return it != m_body.end() ? &it->second : nullptr;
}

void Suspect::AddBodyPart(const std::string& body_part_name)
{
	const BodyPart& part = std::make_tuple(sf::RectangleShape(), int(), sf::Vector2f(), sf::Vector2f());
	m_body.insert({ body_part_name,  part });
}

Suspect::~Suspect()
{

}
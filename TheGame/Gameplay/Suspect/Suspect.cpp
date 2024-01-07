#include "Suspect.h"
#define BODYPART(index, name) std::get<index>(*GetBodyPart(name))

enum PartIndex
{
	SHAPE,
	HIT_POINT,
	ANCHOR_POINT,
	GRAVITY_POINT,
	HIGHEST_POINT,
	LOWEST_POINT
};

void Suspect::AddBodyPart(const KeyMap& body_part_name)
{
	const BodyPart& part = std::make_tuple(sf::RectangleShape(), HitPoint(), AnchorPoint(), GravityPoint(), HighestPoint(), LowestPoint());
	m_body.insert({ body_part_name,  part });
}

Suspect::Suspect()
{
	BuildBody();
}

void Suspect::SwapBodyPart(const KeyMap& k1, const KeyMap& k2)
{
	const Body::iterator it1 = m_body.find(k1);
	const Body::iterator it2 = m_body.find(k2);
	if ((it1 != m_body.end()) && (it2 != m_body.end()))
		std::swap(it1->second, it2->second);
}

void Suspect::BuildBody()
{
	auto BuildBodyPartShape([&](sf::RectangleShape& shape, const AnchorPoint& position, const Size& size, const Origin& origin, const sf::Color& color)
		{
			shape.setSize(size);
			shape.setPosition(position);
			shape.setOrigin(origin);
			shape.setFillColor(color);
		}
	);

	/* Туловище */
	AddBodyPart("corpus");
	const auto& size_corpus = sf::Vector2f(256.f, 256.f * 1.5f);
	const auto& position_corpus = System::camera_position;
	BuildBodyPartShape(BODYPART(SHAPE, "corpus"), position_corpus, size_corpus, size_corpus / 2.f, sf::Color::Green);

	/* Голова */
	AddBodyPart("head");
	const auto& size_head = sf::Vector2f(96.f, 128.f);
	const auto& rotation_corpus = BODYPART(SHAPE, "corpus").getRotation();
	const auto& position_head = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 90);
	const auto& origin_head = sf::Vector2f(size_head.x / 2.f, size_head.y);
	BuildBodyPartShape(BODYPART(SHAPE, "head"), position_head, size_head, origin_head, sf::Color::Yellow);

	/* Волосы (скальп) */
	AddBodyPart("hair");
	const auto& size_hair = sf::Vector2f(128, 32);
	const auto& rotation_head = BODYPART(SHAPE, "head").getRotation();
	const auto& position_hair = Geometry::Normalized(position_head, size_head.y - size_hair.y / 4.0f, rotation_head - 90);
	BuildBodyPartShape(BODYPART(SHAPE, "hair"), position_hair, size_hair, size_hair / 2.f, sf::Color::Cyan);

	/* Левый глаз */
	AddBodyPart("left_eye");
	const auto& size_eye = sf::Vector2f(16.f, 16.f);
	const auto& position_left_eye = Geometry::Normalized(position_head, size_head.y * 0.66f + size_eye.x / 2.f, rotation_head - 110);
	BuildBodyPartShape(BODYPART(SHAPE, "left_eye"), position_left_eye, size_eye, size_eye / 2.f, sf::Color::Black);

	/* Правый глаз */
	AddBodyPart("right_eye");
	const auto& position_right_eye = Geometry::Normalized(position_head, size_head.y * 0.66f + size_eye.x / 2.f, rotation_head -  70);
	BuildBodyPartShape(BODYPART(SHAPE, "right_eye"), position_right_eye, size_eye, size_eye / 2.f, sf::Color::Black);

	/* Левое  плечо */
	AddBodyPart("left_hand_arm");
	const auto& position_left_hand_arm = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 120.f);
	const auto& size_left_hand_arm = sf::Vector2f(64.f, 192.f);
	const auto& origin_left_hand_arm = sf::Vector2f(size_left_hand_arm.x / 2.f, 0.f);
	BuildBodyPartShape(BODYPART(SHAPE, "left_hand_arm"), position_left_hand_arm, size_left_hand_arm, origin_left_hand_arm, sf::Color::Red);
	BODYPART(SHAPE, "left_hand_arm").setRotation(105);

	/* Правое пплечо */
	AddBodyPart("right_hand_arm");
	const auto& position_right_hand_arm = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 60.f);
	const auto& size_right_hand_arm = sf::Vector2f(64.f, 192.f);
	const auto& origin_right_hand_arm = sf::Vector2f(size_right_hand_arm.x / 2.f, 0.f);
	BuildBodyPartShape(BODYPART(SHAPE, "right_hand_arm"), position_right_hand_arm, size_right_hand_arm, origin_right_hand_arm, sf::Color::Magenta);
	BODYPART(SHAPE, "right_hand_arm").setRotation(-105);

	/* Левое  предплечье */
	AddBodyPart("left_hand_forearm");
	const auto& position_left_hand_forearm = Geometry::Normalized(position_left_hand_arm, size_left_hand_arm.y, BODYPART(SHAPE,"left_hand_arm").getRotation() + 90);
	const auto& size_left_hand_forearm = sf::Vector2f(56.f, 192.f);
	const auto& origin_left_hand_forearm = sf::Vector2f(size_left_hand_forearm.x / 2.f, size_left_hand_forearm.y * 0.1f);
	BuildBodyPartShape(BODYPART(SHAPE, "left_hand_forearm"), position_left_hand_forearm, size_left_hand_forearm, origin_left_hand_forearm, sf::Color::Blue);
	BODYPART(SHAPE, "left_hand_forearm").setRotation(60);

	/* Правое предплечье */
	AddBodyPart("right_hand_forearm");
	const auto& position_right_hand_forearm = Geometry::Normalized(position_right_hand_arm, size_right_hand_arm.y, BODYPART(SHAPE, "right_hand_arm").getRotation() + 90);
	const auto& size_right_hand_forearm = sf::Vector2f(56.f, 192.f);
	const auto& origin_right_hand_forearm = sf::Vector2f(size_right_hand_forearm.x / 2.f, size_right_hand_forearm.y * 0.1f);
	BuildBodyPartShape(BODYPART(SHAPE, "right_hand_forearm"), position_right_hand_forearm, size_right_hand_forearm, origin_right_hand_forearm, sf::Color::White);
	BODYPART(SHAPE, "right_hand_forearm").setRotation(300);

	AddBodyPart("left_hand_wrist");				// Левое  запястье (кисть)
	AddBodyPart("right_hand_wrist");			// Правое запястье (кисть)
	AddBodyPart("left_hand_finger_pinkie");		// Палец левой руки (мизинец)
	AddBodyPart("left_hand_finger_ring");		// Палец левой руки (безымянный)
	AddBodyPart("left_hand_finger_middle");		// Палец левой руки (средний)
	AddBodyPart("left_hand_finger_index");		// Палец левой руки (указательный)
	AddBodyPart("left_hand_finger_big");		// Палец левой руки (большой)
	AddBodyPart("right_hand_finger_pinkie");	// Палец правой руки (мизинец)
	AddBodyPart("right_hand_finger_ring");		// Палец правой руки (безымянный)
	AddBodyPart("right_hand_finger_middle");	// Палец правой руки (средний)
	AddBodyPart("right_hand_finger_index");		// Палец правой руки (указательный)
	AddBodyPart("right_hand_finger_big");		// Палец правой руки (большой)
	AddBodyPart("left_leg_hip");				// Левое  бедро
	AddBodyPart("right_leg_hip");				// Правое бедро
	AddBodyPart("left_leg_shin");				// Левая  голень
	AddBodyPart("right_leg_shin");				// Правая голень
	AddBodyPart("left_leg_foot");				// Левая  стопа
	AddBodyPart("right_leg_foot");				// Правая стопа
	AddBodyPart("left_leg_finger_pinkie");		// Палец левой ноги (мизинец)
	AddBodyPart("left_leg_finger_ring");		// Палец левой ноги (безымянный)
	AddBodyPart("left_leg_finger_middle");		// Палец левой ноги (средний)
	AddBodyPart("left_leg_finger_index");		// Палец левой ноги (указательный)
	AddBodyPart("left_leg_finger_big");			// Палец левой ноги (большой)
	AddBodyPart("right_leg_finger_pinkie");		// Палец правой ноги (мизинец)
	AddBodyPart("right_leg_finger_ring");		// Палец правой ноги (безымянный)
	AddBodyPart("right_leg_finger_middle");		// Палец правой ноги (средний)
	AddBodyPart("right_leg_finger_index");		// Палец правой ноги (указательный)
	AddBodyPart("right_leg_finger_big");		// Палец правой ноги (большой)
}
void Suspect::Update()
{

}

void Suspect::Action()
{

}

void Suspect::Render()
{
	for (auto& part : m_body)
		System::window->draw(BODYPART(SHAPE, part.first));
}

Suspect::BodyPart* Suspect::GetBodyPart(const KeyMap& body_part_name)
{
	const auto& it = m_body.find(body_part_name);
	return it != m_body.end() ? &it->second : nullptr;
}

Suspect::~Suspect()
{

}
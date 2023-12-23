#include "Suspect.h"
#define BODY_PART(index, name) std::get<index>(*GetBodyPart(name))

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
	auto BuildPart([&](sf::RectangleShape& shape, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& origin, const sf::Color& color)
		{
			shape.setSize(size);
			shape.setPosition(position);
			shape.setOrigin(origin);
			shape.setFillColor(color);
		}
	);

	/* �������� */
	AddBodyPart("corpus");
	const auto& size_corpus = sf::Vector2f(256.f, 256.f * 1.5f);
	const auto& position_corpus = System::camera_position;
	BuildPart(BODY_PART(SHAPE, "corpus"), position_corpus, size_corpus, size_corpus / 2.f, sf::Color::Green);

	/* ������ */
	AddBodyPart("head");
	const auto& size_head = sf::Vector2f(96.f, 128.f);
	const auto& rotation_corpus = BODY_PART(SHAPE, "corpus").getRotation();
	const auto& position_head = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 90);
	const auto& origin_head = sf::Vector2f(size_head.x / 2.f, size_head.y);
	BuildPart(BODY_PART(SHAPE, "head"), position_head, size_head, origin_head, sf::Color::Yellow);

	/* ������ (������) */
	AddBodyPart("hair");
	const auto& size_hair = sf::Vector2f(128, 32);
	const auto& rotation_head = BODY_PART(SHAPE, "head").getRotation();
	const auto& position_hair = Geometry::Normalized(position_head, size_head.y + size_hair.y / 2.0f, rotation_head - 90);
	BuildPart(BODY_PART(SHAPE, "hair"), position_hair, size_hair, size_hair / 2.f, sf::Color::Cyan);

	/* ����� ���� */
	AddBodyPart("left_eye");
	const auto& size_eye = sf::Vector2f(16.f, 16.f);
	const auto& position_left_eye = Geometry::Normalized(position_head, size_head.y * 0.66f + size_eye.x / 2.f, rotation_head - 110);
	BuildPart(BODY_PART(SHAPE, "left_eye"), position_left_eye, size_eye, size_eye / 2.f, sf::Color::Black);

	/* ������ ���� */
	AddBodyPart("right_eye");
	const auto& position_right_eye = Geometry::Normalized(position_head, size_head.y * 0.66f + size_eye.x / 2.f, rotation_head -  70);
	BuildPart(BODY_PART(SHAPE, "right_eye"), position_right_eye, size_eye, size_eye / 2.f, sf::Color::Black);

	/* �����  ����� */
	AddBodyPart("left_hand_arm");
	const auto& position_left_hand = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 120.f);
	const auto& size_left_hand = sf::Vector2f(64.f, 192.f);
	const auto& origin_left_hand = sf::Vector2f(size_left_hand.x / 2.f, 0.f);
	BuildPart(BODY_PART(SHAPE, "left_hand_arm"), position_left_hand, size_left_hand, origin_left_hand, sf::Color::Red);
	BODY_PART(SHAPE, "left_hand_arm").setRotation(105);

	/* ������ ������ */
	AddBodyPart("right_hand_arm");
	const auto& position_right_hand = Geometry::Normalized(position_corpus, size_corpus.y / 2.0f, rotation_corpus - 60.f);
	const auto& size_right_hand = sf::Vector2f(64.f, 192.f);
	const auto& origin_right_hand = sf::Vector2f(size_right_hand.x / 2.f, 0.f);
	BuildPart(BODY_PART(SHAPE, "right_hand_arm"), position_right_hand, size_right_hand, origin_right_hand, sf::Color::Magenta);
	BODY_PART(SHAPE, "right_hand_arm").setRotation(260);

	AddBodyPart("left_hand_forearm");			// �����  ����������
	AddBodyPart("right_hand_forearm");			// ������ ����������
	AddBodyPart("left_hand_wrist");				// �����  �������� (�����)
	AddBodyPart("right_hand_wrist");			// ������ �������� (�����)
	AddBodyPart("left_hand_finger_pinkie");		// ����� ����� ���� (�������)
	AddBodyPart("left_hand_finger_ring");		// ����� ����� ���� (����������)
	AddBodyPart("left_hand_finger_middle");		// ����� ����� ���� (�������)
	AddBodyPart("left_hand_finger_index");		// ����� ����� ���� (������������)
	AddBodyPart("left_hand_finger_big");		// ����� ����� ���� (�������)
	AddBodyPart("right_hand_finger_pinkie");	// ����� ������ ���� (�������)
	AddBodyPart("right_hand_finger_ring");		// ����� ������ ���� (����������)
	AddBodyPart("right_hand_finger_middle");	// ����� ������ ���� (�������)
	AddBodyPart("right_hand_finger_index");		// ����� ������ ���� (������������)
	AddBodyPart("right_hand_finger_big");		// ����� ������ ���� (�������)
	AddBodyPart("left_leg_hip");				// �����  �����
	AddBodyPart("right_leg_hip");				// ������ �����
	AddBodyPart("left_leg_shin");				// �����  ������
	AddBodyPart("right_leg_shin");				// ������ ������
	AddBodyPart("left_leg_foot");				// �����  �����
	AddBodyPart("right_leg_foot");				// ������ �����
	AddBodyPart("left_leg_finger_pinkie");		// ����� ����� ���� (�������)
	AddBodyPart("left_leg_finger_ring");		// ����� ����� ���� (����������)
	AddBodyPart("left_leg_finger_middle");		// ����� ����� ���� (�������)
	AddBodyPart("left_leg_finger_index");		// ����� ����� ���� (������������)
	AddBodyPart("left_leg_finger_big");			// ����� ����� ���� (�������)
	AddBodyPart("right_leg_finger_pinkie");		// ����� ������ ���� (�������)
	AddBodyPart("right_leg_finger_ring");		// ����� ������ ���� (����������)
	AddBodyPart("right_leg_finger_middle");		// ����� ������ ���� (�������)
	AddBodyPart("right_leg_finger_index");		// ����� ������ ���� (������������)
	AddBodyPart("right_leg_finger_big");		// ����� ������ ���� (�������)

	m_body.rehash(m_body.size());
}

void Suspect::Draw()
{
	for (auto& part : m_body)
		System::window->draw(BODY_PART(SHAPE, part.first));
}

Suspect::BodyPart* Suspect::GetBodyPart(const std::string& body_part_name)
{
	const auto& it = m_body.find(body_part_name);
	return it != m_body.end() ? &it->second : nullptr;
}

void Suspect::AddBodyPart(const std::string& body_part_name)
{
	const BodyPart& part = std::make_tuple(sf::RectangleShape(), int());
	m_body.insert({ body_part_name,  part });
}

Suspect::~Suspect()
{

}
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
	// ������ (������)
	AddBodyPart("hair");					

	// ������
	AddBodyPart("head");

	// �����  ����
	AddBodyPart("left_eye");

	// ������ ����
	AddBodyPart("right_eye");

	// ��������
	AddBodyPart("corpus");

	// �����  �����
	AddBodyPart("left_hand_arm");

	AddBodyPart("right_hand_arm");							// ������ ������
	AddBodyPart("left_hand_forearm");						// �����  ����������
	AddBodyPart("right_hand_forearm");						// ������ ����������
	AddBodyPart("left_hand_wrist");							// �����  �������� (�����)
	AddBodyPart("right_hand_wrist");						// ������ �������� (�����)
	AddBodyPart("left_hand_finger_pinkie");					// ����� ����� ���� (�������)
	AddBodyPart("left_hand_finger_ring");					// ����� ����� ���� (����������)
	AddBodyPart("left_hand_finger_middle");					// ����� ����� ���� (�������)
	AddBodyPart("left_hand_finger_index");					// ����� ����� ���� (������������)
	AddBodyPart("left_hand_finger_big");					// ����� ����� ���� (�������)
	AddBodyPart("right_hand_finger_pinkie");				// ����� ������ ���� (�������)
	AddBodyPart("right_hand_finger_ring");					// ����� ������ ���� (����������)
	AddBodyPart("right_hand_finger_middle");				// ����� ������ ���� (�������)
	AddBodyPart("right_hand_finger_index");					// ����� ������ ���� (������������)
	AddBodyPart("right_hand_finger_big");					// ����� ������ ���� (�������)
	AddBodyPart("left_leg_hip");							// �����  �����
	AddBodyPart("right_leg_hip");							// ������ �����
	AddBodyPart("left_leg_shin");							// �����  ������
	AddBodyPart("right_leg_shin");							// ������ ������
	AddBodyPart("left_leg_foot");							// �����  �����
	AddBodyPart("right_leg_foot");							// ������ �����
	AddBodyPart("left_leg_finger_pinkie");					// ����� ����� ���� (�������)
	AddBodyPart("left_leg_finger_ring");					// ����� ����� ���� (����������)
	AddBodyPart("left_leg_finger_middle");					// ����� ����� ���� (�������)
	AddBodyPart("left_leg_finger_index");					// ����� ����� ���� (������������)
	AddBodyPart("left_leg_finger_big");						// ����� ����� ���� (�������)
	AddBodyPart("right_leg_finger_pinkie");					// ����� ������ ���� (�������)
	AddBodyPart("right_leg_finger_ring");					// ����� ������ ���� (����������)
	AddBodyPart("right_leg_finger_middle");					// ����� ������ ���� (�������)
	AddBodyPart("right_leg_finger_index");					// ����� ������ ���� (������������)
	AddBodyPart("right_leg_finger_big");					// ����� ������ ���� (�������)

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
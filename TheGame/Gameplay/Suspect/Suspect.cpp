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
	AddPart("hair");						// ������ (������)
	AddPart("head");						// ������

	AddPart("left_eye");					// �����  ����
	AddPart("right_eye");					// ������ ����

	AddPart("corpus");						// ��������

	AddPart("left_hand_arm");				// �����  �����
	AddPart("right_hand_arm");				// ������ ������

	AddPart("left_hand_forearm");			// �����  ����������
	AddPart("right_hand_forearm");			// ������ ����������

	AddPart("left_hand_wrist");				// �����  �������� (�����)
	AddPart("right_hand_wrist");			// ������ �������� (�����)

	AddPart("left_hand_finger_pinkie");		// ����� ����� ���� (�������)
	AddPart("left_hand_finger_ring");		// ����� ����� ���� (����������)
	AddPart("left_hand_finger_middle");		// ����� ����� ���� (�������)
	AddPart("left_hand_finger_index");		// ����� ����� ���� (������������)
	AddPart("left_hand_finger_big");		// ����� ����� ���� (�������)

	AddPart("right_hand_finger_pinkie");	// ����� ������ ���� (�������)
	AddPart("right_hand_finger_ring");		// ����� ������ ���� (����������)
	AddPart("right_hand_finger_middle");	// ����� ������ ���� (�������)
	AddPart("right_hand_finger_index");		// ����� ������ ���� (������������)
	AddPart("right_hand_finger_big");		// ����� ������ ���� (�������)

	AddPart("left_leg_hip");				// �����  �����
	AddPart("right_leg_hip");				// ������ �����

	AddPart("left_leg_shin");				// �����  ������
	AddPart("right_leg_shin");				// ������ ������

	AddPart("left_leg_foot");				// �����  �����
	AddPart("right_leg_foot");				// ������ �����

	AddPart("left_leg_finger_pinkie");		// ����� ����� ���� (�������)
	AddPart("left_leg_finger_ring");		// ����� ����� ���� (����������)
	AddPart("left_leg_finger_middle");		// ����� ����� ���� (�������)
	AddPart("left_leg_finger_index");		// ����� ����� ���� (������������)
	AddPart("left_leg_finger_big");			// ����� ����� ���� (�������)

	AddPart("right_leg_finger_pinkie");		// ����� ������ ���� (�������)
	AddPart("right_leg_finger_ring");		// ����� ������ ���� (����������)
	AddPart("right_leg_finger_middle");		// ����� ������ ���� (�������)
	AddPart("right_leg_finger_index");		// ����� ������ ���� (������������)
	AddPart("right_leg_finger_big");		// ����� ������ ���� (�������)

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
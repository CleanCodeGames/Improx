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

		body.AddPart("hair");						// ������ (������)
		body.AddPart("head");						// ������

		body.AddPart("left_eye");					// �����  ����
		body.AddPart("right_eye");					// ������ ����

		body.AddPart("corpus");						// ��������

		body.AddPart("left_hand_arm");				// �����  �����
		body.AddPart("right_hand_arm");				// ������ ������

		body.AddPart("left_hand_forearm");			// �����  ����������
		body.AddPart("right_hand_forearm");			// ������ ����������

		body.AddPart("left_hand_wrist");			// �����  �������� (�����)
		body.AddPart("right_hand_wrist");			// ������ �������� (�����)

		body.AddPart("left_hand_finger_pinkie");	// ����� ����� ���� (�������)
		body.AddPart("left_hand_finger_ring");		// ����� ����� ���� (����������)
		body.AddPart("left_hand_finger_middle");	// ����� ����� ���� (�������)
		body.AddPart("left_hand_finger_index");		// ����� ����� ���� (������������)
		body.AddPart("left_hand_finger_big");		// ����� ����� ���� (�������)

		body.AddPart("right_hand_finger_pinkie");	// ����� ������ ���� (�������)
		body.AddPart("right_hand_finger_ring");		// ����� ������ ���� (����������)
		body.AddPart("right_hand_finger_middle");	// ����� ������ ���� (�������)
		body.AddPart("right_hand_finger_index");	// ����� ������ ���� (������������)
		body.AddPart("right_hand_finger_big");		// ����� ������ ���� (�������)

		body.AddPart("left_leg_hip");				// �����  �����
		body.AddPart("right_leg_hip");				// ������ �����

		body.AddPart("left_leg_shin");				// �����  ������
		body.AddPart("right_leg_shin");				// ������ ������

		body.AddPart("left_leg_foot");				// �����  �����
		body.AddPart("right_leg_foot");				// ������ �����

		body.AddPart("left_leg_finger_pinkie");		// ����� ����� ���� (�������)
		body.AddPart("left_leg_finger_ring");		// ����� ����� ���� (����������)
		body.AddPart("left_leg_finger_middle");		// ����� ����� ���� (�������)
		body.AddPart("left_leg_finger_index");		// ����� ����� ���� (������������)
		body.AddPart("left_leg_finger_big");		// ����� ����� ���� (�������)

		body.AddPart("right_leg_finger_pinkie");	// ����� ������ ���� (�������)
		body.AddPart("right_leg_finger_ring");		// ����� ������ ���� (����������)
		body.AddPart("right_leg_finger_middle");	// ����� ������ ���� (�������)
		body.AddPart("right_leg_finger_index");		// ����� ������ ���� (������������)
		body.AddPart("right_leg_finger_big");		// ����� ������ ���� (�������)


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


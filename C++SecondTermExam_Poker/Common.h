#pragma once

#define MAX_CARD_NUM 52	//�R�D�̐��i�W���[�J�[�Ȃ��j
#define HAND_NUM 5	//��D�̐�
#define SUIT_NUM 4	//�}�[�N�̐�
#define NUM_NUM 13	//�����̐�

//�|�[�J�[�̖�
enum Hand
{
	No_Hand,
	OnePair,
	TwoPair,
	ThreeOfAKind,
	Straight,
	Flush,
	HullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalStraightFlush,
};

//���_������z��́An�Ԗڂ̖���
enum PointArray
{
	Point_Of_Hand,
	Power_Of_Hand,
};
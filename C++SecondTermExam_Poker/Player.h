#pragma once

#include "Common.h"
#include "Shoe.h"
#include "Card.h"

class Player
{
public:
	Player(const char* pName);		//�R���X�g���N�^
	virtual ~Player();				//�f�X�g���N�^
	void ShowHand();				//��D�\��
	void Play(Shoe& shoe);				//�v���C
	Hand DetermineHand();			//���̔���

	//���O��ς���
	const char* GetName()const		
	{
		return _pName;
	}
	//���̋�����Ԃ�
	const int GetPoint()const
	{
		return _point[Point_Of_Hand];
	}
	//�������̋�������߂邽�߂̃p���[��Ԃ�
	const int GetPower()const
	{
		return _point[Power_Of_Hand];
	}

private:
	void ExchangeCards(Shoe& shoe);	//��D����
	void SortHand();				//��D���ёւ�

private:
	char* _pName;
	Card _hand[HAND_NUM];	//��D
	int _point[2];			//���_ (�O�Ԗڂɖ��̋����A�P�Ԗڂɓ������ǂ����̋������r���邽�߂̐���������)
};


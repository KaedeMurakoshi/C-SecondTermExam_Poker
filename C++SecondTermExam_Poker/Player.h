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

	const char* GetName()const		//���O�\���p
	{
		return _pName;
	}
	const int* GetPoint()const
	{
		return _point;
	}
	
private:
	void ExchangeCards(Shoe& shoe);	//��D����
	void SortHand();				//��D���ёւ�

private:
	char* _pName;
	Card _hand[HAND_NUM];	//��D
	int _point[2];			//���_
};


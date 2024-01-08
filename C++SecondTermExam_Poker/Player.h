#pragma once

#include "Common.h"
#include "Shoe.h"
#include "Card.h"

class Player
{
public:
	Player(const char* pName);	//�R���X�g���N�^
	virtual ~Player();			//�f�X�g���N�^
	void ShowHand();			//��D�\��
	void Play(Shoe& shoe);				//�v���C
	int DetermineHand();		//���̔���
	const char* GetName()const;	//���O�\���p
	void ExchangeCards(Shoe& shoe);		//��D����
private:
	//void ExchangeCards();		//��D����
	void SortHand();			//��D���ёւ�

private:
	char* _pName;
	Card _hand[HAND_NUM];	//��D
};


#pragma once
#include"Common.h"

class Shoe
{
public:
	Shoe();				// �R���X�g���N�^
	virtual ~Shoe();	// �f�X�g���N�^��virtual������
	int TakeCard();		// �J�[�h���P���Ԃ�	

private:
	int _card[CARD_NUM];
	int _cardNum;		// �J�[�h�������c���Ă��邩
	void _Shuffle();	// �V���b�t��
};


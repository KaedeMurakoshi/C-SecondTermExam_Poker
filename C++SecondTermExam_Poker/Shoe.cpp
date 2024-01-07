#include <iostream>
#include "Shoe.h"

//�R���X�g���N�^
Shoe::Shoe()
{
	InitShoe();
}

//�f�X�g���N�^
Shoe::~Shoe()
{

}

Card Shoe::TakeCard()
{
	// �J�[�h�̎c�薇�����O��������R�D��������
	if (_cardNum <= 0)
	{
		InitShoe();
		_cardNum = MAX_CARD_NUM;
	}

	// �R�D�̌�납������Ă���
	--_cardNum;
	Card card = _cards[_cardNum];

	// �f�o�b�O�p
	// �������J�[�h�Ɂ|�P������
	_cards[_cardNum].SetNum(-1);
	_cards[_cardNum].SetSuit(-1);

	return card;
}

void Shoe::InitShoe()
{
	// �J�[�h����������
	_cardNum = MAX_CARD_NUM;

	// �J�[�h������
	for (int i = 0; i < MAX_CARD_NUM; ++i)
	{
		_cards[i].SetNum(i % 13);	//�O�`�P�Q�ŏ�����
		_cards[i].SetSuit(i % 4);	//�O�`�R�ŏ�����
	}

	// �V���b�t��
	_Shuffle();
}

//�t�B�b�V���[�C�F�[�c�V���b�t��
void Shoe::_Shuffle()
{
	for (int i = MAX_CARD_NUM - 1; i > 0; --i) 
	{
		int a = i;
		int b = rand() % i;

		Card tempCard = _cards[a];
		_cards[a] = _cards[b];
		_cards[b] = tempCard;
	}
}
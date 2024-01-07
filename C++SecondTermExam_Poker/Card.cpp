#include <iostream>

#include "Card.h"

const char* suitsForShow[SUIT_NUM] = { "SPADE", "DIAMOND", "HEART", "CLUB", };
const char* numsForShow[NUM_NUM] = { "2", "3", "4",  "5",  "6",  "7",  "8",  "9",  "X",  "J",  "Q",  "K",  "A", };


//�R���X�g���N�^
Card::Card()
{
	_num = -1;
	_suit = -1;
}

//�R�s�[�R���X�g���N�^
Card::Card(Card& other)
{
	_num = other._num;
	_suit = other._suit;
}

//�f�X�g���N�^
Card::~Card()
{

}

//�J�[�h����\��
void Card::ShowCard()
{
	printf("%s��%s\n", suitsForShow[_suit], numsForShow[_num]);	//�f�[�^��͂O�`�P�Q�����Q�`A�Ƃ��Ĉ���
	//�f�o�b�O�p
	//printf("[�f�o�b�O�p] suit > %d, num > %d\n", _suit, _num);
}

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include "Player.h"
#include "DetermineHand.h"

using namespace std;

//�R���X�g���N�^
Player::Player(const char* pName)
{
	// ������
	_point[0] = -1;
	_point[1] = -1;

	for (int i = 0; i < HAND_NUM; ++i)
	{
		_hand->SetNum(-1);
		_hand->SetSuit(-1);
	}

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

//�f�X�g���N�^
Player::~Player()
{
	if (_pName == nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
}


//��D�\��
void Player::ShowHand()
{
	//��D���ёւ�
	SortHand();

	printf("������%s������\n", _pName);
	for (int i = 0; i < HAND_NUM; ++i)
	{
		printf("[%d]", i + 1);
		_hand[i].ShowCard();
	}
	printf("\n");
}

//�v���C
void Player::Play(Shoe& shoe)
{
	//5���h���[
	for (int i = 0; i < HAND_NUM; ++i)
	{
		_hand[i] = shoe.TakeCard();
	}

	//��D�\��
	ShowHand();

	int ch = 0;	//���͗p
	while (ch < 1 || ch > 2)
	{
		cout << "�J�[�h���������܂����H\n1.Yes 2.No > " << flush;
		cin >> ch;
		cout << endl;
	}

	if (ch == 1)
	{
		ExchangeCards(shoe);
		ShowHand();
	}

	_point[0] = DetermineHand();
}

//��D����
void Player::ExchangeCards(Shoe& shoe)
{
	int ch = 0;	//���͗p
	for (int i = 0; i < HAND_NUM; ++i)
	{
		ch = 0;
		//�K�؂Ȓl����͂�����
		while (ch < 1 || ch > 2)
		{
			printf("%d�Ԃ̃J�[�h���������܂����H\n1.Yes 2.No > ", i + 1);
			cin >> ch;
		}

		//Yes
		if (ch == 1)
		{
			_hand[i] = shoe.TakeCard();
		}
	}
	//��D�����I��
}

//���̔���
Hand Player::DetermineHand()
{
	//�W�v�̏���
	int countNum[NUM_NUM];		//���������̐����J�E���g
	int countSuit[SUIT_NUM];	//�����}�[�N�̐����J�E���g
	//0�ŏ�����
	fill_n(countNum, NUM_NUM, 0);
	fill_n(countSuit, SUIT_NUM, 0);

	//�W�v
	for (int i = 0; i < HAND_NUM; ++i)
	{
		//��D�̃J�[�h�Ɠ��������Ԗڂ��C���N�������g�i�J�[�h�̐������R�Ȃ�countNum[3]���{�P����j
		++countNum[_hand[i].GetNum()];
		++countSuit[_hand[i].GetSuit()];
	}

	//���̔���ƕ\��
	if (IsRoyalStraightFlush(countNum, countSuit)) {
		printf("[%s�̖�]\n  ���C�����X�g���[�g�t���b�V��\n", GetName());
		return RoyalStraightFlush;
	}

	if (IsStraightFlush(countNum, countSuit)) {
		printf("[%s�̖�]\n  �X�g���[�g�t���b�V��\n", GetName());
		return StraightFlush;
	}

	if (IsFourOfAKind(countNum)) {
		printf("[%s�̖�]\n  �t�H�[�J�[�h\n", GetName());
		return FourOfAKind;
	}

	if (IsHullHouse(countNum)) {
		printf("[%s�̖�]\n  �t���n�E�X\n", GetName());
		return HullHouse;
	}

	if (IsFlush(countSuit)) {
		printf("[%s�̖�]\n  �t���b�V��\n", GetName());
		return Flush;
	}

	if (IsStraight(countNum)) {
		printf("[%s�̖�]\n  �X�g���[�g\n", GetName());
		return Straight;
	}

	if (IsThreeOfAKind(countNum)) {
		printf("[%s�̖�]\n  �X���[�J�[�h\n", GetName());
		return ThreeOfAKind;
	}

	if (IsTwoPair(countNum)) {
		printf("[%s�̖�]\n  �c�[�y�A\n", GetName());
		return TwoPair;
	}

	if (IsOnePair(countNum)) {
		printf("[%s�̖�]\n  �����y�A\n", GetName());
		return OnePair;
	}
	else
	{
		printf("[%s�̖�]\n  �m�[�y�A\n", GetName());
		return No_Hand;
	}
}

//�o�u���\�[�g�i�����j
void Player::SortHand()
{
	for (int i = HAND_NUM - 1; i > 0; --i)
	{
		for(int j = 0; j < i; ++j)
		if (_hand[j] > _hand[j + 1])
		{
			//����ւ�
			Card tempCard = _hand[j];
			_hand[j] = _hand[j + 1];
			_hand[j + 1] = tempCard;
		}
	}
}
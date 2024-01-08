#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include "Player.h"

using namespace std;

//�R���X�g���N�^
Player::Player(const char* pName)
{
	// ������
	/*for (int i = 0; i < MAX_HAND_NUM; ++i)
	{
		_hand->SetNum(-1);
		_hand->SetSuit(-1);
	}*/

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

const char* Player::GetName()const
{
	return _pName;
}

//��D�\��
void Player::ShowHand()
{
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
	}

	if (ch == 1)
	{
		ExchangeCards(shoe);
		ShowHand();
	}

	//�f�o�b�O�p��\��
	//cout << DetermineHand() << endl;
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
int Player::DetermineHand()
{
	//�W�v�̏���
	int countNum[MAX_NUM];		//���������̐����J�E���g
	int countSuit[SUIT_NUM];	//�����}�[�N�̐����J�E���g
	//0�ŏ�����
	fill_n(countNum, MAX_NUM, 0);
	fill_n(countSuit, SUIT_NUM, 0);

	//�W�v
	for (int i = 0; i < HAND_NUM; ++i)
	{
		//��D�̃J�[�h�Ɠ��������Ԗڂ��C���N�������g�i�J�[�h�̐������R�Ȃ�countNum[3]���{�P����j
		++countNum[_hand[i].GetNum()];
		++countSuit[_hand[i].GetSuit()];
	}
	return 0;
}
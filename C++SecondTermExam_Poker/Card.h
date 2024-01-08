#pragma once
#include "Common.h"

using namespace std;

class Card
{
public:
	Card();				//�R���X�g���N�^
	Card(Card& other);	//�R�s�[�R���X�g���N�^
	virtual~Card();		//�f�X�g���N�^
	void ShowCard();	//�\���p

	//������Z�q�̃I�[�o�[���[�h
	Card& operator =(const Card& other)	
	{
		_num = other._num;
		_suit = other._suit;
		return *this;
	}

	//��r���Z�q�̃I�[�o�[���[�h
	bool operator >(const Card& other)
	{
		if (_num > other._num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetNum()const		//�J�[�h�̐����擾
	{
		//�G���[�`�F�b�N
		if (_num < 0 || _num >= NUM_NUM)
		{
			cout << "[�G���[]�����ȃf�[�^�ɃA�N�Z�X���܂����B" << endl;
			return 0;
		}
		return _num;
	}
	int GetSuit()const		//�J�[�h�̃}�[�N�擾
	{
		//�G���[�`�F�b�N
		if (_suit < 0 || _suit >= SUIT_NUM)
		{
			cout << "[�G���[]�����ȃf�[�^�ɃA�N�Z�X���܂����B" << endl;
			return 0;
		}
		return _suit;
	}
	void SetNum(int num)	//�J�[�h�̐�������������
	{
		_num = num;
	}
	void SetSuit(int suit)	//�J�[�h�̃}�[�N����������
	{
		_suit = suit;
	}

private:
	int _num;
	int _suit;
};


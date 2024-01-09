#pragma once

#include "Common.h"

int IsStraightFlush(const int* countNum, const int* countSuit);
int IsStraight(const int* countNum);
int IsFlush(const int* countSuit);

int IsRoyalStraightFlush(const int* countNum, const int* countSuit)
{
	//�X�g���[�g�t���b�V�����ő�l���G�[�X�Ȃ烍�C�����X�g���[�g�t���b�V��
	if (IsStraightFlush(countNum, countSuit) && countNum[NUM_NUM - 1] == 1)
	{
		return true;
	}

	return 	0;
}

int IsStraightFlush(const int* countNum, const int* countSuit)
{
	//�X�g���[�g���t���b�V���Ȃ�X�g���[�g�t���b�V��
	if (IsStraight(countNum) && IsFlush(countSuit))
	{
		return 8;
	}

	return No_Hand;
}

int IsFourOfAKind(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; ++i)
	{
		if (countNum[i] == SUIT_NUM)
		{
			return 7;
		}
	}

	return 0;
}

int IsHullHouse(const int* countNum)
{
	bool twoCard = false;
	bool threeCard = false;

	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 2)
		{
			twoCard = true;
		}
		else if (countNum[i] == 3)
		{
			threeCard = true;
		}
	}

	if (twoCard && threeCard)
	{
		return 6;
	}

	return 0;
}

int IsFlush(const int* countSuit)
{
	for (int i = 0; i < SUIT_NUM; ++i)
	{
		//�����}�[�N�̃J�[�h���T���Ȃ�t���b�V��
		if (countSuit[i] == HAND_NUM)
		{
			return 10;	//�t���b�V�����m�̏��s�͎�D�̍ő�̃J�[�h�Ō��߂�̂ŁA�Ƃ肠����true�̂P��Ԃ�
		}
	}

	return 0;
}

int IsStraight(const int* countNum)
{
	//�P�O�i�f�[�^��͂W�j���傫��������n�܂�X�g���[�g�͑��݂��Ȃ�
	for (int i = 0; i <= NUM_NUM - HAND_NUM; ++i)
	{
		//�P�������Ȃ��J�[�h���������炱���ɓ���
		if (countNum[i] == 1)
		{
			//���̃J�[�h���珇�ԂɂS�����ׂ�
			for (int j = i + 1; j < i + HAND_NUM; ++j)
			{
				if (countNum[j] == 1)
				{
					continue;
				}
				//��ł��P������Ȃ��J�[�h������΃A�E�g
				else
				{
					return 0;
				}
			}
			//�T�������ɕ���ł���΃X�g���[�g
			return i + 1;
		}
	}

	//�����������ꖇ�̃J�[�h���Ȃ���΃A�E�g
	return 0;
}

int IsThreeOfAKind(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 3)
		{
			return i + 1;
		}
	}

	return 0;
}

int IsTwoPair(const int* countNum)
{
	int countPair = 0;

	for (int i = 0; i < NUM_NUM; ++i)
	{
		if (countNum[i] == 2)
		{
			++countPair;
			//�y�A���Q��ڂȂ�c�[�y�A
			if (countPair == 2)
			{
				return i + 1;
			}
		}
	}

	return 0;
}

int IsOnePair(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 2)
		{
			return i + 1;
		}
	}

	return 0;
}
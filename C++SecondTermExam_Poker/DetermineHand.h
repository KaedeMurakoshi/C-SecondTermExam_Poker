#pragma once

#include "Common.h"

bool IsRoyalStraightFlush(const int* countNum, const int* countSuit)
{
	//�X�g���[�g�t���b�V�����ő�l���G�[�X�Ȃ烍�C�����X�g���[�g�t���b�V��
	if (IsStraightFlush(countNum, countSuit) && countNum[NUM_NUM - 1] == 1)
	{
		return true;
	}

	return false;
}

bool IsStraightFlush(const int* countNum, const int* countSuit)
{
	//�X�g���[�g���t���b�V���Ȃ�X�g���[�g�t���b�V��
	if (IsStraight(countNum) && IsFlush(countSuit))
	{
		return true;
	}
}

bool IsFourOfAKind(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; ++i)
	{
		if (countNum[i] == SUIT_NUM)
		{
			return true;
		}
	}

	return false;
}

bool IsHullHouse(const int* countNum)
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
		return true;
	}

	return false;
}

bool IsFlush(const int* countSuit)
{
	for (int i = 0; i < SUIT_NUM; ++i)
	{
		if (countSuit[i] == HAND_NUM)
		{
			return true;
		}
	}

	return false;
}

bool IsStraight(const int* countNum)
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
					return false;
				}
			}
			//�T�������ɕ���ł���΃X�g���[�g
			return true;
		}
	}

	//�����������ꖇ�̃J�[�h���Ȃ���΃A�E�g
	return false;
}

bool IsThreeOfAKind(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 3)
		{
			return true;
		}
	}

	return false;
}

bool IsTwoPair(const int* countNum)
{
	int countPair = 0;

	for (int i = 0; i < NUM_NUM; ++i)
	{
		if (countNum[i] == 2)
		{
			++countPair;
		}
	}

	if (countPair == 2)
	{
		return true;
	}

	return false;
}

bool IsOnePair(const int* countNum)
{
	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 2)
		{
			return true;
		}
	}

	return false;
}
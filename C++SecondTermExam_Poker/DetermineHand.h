#pragma once

#include "Common.h"

bool IsRoyalStraightFlush(const int* countNum, const int* countSuit)
{
	//ストレートフラッシュかつ最大値がエースならロイヤルストレートフラッシュ
	if (IsStraightFlush(countNum, countSuit) && countNum[NUM_NUM - 1] == 1)
	{
		return true;
	}

	return false;
}

bool IsStraightFlush(const int* countNum, const int* countSuit)
{
	//ストレートかつフラッシュならストレートフラッシュ
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
	//１０（データ上は８）より大きい数から始まるストレートは存在しない
	for (int i = 0; i <= NUM_NUM - HAND_NUM; ++i)
	{
		//１枚しかないカードを見つけたらここに入る
		if (countNum[i] == 1)
		{
			//次のカードから順番に４枚調べる
			for (int j = i + 1; j < i + HAND_NUM; ++j)
			{
				if (countNum[j] == 1)
				{
					continue;
				}
				//一個でも１枚じゃないカードがあればアウト
				else
				{
					return false;
				}
			}
			//５枚昇順に並んでいればストレート
			return true;
		}
	}

	//同じ数字が一枚のカードがなければアウト
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
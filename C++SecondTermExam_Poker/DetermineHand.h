#pragma once

#include "Common.h"

int IsStraightFlush(const int* countNum, const int* countSuit);
int IsStraight(const int* countNum);
int IsFlush(const int* countSuit);

int IsRoyalStraightFlush(const int* countNum, const int* countSuit)
{
	//ストレートフラッシュかつ最大値がエースならロイヤルストレートフラッシュ
	if (IsStraightFlush(countNum, countSuit) && countNum[NUM_NUM - 1] == 1)
	{
		return true;
	}

	return 	0;
}

int IsStraightFlush(const int* countNum, const int* countSuit)
{
	//ストレートかつフラッシュならストレートフラッシュ
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
		//同じマークのカードが５枚ならフラッシュ
		if (countSuit[i] == HAND_NUM)
		{
			return 10;	//フラッシュ同士の勝敗は手札の最大のカードで決めるので、とりあえずtrueの１を返す
		}
	}

	return 0;
}

int IsStraight(const int* countNum)
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
					return 0;
				}
			}
			//５枚昇順に並んでいればストレート
			return i + 1;
		}
	}

	//同じ数字が一枚のカードがなければアウト
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
			//ペアが２回目ならツーペア
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
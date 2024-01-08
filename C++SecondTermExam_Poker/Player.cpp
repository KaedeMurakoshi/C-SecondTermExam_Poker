#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include "Player.h"

using namespace std;

//コンストラクタ
Player::Player(const char* pName)
{
	// 初期化
	/*for (int i = 0; i < MAX_HAND_NUM; ++i)
	{
		_hand->SetNum(-1);
		_hand->SetSuit(-1);
	}*/

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

//デストラクタ
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

//手札表示
void Player::ShowHand()
{
	//手札並び替え
	SortHand();

	printf("＝＝＝%s＝＝＝\n", _pName);
	for (int i = 0; i < HAND_NUM; ++i)
	{
		printf("[%d]", i + 1);
		_hand[i].ShowCard();
	}
	printf("\n");
}

//プレイ
void Player::Play(Shoe& shoe)
{
	//5枚ドロー
	for (int i = 0; i < HAND_NUM; ++i)
	{
		_hand[i] = shoe.TakeCard();
	}

	//手札表示
	ShowHand();

	int ch = 0;	//入力用
	while (ch < 1 || ch > 2)
	{
		cout << "カードを交換しますか？\n1.Yes 2.No > " << flush;
		cin >> ch;
	}

	if (ch == 1)
	{
		ExchangeCards(shoe);
		ShowHand();
	}

	//デバッグ用役表示
	cout << DetermineHand() << endl;
}

//手札交換
void Player::ExchangeCards(Shoe& shoe)
{
	int ch = 0;	//入力用
	for (int i = 0; i < HAND_NUM; ++i)
	{
		ch = 0;
		//適切な値を入力させる
		while (ch < 1 || ch > 2)
		{
			printf("%d番のカードを交換しますか？\n1.Yes 2.No > ", i + 1);
			cin >> ch;
		}

		//Yes
		if (ch == 1)
		{
			_hand[i] = shoe.TakeCard();
		}
	}
	//手札交換終了
}

//役の判定
int Player::DetermineHand()
{
	//集計の準備
	int countNum[NUM_NUM];		//同じ数字の数をカウント
	int countSuit[SUIT_NUM];	//同じマークの数をカウント
	//0で初期化
	fill_n(countNum, NUM_NUM, 0);
	fill_n(countSuit, SUIT_NUM, 0);

	//集計
	for (int i = 0; i < HAND_NUM; ++i)
	{
		//手札のカードと同じ数字番目をインクリメント（カードの数字が３ならcountNum[3]を＋１する）
		++countNum[_hand[i].GetNum()];
		++countSuit[_hand[i].GetSuit()];
	}
	return 0;
}

//バブルソート（昇順）
void Player::SortHand()
{
	for (int i = HAND_NUM - 1; i > 0; --i)
	{
		for(int j = 0; j < i; ++j)
		if (_hand[j] > _hand[j + 1])
		{
			//入れ替え
			Card tempCard = _hand[j];
			_hand[j] = _hand[j + 1];
			_hand[j + 1] = tempCard;
		}
	}
}

static bool IsRoyalStraightFlush(const int countNum, const int countSuit)
{
	
}

static bool IsStraightFlush(const int countNum, const int countSuit)
{

}

static bool IsFourOfAKind(const int* countNum)
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

static bool IsHullHouse(const int* countNum)
{
	bool twoCard = false;
	bool threeCard = false;

	for (int i = 0; i < NUM_NUM; i++)
	{
		if (countNum[i] == 2)
		{
			twoCard = true;
		}
		else if(countNum[i] == 3)
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

static bool IsFlush(const int* countSuit)
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

static bool IsStraight(const int* countNum, const int* countSuit)
{

}

static bool IsThreeOfAKind(const int* countNum)
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

static bool IsTwoPair(const int* countNum)
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

static bool IsOnePair(const int* countNum)
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

static bool IsNoHand(const int countNum, const int countSuit)
{

}
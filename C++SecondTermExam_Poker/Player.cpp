#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include "Player.h"
#include "DetermineHand.h"

using namespace std;

//コンストラクタ
Player::Player(const char* pName)
{
	// 初期化
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

//デストラクタ
Player::~Player()
{
	if (_pName == nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
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
		cout << endl;
	}

	if (ch == 1)
	{
		ExchangeCards(shoe);
		ShowHand();
	}

	_point[0] = DetermineHand();
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
Hand Player::DetermineHand()
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

	//役の判定と表示
	if (IsRoyalStraightFlush(countNum, countSuit)) {
		printf("[%sの役]\n  ロイヤルストレートフラッシュ\n", GetName());
		return RoyalStraightFlush;
	}

	if (IsStraightFlush(countNum, countSuit)) {
		printf("[%sの役]\n  ストレートフラッシュ\n", GetName());
		return StraightFlush;
	}

	if (IsFourOfAKind(countNum)) {
		printf("[%sの役]\n  フォーカード\n", GetName());
		return FourOfAKind;
	}

	if (IsHullHouse(countNum)) {
		printf("[%sの役]\n  フルハウス\n", GetName());
		return HullHouse;
	}

	if (IsFlush(countSuit)) {
		printf("[%sの役]\n  フラッシュ\n", GetName());
		return Flush;
	}

	if (IsStraight(countNum)) {
		printf("[%sの役]\n  ストレート\n", GetName());
		return Straight;
	}

	if (IsThreeOfAKind(countNum)) {
		printf("[%sの役]\n  スリーカード\n", GetName());
		return ThreeOfAKind;
	}

	if (IsTwoPair(countNum)) {
		printf("[%sの役]\n  ツーペア\n", GetName());
		return TwoPair;
	}

	if (IsOnePair(countNum)) {
		printf("[%sの役]\n  ワンペア\n", GetName());
		return OnePair;
	}
	else
	{
		printf("[%sの役]\n  ノーペア\n", GetName());
		return No_Hand;
	}
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
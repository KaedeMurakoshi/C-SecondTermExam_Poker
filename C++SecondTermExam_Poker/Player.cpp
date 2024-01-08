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
	//cout << DetermineHand() << endl;
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
	int countNum[MAX_NUM];		//同じ数字の数をカウント
	int countSuit[SUIT_NUM];	//同じマークの数をカウント
	//0で初期化
	fill_n(countNum, MAX_NUM, 0);
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
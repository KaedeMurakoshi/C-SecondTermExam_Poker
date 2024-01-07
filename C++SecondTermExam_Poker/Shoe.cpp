#include <iostream>
#include "Shoe.h"

//コンストラクタ
Shoe::Shoe()
{
	InitShoe();
}

//デストラクタ
Shoe::~Shoe()
{

}

Card Shoe::TakeCard()
{
	// カードの残り枚数が０だったら山札を初期化
	if (_cardNum <= 0)
	{
		InitShoe();
		_cardNum = MAX_CARD_NUM;
	}

	// 山札の後ろから引いていく
	--_cardNum;
	Card card = _cards[_cardNum];

	// デバッグ用
	// 引いたカードに－１を入れる
	_cards[_cardNum].SetNum(-1);
	_cards[_cardNum].SetSuit(-1);

	return card;
}

void Shoe::InitShoe()
{
	// カード枚数初期化
	_cardNum = MAX_CARD_NUM;

	// カード初期化
	for (int i = 0; i < MAX_CARD_NUM; ++i)
	{
		_cards[i].SetNum(i % 13);	//０～１２で初期化
		_cards[i].SetSuit(i % 4);	//０～３で初期化
	}

	// シャッフル
	_Shuffle();
}

//フィッシャーイェーツシャッフル
void Shoe::_Shuffle()
{
	for (int i = MAX_CARD_NUM - 1; i > 0; --i) 
	{
		int a = i;
		int b = rand() % i;

		Card tempCard = _cards[a];
		_cards[a] = _cards[b];
		_cards[b] = tempCard;
	}
}
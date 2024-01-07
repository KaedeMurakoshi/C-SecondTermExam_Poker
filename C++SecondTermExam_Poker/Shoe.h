#pragma once
#include"Common.h"
#include "Card.h"

class Shoe
{
public:
	Shoe();				// コンストラクタ
	virtual ~Shoe();	// デストラクタはvirtualをつける
	Card TakeCard();		// カードを１枚返す	
	
private:
	Card _cards[MAX_CARD_NUM];
	int _cardNum;		// カードが何枚残っているか
	void _Shuffle();	// シャッフル
	void InitShoe();		// 山札の初期化
};


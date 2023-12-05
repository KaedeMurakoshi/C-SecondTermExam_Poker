#pragma once
#include"Common.h"

class Shoe
{
public:
	Shoe();				// コンストラクタ
	virtual ~Shoe();	// デストラクタはvirtualをつける
	int TakeCard();		// カードを１枚返す	

private:
	int _card[CARD_NUM];
	int _cardNum;		// カードが何枚残っているか
	void _Shuffle();	// シャッフル
};


#pragma once

#include "Common.h"
#include "Shoe.h"
#include "Card.h"

class Player
{
public:
	Player(const char* pName);		//コンストラクタ
	virtual ~Player();				//デストラクタ
	void ShowHand();				//手札表示
	void Play(Shoe& shoe);				//プレイ
	Hand DetermineHand();			//役の判定

	const char* GetName()const		//名前表示用
	{
		return _pName;
	}
	const int* GetPoint()const
	{
		return _point;
	}
	
private:
	void ExchangeCards(Shoe& shoe);	//手札交換
	void SortHand();				//手札並び替え

private:
	char* _pName;
	Card _hand[HAND_NUM];	//手札
	int _point[2];			//得点
};


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

	//名前を変えす
	const char* GetName()const		
	{
		return _pName;
	}
	//役の強さを返す
	const int GetPoint()const
	{
		return _point[Point_Of_Hand];
	}
	//同じ役の強弱を決めるためのパワーを返す
	const int GetPower()const
	{
		return _point[Power_Of_Hand];
	}

private:
	void ExchangeCards(Shoe& shoe);	//手札交換
	void SortHand();				//手札並び替え

private:
	char* _pName;
	Card _hand[HAND_NUM];	//手札
	int _point[2];			//得点 (０番目に役の強さ、１番目に同じ役どうしの強さを比較するための数字を入れる)
};


#pragma once
#include "Common.h"

class Card
{
public:
	Card();				//コンストラクタ
	Card(Card& other);	//コピーコンストラクタ
	virtual~Card();		//デストラクタ
	void ShowCard();	//表示用

	Card& operator =(const Card& other)
	{
		_num = other._num;
		_suit = other._suit;
		return *this;
	}

	int GetNum()const		//カードの数字取得
	{
		//エラーチェック
		return _num;
	}
	int GetSuit()const		//カードのマーク取得
	{
		//エラーチェック
		return _suit;
	}
	void SetNum(int num)	//カードの数字を書き込む
	{
		_num = num;
	}
	void SetSuit(int suit)	//カードのマークを書き込む
	{
		_suit = suit;
	}

private:
	int _num;
	int _suit;
};


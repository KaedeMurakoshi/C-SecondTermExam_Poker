#pragma once
#include "Common.h"

using namespace std;

class Card
{
public:
	Card();				//コンストラクタ
	Card(Card& other);	//コピーコンストラクタ
	virtual~Card();		//デストラクタ
	void ShowCard();	//表示用

	//代入演算子のオーバーロード
	Card& operator =(const Card& other)	
	{
		_num = other._num;
		_suit = other._suit;
		return *this;
	}

	//比較演算子のオーバーロード
	bool operator >(const Card& other)
	{
		if (_num > other._num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetNum()const		//カードの数字取得
	{
		//エラーチェック
		if (_num < 0 || _num >= NUM_NUM)
		{
			cout << "[エラー]無効なデータにアクセスしました。" << endl;
			return 0;
		}
		return _num;
	}
	int GetSuit()const		//カードのマーク取得
	{
		//エラーチェック
		if (_suit < 0 || _suit >= SUIT_NUM)
		{
			cout << "[エラー]無効なデータにアクセスしました。" << endl;
			return 0;
		}
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


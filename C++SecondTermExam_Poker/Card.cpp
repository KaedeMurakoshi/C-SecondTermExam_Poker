#include <iostream>

#include "Card.h"

const char* suitsForShow[SUIT_NUM] = { "SPADE", "DIAMOND", "HEART", "CLUB", };
const char* numsForShow[NUM_NUM] = { "2", "3", "4",  "5",  "6",  "7",  "8",  "9",  "X",  "J",  "Q",  "K",  "A", };


//コンストラクタ
Card::Card()
{
	_num = -1;
	_suit = -1;
}

//コピーコンストラクタ
Card::Card(Card& other)
{
	_num = other._num;
	_suit = other._suit;
}

//デストラクタ
Card::~Card()
{

}

//カード情報を表示
void Card::ShowCard()
{
	printf("%sの%s\n", suitsForShow[_suit], numsForShow[_num]);	//データ上は０～１２だが２～Aとして扱う
	//デバッグ用
	//printf("[デバッグ用] suit > %d, num > %d\n", _suit, _num);
}

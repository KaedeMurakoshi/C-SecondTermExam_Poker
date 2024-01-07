

#include <iostream>

#include"Shoe.h"
#include"Player.h"

using namespace std;

int main()
{
	srand(time(NULL));

	printf("＜ルール＞\n・ジョーカーなし\n・手札5枚\n・一回だけ０～５枚のカードを交換可能\n・\n");

	Shoe shoe;

	//デバッグ
	/*for (int i = 0; i < MAX_CARD_NUM; ++i)
	{
		shoe._cards[i].ShowCard();
	}*/
}
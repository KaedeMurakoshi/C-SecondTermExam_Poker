

#include <iostream>

#include"Shoe.h"
#include"Player.h"

using namespace std;

int main()
{
	srand(time(NULL));

	Shoe shoe;

	Player p1("Kaede");
	Player p2("Hosaka");
	Player p3("Tokita");
	Player p4("Sugawara");

	// メンバ変数にポインタがないので値渡しできる
	Player playerList[] = { p1, p2, p3, p4 };

	printf("＜ルール＞\n・ジョーカーなし\n・手札5枚\n・一回だけ０～５枚のカードを交換可能\n・\n");

	playerList[0].Play(shoe);
}
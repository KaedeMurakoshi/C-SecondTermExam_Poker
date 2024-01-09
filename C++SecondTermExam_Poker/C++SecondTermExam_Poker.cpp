

#include <iostream>

#include"Shoe.h"
#include"Player.h"

using namespace std;

//リザルト集計、表示
void Result(Player** pList, const int num)
{
	printf("\n＝＝＝＝＝＝＝＝＝\n　　　Result\n＝＝＝＝＝＝＝＝＝\n");
	int winner = 0;	//勝者の添え字を入れる

	for (int i = 1; i < num; ++i)
	{
		//役の強いほうが勝者
		if (pList[i]->GetPoint() > pList[winner]->GetPoint())
		{
			winner = i;
		}
		else if (pList[i]->GetPoint() == pList[winner]->GetPoint())
		{
			//役が同じだったときは持っているカードの強さで判定する
			if (pList[i]->GetPower() > pList[winner]->GetPower())
			{
				winner = i;
			}
			//役もカードの強さも同じの時は引き分け
			else if(pList[i]->GetPower() == pList[winner]->GetPower())
			{
				printf("%s and %s Draw!\n", pList[winner]->GetName(), pList[i]->GetName());
			}
		}
	}

	printf("\%s Win!\n", pList[winner]->GetName());
}

int main()
{
	srand(time(NULL));

	Shoe shoe;

	//プレイヤー管理用リスト
	Player* playerList[] = { new Player("Kaede"), new Player("Yuki"), new Player("Bayashi"), new Player("Ryohei") };
	//人数
	const int num = sizeof(playerList) / sizeof(Player*);

	printf("＜ルール＞\n・ジョーカーなし\n・手札5枚\n・一回だけ０～５枚のカードを交換可能\n\n");

	for (int i = 0; i < num; ++i)
	{
		playerList[i]->Play(shoe);
	}

	Result(playerList, num);
}
#pragma once

#define MAX_CARD_NUM 52	//山札の数（ジョーカーなし）
#define HAND_NUM 5	//手札の数
#define SUIT_NUM 4	//マークの数
#define NUM_NUM 13	//数字の数

//ポーカーの役
enum Hand
{
	No_Hand,
	OnePair,
	TwoPair,
	ThreeOfAKind,
	Straight,
	Flush,
	HullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalStraightFlush,
};

//得点を入れる配列の、n番目の役割
enum PointArray
{
	Point_Of_Hand,
	Power_Of_Hand,
};
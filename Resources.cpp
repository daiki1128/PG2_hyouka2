#include "Resources.h"
#include "Novice.h"

int graphHandleBackground1;
int graphHandleBackground2;
int graphHandleBackground3;

int graphHandleHp;

//プレイヤー
int graphHandlePlayer[3];
int graphHandlePlayerBullet;

//敵
int graphHandleEnemy[3];
int graphHandleEnemyBullet;

void LoadResources() {

	//背景
	graphHandleBackground1 = Novice::LoadTexture("./Resources/images/backGround.png");
	graphHandleBackground2 = Novice::LoadTexture("./Resources/images/backGround2.png");
	graphHandleBackground3 = Novice::LoadTexture("./Resources/images/backGround3.png");

	graphHandleHp = Novice::LoadTexture("./Resources/images/player/hp.png");

	//プレイヤー
	graphHandlePlayer[0] = Novice::LoadTexture("./Resources/images/player/playerMathine.png");
	graphHandlePlayer[1] = Novice::LoadTexture("./Resources/images/player/playerMathine2.png");
	graphHandlePlayer[2] = Novice::LoadTexture("./Resources/images/player/playerMathine3.png");

	graphHandlePlayerBullet = Novice::LoadTexture("./Resources/images/player/playerBullet.png");

	//敵
	graphHandleEnemy[0] = Novice::LoadTexture("./Resources/images/enemy/enemyMathine.png");
	graphHandleEnemy[1] = Novice::LoadTexture("./Resources/images/enemy/enemyMathine2.png");
	graphHandleEnemy[2] = Novice::LoadTexture("./Resources/images/enemy/enemyMathine3.png");

	graphHandleEnemyBullet = Novice::LoadTexture("./Resources/images/enemy/enemyBullet.png");

}
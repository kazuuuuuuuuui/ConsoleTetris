#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define FEALD_HEIGHT (21)
#define FEALD_WIDTH (12)

//表示用
char buf[FEALD_HEIGHT][FEALD_WIDTH];
char feald[FEALD_HEIGHT][FEALD_WIDTH];

time_t past;
time_t now;

enum{
	Rotate0 = 0,
	Rotate90,
	Rotate180,
	Rotate270,
	RotateMax
};

enum{
	TYPE_O = 0,
	TYPE_I,
	TYPE_invT,
	TYPE_L,
	TYPE_invL,
	TYPE_Z,
	TYPE_invZ
};

//o型
char type_O[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	}

};

//I型
char type_I[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	}

};

//凸型
char type_invT[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	}

};

//L型
char type_L[RotateMax][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	}

};

//逆L型
char type_invL[RotateMax][4][4] = {
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	}

};

//Z型
char type_Z[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	}

};

//逆Z型
char type_invZ[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	}

};

//ブロックのx,yと回転
//curentBlockは現在落下してるBlock
char currentBlock[RotateMax][4][4];
int blockType;
int posX;
int posY;
int rotate;

//ブロック生成
void createBlock(){
	//ランダムでブロックの種類を決定
	blockType = rand() % 7;
	posX = 4;
	posY = 0;
	rotate = 0;

	//現在のブロック初期化
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			for (int u = 0; u < RotateMax; u++){
				currentBlock[u][i][t] = 0;
			}
		}
	}

	switch (blockType){
	case TYPE_O:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_O[u][i][t];
				}
			}
		}
		break;

	case TYPE_I:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_I[u][i][t];
				}
			}
		}
		break;

	case TYPE_invT:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invT[u][i][t];
				}
			}
		}
		break;

	case TYPE_L:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_L[u][i][t];
				}
			}
		}
		break;

	case TYPE_invL:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invL[u][i][t];
				}
			}
		}
		break;

	case TYPE_Z:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_Z[u][i][t];
				}
			}
		}
		break;

	case TYPE_invZ:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invZ[u][i][t];
				}
			}
		}
		break;
	}

}

//フィールドの再描画
void draw(char _bloak[][4][4]){
	system("cls");

	//表示用バッファ初期化
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buf[i][t] = 0;
		}
	}

	//描画用buf更新
	//フィールド情報
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buf[i][t] = feald[i][t];
		}
	}

	//描画用buf更新
	//ブロック
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			buf[i + posY][t + posX] = (buf[i + posY][t + posX]) | (_bloak[rotate][i][t]);
		}
	}

	//描画
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			if (buf[i][t] == 0){
				printf("□");
			}
			else if (buf[i][t] == 1){
				printf("■");
			}
		}
		printf("\n");
	}

	printf("\n");
	printf("%d\n", posY);
}

//当たり判定
bool isHit(char _bloak[][4][4], int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			if (_bloak[_rotate][i][t] && feald[_y + i][_x + t]){
				return true;
			}
			else{

			}
		}
	}
	return false;
}

//ブロック固定
void lockBlock(char _bloak[][4][4], int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			feald[_y + i][_x + t] = (feald[_y + i][_x + t]) | (_bloak[_rotate][i][t]);
		}
	}

	//新しいブロックを生成
	createBlock();
}

void main(){

	//表示用バッファ初期化
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buf[i][t] = 0;
		}
	}

	//フィールド初期化
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			feald[i][t] = 0;
		}
	}

	//壁登録
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			feald[i][0] = 1;
			feald[i][11] = 1;
			feald[20][t] = 1;
		}
	}

	//最初の1個目ブロック生成
	createBlock();

	//最初の描画
	draw(currentBlock);

	/////

	now = time(NULL);
	while (1){
		//経過時間
		past = now;
		now = time(NULL);

		//自由落下処理
		if (past != now){
			if (isHit(currentBlock, posX, posY + 1, rotate)){
				lockBlock(currentBlock, posX, posY, rotate);
			}
			else{
				posY++;
			}
			draw(currentBlock);
		}



		//printf("%d\n", timer);

		//操作
		//キー入力
		if (_kbhit() != 0){
			unsigned char c = _getch();
			switch (c){
			case 'a':
				if (isHit(currentBlock, posX, posY, rotate + 1)){

				}
				else{
					rotate++;
				}

				rotate = rotate%RotateMax;
				break;

			case 0xe0:
				switch (_getch()){
				case 0x50:
					if (isHit(currentBlock, posX, posY + 1, rotate)){
						//下に行けない
						lockBlock(currentBlock, posX, posY, rotate);
					}
					else{
						posY++;
					}
					break;

				case 0x4b:
					if (isHit(currentBlock, posX - 1, posY, rotate)){

					}
					else{
						posX--;
					}
					break;

				case 0x4d:
					if (isHit(currentBlock, posX + 1, posY, rotate)){

					}
					else{
						posX++;
					}
					break;
				}
				break;
			default:
				break;

			}
			draw(currentBlock);
		}
	}
}
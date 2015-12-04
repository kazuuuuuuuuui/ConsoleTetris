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

//o型
char o[RotateMax][4][4] = {
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
char I[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	}

};

//凸型
char invT[RotateMax][4][4] = {
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
char L[RotateMax][4][4] = {
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
char invL[RotateMax][4][4] = {
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
char z[RotateMax][4][4] = {
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
char invZ[RotateMax][4][4] = {
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


//ブロックのx,y
int posX = 4;
int posY = 0;
int rotate = 0;

//フィールドの再描画
void draw(){
	system("cls");

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
			buf[i + posY][t + posX] += invT[rotate][i][t];
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
}

bool isHit(int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			if (invT[_rotate][i][t] && feald[_y + i][_x + t]){
				return true;
			}
			else{

			}
		}
	}
	return false;
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

	//最初の描画
	draw();

	/////

	now = time(NULL);
	while (1){
		//経過時間
		past = now;
		now = time(NULL);
		if (past != now){
			if (isHit(posX, posY + 1, rotate)){

			}
			else{
				posY++;
			}
			draw();
		}
		//printf("%d\n", timer);

		//操作
		//キー入力
		if (_kbhit() != 0){
			unsigned char c = _getch();
			switch (c){
			case 'a':
				if (isHit(posX, posY, rotate + 1)){

				}
				else{
					rotate++;
				}

				rotate = rotate%RotateMax;
				break;

			case 0xe0:
				switch (_getch()){
				case 0x50:
					if (isHit(posX, posY + 1, rotate)){

					}
					else{
						posY++;
					}
					break;

				case 0x4b:
					if (isHit(posX - 1, posY, rotate)){

					}
					else{
						posX--;
					}
					break;

				case 0x4d:
					if (isHit(posX + 1, posY, rotate)){

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
			draw();
		}
	}
}
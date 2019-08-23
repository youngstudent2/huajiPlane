#include "Draw.h"
#define WORD_SIZE 8
Draw::Draw() {	
	settextstyle(WORD_SIZE, WORD_SIZE, _T("Courier"));
	s = new TCHAR*[GAME_X];
	for (int i = 0; i < GAME_X; i++) {		
		s[i] = new TCHAR[GAME_Y + 1];
	}
	clear();
}

Draw::~Draw()
{
	for (int i = 0; i < GAME_X; i++) {
		delete s[i];
	}
	
}
void Draw::gotoxy(int x, int y) {
	COORD pos;
	HANDLE hOutput;
	pos.X = y;
	pos.Y = x;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void Draw::clear() {
	for (int i = 0; i < GAME_X; i++) {
		memset(s[i], 0x20, sizeof(char)*GAME_Y);
		s[i][GAME_Y] = '\0';
	}
}

void Draw::draw_out() {
	//gotoxy(1, 1);
	//printf("%s", s[0]);
//	outtextxy(1, 1, s[0]);

	for (int i = 1; i < GAME_X; i++) {
		//printf("\n%s", s[i]);
//		outtextxy(i * (WORD_SIZE+4) + 1, 1, s[i]);
	}
	clear();
}

void Draw::draw_rect(int x, int y, int width, int height) {
	rectangle(y, x, y + width* WORD_SIZE, x + height* WORD_SIZE);
}

void Draw::prepareImg(int x, int y, Image& img) {
	int i = x;
	int j;
	for (auto& str : img) {
		j = y;
		for (auto& c : str) {
			if(c!='0')
				if (i >= 0 && i < GAME_X&&j >= 0 && j < GAME_Y) {
					s[i][j] = c;
				}			
			++j;
		}
		++i;
	}
}

void Draw::prepareBulletMap(BulletMap * bp, Image & img)
{

	for (int i = 0; i < GAME_X; i++) {
		for (int j = 0; j < GAME_Y; j++) {
			if(bp->bullet_map[i][j])
				prepareImg(i, j, img);
		}
	}
}

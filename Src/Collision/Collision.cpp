#include "Collision.h"

//IsHitRect�̒�`
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh)
{
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	return false;
}

//IsHitCircle�̒�`
bool IsHitCircle(int X1, int Y1, int R1, int X2, int Y2, int R2)
{
	if ((R1 + R2) * (R1 + R2) > (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2))
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	return false;
}

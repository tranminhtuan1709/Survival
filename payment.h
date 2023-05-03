#pragma once
#ifndef payment_h_
#define payment_h_

#include "initGame.h"
#include "font.h"

class PaymentWindow
{
public:
	vector <vector <SDL_Texture*>> paymentFrame;
	vector <SDL_Rect> paymentPosition;
	string fullName;
	string value;
	string thanksSentence;
	int bank{};
	bool checkInputName{};
	bool checkInputValue{};
	bool checkPay{};
	bool checkOutOfRange{};
	bool checkUpdateThanksSentence{};
	void initData(SDL_Renderer* render, Font& font);
};


#endif payment_h_
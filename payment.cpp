#include "payment.h"
#include "enum.h"
void PaymentWindow::initData(SDL_Renderer* render, Font& font)
{
	vector <SDL_Texture*> tempText;
	for (int i = 0; i < ALLPAY; i++)
	{
		paymentFrame.push_back(tempText);
		paymentPosition.push_back({ 0, 0, 0, 0 });
	}
	paymentPosition[PAY_WINDOW] = { PAY_WINDOW_X, PAY_WINDOW_Y, PAY_WINDOW_WIDTH, PAY_WINDOW_HEIGHT };
	paymentPosition[PAY_QUITWINDOW] = { PAY_QUITWINDOW_X, PAY_QUITWINDOW_Y, PAY_QUITWINDOW_WIDTH, PAY_QUITWINDOW_HEIGHT };
	paymentPosition[PAY_QUITRESULT] = { PAY_QUITRESULT_X, PAY_QUITRESULT_Y, PAY_QUITRESULT_WIDTH, PAY_QUITRESULT_HEIGHT };
	paymentPosition[PAY_TITLE] = { PAY_TITLE_X, PAY_TITLE_Y, PAY_TITLE_WIDTH, PAY_TITLE_HEIGHT };
	paymentPosition[PAY_QR] = { PAY_QR_X, PAY_QR_Y, PAY_QR_WIDTH, PAY_QR_HEIGHT };
	paymentPosition[PAY_CIRCLE1] = { PAY_CIRCLE1_X, PAY_CIRCLE1_Y, PAY_CIRCLE1_WIDTH, PAY_CIRCLE1_HEIGHT };
	paymentPosition[PAY_CIRCLE2] = { PAY_CIRCLE2_X, PAY_CIRCLE2_Y, PAY_CIRCLE2_WIDTH, PAY_CIRCLE2_HEIGHT };
	paymentPosition[PAY_CIRCLE3] = { PAY_CIRCLE3_X, PAY_CIRCLE3_Y, PAY_CIRCLE3_WIDTH, PAY_CIRCLE3_HEIGHT };
	paymentPosition[PAY_CIRCLE4] = { PAY_CIRCLE4_X, PAY_CIRCLE4_Y, PAY_CIRCLE4_WIDTH, PAY_CIRCLE4_HEIGHT };
	paymentPosition[PAY_GREENTICK] = { PAY_GREENTICK_X, PAY_GREENTICK_Y, PAY_GREENTICK_WIDTH, PAY_GREENTICK_HEIGHT };
	paymentPosition[PAY_BIDV] = { PAY_BIDV_X, PAY_BIDV_Y, PAY_BIDV_WIDTH, PAY_BIDV_HEIGHT };
	paymentPosition[PAY_TPBANK] = { PAY_TPBANK_X, PAY_TPBANK_Y, PAY_TPBANK_WIDTH, PAY_TPBANK_HEIGHT };
	paymentPosition[PAY_MOMO] = { PAY_MOMO_X, PAY_MOMO_Y, PAY_MOMO_WIDTH, PAY_MOMO_HEIGHT };
	paymentPosition[PAY_VIETTELPAY] = { PAY_VIETTELPAY_X, PAY_VIETTELPAY_Y, PAY_VIETTELPAY_WIDTH, PAY_VIETTELPAY_HEIGHT };
	paymentPosition[PAY_OK] = { PAY_OK_X, PAY_OK_Y, PAY_OK_WIDTH, PAY_OK_HEIGHT };
	paymentPosition[PAY_SALE] = { PAY_SALE_X, PAY_SALE_Y, PAY_SALE_WIDTH, PAY_SALE_HEIGHT };
	paymentPosition[PAY_ENTER_NAME] = { PAY_ENTER_NAME_X, PAY_ENTER_NAME_Y, PAY_ENTER_NAME_WIDTH, PAY_ENTER_NAME_HEIGHT };
	paymentPosition[PAY_BOX_NAME] = { PAY_BOX_NAME_X, PAY_BOX_NAME_Y, PAY_BOX_NAME_WIDTH, PAY_BOX_NAME_HEIGHT };
	paymentPosition[PAY_NAME_WORD] = { PAY_NAME_WORD_X, PAY_NAME_WORD_Y, PAY_NAME_WORD_WIDTH, PAY_NAME_WORD_HEIGHT };
	paymentPosition[PAY_ENTER_VALUE] = { PAY_ENTER_VALUE_X, PAY_ENTER_VALUE_Y, PAY_ENTER_VALUE_WIDTH, PAY_ENTER_VALUE_HEIGHT };
	paymentPosition[PAY_BOX_VALUE] = { PAY_BOX_VALUE_X, PAY_BOX_VALUE_Y, PAY_BOX_VALUE_WIDTH, PAY_BOX_VALUE_HEIGHT };
	paymentPosition[PAY_VALUE_WORD] = { PAY_VALUE_WORD_X, PAY_VALUE_WORD_Y, PAY_VALUE_WORD_WIDTH, PAY_VALUE_WORD_HEIGHT };
	paymentPosition[PAY_BOX_RESULT] = { PAY_BOX_RESULT_X, PAY_BOX_RESULT_Y, PAY_BOX_RESULT_WIDTH, PAY_BOX_RESULT_HEIGHT };
	paymentPosition[PAY_RESULT_WORD] = { PAY_RESULT_WORD_X, PAY_RESULT_WORD_Y, PAY_RESULT_WORD_WIDTH, PAY_RESULT_WORD_HEIGHT };
	paymentPosition[PAY_CHOOSE_BANK] = { PAY_CHOOSE_BANK_X, PAY_CHOOSE_BANK_Y, PAY_CHOOSE_BANK_WIDTH, PAY_CHOOSE_BANK_HEIGHT };
	loadImage(paymentFrame[PAY_WINDOW], "Image/Menu/window", 1, render);
	loadImage(paymentFrame[PAY_QUITWINDOW], "Image/Menu/quit", 2, render);
	loadImage(paymentFrame[PAY_QUITRESULT], "Image/Menu/quit", 2, render);
	paymentFrame[PAY_TITLE].push_back(createTextureFromFont(font.villa, "PAYMENT", font.allColor[COLOR_WHITE], render));
	loadImage(paymentFrame[PAY_QR], "Image/Menu/Payment/QR code", 1, render);
	loadImage(paymentFrame[PAY_CIRCLE1], "Image/Menu/Payment/circle", 1, render);
	loadImage(paymentFrame[PAY_CIRCLE2], "Image/Menu/Payment/circle", 1, render);
	loadImage(paymentFrame[PAY_CIRCLE3], "Image/Menu/Payment/circle", 1, render);
	loadImage(paymentFrame[PAY_CIRCLE4], "Image/Menu/Payment/circle", 1, render);
	loadImage(paymentFrame[PAY_GREENTICK], "Image/Menu/Payment/greentick", 1, render);
	loadImage(paymentFrame[PAY_BIDV], "Image/Menu/Payment/bidv", 1, render);
	loadImage(paymentFrame[PAY_TPBANK], "Image/Menu/Payment/tp bank", 1, render);
	loadImage(paymentFrame[PAY_MOMO], "Image/Menu/Payment/momo", 1, render);
	loadImage(paymentFrame[PAY_VIETTELPAY], "Image/Menu/Payment/viettel pay", 1, render);
	loadImage(paymentFrame[PAY_OK], "Image/Menu/Payment/ok", 2, render);
	loadImage(paymentFrame[PAY_SALE], "Image/Menu/Payment/sale", 1, render);
	paymentFrame[PAY_ENTER_NAME].push_back(createTextureFromFont(font.zag, "Enter your name", font.allColor[COLOR_BLACK], render)); 
	loadImage(paymentFrame[PAY_BOX_NAME], "Image/Menu/Payment/box", 2, render);
	paymentFrame[PAY_NAME_WORD].push_back(createTextureFromFont(font.zag, "", font.allColor[COLOR_BLACK], render));
	paymentFrame[PAY_ENTER_VALUE].push_back(createTextureFromFont(font.zag, "Enter the amount you want to pay", font.allColor[COLOR_BLACK], render));
	loadImage(paymentFrame[PAY_BOX_VALUE], "Image/Menu/Payment/box", 2, render);
	paymentFrame[PAY_VALUE_WORD].push_back(createTextureFromFont(font.zag, "", font.allColor[COLOR_BLACK], render));
	loadImage(paymentFrame[PAY_BOX_RESULT], "Image/Menu/Payment/box", 2, render);
	paymentFrame[PAY_RESULT_WORD].push_back(createTextureFromFont(font.zag, "", font.allColor[COLOR_BLACK], render));
	paymentFrame[PAY_CHOOSE_BANK].push_back(createTextureFromFont(font.zag, "Select a payment method", font.allColor[COLOR_BLACK], render));
	fullName = "";
	value = "";
	thanksSentence = "Thanks you for supporting me \"";
	bank = -1;
	checkInputName = false;
	checkInputValue = false;
	checkPay = false;
	checkOutOfRange = false;
	checkUpdateThanksSentence = false;
}
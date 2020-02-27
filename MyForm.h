#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include<math.h>
float BuyCall[15] = {820,740,630,550,470,397,307,235,173,120,79,48.5,15.5,4.1,1};
float SellCall[15] = {835,740,645,550,470,397,307,235,174,121,81,49,16.5,4.2,2};
float BuyPut[15] = {8.6,12,17,26,38.5,55,78,109,148,195,250,323,493,650,825};
float SellPut[15] = {9.1,12.5,18,27,39.5,56,79,110,149,196,258,332,505,665,855};
float X[15] = {6900,7000,7100,7200,7300,7400,7500,7600,7700,7800,7900,8000,8200,8400,8600};
int buyTAIEX = 7757;
int sellTAIEX = 7758;
int FutureBuy = 7756;
int FutureSll = 7760;
float r = 0.01844;
float T = 0.083;
float e= 2.71828;
namespace CppWinForm8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(597, 538);
			this->panel1->TabIndex = 0;
			this->panel1->BackgroundImageLayoutChanged += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(624, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Arbitrage";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(624, 57);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(790, 64);
			this->listBox1->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 15;
			this->listBox2->Location = System::Drawing::Point(624, 139);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(790, 64);
			this->listBox2->TabIndex = 3;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 15;
			this->listBox3->Location = System::Drawing::Point(624, 221);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(790, 64);
			this->listBox3->TabIndex = 4;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 15;
			this->listBox4->Location = System::Drawing::Point(624, 305);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(790, 64);
			this->listBox4->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1450, 610);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		float max(float a, float b) {
			if (a > b) {
				return a;
			}
			else
				return b;
		}


		void th4(float* C, float S, float* X) {
			for (int i = 0; i < 15; i++) {
				float tmp = S-X[i]*pow(e,-1*r*T);
				if (C[i]+3 < max(tmp, 0)) {
					listBox1->Items->Add("There is a arbitrage opportunity at"+X[i]+", buy 1 call,1 zero coupon bond and sell 1 stock, your profit= X-St");
				
				}
				else {
					listBox1->Items->Add("thrr is no arbitrage opportunity at " + X[i] + "");
				}
			}
		}
		void th6(float*P, float S,float* X ) {
			for (int i = 0; i < 15; i++) {
				float tmp = X[i] * pow(e, -1 * r*T)-S;
				if (P[i] + 3 < max(tmp, 0)) {
					listBox2->Items->Add("There is a arbitrage opportunity at" + X[i] + ", sell 1 put, buy 1 zero coupon bond and sell 1 stock, your profit= St-X");

				}
				else {
					listBox2->Items->Add("thrr is no arbitrage opportunity at " + X[i] + "");
				}
			}
		}
		void th8ForCall(float* X, float* sellcall, float* buycall) {
			//若call price>wcx1+(1-w)cx3 則賣x2 call 買x1,x3call 
			for (int i = 0; i < 15; i++)
			{
				float w = i / 15;
				if (sellcall[i]-3 > w*buycall[0] + (1 - w)*buycall[14]) {
					listBox3->Items->Add("There is a arbitrage opportunity, sell 1 call at" + X[i] + ", buy 1 call with X=820 and 1 call with x=1");
				}
				else
				{
					listBox3->Items->Add("thrr is no arbitrage opportunity at " + X[i] + "");
				}
			}
		}
		void th8ForPut(float* X, float* sellput, float* buyput) {
			//若call price>wcx1+(1-w)cx3 則賣x2 call 買x1,x3call 
			for (int i = 0; i < 15; i++)
			{
				float w = i / 15;
				if (sellput[i]-3 > w*buyput[0] + (1 - w)*buyput[14]) {
					listBox3->Items->Add("There is a arbitrage opportunity, sell 1 put at" + X[i] + ", buy 1 put with X=8 and 1 put with X=825");
				}
				else
				{
					listBox3->Items->Add("there is no arbitrage opportunity at "+X[i]+"");
				}
			}
		}
		void thmfuture(float T, float r, float* sellcall, float* buyput, float buyfuture,float* X) {
			for (int i = 0; i < 15; i++) {
				float deposit = buyput[i] - sellcall[i];
				float tmp = (buyput[i] - sellcall[i])*pow(e, -r*T);
				if (tmp>buyfuture-X[i]) {
					listBox4->Items->Add("There is a arbitrage opportunity, sell 1 call and buy 1 put at" + X[i] + ", buy a future, and deposit "+ deposit+"");
				}
			}
		}
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		th4(BuyCall, sellTAIEX, X);
		th6(SellPut, sellTAIEX, X);
		th8ForCall(X,SellCall,BuyCall);
		th8ForPut(X, SellPut, BuyPut);
		thmfuture(T, r, SellCall, BuyPut, FutureBuy, X);
	}
	};
}
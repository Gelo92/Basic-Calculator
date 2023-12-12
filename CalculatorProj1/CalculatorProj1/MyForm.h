//Computer Methods 3 Calculator Project Group 9
#pragma once
#include <cmath>
#include <iostream>


//Lungelo Zondi (218005716)
template<typename T>
class Calculator		//Calculator Base class
{
protected:
	//  to take two user input numbers firstDigit and secondDigit and store operations in variable result
	T firstDigit, secondDigit, result;
public:
	String^ operators; //variable for function operators to be performed

	Button^ Numbers = safe_cast<Button^>(sender); //button set-up
	if (txtDisplay->Text == "0") //if statement to check if textbox is empty if so replace with number inserted by user
	{
		txtDisplay->Text = Numbers->Text;//display number entered by user
	}
	else
	{
		txtDisplay->Text = txtDisplay->Text + Numbers->Text;
		Button^ NumbersOp = safe_cast<Button^>(sender);
		firstDigit = Double::Parse(txtDisplay->Text);
		txtDisplay->Text = "";
		operators = NumbersOp->Text;
	}


	if (btnClear_Click == true) //btnClear clear all, everything in the textbox and leaves zero "0"   //Angel Mbokazi (218060084)
	{
		txtDisplay->Text = "0";

	}

	if (btnClearEntry_Click == true) //btnClear clear  the textbox and leaves zero "0"			//Lungelo Zondi (218005716)
	{
		txtDisplay->Text = "0";
	}

	if (btnAns_Click == true)//btnAns returns previous answer regardless if clear or clear all is pressed  //Angel Mbokazi (218060084)
	{
		txtDisplay->Text = System::Convert::ToString(result);
	}


};


//Lungelo Zondi (218005716)
template<typename T> 
class Commas : public Calculator //class Commas insertes comma in the textbox
{
public:
	if (!txtDisplay->Text->Contains(","))
	{
		txtDisplay->Text = txtDisplay->Text + ",";

	}

};


//Angel Mbokazi (218060084)
template<typename T> 
class Addition : public Calculator//responsible for adding two values inserted by user
{
public:
	if (operators == "+")//first checks if this is the "+" operator
	{
		secondDigit = Double::Parse(txtDisplay->Text);
		result = firstDigit + secondDigit;//adds first and second digit
		txtDisplay->Text = System::Convert::ToString(firstDigit) + " " + System::Convert::ToString(operators) + " " + System::Convert::ToString(secondDigit) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);
	}

};


//Sthabiso Mqadi (218056725)
template<typename T> 
class Subtraction : public Calculator//responsible for subtraction of numbers
{
public:
	if (operators == "-")//checks if this is the "-" operator
	{
		secondDigit = Double::Parse(txtDisplay->Text);
		result = firstDigit - secondDigit;//performs subtraction operation
		txtDisplay->Text = System::Convert::ToString(firstDigit) + " " + System::Convert::ToString(operators) + " " + System::Convert::ToString(secondDigit) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);
	}

};


//Angel Mbokazi ((218060084))
template<typename T> 
class Division : public Calculator//responsible for division operation
{
public:
	if (operators == "÷")//check if this is the "÷" opearator
	{
		secondDigit = Double::Parse(txtDisplay->Text);
		result = firstDigit / secondDigit;//perfoms and stores subtraction operation
		txtDisplay->Text = System::Convert::ToString(firstDigit) + " " + System::Convert::ToString(operators) + " " + System::Convert::ToString(secondDigit) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);
	}
};


//Lungelo Zondi (218005716)
template<typename T> 
class Multiplication : public Calculator//responsible for multiplication operation
{
public:
	if (operators == "x")//check if this is the "x" opearator
	{
		secondDigit = Double::Parse(txtDisplay->Text);
		result = firstDigit * secondDigit;//perfoms and stores subtraction operation
		txtDisplay->Text = System::Convert::ToString(firstDigit) + " " + System::Convert::ToString(operators) + " " + System::Convert::ToString(secondDigit) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);

	}
};



//Sthabiso Mqadi (218056725)
template<typename T> 
class Root : public Calculator //responsible for performing inverse operation
{
public:
	if (operators == "Root")
	{
		result = sqrt(firstDigit);
		txtDisplay->Text = System::Convert::ToString("Root") + System::Convert::ToString("(") + System::Convert::ToString(firstDigit) + System::Convert::ToString(")") + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);
	}
};



//Angel Mbokazi (218060084)
template<typename T> 
class Power : public Calculator //responsible for the power operation
{
public:
	if (operators == "^")
	{
		secondDigit = Double::Parse(txtDisplay->Text);
		result = pow(firstDigit, secondDigit);
		txtDisplay->Text = System::Convert::ToString(firstDigit) + " " + System::Convert::ToString(operators) + " " + System::Convert::ToString(secondDigit) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);
	}

};





//Lungelo Zondi (218005716)
template<typename T> 
class Factorial : public Calculator //responsible for performing factorial operation
{
	if (operators == "!")
	{

		double factorial = 1.0;
		String^ error;
		if (firstDigit < 0)
		{
			error = "NaN";
			result = error;

		}
		else
			for (int i = 1; i <= firstDigit; ++i) {
				factorial *= i;
			}
		result = factorial;

		txtDisplay->Text = System::Convert::ToString(firstDigit) + "" + System::Convert::ToString(operators) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);

	}
};



//Lungelo Zondi (218005716)
template<typename T> 
class Percentage : public Calculator //responsible for performing percentage operation
{
public:
	if (operators == "%") //checks if button pressed contains the "%" operator
	{

		result = firstDigit / 100; //divides firstDigit by 100 to get percentage
		txtDisplay->Text = System::Convert::ToString(firstDigit) + "" + System::Convert::ToString(operators) + " " + System::Convert::ToString("=") + " " + System::Convert::ToString(result);

	}
};



//Lungelo Zondi (218005716)
template<typename> 
class SpaceButton : public Calculator //responsible for backspace operation
{
public:
	if (txtDisplay->Text->Length > 0)//checks if textbox value is greater than 0
	{
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);//if so delete moving one step back
	}

	if (txtDisplay->Text == "")//if theres nothing on the textbox siplay "0"
	{
		txtDisplay->Text = "0";
	}
};



//Sthabiso Mqadi (218056725)
template<typename T> 
class NegativeNumber : public Calculator //respobsible for inserting a negative sign 
{
public:
	if (txtDisplay->Text->Contains("-"))//checks if button pressed contains "-" operator
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0, 1);//
	}
	else
	{
		txtDisplay->Text = "-" + txtDisplay->Text;//
	}
};


namespace CalculatorProj1 {

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
	private: System::Windows::Forms::Button^ btnSpace;
	protected:
	private: System::Windows::Forms::TextBox^ txtDisplay;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnClearEntry;
	private: System::Windows::Forms::Button^ btnPlusMinus;



	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ btnDigit9;
	private: System::Windows::Forms::Button^ btnDigit8;
	private: System::Windows::Forms::Button^ btnDigit7;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ btnDigit6;
	private: System::Windows::Forms::Button^ btnDigit5;
	private: System::Windows::Forms::Button^ btnDigit4;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ btnDigit3;
	private: System::Windows::Forms::Button^ btnDigit2;
	private: System::Windows::Forms::Button^ btnDigit1;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ btnEquals;

	private: System::Windows::Forms::Button^ btnDecimal;

	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ btnAns;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnSpace = (gcnew System::Windows::Forms::Button());
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnClearEntry = (gcnew System::Windows::Forms::Button());
			this->btnPlusMinus = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->btnDigit9 = (gcnew System::Windows::Forms::Button());
			this->btnDigit8 = (gcnew System::Windows::Forms::Button());
			this->btnDigit7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->btnDigit6 = (gcnew System::Windows::Forms::Button());
			this->btnDigit5 = (gcnew System::Windows::Forms::Button());
			this->btnDigit4 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->btnDigit3 = (gcnew System::Windows::Forms::Button());
			this->btnDigit2 = (gcnew System::Windows::Forms::Button());
			this->btnDigit1 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->btnEquals = (gcnew System::Windows::Forms::Button());
			this->btnDecimal = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->btnAns = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnSpace
			// 
			this->btnSpace->Font = (gcnew System::Drawing::Font(L"Wingdings", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btnSpace->Location = System::Drawing::Point(33, 98);
			this->btnSpace->Name = L"btnSpace";
			this->btnSpace->Size = System::Drawing::Size(75, 57);
			this->btnSpace->TabIndex = 0;
			this->btnSpace->Text = L"";
			this->btnSpace->UseVisualStyleBackColor = true;
			this->btnSpace->Click += gcnew System::EventHandler(this, &MyForm::btnSpace_Click);
			// 
			// txtDisplay
			// 
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDisplay->Location = System::Drawing::Point(33, 34);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(399, 48);
			this->txtDisplay->TabIndex = 1;
			this->txtDisplay->Text = L"0";
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(114, 98);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 57);
			this->btnClear->TabIndex = 2;
			this->btnClear->Text = L"C";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// btnClearEntry
			// 
			this->btnClearEntry->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClearEntry->Location = System::Drawing::Point(195, 98);
			this->btnClearEntry->Name = L"btnClearEntry";
			this->btnClearEntry->Size = System::Drawing::Size(75, 57);
			this->btnClearEntry->TabIndex = 3;
			this->btnClearEntry->Text = L"CE";
			this->btnClearEntry->UseVisualStyleBackColor = true;
			this->btnClearEntry->Click += gcnew System::EventHandler(this, &MyForm::btnClearEntry_Click);
			// 
			// btnPlusMinus
			// 
			this->btnPlusMinus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlusMinus->Location = System::Drawing::Point(276, 98);
			this->btnPlusMinus->Name = L"btnPlusMinus";
			this->btnPlusMinus->Size = System::Drawing::Size(75, 57);
			this->btnPlusMinus->TabIndex = 4;
			this->btnPlusMinus->Text = L"±";
			this->btnPlusMinus->UseVisualStyleBackColor = true;
			this->btnPlusMinus->Click += gcnew System::EventHandler(this, &MyForm::btnPlusMinus_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(276, 161);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 57);
			this->button5->TabIndex = 8;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// btnDigit9
			// 
			this->btnDigit9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit9->Location = System::Drawing::Point(195, 161);
			this->btnDigit9->Name = L"btnDigit9";
			this->btnDigit9->Size = System::Drawing::Size(75, 57);
			this->btnDigit9->TabIndex = 7;
			this->btnDigit9->Text = L"9";
			this->btnDigit9->UseVisualStyleBackColor = true;
			this->btnDigit9->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit8
			// 
			this->btnDigit8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit8->Location = System::Drawing::Point(114, 161);
			this->btnDigit8->Name = L"btnDigit8";
			this->btnDigit8->Size = System::Drawing::Size(75, 57);
			this->btnDigit8->TabIndex = 6;
			this->btnDigit8->Text = L"8";
			this->btnDigit8->UseVisualStyleBackColor = true;
			this->btnDigit8->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit7
			// 
			this->btnDigit7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit7->Location = System::Drawing::Point(33, 161);
			this->btnDigit7->Name = L"btnDigit7";
			this->btnDigit7->Size = System::Drawing::Size(75, 57);
			this->btnDigit7->TabIndex = 5;
			this->btnDigit7->Text = L"7";
			this->btnDigit7->UseVisualStyleBackColor = true;
			this->btnDigit7->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(276, 224);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 57);
			this->button9->TabIndex = 12;
			this->button9->Text = L"-";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// btnDigit6
			// 
			this->btnDigit6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit6->Location = System::Drawing::Point(195, 224);
			this->btnDigit6->Name = L"btnDigit6";
			this->btnDigit6->Size = System::Drawing::Size(75, 57);
			this->btnDigit6->TabIndex = 11;
			this->btnDigit6->Text = L"6";
			this->btnDigit6->UseVisualStyleBackColor = true;
			this->btnDigit6->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit5
			// 
			this->btnDigit5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit5->Location = System::Drawing::Point(114, 224);
			this->btnDigit5->Name = L"btnDigit5";
			this->btnDigit5->Size = System::Drawing::Size(75, 57);
			this->btnDigit5->TabIndex = 10;
			this->btnDigit5->Text = L"5";
			this->btnDigit5->UseVisualStyleBackColor = true;
			this->btnDigit5->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit4
			// 
			this->btnDigit4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit4->Location = System::Drawing::Point(33, 224);
			this->btnDigit4->Name = L"btnDigit4";
			this->btnDigit4->Size = System::Drawing::Size(75, 57);
			this->btnDigit4->TabIndex = 9;
			this->btnDigit4->Text = L"4";
			this->btnDigit4->UseVisualStyleBackColor = true;
			this->btnDigit4->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(276, 287);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 57);
			this->button13->TabIndex = 16;
			this->button13->Text = L"x";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// btnDigit3
			// 
			this->btnDigit3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit3->Location = System::Drawing::Point(195, 287);
			this->btnDigit3->Name = L"btnDigit3";
			this->btnDigit3->Size = System::Drawing::Size(75, 57);
			this->btnDigit3->TabIndex = 15;
			this->btnDigit3->Text = L"3";
			this->btnDigit3->UseVisualStyleBackColor = true;
			this->btnDigit3->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit2
			// 
			this->btnDigit2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit2->Location = System::Drawing::Point(114, 287);
			this->btnDigit2->Name = L"btnDigit2";
			this->btnDigit2->Size = System::Drawing::Size(75, 57);
			this->btnDigit2->TabIndex = 14;
			this->btnDigit2->Text = L"2";
			this->btnDigit2->UseVisualStyleBackColor = true;
			this->btnDigit2->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// btnDigit1
			// 
			this->btnDigit1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDigit1->Location = System::Drawing::Point(33, 287);
			this->btnDigit1->Name = L"btnDigit1";
			this->btnDigit1->Size = System::Drawing::Size(75, 57);
			this->btnDigit1->TabIndex = 13;
			this->btnDigit1->Text = L"1";
			this->btnDigit1->UseVisualStyleBackColor = true;
			this->btnDigit1->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(276, 350);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 57);
			this->button17->TabIndex = 20;
			this->button17->Text = L"÷";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// btnEquals
			// 
			this->btnEquals->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEquals->Location = System::Drawing::Point(195, 350);
			this->btnEquals->Name = L"btnEquals";
			this->btnEquals->Size = System::Drawing::Size(75, 57);
			this->btnEquals->TabIndex = 19;
			this->btnEquals->Text = L"=";
			this->btnEquals->UseVisualStyleBackColor = true;
			this->btnEquals->Click += gcnew System::EventHandler(this, &MyForm::btnEquals_Click);
			// 
			// btnDecimal
			// 
			this->btnDecimal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDecimal->Location = System::Drawing::Point(114, 350);
			this->btnDecimal->Name = L"btnDecimal";
			this->btnDecimal->Size = System::Drawing::Size(75, 57);
			this->btnDecimal->TabIndex = 18;
			this->btnDecimal->Text = L",";
			this->btnDecimal->UseVisualStyleBackColor = true;
			this->btnDecimal->Click += gcnew System::EventHandler(this, &MyForm::btnDecimal_Click);
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(33, 350);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(75, 57);
			this->button20->TabIndex = 17;
			this->button20->Text = L"0";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::EnterNumber);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(357, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 57);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Root";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(357, 162);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 57);
			this->button2->TabIndex = 22;
			this->button2->Text = L"^";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(357, 224);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 57);
			this->button3->TabIndex = 23;
			this->button3->Text = L"!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(357, 287);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 57);
			this->button4->TabIndex = 24;
			this->button4->Text = L"%";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::EnterOperator);
			// 
			// btnAns
			// 
			this->btnAns->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAns->Location = System::Drawing::Point(357, 350);
			this->btnAns->Name = L"btnAns";
			this->btnAns->Size = System::Drawing::Size(75, 57);
			this->btnAns->TabIndex = 25;
			this->btnAns->Text = L"Ans";
			this->btnAns->UseVisualStyleBackColor = true;
			this->btnAns->Click += gcnew System::EventHandler(this, &MyForm::btnAns_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(469, 435);
			this->Controls->Add(this->btnAns);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->btnEquals);
			this->Controls->Add(this->btnDecimal);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->btnDigit3);
			this->Controls->Add(this->btnDigit2);
			this->Controls->Add(this->btnDigit1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->btnDigit6);
			this->Controls->Add(this->btnDigit5);
			this->Controls->Add(this->btnDigit4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->btnDigit9);
			this->Controls->Add(this->btnDigit8);
			this->Controls->Add(this->btnDigit7);
			this->Controls->Add(this->btnPlusMinus);
			this->Controls->Add(this->btnClearEntry);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->txtDisplay);
			this->Controls->Add(this->btnSpace);
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EnterNumber(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void EnterOperator(System::Object^ sender, System::EventArgs^ e) {
		


	}
	private: System::Void btnDecimal_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btnEquals_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
	}

	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void btnClearEntry_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void btnPlusMinus_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btnSpace_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btnAns_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	
	};
}

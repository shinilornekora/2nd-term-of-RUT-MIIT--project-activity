#pragma once
#include <Windows.h>
#include "NeuronNetwork.h"
#include <msclr\marshal_cppstd.h> // Васильева Мирина. Миит - жалуется на плюсы.
namespace Project8 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{

			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;
	public: System::Windows::Forms::TextBox^ textBox1;
	public: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textBox3;
	private:
	public: System::Windows::Forms::TextBox^ textBox4;
	public: System::Windows::Forms::TextBox^ textBox5;
	public: System::Windows::Forms::TextBox^ textBox6;
	public: System::Windows::Forms::TextBox^ textBox7;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(260, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Предсказать!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripTextBox1 });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(161, 39);
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 31);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(110, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(61, 26);
			this->textBox2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(588, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Введите все семь признаков для работы великого предсказателя классов:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(207, 65);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 26);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(307, 65);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(61, 26);
			this->textBox4->TabIndex = 6;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(403, 65);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(61, 26);
			this->textBox5->TabIndex = 7;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(501, 65);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(61, 26);
			this->textBox6->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(601, 65);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(61, 26);
			this->textBox7->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 164);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Предсказатель";
			this->contextMenuStrip1->ResumeLayout(false);
			this->contextMenuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Neuron_Network nn;
		System::String^ f_12 = textBox1->Text;
		System::String^ f_22 = textBox2->Text;
		System::String^ f_32 = textBox3->Text;
		System::String^ f_42 = textBox4->Text;
		System::String^ f_52 = textBox5->Text;
		System::String^ f_62 = textBox6->Text;
		System::String^ f_72 = textBox7->Text;
		msclr::interop::marshal_context context;
		std::string standartString1 = context.marshal_as<std::string>(f_12);
		std::string standartString2 = context.marshal_as<std::string>(f_22);
		std::string standartString3 = context.marshal_as<std::string>(f_32);
		std::string standartString4 = context.marshal_as<std::string>(f_42);
		std::string standartString5 = context.marshal_as<std::string>(f_52);
		std::string standartString6 = context.marshal_as<std::string>(f_62);
		std::string standartString7 = context.marshal_as<std::string>(f_72);
		int f_1, f_2, f_3, f_4, f_5, f_6, f_7;
		f_1 = stoi(standartString1);
		f_2 = stoi(standartString2);
		f_3 = stoi(standartString3);
		f_4 = stoi(standartString4);
		f_5 = stoi(standartString5);
		f_6 = stoi(standartString6);
		f_7 = stoi(standartString7);
		nn.inter_counter();
		nn.refues();
		nn.informativnosti();
		char result = nn.prediction(f_1, f_2, f_3, f_4, f_5, f_6, f_7);
		switch (result) {
		case 67:
			label1->Text = L"                Я думаю, что объект относится к классу  C  ";
			break;
		
		case 66:
			label1->Text = L"                Я думаю, что объект относится к классу  B  ";
			break;

		case 65:
			label1->Text = L"                Я думаю, что объект относится к классу  A  ";
			break;
	}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

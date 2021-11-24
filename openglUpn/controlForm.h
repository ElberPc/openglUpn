#pragma once

namespace openglUpn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de controlForm
	/// </summary>
	public ref class controlForm : public System::Windows::Forms::Form
	{
	public:
		controlForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			button3->Visible = FALSE;
			button5->Visible = FALSE;
			button4->Visible = FALSE;
			label1->Visible = FALSE;
			label2->Visible = FALSE;
			label7->Visible = FALSE;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~controlForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;


	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(controlForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->Location = System::Drawing::Point(30, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Mostrar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &controlForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(265, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 27);
			this->label2->TabIndex = 4;
			this->label2->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(37, 138);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Movimientos Restantes:";
			this->label1->Click += gcnew System::EventHandler(this, &controlForm::label1_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button4->Location = System::Drawing::Point(217, 209);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 43);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Camino Rojo";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &controlForm::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(42, 209);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 43);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Camino Verde";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &controlForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->Location = System::Drawing::Point(30, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 36);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Level 1";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &controlForm::button2_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button5->Location = System::Drawing::Point(364, 214);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(93, 32);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Reiniciar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &controlForm::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(175, 163);
			this->panel1->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(27, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Computación Grafica";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->label4->Location = System::Drawing::Point(43, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 19);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Grupo 03";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel3->Location = System::Drawing::Point(30, 11);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(95, 68);
			this->panel3->TabIndex = 0;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &controlForm::panel3_Paint);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(2, 153);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(175, 278);
			this->panel2->TabIndex = 6;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->button6->Enabled = false;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button6->Location = System::Drawing::Point(30, 171);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(113, 36);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Level 2";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->button4);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Controls->Add(this->button3);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->button5);
			this->panel4->Location = System::Drawing::Point(194, 74);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(493, 286);
			this->panel4->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::DimGray;
			this->label7->Location = System::Drawing::Point(38, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(311, 57);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Reto:\r\nLogra un Jaque Mate en 3 movimientos \r\npara cumplir el desafio.\r\n";
			this->label7->Click += gcnew System::EventHandler(this, &controlForm::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->label6->Location = System::Drawing::Point(188, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(185, 34);
			this->label6->TabIndex = 3;
			this->label6->Text = L"ChessBoard";
			// 
			// controlForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->ClientSize = System::Drawing::Size(705, 395);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"controlForm";
			this->Text = L"Chess Board";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			// timer1->Enabled = TRUE;
				 showBoard = 1;
				 main2(NULL,NULL);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 nivel = 1;
				 if (showBoard != 0){
					 movements = 3;
					 button5->Visible = TRUE;
					 button3->Visible = TRUE;
					 button4->Visible = TRUE;
					 label1->Visible = TRUE;
					 label2->Visible = TRUE;
					 label7->Visible = TRUE;
					 label2->Text = "" + movements;
					 
				 }
				 glutPostRedisplay();

	}
//option green
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (nivel == 1 && step == 1){
				 option = 1;
				 timerState = 1;
				 movements = 2;
				 label2->Text = "" + movements;

			 }
			 else if (nivel == 1 && step == 2){
				 option = 1;
				 timerState = 1;
				 movements = 1;
				 label2->Text = "" + movements;
			 }
			 else if (nivel == 1 && step == 3){
				 option = 1;
				 timerState = 1;
				 movements = 0;
				 label2->Text = "" + movements;
				 if (win < 3){
					 label7->Text = "Intentalo Nuevamente :c";
					 button3->Visible = FALSE;
					 button4->Visible = FALSE;
				 }
				 else {
					 label7->Text = "¡Bien Hecho!";
				 }
				 
			 }
} 
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			
}
		 //option red
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (nivel == 1 && step==1){
				 option = 2;
				 timerState = 1;
				 movements = 2;
				 label2->Text = "" + movements;
			 }
			 else  if (nivel == 1 && step == 2){
				 option = 2;
				 timerState = 1;
				 movements = 1;
				 label2->Text = "" + movements;
			 }
			 else  if (nivel == 1 && step == 3){
				 option = 2;
				 timerState = 1;
                 movements = 0;
				 label2->Text = "" + movements;
				 if (win < 3){
					 label7->Text = "Intentalo Nuevamente :c";
					 button3->Visible = FALSE;
					 button4->Visible = FALSE;
				 }
				 else {
					 label7->Text = "¡Bien Hecho!";
				 }
				 
			 }
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 button3->Visible = TRUE;
			 button4->Visible = TRUE;
			 step = 1;
			 movements = 3;
			 label2->Text = "" + movements;
			 glutPostRedisplay();
			 xTW = -0.28, yTW = -0.52, xTW2 = 0.39, yTW2 = 0.41, xTW3 = 0.39, yTW3 = -0.52;
			 sup = 0;
			 if (nivel == 1){
				 label7->Text = "Reto:\nLogra un Jaque Mate en 3 movimientos\npara cumplir el desafio.";
			 }
			 
}
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}

};
}

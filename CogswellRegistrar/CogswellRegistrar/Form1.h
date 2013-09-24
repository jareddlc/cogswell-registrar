#pragma once
#include "worker.h"

namespace CogswellRegistrar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SQLite;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::GroupBox^  group_settings;
		private: System::Windows::Forms::Button^  btn_audit;
		private: System::Windows::Forms::Button^  btn_master;
		private: System::Windows::Forms::Button^  btn_search;
		private: System::Windows::Forms::TextBox^  input_search;
		private: System::Windows::Forms::GroupBox^  group_table;
		public: OpenFileDialog^ file_audit;
		public: OpenFileDialog^ file_master;
		public: bool sel_audit;
		public: bool sel_master;
		private: System::Windows::Forms::Label^  label_master;
		private: System::Windows::Forms::Label^  label_audit;
		private: System::Windows::Forms::Button^  btn_run;
		private: System::Windows::Forms::TextBox^  textBox_status;
		private: System::Windows::Forms::MenuStrip^  menuStrip;
		private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  version010ToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  version010ToolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^  showConsoleToolStripMenuItem;
		private: System::ComponentModel::IContainer^  components;
		private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->group_settings = (gcnew System::Windows::Forms::GroupBox());
			this->btn_run = (gcnew System::Windows::Forms::Button());
			this->label_master = (gcnew System::Windows::Forms::Label());
			this->label_audit = (gcnew System::Windows::Forms::Label());
			this->btn_search = (gcnew System::Windows::Forms::Button());
			this->input_search = (gcnew System::Windows::Forms::TextBox());
			this->btn_master = (gcnew System::Windows::Forms::Button());
			this->btn_audit = (gcnew System::Windows::Forms::Button());
			this->group_table = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_status = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showConsoleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->version010ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->version010ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->group_settings->SuspendLayout();
			this->group_table->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// group_settings
			// 
			this->group_settings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->group_settings->Controls->Add(this->btn_run);
			this->group_settings->Controls->Add(this->label_master);
			this->group_settings->Controls->Add(this->label_audit);
			this->group_settings->Controls->Add(this->btn_search);
			this->group_settings->Controls->Add(this->input_search);
			this->group_settings->Controls->Add(this->btn_master);
			this->group_settings->Controls->Add(this->btn_audit);
			this->group_settings->Location = System::Drawing::Point(12, 27);
			this->group_settings->Name = L"group_settings";
			this->group_settings->Size = System::Drawing::Size(600, 82);
			this->group_settings->TabIndex = 0;
			this->group_settings->TabStop = false;
			this->group_settings->Text = L"Settings";
			// 
			// btn_run
			// 
			this->btn_run->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_run->Enabled = false;
			this->btn_run->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_run.Image")));
			this->btn_run->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_run->Location = System::Drawing::Point(526, 48);
			this->btn_run->Name = L"btn_run";
			this->btn_run->Size = System::Drawing::Size(68, 23);
			this->btn_run->TabIndex = 6;
			this->btn_run->Text = L"Process";
			this->btn_run->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_run->UseVisualStyleBackColor = true;
			this->btn_run->Click += gcnew System::EventHandler(this, &Form1::btn_run_Click);
			// 
			// label_master
			// 
			this->label_master->AutoSize = true;
			this->label_master->Location = System::Drawing::Point(99, 53);
			this->label_master->Name = L"label_master";
			this->label_master->Size = System::Drawing::Size(62, 13);
			this->label_master->TabIndex = 5;
			this->label_master->Text = L"Select file...";
			// 
			// label_audit
			// 
			this->label_audit->AutoSize = true;
			this->label_audit->Location = System::Drawing::Point(99, 24);
			this->label_audit->Name = L"label_audit";
			this->label_audit->Size = System::Drawing::Size(62, 13);
			this->label_audit->TabIndex = 4;
			this->label_audit->Text = L"Select file...";
			// 
			// btn_search
			// 
			this->btn_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_search->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_search.Image")));
			this->btn_search->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_search->Location = System::Drawing::Point(526, 19);
			this->btn_search->Name = L"btn_search";
			this->btn_search->Size = System::Drawing::Size(68, 23);
			this->btn_search->TabIndex = 3;
			this->btn_search->Text = L"Search";
			this->btn_search->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_search->UseVisualStyleBackColor = true;
			// 
			// input_search
			// 
			this->input_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_search->Location = System::Drawing::Point(352, 22);
			this->input_search->Name = L"input_search";
			this->input_search->Size = System::Drawing::Size(168, 20);
			this->input_search->TabIndex = 2;
			// 
			// btn_master
			// 
			this->btn_master->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_master.Image")));
			this->btn_master->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_master->Location = System::Drawing::Point(6, 48);
			this->btn_master->Name = L"btn_master";
			this->btn_master->Size = System::Drawing::Size(87, 23);
			this->btn_master->TabIndex = 1;
			this->btn_master->Text = L"Master CSV";
			this->btn_master->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_master->UseVisualStyleBackColor = true;
			this->btn_master->Click += gcnew System::EventHandler(this, &Form1::btn_master_Click);
			// 
			// btn_audit
			// 
			this->btn_audit->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_audit.Image")));
			this->btn_audit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_audit->Location = System::Drawing::Point(6, 19);
			this->btn_audit->Name = L"btn_audit";
			this->btn_audit->Size = System::Drawing::Size(87, 23);
			this->btn_audit->TabIndex = 0;
			this->btn_audit->Text = L"Audit CSV";
			this->btn_audit->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_audit->UseVisualStyleBackColor = true;
			this->btn_audit->Click += gcnew System::EventHandler(this, &Form1::btn_audit_Click);
			// 
			// group_table
			// 
			this->group_table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->group_table->Controls->Add(this->textBox_status);
			this->group_table->Location = System::Drawing::Point(12, 115);
			this->group_table->Name = L"group_table";
			this->group_table->Size = System::Drawing::Size(600, 315);
			this->group_table->TabIndex = 1;
			this->group_table->TabStop = false;
			this->group_table->Text = L"Table";
			// 
			// textBox_status
			// 
			this->textBox_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_status->Location = System::Drawing::Point(6, 19);
			this->textBox_status->Multiline = true;
			this->textBox_status->Name = L"textBox_status";
			this->textBox_status->ReadOnly = true;
			this->textBox_status->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_status->Size = System::Drawing::Size(588, 290);
			this->textBox_status->TabIndex = 0;
			// 
			// menuStrip
			// 
			this->menuStrip->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(624, 24);
			this->menuStrip->TabIndex = 2;
			this->menuStrip->Text = L"Menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->showConsoleToolStripMenuItem, 
				this->closeToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// showConsoleToolStripMenuItem
			// 
			this->showConsoleToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->showConsoleToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->showConsoleToolStripMenuItem->Name = L"showConsoleToolStripMenuItem";
			this->showConsoleToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->showConsoleToolStripMenuItem->Text = L"Show Console";
			this->showConsoleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showConsoleToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->version010ToolStripMenuItem, 
				this->version010ToolStripMenuItem1});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// version010ToolStripMenuItem
			// 
			this->version010ToolStripMenuItem->Name = L"version010ToolStripMenuItem";
			this->version010ToolStripMenuItem->Size = System::Drawing::Size(179, 22);
			this->version010ToolStripMenuItem->Text = L"By: Jared De La Cruz";
			// 
			// version010ToolStripMenuItem1
			// 
			this->version010ToolStripMenuItem1->Name = L"version010ToolStripMenuItem1";
			this->version010ToolStripMenuItem1->Size = System::Drawing::Size(179, 22);
			this->version010ToolStripMenuItem1->Text = L"Version 0.1.0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->group_table);
			this->Controls->Add(this->group_settings);
			this->Controls->Add(this->menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Form1";
			this->Text = L"Cogswell Student Audit";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->group_settings->ResumeLayout(false);
			this->group_settings->PerformLayout();
			this->group_table->ResumeLayout(false);
			this->group_table->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		Worker ^work;
		Thread ^workerThread;
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			this->textBox_status->Text += L"Application loaded.\r\n";
			this->textBox_status->Select(textBox_status->Text->Length,0);
			this->textBox_status->ScrollToCaret();
		}

		private: System::Void btn_audit_Click(System::Object^  sender, System::EventArgs^  e) {
			file_audit = gcnew OpenFileDialog();
			file_audit->Filter = "CSV Files|*.csv|All Files|*.*";
			if(file_audit->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			sel_audit = true;
			this->label_audit->Text = file_audit->FileName;
			this->textBox_status->Text += L"Audit file selected: "+file_audit->FileName+"\r\n";

			//Check to see if files where submitted
			if(sel_audit && sel_master) 
			{
				this->btn_run->Enabled = true;
			}
		}
		private: System::Void btn_master_Click(System::Object^  sender, System::EventArgs^  e) {
			file_master = gcnew OpenFileDialog();
			file_master->Filter = "CSV Files|*.csv|All Files|*.*";
			if(file_master->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			sel_master = true;
			this->label_master->Text = file_master->FileName;
			this->textBox_status->Text += L"Master file selected: "+file_master->FileName+"\r\n";

			//Check to see if files where submitted
			if(sel_audit && sel_master) 
			{
				this->btn_run->Enabled = true;
			}
		}
		private: System::Void btn_run_Click(System::Object^  sender, System::EventArgs^  e) {
			work = gcnew Worker(textBox_status, file_audit->FileName, file_master->FileName);

			// Create a thread and calls work method
			workerThread = gcnew Thread(gcnew ThreadStart(work, &Worker::Work));

			// Start the thread
			workerThread->Start();
		}
		private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			exit(0);
		}
		private: System::Void showConsoleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->textBox_status->Visible == true) {
				this->textBox_status->Visible = false;
			}
			else
				this->textBox_status->Visible = true;	
		}
};
}

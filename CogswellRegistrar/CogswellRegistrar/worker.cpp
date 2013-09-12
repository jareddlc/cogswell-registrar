#include "stdafx.h"
#include "worker.h"

Worker::Worker(TextBox ^textBox, String ^audit, String ^master) {
	// textBox
	outputBox = textBox;
	outputDelegate = gcnew setTextBoxText(this, &Worker::setTextBoxMethod);
	outputBox->Invoke(outputDelegate, outputBox, "Initializing...\r\n");

	// file
	this->file_audit = audit;
	this->file_master = master;

	// sCom
	this->sCom = (gcnew SQLiteCommand());
	this->sCom->CommandText = nullptr;

	// sCon
	this->sCon = (gcnew SQLiteConnection());
	this->sCon->ConnectionString = L"Data Source=Students.db";
	this->sCon->DefaultTimeout = 30;
	this->sCon->Flags = static_cast<SQLiteConnectionFlags>((SQLiteConnectionFlags::LogCallbackException | SQLiteConnectionFlags::LogModuleException));
	this->sCon->ParseViaFramework = false;
}

void Worker::setTextBoxMethod(System::Windows::Forms::TextBox ^T, String ^str)
{
	T->AppendText(str); 
}

void Worker::Work()
{
	outputBox->Invoke(outputDelegate, outputBox, "Connecting to Students.db.\r\n");
	sCon->Open();
	outputBox->Invoke(outputDelegate, outputBox, "Connected to Students.db.\r\n");

	this->dropTables();
	this->createTables();
	this->insertAudit();
	this->insertMaster();
	this->createLetterGrades();
	this->createAudit();
	this->createMaster();

	outputBox->Invoke(outputDelegate, outputBox, "Closing Students.db.\r\n");
	sCon->Close();
	outputBox->Invoke(outputDelegate, outputBox, "Closed Students.db.\r\n");
}

void Worker::dropTables()
{
	outputBox->Invoke(outputDelegate, outputBox, "Dropping tables.\r\n");
	sCom = sCon->CreateCommand();
	sCom->CommandText = "DROP TABLE IF EXISTS raw_master;";
	sCom->ExecuteNonQuery();
	sCom->CommandText = "DROP TABLE IF EXISTS raw_audit;";
	sCom->ExecuteNonQuery();
	sCom->CommandText = "DROP TABLE IF EXISTS letterGrades;";
	sCom->ExecuteNonQuery();
	sCom->CommandText = "DROP TABLE IF EXISTS audit;";
	sCom->ExecuteNonQuery();
	outputBox->Invoke(outputDelegate, outputBox, "Dropped tables.\r\n");
}

void Worker::createTables()
{
	outputBox->Invoke(outputDelegate, outputBox, "Creating tables.\r\n");
	sCom = sCon->CreateCommand();
	sCom->CommandText = "CREATE TABLE raw_master (`courseID` text, `title` text, `prereq` text, `coreq` text);";
	sCom->ExecuteNonQuery();
	sCom->CommandText = "CREATE TABLE raw_audit (`studentInfo` text, `courseID` text, `courseDesc` text, `letterGrade` text, `completionStatus` text);";
	sCom->ExecuteNonQuery();
	outputBox->Invoke(outputDelegate, outputBox, "Created tables.\r\n");
}

void Worker::createLetterGrades()
{
	outputBox->Invoke(outputDelegate, outputBox, "Creating letterGrades table.\r\n");
	sCom = sCon->CreateCommand();
	sCom->CommandText = "CREATE TABLE letterGrades (`letter` varchar(2) not null, `number` decimal(2,1) not null, primary key (`letter`, `number`));";
	sCom->ExecuteNonQuery();

	sCom = gcnew SQLiteCommand("BEGIN", sCon);
	sCom->ExecuteNonQuery(); 
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A+', '4.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A', '4.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A-', '3.7');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B+', '3.3');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B', '3.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B-', '2.7');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C+', '2.3');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C', '2.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C-', '1.7');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D+', '1.3');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D', '1.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D-', '0.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('F', '0.0');", sCon);
	sCom->ExecuteNonQuery();
	sCom = gcnew SQLiteCommand("END", sCon);
	sCom->ExecuteNonQuery();
	outputBox->Invoke(outputDelegate, outputBox, "Created letterGrades table.\r\n");
}

void Worker::insertAudit()
{
	int numRows = 0;
	//SQLite Defer for large insertion
	sCom = gcnew SQLiteCommand("BEGIN", sCon);
	sCom->ExecuteNonQuery(); 
	try 
	{
		StreamReader^ sr = gcnew StreamReader(this->file_audit);
		try	
		{
			String ^line;
			array<String^>^ temp;
			while(line = sr->ReadLine())
			{
				numRows++;
				temp = line->Split(',');
				if(temp->Length >= 7)
				{
					sCom = gcnew SQLiteCommand("INSERT INTO raw_audit VALUES('"+temp[0]+"', '"+temp[1]+"', '"+temp[2]+"', '"+temp[5]+"', '"+temp[7]+"');", sCon);
					sCom->ExecuteNonQuery();
				}
			}
			//SQLite perform insertion
			sCom = gcnew SQLiteCommand("END", sCon);
			sCom->ExecuteNonQuery();
			outputBox->Invoke(outputDelegate, outputBox, "Inserted rows = "+numRows+"\r\n");
		}
		finally
		{
			if(sr)
				delete(IDisposable^)sr;
		}
	}
	catch(Exception^ e) 
	{
		// Let the user know what went wrong.
		outputBox->Invoke(outputDelegate, outputBox, "The file could not be read.\r\n");
		outputBox->Invoke(outputDelegate, outputBox, "Error at:"+numRows+"\r\n");
		outputBox->Invoke(outputDelegate, outputBox, e->Message);
	}
}

void Worker::insertMaster()
{
	int numRows = 0;
	//SQLite Defer for large insertion
	sCom = gcnew SQLiteCommand("BEGIN", sCon);
	sCom->ExecuteNonQuery(); 
	try 
	{
		StreamReader^ sr = gcnew StreamReader(this->file_master);
		try	
		{
			String ^line;
			array<String^>^ temp;
			while(line = sr->ReadLine())
			{
				numRows++;
				temp = line->Split(',');
				if(temp->Length >= 15)
				{
					sCom = gcnew SQLiteCommand("INSERT INTO raw_master VALUES('"+temp[0]+"', '"+temp[1]+"', '"+temp[5]+"', '"+temp[6]+"');", sCon);
					sCom->ExecuteNonQuery();
				}
			}
			//SQLite perform insertion
			sCom = gcnew SQLiteCommand("END", sCon);
			sCom->ExecuteNonQuery();
			outputBox->Invoke(outputDelegate, outputBox, "Inserted rows = "+numRows+"\r\n");
		}
		finally
		{
			if(sr)
				delete(IDisposable^)sr;
		}
	}
	catch (Exception^ e) 
	{
		// Let the user know what went wrong.
		outputBox->Invoke(outputDelegate, outputBox, "The file could not be read.\r\n");
		outputBox->Invoke(outputDelegate, outputBox, "Error at:"+numRows+"\r\n");
		outputBox->Invoke(outputDelegate, outputBox, e->Message);
	}
}

void Worker::createAudit()
{
	outputBox->Invoke(outputDelegate, outputBox, "Creating audit table.\r\n");
	sCom = sCon->CreateCommand();
	sCom->CommandText = "CREATE TABLE audit as select `studentInfo` as `studentID`, `courseID`, `completionStatus`, `number` as `numericalGrade` from `raw_audit` left join `letterGrades` on `letterGrade` = `letter`	where `courseID` != '';";
	sCom->ExecuteNonQuery();
	outputBox->Invoke(outputDelegate, outputBox, "Created audit table.\r\n");
}

void Worker::createMaster()
{
}
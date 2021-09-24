// Muaadh Esmail
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;
// Finctions prototypes
void menu(int);
void Triangle(int);
void Rectangle(int);
void Parallelogram(int);
void strip(string&);
void readFile(ifstream&, ifstream&, ifstream&, string[], string[], string[]);
bool findData(int, int, int, string[], string[], string[]);
bool checkAnswer(string, string);
void output(fstream& mHandle, string studentID, int* finalMark);

int main() {// main function

		int choose = 0;
		cout << "|Please choose one of the following shapes|\n"
			<< "|*****************************************|\n"
			<< "|1) Triangle" << setw(32) << "|\n"
			<< "|2) Parrallelogram" << setw(26) << "|\n"
			<< "|3) Rectangle" << setw(31) << "|\n"
			<< "|*****************************************|\n"
			<< "|" << setw(35) << " Enter the shape number you want " << setw(8) << "|\n"
			<< "| ";
		cin >> choose;
		menu(choose);

		string studentID;
		int finalMark = 0;
		int* markPtr = &finalMark;
		string content;
		fstream mHandle("studentMarks.txt");


		cout << setw(20) << "|Now you will be taking test|" << endl
			<< setw(20) << "Please enter your student ID: ";
		cin >> studentID;

		while (getline(mHandle, content))
			// while loop to chech studentID
		{
			content.find(":");
			content.erase(0, content.find(":") + 1);
			if (content.substr(0, content.find(" ")) == studentID)
			{
				cout << "You have already taken the quiz. You are not allowed to take it again.\n";
				mHandle.close();
				exit(-1);
			}
		}
		mHandle.close();
		ifstream Triangle_Handle("Triangle.txt");
		ifstream Parallelogram_Handle("Parallelogram.txt");
		ifstream Rectangle_Handle("Rectangle.txt");
		// since each file has 36 value the size of the arrays will be 36 
		string areas[36];
		string widths_bases[36];
		string heights[36];
		// Call function readFile
		readFile(Triangle_Handle, Parallelogram_Handle, Rectangle_Handle, areas, widths_bases, heights);
		/* First shape triangle. */
		// First section. Calculating the area
		int section = 1;
		if (choose == 1) {

			cout << "Triangle  ----------------------------------------------------------------" << endl;
			for (int i = 0; i < 4; i++)
			{ // This for loop for the first senction
				bool answer = findData(1, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;
			}for (int i = 4; i < 8; i++)
			{ // This for loop for the first senction
				bool answer = findData(2, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;

			}for (int i = 8; i < 12; i++)
			{ // This for loop for the first senction
				bool answer = findData(3, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;
			}
		}
		else if (choose == 2) {
			cout << "Parallelogram-3  ----------------------------------------------------------------" << endl;

			for (int i = 12; i < 16; i++)
			{ // This for loop for the first senction
				bool answer = findData(1, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;

			}for (int i = 16; i < 20; i++)
			{ // This for loop for the first senction
				bool answer = findData(2, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;

			}for (int i = 20; i < 24; i++)
			{ // This for loop for the first senction
				bool answer = findData(3, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;
			}
		}
		else if (choose == 3) {
			cout << "Rectangle  ----------------------------------------------------------------" << endl;
			for (int i = 24; i < 28; i++)
			{ // This for loop for the first senction
				bool answer = findData(1, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;

			}for (int i = 28; i < 32; i++)
			{ // This for loop for the first senction
				bool answer = findData(2, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;

			}for (int i = 32; i < 36; i++)
			{ // This for loop for the first senction
				bool answer = findData(3, section, i, areas, widths_bases, heights);
				(answer) ? (*markPtr)++ : finalMark = finalMark;
			}
		}
		cout << "*********************** you have answered [" << *markPtr << "]correct ***********************";
		output(mHandle, studentID, markPtr);
}
void menu(int choose) {
	// The shape choosen by the user 
	int select;// The calculateion 
	string repeat;// how many calculateion

	if (choose == 1) {
		//Triangle
		cout << "|*****************************************|\n"
			<< "|" << setw(10) << "" << "You choose Triangle" << setw(14) << "|\n"
			<< "|*****************************************|\n";
		cout << "|\tchoose what you want to find" << setw(8) << "|\n"
			<< "|1 to find the Area" << setw(25) << "|\n"
			<< "|2 to find the Base" << setw(25) << "|\n"
			<< "|3 to find the Height" << setw(23) << "|\n";
		cin >> select;

		while (select > 3 || select < 1) {
			cout << "_________________________" << endl;
			cout << "You should enter 1 or 2 or 3" << endl;
			cout << "_________________________" << endl;

			cout << "\tchoose what you want to find\n"
				<< "1 to find the Area\n"
				<< "2 to find the Base\n"
				<< "3 to find the Height\n";
			cin >> select;
		}

		Triangle(select);
		cout << "would you like to do another calculateion y/n ?" << endl;
		cin >> repeat;

		if (repeat == "y" || repeat == "Y") {

			return menu(choose);
		}

	}

	else if (choose == 2) {
		//Rectangle
		cout << "|*****************************************|\n"
			<< "|" << setw(10) << "" << "You choose Rectangle" << setw(13) << "|\n"
			<< "|*****************************************|\n"
			<< "|\tchoose what you want to find" << setw(8) << "|\n"
			<< "|1 to find the Area" << setw(25) << "|\n"
			<< "|2 to find the Width" << setw(24) << "|\n"
			<< "|3 to find the Length" << setw(23) << "|\n";
		cin >> select;

		while (select > 3 || select < 1) {
			cout << "_________________________" << endl;
			cout << "You should enter 1 or 2 or 3" << endl;
			cout << "_________________________" << endl;

			cout << "\tchoose what you want to find\n"
				<< "1 to find the Area\n"
				<< "2 to find the Base\n"
				<< "3 to find the Height\n";
			cin >> select;
		}

		Rectangle(select);
		cout << "would you like to do another calculateion y/n ?" << endl;
		cin >> repeat;

		if (repeat == "y" || repeat == "Y") {

			return menu(choose);
		}

	}

	else if (choose == 3) {
		//Parallelogram
		cout << "|*****************************************|\n"
			<< setw(8) << "" << "You choose Parallelogram\n"
			<< "|*****************************************|\n";
		cout << "\tchoose what you want to find\n"
			<< "1 to find the Area\n"
			<< "2 to find the Width\n"
			<< "3 to find the Length\n";
		cin >> select;

		while (select > 3 || select < 1) {
			cout << "_________________________" << endl;
			cout << "You should enter 1 or 2 or 3" << endl;
			cout << "_________________________" << endl;

			cout << "\tchoose what you want to find\n"
				<< "1 to find the Area\n"
				<< "2 to find the Base\n"
				<< "3 to find the Height\n";
			cin >> select;
		}

		Parallelogram(select);
		cout << "would you like to do another calculateion y/n ?" << endl;
		cin >> repeat;

		if (repeat == "y" || repeat == "Y") {

			return menu(choose);
		}
	}

	else {
		cout << "***********************************************\n";
		cout << "The only valid numbers are 1,2 and 3. Try again" << endl;
		cout << "***********************************************\n";
		return menu(choose);
	}


}

void Triangle(int select) {
	// Triangle function 
	double base = 0.0;
	double height = 0.0;
	double area = 0.0;


	if (select == 1) {

		cout << "enter the base valua :";
		cin >> base;
		cout << "enter the height valua:";
		cin >> height;
		area = (base * height) / 2;
		cout << "the values of area =" << area << endl; //calculation formula
		cout << "To calculate the area of a Triangle use the folowing formula =>"
			 << " Area = (base * height) / 2;" << endl;
	}

	else if (select == 2) {
		cout << "enter the area valua:";
		cin >> area;
		cout << "enter the base valua:";
		cin >> base;

		height = (2 * area) / base;
		cout << "the height value : " << height << endl; //calculation formula
		cout << "To calculate the height of a Triangle use the folowing formula =>"
			 << " Height = (2 * area) / base;" << endl;
	}

	else if (select == 3) {
		cout << "enter the area valua:";
		cin >> area;
		cout << "enter the height valua:";
		cin >> height;

		base = (area / height) * 2;//calculation formula
		cout << "the base value : " << base << endl;
		cout << "To calculate the base of a Triangle use the folowing formula =>"
			 << " Base = (area / height) * 2" << endl;
	}
}

void Rectangle(int select) {
	// Rectangle function
	double length = 0.0;
	double width = 0.0;
	double area = 0.0;
	if (select == 1) {

		cout << "Enter the length value :";
		cin >> length;
		cout << "Enter the width value :";
		cin >> width;
		area = length * width;//calculation formula
		cout << "the values of area =" << area << endl;
		cout << "To calculate the area of a Rectangle use the folowing formula =>"
			 << " Area = length * width" << endl;

	}
	else if (select == 2) {
		cout << "Enter the area valua:";
		cin >> area;
		cout << "Enter the width valua:";
		cin >> width;
		length = area / width;//calculation formula
		cout << "the height valua = " << length << endl;
		cout << "To calculate the lenght of a Rectangle use the folowing formula =>"
			 << " Length = area / width" << endl;
	}
	else if (select == 3) {
		cout << "Enter the area valua:";
		cin >> area;
		cout << "Enter the length valua:";
		cin >> length;
		width = area / length;//calculation formula
		cout << "the height valua = " << width << endl;
		cout << "To calculate the area of a Rectangle use the folowing formula =>"
			 << " Width = area / length" << endl;

	}
}

void Parallelogram(int select) {
	// Parallelogram function
	double base = 0.0;
	double height = 0.0;
	double area = 0.0;

	if (select == 1) {

		cout << "Enter the base valua :";
		cin >> base;
		cout << "Enter the height valua:";
		cin >> height;
		area = base * height;//calculation formula
		cout << "the values of area =" << area << endl;
		cout << "To calculate the area of a Parallelogram use the folowing formula =>" 
			 << " Area = base * height" << endl;

	}
	else if (select == 2) {
		cout << "Enter the area valua:";
		cin >> area;
		cout << "Enter the base valua:";
		cin >> base;
		height = area / base;//calculation formula
		cout << "the height value : " << height << endl;
		cout << "To calculate the hight of a Parallelogram use the folowing formula =>"  
			 << " Height = area / base" << endl;

	}
	else if (select == 3) {
		cout << "Enter the area valua:";
		cin >> area;
		cout << "Enter the height valua:";
		cin >> height;
		base = area / height;//calculation formula
		cout << "the base value : " << base << endl;
		cout << "To calculate the base of a Parallelogram use the folowing formula =>"
			 <<" Base = area / height;" << endl;
	}

}

void strip(string& str) {// Function will replace the spaces between files to noyhing
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n')
		{
			str.replace(i, i + 1, "");
		}
	}
}

void readFile(ifstream& tHandle, ifstream& pHandle, ifstream& rHandle, string areas[], string widths_bases[], string heights[]) {
	// This function to get the data from three files (Triangle,Parallelogram, and Rectangle);
	string rcontent, pContent, rContent;
	int column1 = 0, column2 = 1, column3 = 2, counter = 0, a_arr_control = 0, w_b_arr_control = 0, h_arr_control = 0;
	while (getline(tHandle, rcontent, ' '))
	{
		strip(rcontent);
		if (counter == column1)
		{
			counter++;
			areas[a_arr_control] = rcontent;
			a_arr_control++;
			column1 += 3;
		}
		else if (counter == column2)
		{
			counter++;
			widths_bases[w_b_arr_control] = rcontent;
			w_b_arr_control++;
			column2 += 3;
		}
		else if (counter == column3)
		{
			counter++;
			heights[h_arr_control] = rcontent;
			h_arr_control++;
			column3 += 3;
		}
	}
	column1 = 0;
	column2 = 1;
	column3 = 2;
	counter = 0;
	while (getline(pHandle, pContent, ' '))
	{
		strip(pContent);
		if (counter == column1)
		{
			counter++;
			areas[a_arr_control] = pContent;
			a_arr_control++;
			column1 += 3;
		}
		else if (counter == column2)
		{
			counter++;
			widths_bases[w_b_arr_control] = pContent;
			w_b_arr_control++;
			column2 += 3;
		}
		else if (counter == column3)
		{
			counter++;
			heights[h_arr_control] = pContent;
			h_arr_control++;
			column3 += 3;
		}
	}
	column1 = 0;
	column2 = 1;
	column3 = 2;
	counter = 0;
	while (getline(rHandle, rContent, ' '))
	{
		strip(rContent);
		if (counter == column1)
		{
			counter++;
			areas[a_arr_control] = rContent;
			a_arr_control++;
			column1 += 3;
		}
		else if (counter == column2)
		{
			counter++;
			widths_bases[w_b_arr_control] = rContent;
			w_b_arr_control++;
			column2 += 3;
		}
		else if (counter == column3)
		{
			counter++;
			heights[h_arr_control] = rContent;
			h_arr_control++;
			column3 += 3;
		}
	}
}
bool findData(int shapeNumber, int section, int questionNumber, string areas[], string widthes_bases[], string heights[]){
	// this function will compare the user inpout with the file value
	string answer;
		switch (shapeNumber)
		{
		case 1:
			cout << "Calculate the area of the triangle from the follwing information" << endl;
			cout << "base of: " << widthes_bases[questionNumber] << " Height of: " << heights[questionNumber] << endl;
			cin >> answer;
			return checkAnswer(answer, areas[questionNumber]);
		case 2:
			cout << "Calculate the base of the triangle from the follwing information" << endl;
			cout << "area of: " << areas[questionNumber ] << " Length of: " << heights[questionNumber ] << endl;
			cin >> answer;
			return checkAnswer(answer, widthes_bases[questionNumber]);
		case 3:
			cout << "Calculate the height of the triangle from the follwing information" << endl;
			cout << "base of: " << widthes_bases[questionNumber ] << " Height of: " << areas[questionNumber] << endl;
			cin >> answer;
			return checkAnswer(answer, heights[questionNumber ]);
		default:
			cout << "Something is off please do contact the owner of this program" << endl;
			break;
	}

	return false;
}
bool checkAnswer(string sAnswer, string cAnswer)
{// Function to chech the answes 
	if (cAnswer == sAnswer)
		return true;
	return false;
}
void output(fstream& mHandle, string studentID, int* finalMark)
{
	// This function will write the student ID and, amount of correct answers.
		mHandle.open("studentMarks.txt", fstream::app);
		mHandle << "Student ID:" << studentID << " . Mark: " << (*finalMark) << endl;
}
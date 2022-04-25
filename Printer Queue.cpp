/*Assignment 3 Problem 5
  Roll NO: 2018-CS-613
  Section: A
  Name: M Yahya*/

#include <iostream>
#include <string>
using namespace std;


class UserInFo {
public:
	string sender_Name;
	string sub_Time;
	string start_Time;
	string end_Time;
	int no_Pages;

	UserInFo() {

	}

	UserInFo(string name, int pages, string time) {
		sender_Name = name;
		no_Pages = pages;
		sub_Time = time;
	}

	void inputs() {
		cout << "Enter Sender Name: ";  cin >> sender_Name;
		cout << "Enter No of Pages: ";  cin >> no_Pages;
		cout << "Enter Sub Time: ";     cin >> sub_Time;
	}

	void showUser() {
		cout << "Sender Name: " << sender_Name <<endl;
		cout << "No of Pages: " << no_Pages <<endl;
		cout << "Sub Time: " << sub_Time <<endl;

		cout << endl;
	}
};


class PrinterQueue {
public:
	int size = 10;
	UserInFo* infoQueue = new UserInFo[size];
	int front, rear = 0;

	int* arr = new int[size];
	int top = 0;

	PrinterQueue() {
		
	}

	bool isFull() {
		if (rear == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void enQueue(UserInFo user) {
		if (!isFull()) {
			infoQueue[rear] = user;
			rear++;
		}
		else {
			cout << "Queue is full\n";
		}
	}


	UserInFo deQueue() {
		if (!isEmpty()) {
			UserInFo file;
			file = infoQueue[front];
			front++;
			return file;
		}
		else {
			cout << "Queue is empt\n";
		}
	}



	void displayFiles() {
		cout << "Displaying files: \n\n";
		for (int i = front; i < rear; i++) {
			infoQueue[i].showUser();
			cout <<endl;
		}
	}

	void processJob() {
		int count = 1;
		for (int i = front; i < rear; i++) {
			cout << "Printing File Information: " << count << " \n";
			infoQueue[i].showUser();
			if (i == 0 ) {
				infoQueue[i].start_Time = infoQueue[i].sub_Time;
			}
			else if (infoQueue[i + 1].sub_Time[0] > infoQueue[i].sub_Time[0]) {
				cout << "grreater!";
			}
			else {
				infoQueue[i].start_Time = infoQueue[i - 1].end_Time;
			}
			cout << "start time: " << infoQueue[i].start_Time << endl;
			cout << "Printing..........\n";
			char time = infoQueue[i].start_Time[3];
			int digit = (time - '0');
			float plus = infoQueue[i].no_Pages / 6;
			
			digit = digit + plus;

			if (digit > 9) {
				string str = to_string(digit);
				int o = (str[0] - '0');
				int num = (infoQueue[i].start_Time[2] - '0');
				int newi = o + num;
				char cha = (newi + '0');
				infoQueue[i].start_Time[2] = cha;
				infoQueue[i].start_Time[3] = str[1];

				infoQueue[i].end_Time = infoQueue[i].start_Time;
				cout << "end time: " << infoQueue[i].end_Time << endl;

			}
			else {
				char cha = (digit + '0');
				infoQueue[i].start_Time[3] = cha;

				infoQueue[i].end_Time = infoQueue[i].start_Time;
				cout << "end time: " << infoQueue[i].end_Time << endl;
			}

			count++;
			cout << endl << endl << endl;
		}
	}


};

int main() {
	UserInFo user1("Ahmad", 6, "6:10");
	UserInFo user2("Maria", 18, "6:10");
	UserInFo user3("John", 13, "6:10");
	UserInFo user4("Nad", 40, "6:10");
	UserInFo user5("Kal", 60, "6:10");

	PrinterQueue print;
	print.enQueue(user1);
	print.enQueue(user2);
	print.enQueue(user3);
	print.enQueue(user4);
	print.enQueue(user5);
	print.displayFiles();

	cout << "\n\n\tProcessing............\n";
	print.processJob();

	system("pause");
	return 0;
}
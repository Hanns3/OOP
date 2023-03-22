#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void Change(int arr[][3], int rows, int cols)
{
	mtx.lock();
	cout << "Filtring" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j]>0)
			{
				arr[i][j]= 0;
			}
		}
	}

	cout << endl;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n";
	}
	cout << "Stop Filtring" << endl;
	mtx.unlock();
}

void Print(int arr[][3], int rows,int cols)
{
	mtx.lock();
	cout << "Printing" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << endl;
				for (int k = 0; k < rows; k++)
				{
					cout << arr[i][k] << "\t";
					
				}
				cout << endl;
				
			}
			break;
		}
	}
	cout << "Stop Printing" << endl;
	mtx.unlock();
}


int main()
{
	int rows,cols;
	int arr[3][3];
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of cols: ";
	cin >> cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << endl;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout<< arr[i][j]<<'\t';
		}
		cout << endl;
	}

	auto start = chrono::high_resolution_clock::now();

	thread t2(Print, arr, rows, cols);
	thread t1(Change, arr, rows, cols);
	
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	t1.join();
	t2.join();
	cout << "Seconds: " << duration.count();

	

	return 0;
}



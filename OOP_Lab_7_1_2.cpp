#include <iostream>
#include <thread>

using namespace std;

void Multi(int* arr, int size)
{
	int result = 1;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= -15 && arr[i] <= 15)
		{
			count++;
		}
	}
	if (!count)
	{
		cout << "There isn't any number in range of -15 to 15";
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= -15 && arr[i] <= 15)
		{
			result = result * arr[i];
		}
	}
	cout << "Result of multiplication is: " << result <<endl;
}

void Even(int* arr, int size)
{
	int count=0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i ]%2 == 0)
		{
			count++;
		}
	}

	cout << "Number of Even numbers is: " << count << endl;
}



int main()
{
	int k;
	int arr[20];
	cout << "Enter number of numbers: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	thread t1(Multi, arr, k);
	thread t2(Even,arr,k);

	t1.join();
	t2.join();

	return 0;
}



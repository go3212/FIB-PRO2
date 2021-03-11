#include <iostream>
#include <queue>
using namespace std;

struct SeqData
{
	int max, min;
	double average;
	int sum, size;
};

void updateSeqData(SeqData& myseqdata, int n)
{
	myseqdata.size += 1;
	myseqdata.sum += n;
	myseqdata.average = double(myseqdata.sum)/double(myseqdata.size);
	if (myseqdata.size > 1)
	{
		if (n < myseqdata.min) myseqdata.min = n;
		if (n > myseqdata.max) myseqdata.max = n;
	} else myseqdata.max = n, myseqdata.min = n;
}

void recalculateSeqDataMaxMin(queue<int> myqueuecp, SeqData& myseqdata)
{
	myseqdata.min = myseqdata.max = myqueuecp.front();
	myqueuecp.pop();
	int seq;
	for (int i = 1; i < myseqdata.size; ++i)
	{
		seq = myqueuecp.front();
		if (seq < myseqdata.min) myseqdata.min = seq;
		if (seq > myseqdata.max) myseqdata.max = seq;
		myqueuecp.pop();
	}

}

void printSeqData(const SeqData& myseqdata)
{
	if (myseqdata.size == 0) cout << "0" << endl;
	else
	{
		cout << "min " << myseqdata.min << "; max " << myseqdata.max << "; media " << myseqdata.average << endl;
	}

}

int main() 
{
	queue<int> myqueue;

	SeqData myseqdata;
	myseqdata.size = 0;
	myseqdata.sum = 0;

	int seq;
	while (cin >> seq)
	{
		if (seq < -1001 or seq >= 1001) break;
		if (seq == -1001)
		{
			if (myseqdata.size > 0)
			{
				myseqdata.sum -= myqueue.front();
				myseqdata.size -= 1;
				if (myseqdata.size > 0)
				{
					myseqdata.average = double(myseqdata.sum)/double(myseqdata.size);
					myqueue.pop();
					recalculateSeqDataMaxMin(myqueue, myseqdata);
				} else myqueue.pop();
			} else myseqdata.size = 0, myseqdata.sum = 0;
		} 
		else
		{
			myqueue.push(seq);
			updateSeqData(myseqdata, seq);
		}

		printSeqData(myseqdata);
	}	
}
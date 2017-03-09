/*
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
K.Avery CS 335
Exhaustive Search Algortihm on Graphs


*/

#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	int n, count;
	int Wmatrix[100][100]; // weight matrix

	cout << "CSPC 335 Project 2" << endl;
	cout << "Topology recognition algorithm" << endl;
	
	// get the number of nodes
	cout << "Enter the number of nodes in the topology" << endl;
	cin >> n;

	// read/intialize the weight matrix
	cout << "Enter the postive weights, 100 for infinity" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Wmatrix[i][j];
		}
	}

	bool cond = true;

	cout << "The topography is" << endl;
	// check if its a ring
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100) 
			{
				count++; // increment the number of edges with weights
			}

		}
		// if any verticies have more than 2 edges it can not be a ring
		if (count != 2)
		{
			cond = false;
		}
		
	}
	// if passes test for ring output
	if (cond)
	{
		cout << "ring" << endl;
	}

	cond = true; // reset condition
	int center = 0; // star has one center that has n-1 edges
	// check if graph is a star
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100)
			{
				count++; // increment the number of edges with weights
			}
			
		}

		// if the number of edges = verticies -1 then it is a center
		if (count == n-1)
		{
			center++;
		}
		// if center > 1 then it can not be a star because star has 1 center
		if (center != 1)
		{
			cond = false;
		}
		
	}
	// if passes test for star output
	if (cond)
	{
		cout << "star" << endl;
	}

	cond = true;
	// check if graph is fully connected mesh
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100)
			{
				count++; // increment the number of edges with weights
			}

		}
		// if the number of edges is not equal to number of verticies -1 then it is not a fully connected mesh
		if (count != n-1)
		{
			cond = false;
		}
	}
	// if passes fully connected mesh test
	if (cond)
	{
		cout << "Fully Connected Mesh" << endl;
	}
	// all tests have failed
	else
	{
		cout << "neither" << endl;
	}

	system("pause");
	return 0;
}
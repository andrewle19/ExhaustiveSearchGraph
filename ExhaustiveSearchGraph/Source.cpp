/*
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
K.Avery CS 335
Exhaustive Search Algortihm on Graphs

// Given a network with n>3 nodes and a weight matrix W[0..n−1, 0..n−1] of
// positive integers, of a weighted, connected undirected graph modeling
// a network, decide whether the network is one of the topologies, if any:
// ring, star, fully connected mesh. Note: represent infinity by the value 100.
// INPUT: a positive integer n and a list of n^2 positive values
// OUTPUT: message "ring" or "star" or "complete" or "neither"
*/

#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	int nodes, edges; // node = number of nodes, edges = number of edges
	int Wmatrix[100][100]; // weight matrix
	bool cond = true; // used for each test to check what structure the matrix is
	bool found = false; // if found remains false the graph is neither

	cout << "CSPC 335 Project 2" << endl;
	cout << "Topology recognition algorithm" << endl;
	
	// get the number of nodes
	cout << "Enter the number of nodes in the topology" << endl;
	cin >> nodes;

	// read/intialize the weight matrix
	cout << "Enter the postive weights, 100 for infinity" << endl;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			cin >> Wmatrix[i][j];
		}
	}

	// starts the clock
	auto start = chrono::high_resolution_clock::now();
	cout << "The topography is" << endl;
	// check if its a ring
	for (int i = 0; i < nodes; i++)
	{
		edges = 0;
		for (int j = 0; j < nodes; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100) 
			{
				edges++; // increment the number of edges with weights
			}

		}
		// if any verticies have more than 2 edges it can not be a ring
		if (edges != 2)
		{
			cond = false;
		}
		
	}
	// if passes test for ring output
	if (cond)
	{
		auto end = chrono::high_resolution_clock::now(); // end the clock
		found = true;
		cout << "ring" << endl;
	}

	cond = true; // reset condition
	int center = 0; // star has one center that has n-1 edges
	// check if graph is a star
	for (int i = 0; i < nodes; i++)
	{
		edges = 0;
		for (int j = 0; j < nodes; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100)
			{
				edges++; // increment the number of edges with weights
			}
			
		}

		// if the number of edges = verticies -1 then it is a center
		if (edges == nodes -1)
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
		auto end = chrono::high_resolution_clock::now(); // end the clock
		found = true;
		cout << "star" << endl;
	}

	cond = true;
	// check if graph is fully connected mesh
	for (int i = 0; i < nodes; i++)
	{
		edges = 0;
		for (int j = 0; j < nodes; j++)
		{
			// check each node to see if it has a weight that is not 0 or infinity
			if (Wmatrix[i][j] > 0 && Wmatrix[i][j] != 100)
			{
				edges++; // increment the number of edges with weights
			}

		}
		// if the number of edges is not equal to number of verticies -1 then it is not a fully connected mesh
		if (edges != nodes -1)
		{
			cond = false;
		}
	}
	// if passes fully connected mesh test
	if (cond)
	{
		auto end = chrono::high_resolution_clock::now(); // end the clock
		found = true;
		cout << "Fully Connected Mesh" << endl;
	}
	
	
	// all tests have failed
	if(found != true)
	{
		auto end = chrono::high_resolution_clock::now(); // end the clock
		cout << "neither" << endl;
	}
	auto end = chrono::high_resolution_clock::now(); // end the clock
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count(); // microseconds
	double seconds = microseconds / 1E6; // convert to seconds
	cout << "elapsed time: " << seconds << " seconds" << endl;

	system("pause");
	return 0;
}
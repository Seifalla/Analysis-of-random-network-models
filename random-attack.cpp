#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv){
		
	int adj[1000][1000];

	float coin;
	srand (time(NULL));


	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		for (int k = 0; k <=  atoi(argv[1]) - 1; k ++){

			coin = rand() % (101);
			if (k != j){

				if ((float)coin/(float)100 <= atof(argv[2])){

					adj[k][j] = 1;
				}
				else{

					adj[k][j] = 0;
				}
			}
			else{
				adj[k][j] = 0;
			}
		}
	}
	

	int h = 0;
	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		h = 0;
		while(h != j){

			adj[h][j] = adj[j][h];
			h ++;
		}
	}

	/*for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		for (int k = 0; k <=  atoi(argv[1]) - 1; k ++){

			cout<<adj[j][k];
			if (k != atoi(argv[1]) - 1)
				cout<<',';
		}
		cout<<endl;
	}

	cout<<endl;*/

	int node_ids[atoi(argv[1])];
	int centralities[atoi(argv[1])];

	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		node_ids[j] = j;
	}

	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		centralities[j] = 0;

		for(int e = 0; e <= atoi(argv[1]) - 1; e++){

				centralities[j] = centralities[j] + adj[j][e];
		}
	}

	int b, l;
	for (int j = 1; j < atoi(argv[1]); j ++){

		b = node_ids[j];
		l = j - 1;
		while((l > -1) && centralities[b] > centralities[node_ids[l]]){

			node_ids[l + 1] = node_ids[l];
			l --;
		}
		node_ids[l + 1] = b;
	}

	int node_to_be_removed;
	vector<int> nodes_chosen;


	for (int j = 0; j <=  atoi(argv[3]) - 1; j ++){

		//node_to_be_removed = node_ids[atoi(argv[3]) - 1 - j];
		node_to_be_removed = rand()%(atoi(argv[1]));
		while (search_n(nodes_chosen.begin(), nodes_chosen.end(), 1, node_to_be_removed) != nodes_chosen.end()){
			
			node_to_be_removed = rand()%(atoi(argv[1]));
		}
		nodes_chosen.push_back(node_to_be_removed);
		for (int k = 0; k <=  atoi(argv[1]) - 1; k ++){

			adj[node_to_be_removed][k] = 0;
			adj[k][node_to_be_removed] = 0;
		}
	}


	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		for (int k = 0; k <=  atoi(argv[1]) - 1; k ++){

			cout<<adj[j][k];
			if (k != atoi(argv[1]) - 1)
				cout<<',';
		}
		cout<<endl;
	}

	return 0;
} 
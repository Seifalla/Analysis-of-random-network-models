#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){

	int adj[1000][1000];
	int num_of_nodes = atoi(argv[2]);
	srand (time(NULL));
	int sec_endpoint_index;	

	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		for (int k = 0; k <=  atoi(argv[1]) - 1; k ++){


			adj[k][j] = 0;
		}
	}

	int k = 0;

	for (int j = 0; j <=  atoi(argv[2]) - 1; j ++){

		vector<int> draw;
		k = 0;
		while(k != j){
				
			draw.push_back(k);
			k ++;

		}
		if (draw.size() != 0){
			sec_endpoint_index = rand() % (draw.size());
			adj[j][draw[sec_endpoint_index]] = 1;
		}
	}

	int h = 0;
	for (int j = 0; j <=  atoi(argv[2]) - 1; j ++){

		h = 0;
		while(h != j){

			adj[h][j] = adj[j][h];
			h ++;
		}
	}
	vector<int> chosen_nodes;
	int ne = 0;
	int current_node = 0;
	float degreei = 0;
	float sum_of_degrees = 0;
	int random_num;	

	for (int j = atoi(argv[2]); j <=  atoi(argv[1]) - 1; j ++){

		while (ne <=  atoi(argv[2]) - 1){

			for(int e = 0; e <= num_of_nodes - 1; e++){

				degreei = degreei + adj[current_node][e];
			}
			for(int e = 0; e <= num_of_nodes - 1; e++){

				for(int f = 0; f <= num_of_nodes - 1; f++){

					sum_of_degrees = sum_of_degrees + adj[e][f];
				}
			}
			random_num = rand()%(101);
			//cout<<(float)random_num/100.0<<'\t'<<degreei/sum_of_degrees<<endl;
			if ((float)random_num/100.0 <= degreei/sum_of_degrees
			&& search_n(chosen_nodes.begin(), chosen_nodes.end(), 1, current_node) == chosen_nodes.end()){

				chosen_nodes.push_back(current_node);
				ne ++;
			}

			current_node = (current_node + 1)%num_of_nodes;

		}
		for (int l = 0; l <  chosen_nodes.size(); l ++){

			adj[j][chosen_nodes[l]] = 1;
		}
		num_of_nodes ++;
		chosen_nodes.clear();
		ne = 0;
	}
	for (int j = 0; j <=  atoi(argv[1]) - 1; j ++){

		h = 0;
		while(h != j){

			adj[h][j] = adj[j][h];
			h ++;
		}
	}

	/*for (int j = 0; j <=  num_of_nodes - 1; j ++){

		for (int k = 0; k <=  num_of_nodes - 1; k ++){

			cout<<adj[j][k];
			if (k != num_of_nodes - 1)
				cout<<',';

		}
		cout<<endl;
	}*/
	
	int node_ids[num_of_nodes];
	int centralities[num_of_nodes];

	for (int j = 0; j <=  num_of_nodes - 1; j ++){

		node_ids[j] = j;
	}

	for (int j = 0; j <=  num_of_nodes - 1; j ++){

		centralities[j] = 0;

		for(int e = 0; e <= num_of_nodes - 1; e++){

				centralities[j] = centralities[j] + adj[j][e];
		}
	}

	int b, l;
	for (int j = 1; j < num_of_nodes; j ++){

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
		node_to_be_removed = rand()%(num_of_nodes);
		while (search_n(nodes_chosen.begin(), nodes_chosen.end(), 1, node_to_be_removed) != nodes_chosen.end()){
			
			node_to_be_removed = rand()%(num_of_nodes);
		}
		nodes_chosen.push_back(node_to_be_removed);
		for (int k = 0; k <=  num_of_nodes - 1; k ++){

			adj[node_to_be_removed][k] = 0;
			adj[k][node_to_be_removed] = 0;
		}
	}
	cout<<endl;


	for (int j = 0; j <=  num_of_nodes - 1; j ++){

		for (int k = 0; k <=  num_of_nodes - 1; k ++){

			cout<<adj[j][k];
			if (k != num_of_nodes - 1)
				cout<<',';
		}
		cout<<endl;
	}
	return 0;
} 
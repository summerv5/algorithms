
/*
http://lintcode.com/en/problem/load-balancer/

Implement a load balancer for web servers. It provide the following functionality:

Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().

*/

#include "stdafx.h"
#include "unordered_map"

using namespace std;

/*
	We use a vector to store the server ids and a map to store the indexes for the servers in the vector.
*/


class LoadBalancer {
public:
	LoadBalancer() {
		// do intialization if necessary
	}

	/*
	* @param server_id: add a new server to the cluster
	* @return: nothing
	*/

	// O(1).
	void add(int server_id) {
		// write your code here

		if (!locs.count(server_id)) {
			servers.push_back(server_id);
		}

		locs[server_id] = servers.size() - 1;
	}

	/*
	* @param server_id: server_id remove a bad server from the cluster
	* @return: nothing
	*/

	// O(n) time if we include the swap action.
	void remove(int server_id) {
		// write your code here

		if (locs.count(server_id)) {
			int loc = locs[server_id];

			if (loc != servers.size() - 1) {
				locs[servers[servers.size() - 1]] = loc;
				swap(servers[loc], servers[servers.size() - 1]);
			}

			servers.pop_back();
			locs[server_id] = 0;
		}
	}

	/*
	* @return: pick a server in the cluster randomly with equal probability
	*/
	// O(1).
	int pick() {
		// write your code here

		return servers[rand() % servers.size()];
	}

private:
	vector<int> servers;
	unordered_map<int, int> locs;
};
/*
std::vector<std::vector<double>> BFS (Graph G, City s, City e) {
	std::queue<City> q; # queue
	std::vector<City> path;
	std::map<string, bool> explored;
	std::map<string, bool> previous;
	for (City v : cities_) {
		explored[v] = false;
		previous[v] = NULL;
	}
	explored[s] = true;
	q.push(s);
	while (!q.empty()) {
		If (v == e) {
			path.push_back(v);
			return path;
		}
		q.pop();
		for (City adjCity: Cities[v]) {
			If (!explored[v]) {
				explored[v] = true;
				q.push(v);
		}
	}
}
*/

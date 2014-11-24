/**
Clone Graph Total Accepted: 22116 Total Submissions: 95890 My Submissions Question Solution
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

Author: haoya5509
Time: 12:33AM 2014/11/17
*/

unordered_map<int,UndirectedGraphNode *> created;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(node==NULL)
		return NULL;
    if(created.find(node->label)!=created.end())
        return created[node->label];
	UndirectedGraphNode *cur=new UndirectedGraphNode(node->label);
	created[node->label] = cur;
	for(int i=0;i<node->neighbors.size();i++){
        UndirectedGraphNode *nei = cloneGraph(node->neighbors[i]);
		cur->neighbors.push_back(nei);
		created[node->neighbors[i]] = nei;
	}
	return cur;
}

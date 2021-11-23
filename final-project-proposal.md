# Final Project Proposal

## Finding Shortest Distance Between Wikipedia Pages (Wiki Races)

### Team Members: Gagan Kadadevarmath, Sanjiv Iyer, Sarah Zimmerman, Ritvik Gandesiri

### Leading Question
A 'Wiki Race' is a game in which the player must start at some Wikipedia page and traverse the hyperlinks contained within each page to reach the end, which is the Wikipedia page the player wants to find. So what is the best strategy to win this game? The quickest way to complete this game is to find and take the most optimal path, meaning taking the shortest path from the start node to the end node. However, we can also identify a specific primary node or a type of node that, when searching for any path between some nodes, these primary nodes will most likely be visited on the way to the end. Implementing this within the strategy would allow the player to keep an eye out for these nodes or links, because it would mean that they are on the right track towards finishing the race.

### Dataset Aquisition and Processing
We will be using the SNAP Wikispeedia navigation paths dataset from Stanford, which contains a collection of human navigation paths of 4604 articles on Wikipedia. Each file in our dataset contains table seperated values, where the first column is an article, and the second column is a link that the article contains. We will download and store the datasets into a folder within our repo. We will create a function that will take in each .tsv file and parse it and then insert it into an adjancency list. In our graphs, our nodes will be the articles and the edges are the hyperlinks that lead to another article. 

### Graph Algorithms
We will be using a BFS (Breadth First Search) for our traversal algorithm, the Dijkstra's Algorithm for our shortest path algorithm, and the betweeness centrality algorithm to identify nodes that will be used as the "center" of numerous paths. For the BFS and Dijkstra's method, we expect our inputs to be our starting node and end/goal node. The output would be the shortest path from the start to end node. The time complexity of BFS would be O(E + V) and Dijkstra's would be O(E + VlogV). We understand that the data set we have does not call for weights in any of the edges, and Dijkstras requires a weighted graph. To adjust for this, we will be modifying our graph by adding a weight of 1 to each of our edges. This way, we can still use Dijkstra's algorithm on our graph. For the betweeness centrality method, our input would be the hashmap that maps each article to links that article contains which links to other articles. Our output would be a list of nodes that are the most common in paths taken from starting nodes to end nodes. We will be using Brandes' algorithm, which has O(VE + V^2 log V) time complexity.    

### Timeline
- Week 1 (Nov 8 - 14) - Acquire and understand dataset, begin implementing data processing method
- Week 2 (Nov 15 - 21) - Finish implementing BFS function
- Week 3 (Nov 22 - 28) - Finish implementing Dijkstra's function
- Week 4 (Nov 29 - Dec 5) - Finish implementing betweeness centrality function, prepare for Mid-Project checkin
- Week 5 (Dec 6 - 13) - Finish final project deliverables (commenting/cleaning codebase, written report, and presentation)